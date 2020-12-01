#include "SymbolTable.h"
#include <iostream>

#include "llvm/ADT/APFloat.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/Verifier.h"

using namespace std;

static unique_ptr<llvm::LLVMContext> TheContext;
static unique_ptr<llvm::Module> TheModule;
static unique_ptr<llvm::IRBuilder<>> Builder;
static map<string, llvm::Value*> NamedValues;

class IRVisitor : public ASTvisitor {
    llvm::Value* theValue;

public:
    IRVisitor()
    {
        TheContext = make_unique<llvm::LLVMContext>();
        TheModule = make_unique<llvm::Module>("MyStupidModule", *TheContext);
        // Create a new builder for the module.
        Builder = make_unique<llvm::IRBuilder<>>(*TheContext);
    }

    llvm::Type* getLLVMType(DataType Type)
    {
        switch (Type) {
        case VOID:
            return Builder->getVoidTy();
        case INT:
            return Builder->getInt32Ty();
        case BOOL:
            return Builder->getInt1Ty();
        case STRING:
            return Builder->getInt8PtrTy();
        default:
            throw runtime_error("Unknown type");
        }
    }

    llvm::AllocaInst* CreateEntryBlockAlloca(llvm::Function* TheFunction, string identifier, DataType Type)
    {
        llvm::IRBuilder<> TmpB(&TheFunction->getEntryBlock(), TheFunction->getEntryBlock().begin());
        llvm::AllocaInst* alloca_instruction = nullptr;
        if (Type == INT) {
            alloca_instruction = TmpB.CreateAlloca(llvm::Type::getInt32Ty(*TheContext), 0, identifier);
        } else if (Type == BOOL) {
            alloca_instruction = TmpB.CreateAlloca(llvm::Type::getInt1Ty(*TheContext), 0, identifier);
        }
        return alloca_instruction;
    }

    virtual void visit(ASTProg& node)
    {
        for (auto method : node.methodList) {
            method->accept(*this);
        }
    }

    virtual void visit(ASTMethodCall& node)
    {
        vector<llvm::Value*> ArgsVec;
        string funcName = node.getFunctionName();
        llvm::Function* CalleeF = TheModule->getFunction(funcName);
        funcName.erase(funcName.begin());
        funcName.erase(funcName.end() - 1);
        for (auto expr : node.getExprList()) {
            expr->accept(*this);
            ArgsVec.push_back(theValue);
        }
        theValue = Builder->CreateCall(CalleeF, ArgsVec, "callreturn");
    }

    virtual void visit(ASTMethodArg& node)
    {
        // cout << "ASTMethodArg visit" << endl;
        ASTType* TypeNode = node.getType();
        TypeNode->accept(*this);
        // VarSymbol* symbol = new VarSymbol;
        // symbol->Type = Type;
        ASTExpr *size1 = node.getSize1(), *size2 = node.getSize2();
        if (size1 != nullptr) {
            size1->accept(*this);
            // symbol->size1 = 1;
        } else {
            // symbol->size1 = 0;
        }
        if (size2 != nullptr) {
            size2->accept(*this);
            // symbol->size2 = 1;
        } else {
            // symbol->size2 = 0;
        }
        // string identifier = node.getIdentifier();
        // methodArgsList.push_back(make_pair(identifier, symbol));
        // symbol->identifier = identifier;
        // symbol->scope = symbolTable->scopes.top();
        // symbolTable->insertVariable(symbol);
    }

