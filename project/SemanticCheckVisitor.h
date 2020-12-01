#include "SymbolTable.h"
#include <iostream>

using namespace std;

class SemanticCheckVisitor : public ASTvisitor {

    DataType Type, currFuncType;
    vector<pair<string, VarSymbol*>> methodArgsList;

public:
    SymbolTable *symbolTable;
    SemanticCheckVisitor(SymbolTable* symbolTable)
        : symbolTable(symbolTable)
    {
    }

    virtual void visit(ASTProg& node)
    {
        int i = 1;
        symbolTable->scopes.push(++symbolTable->scope);
        ++symbolTable->lineNumber;

        for (auto method : node.methodList) {
            ++symbolTable->lineNumber;
            cout << "Method " << i << " : " << endl;
            method->accept(*this);
            ++i;
        }
    }

    virtual void visit(ASTMethodCall& node)
    {
        // cout << "In AstMethodCall " << endl;
        vector<DataType> typeSignature;
        string funcName = node.getFunctionName();
        funcName.erase(funcName.begin());
        funcName.erase(funcName.end() - 1);
        for (auto expr : node.getExprList()) {
            expr->accept(*this);
            typeSignature.push_back(Type);
        }
        if (funcName == "print" or funcName == "read") {
            if (typeSignature.size() == 0) {
                cout << "Wrong usage of " + funcName + " near line " << symbolTable->lineNumber << endl;
                exit(0);
            }
            Type = typeSignature[0];
        } else {
            Type = symbolTable->checkFuncSignature(funcName, typeSignature);
        }
        // cout << endl;
    }

    virtual void visit(ASTMethodArg& node)
    {
        // cout << "ASTMethodArg visit" << endl;
        ASTType* TypeNode = node.getType();
        TypeNode->accept(*this);
        VarSymbol* symbol = new VarSymbol;
        symbol->Type = Type;
        ASTExpr *size1 = node.getSize1(), *size2 = node.getSize2();
        if (size1 != nullptr) {
            size1->accept(*this);
            symbol->size1 = 1;
        } else {
            symbol->size1 = 0;
        }
        if (size2 != nullptr) {
            size2->accept(*this);
            symbol->size2 = 1;
        } else {
            symbol->size2 = 0;
        }
        string identifier = node.getIdentifier();
        methodArgsList.push_back(make_pair(identifier, symbol));
        symbol->identifier = identifier;
        symbol->scope = symbolTable->scopes.top();
        symbolTable->insertVariable(symbol);
    }

    virtual void visit(ASTMethodDecl& node)
    {
        // cout << "In ASTMethodDecl method" << endl;
        // cout << "Method Type: " << node.getType() << ", method identifier: " << node.getIdentifier() << endl;
        ASTType* TypeNode = node.getType();
        TypeNode->accept(*this);
        FuncSymbol* symbol = new FuncSymbol();
        symbol->Type = Type;
        currFuncType = Type;
        for (auto arg : node.getArgsList()) {
            arg->accept(*this);
        }
        symbol->args = methodArgsList;
        symbol->identifier = node.getIdentifier();
        symbolTable->addFunction(symbol);
        methodArgsList.clear();
        node.getBlock()->accept(*this);
    }

    virtual void visit(ASTBlock& node)
    {
        // cout << "In visitASTBlock function. Processing block statements: " << endl;
        symbolTable->scopes.push(++symbolTable->scope);
        ++symbolTable->lineNumber;
        for (auto statement : node.statementList) {
            ++symbolTable->lineNumber;
            statement->accept(*this);
        }
        symbolTable->scopes.pop();
        symbolTable->scopes.push(++symbolTable->scope);
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
        Type = symbolTable->checkVariable(node.getIdentifier());
        if (Type == VOID) {
            cout << "Identifier " << node.getIdentifier() << " used before decleration near line " << symbolTable->lineNumber << endl;
            exit(0);
        }
    }

    virtual void visit(ASTLocationIdentifierArray& node)
    {
        // cout << "ASTLocationIdentifierArray visit function" << endl;
        DataType ret = symbolTable->checkVariable(node.getIdentifier());
        if (ret == VOID) {
            cout << "Identifier " << node.getIdentifier() << " used before decleration near line " << symbolTable->lineNumber << endl;
            exit(0);
        }
        node.getExpr()->accept(*this);
        if (Type != INT) {
            cout << "Array address must be an integer near line " << symbolTable->lineNumber << endl;
            exit(0);
        }
        Type = ret;
    }

    virtual void visit(ASTLocationIdentifierDoubleArray& node)
    {
        // cout << "ASTLocationIdentifierDoubleArray visit function" << endl;
        DataType ret = symbolTable->checkVariable(node.getIdentifier());
        if (ret == VOID) {
            cout << "Identifier " << node.getIdentifier() << " used before decleration near line " << symbolTable->lineNumber << endl;
            exit(0);
        }
        node.getExpr1()->accept(*this);
        if (Type != INT) {
            cout << "Array address must be an integer near line " << symbolTable->lineNumber << endl;
            exit(0);
        }
        node.getExpr2()->accept(*this);
        if (Type != INT) {
            cout << "Array address must be an integer near line " << symbolTable->lineNumber << endl;
            exit(0);
        }
        Type = ret;
    }

