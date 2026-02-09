/* Skeleton and definitions for generating a LALR(1) parser in C++ */
%skeleton "lalr1.cc" 
%defines
%define parse.error verbose
%define api.value.type variant
%define api.token.constructor

/* Required code included before the parser definition begins */
%code requires{
  #include <string>
  #include "Node.h"
  #define USE_LEX_ONLY false //change this macro to true if you want to isolate the lexer from the parser.
}

/* Code included in the parser implementation file */
%code{
  #define YY_DECL yy::parser::symbol_type yylex()
  YY_DECL;
  
  Node* root;
  extern int yylineno;
}

/* Token definitions for the grammar */
/* Tokens represent the smallest units of the language, like operators and parentheses */


%token <std::string> PLUSOP MINUSOP MULTOP INT LP RP FLOAT DIVOP NEWLINE POWER FLOAT_TYPE INT_TYPE VOLATILE ID COLON ASSIGN RETURN PRINT LCB RCB MAIN

%token END 0 "end of file"

/* Operator precedence and associativity rules */
/* Used to resolve ambiguities in parsing expressions See https://www.gnu.org/software/bison/manual/bison.html#Precedence-Decl */ 
%left PLUSOP MINUSOP
%left MULTOP DIVOP POWER

/* Specify types for non-terminals in the grammar */
/* The type specifies the data type of the values associated with these non-terminals */
%type <Node *> root expression rules factor math_expression create_variable type return print block main


/* Grammar rules section */ 
/* This section defines the production rules for the language being parsed */
%%
root:       
  expression {
    root = $1;
};

expression:
  expression rules {
    $$ = $1;
    $$->children.push_back($2);
  }
  |
  rules {
    $$ = new Node("Rules", "", yylineno);
    $$->children.push_back($1);
  }
  ;

rules: 
  math_expression {
    $$ = $1;
  }
  |
  create_variable {
    $$ = $1;
  }
  |
  print {
    $$ = $1;
  }
  |
  return {
    $$ = $1;
  }
  |
  block {
    $$ = $1;
  }
  |
  main {
    $$ = $1;
  }
  ;

math_expression:
    math_expression PLUSOP math_expression {
        $$ = new Node("Add", "", yylineno);
        $$->children.push_back($1);
        $$->children.push_back($3);
    }
  | math_expression MINUSOP math_expression {
        $$ = new Node("Sub", "", yylineno);
        $$->children.push_back($1);
        $$->children.push_back($3);
    }
  | math_expression MULTOP math_expression {
        $$ = new Node("Mul", "", yylineno);
        $$->children.push_back($1);
        $$->children.push_back($3);
    }
  | math_expression POWER math_expression {
        $$ = new Node("Power", "", yylineno);
        $$->children.push_back($1);
        $$->children.push_back($3);
  }
  |
  math_expression DIVOP math_expression {
        $$ = new Node("Div", "", yylineno);
        $$->children.push_back($1);
        $$->children.push_back($3);
  }
  | 
  factor {
        $$ = $1;
  }
  ;

factor: 
  INT {
    $$ = new Node("Int", "", yylineno);
  }
  |
  FLOAT {
    $$ = new Node("Float", "", yylineno);
  }
  |
  LP math_expression RP {
    $$ = $2;
  };

type: 
  INT_TYPE {
    $$ = new Node("Int_type", "", yylineno);
  }
  |
  FLOAT_TYPE {
    $$ = new Node("Float_type", "", yylineno);
  }
  ;

create_variable:
  VOLATILE ID COLON type ASSIGN math_expression {
        $$ = new Node("Variable", "", yylineno);
        $$->children.push_back(new Node("Volatile", "", yylineno));
        $$->children.push_back(new Node("Id", "", yylineno)); /*Change text?*/
        $$->children.push_back($4);
        $$->children.push_back($6);
  }
  ;

print:
  PRINT LP ID RP {
        $$ = new Node("Print", "", yylineno);
        $$->children.push_back(new Node("Lp", "", yylineno));
        $$->children.push_back(new Node("Id", "", yylineno));
        $$->children.push_back(new Node("Rp", "", yylineno)); 
  }
  ;

return:
  RETURN ID {
    $$ = new Node("Return", "", yylineno);
    $$->children.push_back(new Node("Id", "", yylineno));
  }
  ;

block:
  LCB expression RCB {
    $$ = new Node("Block", "", yylineno);
    $$->children.push_back($2);
  }
  ;

main:
  MAIN LP RP COLON type block {
    $$ = new Node("main", "", yylineno);
    $$->children.push_back($6);
  }


/* ./compiler < test_files/valid/test1.cpm */


