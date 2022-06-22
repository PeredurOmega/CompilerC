grammar ifcc;

axiom : prog EOF;

prog : function*;
function: (TYPE|'void') VAR '(' parameters? ')' block;

parameters : parameter (',' parameter)* ;
parameter : TYPE VAR ;

block : '{' statement* '}';
statement : statementWithoutDeclaration
          | declaration;

// Statement without declaration for inline statment (next to if, while...)
statementWithoutDeclaration:  empty
                          | assignment
                          | ret
                          | ifBlock
                          | whileBlock
                          | block;

empty: expression? SEMICOLON;

ifBlock: IF '(' (expression | expAssignment) ')' statementWithoutDeclaration elseBlock?;
elseBlock: ELSE statement;

whileBlock: WHILE '(' expression ')' statementWithoutDeclaration;

ret : RETURN (expression | expAssignment) SEMICOLON;
declaration : TYPE rawDeclaration (',' rawDeclaration)* SEMICOLON;
rawDeclaration : VAR ('=' (VAR '=')* expression)?;
expAssignment : (VAR '=')+ expression;
assignment : expAssignment SEMICOLON;

expression : VAR #variable
            |CONST #constant
            |'(' (expression | expAssignment)')' #parenthesis
            |VAR '(' parameters? ')' #functionCall
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
WHILE: 'while';

RETURN : 'return' ;
TYPE : 'int';
COMMENT : (('/*' .*? '*/') | ('//' .*? ('\n' | '\r\n'))) -> skip ;
CONST : [0-9]+ ;
VAR : [a-zA-Z_][a-zA-Z_$0-9]*;
DIRECTIVE : '#' .*? '\n' -> skip ;
WS    : [ \t\r\n] -> channel(HIDDEN);