    virtual void visit(ASTMethodDecl& node)
    {
        vector<pair<string, DataType>> argsVec;
        vector<llvm::Type*> argsType;
        for (auto arg : node.getArgsList()) {
            if (arg->getType()->getType() == INT) {
                argsType.push_back(llvm::Type::getInt32Ty(*TheContext));
                argsVec.push_back(make_pair(arg->getIdentifier(), INT));
            } else if (arg->getType()->getType() == BOOL) {
                argsType.push_back(llvm::Type::getInt1Ty(*TheContext));
                argsVec.push_back(make_pair(arg->getIdentifier(), BOOL));
            }
        }

        llvm::Type* returnType = nullptr;
        if (node.getType()->getType() == INT) {
            returnType = llvm::Type::getInt32Ty(*TheContext);
        } else if (node.getType()->getType() == BOOL) {
            returnType = llvm::Type::getInt1Ty(*TheContext);
        } else if (node.getType()->getType() == VOID) {
            returnType = llvm::Type::getVoidTy(*TheContext);
        }

        llvm::FunctionType* FT = llvm::FunctionType::get(returnType, argsType, false);
        llvm::Function* F = llvm::Function::Create(FT, llvm::Function::ExternalLinkage, node.getIdentifier(), *TheModule);

        llvm::Function::arg_iterator AI = F->arg_begin();
        for (int i = 0; i < argsVec.size(); ++i, ++AI) {
            AI->setName(argsVec[i].first);
        }

        llvm::BasicBlock* BB = llvm::BasicBlock::Create(*TheContext, "entry", F);
        Builder->SetInsertPoint(BB);
        int i = 0;

        for (auto& arg : F->args()) {
            llvm::AllocaInst* Alloca = CreateEntryBlockAlloca(F, argsVec[i].first, argsVec[i].second);
            Builder->CreateStore(&arg, Alloca);
            NamedValues[argsVec[i++].first] = Alloca;
        }

        node.getBlock()->accept(*this);
        llvm::Value* retVal = theValue;

        if (retVal == nullptr and node.getType()->getType() == VOID) {
            Builder->CreateRetVoid();
        } else {
            Builder->CreateRet(retVal);
        }
        llvm::verifyFunction(*F);
        theValue = F;
        F->eraseFromParent();
    }

    virtual void visit(ASTBlock& node)
    {
        for (auto statement : node.statementList) {
            statement->accept(*this);
        }
    }

    virtual void visit(ASTIfElse& node)
    {
        // cout << "ASTIfElse" << endl;
        node.getExpr()->accept(*this);
        node.getIfBlock()->accept(*this);
        if (node.getElseBlock())
            node.getElseBlock()->accept(*this);
    }

    virtual void visit(ASTWhile& node)
    {
        // cout << "ASTWhile" << endl;
        node.getExpr()->accept(*this);
        node.getBlock()->accept(*this);
    }

    virtual void visit(ASTTernary& node)
    {
        // cout << "ASTTernary" << endl;
        node.getExpr()->accept(*this);
        node.getStat1()->accept(*this);
        node.getStat2()->accept(*this);
    }

    virtual void visit(ASTFor& node)
    {
        // cout << "ASTFor" << endl;
        // for (auto expr : node.initialExprList) {
        //     expr->accept(*this);
        // }
        // node.conditionExpr->accept(*this);
        // for (auto expr : node.incrementExprList) {
        //     expr->accept(*this);
        // }
        // node.block->accept(*this);
        node.getBlock()->accept(*this);
        node.getInitExpr()->accept(*this);
        node.getIncrementExpr()->accept(*this);
        node.getConditionExpr()->accept(*this);
    }

    virtual void visit(ASTStatExpr& node)
    {
        // cout << "ASTStatExpr" << endl;
        node.expr->accept(*this);
    }

    virtual void visit(ASTStatAssignExpr& node)
    {
        // cout << node.id;
        // cout << " = ";
        node.expr->accept(*this);
    }

    virtual void visit(ASTLocationIdentifier& node)
    {
        // cout << "ASTLocationIdentifier visit function" << endl;
        // Type = symbolTable->checkVariable(node.getIdentifier());
        // if (Type == VOID) {
        //     cout << "Identifier " << node.getIdentifier() << " used before decleration near line " << symbolTable->lineNumber << endl;
        //     exit(0);
        // }
    }

