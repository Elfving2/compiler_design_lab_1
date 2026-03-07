// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "parser.tab.hh"


// Unqualified %code blocks.
#line 25 "parser.yy"

  #define YY_DECL yy::parser::symbol_type yylex()
  YY_DECL;
  
  Node* root;
  extern int yylineno;

#line 54 "parser.tab.cc"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif



// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 127 "parser.tab.cc"

  /// Build a parser object.
  parser::parser ()
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr)
#else

#endif
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_kind_type
  parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_root: // root
      case symbol_kind::S_block: // block
      case symbol_kind::S_statements: // statements
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_main_def: // main_def
      case symbol_kind::S_class_def: // class_def
      case symbol_kind::S_class_call: // class_call
      case symbol_kind::S_assignment: // assignment
      case symbol_kind::S_parameters: // parameters
      case symbol_kind::S_func_def: // func_def
      case symbol_kind::S_arguments: // arguments
      case symbol_kind::S_func_call: // func_call
      case symbol_kind::S_if_body: // if_body
      case symbol_kind::S_if_stmt: // if_stmt
      case symbol_kind::S_for_stmt: // for_stmt
      case symbol_kind::S_print_stmt: // print_stmt
      case symbol_kind::S_read_stmt: // read_stmt
      case symbol_kind::S_return_stmt: // return_stmt
      case symbol_kind::S_break_stmt: // break_stmt
      case symbol_kind::S_continue_stmt: // continue_stmt
      case symbol_kind::S_expr_stmt: // expr_stmt
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_logical_or: // logical_or
      case symbol_kind::S_logical_and: // logical_and
      case symbol_kind::S_equality: // equality
      case symbol_kind::S_relational: // relational
      case symbol_kind::S_additive: // additive
      case symbol_kind::S_power: // power
      case symbol_kind::S_multiplicative: // multiplicative
      case symbol_kind::S_unary: // unary
      case symbol_kind::S_primary: // primary
      case symbol_kind::S_type: // type
      case symbol_kind::S_comment: // comment
      case symbol_kind::S_values: // values
      case symbol_kind::S_array_call: // array_call
        value.YY_MOVE_OR_COPY< Node * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_PLUSOP: // PLUSOP
      case symbol_kind::S_MINUSOP: // MINUSOP
      case symbol_kind::S_MULTOP: // MULTOP
      case symbol_kind::S_DIVOP: // DIVOP
      case symbol_kind::S_POWER: // POWER
      case symbol_kind::S_OR: // OR
      case symbol_kind::S_AND: // AND
      case symbol_kind::S_EXCLAMATION_MARK: // EXCLAMATION_MARK
      case symbol_kind::S_EQTO: // EQTO
      case symbol_kind::S_NEQ: // NEQ
      case symbol_kind::S_LE: // LE
      case symbol_kind::S_GE: // GE
      case symbol_kind::S_LT: // LT
      case symbol_kind::S_GT: // GT
      case symbol_kind::S_LP: // LP
      case symbol_kind::S_RP: // RP
      case symbol_kind::S_SLB: // SLB
      case symbol_kind::S_SRB: // SRB
      case symbol_kind::S_LCB: // LCB
      case symbol_kind::S_RCB: // RCB
      case symbol_kind::S_DOT: // DOT
      case symbol_kind::S_COMMA: // COMMA
      case symbol_kind::S_COLON: // COLON
      case symbol_kind::S_ASSIGN: // ASSIGN
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_PRINT: // PRINT
      case symbol_kind::S_READ: // READ
      case symbol_kind::S_BREAK: // BREAK
      case symbol_kind::S_CONTINUE: // CONTINUE
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_FOR: // FOR
      case symbol_kind::S_MAIN: // MAIN
      case symbol_kind::S_CLASS: // CLASS
      case symbol_kind::S_LENGTH: // LENGTH
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_FLOAT: // FLOAT
      case symbol_kind::S_TRUE: // TRUE
      case symbol_kind::S_FALSE: // FALSE
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_COMMENT: // COMMENT
      case symbol_kind::S_INT_TYPE: // INT_TYPE
      case symbol_kind::S_FLOAT_TYPE: // FLOAT_TYPE
      case symbol_kind::S_BOOLEAN_TYPE: // BOOLEAN_TYPE
      case symbol_kind::S_VOID_TYPE: // VOID_TYPE
      case symbol_kind::S_VOLATILE: // VOLATILE
      case symbol_kind::S_INT_ARRAY_TYPE: // INT_ARRAY_TYPE
      case symbol_kind::S_FLOAT_ARRAY_TYPE: // FLOAT_ARRAY_TYPE
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s)
  {
    switch (that.kind ())
    {
      case symbol_kind::S_root: // root
      case symbol_kind::S_block: // block
      case symbol_kind::S_statements: // statements
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_main_def: // main_def
      case symbol_kind::S_class_def: // class_def
      case symbol_kind::S_class_call: // class_call
      case symbol_kind::S_assignment: // assignment
      case symbol_kind::S_parameters: // parameters
      case symbol_kind::S_func_def: // func_def
      case symbol_kind::S_arguments: // arguments
      case symbol_kind::S_func_call: // func_call
      case symbol_kind::S_if_body: // if_body
      case symbol_kind::S_if_stmt: // if_stmt
      case symbol_kind::S_for_stmt: // for_stmt
      case symbol_kind::S_print_stmt: // print_stmt
      case symbol_kind::S_read_stmt: // read_stmt
      case symbol_kind::S_return_stmt: // return_stmt
      case symbol_kind::S_break_stmt: // break_stmt
      case symbol_kind::S_continue_stmt: // continue_stmt
      case symbol_kind::S_expr_stmt: // expr_stmt
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_logical_or: // logical_or
      case symbol_kind::S_logical_and: // logical_and
      case symbol_kind::S_equality: // equality
      case symbol_kind::S_relational: // relational
      case symbol_kind::S_additive: // additive
      case symbol_kind::S_power: // power
      case symbol_kind::S_multiplicative: // multiplicative
      case symbol_kind::S_unary: // unary
      case symbol_kind::S_primary: // primary
      case symbol_kind::S_type: // type
      case symbol_kind::S_comment: // comment
      case symbol_kind::S_values: // values
      case symbol_kind::S_array_call: // array_call
        value.move< Node * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_PLUSOP: // PLUSOP
      case symbol_kind::S_MINUSOP: // MINUSOP
      case symbol_kind::S_MULTOP: // MULTOP
      case symbol_kind::S_DIVOP: // DIVOP
      case symbol_kind::S_POWER: // POWER
      case symbol_kind::S_OR: // OR
      case symbol_kind::S_AND: // AND
      case symbol_kind::S_EXCLAMATION_MARK: // EXCLAMATION_MARK
      case symbol_kind::S_EQTO: // EQTO
      case symbol_kind::S_NEQ: // NEQ
      case symbol_kind::S_LE: // LE
      case symbol_kind::S_GE: // GE
      case symbol_kind::S_LT: // LT
      case symbol_kind::S_GT: // GT
      case symbol_kind::S_LP: // LP
      case symbol_kind::S_RP: // RP
      case symbol_kind::S_SLB: // SLB
      case symbol_kind::S_SRB: // SRB
      case symbol_kind::S_LCB: // LCB
      case symbol_kind::S_RCB: // RCB
      case symbol_kind::S_DOT: // DOT
      case symbol_kind::S_COMMA: // COMMA
      case symbol_kind::S_COLON: // COLON
      case symbol_kind::S_ASSIGN: // ASSIGN
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_PRINT: // PRINT
      case symbol_kind::S_READ: // READ
      case symbol_kind::S_BREAK: // BREAK
      case symbol_kind::S_CONTINUE: // CONTINUE
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_FOR: // FOR
      case symbol_kind::S_MAIN: // MAIN
      case symbol_kind::S_CLASS: // CLASS
      case symbol_kind::S_LENGTH: // LENGTH
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_FLOAT: // FLOAT
      case symbol_kind::S_TRUE: // TRUE
      case symbol_kind::S_FALSE: // FALSE
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_COMMENT: // COMMENT
      case symbol_kind::S_INT_TYPE: // INT_TYPE
      case symbol_kind::S_FLOAT_TYPE: // FLOAT_TYPE
      case symbol_kind::S_BOOLEAN_TYPE: // BOOLEAN_TYPE
      case symbol_kind::S_VOID_TYPE: // VOID_TYPE
      case symbol_kind::S_VOLATILE: // VOLATILE
      case symbol_kind::S_INT_ARRAY_TYPE: // INT_ARRAY_TYPE
      case symbol_kind::S_FLOAT_ARRAY_TYPE: // FLOAT_ARRAY_TYPE
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_root: // root
      case symbol_kind::S_block: // block
      case symbol_kind::S_statements: // statements
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_main_def: // main_def
      case symbol_kind::S_class_def: // class_def
      case symbol_kind::S_class_call: // class_call
      case symbol_kind::S_assignment: // assignment
      case symbol_kind::S_parameters: // parameters
      case symbol_kind::S_func_def: // func_def
      case symbol_kind::S_arguments: // arguments
      case symbol_kind::S_func_call: // func_call
      case symbol_kind::S_if_body: // if_body
      case symbol_kind::S_if_stmt: // if_stmt
      case symbol_kind::S_for_stmt: // for_stmt
      case symbol_kind::S_print_stmt: // print_stmt
      case symbol_kind::S_read_stmt: // read_stmt
      case symbol_kind::S_return_stmt: // return_stmt
      case symbol_kind::S_break_stmt: // break_stmt
      case symbol_kind::S_continue_stmt: // continue_stmt
      case symbol_kind::S_expr_stmt: // expr_stmt
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_logical_or: // logical_or
      case symbol_kind::S_logical_and: // logical_and
      case symbol_kind::S_equality: // equality
      case symbol_kind::S_relational: // relational
      case symbol_kind::S_additive: // additive
      case symbol_kind::S_power: // power
      case symbol_kind::S_multiplicative: // multiplicative
      case symbol_kind::S_unary: // unary
      case symbol_kind::S_primary: // primary
      case symbol_kind::S_type: // type
      case symbol_kind::S_comment: // comment
      case symbol_kind::S_values: // values
      case symbol_kind::S_array_call: // array_call
        value.copy< Node * > (that.value);
        break;

      case symbol_kind::S_PLUSOP: // PLUSOP
      case symbol_kind::S_MINUSOP: // MINUSOP
      case symbol_kind::S_MULTOP: // MULTOP
      case symbol_kind::S_DIVOP: // DIVOP
      case symbol_kind::S_POWER: // POWER
      case symbol_kind::S_OR: // OR
      case symbol_kind::S_AND: // AND
      case symbol_kind::S_EXCLAMATION_MARK: // EXCLAMATION_MARK
      case symbol_kind::S_EQTO: // EQTO
      case symbol_kind::S_NEQ: // NEQ
      case symbol_kind::S_LE: // LE
      case symbol_kind::S_GE: // GE
      case symbol_kind::S_LT: // LT
      case symbol_kind::S_GT: // GT
      case symbol_kind::S_LP: // LP
      case symbol_kind::S_RP: // RP
      case symbol_kind::S_SLB: // SLB
      case symbol_kind::S_SRB: // SRB
      case symbol_kind::S_LCB: // LCB
      case symbol_kind::S_RCB: // RCB
      case symbol_kind::S_DOT: // DOT
      case symbol_kind::S_COMMA: // COMMA
      case symbol_kind::S_COLON: // COLON
      case symbol_kind::S_ASSIGN: // ASSIGN
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_PRINT: // PRINT
      case symbol_kind::S_READ: // READ
      case symbol_kind::S_BREAK: // BREAK
      case symbol_kind::S_CONTINUE: // CONTINUE
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_FOR: // FOR
      case symbol_kind::S_MAIN: // MAIN
      case symbol_kind::S_CLASS: // CLASS
      case symbol_kind::S_LENGTH: // LENGTH
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_FLOAT: // FLOAT
      case symbol_kind::S_TRUE: // TRUE
      case symbol_kind::S_FALSE: // FALSE
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_COMMENT: // COMMENT
      case symbol_kind::S_INT_TYPE: // INT_TYPE
      case symbol_kind::S_FLOAT_TYPE: // FLOAT_TYPE
      case symbol_kind::S_BOOLEAN_TYPE: // BOOLEAN_TYPE
      case symbol_kind::S_VOID_TYPE: // VOID_TYPE
      case symbol_kind::S_VOLATILE: // VOLATILE
      case symbol_kind::S_INT_ARRAY_TYPE: // INT_ARRAY_TYPE
      case symbol_kind::S_FLOAT_ARRAY_TYPE: // FLOAT_ARRAY_TYPE
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_root: // root
      case symbol_kind::S_block: // block
      case symbol_kind::S_statements: // statements
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_main_def: // main_def
      case symbol_kind::S_class_def: // class_def
      case symbol_kind::S_class_call: // class_call
      case symbol_kind::S_assignment: // assignment
      case symbol_kind::S_parameters: // parameters
      case symbol_kind::S_func_def: // func_def
      case symbol_kind::S_arguments: // arguments
      case symbol_kind::S_func_call: // func_call
      case symbol_kind::S_if_body: // if_body
      case symbol_kind::S_if_stmt: // if_stmt
      case symbol_kind::S_for_stmt: // for_stmt
      case symbol_kind::S_print_stmt: // print_stmt
      case symbol_kind::S_read_stmt: // read_stmt
      case symbol_kind::S_return_stmt: // return_stmt
      case symbol_kind::S_break_stmt: // break_stmt
      case symbol_kind::S_continue_stmt: // continue_stmt
      case symbol_kind::S_expr_stmt: // expr_stmt
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_logical_or: // logical_or
      case symbol_kind::S_logical_and: // logical_and
      case symbol_kind::S_equality: // equality
      case symbol_kind::S_relational: // relational
      case symbol_kind::S_additive: // additive
      case symbol_kind::S_power: // power
      case symbol_kind::S_multiplicative: // multiplicative
      case symbol_kind::S_unary: // unary
      case symbol_kind::S_primary: // primary
      case symbol_kind::S_type: // type
      case symbol_kind::S_comment: // comment
      case symbol_kind::S_values: // values
      case symbol_kind::S_array_call: // array_call
        value.move< Node * > (that.value);
        break;

      case symbol_kind::S_PLUSOP: // PLUSOP
      case symbol_kind::S_MINUSOP: // MINUSOP
      case symbol_kind::S_MULTOP: // MULTOP
      case symbol_kind::S_DIVOP: // DIVOP
      case symbol_kind::S_POWER: // POWER
      case symbol_kind::S_OR: // OR
      case symbol_kind::S_AND: // AND
      case symbol_kind::S_EXCLAMATION_MARK: // EXCLAMATION_MARK
      case symbol_kind::S_EQTO: // EQTO
      case symbol_kind::S_NEQ: // NEQ
      case symbol_kind::S_LE: // LE
      case symbol_kind::S_GE: // GE
      case symbol_kind::S_LT: // LT
      case symbol_kind::S_GT: // GT
      case symbol_kind::S_LP: // LP
      case symbol_kind::S_RP: // RP
      case symbol_kind::S_SLB: // SLB
      case symbol_kind::S_SRB: // SRB
      case symbol_kind::S_LCB: // LCB
      case symbol_kind::S_RCB: // RCB
      case symbol_kind::S_DOT: // DOT
      case symbol_kind::S_COMMA: // COMMA
      case symbol_kind::S_COLON: // COLON
      case symbol_kind::S_ASSIGN: // ASSIGN
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_PRINT: // PRINT
      case symbol_kind::S_READ: // READ
      case symbol_kind::S_BREAK: // BREAK
      case symbol_kind::S_CONTINUE: // CONTINUE
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_FOR: // FOR
      case symbol_kind::S_MAIN: // MAIN
      case symbol_kind::S_CLASS: // CLASS
      case symbol_kind::S_LENGTH: // LENGTH
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_FLOAT: // FLOAT
      case symbol_kind::S_TRUE: // TRUE
      case symbol_kind::S_FALSE: // FALSE
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_COMMENT: // COMMENT
      case symbol_kind::S_INT_TYPE: // INT_TYPE
      case symbol_kind::S_FLOAT_TYPE: // FLOAT_TYPE
      case symbol_kind::S_BOOLEAN_TYPE: // BOOLEAN_TYPE
      case symbol_kind::S_VOID_TYPE: // VOID_TYPE
      case symbol_kind::S_VOLATILE: // VOLATILE
      case symbol_kind::S_INT_ARRAY_TYPE: // INT_ARRAY_TYPE
      case symbol_kind::S_FLOAT_ARRAY_TYPE: // FLOAT_ARRAY_TYPE
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " (";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex ());
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_root: // root
      case symbol_kind::S_block: // block
      case symbol_kind::S_statements: // statements
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_main_def: // main_def
      case symbol_kind::S_class_def: // class_def
      case symbol_kind::S_class_call: // class_call
      case symbol_kind::S_assignment: // assignment
      case symbol_kind::S_parameters: // parameters
      case symbol_kind::S_func_def: // func_def
      case symbol_kind::S_arguments: // arguments
      case symbol_kind::S_func_call: // func_call
      case symbol_kind::S_if_body: // if_body
      case symbol_kind::S_if_stmt: // if_stmt
      case symbol_kind::S_for_stmt: // for_stmt
      case symbol_kind::S_print_stmt: // print_stmt
      case symbol_kind::S_read_stmt: // read_stmt
      case symbol_kind::S_return_stmt: // return_stmt
      case symbol_kind::S_break_stmt: // break_stmt
      case symbol_kind::S_continue_stmt: // continue_stmt
      case symbol_kind::S_expr_stmt: // expr_stmt
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_logical_or: // logical_or
      case symbol_kind::S_logical_and: // logical_and
      case symbol_kind::S_equality: // equality
      case symbol_kind::S_relational: // relational
      case symbol_kind::S_additive: // additive
      case symbol_kind::S_power: // power
      case symbol_kind::S_multiplicative: // multiplicative
      case symbol_kind::S_unary: // unary
      case symbol_kind::S_primary: // primary
      case symbol_kind::S_type: // type
      case symbol_kind::S_comment: // comment
      case symbol_kind::S_values: // values
      case symbol_kind::S_array_call: // array_call
        yylhs.value.emplace< Node * > ();
        break;

      case symbol_kind::S_PLUSOP: // PLUSOP
      case symbol_kind::S_MINUSOP: // MINUSOP
      case symbol_kind::S_MULTOP: // MULTOP
      case symbol_kind::S_DIVOP: // DIVOP
      case symbol_kind::S_POWER: // POWER
      case symbol_kind::S_OR: // OR
      case symbol_kind::S_AND: // AND
      case symbol_kind::S_EXCLAMATION_MARK: // EXCLAMATION_MARK
      case symbol_kind::S_EQTO: // EQTO
      case symbol_kind::S_NEQ: // NEQ
      case symbol_kind::S_LE: // LE
      case symbol_kind::S_GE: // GE
      case symbol_kind::S_LT: // LT
      case symbol_kind::S_GT: // GT
      case symbol_kind::S_LP: // LP
      case symbol_kind::S_RP: // RP
      case symbol_kind::S_SLB: // SLB
      case symbol_kind::S_SRB: // SRB
      case symbol_kind::S_LCB: // LCB
      case symbol_kind::S_RCB: // RCB
      case symbol_kind::S_DOT: // DOT
      case symbol_kind::S_COMMA: // COMMA
      case symbol_kind::S_COLON: // COLON
      case symbol_kind::S_ASSIGN: // ASSIGN
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_PRINT: // PRINT
      case symbol_kind::S_READ: // READ
      case symbol_kind::S_BREAK: // BREAK
      case symbol_kind::S_CONTINUE: // CONTINUE
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_FOR: // FOR
      case symbol_kind::S_MAIN: // MAIN
      case symbol_kind::S_CLASS: // CLASS
      case symbol_kind::S_LENGTH: // LENGTH
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_FLOAT: // FLOAT
      case symbol_kind::S_TRUE: // TRUE
      case symbol_kind::S_FALSE: // FALSE
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_COMMENT: // COMMENT
      case symbol_kind::S_INT_TYPE: // INT_TYPE
      case symbol_kind::S_FLOAT_TYPE: // FLOAT_TYPE
      case symbol_kind::S_BOOLEAN_TYPE: // BOOLEAN_TYPE
      case symbol_kind::S_VOID_TYPE: // VOID_TYPE
      case symbol_kind::S_VOLATILE: // VOLATILE
      case symbol_kind::S_INT_ARRAY_TYPE: // INT_ARRAY_TYPE
      case symbol_kind::S_FLOAT_ARRAY_TYPE: // FLOAT_ARRAY_TYPE
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }



      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // root: statements "end of file"
