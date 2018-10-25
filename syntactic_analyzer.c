#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#ifndef LEXICAL_PARSER_ZZ
#include "syntactic_analyzer.h"
#define LEXICAL_PARSER_ZZ
#endif

// ------------ Global Variables ------------

/**
 *  Global variable indicating type of the read token.
 */
token_type token;

// ------------------------------------------

// ------------ Main program ------------

int main() {
  _read_token();
  while (token != END_OF_FILE) {
    if (_decl()) {
      puts("OK");
    } else {
      puts("NOK");
    }
    _read_token();
  }
  return 0;
}

// --------------------------------------

// ------------ Functions and Grammatical rules implementations ------------

void _read_token() {
  token = (token_type)yylex();
}

bool _type() {
  bool result = false;
  if (token == INT) {
    result = true;
  } else if (token == DOUBLE) {
    result = true;
  } else if (token == BOOL) {
    result = true;
  }
  return result;
}

bool _const() {
  bool result = false;
  if (token == INT_V) {
    result = true;
  } else if (token == DOUBLE_V) {
    result = true;
  } else if (token == BOOL_V_T) {
    result = true;
  } else if (token == BOOL_V_F) {
    result = true;
  }
  return result;
}

bool _decl_aux() {
  bool result = false;
  if (token == SEMI_COLUMN) {
    result = true;
  } else if (_const()) {
    _read_token();
    if (token == SEMI_COLUMN) {
      result = true;
    }
  }
  return result;
}

bool _decl() {
  bool result = false;
  if (token == IDENTIFIER) {
    _read_token();
    if (_type()) {
      _read_token();
      if (_decl_aux()) {
        result = true;
      }
    }
  }
  return result;
}

// -------------------------------------------------------------------------