    virtual void visit(ASTLocationIdentifierArray& node)
    {
        // cout << "ASTLocationIdentifierArray visit function" << endl;
        // DataType ret = symbolTable->checkVariable(node.getIdentifier());
        // if (ret == VOID) {
        //     cout << "Identifier " << node.getIdentifier() << " used before decleration near line " << symbolTable->lineNumber << endl;
        //     exit(0);
        // }
        node.getExpr()->accept(*this);
        // if (Type != INT) {
        //     cout << "Array address must be an integer near line " << symbolTable->lineNumber << endl;
        //     exit(0);
        // }
        // Type = ret;
    }

    virtual void visit(ASTLocationIdentifierDoubleArray& node)
    {
        // cout << "ASTLocationIdentifierDoubleArray visit function" << endl;
        // DataType ret = symbolTable->checkVariable(node.getIdentifier());
        // if (ret == VOID) {
        //     cout << "Identifier " << node.getIdentifier() << " used before decleration near line " << symbolTable->lineNumber << endl;
        //     exit(0);
        // }
        node.getExpr1()->accept(*this);
        // if (Type != INT) {
        //     cout << "Array address must be an integer near line " << symbolTable->lineNumber << endl;
        //     exit(0);
        // }
        node.getExpr2()->accept(*this);
        // if (Type != INT) {
        //     cout << "Array address must be an integer near line " << symbolTable->lineNumber << endl;
        //     exit(0);
        // }
        // Type = ret;
    }

    virtual void visit(ASTExpr& node)
    {
        // cout << "ASTExpr visit function" << endl;
    }

    virtual void visit(ASTExprUnaryOp& node)
    {
        // cout << " " + node.getUnary_operator();
        node.getExpr()->accept(*this);
        if (node.getUnary_operator() == "-")
            theValue = Builder->CreateNeg(theValue, "neg");
        else if (node.getUnary_operator() == "!")
            theValue = Builder->CreateNot(theValue, "not");
    }

    virtual void visit(ASTVariableList& node)
    {
        node.getType()->accept(*this);
        vector<ASTDeclare*> identifierList = node.getIdentifierList();
        for (auto identifier : identifierList) {
            identifier->accept(*this);
        }
    }

    virtual void visit(ASTDeclare& node)
    {
        // cout << " " << node.getIdentifier();
        // VarSymbol* symbol = new VarSymbol();
        // pair<string, int> key = make_pair(node.getIdentifier(), symbolTable->scopes.top());
        // symbol->identifier = node.getIdentifier();
        // symbol->size1 = 0;
        // symbol->size2 = 0;
        // symbol->Type = Type;
        // symbol->scope = symbolTable->scopes.top();

        if (node.getVal() != nullptr) {
            node.getVal()->accept(*this);
        }
        // if (Type != symbol->Type) {
        //     cout << "Type mismatch in the declaration near line " << symbolTable->lineNumber;
        // }
        // symbolTable->insertVariable(symbol);
    }

    virtual void visit(ASTDeclareArray& node)
    {
        // VarSymbol* symbol = new VarSymbol();
        // pair<string, int> key = make_pair(node.getIdentifier(), symbolTable->scopes.top());
        // symbol->identifier = node.getIdentifier();
        // symbol->size1 = 1;
        // symbol->size2 = 0;
        // symbol->Type = Type;
        // symbol->scope = symbolTable->scopes.top();

        if (node.getSize() != nullptr) {
            node.getSize()->accept(*this);
        }
        // if (Type != INT) {
        //     cout << "Array size must be an integer. Error near line " << symbolTable->lineNumber << endl;
        //     exit(0);
        // }
        // symbolTable->insertVariable(symbol);
    }

    virtual void visit(ASTDeclareDoubleArray& node)
    {
        // VarSymbol* symbol = new VarSymbol();
        // pair<string, int> key = make_pair(node.getIdentifier(), symbolTable->scopes.top());
        // symbol->identifier = node.getIdentifier();
        // symbol->size1 = 1;
        // symbol->size2 = 1;
        // symbol->Type = Type;
        // symbol->scope = symbolTable->scopes.top();

        if (node.getSize1() != nullptr) {
            node.getSize1()->accept(*this);
        }
        // if (Type != INT) {
        //     cout << "Array size must be an integer. Error near line " << symbolTable->lineNumber << endl;
        //     exit(0);
        // }
        if (node.getSize2() != nullptr) {
            node.getSize2()->accept(*this);
        }
        // if (Type != INT) {
        //     cout << "Array size must be an integer. Error near line " << symbolTable->lineNumber << endl;
        //     exit(0);
        // }
        // symbolTable->insertVariable(symbol);
    }

