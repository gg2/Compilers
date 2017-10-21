/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 44 "120++parse.y" /* yacc.c:339  */


//#define YYDEBUG 1

#include <stdio.h>
#include <string.h>
#include "120++nonterms.h"
#include "globals.h"

int yydebug=0;
static const short W_PARSE_UNSUPPORTED = 1;
static const short W_PARSE_UNHANDLED = 2;

extern int yylex(void);
void handle_parse_warning(char *msg,short warning_type);
static void yyerror(char *msg);


#line 85 "120++parse.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "120++parse.tab.h".  */
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

/* Copy the second part of user declarations.  */

#line 247 "120++parse.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  180
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   4186

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  137
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  170
/* YYNRULES -- Number of rules.  */
#define YYNRULES  509
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  892

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   365

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   125,     2,     2,     2,   127,   122,     2,
     113,   114,   121,   123,   111,   124,   118,   126,   135,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   131,   112,
     119,   132,   120,   130,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   116,     2,   117,   128,   136,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   133,   129,   134,   115,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   104,   104,   108,   113,   118,   119,   124,   129,   137,
     141,   142,   143,   144,   145,   149,   153,   157,   161,   165,
     166,   174,   183,   184,   188,   189,   193,   194,   198,   199,
     203,   204,   208,   209,   213,   214,   218,   219,   223,   224,
     228,   229,   233,   234,   238,   239,   243,   244,   248,   249,
     253,   254,   258,   259,   263,   264,   268,   269,   273,   274,
     278,   279,   283,   284,   288,   289,   293,   294,   298,   299,
     303,   304,   312,   313,   314,   315,   319,   320,   324,   325,
     326,   327,   331,   332,   336,   337,   338,   339,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   372,   373,   374,   375,   376,   377,
     378,   379,   380,   381,   385,   386,   387,   388,   392,   393,
     394,   395,   399,   403,   407,   408,   412,   413,   417,   421,
     422,   423,   424,   428,   429,   433,   434,   435,   439,   440,
     441,   442,   446,   447,   448,   452,   453,   454,   458,   459,
     460,   461,   462,   466,   467,   468,   472,   473,   477,   478,
     482,   483,   487,   488,   492,   493,   497,   498,   502,   506,
     507,   508,   512,   513,   514,   515,   516,   517,   518,   519,
     520,   521,   522,   526,   527,   535,   536,   537,   538,   539,
     540,   541,   542,   546,   547,   548,   552,   556,   560,   561,
     565,   566,   567,   571,   572,   576,   577,   578,   582,   583,
     587,   588,   589,   590,   594,   602,   603,   607,   608,   609,
     610,   611,   612,   613,   617,   618,   619,   620,   621,   625,
     626,   630,   631,   632,   633,   634,   638,   639,   643,   644,
     645,   646,   647,   651,   652,   653,   657,   658,   659,   660,
     661,   665,   666,   667,   668,   669,   670,   671,   672,   673,
     674,   675,   676,   677,   678,   679,   680,   684,   685,   686,
     690,   691,   692,   693,   694,   695,   696,   700,   704,   705,
     709,   710,   714,   718,   719,   723,   724,   728,   732,   736,
     740,   744,   748,   749,   750,   751,   755,   756,   757,   758,
     759,   763,   764,   765,   766,   770,   774,   775,   783,   784,
     788,   792,   793,   797,   798,   799,   800,   801,   802,   803,
     804,   805,   806,   810,   811,   812,   813,   814,   815,   816,
     820,   821,   825,   826,   830,   831,   832,   833,   837,   841,
     845,   846,   850,   851,   852,   853,   854,   855,   859,   860,
     861,   862,   866,   867,   871,   872,   873,   874,   878,   879,
     880,   881,   885,   889,   890,   894,   895,   896,   900,   901,
     909,   913,   914,   915,   916,   920,   921,   922,   926,   927,
     931,   932,   933,   934,   935,   936,   937,   938,   942,   943,
     947,   948,   949,   950,   959,   963,   971,   975,   976,   980,
     981,   982,   983,   984,   985,   986,   987,   988,   989,   990,
     991,   995,   996,   997,  1005,  1009,  1013,  1017,  1021,  1022,
    1026,  1030,  1031,  1032,  1033,  1034,  1042,  1046,  1047,  1048,
    1049,  1050,  1051,  1052,  1053,  1054,  1055,  1056,  1057,  1058,
    1059,  1060,  1061,  1062,  1063,  1064,  1065,  1066,  1067,  1068,
    1069,  1070,  1071,  1072,  1073,  1074,  1075,  1076,  1077,  1078,
    1079,  1080,  1081,  1082,  1083,  1084,  1085,  1086,  1087,  1095,
    1099,  1100,  1104,  1105,  1109,  1110,  1111,  1112,  1113,  1114,
    1118,  1122,  1123,  1127,  1128,  1129,  1133,  1137,  1145,  1149,
    1153,  1157,  1161,  1162,  1163,  1164,  1168,  1172,  1176,  1177
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "INTEGER", "FLOATING",
  "CHARACTER", "STRING", "TYPEDEF_NAME", "NAMESPACE_NAME", "CLASS_NAME",
  "ENUM_NAME", "TEMPLATE_NAME", "ELLIPSIS", "COLONCOLON", "DOTSTAR",
  "ADDEQ", "SUBEQ", "MULEQ", "DIVEQ", "MODEQ", "ANDEQ", "OREQ", "XOREQ",
  "SL", "SLEQ", "SR", "SREQ", "EQ", "LTEQ", "GTEQ", "NOTEQ", "ANDAND",
  "OROR", "PLUSPLUS", "MINUSMINUS", "ARROWSTAR", "ARROW", "ALIGNAS",
  "ALIGNOF", "ASM", "AUTO", "BOOL", "BREAK", "CASE", "CATCH", "CHAR",
  "CHAR16_T", "CHAR32_T", "CLASS", "CONST", "CONST_CAST", "CONST_EXPR",
  "CONTINUE", "DECLTYPE", "DEFAULT", "DELETE", "DO", "DOUBLE",
  "DYNAMIC_CAST", "ELSE", "ENUM", "EXPLICIT", "EXPORT", "EXTERN", "FALSE",
  "FLOAT", "FOR", "FRIEND", "GOTO", "IF", "INLINE", "INT", "LONG",
  "MUTABLE", "NAMESPACE", "NEW", "NOEXCEPT", "NULLPTR", "OPERATOR",
  "PRIVATE", "PROTECTED", "PUBLIC", "REGISTER", "REINTERPRET_CAST",
  "RETURN", "SHORT", "SIGNED", "SIZEOF", "STATIC", "STATIC_ASSERT",
  "STATIC_CAST", "STRUCT", "SWITCH", "TEMPLATE", "THIS", "THREAD_LOCAL",
  "THROW", "TRUE", "TRY", "TYPEDEF", "TYPEID", "TYPENAME", "UNION",
  "UNSIGNED", "USING", "VIRTUAL", "VOID", "VOLATILE", "WCHAR_T", "WHILE",
  "','", "';'", "'('", "')'", "'~'", "'['", "']'", "'.'", "'<'", "'>'",
  "'*'", "'&'", "'+'", "'-'", "'!'", "'/'", "'%'", "'^'", "'|'", "'?'",
  "':'", "'='", "'{'", "'}'", "'0'", "'_'", "$accept", "typedef_name",
  "namespace_name", "original_namespace_name", "class_name", "enum_name",
  "template_name", "identifier", "literal", "integer_literal",
  "character_literal", "floating_literal", "string_literal",
  "boolean_literal", "program_start", "declaration_seq_opt",
  "statement_seq_opt", "expression_list_opt", "constant_expression_opt",
  "condition_opt", "assignment_expression_opt", "new_placement_opt",
  "new_initializer_opt", "new_declarator_opt", "nested_name_specifier_opt",
  "initializer_opt", "ctor_initializer_opt", "type_specifier_seq_opt",
  "type_id_list_opt", "abstract_declarator_opt",
  "direct_abstract_declarator_opt", "parameter_declaration_clause_opt",
  "enumerator_list_opt", "member_specification_opt", "handler_seq_opt",
  "conversion_declarator_opt", "EXPORT_opt", "COMMA_opt", "COLONCOLON_opt",
  "SEMICOLON_opt", "primary_expression", "id_expression", "unqualified_id",
  "qualified_id", "nested_name_specifier", "postfix_expression",
  "unary_expression", "unary_operator", "new_expression", "new_placement",
  "new_type_id", "new_declarator", "direct_new_declarator",
  "new_initializer", "delete_expression", "cast_expression",
  "pm_expression", "multiplicative_expression", "additive_expression",
  "shift_expression", "relational_expression", "equality_expression",
  "and_expression", "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "constant_expression", "assignment_expression",
  "assignment_operator", "expression_list", "statement",
  "labeled_statement", "expression_statement", "compound_statement",
  "statement_seq", "selection_statement", "condition",
  "iteration_statement", "for_init_statement", "jump_statement",
  "declaration_statement", "declaration_seq", "declaration",
  "block_declaration", "simple_declaration", "decl_specifier",
  "decl_specifier_seq", "storage_class_specifier", "function_specifier",
  "type_specifier", "simple_type_specifier", "type_name",
  "elaborated_type_specifier", "enum_specifier", "enumerator_list",
  "enumerator_definition", "enumerator", "namespace_definition",
  "named_namespace_definition", "original_namespace_definition",
  "extension_namespace_definition", "unnamed_namespace_definition",
  "namespace_body", "namespace_alias_definition",
  "qualified_namespace_specifier", "using_declaration", "using_directive",
  "asm_definition", "linkage_specification", "init_declarator_list",
  "init_declarator", "declarator", "direct_declarator", "ptr_operator",
  "cv_qualifier_seq", "cv_qualifier", "declarator_id", "type_id",
  "type_specifier_seq", "abstract_declarator",
  "direct_abstract_declarator", "parameter_declaration_clause",
  "parameter_declaration_list", "parameter_declaration",
  "function_definition", "function_body", "initializer",
  "initializer_clause", "initializer_list", "class_specifier",
  "class_head", "class_key", "member_specification", "member_declaration",
  "member_declarator_list", "member_declarator", "pure_specifier",
  "constant_initializer", "base_clause", "base_specifier_list",
  "base_specifier", "access_specifier", "conversion_function_id",
  "conversion_type_id", "conversion_declarator", "ctor_initializer",
  "mem_initializer_list", "mem_initializer", "mem_initializer_id",
  "operator_function_id", "operator", "template_declaration",
  "template_parameter_list", "template_parameter", "type_parameter",
  "template_id", "template_argument_list", "template_argument",
  "explicit_instantiation", "explicit_specialization", "try_block",
  "function_try_block", "handler_seq", "handler", "exception_declaration",
  "throw_expression", "exception_specification", "type_id_list", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,    44,    59,    40,    41,   126,    91,    93,    46,    60,
      62,    42,    38,    43,    45,    33,    47,    37,    94,   124,
      63,    58,    61,   123,   125,    48,    95
};
# endif

#define YYPACT_NINF -697

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-697)))

