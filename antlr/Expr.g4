grammar Expr;

prog: (var_decl|method_decl)+ EOF
    ;

var_decl: type (dec(',' dec)*) ';'
    ; 

dec: ID 
    | ID '[' expr ']'
    | ID '[' expr '][' expr ']'
    | ID ASSIGN_OP expr
    ;

method_decl: (type | 'void' | type '[]' | type '[][]') ID '(' ( method_arg (',' method_arg)*)? ')' block
    ;
method_arg: (type (location | ID '[]' | ID '[][]') )
    ;

block: '{' (var_decl|statement)* '}'
    ;

method_call: 'callout' '(' STRING (',' (STRING|expr))* ')'
    ;

statement: IF '(' expr ')' block  (ELSE block)?     #IF
        | location ASSIGN_OP expr ';'       #ASSIGNMENT
        | method_call ';'
        | expr '?' statement ':' statement ';'
        | WHILE '(' expr ')' block
        | FOR '(' (ID ASSIGN_OP expr)* ';' (expr) ';' (expr) ')' block
        | RETURN (expr)? ';'
        | BREAK ';'
        | CONTINUE ';'
        | block
        ;

expr:    ID
    |    location
    |    literal
    |    method_call
    |    SUB_OP expr
    |    '('expr')'
    |    UNARY_OP expr
    |    expr (MUL_OP | DIV_OP | MOD_OP) expr
    |    expr (ADD_OP | SUB_OP) expr
    |    expr (RELATIONAL_OP | EQUALITY_OP) expr
    |    expr BOOL_OP expr
    |    expr CONDITIONAL_OP expr
    |    expr ASSIGN_OP expr
    ;

location: ID
        | ID '[' expr ']'
        | ID '[' expr '][' expr ']'
        ;

literal: INT | FLOAT | STRING | CHAR | BOOL
       ;

FLOAT: (INT'.')?INT
    ;

type: 'int'
    | 'bool'
    | 'float'
    | 'char'
    | 'string'
    | 'uint'
    ;

/*Tokens*/

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

UNARY_OP: '-' | '!' ;

EQUALITY_OP: '==' | '!=' ;
RELATIONAL_OP: '>' | '>=' | '<' | '<=';
ASSIGN_OP: '=' | '+=' | '-=' | '*=' | '/=' | '%=';
BOOL_OP: '&' | '|' | '!';
CONDITIONAL_OP: '||' | '&&' | 'and' | 'or';

INT: [0-9]+;
ID  : [a-zA-Z][a-zA-Z0-9_]*;
STRING: DOUBLE_QUOTE .+? DOUBLE_QUOTE;
CHAR: '\'' (.|'\\0')? '\'';
BOOL: TRUE | FALSE;

TRUE: 'true';
FALSE: 'false';

DOUBLE_QUOTE: '"';

COMMENT : '//' ~[\r\n]*->skip; 
WS : [ \t\n\r]+ -> channel(HIDDEN);
