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


%token <std::string> PLUSOP MINUSOP MULTOP INT LP RP FLOAT DIVOP POWER FLOAT_TYPE INT_TYPE VOLATILE ID COLON ASSIGN RETURN PRINT LCB RCB MAIN FOR COMMA AND OR EQTO NEQ LE GE LT GT IF SLB SRB COMMENT CLASS READ DOT LENGTH ELSE TRUE FALSE INT_ARRAY_TYPE FLOAT_ARRAY_TYPE VOID_TYPE BOOLEAN_TYPE EXCLAMATION_MARK BREAK CONTINUE

%token END 0 "end of file"

/* Operator precedence and associativity rules */
/* Used to resolve ambiguities in parsing expressions See https://www.gnu.org/software/bison/manual/bison.html#Precedence-Decl */ 
%left PLUSOP MINUSOP
%left MULTOP DIVOP
%right POWER

%left OR
%left AND
%right EXCLAMATION_MARK

/* Specify types for non-terminals in the grammar */
/* The type specifies the data type of the values associated with these non-terminals */
%type <Node *> root statements expression condition relation math_expression unary term factor primary variable type return print block main for_statement relational_operators if_statement number_array array_call array_decl comment class function_decl function_call parameters read arguments else_statement


/* Grammar rules section */ 
/* This section defines the production rules for the language being parsed */
%%
root:       
  statements {
    root = $1;
};

statements :
  %empty {
      $$ = new Node("Statements", "", yylineno);
    }
  | 
  statements expression {
      $$ = $1;
      $$->children.push_back($2);
    }
  ; 

