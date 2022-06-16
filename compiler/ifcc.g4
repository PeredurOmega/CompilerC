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

ifBlock: IF '(' expression ')' statement elseBlock?;
elseBlock: ELSE statement;

ret : RETURN expression ';';
declaration : TYPE rawDeclaration (',' rawDeclaration)* ';';
rawDeclaration : VAR ('=' expression)?;
affectation : VAR '=' expression ';';

expression : VAR #variable
            |CONST #constant
            |VAR'='expression #varexpr
            |'(' expression ')' #parenthesis
            |op=('-'|'!'|'+'|'~') expression #unary
            |expression op=('*' | '/' | '%') expression #times
            |expression op=('+' | '-') expression #addsub
            |expression op=('<<' | '>>') expression #shift
            |expression op=('<' | '<=' | '>=' | '>') expression #compare
            |expression op=('==' | '!=') expression #equal
            |expression op='&' expression #bitwiseand
            |expression op='^' expression #bitwisexor
            |expression op='|' expression #bitwiseor
            |expression op='&&' expression #logicaland
            |expression op='||' expression #logicalor
            ;


IF : 'if';
ELSE: 'else';

RETURN : 'return' ;
TYPE : 'int';
COMMENT : (('/*' .*? '*/') | ('//' .*? ('\n' | '\r\n'))) -> skip ;
CONST : [0-9]+ ;
VAR : [a-zA-Z_][a-zA-Z_$0-9]*;
DIRECTIVE : '#' .*? '\n' -> skip ;
WS    : [ \t\r\n] -> channel(HIDDEN);
