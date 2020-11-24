#include <string>
#include <vector>

using namespace std;

class ASTProg;

class ASTMethodDecl;
class ASTMethodArg;
class ASTMethodCall;

class ASTStatExpr;
class ASTStatAssignExpr;

class ASTBlock;
class ASTIfElse;
class ASTWhile;
class ASTTernary;
class ASTFor;

class ASTDeclare;
class ASTDeclareArray;
class ASTDeclareDoubleArray;
class ASTVariableList;
class ASTType;

class ASTLocationIdentifier;
class ASTLocationIdentifierArray;
class ASTLocationIdentifierDoubleArray;

class ASTControl;

class ASTExpr;
class ASTExprUnaryOp;
class ASTExprBinary;
class ASTExprTernary;
class ASTExprIdentifier;

class ASTLiteral;
class ASTLiteralInt;
class ASTLiteralFloat;
class ASTLiteralBool;
class ASTLiteralChar;
class ASTLiteralString;

class ASTvisitor {
public:
    virtual void visit(ASTProg& node) = 0;

    virtual void visit(ASTMethodArg& node) = 0;
    virtual void visit(ASTMethodDecl& node) = 0;
    virtual void visit(ASTMethodCall& node) = 0;

    virtual void visit(ASTStatExpr& node) = 0;
    virtual void visit(ASTStatAssignExpr& node) = 0;

    virtual void visit(ASTBlock& node) = 0;
    virtual void visit(ASTIfElse& node) = 0;
    virtual void visit(ASTWhile& node) = 0;
    virtual void visit(ASTFor& node) = 0;
    virtual void visit(ASTTernary& node) = 0;

    virtual void visit(ASTDeclare& node) = 0;
    virtual void visit(ASTDeclareArray& node) = 0;
    virtual void visit(ASTDeclareDoubleArray& node) = 0;
    virtual void visit(ASTType& node) = 0;
    virtual void visit(ASTVariableList& node) = 0;

    virtual void visit(ASTLocationIdentifier& node) = 0;
    virtual void visit(ASTLocationIdentifierArray& node) = 0;
    virtual void visit(ASTLocationIdentifierDoubleArray& node) = 0;

    virtual void visit(ASTControl& node) = 0;

    virtual void visit(ASTExpr& node) = 0;
    virtual void visit(ASTExprUnaryOp& node) = 0;
    virtual void visit(ASTExprBinary& node) = 0;
    virtual void visit(ASTExprTernary& node) = 0;
    virtual void visit(ASTExprIdentifier& node) = 0;

    virtual void visit(ASTLiteral& node) = 0;
    virtual void visit(ASTLiteralInt& node) = 0;
    virtual void visit(ASTLiteralFloat& node) = 0;
    virtual void visit(ASTLiteralBool& node) = 0;
    virtual void visit(ASTLiteralChar& node) = 0;
    virtual void visit(ASTLiteralString& node) = 0;
};

class ASTnode {
public:
    virtual ~ASTnode()
    {
    }

    //  virtual void printPostFix() const = 0;

    virtual void accept(ASTvisitor& V) = 0;
};

class ASTStat : public ASTnode {
public:
    virtual ~ASTStat()
    {
    }

    //  virtual void printPostFix() const = 0;

    virtual void accept(ASTvisitor& V) = 0;
};

class ASTProg : public ASTnode {
public:
    std::vector<ASTMethodDecl*> methodList;
    virtual void accept(ASTvisitor& v)
    {
        v.visit(*this);
    }
};

class ASTMethodDecl : public ASTnode {
    ASTBlock* block;
    string identifier;
    ASTType *Type;
    std::vector<ASTMethodArg*> argsList;

public:
    ASTMethodDecl(ASTType *_Type, string _identifier, std::vector<ASTMethodArg*> _argsList, ASTBlock* _block)
        : Type(_Type)
        , identifier(_identifier)
        , argsList(_argsList)
        , block(_block)
    {
    }

    ASTType *getType()
    {
        return Type;
    }
    string getIdentifier()
    {
        return identifier;
    }
    ASTBlock* getBlock()
    {
        return block;
    }
    std::vector<ASTMethodArg*> getArgsList()
    {
        return argsList;
    }
    virtual void accept(ASTvisitor& v)
    {
        v.visit(*this);
    }
};

class ASTMethodArg : public ASTnode {
    string identifier;
    ASTType* Type;
    ASTExpr *size1, *size2;

public:
    ASTMethodArg(ASTType* _Type, string _identifier, ASTExpr* _size1, ASTExpr* _size2)
        : Type(_Type)
        , identifier(_identifier)
        , size1(_size1)
        , size2(_size2)
    {
    }

