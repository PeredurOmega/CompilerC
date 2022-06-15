grammar ifcc;

axiom : prog ;

prog : function*;
function: (TYPE|'void') VAR '(' ')' block;
block : '{' statement* '}';
statement : ';'
          | declaration
          | affectation
          | ret
          | ifBlock
          | block;
ret : RETURN expression ';'+;
declaration : TYPE (init| VAR) (',' (init| VAR))* ';'+;
init : VAR '=' expression ;
affectation : VAR '=' expression ';'+;
expression : VAR #variable
            |CONST #constant
            |VAR'='expression #varexpr
            |'(' expression ')' #parenthesis
            |expression op=('*' | '/' | '%') expression #times
            |expression op=('+' | '-') expression #addsub
            |op='-' expression #unary
            |expression op=('<' | '<=' | '==' | '!=' | '>=' | '>') expression #compare
            ;

ifBlock: IF '(' expression ')' (block | statement) elseBlock?;
elseBlock: ELSE (ifBlock|block|statement);

IF : 'if';
ELSE: 'else';

RETURN : 'return' ;
TYPE : 'int';
CONST : [0-9]+ ;
VAR : [a-zA-Z_][a-zA-Z_$0-9]*;
COMMENT : '/*' .*? '*/' -> skip ;
DIRECTIVE : '#' .*? '\n' -> skip ;
WS    : [ \t\r\n] -> channel(HIDDEN);