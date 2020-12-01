#ifndef INCLUDED_SYMBOLTABLE_H
#define INCLUDED_SYMBOLTABLE_H
#include <map>
#include <set>
#include <stack>
#include <vector>

enum DataType { INT,
    BOOL,
    VOID,
    STRING,
    CHAR,
    FLOAT,
    UINT };

typedef struct VarSymbol {
    std::string identifier;
    int size1, size2, scope;
    DataType Type;
} VarSymbol;

typedef struct FuncSymbol {
    std::string identifier;
    DataType Type;
    std::vector<std::pair<std::string, VarSymbol*>> args;
} FuncSymbol;

std::set<std::string> reservedWords = { "void", "bool", "int", "unit", "char", "float", "break", "callout", "continue", "if", "else", "true", "false", "while", "for", "return", "read", "print" };

class SymbolTable {
public:
    int lineNumber = 0, scope = 0;
    std::map<std::pair<std::string, int>, VarSymbol*> VarSymbolTable; // ID, Scope
    std::map<std::string, FuncSymbol*> FuncSymbolTable;
    std::stack<int> scopes;

    DataType checkFuncSignature(std::string funcName, std::vector <DataType> &typeSignature) {
        if (FuncSymbolTable.find(funcName) == FuncSymbolTable.end()) {
            std::cout << "Function " + funcName + " used before declaration." << std::endl;
            exit(0);
        }
        FuncSymbol *symbol = FuncSymbolTable[funcName];
        if (symbol->args.size() != typeSignature.size()) {
            std::cout << "Wrong number of arguments to the function " << funcName << " near line " << lineNumber << std::endl;
            exit(0);
        }
        for (int i = 0; i < typeSignature.size(); ++i) {
            if (symbol->args[i].second->Type != typeSignature[i]) {
                std::cout << "Argument type mismatch near line " << lineNumber << std::endl;
                exit(0);
            }
        }
        return symbol->Type;
    }

    void addFunction(FuncSymbol *symbol) {
        std::string id = symbol->identifier;
        if (FuncSymbolTable.find(id) != FuncSymbolTable.end()) {
            std::cout << "Function " << id << " redeclared near line " << lineNumber << std::endl;
            exit(0);
        }
        if (reservedWords.find(id) != reservedWords.end()) {
            std::cout << "Can not use reserved word " << id << " as identifier near line " << lineNumber << std::endl;
            exit(0);
        }
        for (auto arg : symbol->args) {
            if (reservedWords.find(arg.first) != reservedWords.end()) {
                std::cout << "Can not use reserved word " << arg.first << " as identifier near line " << lineNumber << std::endl;
            }
        }
        FuncSymbolTable[id] = symbol;
        return;
    }

    DataType checkVariable(std::string identifier) {
        int currScope = scopes.top();
        do {
            if (VarSymbolTable.find(make_pair(identifier, currScope)) != VarSymbolTable.end()) {
                return VarSymbolTable[make_pair(identifier, currScope)]->Type;
            }
        } while (--currScope);
        return VOID;
    }

    void insertVariable(VarSymbol *symbol) {
        // if (checkVariable(symbol->identifier) != VOID and VarSymbolTable[make_pair(symbol->identifier, currScope)]->scope == scopes.top()) {
        // }
        if (VarSymbolTable.find(make_pair(symbol->identifier, symbol->scope)) != VarSymbolTable.end()) {
            std::cout << "Variable " << symbol->identifier << " redeclared in the same scope near line " << lineNumber << std::endl;
            exit(0);
        }
        VarSymbolTable[make_pair(symbol->identifier, symbol->scope)] = symbol;
    }
};

#endif
