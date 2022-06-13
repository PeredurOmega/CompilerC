grammar ifcc;

axiom : prog ;

prog : 'int' 'main' '(' ')' '{' statement* RETURN CONST ';' '}' ;
statement : declaration
          | affectation ;
declaration : TYPE (init| VAR) (',' (init| VAR))*';';
init : VAR '=' expression ;
affectation : VAR '=' expression ';';
expression : VAR #variable
            |CONST #constant
            |VAR'='expression #varexpr
            ;

RETURN : 'return' ;
TYPE : 'int';
CONST : [0-9]+ ;
VAR : [a-zA-Z_][a-zA-Z_$0-9]*;
COMMENT : '/*' .*? '*/' -> skip ;
DIRECTIVE : '#' .*? '\n' -> skip ;
WS    : [ \t\r\n] -> channel(HIDDEN);