#define YYTABLE_NINF -505

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    3358,  -697,  -697,  -697,  -697,  -697,  -697,   305,   -60,  -697,
    -697,  -697,  -697,  -697,  -697,  -697,  -697,   502,  -697,  -697,
      88,  -697,  -697,  -697,  -697,  -697,  -697,    27,  2310,  -697,
    -697,  -697,  -697,  -697,  3271,  -697,   122,  -697,  -697,   581,
    -697,  -697,  -697,  -697,   279,   350,    19,  -697,  -697,   145,
    -697,    18,  -697,    52,  -697,   188,  -697,    98,  -697,  -697,
    -697,   484,  3358,  -697,  -697,  -697,  -697,  3445,  -697,  -697,
    -697,  -697,  -697,  -697,  -697,  -697,  -697,  -697,  -697,  -697,
    -697,  -697,  -697,  -697,  -697,   -28,    92,   279,  -697,  -697,
    -697,  -697,    79,   963,  -697,  -697,  -697,  -697,  -697,  -697,
     190,   162,  -697,   643,  -697,    88,   456,   190,   107,   248,
    -697,  2072,  3358,   139,   -55,   479,  -697,  -697,  -697,  -697,
    -697,  -697,  -697,  -697,  -697,  -697,  -697,  -697,  -697,  -697,
    -697,  -697,  -697,  -697,  -697,  -697,  -697,  -697,   168,   174,
    -697,   182,  -697,   183,  -697,  -697,  -697,  -697,  -697,  -697,
    -697,  -697,  -697,  -697,  -697,  -697,   162,  4077,   463,  -697,
    -697,   201,  -697,  -697,   479,   571,   325,   704,    65,   305,
      18,    40,   217,  -697,  -697,    19,   479,   813,  3769,  2567,
    -697,   219,    65,    19,  -697,  -697,  -697,  -697,  -697,  -697,
    -697,   292,  -697,   179,   211,  1002,   275,  -697,  -697,  3769,
    2990,  -697,  3184,   456,   235,   248,   479,  -697,    19,  -697,
     236,  -697,   248,   248,  -697,  3358,  -697,  -697,   280,  3358,
    1011,  3358,  -697,   304,   308,  -697,  -697,  -697,  -697,   479,
    -697,   329,   463,  -697,  3358,   248,   362,    65,   479,    71,
     453,   479,    65,   371,   643,  -697,  -697,  -697,   305,    35,
      39,   377,  -697,   385,  3530,  -697,    83,  -697,  -697,  -697,
    -697,   446,  2990,  2990,   404,   406,   414,  2690,   422,   420,
    -697,   434,   436,   442,   447,   440,   448,  3090,   443,  -697,
    2790,  -697,   452,  2567,   350,  2990,  2990,  -697,  -697,  -697,
      52,  -697,  -697,  -697,  -697,  -697,  -697,  -697,  -697,   739,
     699,  -697,  2990,  -697,  -697,  -697,    77,    20,   313,   458,
     251,   169,   445,   441,   450,   540,  1023,  -697,  -697,  -697,
     799,   -29,  -697,  -697,  3839,  -697,  -697,   279,  -697,  2790,
    2192,  -697,   275,  -697,  -697,   275,   479,   190,  -697,   350,
    -697,   464,   473,  1815,  -697,  -697,   474,    41,   404,   406,
     422,   434,   436,   442,   448,   460,    39,     7,  -697,  -697,
    -697,  -697,  -697,   830,  -697,   461,   472,   475,  3615,  -697,
      53,   498,  -697,  3184,   412,  -697,   480,  -697,  -697,   248,
     522,  -697,   235,  -697,  -697,   500,  -697,  -697,   488,   503,
    -697,   481,   490,  -697,   491,   479,   145,   453,   506,   493,
    -697,  -697,   499,  -697,  -697,   511,  -697,   520,    84,   453,
    -697,   527,    65,   531,  -697,   739,  3769,  3769,  -697,   494,
     513,   109,   516,   430,  -697,   163,  -697,  3941,  2890,   447,
    -697,  -697,  2790,  2790,  4077,   517,  -697,  2790,  4077,  2790,
    2790,  2790,  2790,  1263,  -697,  4077,  2790,  2567,  -697,  4077,
    -697,  -697,  2567,  -697,   187,   535,  -697,  -697,  -697,  -697,
     246,  2790,  2790,   762,  -697,  2990,  2990,  2990,  2990,  2990,
    2990,  2990,  2990,  2990,  2990,  2990,  2990,  2990,  2990,  2990,
    2990,  2990,  2990,  2990,  -697,  -697,  -697,  -697,  -697,  -697,
    -697,  -697,  -697,  -697,  2990,  2790,  -697,  2790,   285,  -697,
     799,  2567,  -697,   248,   533,   111,  -697,    87,  -697,  -697,
    -697,   -24,   193,  1682,  -697,  -697,  -697,   612,   190,   350,
    -697,  1002,  2790,   546,  2990,   549,   536,  1946,   556,   248,
     558,   248,  2790,   559,   275,   561,   548,   528,   565,   570,
    -697,  -697,  -697,  -697,  1815,  -697,  -697,  -697,  -697,  -697,
    3445,  -697,     2,  -697,  2990,  -697,  -697,  -697,    53,   418,
    1546,  -697,  -697,  -697,  -697,  -697,   279,  -697,  3184,  -697,
     479,   971,   190,   350,   580,  -697,    95,  -697,  -697,  -697,
     248,  2990,  -697,  -697,   145,   453,  -697,  -697,  -697,  2567,
    -697,  -697,   582,  -697,   585,  -697,   578,   584,   586,  2790,
    3769,  2990,  2790,  -697,  -697,  -697,   587,  -697,  3700,   595,
     605,   601,  2990,   610,   606,   611,   613,   616,   208,  4077,
     618,   256,   615,   624,   627,   623,   212,   630,  2790,  -697,
    2990,   571,   895,  -697,   638,    11,   571,   950,  -697,  -697,
    -697,    77,    77,    77,    20,    20,   313,   313,   458,   458,
     458,   458,   251,   251,   169,   445,   441,   450,   540,   -10,
    -697,  -697,   600,  3839,   621,  3839,  3358,  -697,  -697,  -697,
     644,   641,  -697,   612,  -697,  -697,   655,  -697,   639,  -697,
    1946,   665,  2444,   666,  2567,   648,   671,  2567,   612,  2567,
    1946,  -697,  -697,  -697,   678,   696,  -697,  -697,  -697,  -697,
    -697,   662,  -697,  -697,   190,   350,   479,   350,  1018,  -697,
     522,   479,  1057,   350,  -697,  -697,  -697,   142,  -697,  -697,
    -697,  -697,  -697,  -697,   681,   682,  -697,  2990,  4077,   618,
    -697,  -697,   687,  -697,  -697,   691,  -697,  -697,  -697,  -697,
     705,  2790,  -697,  -697,  2790,  -697,  -697,   689,   256,   708,
    -697,  -697,   716,  -697,  -697,  -697,  -697,  -697,   571,  -697,
    -697,  -697,  -697,   571,  -697,  2790,  4077,   166,  4077,  -697,
    -697,  2192,   697,  4009,  -697,  -697,  -697,  1946,  -697,   717,
    -697,  2567,  -697,  -697,   570,   718,   279,  -697,   721,  -697,
     729,  -697,  4077,  -697,  -697,   350,  -697,   479,   350,  -697,
     350,   479,   350,  -697,  -697,     2,  -697,  -697,   731,  -697,
    2790,  2790,   618,   732,   119,  2990,  -697,  2790,  2790,  -697,
    -697,  -697,  -697,   804,  -697,  -697,  -697,  -697,   877,   734,
    -697,  2790,   743,  -697,  1946,   725,  1946,  1946,   746,  -697,
     750,  -697,   350,  -697,  -697,   350,  -697,   696,  -697,   618,
     218,   233,  -697,  -697,  -697,   748,   276,   301,   248,  -697,
    -697,   275,   353,  2790,   806,  2790,  -697,  -697,  -697,  4077,
    -697,  -697,  -697,  -697,  -697,  -697,  -697,  -697,  -697,   735,
    -697,   758,   757,  1946,  -697,  -697,   863,  -697,  1946,  -697,
    -697,  -697
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
      22,     9,     2,     4,     5,     7,     8,     0,     0,   248,
     265,   266,   267,   268,   385,   342,   274,     0,   255,    65,
     251,   273,   244,   253,   271,   272,   252,     0,     0,   249,
     270,   275,   250,   386,     0,   245,    68,   387,   276,     0,
     254,   264,   343,   269,     0,     0,   333,   335,   279,     0,
       3,   277,   278,     0,    78,     0,    21,     0,   344,    76,
      77,     0,    23,   225,   227,   234,   246,     0,   241,   243,
     242,   256,   261,   259,   258,   233,   293,   295,   296,   294,
     236,   237,   238,   235,   232,    44,   321,     0,   260,   323,
     228,   257,     0,     0,    80,    79,   229,     6,   230,   231,
     277,     0,   345,     0,   347,     0,     0,     0,     0,     0,
      18,     0,    22,     0,     0,    40,   454,   455,   456,   457,
     458,   460,   461,   459,   462,   465,   463,   464,   466,   468,
     469,   467,   470,   471,   472,   473,   475,   476,   438,   437,
     474,     0,   449,     0,   452,   453,   443,   447,   441,   450,
     444,   445,   446,   448,   451,   442,     0,    46,    62,   424,
     436,     0,   496,    69,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    81,   334,   340,    87,    86,    54,     0,
       1,     0,     0,   336,   277,    82,   262,   226,   251,   240,
     247,     0,   318,    42,    44,     0,     0,    45,   370,    54,
      28,   322,    58,     0,   381,     0,    86,   263,   338,   346,
       0,   283,     0,    56,   284,    22,   317,   300,     0,    22,
       0,    22,    41,     0,     0,   477,   478,   349,    47,     0,
     425,     0,    62,    63,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   332,   341,    85,     0,     0,
      84,     0,   361,     0,    50,    55,   360,   362,    15,    17,
      16,    40,     0,     0,   265,   266,     0,     0,   274,     0,
      20,   273,   271,   272,    34,     0,   270,     0,     0,    73,
      32,    19,     0,     0,   127,     0,     0,   124,   125,   126,
     495,    72,    10,    11,    12,    13,    14,    88,    75,     0,
     114,   143,     0,   122,   123,   145,   148,   152,   155,   158,
     163,   166,   168,   170,   172,   174,   176,   179,   493,   494,
      50,     0,   491,   181,     0,    83,   337,     0,   239,     0,
       0,   320,     0,    43,   371,     0,     0,   434,   435,     0,
     427,   428,     0,    24,   372,   368,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   176,   178,    29,
     421,   422,   423,     0,   393,    78,     0,    77,     0,   396,
     400,    70,    59,    58,     0,   398,     0,   397,   281,     0,
       0,   382,   383,    84,   339,     0,   282,   292,     0,    57,
     288,   290,     0,   299,     0,     0,   305,     0,     0,     0,
     440,   439,     0,   426,   497,   285,   310,     0,     0,     0,
     314,     0,     0,     0,   309,     0,    54,    54,   328,    52,
     366,     0,   364,    50,    51,   351,   358,     0,     0,    34,
     115,   116,    26,    26,     0,     0,   139,    26,     0,    26,
      26,    26,     0,     0,    35,     0,    26,     0,   120,     0,
     506,    33,     0,   193,     0,     0,   117,   118,   106,   107,
       0,    26,     0,     0,   119,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   186,   187,   183,   184,   185,   190,
     192,   191,   189,   188,     0,     0,   182,     0,    52,   348,
      50,     0,   490,   385,     0,    68,   483,     0,   480,   482,
     319,    42,     0,     0,   375,   373,   369,     0,   432,     0,
     433,     0,    26,     0,     0,     0,     0,    26,     0,     0,
       0,     0,    26,     0,     0,     0,    78,     0,     0,    27,
     208,   195,   196,   197,    25,   198,   199,   200,   201,   224,
       0,   202,   327,   331,     0,   380,   395,   391,   400,     0,
       0,   401,   402,    71,   394,   388,     0,   392,    58,   280,
       0,     0,   412,     0,   406,   407,     0,   384,   315,   287,
       0,     0,   316,   298,   303,     0,   304,   301,   297,     0,
     308,   312,     0,   313,     0,   307,     0,     0,     0,     0,
      54,    28,     0,   350,   359,   363,     0,   140,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      36,    38,     0,     0,     0,     0,     0,     0,     0,    74,
       0,     0,     0,   105,     0,     0,     0,     0,   101,   146,
     147,   149,   150,   151,   153,   154,   156,   157,   161,   162,
     159,   160,   164,   165,   167,   169,   171,   173,   175,     0,
     180,   492,   484,     0,   486,     0,     0,   374,   377,   378,
      66,     0,   499,    60,   431,   429,     0,   220,     0,   221,
      26,     0,    26,     0,     0,     0,     0,     0,     0,     0,
      26,   207,   206,   209,     0,   325,   326,   403,   390,   404,
     405,   400,   399,   389,   410,     0,     0,     0,     0,   411,
       0,     0,     0,     0,   289,   291,   302,     0,   311,   306,
     330,   329,   357,   367,     0,     0,   365,     0,     0,    36,
      91,    92,     0,   141,    96,     0,    97,    94,    95,   132,
       0,    26,   128,    37,     0,   133,    39,   135,    38,     0,
      93,   121,     0,   112,   113,   194,   144,   104,     0,   103,
      90,    89,   100,     0,    99,     0,     0,     0,     0,   481,
     479,    67,     0,     0,   500,    61,   430,    26,   205,     0,
     218,    30,   219,   223,   213,     0,     0,   222,     0,   498,
       0,   203,    48,   324,   409,     0,   416,     0,     0,   408,
       0,     0,     0,   420,   286,   355,   356,   142,     0,   129,
       0,     0,    36,     0,     0,     0,   134,     0,     0,   102,
      98,   177,   485,     0,   487,   379,   376,   505,    52,     0,
     204,     0,     0,    31,    26,     0,    26,    26,     0,   508,
      49,   415,     0,   414,   419,     0,   418,   353,   354,    36,
       0,     0,   130,   138,   136,     0,     0,     0,     0,   502,
     503,     0,     0,    26,   210,     0,   212,   215,   507,     0,
     413,   417,   352,   131,   111,   108,   137,   110,   109,   488,
     501,     0,     0,    26,   214,   509,     0,   216,    26,   211,
     489,   217
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -697,  -697,  -150,   849,   695,  -697,  -171,   258,  -697,  -697,
    -697,  -697,    21,  -697,  -697,    29,  -697,  -382,   284,  -697,
    -697,   466,  -696,   133,  -495,  -697,  -169,  -697,  -697,  -191,
    -697,  -143,  -697,  -350,  -697,   661,  -697,  -697,  -697,  -697,
    -697,  1083,   759,  -192,     0,  -697,   622,  -697,  -697,  -697,
     298,  -697,  -697,  -697,  -697,  -202,   -37,    67,    69,  -120,
      75,   428,   419,   435,   439,   424,  -179,  -155,  -506,  -148,
    -697,   416,    13,  -697,   237,  -193,  -697,  -697,  -538,  -697,
    -697,  -697,  -697,  -697,   -25,    12,   243,   -65,   486,  -697,
    -697,   195,  -697,   149,  -697,  -697,  -697,   346,  -697,  -697,
    -697,  -697,  -697,  -697,   294,  -697,  -697,  -183,  -697,  -697,
    -697,  -697,   604,   -40,  -697,  -152,  -170,   -45,   756,  -210,
     -14,  -404,  -697,  -697,  -697,  -252,  -182,   144,  -697,  -502,
    -697,  -697,  -697,  -697,  -697,  -697,   566,   369,  -697,  -697,
     554,  -697,   227,  -314,  -697,  -697,  -697,  -697,   421,  -697,
    -697,  -697,  -697,  -180,   277,   281,  -697,  -697,   355,   444,
    -697,  -697,  -697,  -167,  -553,  -697,  -697,  -697,  -660,  -697
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    48,    49,    50,   107,    52,    53,    54,   291,   292,
     293,   294,   295,   296,    55,   217,   537,   538,   355,   832,
     450,   443,   742,   745,   101,   331,   196,   227,   838,   603,
     421,   253,   388,   366,   774,   230,    57,   772,   164,   564,
     297,   298,    59,    60,   356,   300,   301,   302,   303,   444,
     620,   746,   747,   743,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   359,   453,
     497,   539,   540,   541,   542,   543,   544,   545,   785,   546,
     781,   547,   548,    62,    63,   549,    65,    66,   550,    68,
      69,    70,    71,    72,    73,    74,   389,   390,   391,    75,
      76,    77,    78,    79,   218,    80,   398,    81,    82,    83,
      84,   191,   192,    85,    86,    87,   174,    88,    89,   319,
     320,   424,   425,   255,   256,   257,    90,   345,   333,   515,
     670,    91,    92,    93,   372,   373,   374,   375,   561,   562,
     381,   574,   575,   376,    94,   159,   233,   197,   340,   341,
     342,    95,   160,    96,   507,   508,   509,    97,   321,   322,
      98,    99,   551,   198,   672,   673,   829,   323,   696,   840
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      61,   175,   190,   344,   172,   246,   232,   103,   290,   162,
     367,   669,    64,   326,   158,   598,   239,   109,   678,   369,
     371,   357,   377,   565,   332,   335,   334,   193,   156,    56,
       1,   318,   177,   809,    61,   793,     3,   187,   384,   168,
     494,   111,     1,     1,   171,   358,    64,   201,   697,   206,
     609,   610,    15,   105,   700,   613,   346,   615,   616,   617,
     430,   431,    61,   420,   623,   436,   576,    61,     1,    15,
     396,   194,   506,   455,    64,   715,   707,   220,   221,   634,
     232,   713,   501,   456,   457,   176,   216,   171,   408,   329,
     411,   502,   465,   205,   598,   110,   426,   428,   176,   694,
     464,   628,   423,   195,     3,     4,   212,     6,   330,   711,
      42,    61,    61,   466,     1,   222,   852,   429,    28,    28,
     775,   765,   628,    64,    64,   163,   210,    42,   761,   499,
     175,   178,   451,   182,   182,   789,   163,   495,   175,   344,
     676,   467,   344,   228,    28,   848,   468,   469,   416,   788,
     686,   790,   194,   873,    45,    45,   104,   156,   231,   176,
     112,   183,   370,   175,   235,   237,   240,   242,   500,   244,
       2,   179,     4,     5,     6,   605,   247,   250,   156,   299,
      45,   367,   514,   410,   195,   560,   -44,   872,   180,   190,
     369,   371,   181,   377,   427,   339,   591,   478,   665,   156,
     479,   712,    61,   379,   206,   199,   383,   666,   200,   404,
     186,   795,   202,   798,   422,    61,   800,   802,   703,    61,
     397,    61,   600,   157,   611,   601,   607,    64,   614,   402,
     628,    64,   231,    64,    61,   622,   854,   624,   409,   625,
     213,   412,   627,   833,   392,   584,    64,   586,   415,     1,
     207,     1,   209,   501,    61,     3,     4,   708,     6,   592,
     631,   222,   804,   639,   640,     3,     4,   423,     6,   825,
     229,   423,   219,   596,   597,   108,   -53,   665,   194,   -53,
     474,   475,     1,   299,   223,   114,   823,   511,     3,     4,
     224,     6,   329,   169,     3,     4,   225,     6,   628,   229,
     226,   629,   842,   190,   628,   186,   845,   667,     1,   855,
     195,   330,   -44,     2,     3,     4,     5,     6,   104,   628,
     231,   234,   739,   628,   156,    28,   753,   171,   558,   628,
     290,   245,   874,   370,     3,     4,   519,     6,   324,   238,
     632,   688,   195,   299,   628,   357,   500,   875,   500,   660,
     385,   204,   157,   318,   648,   649,   650,   651,    28,   813,
       4,    45,     6,   168,   211,   514,   380,   214,    61,   358,
     476,   477,   744,    61,   157,   357,   367,    46,    47,   172,
     573,   357,   695,   201,    28,   369,   371,   628,   377,   332,
     877,   334,    44,   209,    45,   585,   576,   104,   498,   358,
      46,    47,   357,   327,   328,   358,    46,    47,   343,   740,
     733,   506,   628,   506,   393,   878,   156,   156,   290,   171,
      45,   400,   357,   171,   860,   401,   358,   156,   756,   621,
     641,   642,   643,     1,   156,   716,   470,   471,   156,     3,
       4,   318,     6,   156,   169,   156,   358,   299,   186,   156,
     183,   723,   299,   338,   726,     3,     4,   724,     6,     1,
     365,   378,     3,   382,   628,     3,     4,   881,     6,   748,
     386,   387,     3,     4,   406,     6,   516,   229,   157,   517,
     755,   882,   472,   414,   473,   190,    67,     1,     3,     4,
     417,     6,     2,   405,     4,     5,     6,     1,   231,   418,
     231,   299,   428,     3,     4,     1,     6,   175,   169,    28,
     511,     3,     4,   394,     6,   399,   106,   432,   808,   433,
      67,   339,   429,   566,   567,   807,   701,   299,   370,   566,
     698,     3,     4,   434,     6,   437,   570,   644,   645,   438,
     681,   646,   647,   419,   299,    45,   -52,   439,    67,   440,
      61,    46,    47,   652,   653,   441,   822,   693,   824,   445,
     442,   446,   449,    28,   209,   452,   171,   480,    61,   481,
     705,   222,   483,    28,     1,   521,   222,   553,   182,   482,
       3,     4,   839,     6,    46,    47,   522,   556,   552,   299,
       3,     4,   554,     6,   621,   165,   748,    67,    67,    45,
     156,   536,   360,   361,   362,   183,   555,   419,   156,    45,
     563,   568,   578,   581,   580,    46,    47,   821,   587,   156,
     208,   231,   579,   514,   582,   583,   365,   588,   571,   157,
     589,   365,   590,   157,   612,   847,   357,   569,   157,   593,
     157,   770,   157,   595,   157,   599,     1,   157,   602,   630,
      28,     2,   663,     4,     5,     6,   166,   671,   677,   885,
     358,   679,   691,   156,   254,   156,    61,   680,   880,   682,
     786,   684,   687,   786,   689,   786,   423,   692,    64,   690,
     299,   628,   299,   167,   299,   254,    45,   299,   368,   299,
     299,   710,   720,   778,   718,    51,   157,   719,   721,   454,
     722,    67,   100,   791,   727,    67,   222,    67,   222,   730,
     573,   222,   222,     3,     4,   890,     6,   884,   241,   731,
      67,   732,    28,   100,   734,   736,   735,   737,   156,    51,
     738,   741,   766,   458,   459,   749,   460,   182,   750,   170,
     173,   751,     1,   752,   754,   512,   835,     2,   231,     4,
       5,     6,   760,   768,   773,   771,   184,    51,    45,   828,
     175,   662,    51,   664,   208,     1,   156,   786,   156,   776,
     777,     3,     4,   156,     6,   779,   636,   299,   783,   338,
     220,   299,   170,   787,   157,   536,   171,   683,   859,   685,
     830,   792,   156,   694,   560,   805,   184,   222,   184,   806,
     810,   222,   536,   157,   811,   815,    51,    51,     3,     4,
     254,     6,   461,   229,   157,   462,     1,   463,    28,   812,
     185,   817,     3,     4,   365,     6,   365,   248,   171,   818,
     831,   826,   834,   182,   299,   836,   299,   299,   387,     3,
       4,    28,     6,   837,   165,   849,   853,   864,   861,   866,
     867,   184,   100,   858,    45,   863,   637,   865,   618,   368,
     868,   869,   185,   454,   100,   876,   883,   886,   626,   156,
     887,   888,   249,   100,   100,     6,   113,    45,   635,   157,
       1,   816,   157,   299,   157,   725,     3,     4,   299,     6,
     337,   169,    28,   403,   100,   608,   889,    51,     1,   448,
     655,   891,   254,   254,     3,     4,   729,     6,   654,   758,
      51,   659,   498,   254,    51,   -52,    51,   656,   658,   780,
      46,    47,   657,   157,   236,   782,   714,   243,    45,    51,
     185,   510,   167,   251,   559,   702,   577,   799,   536,   184,
     767,   325,   675,   100,   717,   661,   769,     0,   536,    51,
       0,     0,     0,     1,     0,     0,    28,     0,     0,     3,
       4,   157,     6,   157,   763,     0,     1,     0,   157,     0,
       0,     0,     3,     4,    28,     6,   157,   203,   100,   173,
       3,     4,     0,     6,     0,   706,     0,   157,     0,     0,
     419,  -504,    45,     0,   184,     0,   407,     0,    46,    47,
       0,   413,     0,   185,     0,     1,     0,     0,     0,   185,
      45,     3,     4,     0,     6,     0,   336,     0,     0,   100,
       3,     4,   170,     6,     0,   395,     0,     3,     4,    28,
       6,   518,   797,     0,   520,   536,     0,     0,   100,   484,
     485,   486,   487,   488,   489,   490,   491,     0,   492,     0,
     493,   360,   361,   362,   368,     0,   494,     0,   185,     0,
       0,     0,     0,    51,   157,    45,     3,     4,    51,     6,
       0,   801,     0,     0,     0,   572,     0,     0,     0,     0,
       0,     0,     0,    58,     0,     0,   254,     0,     0,     0,
     102,     0,   536,     0,   536,   536,     0,     0,     0,     0,
     784,     0,     0,   784,     0,   784,     0,     0,     0,     0,
     184,   100,   100,     0,   170,   185,   879,    58,   170,     0,
       0,     0,   100,     0,     0,     0,     0,    58,     0,   100,
       0,     0,     0,   100,     0,     0,     0,     0,   100,     0,
     100,   536,   100,     0,   100,    58,   536,   100,     0,   254,
      58,   254,    67,   495,     0,   496,     0,     0,     0,     0,
     814,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      58,   594,     0,     0,   185,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    58,    58,   100,   784,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   674,     0,   337,     0,     0,     0,
       0,     0,   100,     0,     0,     0,   850,   851,     0,     0,
       0,     0,     0,   856,   857,     0,     0,     0,     0,   100,
       0,     0,     0,     0,     0,    51,     0,   862,     0,     0,
       0,     0,   102,     0,     0,     0,     0,     0,     0,     0,
      58,   170,     0,    51,     0,   704,     0,     0,   709,     0,
       0,     2,     3,     4,     5,     6,     0,   115,     0,     0,
       0,     0,     0,     0,   100,    58,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   100,     0,     0,    58,     0,
       0,     0,    58,   100,    58,    10,     0,     0,     0,    11,
      12,    13,    14,    15,   100,     0,     0,    58,     0,     0,
       0,    16,     0,     0,    17,     0,     0,     0,     0,    21,
       0,   102,     0,     0,     0,    24,    25,    58,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    30,
      31,     0,     0,     0,     0,    33,     0,     0,   100,     0,
     100,    51,     0,     0,     0,    36,    37,    38,     0,     0,
      41,    42,    43,     0,     0,   100,   619,   100,     0,   100,
       0,     0,   100,     0,   100,   100,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     794,     0,   796,     0,     0,   572,     0,     0,   803,     0,
      58,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   100,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    58,     0,     0,     0,     0,    58,     0,     0,     0,
       0,   100,     0,   100,     0,     0,     0,     0,   100,     0,
       0,     0,   100,     0,     0,     0,   100,     0,     0,     0,
       0,   170,     0,     0,     0,     0,     0,   100,     0,     0,
     841,     0,     0,   843,     0,   844,     0,   846,     0,     0,
       0,     0,    58,     0,     0,     0,    58,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   170,     0,     0,     0,     0,     0,   100,
       0,   100,   100,     0,     0,     0,     0,   870,     0,     0,
     871,     0,     0,   633,     0,     0,   638,     0,     0,     1,
     258,   259,   260,   110,     0,     3,     4,     0,     6,     0,
     347,     0,     0,     0,   100,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   100,     0,
     262,   263,     0,   100,     0,     0,     0,     0,   348,     0,
       0,     0,   349,     0,     0,     0,     0,   266,     0,     0,
       0,     0,   267,     0,   350,   269,     0,     0,     0,     0,
       0,   270,   351,     0,     0,     0,     0,     0,   352,   353,
       0,     0,   274,     0,     0,    28,     0,     0,     0,     0,
     275,     0,   354,    58,   277,     0,     0,   278,     0,     0,
       0,   279,     0,     0,   281,     0,     0,   282,     0,    58,
       0,    58,     0,     0,     0,     0,     0,     0,     0,   283,
       0,   284,     0,     0,     0,     0,     0,   285,   286,   287,
     288,   289,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   699,     0,     0,     0,     1,   258,   259,   260,   110,
       0,     3,     4,     0,     6,     0,   347,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   757,   759,   262,   263,     0,   762,
     764,     0,     0,     0,   348,     0,     0,     0,   349,     0,
       0,     0,     0,   266,     0,     0,     0,     0,   267,     0,
     350,   269,     0,     0,     0,     0,     0,   270,   351,    58,
       0,     0,     0,     0,   352,   353,     0,     0,   274,     0,
       0,    28,     0,     0,     0,     0,   275,     0,   354,     0,
     277,     0,     0,   278,     0,     0,     0,   279,     0,   280,
     281,     0,     0,   282,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   283,     0,   284,     0,     0,
       0,     0,     0,   285,   286,   287,   288,   289,     0,     0,
       0,     0,     0,     0,     0,   513,   668,     0,     1,   258,
     259,   260,   110,     2,     3,     4,     5,     6,     0,   261,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   819,     0,     0,     0,     0,   820,     0,     0,   262,
     263,     0,     0,     0,     0,     8,     9,   264,   523,   524,
       0,   265,    12,    13,    14,    15,   266,     0,   525,    58,
     526,   267,   527,   268,   269,     0,    17,    18,     0,   188,
     270,   271,   528,    22,   529,   530,    23,   272,   273,    26,
     531,   274,     0,     0,    28,     0,     0,     0,    29,   275,
     532,   276,    31,   277,    32,     0,   278,    33,   533,     0,
     279,    58,   280,   281,   534,    35,   282,    36,    37,    38,
      39,    40,    41,    42,    43,   535,     0,   -26,   283,     0,
     284,     0,     0,     0,     0,     0,   285,   286,   287,   288,
     289,     0,     0,     0,     0,     0,     0,     0,   343,     1,
     258,   259,   260,   110,     2,     3,     4,     5,     6,     0,
     261,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     262,   263,     0,     0,     0,     0,     8,     9,   264,   523,
     524,     0,   265,    12,    13,    14,    15,   266,     0,   525,
       0,   526,   267,   527,   268,   269,     0,    17,    18,     0,
     188,   270,   271,   528,    22,   529,   530,    23,   272,   273,
      26,   531,   274,     0,     0,    28,     0,     0,     0,    29,
     275,   532,   276,    31,   277,    32,     0,   278,    33,   533,
       0,   279,     0,   280,   281,   534,    35,   282,    36,    37,
      38,    39,    40,    41,    42,    43,   535,     0,     0,   283,
       0,   284,     0,     0,     0,     0,     0,   285,   286,   287,
     288,   289,     0,     0,     0,     1,     0,     0,     0,   343,
       2,     3,     4,     5,     6,     0,     7,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     8,     9,    10,     0,     0,     0,    11,    12,
      13,    14,    15,     0,     0,     0,     0,     0,     0,     0,
      16,     0,     0,    17,    18,    19,    20,     0,    21,     0,
      22,     0,     0,    23,    24,    25,    26,    27,     0,     0,
       0,    28,     0,     0,     0,    29,     0,     0,    30,    31,
       0,    32,     0,     0,    33,     0,    34,     0,     0,     0,
       0,     0,    35,     0,    36,    37,    38,    39,    40,    41,
      42,    43,     0,     0,     0,    44,     0,    45,     0,     0,
       0,     0,     0,    46,    47,     1,   258,   259,   260,   110,
       0,     3,     4,     0,     6,   215,   347,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   262,   263,     0,     0,
       0,     0,     0,     0,   348,     0,     0,     0,   349,     0,
       0,     0,     0,   266,     0,     0,     0,     0,   267,     0,
     350,   269,     0,     0,     0,     0,     0,   270,   351,     0,
       0,     0,     0,     0,   352,   353,     0,     0,   274,     0,
       0,    28,     0,     0,     0,     0,   275,     0,   354,     0,
     277,     0,     0,   278,     0,     0,     0,   279,     0,   280,
     281,     0,     0,   282,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   283,     0,   284,     0,     0,
       0,     0,     0,   285,   286,   287,   288,   289,     2,     3,
       4,     5,     6,     0,   115,   513,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,     0,     0,
       0,     0,    10,     0,     0,     0,    11,    12,    13,    14,
      15,     0,     0,     0,     0,     0,   138,     0,    16,     0,
       0,    17,     0,     0,     0,     0,    21,     0,     0,     0,
       0,     0,    24,    25,     0,     0,   139,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    30,    31,     0,     0,
       0,     0,    33,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    36,    37,    38,     0,     0,    41,    42,    43,
       0,   140,     0,   141,     0,   142,   143,     0,     0,   144,
     145,   146,   147,   148,     0,   149,   150,   151,   152,   153,
       0,     0,   154,     0,     0,     0,   155,     1,   258,   259,
     260,   110,     2,     3,     4,     5,     6,     0,   261,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   262,   263,
       0,     0,     0,     0,     0,     9,   264,     0,     0,     0,
     265,    12,    13,    14,    15,   266,     0,     0,     0,     0,
     267,     0,   268,   269,     0,    17,    18,     0,   188,   270,
     271,     0,    22,     0,     0,    23,   272,   273,    26,     0,
     274,     0,     0,    28,     0,     0,     0,    29,   275,     0,
     276,    31,   277,    32,     0,   278,    33,     0,     0,   279,
       0,   280,   281,     0,    35,   282,    36,    37,    38,     0,
      40,    41,    42,    43,     0,     0,     0,   283,     0,   284,
       0,     0,     0,     0,     0,   285,   286,   287,   288,   289,
       1,   258,   259,   260,   110,     2,     3,     4,     5,     6,
       0,   261,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   262,   263,     0,     0,     0,     0,     0,     0,   264,
       0,     0,     0,   265,    12,    13,    14,    15,   266,     0,
       0,     0,     0,   267,     0,   268,   269,     0,    17,     0,
       0,     0,   270,   271,     0,     0,     0,     0,     0,   272,
     273,     0,     0,   274,     0,     0,    28,     0,     0,     0,
       0,   275,     0,   276,    31,   277,     0,     0,   278,    33,
       0,     0,   279,     0,   280,   281,     0,     0,   282,    36,
      37,    38,     0,     0,    41,    42,    43,     0,     0,     0,
     283,     0,   284,     0,     0,     0,     0,     0,   285,   286,
     287,   288,   289,     1,   258,   259,   260,   110,     0,     3,
       4,     0,     6,     0,   347,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   262,   263,     0,     0,     0,     0,
       0,     0,   348,     0,     0,     0,   349,     0,     0,     0,
       0,   266,     0,     0,     0,     0,   267,     0,   350,   269,
       0,     0,     0,     0,     0,   270,   351,     0,     0,     0,
       0,     0,   352,   353,     0,     0,   274,     0,     0,    28,
       0,     0,     0,     0,   275,     0,   354,     0,   277,     0,
       0,   278,     0,     0,     0,   279,     0,     0,   281,     0,
       0,   282,     0,     1,   258,   259,   260,   110,     0,     3,
       4,     0,     6,   283,   347,   284,   435,     0,     0,     0,
       0,   285,   286,   287,   288,   289,     0,     0,     0,     0,
       0,     0,     0,     0,   262,   263,     0,     0,     0,     0,
       0,     0,   348,     0,     0,     0,   349,     0,     0,     0,
       0,   266,     0,     0,     0,     0,   267,     0,   350,   269,
       0,     0,     0,     0,     0,   270,   351,     0,     0,     0,
       0,     0,   352,   353,     0,     0,   274,     0,     0,    28,
       0,     0,     0,     0,   275,     0,   354,     0,   277,     0,
       0,   278,     0,     0,     0,   279,     0,   280,   281,     0,
       0,   282,     0,     1,   258,   259,   260,   110,     0,     3,
       4,     0,     6,   283,   347,   284,     0,     0,     0,     0,
       0,   285,   286,   287,   288,   289,     0,     0,     0,     0,
       0,     0,     0,     0,   262,   263,     0,     0,     0,     0,
       0,     0,   348,     0,     0,     0,   349,     0,     0,     0,
       0,   266,     0,     0,     0,     0,   267,     0,   350,   269,
       0,     0,     0,     0,     0,   270,   351,     0,     0,     0,
       0,     0,   352,   353,     0,     0,   274,     0,     0,    28,
       0,     0,     0,     0,   275,     0,   354,     0,   277,     0,
       0,   278,     0,     0,     0,   279,     0,     0,   281,     0,
       0,   282,     0,     1,   258,   259,   260,   110,     0,     3,
       4,     0,     6,   283,   347,   284,   606,     0,     0,     0,
       0,   285,   286,   287,   288,   289,     0,     0,     0,     0,
       0,     0,     0,     0,   262,   263,     0,     0,     0,     0,
       0,     0,   348,     0,     0,     0,   349,     0,     0,     0,
       0,   266,     0,     0,     0,     0,   267,     0,   350,   269,
       0,     0,     0,     0,     0,   270,   351,     0,     0,     0,
       0,     0,   352,   353,     0,     0,   274,     0,     0,    28,
       0,     0,     0,     0,   275,     0,   354,     0,   277,     0,
       0,   278,     0,     0,     0,   279,     0,     0,   281,     0,
       0,   282,     0,     1,   258,   259,   260,   110,     0,     3,
       4,     0,     6,   283,   347,   284,     0,     0,     0,     0,
       0,   285,   286,   287,   288,   289,     0,     0,     0,     0,
       0,     0,     0,     0,   262,   263,     0,     0,     0,     0,
       0,     0,   348,     0,     0,     0,   349,     0,     0,     0,
       0,   266,     0,     0,     0,     0,   267,     0,   350,   269,
       0,     0,     0,     0,     0,   270,   351,     0,     0,     0,
       0,     0,   352,   353,     0,     0,   274,     0,     0,    28,
       0,     0,     0,     0,   275,     0,   354,     0,   277,     0,
       0,   278,     0,     0,     0,   279,     0,     1,   281,     0,
       0,   282,     2,     3,     4,     5,     6,     0,     7,     0,
       0,     0,     0,   447,     0,   284,     0,     0,     0,     0,
       0,   285,   286,   287,   288,   289,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     9,    10,     0,     0,     0,
      11,    12,    13,    14,    15,     0,     0,     0,     0,     0,
       0,     0,    16,     0,     0,    17,    18,    19,   188,     0,
      21,     0,    22,     0,     0,    23,    24,    25,    26,     0,
       0,     0,     0,    28,   360,   361,   362,    29,     0,     0,
      30,    31,     0,    32,     1,     0,    33,     0,   -64,     2,
       3,     4,     5,     6,    35,     7,    36,    37,    38,   363,
      40,    41,    42,    43,     0,     0,   364,    44,     0,    45,
       0,     0,     0,     0,     0,    46,    47,     0,     0,     0,
       0,     8,     9,    10,     0,     0,     0,    11,    12,    13,
      14,    15,     0,     0,     0,     0,     0,     0,     0,    16,
       0,     0,    17,    18,    19,    20,     0,    21,     0,    22,
       0,     0,    23,    24,    25,    26,    27,     0,     0,     0,
      28,     0,     0,     0,    29,     0,     0,    30,    31,     0,
      32,     1,     0,    33,     0,    34,     2,     3,     4,     5,
       6,    35,     7,    36,    37,    38,    39,    40,    41,    42,
      43,     0,     0,     0,    44,     0,    45,     0,     0,     0,
     161,     0,    46,    47,     0,     0,     0,     0,     8,     9,
      10,     0,     0,     0,    11,    12,    13,    14,    15,     0,
       0,     0,     0,     0,     0,     0,    16,     0,     0,    17,
      18,    19,    20,     0,    21,     0,    22,     0,     0,    23,
      24,    25,    26,    27,     0,     0,     0,    28,     0,     0,
       0,    29,     0,     0,    30,    31,     0,    32,     1,     0,
      33,     0,    34,     2,     3,     4,     5,     6,    35,     7,
      36,    37,    38,    39,    40,    41,    42,    43,     0,     0,
       0,    44,     0,    45,     0,     0,     0,     0,     0,    46,
      47,     0,     0,     0,     0,     0,     9,    10,     0,     0,
       0,    11,    12,    13,    14,    15,     0,     0,     0,     0,
       0,     0,     0,    16,     0,     0,    17,    18,     0,   188,
       0,    21,     0,    22,     0,     0,    23,    24,    25,    26,
       0,     0,     0,     0,    28,     0,     0,     0,    29,     0,
       0,    30,    31,     1,    32,     0,     0,    33,     2,     3,
       4,     5,     6,     0,     7,    35,     0,    36,    37,    38,
       0,    40,    41,    42,    43,     0,     0,   189,    44,     0,
      45,     0,     0,     0,     0,     0,    46,    47,     0,     0,
       0,     9,    10,     0,     0,     0,    11,    12,    13,    14,
      15,     0,     0,     0,     0,     0,     0,     0,    16,     0,
       0,    17,    18,     0,   188,     0,    21,     0,    22,     0,
       0,    23,    24,    25,    26,     0,     0,     0,     0,    28,
       0,     0,     0,    29,     0,     0,    30,    31,     1,    32,
       0,     0,    33,     2,     3,     4,     5,     6,     0,     7,
      35,     0,    36,    37,    38,     0,    40,    41,    42,    43,
       0,     0,     0,   419,     0,    45,   -52,     0,     0,     0,
       0,    46,    47,     0,     0,     0,     9,    10,     0,     0,
       0,    11,    12,    13,    14,    15,     0,     0,     0,     0,
       0,     0,     0,    16,     0,     0,    17,    18,     0,   188,
       0,    21,     0,    22,     0,     0,    23,    24,    25,    26,
       0,     0,     0,     0,    28,     0,     0,     0,    29,     0,
       0,    30,    31,     0,    32,     0,     0,    33,     2,     3,
       4,     5,     6,     0,   115,    35,     0,    36,    37,    38,
       0,    40,    41,    42,    43,     0,     0,   557,    44,     0,
      45,     0,     0,     0,     0,     0,    46,    47,     0,     0,
       0,     0,    10,     0,     0,     0,    11,    12,    13,    14,
      15,     0,     0,     0,     0,     0,     0,     0,    16,     0,
       0,    17,     0,     0,     0,     0,    21,     0,     0,     0,
       0,     0,    24,    25,     0,     0,     0,     2,     3,     4,
       5,     6,   252,   115,     0,     0,    30,    31,     0,     0,
       0,     0,    33,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    36,    37,    38,     0,     0,    41,    42,    43,
       9,    10,     0,   728,     0,    11,    12,    13,    14,    15,
       0,     0,     0,     0,     0,     0,     0,    16,     0,     0,
      17,    18,     0,   188,     0,    21,     0,    22,     0,     0,
      23,    24,    25,    26,     0,     0,     0,     2,     3,     4,
       5,     6,    29,   115,     0,    30,    31,     0,    32,     0,
       0,    33,     0,     0,     0,     0,     0,     0,     0,    35,
       0,    36,    37,    38,     0,    40,    41,    42,    43,     0,
       9,    10,     0,     0,     0,    11,    12,    13,   503,    15,
       0,     0,     0,     0,     0,     0,     0,    16,     0,     0,
      17,    18,     0,   188,     0,    21,     0,    22,     0,     0,
      23,    24,    25,    26,     0,     0,     0,     0,     0,     0,
       0,     0,    29,     0,     0,    30,    31,     0,    32,     0,
       0,    33,     0,   504,     0,     0,     0,     0,     0,    35,
       0,   505,    37,    38,     0,    40,    41,    42,    43,     2,
       3,     4,     5,     6,   604,   115,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     9,    10,     0,     0,     0,    11,    12,    13,
      14,    15,     0,     0,     0,     0,     0,     0,     0,    16,
       0,     0,    17,    18,     0,   188,     0,    21,     0,    22,
       0,     0,    23,    24,    25,    26,     0,     2,     3,     4,
       5,     6,   827,   115,    29,     0,     0,    30,    31,     0,
      32,     0,     0,    33,     0,     0,     0,     0,     0,     0,
       0,    35,     0,    36,    37,    38,     0,    40,    41,    42,
      43,    10,     0,     0,     0,    11,    12,    13,    14,    15,
       0,     0,     0,     0,     0,     0,     0,    16,     0,     0,
      17,     0,     0,     0,     0,    21,     0,     0,     0,     0,
       0,    24,    25,     0,     0,     2,     3,     4,     5,     6,
       0,   115,     0,     0,     0,    30,    31,     0,     0,     0,
       0,    33,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    36,    37,    38,     0,     0,    41,    42,    43,    10,
       0,     0,     0,    11,    12,    13,    14,    15,     0,     0,
       0,     0,     0,     0,     0,    16,     0,     0,    17,     0,
       0,     0,     0,    21,     0,     0,     0,     0,     0,    24,
      25,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    30,    31,     0,     0,     0,     0,    33,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    36,
      37,    38,     0,     0,    41,    42,    43
};