    virtual void visit(ASTExpr& node)
    {
        // cout << "ASTExpr visit function" << endl;
    }

    virtual void visit(ASTExprUnaryOp& node)
    {
        // cout << " " + node.getUnary_operator();
        node.getExpr()->accept(*this);
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
        VarSymbol *symbol = new VarSymbol();
        pair<string, int> key = make_pair(node.getIdentifier(), symbolTable->scopes.top());
        symbol->identifier = node.getIdentifier();
        symbol->size1 = 0;
        symbol->size2 = 0;
        symbol->Type = Type;
        symbol->scope = symbolTable->scopes.top();

        if (node.getVal() != nullptr) {
            node.getVal()->accept(*this);
        }
        if (Type != symbol->Type) {
            cout << "Type mismatch in the declaration near line " << symbolTable->lineNumber << endl;
        }
        symbolTable->insertVariable(symbol);
    }

    virtual void visit(ASTDeclareArray& node)
    {
        VarSymbol *symbol = new VarSymbol();
        pair<string, int> key = make_pair(node.getIdentifier(), symbolTable->scopes.top());
        symbol->identifier = node.getIdentifier();
        symbol->size1 = 1;
        symbol->size2 = 0;
        symbol->Type = Type;
        symbol->scope = symbolTable->scopes.top();

        if (node.getSize() != nullptr) {
            node.getSize()->accept(*this);
        }
        if (Type != INT) {
            cout << "Array size must be an integer. Error near line " << symbolTable->lineNumber << endl;
            exit(0);
        }
        symbolTable->insertVariable(symbol);
    }

    virtual void visit(ASTDeclareDoubleArray& node)
    {
        VarSymbol *symbol = new VarSymbol();
        pair<string, int> key = make_pair(node.getIdentifier(), symbolTable->scopes.top());
        symbol->identifier = node.getIdentifier();
        symbol->size1 = 1;
        symbol->size2 = 1;
        symbol->Type = Type;
        symbol->scope = symbolTable->scopes.top();

        if (node.getSize1() != nullptr) {
            node.getSize1()->accept(*this);
        }
        if (Type != INT) {
            cout << "Array size must be an integer. Error near line " << symbolTable->lineNumber << endl;
            exit(0);
        }
        if (node.getSize2() != nullptr) {
            node.getSize2()->accept(*this);
        }
        if (Type != INT) {
            cout << "Array size must be an integer. Error near line " << symbolTable->lineNumber << endl;
            exit(0);
        }
        symbolTable->insertVariable(symbol);
    }

    virtual void visit(ASTType& node)
    {
        // cout << " " << node.getType();
        Type = node.getType();
    }

    virtual void visit(ASTControl& node)
    {
        ASTExpr* expr = node.getExpr();
        if (expr != nullptr) {
            expr->accept(*this);
            if (Type != currFuncType) {
                cout << "Return type mismatch near line " << symbolTable->lineNumber << endl;
                exit(0);
            }
        }
        Type == VOID;
    }

    virtual void visit(ASTExprBinary& node)
    {
        node.getLeft()->accept(*this);
        DataType leftType = Type;
        node.getRight()->accept(*this);
        DataType rightType = Type;

        string binop = node.getBinOp();
        if (leftType != rightType) {
            cout << "Operand type mismatch near line " << symbolTable->lineNumber << endl;
            exit(0);
        }
        if (binop == ">" or binop == ">=" or binop == "<" or binop == "<=" or binop == "==" or binop == "!=") {
            Type = BOOL;
            return;
        }
        if ((binop == "&&" or binop == "||") and rightType != BOOL) {
            cout << "Non boolean operands for boolean operation near line " << symbolTable->lineNumber << endl;
            exit(0);
        }
        Type = leftType;
    }

    virtual void visit(ASTExprTernary& node)
    {
        node.getFirst()->accept(*this);
        DataType type1 = Type;
        node.getSecond()->accept(*this);
        DataType type2 = Type;
        node.getThird()->accept(*this);
        DataType type3 = Type;
    }

    virtual void visit(ASTExprIdentifier& node)
    {
        cout << " " << node.getIdentifier();
    }

    virtual void visit(ASTLiteral& node)
    {
        // cout << "literal" << endl;
    }
    virtual void visit(ASTLiteralInt& node)
    {
        // cout << " " << node.getIntLit();
        Type = INT;
    }
    virtual void visit(ASTLiteralFloat& node)
    {
        Type = FLOAT;
    }
    virtual void visit(ASTLiteralString& node)
    {
        // cout << " " << node.getStringLit();
        Type = STRING;
    }
    virtual void visit(ASTLiteralChar& node)
    {
        // cout << " " << node.getCharLit();
        Type = CHAR;
    }
    virtual void visit(ASTLiteralBool& node)
    {
        // cout << " " << node.getBoolLit();
        Type = BOOL;
    }
};