    ASTType* getType()
    {
        return Type;
    }

    string getIdentifier()
    {
        return identifier;
    }
    ASTExpr* getSize1()
    {
        return size1;
    }
    ASTExpr* getSize2()
    {
        return size2;
    }
    virtual void accept(ASTvisitor& v)
    {
        v.visit(*this);
    }
};

class ASTMethodCall : public ASTnode {
    string functionName;
    std::vector<ASTExpr*> exprList;

public:
    ASTMethodCall(string _functionName, std::vector<ASTExpr*> _exprList)
        : functionName(_functionName)
        , exprList(_exprList)
    {
    }

    string getFunctionName()
    {
        return functionName;
    }

    std::vector<ASTExpr*> getExprList()
    {
        return exprList;
    }

    virtual void accept(ASTvisitor& v)
    {
        v.visit(*this);
    }
};

class ASTExpr : public ASTnode {
public:
    virtual void accept(ASTvisitor& v)
    {
        v.visit(*this);
    }
};

class ASTBlock : public ASTnode {
public:
    std::vector<ASTStat*> statementList;
    virtual void accept(ASTvisitor& v)
    {
        v.visit(*this);
    }
};

class ASTFor : public ASTnode {
    ASTExpr *conditionExpr, *initExpr, *incrementExpr;
    ASTBlock* block;

public:
    // std::vector<ASTExpr *> initialExprList;
    // std::vector<ASTExpr *> incrementExprList;
    ASTFor(ASTExpr* _initExpr, ASTExpr* _conditionExpr, ASTExpr* _incrementExpr, ASTBlock* _block)
        : initExpr(_initExpr)
        , conditionExpr(_conditionExpr)
        , incrementExpr(_incrementExpr)
        , block(_block)
    {
    }

    ASTExpr* getInitExpr()
    {
        return initExpr;
    }

    ASTExpr* getConditionExpr()
    {
        return conditionExpr;
    }

    ASTExpr* getIncrementExpr()
    {
        return incrementExpr;
    }

    ASTBlock* getBlock()
    {
        return block;
    }

    virtual void accept(ASTvisitor& v)
    {
        v.visit(*this);
    }
};

class ASTIfElse : public ASTnode {
    ASTExpr* expr;
    ASTBlock *ifBlock, *elseBlock;

public:
    ASTIfElse(ASTExpr* _expr, ASTBlock* _ifBlock, ASTBlock* _elseBlock)
        : expr(_expr)
        , ifBlock(_ifBlock)
        , elseBlock(_elseBlock)
    {
    }

    ASTExpr* getExpr()
    {
        return expr;
    }

    ASTBlock* getIfBlock()
    {
        return ifBlock;
    }

    ASTBlock* getElseBlock()
    {
        return elseBlock;
    }

    virtual void accept(ASTvisitor& v)
    {
        v.visit(*this);
    }
};

class ASTWhile : public ASTnode {
    ASTExpr* expr;
    ASTBlock* block;

public:
    ASTWhile(ASTExpr* _expr, ASTBlock* _block)
        : expr(_expr)
        , block(_block)
    {
    }

    ASTExpr* getExpr()
    {
        return expr;
    }

    ASTBlock* getBlock()
    {
        return block;
    }

    virtual void accept(ASTvisitor& v)
    {
        v.visit(*this);
    }
};

class ASTTernary : public ASTnode {
    ASTExpr* expr;
    ASTStat *stat1, *stat2;

public:
    ASTTernary(ASTExpr* _expr, ASTStat* _stat1, ASTStat* _stat2)
        : expr(_expr)
        , stat1(_stat1)
        , stat2(_stat2)
    {
    }

    ASTExpr* getExpr()
    {
        return expr;
    }

    ASTStat* getStat1()
    {
        return stat1;
    }

    ASTStat* getStat2()
    {
        return stat2;
    }

    virtual void accept(ASTvisitor& v)
    {
        v.visit(*this);
    }
};

class ASTType : public ASTnode {
    string type;

public:
    ASTType(string type)
        : type(type)
    {
    }
    string getType()
    {
        return type;
    }
    virtual void accept(ASTvisitor& v)
    {
        v.visit(*this);
    }
};

