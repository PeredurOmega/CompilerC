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
statementWithoutAssignment:  empty
                          | declaration
                          | ret
                          | ifBlock
                          | block;

empty: SEMICOLON;

ifBlock: IF '(' (expression | expAssignment) ')' statementWithoutAssignment elseBlock?;

elseBlock: ELSE statement;

ret : RETURN (expression | expAssignment) SEMICOLON;
declaration : TYPE rawDeclaration (',' rawDeclaration)* SEMICOLON;
rawDeclaration : VAR ('=' (VAR '=')* expression)?;
expAssignment : (VAR '=')+ expression;
assignment : expAssignment SEMICOLON;

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


SEMICOLON : ';';

IF : 'if';
ELSE: 'else';

RETURN : 'return' ;
TYPE : 'int';
COMMENT : (('/*' .*? '*/') | ('//' .*? ('\n' | '\r\n'))) -> skip ;
CONST : [0-9]+ ;
VAR : [a-zA-Z_][a-zA-Z_$0-9]*;
DIRECTIVE : '#' .*? '\n' -> skip ;
WS    : [ \t\r\n] -> channel(HIDDEN);
