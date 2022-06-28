grammar ifcc;

axiom : prog EOF;

prog : ( function | functionDeclaration | staticVariable )*;
function: (TYPE|'void') VAR '(' parameters? ')' block;
functionDeclaration: (TYPE|'void') VAR '(' parameters? ')' SEMICOLON ;
// TODO ADD SUPPORT FOR PROPAGATED CONSTANT
staticVariable: STATIC? TYPE VAR '=' CONST SEMICOLON;

parameters : parameter (',' parameter)* ;
parameter : TYPE VAR ;

arguments : argument (',' argument)* ;
argument : expression ;

block : '{' statement* '}';
statement : statementWithoutDeclaration
          | declaration;

// Statement without declaration for inline statment (next to if, while...)
statementWithoutDeclaration: assignment
                          | ret
                          | ifBlock
                          | whileBlock
                          | procedureCall
                          | block
                          | empty;

procedureCall : VAR '(' arguments? ')' SEMICOLON;

empty: exp? SEMICOLON;

ifBlock: IF '(' (exp | expAssignment) ')' statementWithoutDeclaration elseBlock?;
elseBlock: ELSE statement;

whileBlock: WHILE '(' exp | expAssignment ')' statementWithoutDeclaration;

ret : RETURN (exp | expAssignment) SEMICOLON;
declaration : TYPE rawDeclaration (',' rawDeclaration)* SEMICOLON;
rawDeclaration : VAR ('=' (VAR '=')* exp)?;
expAssignment : (VAR '=')+ exp;
assignment : expAssignment SEMICOLON;

exp: expression;
expression : VAR #variable
            |CONST #constant
            |'(' (expression | expAssignment)')' #parenthesis
            |VAR '(' arguments? ')' #functionCall
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
STATIC : 'static';
COMMENT : (('/*' .*? '*/') | ('//' .*? ('\n' | '\r\n'))) -> skip ;
CONST : [0-9]+ ;
VAR : [a-zA-Z_][a-zA-Z_$0-9]*;
DIRECTIVE : '#' .*? '\n' -> skip ;
WS    : [ \t\r\n] -> channel(HIDDEN);
