#include <stdio.h>
#include <stdbool.h>

// ------------ Structs and Enums declarations ------------

typedef enum {
	END_OF_FILE,
	INT,
	DOUBLE,
	BOOL,
	INT_V,
	DOUBLE_V,
	BOOL_V_T,
	BOOL_V_F,
	SEMI_COLUMN,
	IDENTIFIER
} token_type;

// --------------------------------------------------------

// ------------ Functions definitions ------------

/**
 *  Lexical analyzer function coming from the generated lex.yy.c file using flex.
 */
extern int yylex();

/**
 *  Wrapper to yylex().
 */
void _read_token();

// -----------------------------------------------

// ------------ Grammatical rules definitions ------------

/**
 *  Each function returns true if the phrase is well constructed 
 *  using the derivation from the corresponding grammatical rule.
 */

bool _type();

bool _const();

bool _decl_aux();

bool _decl();

// -------------------------------------------------------