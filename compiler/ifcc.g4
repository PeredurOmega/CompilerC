grammar ifcc;

axiom : prog EOF;

prog : function*;
function: (TYPE|'void') VAR '(' parameters? ')' block;

parameters : parameter (',' parameter)* ;
parameter : TYPE VAR ;

block : '{' statement* '}';
statement : statementWithoutAssignment
          | assignment;

// Statement without assignment for inline statment (next to if, while...)
statementWithoutAssignment:  ';'
                          | declaration
                          | ret
                          | ifBlock
                          | block;

ifBlock: IF '(' (expression | expAssignment) ')' statementWithoutAssignment elseBlock?;

elseBlock: ELSE statement;

ret : RETURN (expression | expAssignment) ';';
declaration : TYPE rawDeclaration (',' rawDeclaration)* ';';
rawDeclaration : VAR ('=' (VAR '=')* expression)?;
expAssignment : (VAR '=')+ expression;
assignment : expAssignment ';';

expression : VAR #variable
            |CONST #constant
            |'(' (expression | expAssignment)')' #parenthesis
            |op=('-'|'!'|'+'|'~') expression #unary
            |expression op=('*' | '/' | '%') expression #timesDivModulo
            |expression op=('+' | '-') expression #addSub
            |expression op=('<<' | '>>') expression #shift
            |expression op=('<' | '<=' | '>=' | '>') expression #compare
            |expression op=('==' | '!=') expression #equal
            |expression op='&' expression #bitwiseAnd
            |expression op='^' expression #bitwiseXor
            |expression op='|' expression #bitwiseOr
            |expression op='&&' expression #logicalAnd
            |expression op='||' expression #logicalOr
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
