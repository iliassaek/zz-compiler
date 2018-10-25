%option noyywrap
%option caseless

%{
#ifndef LEXICAL_PARSER_ZZ
#include "syntactic_analyzer.h"
#define LEXICAL_PARSER_ZZ
#endif
%}

IDENTIFIER        [A-Za-z_][A-Za-z0-9_]*
INT 							"int"
DOUBLE 						"double"
BOOL 							"bool"
INT_V   	        [\-\+]?[0-9]+
DOUBLE_V          [\-\+]?[0-9]+\.[0-9]+
BOOL_V_T          "true"
BOOL_V_F          "false"
OPERATION         "="|"*"|"+"|"=="|"/"|"-"|"/="|"+="|"-="|"*="|"<"|"<="|">"|">="
KEY_WORD          "begin"|"end"|"for"|"to"|"do"|"endfor"|"print"|"if"|"else"|"then"|"endif"|"while"|"endwhile"

%%

{KEY_WORD}               printf("KEY_WORD(%s)\n", yytext);
{INT} 									 return INT;
{DOUBLE} 								 return DOUBLE;
{BOOL} 									 return BOOL;
{INT_V}                  return INT_V;
{DOUBLE_V}               return DOUBLE_V;
{BOOL_V_T}               return BOOL_V_T;
{BOOL_V_F}               return BOOL_V_F;
{IDENTIFIER}             return IDENTIFIER;
{OPERATION}              printf("OPERATION(%s)\n", yytext);
"("|")"                  printf("BRACKET(%s)\n", yytext);
";" 										 return SEMI_COLUMN;
[\n\t ]+
"REM"[^\n]*
.                        printf("ERROR(%s)\n", yytext);

%%

