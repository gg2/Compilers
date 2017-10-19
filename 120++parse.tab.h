/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_120_PARSE_TAB_H_INCLUDED
# define YY_YY_120_PARSE_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IDENTIFIER = 258,
    INTEGER = 259,
    FLOATING = 260,
    CHARACTER = 261,
    STRING = 262,
    TYPEDEF_NAME = 263,
    NAMESPACE_NAME = 264,
    CLASS_NAME = 265,
    ENUM_NAME = 266,
    TEMPLATE_NAME = 267,
    ELLIPSIS = 268,
    COLONCOLON = 269,
    DOTSTAR = 270,
    ADDEQ = 271,
    SUBEQ = 272,
    MULEQ = 273,
    DIVEQ = 274,
    MODEQ = 275,
    ANDEQ = 276,
    OREQ = 277,
    XOREQ = 278,
    SL = 279,
    SLEQ = 280,
    SR = 281,
    SREQ = 282,
    EQ = 283,
    LTEQ = 284,
    GTEQ = 285,
    NOTEQ = 286,
    ANDAND = 287,
    OROR = 288,
    PLUSPLUS = 289,
    MINUSMINUS = 290,
    ARROWSTAR = 291,
    ARROW = 292,
    ALIGNAS = 293,
    ALIGNOF = 294,
    ASM = 295,
    AUTO = 296,
    BOOL = 297,
    BREAK = 298,
    CASE = 299,
    CATCH = 300,
    CHAR = 301,
    CHAR16_T = 302,
    CHAR32_T = 303,
    CLASS = 304,
    CONST = 305,
    CONST_CAST = 306,
    CONST_EXPR = 307,
    CONTINUE = 308,
    DECLTYPE = 309,
    DEFAULT = 310,
    DELETE = 311,
    DO = 312,
    DOUBLE = 313,
    DYNAMIC_CAST = 314,
    ELSE = 315,
    ENUM = 316,
    EXPLICIT = 317,
    EXPORT = 318,
    EXTERN = 319,
    FALSE = 320,
    FLOAT = 321,
    FOR = 322,
    FRIEND = 323,
    GOTO = 324,
    IF = 325,
    INLINE = 326,
    INT = 327,
    LONG = 328,
    MUTABLE = 329,
    NAMESPACE = 330,
    NEW = 331,
    NOEXCEPT = 332,
    NULLPTR = 333,
    OPERATOR = 334,
    PRIVATE = 335,
    PROTECTED = 336,
    PUBLIC = 337,
    REGISTER = 338,
    REINTERPRET_CAST = 339,
    RETURN = 340,
    SHORT = 341,
    SIGNED = 342,
    SIZEOF = 343,
    STATIC = 344,
    STATIC_ASSERT = 345,
    STATIC_CAST = 346,
    STRUCT = 347,
    SWITCH = 348,
    TEMPLATE = 349,
    THIS = 350,
    THREAD_LOCAL = 351,
    THROW = 352,
    TRUE = 353,
    TRY = 354,
    TYPEDEF = 355,
    TYPEID = 356,
    TYPENAME = 357,
    UNION = 358,
    UNSIGNED = 359,
    USING = 360,
    VIRTUAL = 361,
    VOID = 362,
    VOLATILE = 363,
    WCHAR_T = 364,
    WHILE = 365
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef  tree*  YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_120_PARSE_TAB_H_INCLUDED  */