class ASTVariableList : public ASTnode {
public:
    ASTType* type;
    vector<ASTDeclare*> identifierList;
    ASTVariableList(ASTType* type, vector<ASTDeclare*> identifierList)
        : type(type)
        , identifierList(identifierList)
    {
    }
    ASTType* getType()
    {
        return type;
    }
    vector<ASTDeclare*> getIdentifierList()
    {
        return identifierList;
    }
    virtual void accept(ASTvisitor& v)
    {
        v.visit(*this);
    }
};

class ASTDeclare : public ASTnode {
    string identifier, op;
    ASTExpr* val;

public:
    ASTDeclare(std::string identifier, std::string op, ASTExpr* val)
        : identifier(identifier)
        , op(op)
        , val(val)
    {
    }
    string getIdentifier()
    {
        return identifier;
    }
    string getOp()
    {
        return op;
    }
    ASTExpr* getVal()
    {
        return val;
    }
    virtual void accept(ASTvisitor& v)
    {
        v.visit(*this);
    }
};

class ASTDeclareArray : public ASTnode {
    string identifier;
    ASTExpr* size;

public:
    ASTDeclareArray(string identifier, ASTExpr *size)
        : identifier(identifier)
        , size(size)
    {
    }
    string getIdentifier()
    {
        return identifier;
    }
    ASTExpr *getSize() {
        return size;
    }
    virtual void accept(ASTvisitor& v)
    {
        v.visit(*this);
    }
};

class ASTDeclareDoubleArray : public ASTnode {
    string identifier;
    ASTExpr *size1, *size2;

public:
    ASTDeclareDoubleArray(string identifier, ASTExpr *size1, ASTExpr *size2)
        : identifier(identifier)
        , size1(size1)
        , size2(size2)
    {
    }
    string getIdentifier()
    {
        return identifier;
    }
    ASTExpr *getSize1() {
        return size1;
    }
    ASTExpr *getSize2() {
        return size2;
    }
    virtual void accept(ASTvisitor& v)
    {
        v.visit(*this);
    }
};

class ASTLiteral : public ASTnode {
public:
    virtual void accept(ASTvisitor& v)
    {
        v.visit(*this);
    }
};

class ASTLiteralInt : public ASTLiteral {

    int intlit;

public:
    ASTLiteralInt(int intlit)
        : intlit(intlit)
    {
    }

    int getIntLit()
    {
        return intlit;
    }

    virtual void accept(ASTvisitor& v)
    {
        v.visit(*this);
    }
};

class ASTLiteralFloat : public ASTLiteral {

    float floatlit;

public:
    ASTLiteralFloat(float floatlit)
        : floatlit(floatlit)
    {
    }

    float getFloatLit()
    {
        return floatlit;
    }

    virtual void accept(ASTvisitor& v)
    {
        v.visit(*this);
    }
};

class ASTLiteralString : public ASTLiteral {

    string stringlit;

public:
    ASTLiteralString(string stringlit)
        : stringlit(stringlit)
    {
    }

    string getStringLit()
    {
        return stringlit;
    }

    virtual void accept(ASTvisitor& v)
    {
        v.visit(*this);
    }
};

class ASTLiteralChar : public ASTLiteral {

    char charlit;

public:
    ASTLiteralChar(char charlit)
        : charlit(charlit)
    {
    }

    char getCharLit()
    {
        return charlit;
    }

    virtual void accept(ASTvisitor& v)
    {
        v.visit(*this);
    }
};

class ASTLiteralBool : public ASTLiteral {

    bool boollit;

public:
    ASTLiteralBool(bool boollit)
        : boollit(boollit)
    {
    }

    bool getBoolLit()
    {
        return boollit;
    }

    virtual void accept(ASTvisitor& v)
    {
        v.visit(*this);
    }
};

class ASTStatExpr : public ASTStat {
public:
    ASTExpr* expr;
    virtual void accept(ASTvisitor& v)
    {
        v.visit(*this);
    }
};

class ASTLocationIdentifier : public ASTnode {
    string identifier;

public:
    ASTLocationIdentifier(string identifier)
        : identifier(identifier)
    {
    }

    string getIdentifier()
    {
        return identifier;
    }

    virtual void accept(ASTvisitor& v)
    {
        v.visit(*this);
    }
};

class ASTLocationIdentifierArray : public ASTnode {
    string identifier;
    ASTExpr* expr;

public:
    ASTLocationIdentifierArray(string identifier, ASTExpr* _expr)
        : identifier(identifier)
        , expr(_expr)
    {
    }

    string getIdentifier()
    {
        return identifier;
    }

    ASTExpr* getExpr()
    {
        return expr;
    }