    virtual void visit(ASTType& node)
    {
        // cout << " " << node.getType();
    }

    virtual void visit(ASTControl& node)
    {
        ASTExpr* expr = node.getExpr();
        if (expr != nullptr) {
            expr->accept(*this);
        //     if (Type != currFuncType) {
        //         cout << "Return type mismatch near line " << symbolTable->lineNumber << endl;
        //         exit(0);
        //     }
        }
        // Type == VOID;
    }

    virtual void visit(ASTExprBinary& node)
    {
        node.getLeft()->accept(*this);
        llvm::Value* leftValue = theValue;
        node.getRight()->accept(*this);
        llvm::Value* rightValue = theValue;

        string binop = node.getBinOp();

        if (binop == "+") {
            theValue = Builder->CreateAdd(leftValue, rightValue, "add");
        } else if (binop == "-") {
            theValue = Builder->CreateSub(leftValue, rightValue, "sub");
        } else if (binop == "*") {
            theValue = Builder->CreateMul(leftValue, rightValue, "mul");
        } else if (binop == "/") {
            theValue = Builder->CreateSDiv(leftValue, rightValue, "div");
        } else if (binop == "%") {
            theValue = Builder->CreateSRem(leftValue, rightValue, "mod");
        } else if (binop == "<") {
            theValue = Builder->CreateICmpSLT(leftValue, rightValue, "lt");
        } else if (binop == ">") {
            theValue = Builder->CreateICmpSGT(leftValue, rightValue, "gt");
        } else if (binop == "<=") {
            theValue = Builder->CreateICmpSLE(leftValue, rightValue, "leq");
        } else if (binop == ">=") {
            theValue = Builder->CreateICmpSGE(leftValue, rightValue, "geq");
        } else if (binop == "==") {
            theValue = Builder->CreateICmpEQ(leftValue, rightValue, "eq");
        } else if (binop == "!=") {
            theValue = Builder->CreateICmpNE(leftValue, rightValue, "neq");
        }
    }

    virtual void
    visit(ASTExprTernary& node)
    {
        node.getFirst()->accept(*this);
        // DataType type1 = Type;
        node.getSecond()->accept(*this);
        // DataType type2 = Type;
        node.getThird()->accept(*this);
        // DataType type3 = Type;
    }

    virtual void visit(ASTExprIdentifier& node)
    {
        // cout << " " << node.getIdentifier();
    }

    virtual void visit(ASTLiteral& node)
    {
        // cout << "literal" << endl;
    }
    virtual void visit(ASTLiteralInt& node)
    {
        // cout << " " << node.getIntLit();
        // Type = INT;
        theValue = llvm::ConstantInt::get(getLLVMType(INT), node.getIntLit());
    }
    virtual void visit(ASTLiteralFloat& node)
    {
        // Type = FLOAT;
        // theValue = llvm::ConstantFP::get(getLLVMType(CHAR), node.getCharLit());
    }
    virtual void visit(ASTLiteralString& node)
    {
        // cout << " " << node.getStringLit();
        // Type = STRING;
        theValue = Builder->CreateGlobalStringPtr(node.getStringLit());
    }
    virtual void visit(ASTLiteralChar& node)
    {
        // cout << " " << node.getCharLit();
        // Type = CHAR;
        theValue = llvm::ConstantInt::get(getLLVMType(CHAR), node.getCharLit());
    }
    virtual void visit(ASTLiteralBool& node)
    {
        // cout << " " << node.getBoolLit();
        // Type = BOOL;
        theValue = llvm::ConstantInt::get(getLLVMType(BOOL), node.getBoolLit());
    }
};