grammar Expr;

prog: (expr ';') + EOF
    ;

expr:   IDENTIFIER
    |   literal
    |   '-' expr
    |   '('expr')'
    |   expr (MUL_OP | DIV_OP | REM_OP) expr
    |   expr (ADD_OP | SUB_OP) expr
    |   expr (RELATIONAL_OP | EQUALITY_OP) expr
    ;

literal: INT | FLOAT
       ;

FLOAT: INT'.'INT
    ;

/*Tokens*/
MUL_OP: '*';
DIV_OP: '/';
REM_OP: '%';
ADD_OP: '+';
SUB_OP: '-';
EQUALITY_OP: '==' | '!=' ;
RELATIONAL_OP: '>' | '>=' | '<' | '<=';
INT: [0-9]+;
IDENTIFIER  : [a-zA-Z][a-zA-Z0-9_]*;
COMMENT : '//' ~[\r\n]*->skip; 
NS : [ \t\n]+ -> skip;