#line 72 "parser.yy"
  {
    root = yystack_[1].value.as < Node * > ();
  }
#line 955 "parser.tab.cc"
    break;

  case 3: // root: block "end of file"
#line 75 "parser.yy"
              {
    root = yystack_[1].value.as < Node * > ();
  }
#line 963 "parser.tab.cc"
    break;

  case 4: // block: LCB statements RCB
#line 81 "parser.yy"
                     {
    yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
  }
#line 971 "parser.tab.cc"
    break;

  case 5: // statements: statement
#line 87 "parser.yy"
            {
    yylhs.value.as < Node * > () = new Node("Block", "Block", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 980 "parser.tab.cc"
    break;

  case 6: // statements: statements statement
#line 91 "parser.yy"
                       {
  yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
  yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
}
#line 989 "parser.tab.cc"
    break;

  case 7: // statement: main_def
#line 98 "parser.yy"
  { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); }
#line 995 "parser.tab.cc"
    break;

  case 8: // statement: class_def
#line 99 "parser.yy"
    { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); }
#line 1001 "parser.tab.cc"
    break;

  case 9: // statement: func_def
#line 100 "parser.yy"
    { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); }
#line 1007 "parser.tab.cc"
    break;

  case 10: // statement: assignment
#line 101 "parser.yy"
    { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); }
