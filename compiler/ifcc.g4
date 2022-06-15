grammar ifcc;

axiom : prog EOF;

prog : function*;
function: (TYPE|'void') VAR '(' parameters? ')' block;

parameters : parameter (',' parameter)* ;
parameter : TYPE VAR ;

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
            |op=('-'|'!') expression #unary
            |expression op=('<' | '<=' | '==' | '!=' | '>=' | '>') expression #compare
            ;

ifBlock: IF '(' expression ')' (block | statement) elseBlock?;
elseBlock: ELSE (ifBlock|block|statement);

IF : 'if';
ELSE: 'else';

RETURN : 'return' ;
TYPE : 'int';
COMMENT : (('/*' .*? '*/') | ('//' .*? ('\n' | '\r\n'))) -> skip ;
CONST : [0-9]+ ;
VAR : [a-zA-Z_][a-zA-Z_$0-9]*;
DIRECTIVE : '#' .*? '\n' -> skip ;
WS    : [ \t\r\n] -> channel(HIDDEN);