    virtual void accept(ASTvisitor& v)
    {
        v.visit(*this);
    }
};

class ASTLocationIdentifierDoubleArray : public ASTnode {
    string identifier;
    ASTExpr *expr1, *expr2;

public:
    ASTLocationIdentifierDoubleArray(string identifier, ASTExpr* _expr1, ASTExpr* _expr2)
        : identifier(identifier)
        , expr1(_expr1)
        , expr2(_expr2)
    {
    }

    string getIdentifier()
    {
        return identifier;
    }

    ASTExpr* getExpr1()
    {
        return expr1;
    }

    ASTExpr* getExpr2()
    {
        return expr2;
    }

    virtual void accept(ASTvisitor& v)
    {
        v.visit(*this);
    }
};

class ASTControl : public ASTnode {
    std::string command;
    ASTExpr* expr;

public:
    ASTControl(std::string command, ASTExpr* _expr)
        : command(command)
        , expr(_expr)
    {
    }
    ASTExpr* getExpr()
    {
        return expr;
    }

    std::string getCommand()
    {
        return command;
    }
    virtual void accept(ASTvisitor& v)
    {
        v.visit(*this);
    }
};

class ASTStatAssignExpr : public ASTStat {
public:
    string id;
    ASTExpr* expr;
    virtual void accept(ASTvisitor& v)
    {
        v.visit(*this);
    }
};

class ASTExprUnaryOp : public ASTExpr {
    std::string unary_operator;

    // lhs and rhs can be of any type.
    // So we need to use BaseAST
    ASTExpr* expr;

public:
    // Constructor to initialize binary operator,
    // lhs and rhs of the binary expression.
    ASTExprUnaryOp(std::string op, ASTExpr* _node)
        : unary_operator(op)
        , expr(_node)
    {
    }

    /*  virtual void printPostFix() const 
     {
     	lhs->printPostFix();
     	rhs->printPostFix();
     	std::cout << bin_operator << " "; 
     } */

    ASTExpr* getExpr()
    {
        return expr;
    }

    std::string getUnary_operator()
    {
        return unary_operator;
    }
    virtual void accept(ASTvisitor& v)
    {
        v.visit(*this);
    }
};

class ASTExprBinary : public ASTExpr {
    std::string bin_operator;

    // lhs and rhs can be of any type.
    // So we need to use BaseAST
    ASTExpr* left;
    ASTExpr* right;

public:
    // Constructor to initialize binary operator,
    // lhs and rhs of the binary expression.
    ASTExprBinary(std::string op, ASTExpr* _left, ASTExpr* _right)
        : bin_operator(op)
        , left(_left)
        , right(_right)
    {
    }

    /*  virtual void printPostFix() const 
     {
     	lhs->printPostFix();
     	rhs->printPostFix();
     	std::cout << bin_operator << " "; 
     } */

    ASTExpr* getLeft()
    {
        return left;
    }

    ASTExpr* getRight()
    {
        return right;
    }

    std::string getBinOp()
    {
        return bin_operator;
    }
    virtual void accept(ASTvisitor& v)
    {
        v.visit(*this);
    }
};

class ASTExprTernary : public ASTExpr {

    ASTExpr* first;
    ASTExpr* second;
    ASTExpr* third;

public:
    ASTExprTernary(ASTExpr* first, ASTExpr* second, ASTExpr* third)
        : first(first)
        , second(second)
        , third(third)
    {
    }

    /*   virtual void printPostFix() const
     {
     	first->printPostFix();
     	second->printPostFix();
     	third->printPostFix();
     	std::cout << "? " << std::endl; 
     }  */

    ASTExpr* getFirst()
    {
        return first;
    }

    ASTExpr* getSecond()
    {
        return second;
    }

    ASTExpr* getThird()
    {
        return third;
    }

    virtual void accept(ASTvisitor& v)
    {
        v.visit(*this);
    }
};

class ASTExprIdentifier : public ASTExpr {

    string identifier;

public:
    ASTExprIdentifier(string identifier)
        : identifier(identifier)
    {
    }

    string getIdentifier()
    {
        return identifier;
    }

    virtual void accept(ASTvisitor& v)
    {
        v.visit(*this);
    }

    /* virtual void printPostFix() const
	{
		std::cout << intlit << " " ;
	} */
};

class ASTContext {
public:
    ASTnode* root;

    ~ASTContext()
    {
        clearAST();
    }

    /// free all saved expression trees
    void clearAST()
    {
        delete root;
    }
};