#line 1013 "parser.tab.cc"
    break;

  case 11: // statement: if_stmt
#line 102 "parser.yy"
    { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); }
#line 1019 "parser.tab.cc"
    break;

  case 12: // statement: for_stmt
#line 103 "parser.yy"
    { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); }
#line 1025 "parser.tab.cc"
    break;

  case 13: // statement: print_stmt
#line 104 "parser.yy"
    { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); }
#line 1031 "parser.tab.cc"
    break;

  case 14: // statement: read_stmt
#line 105 "parser.yy"
    { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); }
#line 1037 "parser.tab.cc"
    break;

  case 15: // statement: return_stmt
#line 106 "parser.yy"
    { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); }
#line 1043 "parser.tab.cc"
    break;

  case 16: // statement: break_stmt
#line 107 "parser.yy"
    { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); }
#line 1049 "parser.tab.cc"
    break;

  case 17: // statement: continue_stmt
#line 108 "parser.yy"
    { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); }
#line 1055 "parser.tab.cc"
    break;

  case 18: // statement: expr_stmt
#line 109 "parser.yy"
    { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); }
#line 1061 "parser.tab.cc"
    break;

  case 19: // statement: type
#line 110 "parser.yy"
    { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); }
#line 1067 "parser.tab.cc"
    break;

  case 20: // statement: comment
