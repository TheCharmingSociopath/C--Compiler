grammar Expr;

/** The start rule; begin parsing here. */

prog: (methodDecl)+ EOF;

methodDecl: (type | 'void') IDENTIFIER '(' ( methodArg1 (',' methodArg1)*)? ')' block
    ;

methodArg1: type IDENTIFIER #methodArg
    |       type IDENTIFIER '[' expr ']' #methodArg1D
    |       type IDENTIFIER '[' expr ']' '[' expr ']' #methodArg2D
    ;

methodCall: 'callout(' STRING (',' (expr))* ');'
    ;

block: '{' statement+ '}'           
    ;

statement : IF '(' expr ')' block  (ELSE block)?     #statIfElse
          | WHILE '(' expr ')' block    #statWhile
          | expr '?' statement ':' statement ';'    #statTernary
          | FOR '(' expr ';' expr ';' expr ')' block    #statFor
          | location ASSIGN expr';'   #statAssignExpr
          | control';'                  #statementControl
          | variable                    #statVariable
          | block                       #statBlock
          | methodCall                     #statMethodCall
          ;

variable: type declare(','declare)*';'
    ;

declare: location                     #declareLocation
    |    IDENTIFIER '=' expr            #declareIdentifierAssign 
    ;

control: RETURN (expr)?           #controlReturn
       |   BREAK                  #controlBreak
       |   CONTINUE               #controlContinue
       ;

expr:   literal #exprLiteral
    |   IDENTIFIER #exprIdentifier
    |   '(' expr ')'             #exprParenthesis
    |   expr op=(MUL_OP|DIV_OP|MOD_OP) expr   #exprMulDivModOp
    |   expr op=(ADD_OP|SUB_OP) expr   #exprAddSubOp
    |   expr op=RELATIONAL_OP expr         #exprRelationalOp
    |   expr op=EQUALITY_OP expr          #exprEqualityOp
    |   expr op=BOOL_OP expr        #exprBoolOp
    |   expr op=CONDITIONAL_OP expr        #exprConditionalOp
    |   expr op=ASSIGN expr      #exprAssignOp
    |   op=UNARY_OP expr               #exprUnaryOp
    |   methodCall                  #exprMethodCall
    ;

location: IDENTIFIER    #locationIdentifier
        | IDENTIFIER '[' expr ']'   #locationIdentifierArray
        | IDENTIFIER '[' expr '][' expr ']'  #locationIdentifierDoubleArray
        ;

type: 'int'
    | 'bool'
    | 'float'
    | 'char'
    | 'string'
    | 'uint'
    ;

literal: INT                     #literalInt
    |  FLOAT                     #literalFloat
    |  BOOL                      #literalBool
    |  CHAR                      #literalChar
    |  STRING                    #literalString
    ;

IF: 'if';
ELSE: 'else';
WHILE: 'while';
FOR: 'for';
RETURN: 'return';
BREAK: 'break';
CONTINUE: 'continue';

MUL_OP: '*';
DIV_OP: '/';
MOD_OP: '%';
ADD_OP: '+';
SUB_OP: '-';

ASSIGN: '=';

UNARY_OP: '-' | '!' ;

EQUALITY_OP: '==' | '!=' ;
RELATIONAL_OP: '>' | '>=' | '<' | '<=';
ASSIGN_OP: '=' | '+=' | '-=' | '*=' | '/=' | '%=';
BOOL_OP: '&' | '|' | '!';
CONDITIONAL_OP: '||' | '&&' | 'and' | 'or';

INT: [0-9]+;
IDENTIFIER  : [a-zA-Z][a-zA-Z0-9_]*;
FLOAT: (INT'.')?INT;
STRING: DOUBLE_QUOTE .+? DOUBLE_QUOTE;
CHAR: '\'' (.)? '\'';
BOOL: 'true' | 'false';

DOUBLE_QUOTE: '"';

COMMENT : '//' ~[\r\n]*->skip; 
WS : [ \t\n\r]+ -> channel(HIDDEN);