static const yytype_int16 yycheck[] =
{
       0,    46,    67,   196,    44,   175,   158,     7,   179,    34,
     202,   513,     0,   183,    28,   419,   166,    17,   524,   202,
     202,   200,   202,   373,   193,   194,   193,    67,    28,     0,
       3,   179,    14,   729,    34,   695,     9,    62,   208,    39,
      33,    20,     3,     3,    44,   200,    34,    87,   554,    14,
     432,   433,    50,   113,   560,   437,   199,   439,   440,   441,
     262,   263,    62,   254,   446,   267,   380,    67,     3,    50,
     220,    99,   324,   283,    62,   581,   571,   132,   133,   461,
     232,   576,   111,   285,   286,    14,   111,    87,   238,   113,
     240,   120,    15,    93,   498,     7,    13,    56,    14,    97,
     302,   111,   254,   131,     9,    10,   106,    12,   132,    14,
     108,   111,   112,    36,     3,   115,   812,    76,    79,    79,
     673,   131,   111,   111,   112,    14,   105,   108,   117,   320,
     175,   113,   280,    94,    94,   688,    14,   130,   183,   332,
     522,   121,   335,   157,    79,   805,   126,   127,   113,   687,
     532,   689,    99,   849,   115,   115,     7,   157,   158,    14,
     133,   121,   202,   208,   164,   165,   166,   167,   320,   169,
       8,   119,    10,    11,    12,   427,   176,   177,   178,   179,
     115,   373,   330,   112,   131,   132,   133,   847,     0,   254,
     373,   373,    94,   373,   111,   195,   112,    28,   111,   199,
      31,   106,   202,   203,    14,   113,   206,   120,   116,   234,
      61,   706,   133,   708,   254,   215,   711,   712,   568,   219,
     220,   221,   113,    28,   434,   116,   428,   215,   438,   229,
     111,   219,   232,   221,   234,   445,   117,   447,   238,   449,
     133,   241,   452,   781,   215,   395,   234,   397,   248,     3,
     101,     3,   103,   111,   254,     9,    10,   571,    12,   409,
      14,   261,   120,   465,   466,     9,    10,   419,    12,   771,
      14,   423,   133,   416,   417,    17,   113,   111,    99,   116,
      29,    30,     3,   283,   116,    27,   120,   327,     9,    10,
     116,    12,   113,    14,     9,    10,   114,    12,   111,    14,
     117,   114,   797,   368,   111,   156,   801,   114,     3,   815,
     131,   132,   133,     8,     9,    10,    11,    12,   169,   111,
     320,   120,   114,   111,   324,    79,   114,   327,   368,   111,
     501,   114,   114,   373,     9,    10,   336,    12,   119,    14,
      94,   534,   131,   343,   111,   524,   498,   114,   500,   497,
     114,    93,   157,   501,   474,   475,   476,   477,    79,   741,
      10,   115,    12,   363,   106,   513,   131,   109,   368,   524,
     119,   120,   116,   373,   179,   554,   568,   121,   122,   419,
     380,   560,   552,   423,    79,   568,   568,   111,   568,   558,
     114,   558,   113,   244,   115,   395,   710,   248,   113,   554,
     121,   122,   581,   111,   112,   560,   121,   122,   133,   619,
     612,   663,   111,   665,   134,   114,   416,   417,   589,   419,
     115,   117,   601,   423,   828,   117,   581,   427,   630,   443,
     467,   468,   469,     3,   434,   585,   123,   124,   438,     9,
      10,   589,    12,   443,    14,   445,   601,   447,   299,   449,
     121,   599,   452,   195,   602,     9,    10,   600,    12,     3,
     202,   203,     9,   205,   111,     9,    10,   114,    12,   621,
     212,   213,     9,    10,   112,    12,   332,    14,   283,   335,
     628,   863,    24,   112,    26,   550,     0,     3,     9,    10,
     113,    12,     8,   235,    10,    11,    12,     3,   498,   114,
     500,   501,    56,     9,    10,     3,    12,   552,    14,    79,
     550,     9,    10,   219,    12,   221,    14,   113,   728,   113,
      34,   521,    76,   111,   112,   727,   566,   527,   568,   111,
     112,     9,    10,   119,    12,   113,    14,   470,   471,   119,
     527,   472,   473,   113,   544,   115,   116,   113,    62,   113,
     550,   121,   122,   478,   479,   113,   766,   544,   768,   119,
     113,   113,   119,    79,   415,   113,   566,   122,   568,   128,
     570,   571,    32,    79,     3,   111,   576,   117,    94,   129,
       9,    10,   792,    12,   121,   122,   113,   112,   114,   589,
       9,    10,   131,    12,   608,    14,   748,   111,   112,   115,
     600,   343,    80,    81,    82,   121,   134,   113,   608,   115,
     112,   131,   112,   132,   111,   121,   122,   765,   112,   619,
     121,   621,   134,   771,   134,   134,   368,   134,   106,   434,
     119,   373,   112,   438,   117,   805,   815,   379,   443,   112,
     445,   666,   447,   112,   449,   132,     3,   452,   132,   114,
      79,     8,   119,    10,    11,    12,    75,    45,   112,   869,
     815,   112,   134,   663,   178,   665,   666,   131,   861,   113,
     684,   113,   113,   687,   113,   689,   828,   112,   666,   131,
     680,   111,   682,   102,   684,   199,   115,   687,   202,   689,
     690,   111,   114,   680,   112,     0,   501,   112,   114,   283,
     114,   215,     7,   690,   117,   219,   706,   221,   708,   114,
     710,   711,   712,     9,    10,   886,    12,   865,    14,   114,
     234,   120,    79,    28,   114,   114,   120,   114,   728,    34,
     114,   113,   132,    34,    35,   120,    37,    94,   114,    44,
      45,   114,     3,   120,   114,   329,   786,     8,   748,    10,
      11,    12,   114,   132,   113,   111,    61,    62,   115,   773,
     805,   503,    67,   505,   121,     3,   766,   781,   768,   114,
     131,     9,    10,   773,    12,   110,    14,   777,   112,   521,
     132,   781,    87,   112,   589,   527,   786,   529,   828,   531,
     777,   113,   792,    97,   132,   114,   101,   797,   103,   117,
     113,   801,   544,   608,   113,   116,   111,   112,     9,    10,
     324,    12,   113,    14,   619,   116,     3,   118,    79,   114,
      61,   113,     9,    10,   566,    12,   568,    14,   828,   113,
     113,   134,   114,    94,   834,   114,   836,   837,   580,     9,
      10,    79,    12,   114,    14,   114,   114,   834,   114,   836,
     837,   156,   157,    49,   115,   112,    94,   132,   442,   373,
     114,   111,   103,   447,   169,   117,    60,   132,   452,   869,
     112,   114,   177,   178,   179,    12,    27,   115,   462,   684,
       3,   748,   687,   883,   689,   601,     9,    10,   888,    12,
     195,    14,    79,   232,   199,   429,   883,   202,     3,   277,
     481,   888,   416,   417,     9,    10,   608,    12,   480,    14,
     215,   495,   113,   427,   219,   116,   221,   482,   494,   682,
     121,   122,   483,   728,   165,   682,   580,   168,   115,   234,
     171,   327,   102,   177,   368,   566,   382,   710,   680,   244,
     663,   182,   521,   248,   589,   501,   665,    -1,   690,   254,
      -1,    -1,    -1,     3,    -1,    -1,    79,    -1,    -1,     9,
      10,   766,    12,   768,    14,    -1,     3,    -1,   773,    -1,
      -1,    -1,     9,    10,    79,    12,   781,    14,   283,   284,
       9,    10,    -1,    12,    -1,    14,    -1,   792,    -1,    -1,
     113,   114,   115,    -1,   299,    -1,   237,    -1,   121,   122,
      -1,   242,    -1,   244,    -1,     3,    -1,    -1,    -1,   250,
     115,     9,    10,    -1,    12,    -1,    14,    -1,    -1,   324,
       9,    10,   327,    12,    -1,    14,    -1,     9,    10,    79,
      12,   336,    14,    -1,   339,   777,    -1,    -1,   343,    16,
      17,    18,    19,    20,    21,    22,    23,    -1,    25,    -1,
      27,    80,    81,    82,   568,    -1,    33,    -1,   299,    -1,
      -1,    -1,    -1,   368,   869,   115,     9,    10,   373,    12,
      -1,    14,    -1,    -1,    -1,   380,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     0,    -1,    -1,   600,    -1,    -1,    -1,
       7,    -1,   834,    -1,   836,   837,    -1,    -1,    -1,    -1,
     684,    -1,    -1,   687,    -1,   689,    -1,    -1,    -1,    -1,
     415,   416,   417,    -1,   419,   356,   858,    34,   423,    -1,
      -1,    -1,   427,    -1,    -1,    -1,    -1,    44,    -1,   434,
      -1,    -1,    -1,   438,    -1,    -1,    -1,    -1,   443,    -1,
     445,   883,   447,    -1,   449,    62,   888,   452,    -1,   663,
      67,   665,   666,   130,    -1,   132,    -1,    -1,    -1,    -1,
     744,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      87,   412,    -1,    -1,   415,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   111,   112,   501,   781,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   519,    -1,   521,    -1,    -1,    -1,
      -1,    -1,   527,    -1,    -1,    -1,   810,   811,    -1,    -1,
      -1,    -1,    -1,   817,   818,    -1,    -1,    -1,    -1,   544,
      -1,    -1,    -1,    -1,    -1,   550,    -1,   831,    -1,    -1,
      -1,    -1,   169,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     177,   566,    -1,   568,    -1,   570,    -1,    -1,   573,    -1,
      -1,     8,     9,    10,    11,    12,    -1,    14,    -1,    -1,
      -1,    -1,    -1,    -1,   589,   202,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   600,    -1,    -1,   215,    -1,
      -1,    -1,   219,   608,   221,    42,    -1,    -1,    -1,    46,
      47,    48,    49,    50,   619,    -1,    -1,   234,    -1,    -1,
      -1,    58,    -1,    -1,    61,    -1,    -1,    -1,    -1,    66,
      -1,   248,    -1,    -1,    -1,    72,    73,   254,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,
      87,    -1,    -1,    -1,    -1,    92,    -1,    -1,   663,    -1,
     665,   666,    -1,    -1,    -1,   102,   103,   104,    -1,    -1,
     107,   108,   109,    -1,    -1,   680,   113,   682,    -1,   684,
      -1,    -1,   687,    -1,   689,   690,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     705,    -1,   707,    -1,    -1,   710,    -1,    -1,   713,    -1,
     327,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   728,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   368,    -1,    -1,    -1,    -1,   373,    -1,    -1,    -1,
      -1,   766,    -1,   768,    -1,    -1,    -1,    -1,   773,    -1,
      -1,    -1,   777,    -1,    -1,    -1,   781,    -1,    -1,    -1,
      -1,   786,    -1,    -1,    -1,    -1,    -1,   792,    -1,    -1,
     795,    -1,    -1,   798,    -1,   800,    -1,   802,    -1,    -1,
      -1,    -1,   419,    -1,    -1,    -1,   423,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   828,    -1,    -1,    -1,    -1,    -1,   834,
      -1,   836,   837,    -1,    -1,    -1,    -1,   842,    -1,    -1,
     845,    -1,    -1,   460,    -1,    -1,   463,    -1,    -1,     3,
       4,     5,     6,     7,    -1,     9,    10,    -1,    12,    -1,
      14,    -1,    -1,    -1,   869,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   883,    -1,
      34,    35,    -1,   888,    -1,    -1,    -1,    -1,    42,    -1,
      -1,    -1,    46,    -1,    -1,    -1,    -1,    51,    -1,    -1,
      -1,    -1,    56,    -1,    58,    59,    -1,    -1,    -1,    -1,
      -1,    65,    66,    -1,    -1,    -1,    -1,    -1,    72,    73,
      -1,    -1,    76,    -1,    -1,    79,    -1,    -1,    -1,    -1,
      84,    -1,    86,   550,    88,    -1,    -1,    91,    -1,    -1,
      -1,    95,    -1,    -1,    98,    -1,    -1,   101,    -1,   566,
      -1,   568,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,
      -1,   115,    -1,    -1,    -1,    -1,    -1,   121,   122,   123,
     124,   125,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   135,    -1,    -1,    -1,     3,     4,     5,     6,     7,
      -1,     9,    10,    -1,    12,    -1,    14,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   631,   632,    34,    35,    -1,   636,
     637,    -1,    -1,    -1,    42,    -1,    -1,    -1,    46,    -1,
      -1,    -1,    -1,    51,    -1,    -1,    -1,    -1,    56,    -1,
      58,    59,    -1,    -1,    -1,    -1,    -1,    65,    66,   666,
      -1,    -1,    -1,    -1,    72,    73,    -1,    -1,    76,    -1,
      -1,    79,    -1,    -1,    -1,    -1,    84,    -1,    86,    -1,
      88,    -1,    -1,    91,    -1,    -1,    -1,    95,    -1,    97,
      98,    -1,    -1,   101,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   113,    -1,   115,    -1,    -1,
      -1,    -1,    -1,   121,   122,   123,   124,   125,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   133,   134,    -1,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    -1,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   758,    -1,    -1,    -1,    -1,   763,    -1,    -1,    34,
      35,    -1,    -1,    -1,    -1,    40,    41,    42,    43,    44,
      -1,    46,    47,    48,    49,    50,    51,    -1,    53,   786,
      55,    56,    57,    58,    59,    -1,    61,    62,    -1,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    -1,    -1,    79,    -1,    -1,    -1,    83,    84,
      85,    86,    87,    88,    89,    -1,    91,    92,    93,    -1,
      95,   828,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,    -1,   112,   113,    -1,
     115,    -1,    -1,    -1,    -1,    -1,   121,   122,   123,   124,
     125,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   133,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    -1,
      14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      34,    35,    -1,    -1,    -1,    -1,    40,    41,    42,    43,
      44,    -1,    46,    47,    48,    49,    50,    51,    -1,    53,
      -1,    55,    56,    57,    58,    59,    -1,    61,    62,    -1,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    -1,    -1,    79,    -1,    -1,    -1,    83,
      84,    85,    86,    87,    88,    89,    -1,    91,    92,    93,
      -1,    95,    -1,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,    -1,    -1,   113,
      -1,   115,    -1,    -1,    -1,    -1,    -1,   121,   122,   123,
     124,   125,    -1,    -1,    -1,     3,    -1,    -1,    -1,   133,
       8,     9,    10,    11,    12,    -1,    14,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    40,    41,    42,    -1,    -1,    -1,    46,    47,
      48,    49,    50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      58,    -1,    -1,    61,    62,    63,    64,    -1,    66,    -1,
      68,    -1,    -1,    71,    72,    73,    74,    75,    -1,    -1,
      -1,    79,    -1,    -1,    -1,    83,    -1,    -1,    86,    87,
      -1,    89,    -1,    -1,    92,    -1,    94,    -1,    -1,    -1,
      -1,    -1,   100,    -1,   102,   103,   104,   105,   106,   107,
     108,   109,    -1,    -1,    -1,   113,    -1,   115,    -1,    -1,
      -1,    -1,    -1,   121,   122,     3,     4,     5,     6,     7,
      -1,     9,    10,    -1,    12,   133,    14,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    34,    35,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,    46,    -1,
      -1,    -1,    -1,    51,    -1,    -1,    -1,    -1,    56,    -1,
      58,    59,    -1,    -1,    -1,    -1,    -1,    65,    66,    -1,
      -1,    -1,    -1,    -1,    72,    73,    -1,    -1,    76,    -1,
      -1,    79,    -1,    -1,    -1,    -1,    84,    -1,    86,    -1,
      88,    -1,    -1,    91,    -1,    -1,    -1,    95,    -1,    97,
      98,    -1,    -1,   101,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   113,    -1,   115,    -1,    -1,
      -1,    -1,    -1,   121,   122,   123,   124,   125,     8,     9,
      10,    11,    12,    -1,    14,   133,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    -1,    -1,
      -1,    -1,    42,    -1,    -1,    -1,    46,    47,    48,    49,
      50,    -1,    -1,    -1,    -1,    -1,    56,    -1,    58,    -1,
      -1,    61,    -1,    -1,    -1,    -1,    66,    -1,    -1,    -1,
      -1,    -1,    72,    73,    -1,    -1,    76,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    86,    87,    -1,    -1,
      -1,    -1,    92,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   102,   103,   104,    -1,    -1,   107,   108,   109,
      -1,   111,    -1,   113,    -1,   115,   116,    -1,    -1,   119,
     120,   121,   122,   123,    -1,   125,   126,   127,   128,   129,
      -1,    -1,   132,    -1,    -1,    -1,   136,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    -1,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,
      -1,    -1,    -1,    -1,    -1,    41,    42,    -1,    -1,    -1,
      46,    47,    48,    49,    50,    51,    -1,    -1,    -1,    -1,
      56,    -1,    58,    59,    -1,    61,    62,    -1,    64,    65,
      66,    -1,    68,    -1,    -1,    71,    72,    73,    74,    -1,
      76,    -1,    -1,    79,    -1,    -1,    -1,    83,    84,    -1,
      86,    87,    88,    89,    -1,    91,    92,    -1,    -1,    95,
      -1,    97,    98,    -1,   100,   101,   102,   103,   104,    -1,
     106,   107,   108,   109,    -1,    -1,    -1,   113,    -1,   115,
      -1,    -1,    -1,    -1,    -1,   121,   122,   123,   124,   125,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    42,
      -1,    -1,    -1,    46,    47,    48,    49,    50,    51,    -1,
      -1,    -1,    -1,    56,    -1,    58,    59,    -1,    61,    -1,
      -1,    -1,    65,    66,    -1,    -1,    -1,    -1,    -1,    72,
      73,    -1,    -1,    76,    -1,    -1,    79,    -1,    -1,    -1,
      -1,    84,    -1,    86,    87,    88,    -1,    -1,    91,    92,
      -1,    -1,    95,    -1,    97,    98,    -1,    -1,   101,   102,
     103,   104,    -1,    -1,   107,   108,   109,    -1,    -1,    -1,
     113,    -1,   115,    -1,    -1,    -1,    -1,    -1,   121,   122,
     123,   124,   125,     3,     4,     5,     6,     7,    -1,     9,
      10,    -1,    12,    -1,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    34,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    -1,    -1,    -1,    46,    -1,    -1,    -1,
      -1,    51,    -1,    -1,    -1,    -1,    56,    -1,    58,    59,
      -1,    -1,    -1,    -1,    -1,    65,    66,    -1,    -1,    -1,
      -1,    -1,    72,    73,    -1,    -1,    76,    -1,    -1,    79,
      -1,    -1,    -1,    -1,    84,    -1,    86,    -1,    88,    -1,
      -1,    91,    -1,    -1,    -1,    95,    -1,    -1,    98,    -1,
      -1,   101,    -1,     3,     4,     5,     6,     7,    -1,     9,
      10,    -1,    12,   113,    14,   115,   116,    -1,    -1,    -1,
      -1,   121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    34,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    -1,    -1,    -1,    46,    -1,    -1,    -1,
      -1,    51,    -1,    -1,    -1,    -1,    56,    -1,    58,    59,
      -1,    -1,    -1,    -1,    -1,    65,    66,    -1,    -1,    -1,
      -1,    -1,    72,    73,    -1,    -1,    76,    -1,    -1,    79,
      -1,    -1,    -1,    -1,    84,    -1,    86,    -1,    88,    -1,
      -1,    91,    -1,    -1,    -1,    95,    -1,    97,    98,    -1,
      -1,   101,    -1,     3,     4,     5,     6,     7,    -1,     9,
      10,    -1,    12,   113,    14,   115,    -1,    -1,    -1,    -1,
      -1,   121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    34,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    -1,    -1,    -1,    46,    -1,    -1,    -1,
      -1,    51,    -1,    -1,    -1,    -1,    56,    -1,    58,    59,
      -1,    -1,    -1,    -1,    -1,    65,    66,    -1,    -1,    -1,
      -1,    -1,    72,    73,    -1,    -1,    76,    -1,    -1,    79,
      -1,    -1,    -1,    -1,    84,    -1,    86,    -1,    88,    -1,
      -1,    91,    -1,    -1,    -1,    95,    -1,    -1,    98,    -1,
      -1,   101,    -1,     3,     4,     5,     6,     7,    -1,     9,
      10,    -1,    12,   113,    14,   115,   116,    -1,    -1,    -1,
      -1,   121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    34,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    -1,    -1,    -1,    46,    -1,    -1,    -1,
      -1,    51,    -1,    -1,    -1,    -1,    56,    -1,    58,    59,
      -1,    -1,    -1,    -1,    -1,    65,    66,    -1,    -1,    -1,
      -1,    -1,    72,    73,    -1,    -1,    76,    -1,    -1,    79,
      -1,    -1,    -1,    -1,    84,    -1,    86,    -1,    88,    -1,
      -1,    91,    -1,    -1,    -1,    95,    -1,    -1,    98,    -1,
      -1,   101,    -1,     3,     4,     5,     6,     7,    -1,     9,
      10,    -1,    12,   113,    14,   115,    -1,    -1,    -1,    -1,
      -1,   121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    34,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    -1,    -1,    -1,    46,    -1,    -1,    -1,
      -1,    51,    -1,    -1,    -1,    -1,    56,    -1,    58,    59,
      -1,    -1,    -1,    -1,    -1,    65,    66,    -1,    -1,    -1,
      -1,    -1,    72,    73,    -1,    -1,    76,    -1,    -1,    79,
      -1,    -1,    -1,    -1,    84,    -1,    86,    -1,    88,    -1,
      -1,    91,    -1,    -1,    -1,    95,    -1,     3,    98,    -1,
      -1,   101,     8,     9,    10,    11,    12,    -1,    14,    -1,
      -1,    -1,    -1,   113,    -1,   115,    -1,    -1,    -1,    -1,
      -1,   121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    41,    42,    -1,    -1,    -1,
      46,    47,    48,    49,    50,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    58,    -1,    -1,    61,    62,    63,    64,    -1,
      66,    -1,    68,    -1,    -1,    71,    72,    73,    74,    -1,
      -1,    -1,    -1,    79,    80,    81,    82,    83,    -1,    -1,
      86,    87,    -1,    89,     3,    -1,    92,    -1,    94,     8,
       9,    10,    11,    12,   100,    14,   102,   103,   104,   105,
     106,   107,   108,   109,    -1,    -1,   112,   113,    -1,   115,
      -1,    -1,    -1,    -1,    -1,   121,   122,    -1,    -1,    -1,
      -1,    40,    41,    42,    -1,    -1,    -1,    46,    47,    48,
      49,    50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,
      -1,    -1,    61,    62,    63,    64,    -1,    66,    -1,    68,
      -1,    -1,    71,    72,    73,    74,    75,    -1,    -1,    -1,
      79,    -1,    -1,    -1,    83,    -1,    -1,    86,    87,    -1,
      89,     3,    -1,    92,    -1,    94,     8,     9,    10,    11,
      12,   100,    14,   102,   103,   104,   105,   106,   107,   108,
     109,    -1,    -1,    -1,   113,    -1,   115,    -1,    -1,    -1,
     119,    -1,   121,   122,    -1,    -1,    -1,    -1,    40,    41,
      42,    -1,    -1,    -1,    46,    47,    48,    49,    50,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,    61,
      62,    63,    64,    -1,    66,    -1,    68,    -1,    -1,    71,
      72,    73,    74,    75,    -1,    -1,    -1,    79,    -1,    -1,
      -1,    83,    -1,    -1,    86,    87,    -1,    89,     3,    -1,
      92,    -1,    94,     8,     9,    10,    11,    12,   100,    14,
     102,   103,   104,   105,   106,   107,   108,   109,    -1,    -1,
      -1,   113,    -1,   115,    -1,    -1,    -1,    -1,    -1,   121,
     122,    -1,    -1,    -1,    -1,    -1,    41,    42,    -1,    -1,
      -1,    46,    47,    48,    49,    50,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    58,    -1,    -1,    61,    62,    -1,    64,
      -1,    66,    -1,    68,    -1,    -1,    71,    72,    73,    74,
      -1,    -1,    -1,    -1,    79,    -1,    -1,    -1,    83,    -1,
      -1,    86,    87,     3,    89,    -1,    -1,    92,     8,     9,
      10,    11,    12,    -1,    14,   100,    -1,   102,   103,   104,
      -1,   106,   107,   108,   109,    -1,    -1,   112,   113,    -1,
     115,    -1,    -1,    -1,    -1,    -1,   121,   122,    -1,    -1,
      -1,    41,    42,    -1,    -1,    -1,    46,    47,    48,    49,
      50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    -1,
      -1,    61,    62,    -1,    64,    -1,    66,    -1,    68,    -1,
      -1,    71,    72,    73,    74,    -1,    -1,    -1,    -1,    79,
      -1,    -1,    -1,    83,    -1,    -1,    86,    87,     3,    89,
      -1,    -1,    92,     8,     9,    10,    11,    12,    -1,    14,
     100,    -1,   102,   103,   104,    -1,   106,   107,   108,   109,
      -1,    -1,    -1,   113,    -1,   115,   116,    -1,    -1,    -1,
      -1,   121,   122,    -1,    -1,    -1,    41,    42,    -1,    -1,
      -1,    46,    47,    48,    49,    50,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    58,    -1,    -1,    61,    62,    -1,    64,
      -1,    66,    -1,    68,    -1,    -1,    71,    72,    73,    74,
      -1,    -1,    -1,    -1,    79,    -1,    -1,    -1,    83,    -1,
      -1,    86,    87,    -1,    89,    -1,    -1,    92,     8,     9,
      10,    11,    12,    -1,    14,   100,    -1,   102,   103,   104,
      -1,   106,   107,   108,   109,    -1,    -1,   112,   113,    -1,
     115,    -1,    -1,    -1,    -1,    -1,   121,   122,    -1,    -1,
      -1,    -1,    42,    -1,    -1,    -1,    46,    47,    48,    49,
      50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    -1,
      -1,    61,    -1,    -1,    -1,    -1,    66,    -1,    -1,    -1,
      -1,    -1,    72,    73,    -1,    -1,    -1,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    86,    87,    -1,    -1,
      -1,    -1,    92,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   102,   103,   104,    -1,    -1,   107,   108,   109,
      41,    42,    -1,   113,    -1,    46,    47,    48,    49,    50,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,
      61,    62,    -1,    64,    -1,    66,    -1,    68,    -1,    -1,
      71,    72,    73,    74,    -1,    -1,    -1,     8,     9,    10,
      11,    12,    83,    14,    -1,    86,    87,    -1,    89,    -1,
      -1,    92,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   100,
      -1,   102,   103,   104,    -1,   106,   107,   108,   109,    -1,
      41,    42,    -1,    -1,    -1,    46,    47,    48,    49,    50,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,
      61,    62,    -1,    64,    -1,    66,    -1,    68,    -1,    -1,
      71,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    83,    -1,    -1,    86,    87,    -1,    89,    -1,
      -1,    92,    -1,    94,    -1,    -1,    -1,    -1,    -1,   100,
      -1,   102,   103,   104,    -1,   106,   107,   108,   109,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    41,    42,    -1,    -1,    -1,    46,    47,    48,
      49,    50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,
      -1,    -1,    61,    62,    -1,    64,    -1,    66,    -1,    68,
      -1,    -1,    71,    72,    73,    74,    -1,     8,     9,    10,
      11,    12,    13,    14,    83,    -1,    -1,    86,    87,    -1,
      89,    -1,    -1,    92,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   100,    -1,   102,   103,   104,    -1,   106,   107,   108,
     109,    42,    -1,    -1,    -1,    46,    47,    48,    49,    50,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,
      61,    -1,    -1,    -1,    -1,    66,    -1,    -1,    -1,    -1,
      -1,    72,    73,    -1,    -1,     8,     9,    10,    11,    12,
      -1,    14,    -1,    -1,    -1,    86,    87,    -1,    -1,    -1,
      -1,    92,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   102,   103,   104,    -1,    -1,   107,   108,   109,    42,
      -1,    -1,    -1,    46,    47,    48,    49,    50,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,    61,    -1,
      -1,    -1,    -1,    66,    -1,    -1,    -1,    -1,    -1,    72,
      73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    86,    87,    -1,    -1,    -1,    -1,    92,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   102,
     103,   104,    -1,    -1,   107,   108,   109
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     3,     8,     9,    10,    11,    12,    14,    40,    41,
      42,    46,    47,    48,    49,    50,    58,    61,    62,    63,
      64,    66,    68,    71,    72,    73,    74,    75,    79,    83,
      86,    87,    89,    92,    94,   100,   102,   103,   104,   105,
     106,   107,   108,   109,   113,   115,   121,   122,   138,   139,
     140,   141,   142,   143,   144,   151,   152,   173,   178,   179,
     180,   181,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   236,   237,   238,   239,   240,
     242,   244,   245,   246,   247,   250,   251,   252,   254,   255,
     263,   268,   269,   270,   281,   288,   290,   294,   297,   298,
     141,   161,   178,   181,   230,   113,    14,   141,   144,   181,
       7,   149,   133,   140,   144,    14,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    56,    76,
     111,   113,   115,   116,   119,   120,   121,   122,   123,   125,
     126,   127,   128,   129,   132,   136,   181,   228,   257,   282,
     289,   119,   221,    14,   175,    14,    75,   102,   181,    14,
     141,   181,   250,   141,   253,   254,    14,    14,   113,   119,
       0,    94,    94,   121,   141,   179,   230,   221,    64,   112,
     224,   248,   249,   250,    99,   131,   163,   284,   300,   113,
     116,   250,   133,    14,   144,   181,    14,   230,   121,   230,
     149,   144,   181,   133,   144,   133,   221,   152,   241,   133,
     132,   133,   181,   116,   116,   114,   117,   164,   257,    14,
     172,   181,   252,   283,   120,   181,   179,   181,    14,   139,
     181,    14,   181,   179,   181,   114,   253,   181,    14,   141,
     181,   255,    13,   168,   225,   260,   261,   262,     4,     5,
       6,    14,    34,    35,    42,    46,    51,    56,    58,    59,
      65,    66,    72,    73,    76,    84,    86,    88,    91,    95,
      97,    98,   101,   113,   115,   121,   122,   123,   124,   125,
     143,   145,   146,   147,   148,   149,   150,   177,   178,   181,
     182,   183,   184,   185,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   206,   256,
     257,   295,   296,   304,   119,   179,   253,   111,   112,   113,
     132,   162,   163,   265,   300,   163,    14,   141,   144,   181,
     285,   286,   287,   133,   212,   264,   168,    14,    42,    46,
      58,    66,    72,    73,    86,   155,   181,   203,   204,   205,
      80,    81,    82,   105,   112,   144,   170,   180,   225,   244,
     250,   263,   271,   272,   273,   274,   280,   290,   144,   181,
     131,   277,   144,   181,   253,   114,   144,   144,   169,   233,
     234,   235,   152,   134,   241,    14,   139,   181,   243,   241,
     117,   117,   181,   172,   221,   144,   112,   179,   139,   181,
     112,   139,   181,   179,   112,   181,   113,   113,   114,   113,
     166,   167,   250,   252,   258,   259,    13,   111,    56,    76,
     192,   192,   113,   113,   119,   116,   192,   113,   119,   113,
     113,   113,   113,   158,   186,   119,   113,   113,   183,   119,
     157,   206,   113,   206,   208,   256,   192,   192,    34,    35,
      37,   113,   116,   118,   192,    15,    36,   121,   126,   127,
     123,   124,    24,    26,    29,    30,   119,   120,    28,    31,
     122,   128,   129,    32,    16,    17,    18,    19,    20,    21,
      22,    23,    25,    27,    33,   130,   132,   207,   113,   166,
     252,   111,   120,    49,    94,   102,   262,   291,   292,   293,
     249,   250,   208,   133,   206,   266,   264,   264,   141,   181,
     141,   111,   113,    43,    44,    53,    55,    57,    67,    69,
      70,    75,    85,    93,    99,   110,   144,   153,   154,   208,
     209,   210,   211,   212,   213,   214,   216,   218,   219,   222,
     225,   299,   114,   117,   131,   134,   112,   112,   250,   273,
     132,   275,   276,   112,   176,   170,   111,   112,   131,   144,
      14,   106,   141,   181,   278,   279,   280,   277,   112,   134,
     111,   132,   134,   134,   139,   181,   139,   112,   134,   119,
     112,   112,   139,   112,   179,   112,   168,   168,   258,   132,
     113,   116,   132,   166,    13,   262,   116,   192,   158,   154,
     154,   256,   117,   154,   256,   154,   154,   154,   208,   113,
     187,   257,   256,   154,   256,   256,   208,   256,   111,   114,
     114,    14,    94,   178,   154,   208,    14,    94,   178,   192,
     192,   193,   193,   193,   194,   194,   195,   195,   196,   196,
     196,   196,   197,   197,   198,   199,   200,   201,   202,   208,
     206,   296,   144,   119,   144,   111,   120,   114,   134,   266,
     267,    45,   301,   302,   141,   285,   154,   112,   205,   112,
     131,   209,   113,   144,   113,   144,   154,   113,   212,   113,
     131,   134,   112,   209,    97,   253,   305,   205,   112,   135,
     205,   250,   274,   170,   141,   181,    14,   161,   280,   141,
     111,    14,   106,   161,   234,   205,   139,   295,   112,   112,
     114,   114,   114,   206,   168,   155,   206,   117,   113,   187,
     114,   114,   120,   192,   114,   120,   114,   114,   114,   114,
     256,   113,   159,   190,   116,   160,   188,   189,   252,   120,
     114,   114,   120,   114,   114,   206,   192,   178,    14,   178,
     114,   117,   178,    14,   178,   131,   132,   291,   132,   292,
     221,   111,   174,   113,   171,   301,   114,   131,   209,   110,
     211,   217,   223,   112,   208,   215,   257,   112,   215,   301,
     215,   209,   113,   305,   141,   161,   141,    14,   161,   279,
     161,    14,   161,   141,   120,   114,   117,   192,   256,   159,
     113,   113,   114,   154,   208,   116,   160,   113,   113,   178,
     178,   206,   256,   120,   256,   266,   134,    13,   257,   303,
     209,   113,   156,   215,   114,   250,   114,   114,   165,   256,
     306,   141,   161,   141,   141,   161,   141,   253,   305,   114,
     208,   208,   159,   114,   117,   205,   208,   208,    49,   250,
     258,   114,   208,   112,   209,   132,   209,   209,   114,   111,
     141,   141,   305,   159,   114,   114,   117,   114,   114,   144,
     212,   114,   154,    60,   206,   256,   132,   112,   114,   209,
     143,   209
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   137,   138,   139,   140,   141,   141,   142,   143,   144,
     145,   145,   145,   145,   145,   146,   147,   148,   149,   150,
     150,   151,   152,   152,   153,   153,   154,   154,   155,   155,
     156,   156,   157,   157,   158,   158,   159,   159,   160,   160,
     161,   161,   162,   162,   163,   163,   164,   164,   165,   165,
     166,   166,   167,   167,   168,   168,   169,   169,   170,   170,
     171,   171,   172,   172,   173,   173,   174,   174,   175,   175,
     176,   176,   177,   177,   177,   177,   178,   178,   179,   179,
     179,   179,   180,   180,   181,   181,   181,   181,   182,   182,
     182,   182,   182,   182,   182,   182,   182,   182,   182,   182,
     182,   182,   182,   182,   182,   182,   182,   182,   182,   182,
     182,   182,   182,   182,   183,   183,   183,   183,   183,   183,
     183,   183,   183,   183,   184,   184,   184,   184,   185,   185,
     185,   185,   186,   187,   188,   188,   189,   189,   190,   191,
     191,   191,   191,   192,   192,   193,   193,   193,   194,   194,
     194,   194,   195,   195,   195,   196,   196,   196,   197,   197,
     197,   197,   197,   198,   198,   198,   199,   199,   200,   200,
     201,   201,   202,   202,   203,   203,   204,   204,   205,   206,
     206,   206,   207,   207,   207,   207,   207,   207,   207,   207,
     207,   207,   207,   208,   208,   209,   209,   209,   209,   209,
     209,   209,   209,   210,   210,   210,   211,   212,   213,   213,
     214,   214,   214,   215,   215,   216,   216,   216,   217,   217,
     218,   218,   218,   218,   219,   220,   220,   221,   221,   221,
     221,   221,   221,   221,   222,   222,   222,   222,   222,   223,
     223,   224,   224,   224,   224,   224,   225,   225,   226,   226,
     226,   226,   226,   227,   227,   227,   228,   228,   228,   228,
     228,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   230,   230,   230,
     231,   231,   231,   231,   231,   231,   231,   232,   233,   233,
     234,   234,   235,   236,   236,   237,   237,   238,   239,   240,
     241,   242,   243,   243,   243,   243,   244,   244,   244,   244,
     244,   245,   245,   245,   245,   246,   247,   247,   248,   248,
     249,   250,   250,   251,   251,   251,   251,   251,   251,   251,
     251,   251,   251,   252,   252,   252,   252,   252,   252,   252,
     253,   253,   254,   254,   255,   255,   255,   255,   256,   257,
     258,   258,   259,   259,   259,   259,   259,   259,   260,   260,
     260,   260,   261,   261,   262,   262,   262,   262,   263,   263,
     263,   263,   264,   265,   265,   266,   266,   266,   267,   267,
     268,   269,   269,   269,   269,   270,   270,   270,   271,   271,
     272,   272,   272,   272,   272,   272,   272,   272,   273,   273,
     274,   274,   274,   274,   275,   276,   277,   278,   278,   279,
     279,   279,   279,   279,   279,   279,   279,   279,   279,   279,
     279,   280,   280,   280,   281,   282,   283,   284,   285,   285,
     286,   287,   287,   287,   287,   287,   288,   289,   289,   289,
     289,   289,   289,   289,   289,   289,   289,   289,   289,   289,
     289,   289,   289,   289,   289,   289,   289,   289,   289,   289,
     289,   289,   289,   289,   289,   289,   289,   289,   289,   289,
     289,   289,   289,   289,   289,   289,   289,   289,   289,   290,
     291,   291,   292,   292,   293,   293,   293,   293,   293,   293,
     294,   295,   295,   296,   296,   296,   297,   298,   299,   300,
     301,   302,   303,   303,   303,   303,   304,   305,   306,   306
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     1,     0,     1,     0,     1,     0,     1,
       0,     1,     0,     1,     0,     1,     0,     1,     0,     1,
       0,     1,     0,     1,     0,     1,     0,     1,     0,     1,
       0,     1,     0,     1,     0,     1,     0,     1,     0,     1,
       0,     1,     0,     1,     0,     1,     0,     1,     0,     1,
       0,     1,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     2,     2,     3,     3,     3,     2,     2,     1,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     5,     4,
       4,     3,     5,     4,     4,     3,     2,     2,     7,     7,
       7,     7,     4,     4,     1,     2,     2,     2,     2,     2,
       2,     4,     1,     1,     1,     1,     1,     1,     4,     5,
       6,     7,     3,     2,     2,     1,     3,     4,     3,     2,
       3,     4,     5,     1,     4,     1,     3,     3,     1,     3,
       3,     3,     1,     3,     3,     1,     3,     3,     1,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     5,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     4,     3,     2,     3,     1,     2,
       5,     7,     5,     1,     4,     5,     7,     8,     1,     1,
       2,     2,     3,     3,     1,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       2,     1,     1,     1,     1,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     3,     4,     3,     3,     4,     7,     5,     1,     3,
       1,     3,     1,     1,     1,     1,     1,     5,     5,     4,
       1,     5,     3,     2,     2,     1,     6,     5,     5,     4,
       4,     6,     5,     5,     4,     5,     5,     3,     1,     3,
       2,     1,     2,     1,     6,     5,     5,     4,     4,     6,
       6,     4,     3,     1,     2,     1,     2,     3,     3,     4,
       1,     2,     1,     1,     1,     2,     3,     2,     2,     2,
       2,     1,     6,     5,     5,     4,     4,     3,     2,     3,
       1,     1,     1,     3,     2,     4,     2,     4,     3,     4,
       2,     3,     1,     2,     3,     1,     4,     2,     1,     3,
       4,     2,     3,     3,     4,     1,     1,     1,     2,     3,
       3,     2,     2,     1,     2,     2,     1,     1,     1,     3,
       1,     2,     2,     3,     2,     2,     2,     1,     3,     3,
       2,     2,     1,     5,     4,     4,     3,     5,     4,     4,
       3,     1,     1,     1,     2,     2,     2,     2,     1,     3,
       4,     3,     2,     2,     1,     1,     2,     1,     1,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     6,
       1,     3,     1,     1,     2,     4,     2,     4,     6,     8,
       4,     1,     3,     1,     1,     1,     2,     4,     3,     4,
       2,     5,     2,     2,     1,     1,     2,     4,     1,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 104 "120++parse.y" /* yacc.c:1646  */
    { yylval->production = typedef_name; (yyval) = (yyvsp[0]); }
#line 2695 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 108 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( namespace_name, "namespace_name", 1, (yyvsp[0]) ); }
#line 2701 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 113 "120++parse.y" /* yacc.c:1646  */
    { yylval->production = original_namespace_name; (yyval) = (yyvsp[0]); }
#line 2707 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 118 "120++parse.y" /* yacc.c:1646  */
    { yylval->production = class_name; (yyval) = (yyvsp[0]); }
#line 2713 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 119 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned below */ (yyval) = pt_generate_node( class_name+2, "class_name_2", 1, (yyvsp[0]) ); }
#line 2719 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 124 "120++parse.y" /* yacc.c:1646  */
    { yylval->production = enum_name; (yyval) = (yyvsp[0]); }
#line 2725 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 129 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ yylval->production = template_name; (yyval) = (yyvsp[0]); }
#line 2731 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 137 "120++parse.y" /* yacc.c:1646  */
    { yylval->production = identifier; (yyval) = (yyvsp[0]); }
#line 2737 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 141 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( literal+1, "literal_1", 1, (yyvsp[0]) ); }
#line 2743 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 142 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( literal+2, "literal_2", 1, (yyvsp[0]) ); }
#line 2749 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 143 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( literal+3, "literal_3", 1, (yyvsp[0]) ); }
#line 2755 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 144 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( literal+4, "literal_4", 1, (yyvsp[0]) ); }
#line 2761 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 145 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( literal+5, "literal_5", 1, (yyvsp[0]) ); }
#line 2767 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 149 "120++parse.y" /* yacc.c:1646  */
    { yylval->production = integer_literal; (yyval) = (yyvsp[0]); }
#line 2773 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 153 "120++parse.y" /* yacc.c:1646  */
    { yylval->production = character_literal; (yyval) = (yyvsp[0]); }
#line 2779 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 157 "120++parse.y" /* yacc.c:1646  */
    { yylval->production = floating_literal; (yyval) = (yyvsp[0]); }
#line 2785 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 161 "120++parse.y" /* yacc.c:1646  */
    { yylval->production = string_literal; (yyval) = (yyvsp[0]); }
#line 2791 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 165 "120++parse.y" /* yacc.c:1646  */
    { yylval->production = boolean_literal+1; (yyval) = (yyvsp[0]); }
#line 2797 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 166 "120++parse.y" /* yacc.c:1646  */
    { yylval->production = boolean_literal+2; (yyval) = (yyvsp[0]); }
#line 2803 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 174 "120++parse.y" /* yacc.c:1646  */
    { yyparsetree = pt_generate_node( program_start, "program_start", 1, (yyvsp[0]) ); }
#line 2809 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 183 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = NULL; }
#line 2815 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 184 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( declaration_seq_opt+1, "declaration_seq_opt", 1, (yyvsp[0]) ); }
#line 2821 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 188 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = NULL; }
#line 2827 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 189 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( statement_seq_opt+1, "statement_seq_opt", 1, (yyvsp[0]) ); }
#line 2833 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 193 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = NULL; }
#line 2839 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 194 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( expression_list_opt+1, "expression_list_opt", 1, (yyvsp[0]) ); }
#line 2845 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 198 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = NULL; }
#line 2851 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 199 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( constant_expression_opt+1, "constant_expression_opt", 1, (yyvsp[0]) ); }
#line 2857 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 203 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = NULL; }
#line 2863 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 204 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( condition_opt+1, "condition_opt", 1, (yyvsp[0]) ); }
#line 2869 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 208 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = NULL; }
#line 2875 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 209 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ (yyval) = pt_generate_node( assignment_expression_opt+1, "assignment_expression_opt", 1, (yyvsp[0]) ); }
#line 2881 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 213 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = NULL; }
#line 2887 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 214 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( new_placement_opt+1, "new_placement_opt", 1, (yyvsp[0]) ); }
#line 2893 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 218 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = NULL; }
#line 2899 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 219 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( new_initializer_opt+1, "new_initializer_opt", 1, (yyvsp[0]) ); }
#line 2905 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 223 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = NULL; }
#line 2911 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 224 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( new_declarator_opt+1, "new_declarator_opt", 1, (yyvsp[0]) ); }
#line 2917 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 228 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = NULL; }
#line 2923 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 229 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( nested_name_specifier_opt+1, "nested_name_specifier_opt", 1, (yyvsp[0]) ); }
#line 2929 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 233 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = NULL; }
#line 2935 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 234 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( initializer_opt+1, "initializer_opt", 1, (yyvsp[0]) ); }
#line 2941 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 238 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = NULL; }
#line 2947 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 239 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ (yyval) = pt_generate_node( ctor_initializer_opt+1, "ctor_initializer_opt", 1, (yyvsp[0]) ); }
#line 2953 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 243 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = NULL; }
#line 2959 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 244 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( type_specifier_seq_opt+1, "type_specifier_seq_opt", 1, (yyvsp[0]) ); }
#line 2965 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 248 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = NULL; }
#line 2971 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 249 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ (yyval) = pt_generate_node( type_id_list_opt+1, "type_id_list_opt", 1, (yyvsp[0]) ); }
#line 2977 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 253 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = NULL; }
#line 2983 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 254 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( abstract_declarator_opt+1, "abstract_declarator_opt", 1, (yyvsp[0]) ); }
#line 2989 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 258 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = NULL; }
#line 2995 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 259 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( direct_abstract_declarator_opt+1, "direct_abstract_declarator_opt", 1, (yyvsp[0]) ); }
#line 3001 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 263 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = NULL; }
#line 3007 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 264 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( parameter_declaration_clause_opt+1, "parameter_declaration_clause_opt", 1, (yyvsp[0]) ); }
#line 3013 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 268 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = NULL; }
#line 3019 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 269 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ (yyval) = pt_generate_node( enumerator_list_opt+1, "enumerator_list_opt", 1, (yyvsp[0]) ); }
#line 3025 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 273 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = NULL; }
#line 3031 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 274 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( member_specification_opt+1, "member_specification_opt", 1, (yyvsp[0]) ); }
#line 3037 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 278 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = NULL; }
#line 3043 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 279 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ (yyval) = pt_generate_node( handler_seq_opt+1, "handler_seq_opt", 1, (yyvsp[0]) ); }
#line 3049 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 283 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = NULL; }
#line 3055 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 284 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ (yyval) = pt_generate_node( conversion_declarator_opt+1, "conversion_declarator_opt", 1, (yyvsp[0]) ); }
#line 3061 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 288 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = NULL; }
#line 3067 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 289 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ (yyval) = pt_generate_node( EXPORT_opt+1, "EXPORT_opt", 1, (yyvsp[0]) ); }
#line 3073 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 293 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = NULL; }
#line 3079 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 294 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( COMMA_opt+1, "COMMA_opt", 1, (yyvsp[0]) ); }
#line 3085 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 298 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = NULL; }
#line 3091 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 299 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ (yyval) = pt_generate_node( COLONCOLON_opt+1, "COLONCOLON_opt", 1, (yyvsp[0]) ); }
#line 3097 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 303 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = NULL; }
#line 3103 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 304 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( SEMICOLON_opt+1, "SEMICOLON_opt", 1, (yyvsp[0]) ); }
#line 3109 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 312 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( primary_expression+1, "primary_expression_1", 1, (yyvsp[0]) ); }
#line 3115 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 313 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( primary_expression+2, "primary_expression_2", 1, (yyvsp[0]) ); }
#line 3121 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 314 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( primary_expression+3, "primary_expression_3", 3, (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 3127 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 315 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( primary_expression+4, "primary_expression_4", 1, (yyvsp[0]) ); }
#line 3133 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 319 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( id_expression+1, "id_expression_1", 1, (yyvsp[0]) ); }
#line 3139 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 320 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( id_expression+2, "id_expression_2", 1, (yyvsp[0]) ); }
#line 3145 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 324 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( unqualified_id+1, "unqualified_id_1", 1, (yyvsp[0]) ); }
#line 3151 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 325 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned below */ (yyval) = pt_generate_node( unqualified_id+2, "unqualified_id_2", 1, (yyvsp[0]) ); }
#line 3157 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 326 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned below */ (yyval) = pt_generate_node( unqualified_id+3, "unqualified_id_3", 1, (yyvsp[0]) ); }
#line 3163 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 327 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ handle_parse_warning( "Class destructor operator is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); (yyval) = pt_generate_node( unqualified_id+4, "unqualified_id_4", 2, (yyvsp[-1]), (yyvsp[0]) ); }
#line 3169 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 331 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( qualified_id+1, "qualified_id_1", 2, (yyvsp[-1]), (yyvsp[0]) ); }
#line 3175 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 332 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ handle_parse_warning( "Templates are not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); (yyval) = pt_generate_node( qualified_id+2, "qualified_id_2", 3, (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 3181 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 336 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( nested_name_specifier+1, "nested_name_specifier_1", 3, (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 3187 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 337 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( nested_name_specifier+2, "nested_name_specifier_2", 3, (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 3193 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 338 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( nested_name_specifier+3, "nested_name_specifier_3", 2, (yyvsp[-1]), (yyvsp[0]) ); }
#line 3199 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 339 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( nested_name_specifier+4, "nested_name_specifier_4", 2, (yyvsp[-1]), (yyvsp[0]) ); }
#line 3205 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 343 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( postfix_expression+1, "postfix_expression_1", 1, (yyvsp[0]) ); }
#line 3211 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 344 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( postfix_expression+2, "postfix_expression_2", 4, (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 3217 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 345 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( postfix_expression+3, "postfix_expression_3", 4, (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 3223 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 346 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( postfix_expression+4, "postfix_expression_4", 4, (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 3229 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 347 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( postfix_expression+5, "postfix_expression_5", 4, (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 3235 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 348 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( postfix_expression+6, "postfix_expression_6", 4, (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 3241 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 349 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( postfix_expression+7, "postfix_expression_7", 4, (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 3247 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 350 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( postfix_expression+8, "postfix_expression_8", 4, (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 3253 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 351 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( postfix_expression+9, "postfix_expression_9", 4, (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 3259 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 352 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( postfix_expression+10, "postfix_expression_10", 4, (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 3265 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 353 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ handle_parse_warning( "Templates are not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); (yyval) = pt_generate_node( postfix_expression+12, "postfix_expression_12", 5, (yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 3271 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 354 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ handle_parse_warning( "Templates are not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); (yyval) = pt_generate_node( postfix_expression+13, "postfix_expression_13", 4, (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 3277 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 355 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ handle_parse_warning( ":: is not a supported feature in this context in 120++ specs.", W_PARSE_UNSUPPORTED ); (yyval) = pt_generate_node( postfix_expression+14, "postfix_expression_14", 4, (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 3283 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 356 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( postfix_expression+15, "postfix_expression_15", 3, (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 3289 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 357 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ handle_parse_warning( "Templates are not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); (yyval) = pt_generate_node( postfix_expression+16, "postfix_expression_16", 5, (yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 3295 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 358 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ handle_parse_warning( "Templates are not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); (yyval) = pt_generate_node( postfix_expression+17, "postfix_expression_17", 4, (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 3301 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 359 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ handle_parse_warning( ":: is not a supported feature in this context in 120++ specs.", W_PARSE_UNSUPPORTED ); (yyval) = pt_generate_node( postfix_expression+18, "postfix_expression_18", 4, (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 3307 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 360 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( postfix_expression+19, "postfix_expression_19", 3, (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 3313 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 361 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( postfix_expression+20, "postfix_expression_20", 2, (yyvsp[-1]), (yyvsp[0]) ); }
#line 3319 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 362 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( postfix_expression+21, "postfix_expression_21", 2, (yyvsp[-1]), (yyvsp[0]) ); }
#line 3325 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 363 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ handle_parse_warning( "dynamic_cast is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); (yyval) = pt_generate_node( postfix_expression+22, "postfix_expression_22", 7, (yyvsp[-6]), (yyvsp[-5]), (yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 3331 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 364 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ handle_parse_warning( "static_cast is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); (yyval) = pt_generate_node( postfix_expression+23, "postfix_expression_23", 7, (yyvsp[-6]), (yyvsp[-5]), (yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 3337 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 365 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ handle_parse_warning( "reinterpret_cast is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); (yyval) = pt_generate_node( postfix_expression+24, "postfix_expression_24", 7, (yyvsp[-6]), (yyvsp[-5]), (yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 3343 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 366 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ handle_parse_warning( "const_cast is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); (yyval) = pt_generate_node( postfix_expression+25, "postfix_expression_25", 7, (yyvsp[-6]), (yyvsp[-5]), (yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 3349 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 367 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ handle_parse_warning( "typeid is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); (yyval) = pt_generate_node( postfix_expression+26, "postfix_expression_26", 4, (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 3355 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 368 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ handle_parse_warning( "typeid is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); (yyval) = pt_generate_node( postfix_expression+27, "postfix_expression_27", 4, (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 3361 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 372 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( unary_expression+1, "unary_expression_1", 1, (yyvsp[0]) ); }
#line 3367 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 373 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( unary_expression+2, "unary_expression_2", 2, (yyvsp[-1]), (yyvsp[0]) ); }
#line 3373 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 374 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( unary_expression+3, "unary_expression_3", 2, (yyvsp[-1]), (yyvsp[0]) ); }
#line 3379 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 375 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( unary_expression+4, "unary_expression_4", 2, (yyvsp[-1]), (yyvsp[0]) ); }
#line 3385 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 376 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( unary_expression+5, "unary_expression_5", 2, (yyvsp[-1]), (yyvsp[0]) ); }
#line 3391 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 377 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( unary_expression+6, "unary_expression_6", 2, (yyvsp[-1]), (yyvsp[0]) ); }
#line 3397 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 378 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( unary_expression+7, "unary_expression_7", 2, (yyvsp[-1]), (yyvsp[0]) ); }
#line 3403 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 379 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( unary_expression+8, "unary_expression_8", 4, (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 3409 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 380 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( unary_expression+9, "unary_expression_9", 1, (yyvsp[0]) ); }
#line 3415 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 381 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( unary_expression+10, "unary_expression_10", 1, (yyvsp[0]) ); }
#line 3421 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 385 "120++parse.y" /* yacc.c:1646  */
    { yylval->production = unary_operator+1; (yyval) = (yyvsp[0]); }
#line 3427 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 386 "120++parse.y" /* yacc.c:1646  */
    { yylval->production = unary_operator+2; (yyval) = (yyvsp[0]); }
#line 3433 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 387 "120++parse.y" /* yacc.c:1646  */
    { yylval->production = unary_operator+3; (yyval) = (yyvsp[0]); }
#line 3439 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 388 "120++parse.y" /* yacc.c:1646  */
    { yylval->production = unary_operator+4; (yyval) = (yyvsp[0]); }
#line 3445 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 392 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( new_expression+1, "new_expression_1", 4, (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 3451 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 393 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ handle_parse_warning( "This usage of new is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); (yyval) = pt_generate_node( new_expression+2, "new_expression_2", 5, (yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 3457 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 394 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( new_expression+3, "new_expression_3", 6, (yyvsp[-5]), (yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 3463 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 395 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ handle_parse_warning( "This usage of new is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); (yyval) = pt_generate_node( new_expression+4, "new_expression_4", 7, (yyvsp[-6]), (yyvsp[-5]), (yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 3469 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 399 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( new_placement, "new_placement", 3, (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 3475 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 403 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( new_type_id, "new_type_id", 2, (yyvsp[-1]), (yyvsp[0]) ); }
#line 3481 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 407 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( new_declarator+1, "new_declarator_1", 2, (yyvsp[-1]), (yyvsp[0]) ); }
#line 3487 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 408 "120++parse.y" /* yacc.c:1646  */
    { /* ?Not 120++? */ (yyval) = pt_generate_node( new_declarator+2, "new_declarator_2", 1, (yyvsp[0]) ); }
#line 3493 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 412 "120++parse.y" /* yacc.c:1646  */
    { /* ?Not 120++? */ /* Warned above */ (yyval) = pt_generate_node( direct_new_declarator+1, "direct_new_declarator_1", 3, (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 3499 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 413 "120++parse.y" /* yacc.c:1646  */
    { /* ?Not 120++? */ /* Warned above */ (yyval) = pt_generate_node( direct_new_declarator+2, "direct_new_declarator_2", 4, (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 3505 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 417 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( new_initializer, "new_initializer", 3, (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 3511 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 421 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( delete_expression+1, "delete_expression_1", 2, (yyvsp[-1]), (yyvsp[0]) ); }
#line 3517 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 422 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ handle_parse_warning( "This usage of delete is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); (yyval) = pt_generate_node( delete_expression+2, "delete_expression_2", 3, (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 3523 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 423 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( delete_expression+3, "delete_expression_3", 4, (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 3529 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 424 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ handle_parse_warning( "This usage of delete is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); (yyval) = pt_generate_node( delete_expression+4, "delete_expression_4", 5, (yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 3535 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 428 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( cast_expression+1, "cast_expression_1", 1, (yyvsp[0]) ); }
#line 3541 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 429 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( cast_expression+2, "cast_expression_2", 4, (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 3547 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 433 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( pm_expression+1, "pm_expression_1", 1, (yyvsp[0]) ); }
#line 3553 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 434 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ handle_parse_warning( "Pointer-to-member operators are not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); (yyval) = pt_generate_node( pm_expression+2, "pm_expression_2", 3, (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 3559 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 435 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ handle_parse_warning( "Pointer-to-member operators are not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); (yyval) = pt_generate_node( pm_expression+3, "pm_expression_3", 3, (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 3565 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 439 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( multiplicative_expression+1, "multiplicative_expression_1", 1, (yyvsp[0]) ); }
#line 3571 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 440 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( multiplicative_expression+2, "multiplicative_expression_2", 3, (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 3577 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 441 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( multiplicative_expression+3, "multiplicative_expression_3", 3, (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 3583 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 442 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( multiplicative_expression+4, "multiplicative_expression_4", 3, (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 3589 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 446 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( additive_expression+1, "additive_expression_1", 1, (yyvsp[0]) ); }
#line 3595 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 447 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( additive_expression+2, "additive_expression_2", 3, (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 3601 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 448 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( additive_expression+3, "additive_expression_3", 3, (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 3607 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 452 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( shift_expression+1, "shift_expression_1", 1, (yyvsp[0]) ); }
#line 3613 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 453 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Might be overloaded for cout, but still warned */ handle_parse_warning( "Shift operators are not supported in 120++ specs. (If using them as the stream operator for cout, ignore this warning.)", W_PARSE_UNSUPPORTED ); (yyval) = pt_generate_node( shift_expression+2, "shift_expression_2", 3, (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 3619 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 454 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Might be overloaded for cin, but still warned */ handle_parse_warning( "Shift operators are not supported in 120++ specs. (If using them as the stream operator for cin, ignore this warning.)", W_PARSE_UNSUPPORTED ); (yyval) = pt_generate_node( shift_expression+3, "shift_expression_3", 3, (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 3625 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 458 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( relational_expression+1, "relational_expression_1", 1, (yyvsp[0]) ); }
#line 3631 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 159:
#line 459 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( relational_expression+2, "relational_expression_2", 3, (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 3637 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 460 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( relational_expression+3, "relational_expression_3", 3, (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 3643 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 461 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( relational_expression+4, "relational_expression_4", 3, (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 3649 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 462 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( relational_expression+5, "relational_expression_5", 3, (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 3655 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 466 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( equality_expression+1, "equality_expression_1", 1, (yyvsp[0]) ); }
#line 3661 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 467 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( equality_expression+2, "equality_expression_2", 3, (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 3667 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 468 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( equality_expression+3, "equality_expression_3", 3, (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 3673 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 166:
#line 472 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( and_expression+1, "and_expression_1", 1, (yyvsp[0]) ); }
#line 3679 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 167:
#line 473 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ handle_parse_warning( "Bitwise operators are not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); (yyval) = pt_generate_node( and_expression+2, "and_expression_2", 3, (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 3685 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 168:
#line 477 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( exclusive_or_expression+1, "exclusive_or_expression_1", 1, (yyvsp[0]) ); }
#line 3691 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 169:
#line 478 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ handle_parse_warning( "Bitwise operators are not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); (yyval) = pt_generate_node( exclusive_or_expression+2, "exclusive_or_expression_2", 3, (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 3697 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 170:
#line 482 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( inclusive_or_expression+1, "inclusive_or_expression_1", 1, (yyvsp[0]) ); }
#line 3703 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 171:
#line 483 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ handle_parse_warning( "Bitwise operators are not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); (yyval) = pt_generate_node( inclusive_or_expression+2, "inclusive_or_expression_2", 3, (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 3709 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 172:
#line 487 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( logical_and_expression+1, "logical_and_expression_1", 1, (yyvsp[0]) ); }
#line 3715 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 173:
#line 488 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( logical_and_expression+2, "logical_and_expression_2", 3, (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 3721 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 492 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( logical_or_expression+1, "logical_or_expression_1", 1, (yyvsp[0]) ); }
#line 3727 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 175:
#line 493 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( logical_or_expression+2, "logical_or_expression_2", 3, (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 3733 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 176:
#line 497 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( conditional_expression+1, "conditional_expression_1", 1, (yyvsp[0]) ); }
#line 3739 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 177:
#line 498 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( conditional_expression+2, "conditional_expression_2", 5, (yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 3745 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 502 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( constant_expression, "constant_expression", 1, (yyvsp[0]) ); }
#line 3751 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 506 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( assignment_expression+1, "assignment_expression_1", 1, (yyvsp[0]) ); }
#line 3757 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 180:
#line 507 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( assignment_expression+2, "assignment_expression_2", 3, (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 3763 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 508 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned below */ (yyval) = pt_generate_node( assignment_expression+3, "assignment_expression_3", 1, (yyvsp[0]) ); }
#line 3769 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 182:
#line 512 "120++parse.y" /* yacc.c:1646  */
    { yylval->production = assignment_operator+1; (yyval) = (yyvsp[0]); }
#line 3775 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 183:
#line 513 "120++parse.y" /* yacc.c:1646  */
    { yylval->production = assignment_operator+2; (yyval) = (yyvsp[0]); }
#line 3781 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 184:
#line 514 "120++parse.y" /* yacc.c:1646  */
    { yylval->production = assignment_operator+3; (yyval) = (yyvsp[0]); }
#line 3787 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 185:
#line 515 "120++parse.y" /* yacc.c:1646  */
    { yylval->production = assignment_operator+4; (yyval) = (yyvsp[0]); }
#line 3793 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 186:
#line 516 "120++parse.y" /* yacc.c:1646  */
    { yylval->production = assignment_operator+5; (yyval) = (yyvsp[0]); }
#line 3799 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 187:
#line 517 "120++parse.y" /* yacc.c:1646  */
    { yylval->production = assignment_operator+6; (yyval) = (yyvsp[0]); }
#line 3805 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 188:
#line 518 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ handle_parse_warning( "Operator is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); yylval->production = assignment_operator+7; (yyval) = (yyvsp[0]); }
#line 3811 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 189:
#line 519 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ handle_parse_warning( "Operator is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); yylval->production = assignment_operator+8; (yyval) = (yyvsp[0]); }
#line 3817 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 190:
#line 520 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ handle_parse_warning( "Operator is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); yylval->production = assignment_operator+9; (yyval) = (yyvsp[0]); }
#line 3823 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 191:
#line 521 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ handle_parse_warning( "Operator is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); yylval->production = assignment_operator+10; (yyval) = (yyvsp[0]); }
#line 3829 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 192:
#line 522 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ handle_parse_warning( "Operator is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); yylval->production = assignment_operator+11; (yyval) = (yyvsp[0]); }
#line 3835 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 193:
#line 526 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( expression_list+1, "expression_list_1", 1, (yyvsp[0]) ); }
#line 3841 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 194:
#line 527 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( expression_list+2, "expression_list_2", 3, (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 3847 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 195:
#line 535 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( statement+1, "statement_1", 1, (yyvsp[0]) ); }
#line 3853 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 196:
#line 536 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( statement+2, "statement_2", 1, (yyvsp[0]) ); }
#line 3859 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 197:
#line 537 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( statement+3, "statement_3", 1, (yyvsp[0]) ); }
#line 3865 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 198:
#line 538 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( statement+4, "statement_4", 1, (yyvsp[0]) ); }
#line 3871 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 199:
#line 539 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( statement+5, "statement_5", 1, (yyvsp[0]) ); }
#line 3877 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 200:
#line 540 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( statement+6, "statement_6", 1, (yyvsp[0]) ); }
#line 3883 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 201:
#line 541 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( statement+7, "statement_7", 1, (yyvsp[0]) ); }
#line 3889 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 202:
#line 542 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned below */ (yyval) = pt_generate_node( statement+8, "statement_8", 1, (yyvsp[0]) ); }
#line 3895 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 203:
#line 546 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ handle_parse_warning( "This labeled statement syntax is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); (yyval) = pt_generate_node( labeled_statement+1, "labeled_statement_1", 3, (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 3901 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 204:
#line 547 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( labeled_statement+2, "labeled_statement_2", 4, (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 3907 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 205:
#line 548 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( labeled_statement+3, "labeled_statement_3", 3, (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 3913 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 206:
#line 552 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( expression_statement, "expression_statement", 2, (yyvsp[-1]), (yyvsp[0]) ); }
#line 3919 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 207:
#line 556 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( compound_statement, "compound_statement", 3, (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 3925 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 208:
#line 560 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( statement_seq+1, "statement_seq_1", 1, (yyvsp[0]) ); }
#line 3931 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 209:
#line 561 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( statement_seq+2, "statement_seq_2", 2, (yyvsp[-1]), (yyvsp[0]) ); }
#line 3937 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 210:
#line 565 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( selection_statement+1, "selection_statement_1", 5, (yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 3943 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 211:
#line 566 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( selection_statement+2, "selection_statement_2", 7, (yyvsp[-6]), (yyvsp[-5]), (yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 3949 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 212:
#line 567 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( selection_statement+3, "selection_statement_3", 5, (yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 3955 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 213:
#line 571 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( condition+1, "condition_1", 1, (yyvsp[0]) ); }
#line 3961 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 214:
#line 572 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( condition+2, "condition_2", 4, (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 3967 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 215:
#line 576 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( iteration_statement+1, "iteration_statement_1", 5, (yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 3973 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 216:
#line 577 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( iteration_statement+2, "iteration_statement_2", 7, (yyvsp[-6]), (yyvsp[-5]), (yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 3979 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 217:
#line 578 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( iteration_statement+3, "iteration_statement_3", 8, (yyvsp[-7]), (yyvsp[-6]), (yyvsp[-5]), (yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 3985 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 218:
#line 582 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( for_init_statement+1, "for_init_statement_1", 1, (yyvsp[0]) ); }
#line 3991 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 219:
#line 583 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( for_init_statement+2, "for_init_statement_2", 1, (yyvsp[0]) ); }
#line 3997 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 220:
#line 587 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( jump_statement+1, "jump_statement_1", 2, (yyvsp[-1]), (yyvsp[0]) ); }
#line 4003 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 221:
#line 588 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( jump_statement+2, "jump_statement_2", 2, (yyvsp[-1]), (yyvsp[0]) ); }
#line 4009 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 222:
#line 589 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( jump_statement+3, "jump_statement_3", 3, (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 4015 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 223:
#line 590 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ handle_parse_warning( "goto is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); (yyval) = pt_generate_node( jump_statement+4, "jump_statement_4", 3, (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 4021 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 224:
#line 594 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( declaration_statement, "declaration_statement", 1, (yyvsp[0]) ); }
#line 4027 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 225:
#line 602 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( declaration_seq+1, "declaration_seq_1", 1, (yyvsp[0]) ); }
#line 4033 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 226:
#line 603 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( declaration_seq+2, "declaration_seq_2", 2, (yyvsp[-1]), (yyvsp[0]) ); }
#line 4039 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 227:
#line 607 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( declaration+1, "declaration_1", 1, (yyvsp[0]) ); }
#line 4045 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 228:
#line 608 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( declaration+2, "declaration_2", 1, (yyvsp[0]) ); }
#line 4051 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 229:
#line 609 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned below */ (yyval) = pt_generate_node( declaration+3, "declaration_3", 1, (yyvsp[0]) ); }
#line 4057 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 230:
#line 610 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned below */ (yyval) = pt_generate_node( declaration+4, "declaration_4", 1, (yyvsp[0]) ); }
#line 4063 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 231:
#line 611 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned below */ (yyval) = pt_generate_node( declaration+5, "declaration_5", 1, (yyvsp[0]) ); }
#line 4069 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 232:
#line 612 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned below */ (yyval) = pt_generate_node( declaration+6, "declaration_6", 1, (yyvsp[0]) ); }
#line 4075 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 233:
#line 613 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned below */ (yyval) = pt_generate_node( declaration+7, "declaration_7", 1, (yyvsp[0]) ); }
#line 4081 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 234:
#line 617 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( block_declaration+1, "block_declaration_1", 1, (yyvsp[0]) ); }
#line 4087 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 235:
#line 618 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned below */ (yyval) = pt_generate_node( block_declaration+2, "block_declaration_2", 1, (yyvsp[0]) ); }
#line 4093 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 236:
#line 619 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned below */ (yyval) = pt_generate_node( block_declaration+3, "block_declaration_3", 1, (yyvsp[0]) ); }
#line 4099 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 237:
#line 620 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ handle_parse_warning( "This usage of using is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); (yyval) = pt_generate_node( block_declaration+4, "block_declaration_4", 1, (yyvsp[0]) ); }
#line 4105 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 238:
#line 621 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( block_declaration+5, "block_declaration_5", 1, (yyvsp[0]) ); }
#line 4111 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 239:
#line 625 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( simple_declaration+1, "simple_declaration_1", 3, (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 4117 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 240:
#line 626 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( simple_declaration+2, "simple_declaration_2", 2, (yyvsp[-1]), (yyvsp[0]) ); }
#line 4123 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 241:
#line 630 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned below */ (yyval) = pt_generate_node( decl_specifier+1, "decl_specifier_1", 1, (yyvsp[0]) ); }
#line 4129 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 242:
#line 631 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( decl_specifier+2, "decl_specifier_2", 1, (yyvsp[0]) ); }
#line 4135 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 243:
#line 632 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned below */ (yyval) = pt_generate_node( decl_specifier+3, "decl_specifier_3", 1, (yyvsp[0]) ); }
#line 4141 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 244:
#line 633 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ handle_parse_warning( "friend is not supported in 120++ specs.", W_PARSE_UNHANDLED ); (yyval) = NULL; }
#line 4147 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 245:
#line 634 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ handle_parse_warning( "typedef is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); yylval->production = decl_specifier+5; (yyval) = (yyvsp[0]); }
#line 4153 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 246:
#line 638 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( decl_specifier_seq+1, "decl_specifier_seq_1", 1, (yyvsp[0]) ); }
#line 4159 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 247:
#line 639 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( decl_specifier_seq+2, "decl_specifier_seq_2", 2, (yyvsp[-1]), (yyvsp[0]) ); }
#line 4165 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 248:
#line 643 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ handle_parse_warning( "auto is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); yylval->production = storage_class_specifier+1; (yyval) = (yyvsp[0]); }
#line 4171 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 249:
#line 644 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ handle_parse_warning( "register is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); yylval->production = storage_class_specifier+2; (yyval) = (yyvsp[0]); }
#line 4177 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 250:
#line 645 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ handle_parse_warning( "static is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); yylval->production = storage_class_specifier+3; (yyval) = (yyvsp[0]); }
#line 4183 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 251:
#line 646 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ handle_parse_warning( "extern is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); yylval->production = storage_class_specifier+4; (yyval) = (yyvsp[0]); }
#line 4189 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 252:
#line 647 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ handle_parse_warning( "mutable is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); yylval->production = storage_class_specifier+5; (yyval) = (yyvsp[0]); }
#line 4195 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 253:
#line 651 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ handle_parse_warning( "inline is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); yylval->production = function_specifier+1; (yyval) = (yyvsp[0]); }
#line 4201 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 254:
#line 652 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ handle_parse_warning( "virtual is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); yylval->production = function_specifier+2; (yyval) = (yyvsp[0]); }
#line 4207 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 255:
#line 653 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ handle_parse_warning( "explicit is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); yylval->production = function_specifier+3; (yyval) = (yyvsp[0]); }
#line 4213 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 256:
#line 657 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( type_specifier+1, "type_specifier_1", 1, (yyvsp[0]) ); }
#line 4219 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 257:
#line 658 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( type_specifier+2, "type_specifier_2", 1, (yyvsp[0]) ); }
#line 4225 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 258:
#line 659 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ handle_parse_warning( "enum is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); (yyval) = pt_generate_node( type_specifier+3, "type_specifier_3", 1, (yyvsp[0]) ); }
#line 4231 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 259:
#line 660 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ handle_parse_warning( "Elaborated type specifiers are not supported in 120++ specs.", W_PARSE_UNHANDLED ); (yyval) = NULL; }
#line 4237 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 260:
#line 661 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( type_specifier+5, "type_specifier_5", 1, (yyvsp[0]) ); }
#line 4243 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 261:
#line 665 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( simple_type_specifier+1, "simple_type_specifier_1", 1, (yyvsp[0]) ); }
#line 4249 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 262:
#line 666 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( simple_type_specifier+2, "simple_type_specifier_2", 2, (yyvsp[-1]), (yyvsp[0]) ); }
#line 4255 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 263:
#line 667 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( simple_type_specifier+3, "simple_type_specifier_3", 3, (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 4261 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 264:
#line 668 "120++parse.y" /* yacc.c:1646  */
    { yylval->production = simple_type_specifier+4; (yyval) = (yyvsp[0]); }
#line 4267 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 265:
#line 669 "120++parse.y" /* yacc.c:1646  */
    { yylval->production = simple_type_specifier+5; (yyval) = (yyvsp[0]); }
#line 4273 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 266:
#line 670 "120++parse.y" /* yacc.c:1646  */
    { yylval->production = simple_type_specifier+6; (yyval) = (yyvsp[0]); }
#line 4279 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 267:
#line 671 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ handle_parse_warning( "char16_t is not supported in 120++ specs.", W_PARSE_UNSUPPORTED );yylval->production = simple_type_specifier+7; (yyval) = (yyvsp[0]); }
#line 4285 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 268:
#line 672 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ handle_parse_warning( "char32_t is not supported in 120++ specs.", W_PARSE_UNSUPPORTED );yylval->production = simple_type_specifier+8; (yyval) = (yyvsp[0]); }
#line 4291 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 269:
#line 673 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ handle_parse_warning( "wchar_t is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); yylval->production = simple_type_specifier+9; (yyval) = (yyvsp[0]); }
#line 4297 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 270:
#line 674 "120++parse.y" /* yacc.c:1646  */
    { yylval->production = simple_type_specifier+10; (yyval) = (yyvsp[0]); }
#line 4303 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 271:
#line 675 "120++parse.y" /* yacc.c:1646  */
    { yylval->production = simple_type_specifier+11; (yyval) = (yyvsp[0]); }
#line 4309 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 272:
#line 676 "120++parse.y" /* yacc.c:1646  */
    { yylval->production = simple_type_specifier+12; (yyval) = (yyvsp[0]); }
#line 4315 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 273:
#line 677 "120++parse.y" /* yacc.c:1646  */
    { yylval->production = simple_type_specifier+13; (yyval) = (yyvsp[0]); }
#line 4321 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 274:
#line 678 "120++parse.y" /* yacc.c:1646  */
    { yylval->production = simple_type_specifier+14; (yyval) = (yyvsp[0]); }
#line 4327 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 275:
#line 679 "120++parse.y" /* yacc.c:1646  */
    { yylval->production = simple_type_specifier+15; (yyval) = (yyvsp[0]); }
#line 4333 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 276:
#line 680 "120++parse.y" /* yacc.c:1646  */
    { yylval->production = simple_type_specifier+16; (yyval) = (yyvsp[0]); }
#line 4339 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 277:
#line 684 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( type_name+1, "type_name_1", 1, (yyvsp[0]) ); }
#line 4345 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 278:
#line 685 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( type_name+2, "type_name_2", 1, (yyvsp[0]) ); }
#line 4351 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 279:
#line 686 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( type_name+3, "type_name_3", 1, (yyvsp[0]) ); }
#line 4357 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 280:
#line 690 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned above */ (yyval) = pt_generate_node( elaborated_type_specifier+1, "elaborated_type_specifier_1", 4, (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 4363 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 281:
#line 691 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned above */ (yyval) = pt_generate_node( elaborated_type_specifier+2, "elaborated_type_specifier_2", 3, (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 4369 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 282:
#line 692 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned above */ (yyval) = pt_generate_node( elaborated_type_specifier+3, "elaborated_type_specifier_3", 4, (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 4375 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 283:
#line 693 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned above */ (yyval) = pt_generate_node( elaborated_type_specifier+4, "elaborated_type_specifier_4", 3, (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 4381 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 284:
#line 694 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned above */ (yyval) = pt_generate_node( elaborated_type_specifier+5, "elaborated_type_specifier_5", 3, (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 4387 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 285:
#line 695 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned above */ (yyval) = pt_generate_node( elaborated_type_specifier+6, "elaborated_type_specifier_6", 4, (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 4393 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 286:
#line 696 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned above */ handle_parse_warning( "Template features are not supported in 120++ specs.", W_PARSE_UNHANDLED ); (yyval) = pt_generate_node( elaborated_type_specifier+7, "elaborated_type_specifier_7", 7, (yyvsp[-6]), (yyvsp[-5]), (yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 4399 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 287:
#line 700 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned above */ (yyval) = pt_generate_node( enum_specifier, "enum_specifier", 5, (yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 4405 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 288:
#line 704 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned above */ (yyval) = pt_generate_node( enumerator_list+1, "enumerator_list_1", 1, (yyvsp[0]) ); }
#line 4411 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 289:
#line 705 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned above */ (yyval) = pt_generate_node( enumerator_list+2, "enumerator_list_2", 3, (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 4417 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 290:
#line 709 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned above */ (yyval) = pt_generate_node( enumerator_definition+1, "enumerator_definition_1", 1, (yyvsp[0]) ); }
#line 4423 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 291:
#line 710 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned above */ (yyval) = pt_generate_node( enumerator_definition+2, "enumerator_definition_2", 3, (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 4429 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 292:
#line 714 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned above */ (yyval) = pt_generate_node( enumerator, "enumerator", 1, (yyvsp[0]) ); }
#line 4435 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 293:
#line 718 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ handle_parse_warning( "Namespaces (except for std) are not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); (yyval) = pt_generate_node( namespace_definition+1, "namespace_definition_1", 1, (yyvsp[0]) ); }
#line 4441 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 294:
#line 719 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ handle_parse_warning( "Namespaces (except for std) are not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); (yyval) = pt_generate_node( namespace_definition+2, "namespace_definition_2", 1, (yyvsp[0]) ); }
#line 4447 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 295:
#line 723 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned above */ (yyval) = pt_generate_node( named_namespace_definition+1, "named_namespace_definition_1", 1, (yyvsp[0]) ); }
#line 4453 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 296:
#line 724 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned above */ (yyval) = pt_generate_node( named_namespace_definition+2, "named_namespace_definition_2", 1, (yyvsp[0]) ); }
#line 4459 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 297:
#line 728 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned above */ (yyval) = pt_generate_node( original_namespace_definition, "original_namespace_definition", 5, (yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 4465 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 298:
#line 732 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned above */ (yyval) = pt_generate_node( extension_namespace_definition, "extension_namespace_definition", 5, (yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 4471 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 299:
#line 736 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned above */ (yyval) = pt_generate_node( unnamed_namespace_definition, "unnamed_namespace_definition", 4, (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 4477 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 300:
#line 740 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned above */ (yyval) = pt_generate_node( namespace_body, "namespace_body", 1, (yyvsp[0]) ); }
#line 4483 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 301:
#line 744 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ handle_parse_warning( "Namespaces (except for std) are not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); (yyval) = pt_generate_node( namespace_alias_definition, "namespace_alias_definition", 5, (yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 4489 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 302:
#line 748 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned above */ (yyval) = pt_generate_node( qualified_namespace_specifier+1, "qualified_namespace_specifier_1", 3, (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 4495 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 303:
#line 749 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned above */ (yyval) = pt_generate_node( qualified_namespace_specifier+2, "qualified_namespace_specifier_2", 2, (yyvsp[-1]), (yyvsp[0]) ); }
#line 4501 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 304:
#line 750 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned above */ (yyval) = pt_generate_node( qualified_namespace_specifier+3, "qualified_namespace_specifier_3", 2, (yyvsp[-1]), (yyvsp[0]) ); }
#line 4507 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 305:
#line 751 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned above */ (yyval) = pt_generate_node( qualified_namespace_specifier+4, "qualified_namespace_specifier_4", 1, (yyvsp[0]) ); }
#line 4513 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 306:
#line 755 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned above */ (yyval) = pt_generate_node( using_declaration+1, "using_declaration_1", 6, (yyvsp[-5]), (yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 4519 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 307:
#line 756 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned above */ (yyval) = pt_generate_node( using_declaration+2, "using_declaration_2", 5, (yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 4525 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 308:
#line 757 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned above */ (yyval) = pt_generate_node( using_declaration+3, "using_declaration_3", 5, (yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 4531 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 309:
#line 758 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned above */ (yyval) = pt_generate_node( using_declaration+4, "using_declaration_4", 4, (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 4537 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 310:
#line 759 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned above */ (yyval) = pt_generate_node( using_declaration+5, "using_declaration_5", 4, (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 4543 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 311:
#line 763 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ handle_parse_warning( "This usage of using is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); (yyval) = pt_generate_node( using_directive+1, "using_directive_1", 6, (yyvsp[-5]), (yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 4549 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 312:
#line 764 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ handle_parse_warning( "This usage of using is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); (yyval) = pt_generate_node( using_directive+2, "using_directive_2", 5, (yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 4555 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 313:
#line 765 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ handle_parse_warning( "This usage of using is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); (yyval) = pt_generate_node( using_directive+3, "using_directive_3", 5, (yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 4561 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 314:
#line 766 "120++parse.y" /* yacc.c:1646  */
    { handle_parse_warning( "120++ specs only support usage of the namespace std.", W_PARSE_UNSUPPORTED ); (yyval) = pt_generate_node( using_directive+4, "using_directive_4", 4, (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 4567 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 315:
#line 770 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ handle_parse_warning( "asm is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); (yyval) = pt_generate_node( asm_definition, "asm_definition", 5, (yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 4573 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 316:
#line 774 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ handle_parse_warning( "extern is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); (yyval) = pt_generate_node( linkage_specification+1, "linkage_specification_1", 5, (yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 4579 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 317:
#line 775 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ handle_parse_warning( "extern is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); (yyval) = pt_generate_node( linkage_specification+2, "linkage_specification_2", 3, (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 4585 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 318:
#line 783 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( init_declarator_list+1, "init_declarator_list_1", 1, (yyvsp[0]) ); }
#line 4591 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 319:
#line 784 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( init_declarator_list+2, "init_declarator_list_2", 3, (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 4597 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 320:
#line 788 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( init_declarator, "init_declarator", 2, (yyvsp[-1]), (yyvsp[0]) ); }
#line 4603 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 321:
#line 792 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( declarator+1, "declarator_1", 1, (yyvsp[0]) ); }
#line 4609 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 322:
#line 793 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( declarator+2, "declarator_2", 2, (yyvsp[-1]), (yyvsp[0]) ); }
#line 4615 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 323:
#line 797 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( direct_declarator+1, "direct_declarator_1", 1, (yyvsp[0]) ); }
#line 4621 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 324:
#line 798 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned below */ (yyval) = pt_generate_node( direct_declarator+2, "direct_declarator_2", 6, (yyvsp[-5]), (yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 4627 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 325:
#line 799 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( direct_declarator+3, "direct_declarator_3", 5, (yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 4633 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 326:
#line 800 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned below */ (yyval) = pt_generate_node( direct_declarator+4, "direct_declarator_4", 5, (yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 4639 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 327:
#line 801 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( direct_declarator+5, "direct_declarator_5", 4, (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 4645 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 328:
#line 802 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( direct_declarator+6, "direct_declarator_6", 4, (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 4651 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 329:
#line 803 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( direct_declarator+7, "direct_declarator_7", 6, (yyvsp[-5]), (yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 4657 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 330:
#line 804 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( direct_declarator+8, "direct_declarator_8", 6, (yyvsp[-5]), (yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 4663 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 331:
#line 805 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( direct_declarator+9, "direct_declarator_9", 4, (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 4669 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 332:
#line 806 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( direct_declarator+10, "direct_declarator_10", 3, (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 4675 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 333:
#line 810 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( ptr_operator+1, "ptr_operator_1", 1, (yyvsp[0]) ); }
#line 4681 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 334:
#line 811 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( ptr_operator+2, "ptr_operator_2", 2, (yyvsp[-1]), (yyvsp[0]) ); }
#line 4687 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 335:
#line 812 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( ptr_operator+3, "ptr_operator_3", 1, (yyvsp[0]) ); }
#line 4693 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 336:
#line 813 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( ptr_operator+4, "ptr_operator_4", 2, (yyvsp[-1]), (yyvsp[0]) ); }
#line 4699 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 337:
#line 814 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( ptr_operator+5, "ptr_operator_5", 3, (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 4705 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 338:
#line 815 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ handle_parse_warning( "This usage of :: is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); (yyval) = pt_generate_node( ptr_operator+6, "ptr_operator_6", 3, (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 4711 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 339:
#line 816 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ handle_parse_warning( "This usage of :: is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); (yyval) = pt_generate_node( ptr_operator+7, "ptr_operator_7", 4, (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 4717 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 340:
#line 820 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( cv_qualifier_seq+1, "cv_qualifier_seq_1", 1, (yyvsp[0]) ); }
#line 4723 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 341:
#line 821 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( cv_qualifier_seq+2, "cv_qualifier_seq_2", 2, (yyvsp[-1]), (yyvsp[0]) ); }
#line 4729 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 342:
#line 825 "120++parse.y" /* yacc.c:1646  */
    { yylval->production = cv_qualifier+1; (yyval) = (yyvsp[0]); }
#line 4735 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 343:
#line 826 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ handle_parse_warning( "volatile is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); yylval->production = cv_qualifier+2; (yyval) = (yyvsp[0]); }
#line 4741 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 344:
#line 830 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( declarator_id+1, "declarator_id_1", 1, (yyvsp[0]) ); }
#line 4747 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 345:
#line 831 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ handle_parse_warning( "This usage of :: is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); (yyval) = pt_generate_node( declarator_id+2, "declarator_id_2", 2, (yyvsp[-1]), (yyvsp[0]) ); }
#line 4753 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 346:
#line 832 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ (yyval) = pt_generate_node( declarator_id+3, "declarator_id_3", 3, (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 4759 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 347:
#line 833 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ handle_parse_warning( "This usage of :: is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); (yyval) = pt_generate_node( declarator_id+4, "declarator_id_4", 2, (yyvsp[-1]), (yyvsp[0]) ); }
#line 4765 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 348:
#line 837 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( type_id, "type_id", 2, (yyvsp[-1]), (yyvsp[0]) ); }
#line 4771 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 349:
#line 841 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( type_specifier_seq, "type_specifier_seq", 2, (yyvsp[-1]), (yyvsp[0]) ); }
#line 4777 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 350:
#line 845 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( abstract_declarator+1, "abstract_declarator_1", 2, (yyvsp[-1]), (yyvsp[0]) ); }
#line 4783 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 351:
#line 846 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( abstract_declarator+2, "abstract_declarator_2", 1, (yyvsp[0]) ); }
#line 4789 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 352:
#line 850 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned below */ (yyval) = pt_generate_node( direct_abstract_declarator+1, "direct_abstract_declarator_1", 6, (yyvsp[-5]), (yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 4795 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 353:
#line 851 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( direct_abstract_declarator+2, "direct_abstract_declarator_2", 5, (yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 4801 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 354:
#line 852 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned below */ (yyval) = pt_generate_node( direct_abstract_declarator+3, "direct_abstract_declarator_3", 5, (yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 4807 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 355:
#line 853 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( direct_abstract_declarator+4, "direct_abstract_declarator_4", 4, (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 4813 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 356:
#line 854 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( direct_abstract_declarator+5, "direct_abstract_declarator_5", 4, (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 4819 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 357:
#line 855 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( direct_abstract_declarator+6, "direct_abstract_declarator_6", 3, (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 4825 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 358:
#line 859 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ handle_parse_warning( "Variable arguments (ellipsis) is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); (yyval) = pt_generate_node( parameter_declaration_clause+1, "parameter_declaration_clause_1", 2, (yyvsp[-1]), (yyvsp[0]) ); }
#line 4831 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 359:
#line 860 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ handle_parse_warning( "Variable arguments (ellipsis) is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); (yyval) = pt_generate_node( parameter_declaration_clause+2, "parameter_declaration_clause_2", 3, (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 4837 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 360:
#line 861 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( parameter_declaration_clause+3, "parameter_declaration_clause_3", 1, (yyvsp[0]) ); }
#line 4843 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 361:
#line 862 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ handle_parse_warning( "Variable arguments (ellipsis) is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); (yyval) = pt_generate_node( parameter_declaration_clause+4, "parameter_declaration_clause_4", 1, (yyvsp[0]) ); }
#line 4849 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 362:
#line 866 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( parameter_declaration_list+1, "parameter_declaration_list_1", 1, (yyvsp[0]) ); }
#line 4855 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 363:
#line 867 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( parameter_declaration_list+2, "parameter_declaration_list_2", 3, (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 4861 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 364:
#line 871 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( parameter_declaration+1, "parameter_declaration_1", 2, (yyvsp[-1]), (yyvsp[0]) ); }
#line 4867 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 365:
#line 872 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( parameter_declaration+2, "parameter_declaration_2", 4, (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 4873 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 366:
#line 873 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( parameter_declaration+3, "parameter_declaration_3", 2, (yyvsp[-1]), (yyvsp[0]) ); }
#line 4879 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 367:
#line 874 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( parameter_declaration+4, "parameter_declaration_4", 4, (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 4885 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 368:
#line 878 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( function_definition+1, "function_definition_1", 3, (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 4891 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 369:
#line 879 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( function_definition+2, "function_definition_2", 4, (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 4897 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 370:
#line 880 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned below */ (yyval) = pt_generate_node( function_definition+3, "function_definition_3", 2, (yyvsp[-1]), (yyvsp[0]) ); }
#line 4903 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 371:
#line 881 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned below */ (yyval) = pt_generate_node( function_definition+4, "function_definition_4", 3, (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 4909 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 372:
#line 885 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( function_body, "function_body", 1, (yyvsp[0]) ); }
#line 4915 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 373:
#line 889 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( initializer+1, "initializer_1", 2, (yyvsp[-1]), (yyvsp[0]) ); }
#line 4921 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 374:
#line 890 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( initializer+2, "initializer_2", 3, (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 4927 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 375:
#line 894 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( initializer_clause+1, "initializer_clause_1", 1, (yyvsp[0]) ); }
#line 4933 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 376:
#line 895 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( initializer_clause+2, "initializer_clause_2", 4, (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 4939 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 377:
#line 896 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( initializer_clause+3, "initializer_clause_3", 2, (yyvsp[-1]), (yyvsp[0]) ); }
#line 4945 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 378:
#line 900 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( initializer_list+1, "initializer_list_1", 1, (yyvsp[0]) ); }
#line 4951 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 379:
#line 901 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( initializer_list+2, "initializer_list_2", 3, (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 4957 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 380:
#line 909 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( class_specifier, "class_specifier", 4, (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 4963 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 381:
#line 913 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( class_head+1, "class_head_1", 2, (yyvsp[-1]), (yyvsp[0]) ); }
#line 4969 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 382:
#line 914 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned below */ (yyval) = pt_generate_node( class_head+2, "class_head_2", 3, (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 4975 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 383:
#line 915 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( class_head+3, "class_head_3", 3, (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 4981 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 384:
#line 916 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned below */ (yyval) = pt_generate_node( class_head+4, "class_head_4", 4, (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 4987 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 385:
#line 920 "120++parse.y" /* yacc.c:1646  */
    { yylval->production = class_key+1; (yyval) = (yyvsp[0]); }
#line 4993 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 386:
#line 921 "120++parse.y" /* yacc.c:1646  */
    { yylval->production = class_key+2; (yyval) = (yyvsp[0]); }
#line 4999 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 387:
#line 922 "120++parse.y" /* yacc.c:1646  */
    { yylval->production = class_key+3; (yyval) = (yyvsp[0]); }
#line 5005 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 388:
#line 926 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( member_specification+1, "member_specification_1", 2, (yyvsp[-1]), (yyvsp[0]) ); }
#line 5011 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 389:
#line 927 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( member_specification+2, "member_specification_2", 3, (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 5017 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 390:
#line 931 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( member_declaration+1, "member_declaration_1", 3, (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 5023 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 391:
#line 932 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( member_declaration+2, "member_declaration_2", 2, (yyvsp[-1]), (yyvsp[0]) ); }
#line 5029 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 392:
#line 933 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( member_declaration+3, "member_declaration_3", 2, (yyvsp[-1]), (yyvsp[0]) ); }
#line 5035 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 393:
#line 934 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( member_declaration+4, "member_declaration_4", 1, (yyvsp[0]) ); }
#line 5041 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 394:
#line 935 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( member_declaration+5, "member_declaration_5", 2, (yyvsp[-1]), (yyvsp[0]) ); }
#line 5047 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 395:
#line 936 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( member_declaration+6, "member_declaration_6", 2, (yyvsp[-1]), (yyvsp[0]) ); }
#line 5053 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 396:
#line 937 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ handle_parse_warning( "This usage of using is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); (yyval) = pt_generate_node( member_declaration+7, "member_declaration_7", 1, (yyvsp[0]) ); }
#line 5059 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 397:
#line 938 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned below */ (yyval) = pt_generate_node( member_declaration+8, "member_declaration_8", 1, (yyvsp[0]) ); }
#line 5065 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 398:
#line 942 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( member_declarator_list+1, "member_declarator_list_1", 1, (yyvsp[0]) ); }
#line 5071 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 399:
#line 943 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( member_declarator_list+2, "member_declarator_list_2", 3, (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 5077 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 400:
#line 947 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( member_declarator+1, "member_declarator_1", 1, (yyvsp[0]) ); }
#line 5083 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 401:
#line 948 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ handle_parse_warning( "Whatever a \"pure specifier\" is, it is not supported in 120++ specs.", W_PARSE_UNHANDLED ); (yyval) = pt_generate_node( member_declarator+2, "member_declarator_2", 2, (yyvsp[-1]), (yyvsp[0]) ); }
#line 5089 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 402:
#line 949 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( member_declarator+3, "member_declarator_3", 2, (yyvsp[-1]), (yyvsp[0]) ); }
#line 5095 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 403:
#line 950 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ handle_parse_warning( "This member declarator syntax is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); (yyval) = pt_generate_node( member_declarator+4, "member_declarator_4", 3, (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 5101 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 404:
#line 959 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ (yyval) = NULL; }
#line 5107 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 405:
#line 963 "120++parse.y" /* yacc.c:1646  */
    { (yyval) = pt_generate_node( constant_initializer, "constant_initializer", 2, (yyvsp[-1]), (yyvsp[0]) ); }
#line 5113 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 406:
#line 971 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ handle_parse_warning( "This class declaration syntax is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); (yyval) = pt_generate_node( base_clause, "base_clause", 2, (yyvsp[-1]), (yyvsp[0]) ); }
#line 5119 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 407:
#line 975 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned above */ (yyval) = pt_generate_node( base_specifier_list+1, "base_specifier_list_1", 1, (yyvsp[0]) ); }
#line 5125 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 408:
#line 976 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned above */ (yyval) = pt_generate_node( base_specifier_list+2, "base_specifier_list_2", 3, (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 5131 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 409:
#line 980 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned above */ (yyval) = pt_generate_node( base_specifier+1, "base_specifier_1", 3, (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 5137 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 410:
#line 981 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned above */ (yyval) = pt_generate_node( base_specifier+2, "base_specifier_2", 2, (yyvsp[-1]), (yyvsp[0]) ); }
#line 5143 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 411:
#line 982 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned above */ (yyval) = pt_generate_node( base_specifier+3, "base_specifier_3", 2, (yyvsp[-1]), (yyvsp[0]) ); }
#line 5149 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 412:
#line 983 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned above */ (yyval) = pt_generate_node( base_specifier+4, "base_specifier_4", 1, (yyvsp[0]) ); }
#line 5155 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 413:
#line 984 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned above */ (yyval) = pt_generate_node( base_specifier+5, "base_specifier_5", 5, (yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 5161 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 414:
#line 985 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned above */ (yyval) = pt_generate_node( base_specifier+6, "base_specifier_6", 4, (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 5167 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 415:
#line 986 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned above */ (yyval) = pt_generate_node( base_specifier+7, "base_specifier_7", 4, (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 5173 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 416:
#line 987 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned above */ (yyval) = pt_generate_node( base_specifier+8, "base_specifier_8", 3, (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 5179 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 417:
#line 988 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned above */ (yyval) = pt_generate_node( base_specifier+9, "base_specifier_9", 5, (yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 5185 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 418:
#line 989 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned above */ (yyval) = pt_generate_node( base_specifier+10, "base_specifier_10", 4, (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 5191 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 419:
#line 990 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned above */ (yyval) = pt_generate_node( base_specifier+11, "base_specifier_11", 4, (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 5197 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 420:
#line 991 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned above */ (yyval) = pt_generate_node( base_specifier+12, "base_specifier_12", 3, (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 5203 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 421:
#line 995 "120++parse.y" /* yacc.c:1646  */
    { yylval->production = access_specifier+1; (yyval) = (yyvsp[0]); }
#line 5209 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 422:
#line 996 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ handle_parse_warning( "protected member access is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); yylval->production = access_specifier+2; (yyval) = (yyvsp[0]); }
#line 5215 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 423:
#line 997 "120++parse.y" /* yacc.c:1646  */
    { yylval->production = access_specifier+3; (yyval) = (yyvsp[0]); }
#line 5221 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 424:
#line 1005 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ handle_parse_warning( "Operator conversion functions are not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); (yyval) = pt_generate_node( conversion_function_id, "conversion_function_id", 2, (yyvsp[-1]), (yyvsp[0]) ); }
#line 5227 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 425:
#line 1009 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned above */ (yyval) = pt_generate_node( conversion_type_id, "conversion_type_id", 2, (yyvsp[-1]), (yyvsp[0]) ); }
#line 5233 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 426:
#line 1013 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned above */ (yyval) = pt_generate_node( conversion_declarator, "conversion_declarator", 2, (yyvsp[-1]), (yyvsp[0]) ); }
#line 5239 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 427:
#line 1017 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ handle_parse_warning( "Constructor initializations are not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); (yyval) = pt_generate_node( ctor_initializer, "ctor_initializer", 2, (yyvsp[-1]), (yyvsp[0]) ); }
#line 5245 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 428:
#line 1021 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned above */ (yyval) = pt_generate_node( mem_initializer_list+1, "mem_initializer_list_1", 1, (yyvsp[0]) ); }
#line 5251 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 429:
#line 1022 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned above */ (yyval) = pt_generate_node( mem_initializer_list+2, "mem_initializer_list_2", 3, (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 5257 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 430:
#line 1026 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned above */ (yyval) = pt_generate_node( mem_initializer, "mem_initializer", 4, (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 5263 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 431:
#line 1030 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned above */ (yyval) = pt_generate_node( mem_initializer_id+1, "mem_initializer_id_1", 3, (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 5269 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 432:
#line 1031 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned above */ (yyval) = pt_generate_node( mem_initializer_id+2, "mem_initializer_id_2", 2, (yyvsp[-1]), (yyvsp[0]) ); }
#line 5275 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 433:
#line 1032 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned above */ (yyval) = pt_generate_node( mem_initializer_id+3, "mem_initializer_id_3", 2, (yyvsp[-1]), (yyvsp[0]) ); }
#line 5281 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 434:
#line 1033 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned above */ (yyval) = pt_generate_node( mem_initializer_id+4, "mem_initializer_id_4", 1, (yyvsp[0]) ); }
#line 5287 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 435:
#line 1034 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned above */ (yyval) = pt_generate_node( mem_initializer_id+5, "mem_initializer_id_5", 1, (yyvsp[0]) ); }
#line 5293 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 436:
#line 1042 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ handle_parse_warning( "Operator overloading is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); (yyval) = pt_generate_node( operator_function_id, "operator_function_id", 2, (yyvsp[-1]), (yyvsp[0]) ); }
#line 5299 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 437:
#line 1046 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned above */ yylval->production = operator+1; (yyval) = (yyvsp[0]); }
#line 5305 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 438:
#line 1047 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned above */ yylval->production = operator+2; (yyval) = (yyvsp[0]); }
#line 5311 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 439:
#line 1048 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned above */ (yyval) = pt_generate_node( operator+3, "operator_3", 3, (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 5317 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 440:
#line 1049 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned above */ (yyval) = pt_generate_node( operator+4, "operator_4", 3, (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 5323 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 441:
#line 1050 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ yylval->production = operator+5; (yyval) = (yyvsp[0]); }
#line 5329 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 442:
#line 1051 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ yylval->production = operator+6; (yyval) = (yyvsp[0]); }
#line 5335 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 443:
#line 1052 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ yylval->production = operator+7; (yyval) = (yyvsp[0]); }
#line 5341 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 444:
#line 1053 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ yylval->production = operator+8; (yyval) = (yyvsp[0]); }
#line 5347 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 445:
#line 1054 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ yylval->production = operator+9; (yyval) = (yyvsp[0]); }
#line 5353 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 446:
#line 1055 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ yylval->production = operator+10; (yyval) = (yyvsp[0]); }
#line 5359 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 447:
#line 1056 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ yylval->production = operator+11; (yyval) = (yyvsp[0]); }
#line 5365 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 448:
#line 1057 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ yylval->production = operator+12; (yyval) = (yyvsp[0]); }
#line 5371 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 449:
#line 1058 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ yylval->production = operator+13; (yyval) = (yyvsp[0]); }
#line 5377 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 450:
#line 1059 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ yylval->production = operator+14; (yyval) = (yyvsp[0]); }
#line 5383 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 451:
#line 1060 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ yylval->production = operator+15; (yyval) = (yyvsp[0]); }
#line 5389 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 452:
#line 1061 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ yylval->production = operator+16; (yyval) = (yyvsp[0]); }
#line 5395 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 453:
#line 1062 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ yylval->production = operator+17; (yyval) = (yyvsp[0]); }
#line 5401 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 454:
#line 1063 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ yylval->production = operator+18; (yyval) = (yyvsp[0]); }
#line 5407 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 455:
#line 1064 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ yylval->production = operator+19; (yyval) = (yyvsp[0]); }
#line 5413 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 456:
#line 1065 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ yylval->production = operator+20; (yyval) = (yyvsp[0]); }
#line 5419 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 457:
#line 1066 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ yylval->production = operator+21; (yyval) = (yyvsp[0]); }
#line 5425 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 458:
#line 1067 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ yylval->production = operator+22; (yyval) = (yyvsp[0]); }
#line 5431 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 459:
#line 1068 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ yylval->production = operator+23; (yyval) = (yyvsp[0]); }
#line 5437 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 460:
#line 1069 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ yylval->production = operator+24; (yyval) = (yyvsp[0]); }
#line 5443 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 461:
#line 1070 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ yylval->production = operator+25; (yyval) = (yyvsp[0]); }
#line 5449 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 462:
#line 1071 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ yylval->production = operator+26; (yyval) = (yyvsp[0]); }
#line 5455 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 463:
#line 1072 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ yylval->production = operator+27; (yyval) = (yyvsp[0]); }
#line 5461 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 464:
#line 1073 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ yylval->production = operator+28; (yyval) = (yyvsp[0]); }
#line 5467 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 465:
#line 1074 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ yylval->production = operator+29; (yyval) = (yyvsp[0]); }
#line 5473 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 466:
#line 1075 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ yylval->production = operator+30; (yyval) = (yyvsp[0]); }
#line 5479 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 467:
#line 1076 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ yylval->production = operator+31; (yyval) = (yyvsp[0]); }
#line 5485 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 468:
#line 1077 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ yylval->production = operator+32; (yyval) = (yyvsp[0]); }
#line 5491 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 469:
#line 1078 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ yylval->production = operator+33; (yyval) = (yyvsp[0]); }
#line 5497 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 470:
#line 1079 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ yylval->production = operator+34; (yyval) = (yyvsp[0]); }
#line 5503 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 471:
#line 1080 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ yylval->production = operator+35; (yyval) = (yyvsp[0]); }
#line 5509 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 472:
#line 1081 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ yylval->production = operator+36; (yyval) = (yyvsp[0]); }
#line 5515 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 473:
#line 1082 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ yylval->production = operator+37; (yyval) = (yyvsp[0]); }
#line 5521 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 474:
#line 1083 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ yylval->production = operator+38; (yyval) = (yyvsp[0]); }
#line 5527 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 475:
#line 1084 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ yylval->production = operator+39; (yyval) = (yyvsp[0]); }
#line 5533 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 476:
#line 1085 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ yylval->production = operator+40; (yyval) = (yyvsp[0]); }
#line 5539 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 477:
#line 1086 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ (yyval) = pt_generate_node( operator+41, "operator_41", 2, (yyvsp[-1]), (yyvsp[0]) ); }
#line 5545 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 478:
#line 1087 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ (yyval) = pt_generate_node( operator+42, "operator_42", 2, (yyvsp[-1]), (yyvsp[0]) ); }
#line 5551 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 479:
#line 1095 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ handle_parse_warning( "Template features are not supported in 120++ specs.", W_PARSE_UNHANDLED ); (yyval) = NULL; }
#line 5557 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 480:
#line 1099 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned above */ (yyval) = NULL; }
#line 5563 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 481:
#line 1100 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned above */ (yyval) = NULL; }
#line 5569 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 482:
#line 1104 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned above */ (yyval) = NULL; }
#line 5575 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 483:
#line 1105 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned above */ (yyval) = NULL; }
#line 5581 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 484:
#line 1109 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned above */ (yyval) = NULL; }
#line 5587 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 485:
#line 1110 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned above */ (yyval) = NULL; }
#line 5593 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 486:
#line 1111 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned above */ (yyval) = NULL; }
#line 5599 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 487:
#line 1112 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned above */ (yyval) = NULL; }
#line 5605 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 488:
#line 1113 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned above */ (yyval) = NULL; }
#line 5611 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 489:
#line 1114 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned above */ (yyval) = NULL; }
#line 5617 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 490:
#line 1118 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ handle_parse_warning( "Template features are not supported in 120++ specs.", W_PARSE_UNHANDLED ); (yyval) = NULL; }
#line 5623 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 491:
#line 1122 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned above */ (yyval) = NULL; }
#line 5629 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 492:
#line 1123 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned above */ (yyval) = NULL; }
#line 5635 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 493:
#line 1127 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned above */ (yyval) = NULL; }
#line 5641 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 494:
#line 1128 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned above */ (yyval) = NULL; }
#line 5647 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 495:
#line 1129 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned above */ (yyval) = NULL; }
#line 5653 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 496:
#line 1133 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ handle_parse_warning( "Template features are not supported in 120++ specs.", W_PARSE_UNHANDLED ); (yyval) = NULL; }
#line 5659 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 497:
#line 1137 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ handle_parse_warning( "Template features are not supported in 120++ specs.", W_PARSE_UNHANDLED ); (yyval) = NULL; }
#line 5665 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 498:
#line 1145 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ handle_parse_warning( "Exception handling features are not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); (yyval) = pt_generate_node( try_block, "try_block", 3, (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 5671 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 499:
#line 1149 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ handle_parse_warning( "Exception handling features are not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); (yyval) = pt_generate_node( function_try_block, "function_try_block", 4, (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 5677 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 500:
#line 1153 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned above */ (yyval) = pt_generate_node( handler_seq, "handler_seq", 2, (yyvsp[-1]), (yyvsp[0]) ); }
#line 5683 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 501:
#line 1157 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned above */ (yyval) = pt_generate_node( handler, "handler", 5, (yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 5689 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 502:
#line 1161 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned above */ (yyval) = pt_generate_node( exception_declaration+1, "exception_declaration_1", 2, (yyvsp[-1]), (yyvsp[0]) ); }
#line 5695 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 503:
#line 1162 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned above */ (yyval) = pt_generate_node( exception_declaration+2, "exception_declaration_2", 2, (yyvsp[-1]), (yyvsp[0]) ); }
#line 5701 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 504:
#line 1163 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned above */ (yyval) = pt_generate_node( exception_declaration+3, "exception_declaration_3", 1, (yyvsp[0]) ); }
#line 5707 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 505:
#line 1164 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned above */ yylval->production = exception_declaration+4; (yyval) = (yyvsp[0]); }
#line 5713 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 506:
#line 1168 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ handle_parse_warning( "Exception handling features are not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); (yyval) = pt_generate_node( throw_expression, "throw_expression", 2, (yyvsp[-1]), (yyvsp[0]) ); }
#line 5719 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 507:
#line 1172 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ handle_parse_warning( "Exception handling features are not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); (yyval) = pt_generate_node( exception_specification, "exception_specification", 4, (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 5725 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 508:
#line 1176 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned above */ (yyval) = pt_generate_node( type_id_list+1, "type_id_list_1", 1, (yyvsp[0]) ); }
#line 5731 "120++parse.tab.c" /* yacc.c:1646  */
    break;

  case 509:
#line 1177 "120++parse.y" /* yacc.c:1646  */
    { /* !Not 120++! */ /* Warned above */ (yyval) = pt_generate_node( type_id_list+2, "type_id_list_2", 3, (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]) ); }
#line 5737 "120++parse.tab.c" /* yacc.c:1646  */
    break;


#line 5741 "120++parse.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 1179 "120++parse.y" /* yacc.c:1906  */



static void yyerror( char *msg )
{
	if ( program_result_120 == EXIT_NORMAL || program_result_120 == EXIT_ERROR_PARSE  ) 
	{
		fprintf( stderr, "In %s, line %d: %s\n", yyfiles->filename, yyfiles->line_num, msg );
		program_result_120 = EXIT_ERROR_PARSE;
	}
}


void handle_parse_warning( char *msg, short warning_type )
{
	switch ( warning_type )
	{
		fprintf( stderr, "Bison > Warning: " );
		case 1:
			fprintf( stderr, "%s\n\tIn file %s at line %d.\n", msg, yyfiles->filename, yyfiles->line_num );
			break;
		case 2:
			fprintf( stderr, "%s%s\n\tIn file %s at line %d.\n", msg, " The unhandled syntax has been dropped and ignored by this compiler.", yyfiles->filename, yyfiles->line_num );
			break;
		default:
			fprintf( stderr, "%s\n\tIn file %s at line %d.\n", msg, yyfiles->filename, yyfiles->line_num );
			break;
	}
}