expression:
  variable {
    $$ = $1;
  }
  |
  read {
    $$ = $1; 
  }
  |
  print {
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
  |
  for_statement {
    $$ = $1;
  }
  |
  if_statement {
    $$ = $1;
  }
  |
  array_decl {
    $$ = $1;
  }
  |
  comment {
    $$ = $1;
  }
  |
  return {
    $$ = $1;
  }
  |
  class {
    $$ = $1;
  }
  |
  function_decl {
    $$ = $1;
  }
  |
  function_call {
    $$ = $1;
  }
  |
  else_statement {
    $$ = $1;
  }
  ;
condition:
    condition OR condition {
      $$ = new Node("Or", "", yylineno);
      $$->children.push_back($1);
      $$->children.push_back($3);
    }
  | condition AND condition {
      $$ = new Node("And", "", yylineno);
      $$->children.push_back($1);
      $$->children.push_back($3);
    }
  | EXCLAMATION_MARK condition {
      $$ = new Node("Not", "", yylineno);
      $$->children.push_back($2);
    }
  | LP condition RP {
      $$ = $2;
    }
  | relation {
      $$ = $1;
    }
  | TRUE {
      $$ = new Node("Boolean", "", yylineno);
      $$->children.push_back(new Node("", $1, yylineno));
    }
  | FALSE {
      $$ = new Node("Boolean", "", yylineno);
      $$->children.push_back(new Node("", $1, yylineno));
    }
  ;

relation:
    math_expression relational_operators math_expression {
      Node *op = $2;
      op->children.push_back($1);
      op->children.push_back($3);
      $$ = op;
    }
  ;

math_expression:
      math_expression PLUSOP term {
          $$ = new Node("Add","",yylineno);
          $$->children.push_back($1);
          $$->children.push_back($3);
      }
    | math_expression MINUSOP term {
          $$ = new Node("Sub","",yylineno);
          $$->children.push_back($1);
          $$->children.push_back($3);
      }
    | term {
          $$ = $1;
      }
;

term:
      term MULTOP factor {
          $$ = new Node("Multiplication", "", yylineno);
          $$->children.push_back($1);
          $$->children.push_back($3);
      }
    | term DIVOP factor {
          $$ = new Node("Division","",yylineno);
          $$->children.push_back($1);
          $$->children.push_back($3);
      }
    | factor {
          $$ = $1;
      }
;

factor:
      unary {
          $$ = $1;
      }
    | unary POWER factor {
          $$ = new Node("Pow","",yylineno);
          $$->children.push_back($1);
          $$->children.push_back($3);
      }
;

unary:
      MINUSOP unary {
          $$ = new Node("Negate", "", yylineno);
          $$->children.push_back($2);
      }
    | primary {
          $$ = $1;
      }
;


primary:
      ID {
          Node * identifier = new Node("Identifier", "", yylineno);
          identifier->children.push_back(new Node("", $1, yylineno));
          $$ = identifier;
      }
    | INT {
          $$ = new Node("Integer", "", yylineno);
          $$->children.push_back(new Node("", $1, yylineno));
      }
    | FLOAT {
          $$ = new Node("Float", "", yylineno);
          $$->children.push_back(new Node("", $1, yylineno));
      }
    | function_call {
          $$ = $1;
      }
    | array_call {
          $$ = $1;
      }
    | LP math_expression RP {
          $$ = $2;
      }
    ;



type: 
  INT_TYPE {
    Node * type = new Node("Type", "", yylineno);
    type->children.push_back(new Node("Integer", "", yylineno));
    $$ = type;
  }
  |
  FLOAT_TYPE {
    Node * type = new Node("Type", "", yylineno);
    type->children.push_back(new Node("Float", "", yylineno));
    $$ = type;
  }
  |
  INT_ARRAY_TYPE {
    Node * type = new Node("Type", "", yylineno);
    type->children.push_back(new Node("Integer_array", "", yylineno));
    $$ = type;
  }
  |
  FLOAT_ARRAY_TYPE {
    Node * type = new Node("Type", "", yylineno);
    type->children.push_back(new Node("Float_array", "", yylineno));
    $$ = type;
  }
  |
  VOID_TYPE {
    Node * type = new Node("Type", "", yylineno);
    type->children.push_back(new Node("Void", "", yylineno));
    $$ = type;
  }
  |
  BOOLEAN_TYPE {
    Node * type = new Node("Type", "", yylineno);
    type->children.push_back(new Node("Boolean", "", yylineno));
    $$ = type;
  }
  ;

variable:
  VOLATILE ID COLON type ASSIGN math_expression {
    $$ = new Node("VarDecl", "", yylineno);

    Node * modifier = new Node("Modifier", "", yylineno);
    modifier->children.push_back(new Node("Volatile", "", yylineno));


    Node * identifier = new Node("Identifier", "", yylineno);
    identifier->children.push_back(new Node("", $2, yylineno));
    
     $$->children.push_back(modifier);
     $$->children.push_back(identifier);
     $$->children.push_back($4);
     $$->children.push_back($6);
    
  }
  |
  VOLATILE ID COLON type {

    $$ = new Node("VarDecl", "", yylineno);

    Node * modifier = new Node("Modifier", "", yylineno);
    modifier->children.push_back(new Node("Volatile", "", yylineno));

    Node * identifier = new Node("Identifier", "", yylineno);
    identifier->children.push_back(new Node("", $2, yylineno));

     $$->children.push_back(modifier);
     $$->children.push_back(identifier);
     $$->children.push_back($4);

  }
  |
  VOLATILE ID COLON type ASSIGN ID LP RP DOT function_call {
    $$ = new Node("Variable", "", yylineno);
    $$->children.push_back(new Node("Volatile", "", yylineno));
    $$->children.push_back(new Node("Id", "", yylineno));
    $$->children.push_back($4);
    $$->children.push_back($10);
  }
  |
  VOLATILE ID COLON ID ASSIGN function_call {
    $$ = new Node("Variaasasdasdble", "", yylineno);
    $$->children.push_back(new Node("Volatile", "", yylineno));
    $$->children.push_back(new Node("Id", "", yylineno));
    $$->children.push_back($6);
  }
  |
  ID DOT function_call {
    $$ = new Node("Id", "", yylineno);
    $$->children.push_back($3);
  }
  |
  ID ASSIGN math_expression {
    $$ = new Node("Re_assign", "", yylineno);
    Node * identifier = new Node("Identifier", "", yylineno);
    identifier->children.push_back(new Node("", $1, yylineno));
    $$->children.push_back(identifier);
    $$->children.push_back($3);
  }
  |
  VOLATILE ID COLON type ASSIGN ID DOT function_call {
    $$ = new Node("Variable", "", yylineno);
    $$->children.push_back(new Node("Id", "", yylineno));
    $$->children.push_back($4);
  }
  |
  ID ASSIGN condition {
    $$ = new Node("Re_assign", "", yylineno);
    Node * identifier = new Node("Identifier", "", yylineno);
    identifier->children.push_back(new Node("", $1, yylineno));
    $$->children.push_back(identifier);
    $$->children.push_back($3);
  }
  ;

read:
  READ LP ID RP {
    $$ = new Node("Read", "", yylineno);
    $$->children.push_back(new Node("Id", "", yylineno)); 
  }
  ;

print:
  PRINT LP math_expression RP {
    $$ = new Node("Print", "", yylineno);
    $$->children.push_back($3);
  }
  |
  PRINT LP ID DOT function_call RP {
    $$ = new Node("Print", "", yylineno);
    $$->children.push_back($5);
  }
  |
  PRINT LP ID LP RP DOT function_call RP {
    $$ = new Node("Print", "", yylineno);
    Node * class_func_call = new Node("Id", "", yylineno);
    class_func_call->children.push_back(new Node("Dot", "", yylineno));
    class_func_call->children.push_back($7);

    $$->children.push_back(class_func_call);
    
  }
  ;

return:
  RETURN math_expression {
    $$ = new Node("Return", "", yylineno);
    $$->children.push_back($2);
  }
  ;

block:
  LCB statements RCB {
    $$ = new Node("Block", "", yylineno);
    $$->children.push_back($2);
  }
  |
  BREAK {
    $$ = new Node("Break", "", yylineno); 
  }
  |
  CONTINUE {
    $$ = new Node("Continue", "", yylineno);
  }
  ;

main:
  MAIN LP RP COLON type block {
    $$ = new Node("main_function", "", yylineno);
    $$->children.push_back($5);
    $$->children.push_back($6);
  }
  ;

for_statement:
  FOR LP COMMA condition COMMA ID ASSIGN math_expression RP block {
    $$ = new Node("for_loop", "", yylineno);

    // init (tom)
    Node * init = new Node("Init", "", yylineno);
    init->children.push_back(new Node("(Empty)", "", yylineno));

    // condition
    Node * cond = $4;

    // update
    Node * update = new Node("Update", "", yylineno);
    Node * id = new Node("Identifier", "", yylineno);
    id->children.push_back(new Node("", $6, yylineno));
    update->children.push_back(id);
    update->children.push_back($8);

    // body
    Node * body = $10;

    $$->children.push_back(init);
    $$->children.push_back(cond);
    $$->children.push_back(update);
    $$->children.push_back(body);
  }
  |
  FOR LP COMMA math_expression COMMA ID ASSIGN math_expression RP block {
    $$ = new Node("for_loop", "", yylineno);

    // init (tom)
    Node * init = new Node("Init", "", yylineno);
    init->children.push_back(new Node("(Empty)", "", yylineno));

    // condition
    Node * cond = $4;

    // update
    Node * update = new Node("Update", "", yylineno);
    Node * id = new Node("Identifier", "", yylineno);
    id->children.push_back(new Node("", $6, yylineno));
    update->children.push_back(id);
    update->children.push_back($8);

    // body
    Node * body = $10;

    $$->children.push_back(init);
    $$->children.push_back(cond);
    $$->children.push_back(update);
    $$->children.push_back(body);
  }
  |
  FOR LP ID ASSIGN math_expression COMMA condition relational_operators math_expression COMMA ID ASSIGN math_expression RP block {
    $$ = new Node("for_loop", "", yylineno);

    Node * variable = new Node("VarDecl", "", yylineno);
    Node * identifier = new Node("Identifier", "", yylineno);
    identifier->children.push_back(new Node("", $3, yylineno));
    variable->children.push_back(identifier);
    variable->children.push_back($5);


    Node * logicalCondition = new Node("Logical_condition", "", yylineno);
    Node * condition = $8;

    condition->children.push_back($7);
    condition->children.push_back($9);
    logicalCondition->children.push_back(condition);


    Node * variableTwo = new Node("Expression", "", yylineno);
    variableTwo->children.push_back($13);



    $$->children.push_back(variable);
    $$->children.push_back(logicalCondition);
    $$->children.push_back(variableTwo);
    $$->children.push_back($15);
  }
  ;

relational_operators:
  EQTO {
    $$ = new Node("", $1, yylineno);
  }
  |
  NEQ {
    $$ = new Node("", $1, yylineno);
  }
  |
  LE {
    $$ = new Node("", $1, yylineno);
  }
  |
  GE {
    $$ = new Node("", $1, yylineno);
  }
  |
  LT {
    $$ = new Node("", $1, yylineno);
  }
  |
  GT {
    $$ = new Node("", $1, yylineno);
  }
  ;

  if_statement:
    IF LP condition RP block {
      $$ = new Node("If_statement", "", yylineno);
      $$->children.push_back($3);
      $$->children.push_back($5);
    }
    |
    IF LP condition relational_operators condition RP block {
      $$ = new Node("If_statement", "", yylineno);

      Node * logicalCondition = new Node("Logical_condition", "", yylineno);
      Node * condition = $4;

      condition->children.push_back($3);
      condition->children.push_back($5);
      logicalCondition->children.push_back(condition);

      $$->children.push_back(logicalCondition);
      $$->children.push_back($7);
      
    }
  ;


  else_statement:
    ELSE block {
      $$ = new Node("Else_statement", "", yylineno);
      $$->children.push_back($2);
    }
    |
    ELSE variable {
      $$ = new Node("Else", "", yylineno);
      $$->children.push_back($2);
    }
    ;

number_array:
  primary {
    Node * arrayLiteral = new Node("Array_literal", "", yylineno);
    $$ = arrayLiteral;
    $$->children.push_back($1);
  }
  | 
  number_array COMMA primary {
    $$ = $1;
    $$->children.push_back($3);
  }
;

array_decl:
  VOLATILE ID COLON type ASSIGN type SLB number_array SRB {

    $$ = new Node("ArrayDecl", "", yylineno);

    Node * modifier = new Node("Modifier", "", yylineno);
    modifier->children.push_back(new Node("Volatile", "", yylineno));

    Node * identifier = new Node("Identifier", "", yylineno);
    identifier->children.push_back(new Node("", $2, yylineno));    

    $$->children.push_back(modifier);
    $$->children.push_back(identifier);
    $$->children.push_back($4);
    $$->children.push_back($8);
  }
  |
  ID ASSIGN type SLB number_array SRB {
    $$ = new Node("Assgin", "", yylineno);
    $$->children.push_back(new Node("Id", "", yylineno));
    Node * array = $3;
    array->children.push_back($5);
    $$->children.push_back(array);
  }
  |
  ID SLB math_expression SRB ASSIGN ID SLB math_expression SRB {
    $$ = new Node("Re_assign", "", yylineno);
    
    Node * arrayOne = new Node("Array", "", yylineno);
    Node * identifierOne = new Node("Identifier", "", yylineno);
    Node * idOne = new Node("", $1, yylineno);
    identifierOne->children.push_back(idOne);
    Node * indexOne = new Node("index", "", yylineno);
    indexOne->children.push_back($3);

    arrayOne->children.push_back(identifierOne);
    arrayOne->children.push_back(indexOne);


    Node * arrayTwo = new Node("Array", "", yylineno);

    Node * identifierTwo = new Node("Identifier", "", yylineno);
    Node * idTwo = new Node("", $6, yylineno);
    identifierTwo->children.push_back(idTwo);
    Node * indexTwo = new Node("index", "", yylineno);
    indexTwo->children.push_back($8);

    arrayTwo->children.push_back(identifierTwo);
    arrayTwo->children.push_back(indexTwo);

    $$->children.push_back(arrayOne);
    $$->children.push_back(arrayTwo);
  }
  |
  ID SLB math_expression SRB ASSIGN ID {
    $$ = new Node("Re_assign", "", yylineno);
    
    Node * arrayOne = new Node("Array", "", yylineno);
    Node * identifierOne = new Node("Identifier", "", yylineno);
    Node * idOne = new Node("", $1, yylineno);
    identifierOne->children.push_back(idOne);
    Node * indexOne = new Node("index", "", yylineno);
    indexOne->children.push_back($3);

    arrayOne->children.push_back(identifierOne);
    arrayOne->children.push_back(indexOne);


    Node * identifierTwo = new Node("Identifier", "", yylineno);
    Node * idTwo = new Node("", $6, yylineno);

    identifierTwo->children.push_back(idTwo);

    $$->children.push_back(arrayOne);
    $$->children.push_back(identifierTwo);
  }

array_call:
  ID SLB math_expression SRB {
    $$ = new Node("Array", "", yylineno);
    
    Node * identifier = new Node("Identifier", "", yylineno);
    identifier->children.push_back(new Node("", $1, yylineno));

    Node * index = new Node("Index", "", yylineno);
    index->children.push_back($3);

    $$->children.push_back(identifier);
    $$->children.push_back(index);
  }
  |
  ID DOT LENGTH {
    $$ = new Node("Array", "", yylineno);
    Node * member_access = new Node("Member_access", "", yylineno);

    Node * identifier = new Node("Identifier", "", yylineno);
    identifier->children.push_back(new Node("", $1, yylineno));

    member_access->children.push_back(identifier);
    member_access->children.push_back(new Node("Length", "", yylineno));

    $$->children.push_back(member_access);
  }
  ;

comment:
  COMMENT {
    $$ = new Node("Comment", "", yylineno);
  }
  ;

class:
  CLASS ID block {
    $$ = new Node("Class", "", yylineno);
    Node * identifier = new Node("Identifier", "", yylineno);
    identifier->children.push_back(new Node("", $2, yylineno));
    $$->children.push_back(identifier);
    $$->children.push_back($3);
  }
  |
  ID COLON ID ASSIGN ID LP RP {
    $$ = new Node("VarDec", "", yylineno);

    Node * identifier = new Node("Identifier", "", yylineno);
    identifier->children.push_back(new Node("", $1, yylineno));

    Node * type = new Node("Type", "", yylineno);
    type->children.push_back(new Node("", $3, yylineno));

    Node * classs = new Node("Class", "", yylineno);
    classs->children.push_back(new Node("", $5, yylineno));

    $$->children.push_back(identifier);
    $$->children.push_back(type);
    $$->children.push_back(classs);
  
  }
  ;

function_decl:
  ID LP parameters RP COLON type block {
    $$ = new Node("function_Decl", "", yylineno);
    Node * identifier = new Node("Identifier", "", yylineno);
    identifier->children.push_back(new Node("", $1, yylineno));

    Node * returnType = new Node("Return_type", "", yylineno);
    returnType->children.push_back($6);


    $$->children.push_back(identifier);
    $$->children.push_back($3);
    $$->children.push_back(returnType);
    $$->children.push_back($7);
  }
  |
  ID LP RP COLON type block {
    $$ = new Node("function_Decl", "", yylineno);
    $$->children.push_back($5);
    $$->children.push_back($6); 
  }
  ;

function_call:
  ID LP arguments RP {
    $$ = new Node("function_call", "", yylineno);
    Node * identifier = new Node("Identifier", "", yylineno);
    identifier->children.push_back(new Node("", $1, yylineno));
    $$->children.push_back(identifier);
    $$->children.push_back($3);
  }
  |
  ID LP RP {
    $$ = new Node("function_call", "", yylineno);
    Node * identifier = new Node("Identifier", "", yylineno);
    identifier->children.push_back(new Node("", $1, yylineno));
    $$->children.push_back(identifier);
  }
;

parameters: 
  ID COLON type {
    $$ = new Node("parameters", "", yylineno);

    Node * parameter = new Node("Parameter", "", yylineno);
    Node * identifier = new Node("Identifier", "", yylineno);
    identifier->children.push_back(new Node("", $1, yylineno));

    parameter->children.push_back(identifier);
    parameter->children.push_back($3);
    $$->children.push_back(parameter);
  }
  |
  parameters COMMA ID COLON type {

    $$ = $1;

    Node * parameter = new Node("Parameter", "", yylineno);
    Node * identifier = new Node("Identifier", "", yylineno);
    identifier->children.push_back(new Node("", $3, yylineno));

    parameter->children.push_back(identifier);
    parameter->children.push_back($5);
    $$->children.push_back(parameter);
  }
  ;

  arguments:
    math_expression {
      $$ = new Node("Arguments", "", yylineno);

      Node * argument = new Node("argument", "", yylineno);
      argument->children.push_back($1);   
      $$->children.push_back(argument);
    }
    |
    arguments COMMA math_expression {
      $$ = $1;

      Node * argument = new Node("argument", "", yylineno);
      argument->children.push_back($3);   
      $$->children.push_back(argument);
    }
    ;
    

/* ./compiler < test_files/valid/test1.cpm */