#line 111 "parser.yy"
    { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); }
#line 1073 "parser.tab.cc"
    break;

  case 21: // main_def: MAIN LP RP COLON INT_TYPE block
#line 116 "parser.yy"
                                  {
    yylhs.value.as < Node * > () = new Node("Main", yystack_[1].value.as < std::string > (), yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1082 "parser.tab.cc"
    break;

  case 22: // class_def: CLASS ID block
#line 123 "parser.yy"
                 {
    yylhs.value.as < Node * > () = new Node("Class", yystack_[1].value.as < std::string > (), yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1091 "parser.tab.cc"
    break;

  case 23: // class_call: ID LP RP
#line 130 "parser.yy"
           {
    yylhs.value.as < Node * > () = new Node("Class", yystack_[2].value.as < std::string > (), yylineno);
  }
#line 1099 "parser.tab.cc"
    break;

  case 24: // assignment: VOLATILE ID COLON type ASSIGN expression
#line 136 "parser.yy"
                                           {
    yylhs.value.as < Node * > () = new Node("varDecl", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(new Node("Modifier", yystack_[5].value.as < std::string > (), yylineno));
    yylhs.value.as < Node * > ()->children.push_back(new Node("Identifier", yystack_[4].value.as < std::string > (), yylineno));
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1111 "parser.tab.cc"
    break;

  case 25: // assignment: ID COLON type ASSIGN expression
#line 144 "parser.yy"
                                  {
    yylhs.value.as < Node * > () = new Node("varDecl", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(new Node("Identifier", yystack_[4].value.as < std::string > (), yylineno));
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1122 "parser.tab.cc"
    break;

  case 26: // assignment: VOLATILE ID COLON type
#line 151 "parser.yy"
                         {
    yylhs.value.as < Node * > () = new Node("varDecl", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(new Node("Modifier", yystack_[3].value.as < std::string > (), yylineno));
    yylhs.value.as < Node * > ()->children.push_back(new Node("Identifier", yystack_[2].value.as < std::string > (), yylineno));
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1133 "parser.tab.cc"
    break;

  case 27: // assignment: VOLATILE ID COLON type ASSIGN type SLB values SRB
#line 158 "parser.yy"
                                                    {
    yylhs.value.as < Node * > () = new Node("varDecl", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(new Node("Modifier", yystack_[8].value.as < std::string > (), yylineno));
    yylhs.value.as < Node * > ()->children.push_back(new Node("Identifier", yystack_[7].value.as < std::string > (), yylineno));
    yylhs.value.as < Node * > ()->children.push_back(yystack_[5].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
  }
#line 1145 "parser.tab.cc"
    break;

  case 28: // assignment: array_call ASSIGN array_call
#line 166 "parser.yy"
                               {
    yystack_[2].value.as < Node * > ()->value = "1";
    yystack_[0].value.as < Node * > ()->value = "2";
    yylhs.value.as < Node * > () = new Node("Assign", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1157 "parser.tab.cc"
    break;

  case 29: // assignment: ID COLON ID ASSIGN class_call
#line 174 "parser.yy"
                                {
    yylhs.value.as < Node * > () = new Node("Assign", "", yylineno);

    yylhs.value.as < Node * > ()->children.push_back(new Node("Identifier", yystack_[4].value.as < std::string > (), yylineno));
    yylhs.value.as < Node * > ()->children.push_back(new Node("Type", yystack_[2].value.as < std::string > (), yylineno));
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1169 "parser.tab.cc"
    break;

  case 30: // assignment: VOLATILE ID COLON ID ASSIGN class_call
#line 182 "parser.yy"
                                         {
    yylhs.value.as < Node * > () = new Node("varDecl", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(new Node("Modifier", yystack_[5].value.as < std::string > (), yylineno));
    yylhs.value.as < Node * > ()->children.push_back(new Node("Identifier", yystack_[4].value.as < std::string > (), yylineno));
    yylhs.value.as < Node * > ()->children.push_back(new Node("Class", yystack_[2].value.as < std::string > (), yylineno));
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1181 "parser.tab.cc"
    break;

  case 31: // assignment: VOLATILE ID COLON type ASSIGN class_call DOT func_call
#line 190 "parser.yy"
                                                         {
    yylhs.value.as < Node * > () = new Node("varDecl", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(new Node("Modifier", yystack_[7].value.as < std::string > (), yylineno));
    yylhs.value.as < Node * > ()->children.push_back(new Node("Identifier", yystack_[6].value.as < std::string > (), yylineno));
    yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
    Node * c = yystack_[2].value.as < Node * > ();
    c->children.push_back(yystack_[0].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(c);
  }
#line 1195 "parser.tab.cc"
    break;

  case 32: // assignment: VOLATILE ID COLON type ASSIGN ID DOT func_call
#line 200 "parser.yy"
                                                 {
    yylhs.value.as < Node * > () = new Node("varDecl", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(new Node("Modifier", yystack_[7].value.as < std::string > (), yylineno));
    yylhs.value.as < Node * > ()->children.push_back(new Node("Identifier", yystack_[6].value.as < std::string > (), yylineno));
    yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
    Node * c = new Node("Class", yystack_[2].value.as < std::string > (), yylineno);
    c->children.push_back(yystack_[0].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(c);
  }
#line 1209 "parser.tab.cc"
    break;

  case 33: // assignment: ID ASSIGN expression
#line 210 "parser.yy"
                       {
    yylhs.value.as < Node * > () = new Node("Assign", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(new Node("Identifier", yystack_[2].value.as < std::string > (), yylineno));
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1219 "parser.tab.cc"
    break;

  case 34: // assignment: array_call ASSIGN ID
#line 216 "parser.yy"
                       {
    yystack_[2].value.as < Node * > ()->value = "1";
    yylhs.value.as < Node * > () = new Node("Assign", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(new Node("Value", yystack_[0].value.as < std::string > (), yylineno));
  }
#line 1230 "parser.tab.cc"
    break;

  case 35: // assignment: ID ASSIGN type SLB values SRB
#line 223 "parser.yy"
                                {
    yylhs.value.as < Node * > () = new Node("Assaign", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(new Node("Identifier", yystack_[5].value.as < std::string > (), yylineno));
    Node * array = new Node("Array", "", yylineno);
    array->children.push_back(yystack_[3].value.as < Node * > ());
    array->children.push_back(yystack_[1].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(array);
  }
#line 1243 "parser.tab.cc"
    break;

  case 36: // assignment: ID DOT func_call
#line 232 "parser.yy"
                   {
    yylhs.value.as < Node * > () = new Node("Identifier", yystack_[2].value.as < std::string > (), yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1252 "parser.tab.cc"
    break;

  case 37: // parameters: ID COLON type
#line 239 "parser.yy"
                {
    yylhs.value.as < Node * > () = new Node("Parameters", "", yylineno);
    Node * parameter = new Node("Parameter", "", yylineno);
    parameter->children.push_back(new Node("Identifier", yystack_[2].value.as < std::string > (), yylineno));
    parameter->children.push_back(yystack_[0].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(parameter);
  }
#line 1264 "parser.tab.cc"
    break;

  case 38: // parameters: parameters COMMA ID COLON type
#line 247 "parser.yy"
                                  {
    yylhs.value.as < Node * > () = yystack_[4].value.as < Node * > ();
    Node * parameter = new Node("Parameter", "", yylineno);
    parameter->children.push_back(new Node("Identifier", yystack_[2].value.as < std::string > (), yylineno));
    parameter->children.push_back(yystack_[0].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(parameter);
  }
#line 1276 "parser.tab.cc"
    break;

  case 39: // func_def: ID LP parameters RP COLON type block
#line 256 "parser.yy"
                                       {
    yylhs.value.as < Node * > () = new Node("function_def", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(new Node("Identifier", yystack_[6].value.as < std::string > (), yylineno));
    yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
    Node * return_type = new Node("Return_type", "", yylineno);
    return_type->children.push_back(yystack_[1].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(return_type);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1290 "parser.tab.cc"
    break;

  case 40: // func_def: ID LP RP COLON type block
#line 266 "parser.yy"
                            {
    yylhs.value.as < Node * > () = new Node("function_def", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(new Node("Identifier", yystack_[5].value.as < std::string > (), yylineno));
    Node * return_type = new Node("Return_type", "", yylineno);
    return_type->children.push_back(yystack_[1].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(return_type);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1303 "parser.tab.cc"
    break;

  case 41: // func_def: ID COLON type LP RP block
#line 275 "parser.yy"
                            {
    yylhs.value.as < Node * > () = new Node("function_def", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(new Node("Identifier", yystack_[5].value.as < std::string > (), yylineno));
    Node * return_type = new Node("Return_type", "", yylineno);
    return_type->children.push_back(yystack_[3].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(return_type);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1316 "parser.tab.cc"
    break;

  case 42: // arguments: %empty
#line 286 "parser.yy"
        { 
    yylhs.value.as < Node * > () = new Node("","", yylineno);
  }
#line 1324 "parser.tab.cc"
    break;

  case 43: // arguments: expression
#line 290 "parser.yy"
             {
    yylhs.value.as < Node * > () = new Node("Arguments", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1333 "parser.tab.cc"
    break;

  case 44: // arguments: arguments COMMA expression
#line 295 "parser.yy"
                             {
    yylhs.value.as < Node * > () = yystack_[2].value.as < Node * > ();
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1342 "parser.tab.cc"
    break;

  case 45: // func_call: ID LP arguments RP
#line 301 "parser.yy"
                     {
    yylhs.value.as < Node * > () = new Node("function_call", yystack_[3].value.as < std::string > (), yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
  }
#line 1351 "parser.tab.cc"
    break;

  case 46: // if_body: statement
#line 309 "parser.yy"
              {
    yylhs.value.as < Node * > () = new Node("Block", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());

  }
#line 1361 "parser.tab.cc"
    break;

  case 47: // if_body: block
#line 314 "parser.yy"
    { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); }
#line 1367 "parser.tab.cc"
    break;

  case 48: // if_stmt: IF LP expression RP if_body
#line 319 "parser.yy"
    {
      yylhs.value.as < Node * > () = new Node("If_statement", "", yylineno);
      yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
      yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 1377 "parser.tab.cc"
    break;

  case 49: // if_stmt: IF LP expression RP if_body ELSE if_body
#line 325 "parser.yy"
    {
      yylhs.value.as < Node * > () = new Node("If_statement", "", yylineno);
      yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
      yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
      Node * el = new Node("Else", "", yylineno);
      el->children.push_back(yystack_[0].value.as < Node * > ());
      yylhs.value.as < Node * > ()->children.push_back(el);
    }
#line 1390 "parser.tab.cc"
    break;

  case 50: // for_stmt: FOR LP ID ASSIGN expression COMMA relational COMMA ID ASSIGN expression RP block
#line 338 "parser.yy"
                                                                                   {
    yylhs.value.as < Node * > () = new Node("For_loop", "", yylineno);
    Node * assign = new Node("Assign", "1", yylineno);
    assign->children.push_back(new Node("Identifier", yystack_[10].value.as < std::string > (), yylineno));
    assign->children.push_back(yystack_[8].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(assign);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[6].value.as < Node * > ());
    
    Node * assign2 = new Node("Assign", "2", yylineno);
    assign2->children.push_back(new Node("Identifier", yystack_[4].value.as < std::string > (), yylineno));
    assign2->children.push_back(yystack_[2].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(assign2);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1409 "parser.tab.cc"
    break;

  case 51: // for_stmt: FOR LP COMMA primary COMMA primary ASSIGN primary RP block
#line 353 "parser.yy"
                                                             {
    yylhs.value.as < Node * > () = new Node("For_loop", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[6].value.as < Node * > ());
    Node * assign = new Node("Assign", "2", yylineno);
    assign->children.push_back(yystack_[4].value.as < Node * > ());
    assign->children.push_back(yystack_[2].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(assign);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1423 "parser.tab.cc"
    break;

  case 52: // print_stmt: PRINT LP ID DOT func_call RP
#line 365 "parser.yy"
                               {
    yylhs.value.as < Node * > () = new Node("Print", "", yylineno);
    Node * identifier = new Node("Identifier", yystack_[3].value.as < std::string > (), yylineno);
    identifier->children.push_back(yystack_[1].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(identifier);
  }
#line 1434 "parser.tab.cc"
    break;

  case 53: // print_stmt: PRINT LP expression RP
#line 372 "parser.yy"
                         {
    yylhs.value.as < Node * > () = new Node("Print", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
  }
#line 1443 "parser.tab.cc"
    break;

  case 54: // print_stmt: PRINT LP class_call DOT func_call RP
#line 377 "parser.yy"
                                       {
    yylhs.value.as < Node * > () = new Node("Print", "", yylineno);
    Node * c = yystack_[3].value.as < Node * > ();
    c->children.push_back(yystack_[1].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(c);
  }
#line 1454 "parser.tab.cc"
    break;

  case 55: // read_stmt: READ LP expression RP
#line 386 "parser.yy"
                        {
    yylhs.value.as < Node * > () = new Node("Read", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
  }
#line 1463 "parser.tab.cc"
    break;

  case 56: // return_stmt: RETURN expression
#line 393 "parser.yy"
                    {
    yylhs.value.as < Node * > () = new Node("Return", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1472 "parser.tab.cc"
    break;

  case 57: // break_stmt: BREAK
#line 400 "parser.yy"
        {
    yylhs.value.as < Node * > () = new Node("Break", yystack_[0].value.as < std::string > (), yylineno);
  }
#line 1480 "parser.tab.cc"
    break;

  case 58: // continue_stmt: CONTINUE
#line 406 "parser.yy"
             {}
#line 1486 "parser.tab.cc"
    break;

  case 59: // expr_stmt: expression
#line 410 "parser.yy"
             {
    yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();
  }
#line 1494 "parser.tab.cc"
    break;

  case 60: // expression: logical_or
#line 416 "parser.yy"
               {
    yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();
  }
#line 1502 "parser.tab.cc"
    break;

  case 61: // logical_or: logical_or OR logical_and
#line 422 "parser.yy"
                            {
    yylhs.value.as < Node * > () = new Node("", yystack_[1].value.as < std::string > (), yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1512 "parser.tab.cc"
    break;

  case 62: // logical_or: logical_and
#line 427 "parser.yy"
                {
    yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();
  }
#line 1520 "parser.tab.cc"
    break;

  case 63: // logical_and: logical_and AND equality
#line 433 "parser.yy"
                          {
    yylhs.value.as < Node * > () = new Node("", yystack_[1].value.as < std::string > (), yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    
  }
#line 1531 "parser.tab.cc"
    break;

  case 64: // logical_and: equality
#line 439 "parser.yy"
             {
    yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();
  }
#line 1539 "parser.tab.cc"
    break;

  case 65: // equality: equality EQTO relational
#line 445 "parser.yy"
                           {
    yylhs.value.as < Node * > () = new Node("Equal_to", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1549 "parser.tab.cc"
    break;

  case 66: // equality: equality NEQ relational
#line 450 "parser.yy"
    { yylhs.value.as < Node * > () = yystack_[2].value.as < Node * > (); }
#line 1555 "parser.tab.cc"
    break;

  case 67: // equality: relational
#line 451 "parser.yy"
               {
    yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();
  }
#line 1563 "parser.tab.cc"
    break;

  case 68: // relational: relational LT additive
#line 457 "parser.yy"
                           {
    yylhs.value.as < Node * > () = new Node("Less_than", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1573 "parser.tab.cc"
    break;

  case 69: // relational: relational GT additive
#line 462 "parser.yy"
                           {
    yylhs.value.as < Node * > () = new Node("Greater_than", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1583 "parser.tab.cc"
    break;

  case 70: // relational: relational LE additive
#line 467 "parser.yy"
                           {
    yylhs.value.as < Node * > () = new Node("Less_than_or_equal_to", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1593 "parser.tab.cc"
    break;

  case 71: // relational: relational GE additive
#line 472 "parser.yy"
                           {
    yylhs.value.as < Node * > () = new Node("Greater_than_or_equal_to", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1603 "parser.tab.cc"
    break;

  case 72: // relational: additive
#line 477 "parser.yy"
             {
    yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();
  }
#line 1611 "parser.tab.cc"
    break;

  case 73: // additive: additive PLUSOP multiplicative
#line 483 "parser.yy"
                                 {
    yylhs.value.as < Node * > () = new Node("Add", "", yylineno); 
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1621 "parser.tab.cc"
    break;

  case 74: // additive: additive MINUSOP multiplicative
#line 488 "parser.yy"
                                    {
    yylhs.value.as < Node * > () = new Node("Minus", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());

  }
#line 1632 "parser.tab.cc"
    break;

  case 75: // additive: multiplicative
#line 494 "parser.yy"
                   {
    yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();
  }
#line 1640 "parser.tab.cc"
    break;

  case 76: // power: unary POWER power
#line 500 "parser.yy"
                    {
      yylhs.value.as < Node * > () = new Node("Power", "", yylineno);
      yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
      yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1650 "parser.tab.cc"
    break;

  case 77: // power: unary
#line 505 "parser.yy"
        {
      yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();
  }
#line 1658 "parser.tab.cc"
    break;

  case 78: // multiplicative: multiplicative MULTOP unary
#line 511 "parser.yy"
                              {
    yylhs.value.as < Node * > () = new Node("Multiply", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1668 "parser.tab.cc"
    break;

  case 79: // multiplicative: multiplicative DIVOP unary
#line 516 "parser.yy"
                               {
    yylhs.value.as < Node * > () = new Node("Divide", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1678 "parser.tab.cc"
    break;

  case 80: // multiplicative: power
#line 521 "parser.yy"
          {
    yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();
  }
#line 1686 "parser.tab.cc"
    break;

  case 81: // unary: EXCLAMATION_MARK unary
#line 528 "parser.yy"
    {
      yylhs.value.as < Node * > () = new Node("!", "", yylineno);
      yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 1695 "parser.tab.cc"
    break;

  case 82: // unary: primary
#line 533 "parser.yy"
    {
      yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();
    }
#line 1703 "parser.tab.cc"
    break;

  case 83: // primary: INT
#line 539 "parser.yy"
        {
    yylhs.value.as < Node * > () = new Node("Value", yystack_[0].value.as < std::string > (), yylineno);
  }
#line 1711 "parser.tab.cc"
    break;

  case 84: // primary: FLOAT
#line 542 "parser.yy"
          {
    yylhs.value.as < Node * > () = new Node("Value", yystack_[0].value.as < std::string > (), yylineno);
  }
#line 1719 "parser.tab.cc"
    break;

  case 85: // primary: TRUE
#line 545 "parser.yy"
         {
    yylhs.value.as < Node * > () = new Node("Value", yystack_[0].value.as < std::string > (), yylineno);
  }
#line 1727 "parser.tab.cc"
    break;

  case 86: // primary: FALSE
#line 548 "parser.yy"
          {
    yylhs.value.as < Node * > () = new Node("Value", yystack_[0].value.as < std::string > (), yylineno);
  }
#line 1735 "parser.tab.cc"
    break;

  case 87: // primary: ID
#line 551 "parser.yy"
       {
    yylhs.value.as < Node * > () = new Node("Value", yystack_[0].value.as < std::string > (), yylineno);
  }
#line 1743 "parser.tab.cc"
    break;

  case 88: // primary: LP logical_or RP
#line 554 "parser.yy"
                     {
    yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
  }
#line 1751 "parser.tab.cc"
    break;

  case 89: // primary: array_call
#line 558 "parser.yy"
             {
    yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();
  }
#line 1759 "parser.tab.cc"
    break;

  case 90: // primary: func_call
#line 562 "parser.yy"
            {
    yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();
  }
#line 1767 "parser.tab.cc"
    break;

  case 91: // type: INT_TYPE
#line 568 "parser.yy"
           {
    yylhs.value.as < Node * > () = new Node("Type", yystack_[0].value.as < std::string > (), yylineno);
  }
#line 1775 "parser.tab.cc"
    break;

  case 92: // type: FLOAT_TYPE
#line 572 "parser.yy"
             {
    yylhs.value.as < Node * > () = new Node("Type", yystack_[0].value.as < std::string > (), yylineno);
  }
#line 1783 "parser.tab.cc"
    break;

  case 93: // type: BOOLEAN_TYPE
#line 575 "parser.yy"
                 {
    yylhs.value.as < Node * > () = new Node("Type", yystack_[0].value.as < std::string > (), yylineno);
  }
#line 1791 "parser.tab.cc"
    break;

  case 94: // type: VOID_TYPE
#line 579 "parser.yy"
            {
    yylhs.value.as < Node * > () = new Node("Type", yystack_[0].value.as < std::string > (), yylineno);
  }
#line 1799 "parser.tab.cc"
    break;

  case 95: // type: FLOAT_ARRAY_TYPE
#line 583 "parser.yy"
                   {
    yylhs.value.as < Node * > () = new Node("Type", yystack_[0].value.as < std::string > (), yylineno);
  }
#line 1807 "parser.tab.cc"
    break;

  case 96: // type: INT_ARRAY_TYPE
#line 587 "parser.yy"
                 {
    yylhs.value.as < Node * > () = new Node("Type", yystack_[0].value.as < std::string > (), yylineno);
  }
#line 1815 "parser.tab.cc"
    break;

  case 97: // comment: COMMENT
#line 593 "parser.yy"
          {
    yylhs.value.as < Node * > () = new Node("Comment", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(new Node("Value", yystack_[0].value.as < std::string > (), yylineno));
  }
#line 1824 "parser.tab.cc"
    break;

  case 98: // values: primary
#line 601 "parser.yy"
          {
    yylhs.value.as < Node * > () = new Node("Array_literal", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1833 "parser.tab.cc"
    break;

  case 99: // values: values COMMA primary
#line 606 "parser.yy"
                       {
    yylhs.value.as < Node * > () = yystack_[2].value.as < Node * > ();
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1842 "parser.tab.cc"
    break;

  case 100: // array_call: ID SLB expression SRB
#line 613 "parser.yy"
                        {
    yylhs.value.as < Node * > () = new Node("Array", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(new Node("Identifier", yystack_[3].value.as < std::string > (), yylineno));
    Node * index = new Node("Index", "", yylineno);
    index->children.push_back(yystack_[1].value.as < Node * > ());

    yylhs.value.as < Node * > ()->children.push_back(index);
  }
#line 1855 "parser.tab.cc"
    break;

  case 101: // array_call: ID DOT LENGTH
#line 622 "parser.yy"
                {
    yylhs.value.as < Node * > () = new Node("Array", "", yylineno);
    Node * identifier = new Node("Identifier", yystack_[2].value.as < std::string > (), yylineno);
    identifier->children.push_back(new Node("function_call", yystack_[0].value.as < std::string > (), yylineno));
    yylhs.value.as < Node * > ()->children.push_back(identifier);

  }
#line 1867 "parser.tab.cc"
    break;


#line 1871 "parser.tab.cc"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (YY_MOVE (msg));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;


      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what ());
  }

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

  std::string
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  // parser::context.
  parser::context::context (const parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    const int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        const int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        const int yychecklim = yylast_ - yyn + 1;
        const int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck_[yyx + yyn] == yyx && yyx != symbol_kind::S_YYerror
              && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
            {
              if (!yyarg)
                ++yycount;
              else if (yycount == yyargn)
                return 0;
              else
                yyarg[yycount++] = YY_CAST (symbol_kind_type, yyx);
            }
      }

    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }






  int
  parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const short parser::yypact_ninf_ = -145;

  const signed char parser::yytable_ninf_ = -1;

  const short
  parser::yypact_[] =
  {
     202,    68,    68,   284,    68,    -1,    24,  -145,  -145,    47,
      60,    77,    53,  -145,  -145,  -145,  -145,   154,  -145,  -145,
    -145,  -145,  -145,    78,  -145,  -145,   127,   130,   159,  -145,
    -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,
    -145,  -145,  -145,  -145,   136,   139,     7,    88,    76,  -145,
      65,   149,  -145,  -145,  -145,   131,    67,  -145,  -145,     9,
     243,  -145,   112,    68,    68,   -11,   140,   146,    11,    68,
      79,   212,    -2,   138,  -145,  -145,  -145,  -145,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,   119,    68,   133,  -145,  -145,   100,   152,   160,   163,
     165,    95,   158,   167,  -145,   171,   143,    -4,    39,  -145,
     193,  -145,   197,  -145,   189,    29,  -145,   198,   253,   139,
       7,    88,    88,    76,    76,    76,    76,    65,    65,  -145,
    -145,  -145,    35,  -145,    58,    79,   176,  -145,  -145,   202,
     196,    68,   177,   307,   307,   203,   180,  -145,    68,  -145,
     213,   217,    68,    95,   237,   238,  -145,   221,   248,  -145,
    -145,   234,    95,   244,   146,   146,  -145,   307,   251,  -145,
     252,  -145,   146,  -145,  -145,   122,   213,   300,  -145,  -145,
     202,   254,    68,  -145,  -145,   146,   307,   278,  -145,  -145,
      95,  -145,   109,   281,  -145,   286,  -145,    95,    10,  -145,
    -145,  -145,    79,   176,    95,   288,   265,  -145,  -145,   123,
     146,   282,  -145,  -145,    68,   291,   146,  -145
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,     0,     0,     0,     0,     0,    57,    58,     0,
       0,     0,     0,    83,    84,    85,    86,    87,    97,    91,
      92,    93,    94,     0,    96,    95,     0,     0,     0,     5,
       7,     8,    10,     9,    90,    11,    12,    13,    14,    15,
      16,    17,    18,    59,    60,    62,    64,    67,    72,    80,
      75,    77,    82,    19,    20,    89,    87,    81,    89,     0,
       0,    56,     0,     0,     0,     0,     0,     0,    42,     0,
       0,     0,     0,     0,     1,     3,     2,     6,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    42,     0,    88,     4,    87,     0,     0,     0,
       0,     0,     0,     0,    22,     0,    87,     0,     0,    43,
       0,   101,     0,    36,     0,     0,    33,     0,     0,    61,
      63,    65,    66,    70,    71,    68,    69,    73,    74,    78,
      79,    76,    34,    28,    42,     0,     0,    53,    55,     0,
       0,     0,     0,     0,     0,     0,     0,    45,     0,   100,
       0,     0,     0,     0,     0,    26,    23,     0,     0,    47,
      46,    48,     0,     0,     0,     0,    37,     0,     0,    44,
       0,    29,     0,    25,    98,     0,     0,     0,    52,    54,
       0,     0,     0,    21,    40,     0,     0,     0,    41,    35,
       0,    30,    87,     0,    24,     0,    49,     0,     0,    39,
      38,    99,     0,     0,     0,     0,     0,    32,    31,     0,
       0,     0,    27,    51,     0,     0,     0,    50
  };

  const short
  parser::yypgoto_[] =
  {
    -145,  -145,     0,   318,   -25,  -145,  -145,  -144,  -145,  -145,
    -145,  -145,   -63,   155,  -145,  -145,  -145,  -145,  -145,  -145,
    -145,  -145,    -3,   334,   259,   264,   -69,   142,   258,     1,
       3,   -79,   -62,  -145,   151,     2
  };

  const unsigned char
  parser::yydefgoto_[] =
  {
       0,    26,   159,    28,    29,    30,    31,    97,    32,   107,
      33,   108,    34,   161,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,   175,    58
  };

  const unsigned char
  parser::yytable_[] =
  {
      27,    61,    55,    77,    57,    55,   171,   113,     1,   115,
     117,   121,   122,   101,   145,     2,    62,    78,    80,    81,
     146,     1,   140,    82,    83,    84,    85,    94,     2,   105,
      55,   102,   191,   193,   206,    77,    13,    14,    15,    16,
      56,    63,    19,    20,    21,    22,   151,    24,    25,    13,
      14,    15,    16,   106,    69,   152,   155,   147,    93,    98,
      99,   100,    55,   148,    64,   109,   110,   104,     1,   116,
      88,    89,   157,   158,   174,     2,   156,    65,     1,    86,
      87,   165,   166,   181,    92,     2,    69,   127,   128,   109,
      93,   129,   130,   133,    66,    67,    13,    14,    15,    16,
      56,    82,    83,    84,    85,   185,    13,    14,    15,    16,
      56,   201,     2,   198,   160,   195,   111,   134,   205,    69,
      73,   112,     1,   135,   200,   174,   134,    74,    69,     2,
      75,   109,   202,    13,    14,    15,    16,    56,   163,   207,
     208,    55,   189,   212,    78,   169,   190,   190,    79,   173,
      13,    14,    15,    16,    96,   160,    90,    91,   103,    76,
      92,   132,    69,   118,   183,   184,    93,     3,   144,     1,
     111,    68,   188,    69,   194,   136,     2,    70,   137,    71,
      72,   138,    55,   139,   141,   199,     4,     5,     6,     7,
       8,     9,   142,    10,    11,    12,   143,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
     213,   215,     1,   149,    92,   150,   217,   153,   112,     2,
     162,   164,   168,     3,   123,   124,   125,   126,   167,     4,
       5,     6,     7,     8,     9,   172,    10,    11,    12,   178,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,     1,   114,   170,    19,    20,    21,    22,
       2,    24,    25,   176,   177,    95,   179,   180,   182,   187,
       4,     5,     6,     7,     8,     9,   186,    10,    11,    12,
     197,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,     1,   154,   156,    19,    20,    21,
      22,     2,    24,    25,   203,   204,   210,   211,   214,   216,
       1,     4,     5,     6,     7,     8,     9,     2,    10,    11,
      12,    60,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,   196,    59,   119,    13,    14,
      15,    16,   192,   120,    19,    20,    21,    22,   131,    24,
      25,    19,    20,    21,    22,   209,    24,    25
  };

  const unsigned char
  parser::yycheck_[] =
  {
       0,     4,     0,    28,     1,     3,   150,    70,    10,    71,
      72,    80,    81,    24,    18,    17,    17,     8,    11,    12,
      24,    10,   101,    13,    14,    15,    16,    18,    17,    18,
      28,    42,   176,   177,    24,    60,    38,    39,    40,    41,
      42,    17,    44,    45,    46,    47,    17,    49,    50,    38,
      39,    40,    41,    42,    19,    26,   118,    18,    23,    62,
      63,    64,    60,    24,    17,    68,    69,    67,    10,    72,
       5,     6,   135,   136,   153,    17,    18,    17,    10,     3,
       4,   143,   144,   162,    17,    17,    19,    86,    87,    92,
      23,    88,    89,    91,    17,    42,    38,    39,    40,    41,
      42,    13,    14,    15,    16,   167,    38,    39,    40,    41,
      42,   190,    17,   182,   139,   177,    37,    17,   197,    19,
      42,    42,    10,    23,   186,   204,    17,     0,    19,    17,
       0,   134,    23,    38,    39,    40,    41,    42,   141,   202,
     203,   139,    20,    20,     8,   148,    24,    24,     9,   152,
      38,    39,    40,    41,    42,   180,     7,    26,    18,     0,
      17,    42,    19,    25,   164,   165,    23,    21,    25,    10,
      37,    17,   172,    19,   177,    23,    17,    23,    18,    25,
      26,    18,   180,    18,    26,   185,    27,    28,    29,    30,
      31,    32,    25,    34,    35,    36,    25,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
     210,   214,    10,    20,    17,    26,   216,    19,    42,    17,
      24,    44,    42,    21,    82,    83,    84,    85,    25,    27,
      28,    29,    30,    31,    32,    18,    34,    35,    36,    18,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    10,    42,    42,    44,    45,    46,    47,
      17,    49,    50,    26,    26,    22,    18,    33,    24,    17,
      27,    28,    29,    30,    31,    32,    25,    34,    35,    36,
      26,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    10,    42,    18,    44,    45,    46,
      47,    17,    49,    50,    23,    19,    18,    42,    26,    18,
      10,    27,    28,    29,    30,    31,    32,    17,    34,    35,
      36,     3,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,   180,     2,    78,    38,    39,
      40,    41,    42,    79,    44,    45,    46,    47,    90,    49,
      50,    44,    45,    46,    47,   204,    49,    50
  };

  const signed char
  parser::yystos_[] =
  {
       0,    10,    17,    21,    27,    28,    29,    30,    31,    32,
      34,    35,    36,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    53,    54,    55,    56,
      57,    58,    60,    62,    64,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    87,    42,    82,    87,    75,
      55,    74,    17,    17,    17,    17,    17,    42,    17,    19,
      23,    25,    26,    42,     0,     0,     0,    56,     8,     9,
      11,    12,    13,    14,    15,    16,     3,     4,     5,     6,
       7,    26,    17,    23,    18,    22,    42,    59,    74,    74,
      74,    24,    42,    18,    54,    18,    42,    61,    63,    74,
      74,    37,    42,    64,    42,    84,    74,    84,    25,    76,
      77,    78,    78,    79,    79,    79,    79,    81,    81,    82,
      82,    80,    42,    87,    17,    23,    23,    18,    18,    18,
      83,    26,    25,    25,    25,    18,    24,    18,    24,    20,
      26,    17,    26,    19,    42,    84,    18,    64,    64,    54,
      56,    65,    24,    74,    44,    84,    84,    25,    42,    74,
      42,    59,    18,    74,    83,    86,    26,    26,    18,    18,
      33,    83,    24,    54,    54,    84,    25,    17,    54,    20,
      24,    59,    42,    59,    74,    84,    65,    26,    78,    54,
      84,    83,    23,    23,    19,    83,    24,    64,    64,    86,
      18,    42,    20,    54,    26,    74,    18,    54
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    52,    53,    53,    54,    55,    55,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    57,    58,    59,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    61,    61,    62,
      62,    62,    63,    63,    63,    64,    65,    65,    66,    66,
      67,    67,    68,    68,    68,    69,    70,    71,    72,    73,
      74,    75,    75,    76,    76,    77,    77,    77,    78,    78,
      78,    78,    78,    79,    79,    79,    80,    80,    81,    81,
      81,    82,    82,    83,    83,    83,    83,    83,    83,    83,
      83,    84,    84,    84,    84,    84,    84,    85,    86,    86,
      87,    87
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     2,     2,     3,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     6,     3,     3,     6,     5,     4,     9,     3,     5,
       6,     8,     8,     3,     3,     6,     3,     3,     5,     7,
       6,     6,     0,     1,     3,     4,     1,     1,     5,     7,
      13,    10,     6,     4,     6,     4,     2,     1,     1,     1,
       1,     3,     1,     3,     1,     3,     3,     1,     3,     3,
       3,     3,     1,     3,     3,     1,     3,     1,     3,     3,
       1,     2,     1,     1,     1,     1,     1,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       4,     3
  };


#if YYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "PLUSOP", "MINUSOP",
  "MULTOP", "DIVOP", "POWER", "OR", "AND", "EXCLAMATION_MARK", "EQTO",
  "NEQ", "LE", "GE", "LT", "GT", "LP", "RP", "SLB", "SRB", "LCB", "RCB",
  "DOT", "COMMA", "COLON", "ASSIGN", "RETURN", "PRINT", "READ", "BREAK",
  "CONTINUE", "IF", "ELSE", "FOR", "MAIN", "CLASS", "LENGTH", "INT",
  "FLOAT", "TRUE", "FALSE", "ID", "COMMENT", "INT_TYPE", "FLOAT_TYPE",
  "BOOLEAN_TYPE", "VOID_TYPE", "VOLATILE", "INT_ARRAY_TYPE",
  "FLOAT_ARRAY_TYPE", "IFX", "$accept", "root", "block", "statements",
  "statement", "main_def", "class_def", "class_call", "assignment",
  "parameters", "func_def", "arguments", "func_call", "if_body", "if_stmt",
  "for_stmt", "print_stmt", "read_stmt", "return_stmt", "break_stmt",
  "continue_stmt", "expr_stmt", "expression", "logical_or", "logical_and",
  "equality", "relational", "additive", "power", "multiplicative", "unary",
  "primary", "type", "comment", "values", "array_call", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,    71,    71,    75,    81,    87,    91,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   116,   123,   130,   136,   144,   151,   158,   166,   174,
     182,   190,   200,   210,   216,   223,   232,   239,   247,   256,
     266,   275,   286,   290,   295,   301,   309,   314,   318,   324,
     338,   353,   365,   372,   377,   386,   393,   400,   406,   410,
     416,   422,   427,   433,   439,   445,   450,   451,   457,   462,
     467,   472,   477,   483,   488,   494,   500,   505,   511,   516,
     521,   527,   532,   539,   542,   545,   548,   551,   554,   558,
     562,   568,   572,   575,   579,   583,   587,   593,   601,   606,
     613,   622
  };

  void
  parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


} // yy
#line 2507 "parser.tab.cc"

#line 629 "parser.yy"




/* ./compiler < test_files/valid/test1.cpm */

