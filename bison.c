/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "yabasic.bison"

/*

    YABASIC  ---  a simple Basic Interpreter
    written by Marc Ihm 1995-2022
    more info at www.yabasic.de

    BISON part
     
    This file is part of yabasic and may be copied under the terms of
    MIT License which can be found in the file LICENSE.

*/


#ifndef YABASIC_INCLUDED
#include "yabasic.h"     /* definitions of yabasic */
#endif

#ifdef WINDOWS
#include <malloc.h>
#else
#ifdef HAVE_MALLOC_H
#include <malloc.h>
#else
#include <stdlib.h>
#endif
#endif

#if HAVE_ALLOCA_H
#ifndef WINDOWS
#include <alloca.h>
#endif
#endif

void __yy_bcopy(char *,char *,int); /* prototype missing */

int tileol; /* true, read should go to eon of line */
int function_type=ftNONE; /* contains function type while parsing function */
char *current_function=NULL; /* name of currently parsed function */
int exported=FALSE; /* true, if function is exported */
int yylex(void);
extern struct library *current_library; /* defined in main.c: name of currently parsed library */
extern int yylineno; /* defined in flex */
int missing_endif=0;
int missing_endif_line=0;
int missing_endsub=0;
int missing_endsub_line=0;
int missing_next=0;
int missing_next_line=0;
int missing_wend=0;
int missing_wend_line=0;
int missing_until=0;
int missing_until_line=0;
int missing_loop=0;
int missing_loop_line=0;
int loop_nesting=0;
int switch_nesting=0;

void report_if_missing(char *text,int eof) {
  if (missing_loop || missing_endif || missing_next || missing_until || missing_wend) {
    if (eof) {
       error_without_position(sERROR,text);
    } else {
       error(sERROR,text);
    }
    collect_missing_clauses(string,-1);
    if (string[0]) {
      error_without_position(sERROR,string);
    }
  }
}

void report_conflicting_close(char *text,int missing) {
  error(sERROR,text);
  collect_missing_clauses(string,missing);
  error(sERROR,string);
}

void collect_missing_clauses(char *string, char exclude) {
  char buff[INBUFFLEN];
  
  string[0]='\0';
  if (missing_endif && exclude!='e') {
    if (string[0]) strcat(string,"; ");
    sprintf(buff,"if-statement starting at line %d has seen no 'endif' yet",missing_endif_line);
    strcat(string, buff);
  }

  if (missing_next && exclude!='n') {
    if (string[0]) strcat(string,"; ");
    sprintf(buff,"for-loop starting at line %d has seen no 'next' yet",missing_next_line);
    strcat(string, buff);
  }

  if (missing_wend && exclude!='w') {
    if (string[0]) strcat(string,"; ");
    sprintf(buff,"while-loop starting at line %d has seen no 'wend' yet",missing_wend_line);
    strcat(string, buff);
  }

  if (missing_until && exclude!='u') {
    if (string[0]) strcat(string,"; ");
    sprintf(buff,"repeat-loop starting at line %d has seen no 'until' yet",missing_until_line);
    strcat(string, buff);
  }
  
  if (missing_loop && exclude!='l') {
    if (string[0]) strcat(string,"; ");
    sprintf(buff,"do-loop starting at line %d has seen no 'loop' yet",missing_loop_line);
    strcat(string, buff);
  }
}

#line 186 "bison.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "bison.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_tFNUM = 3,                      /* tFNUM  */
  YYSYMBOL_tSYMBOL = 4,                    /* tSYMBOL  */
  YYSYMBOL_tSTRSYM = 5,                    /* tSTRSYM  */
  YYSYMBOL_tDOCU = 6,                      /* tDOCU  */
  YYSYMBOL_tDIGITS = 7,                    /* tDIGITS  */
  YYSYMBOL_tHEXDIGITS = 8,                 /* tHEXDIGITS  */
  YYSYMBOL_tBINDIGITS = 9,                 /* tBINDIGITS  */
  YYSYMBOL_tSTRING = 10,                   /* tSTRING  */
  YYSYMBOL_tFOR = 11,                      /* tFOR  */
  YYSYMBOL_tTO = 12,                       /* tTO  */
  YYSYMBOL_tSTEP = 13,                     /* tSTEP  */
  YYSYMBOL_tNEXT = 14,                     /* tNEXT  */
  YYSYMBOL_tWHILE = 15,                    /* tWHILE  */
  YYSYMBOL_tWEND = 16,                     /* tWEND  */
  YYSYMBOL_tREPEAT = 17,                   /* tREPEAT  */
  YYSYMBOL_tUNTIL = 18,                    /* tUNTIL  */
  YYSYMBOL_tIMPORT = 19,                   /* tIMPORT  */
  YYSYMBOL_tGOTO = 20,                     /* tGOTO  */
  YYSYMBOL_tGOSUB = 21,                    /* tGOSUB  */
  YYSYMBOL_tLABEL = 22,                    /* tLABEL  */
  YYSYMBOL_tON = 23,                       /* tON  */
  YYSYMBOL_tSUB = 24,                      /* tSUB  */
  YYSYMBOL_tENDSUB = 25,                   /* tENDSUB  */
  YYSYMBOL_tLOCAL = 26,                    /* tLOCAL  */
  YYSYMBOL_tSTATIC = 27,                   /* tSTATIC  */
  YYSYMBOL_tEXPORT = 28,                   /* tEXPORT  */
  YYSYMBOL_tERROR = 29,                    /* tERROR  */
  YYSYMBOL_tEXECUTE = 30,                  /* tEXECUTE  */
  YYSYMBOL_tEXECUTE2 = 31,                 /* tEXECUTE2  */
  YYSYMBOL_tCOMPILE = 32,                  /* tCOMPILE  */
  YYSYMBOL_tRUNTIME_CREATED_SUB = 33,      /* tRUNTIME_CREATED_SUB  */
  YYSYMBOL_tINTERRUPT = 34,                /* tINTERRUPT  */
  YYSYMBOL_tBREAK = 35,                    /* tBREAK  */
  YYSYMBOL_tCONTINUE = 36,                 /* tCONTINUE  */
  YYSYMBOL_tSWITCH = 37,                   /* tSWITCH  */
  YYSYMBOL_tSEND = 38,                     /* tSEND  */
  YYSYMBOL_tCASE = 39,                     /* tCASE  */
  YYSYMBOL_tDEFAULT = 40,                  /* tDEFAULT  */
  YYSYMBOL_tLOOP = 41,                     /* tLOOP  */
  YYSYMBOL_tDO = 42,                       /* tDO  */
  YYSYMBOL_tSEP = 43,                      /* tSEP  */
  YYSYMBOL_tEOPROG = 44,                   /* tEOPROG  */
  YYSYMBOL_tIF = 45,                       /* tIF  */
  YYSYMBOL_tTHEN = 46,                     /* tTHEN  */
  YYSYMBOL_tELSE = 47,                     /* tELSE  */
  YYSYMBOL_tELSIF = 48,                    /* tELSIF  */
  YYSYMBOL_tENDIF = 49,                    /* tENDIF  */
  YYSYMBOL_tIMPLICITENDIF = 50,            /* tIMPLICITENDIF  */
  YYSYMBOL_tUSING = 51,                    /* tUSING  */
  YYSYMBOL_tPRINT = 52,                    /* tPRINT  */
  YYSYMBOL_tINPUT = 53,                    /* tINPUT  */
  YYSYMBOL_tRETURN = 54,                   /* tRETURN  */
  YYSYMBOL_tDIM = 55,                      /* tDIM  */
  YYSYMBOL_tEND = 56,                      /* tEND  */
  YYSYMBOL_tEXIT = 57,                     /* tEXIT  */
  YYSYMBOL_tAT = 58,                       /* tAT  */
  YYSYMBOL_tSCREEN = 59,                   /* tSCREEN  */
  YYSYMBOL_tREVERSE = 60,                  /* tREVERSE  */
  YYSYMBOL_tCOLOUR = 61,                   /* tCOLOUR  */
  YYSYMBOL_tBACKCOLOUR = 62,               /* tBACKCOLOUR  */
  YYSYMBOL_tAND = 63,                      /* tAND  */
  YYSYMBOL_tOR = 64,                       /* tOR  */
  YYSYMBOL_tNOT = 65,                      /* tNOT  */
  YYSYMBOL_tBITNOT = 66,                   /* tBITNOT  */
  YYSYMBOL_tEOR = 67,                      /* tEOR  */
  YYSYMBOL_tSHL = 68,                      /* tSHL  */
  YYSYMBOL_tSHR = 69,                      /* tSHR  */
  YYSYMBOL_tNEQ = 70,                      /* tNEQ  */
  YYSYMBOL_tLEQ = 71,                      /* tLEQ  */
  YYSYMBOL_tGEQ = 72,                      /* tGEQ  */
  YYSYMBOL_tLTN = 73,                      /* tLTN  */
  YYSYMBOL_tGTN = 74,                      /* tGTN  */
  YYSYMBOL_tEQU = 75,                      /* tEQU  */
  YYSYMBOL_tEQU2 = 76,                     /* tEQU2  */
  YYSYMBOL_tPOW = 77,                      /* tPOW  */
  YYSYMBOL_tREAD = 78,                     /* tREAD  */
  YYSYMBOL_tDATA = 79,                     /* tDATA  */
  YYSYMBOL_tRESTORE = 80,                  /* tRESTORE  */
  YYSYMBOL_tOPEN = 81,                     /* tOPEN  */
  YYSYMBOL_tCLOSE = 82,                    /* tCLOSE  */
  YYSYMBOL_tSEEK = 83,                     /* tSEEK  */
  YYSYMBOL_tTELL = 84,                     /* tTELL  */
  YYSYMBOL_tAS = 85,                       /* tAS  */
  YYSYMBOL_tREADING = 86,                  /* tREADING  */
  YYSYMBOL_tWRITING = 87,                  /* tWRITING  */
  YYSYMBOL_tORIGIN = 88,                   /* tORIGIN  */
  YYSYMBOL_tWINDOW = 89,                   /* tWINDOW  */
  YYSYMBOL_tDOT = 90,                      /* tDOT  */
  YYSYMBOL_tLINE = 91,                     /* tLINE  */
  YYSYMBOL_tCIRCLE = 92,                   /* tCIRCLE  */
  YYSYMBOL_tTRIANGLE = 93,                 /* tTRIANGLE  */
  YYSYMBOL_tTEXT = 94,                     /* tTEXT  */
  YYSYMBOL_tCLEAR = 95,                    /* tCLEAR  */
  YYSYMBOL_tFILL = 96,                     /* tFILL  */
  YYSYMBOL_tPRINTER = 97,                  /* tPRINTER  */
  YYSYMBOL_tWAIT = 98,                     /* tWAIT  */
  YYSYMBOL_tBELL = 99,                     /* tBELL  */
  YYSYMBOL_tLET = 100,                     /* tLET  */
  YYSYMBOL_tARDIM = 101,                   /* tARDIM  */
  YYSYMBOL_tARSIZE = 102,                  /* tARSIZE  */
  YYSYMBOL_tBIND = 103,                    /* tBIND  */
  YYSYMBOL_tRECT = 104,                    /* tRECT  */
  YYSYMBOL_tGETBIT = 105,                  /* tGETBIT  */
  YYSYMBOL_tPUTBIT = 106,                  /* tPUTBIT  */
  YYSYMBOL_tGETCHAR = 107,                 /* tGETCHAR  */
  YYSYMBOL_tPUTCHAR = 108,                 /* tPUTCHAR  */
  YYSYMBOL_tNEW = 109,                     /* tNEW  */
  YYSYMBOL_tCURVE = 110,                   /* tCURVE  */
  YYSYMBOL_tSIN = 111,                     /* tSIN  */
  YYSYMBOL_tASIN = 112,                    /* tASIN  */
  YYSYMBOL_tCOS = 113,                     /* tCOS  */
  YYSYMBOL_tACOS = 114,                    /* tACOS  */
  YYSYMBOL_tTAN = 115,                     /* tTAN  */
  YYSYMBOL_tATAN = 116,                    /* tATAN  */
  YYSYMBOL_tEXP = 117,                     /* tEXP  */
  YYSYMBOL_tLOG = 118,                     /* tLOG  */
  YYSYMBOL_tSQRT = 119,                    /* tSQRT  */
  YYSYMBOL_tSQR = 120,                     /* tSQR  */
  YYSYMBOL_tMYEOF = 121,                   /* tMYEOF  */
  YYSYMBOL_tABS = 122,                     /* tABS  */
  YYSYMBOL_tSIG = 123,                     /* tSIG  */
  YYSYMBOL_tINT = 124,                     /* tINT  */
  YYSYMBOL_tCEIL = 125,                    /* tCEIL  */
  YYSYMBOL_tFLOOR = 126,                   /* tFLOOR  */
  YYSYMBOL_tFRAC = 127,                    /* tFRAC  */
  YYSYMBOL_tROUND = 128,                   /* tROUND  */
  YYSYMBOL_tMOD = 129,                     /* tMOD  */
  YYSYMBOL_tRAN = 130,                     /* tRAN  */
  YYSYMBOL_tVAL = 131,                     /* tVAL  */
  YYSYMBOL_tLEFT = 132,                    /* tLEFT  */
  YYSYMBOL_tRIGHT = 133,                   /* tRIGHT  */
  YYSYMBOL_tMID = 134,                     /* tMID  */
  YYSYMBOL_tLEN = 135,                     /* tLEN  */
  YYSYMBOL_tMIN = 136,                     /* tMIN  */
  YYSYMBOL_tMAX = 137,                     /* tMAX  */
  YYSYMBOL_tSTR = 138,                     /* tSTR  */
  YYSYMBOL_tINKEY = 139,                   /* tINKEY  */
  YYSYMBOL_tCHR = 140,                     /* tCHR  */
  YYSYMBOL_tASC = 141,                     /* tASC  */
  YYSYMBOL_tHEX = 142,                     /* tHEX  */
  YYSYMBOL_tDEC = 143,                     /* tDEC  */
  YYSYMBOL_tBIN = 144,                     /* tBIN  */
  YYSYMBOL_tUPPER = 145,                   /* tUPPER  */
  YYSYMBOL_tLOWER = 146,                   /* tLOWER  */
  YYSYMBOL_tMOUSEX = 147,                  /* tMOUSEX  */
  YYSYMBOL_tMOUSEY = 148,                  /* tMOUSEY  */
  YYSYMBOL_tMOUSEB = 149,                  /* tMOUSEB  */
  YYSYMBOL_tMOUSEMOD = 150,                /* tMOUSEMOD  */
  YYSYMBOL_tTRIM = 151,                    /* tTRIM  */
  YYSYMBOL_tLTRIM = 152,                   /* tLTRIM  */
  YYSYMBOL_tRTRIM = 153,                   /* tRTRIM  */
  YYSYMBOL_tINSTR = 154,                   /* tINSTR  */
  YYSYMBOL_tRINSTR = 155,                  /* tRINSTR  */
  YYSYMBOL_tCHOMP = 156,                   /* tCHOMP  */
  YYSYMBOL_tSYSTEM = 157,                  /* tSYSTEM  */
  YYSYMBOL_tSYSTEM2 = 158,                 /* tSYSTEM2  */
  YYSYMBOL_tPEEK = 159,                    /* tPEEK  */
  YYSYMBOL_tPEEK2 = 160,                   /* tPEEK2  */
  YYSYMBOL_tPOKE = 161,                    /* tPOKE  */
  YYSYMBOL_tFRNFN_CALL = 162,              /* tFRNFN_CALL  */
  YYSYMBOL_tFRNFN_CALL2 = 163,             /* tFRNFN_CALL2  */
  YYSYMBOL_tFRNFN_SIZE = 164,              /* tFRNFN_SIZE  */
  YYSYMBOL_tFRNBF_ALLOC = 165,             /* tFRNBF_ALLOC  */
  YYSYMBOL_tFRNBF_FREE = 166,              /* tFRNBF_FREE  */
  YYSYMBOL_tFRNBF_SIZE = 167,              /* tFRNBF_SIZE  */
  YYSYMBOL_tFRNBF_DUMP = 168,              /* tFRNBF_DUMP  */
  YYSYMBOL_tFRNBF_SET = 169,               /* tFRNBF_SET  */
  YYSYMBOL_tFRNBF_GET = 170,               /* tFRNBF_GET  */
  YYSYMBOL_tFRNBF_GET2 = 171,              /* tFRNBF_GET2  */
  YYSYMBOL_tFRNBF_GET_BUFFER = 172,        /* tFRNBF_GET_BUFFER  */
  YYSYMBOL_tFRNBF_SET_BUFFER = 173,        /* tFRNBF_SET_BUFFER  */
  YYSYMBOL_tDATE = 174,                    /* tDATE  */
  YYSYMBOL_tTIME = 175,                    /* tTIME  */
  YYSYMBOL_tTOKEN = 176,                   /* tTOKEN  */
  YYSYMBOL_tTOKENALT = 177,                /* tTOKENALT  */
  YYSYMBOL_tSPLIT = 178,                   /* tSPLIT  */
  YYSYMBOL_tSPLITALT = 179,                /* tSPLITALT  */
  YYSYMBOL_tGLOB = 180,                    /* tGLOB  */
  YYSYMBOL_tSTART_PROGRAM = 181,           /* tSTART_PROGRAM  */
  YYSYMBOL_tSTART_EXPRESSION = 182,        /* tSTART_EXPRESSION  */
  YYSYMBOL_tSTART_STRING_EXPRESSION = 183, /* tSTART_STRING_EXPRESSION  */
  YYSYMBOL_tSTART_ASSIGNMENT = 184,        /* tSTART_ASSIGNMENT  */
  YYSYMBOL_tSTART_FUNCTION_DEFINITION = 185, /* tSTART_FUNCTION_DEFINITION  */
  YYSYMBOL_tEVAL = 186,                    /* tEVAL  */
  YYSYMBOL_tEVAL2 = 187,                   /* tEVAL2  */
  YYSYMBOL_tBEAM_OPEN = 188,               /* tBEAM_OPEN  */
  YYSYMBOL_tBEAM_CLOSE = 189,              /* tBEAM_CLOSE  */
  YYSYMBOL_tBEAM_TITLE = 190,              /* tBEAM_TITLE  */
  YYSYMBOL_tBEAM_SIZE = 191,               /* tBEAM_SIZE  */
  YYSYMBOL_tBEAM_RUNNING = 192,            /* tBEAM_RUNNING  */
  YYSYMBOL_tBEAM_BEGIN = 193,              /* tBEAM_BEGIN  */
  YYSYMBOL_tBEAM_END = 194,                /* tBEAM_END  */
  YYSYMBOL_tBEAM_BUTTON = 195,             /* tBEAM_BUTTON  */
  YYSYMBOL_tBEAM_LABEL = 196,              /* tBEAM_LABEL  */
  YYSYMBOL_tBEAM_TEXT = 197,               /* tBEAM_TEXT  */
  YYSYMBOL_tBEAM_INPUT = 198,              /* tBEAM_INPUT  */
  YYSYMBOL_tBEAM_CHECKBOX = 199,           /* tBEAM_CHECKBOX  */
  YYSYMBOL_tBEAM_COMBO = 200,              /* tBEAM_COMBO  */
  YYSYMBOL_tBEAM_SLIDER = 201,             /* tBEAM_SLIDER  */
  YYSYMBOL_tBEAM_PROGRESS = 202,           /* tBEAM_PROGRESS  */
  YYSYMBOL_tBEAM_VBAR = 203,               /* tBEAM_VBAR  */
  YYSYMBOL_tBEAM_SEPARATOR = 204,          /* tBEAM_SEPARATOR  */
  YYSYMBOL_tBEAM_SPACING = 205,            /* tBEAM_SPACING  */
  YYSYMBOL_tBEAM_IMAGE = 206,              /* tBEAM_IMAGE  */
  YYSYMBOL_tBEAM_ROW = 207,                /* tBEAM_ROW  */
  YYSYMBOL_tBEAM_ROW_END = 208,            /* tBEAM_ROW_END  */
  YYSYMBOL_tBEAM_GROUP_BEGIN = 209,        /* tBEAM_GROUP_BEGIN  */
  YYSYMBOL_tBEAM_GROUP_END = 210,          /* tBEAM_GROUP_END  */
  YYSYMBOL_tBEAM_PANEL_BEGIN = 211,        /* tBEAM_PANEL_BEGIN  */
  YYSYMBOL_tBEAM_PANEL_END = 212,          /* tBEAM_PANEL_END  */
  YYSYMBOL_tBEAM_MSGBOX = 213,             /* tBEAM_MSGBOX  */
  YYSYMBOL_tBEAM_CONFIRM = 214,            /* tBEAM_CONFIRM  */
  YYSYMBOL_tBEAM_OPEN_FILE = 215,          /* tBEAM_OPEN_FILE  */
  YYSYMBOL_tBEAM_SAVE_FILE = 216,          /* tBEAM_SAVE_FILE  */
  YYSYMBOL_tBEAM_SET_COLOR = 217,          /* tBEAM_SET_COLOR  */
  YYSYMBOL_tBEAM_SET_STYLE = 218,          /* tBEAM_SET_STYLE  */
  YYSYMBOL_tBEAM_TIME = 219,               /* tBEAM_TIME  */
  YYSYMBOL_tBEAM_SLEEP = 220,              /* tBEAM_SLEEP  */
  YYSYMBOL_tBEAM_NMEA_OPEN = 221,          /* tBEAM_NMEA_OPEN  */
  YYSYMBOL_tBEAM_NMEA_CLOSE = 222,         /* tBEAM_NMEA_CLOSE  */
  YYSYMBOL_tBEAM_NMEA_READ = 223,          /* tBEAM_NMEA_READ  */
  YYSYMBOL_tBEAM_NMEA_FIELD = 224,         /* tBEAM_NMEA_FIELD  */
  YYSYMBOL_225_ = 225,                     /* '-'  */
  YYSYMBOL_226_ = 226,                     /* '+'  */
  YYSYMBOL_227_ = 227,                     /* '*'  */
  YYSYMBOL_228_ = 228,                     /* '/'  */
  YYSYMBOL_UMINUS = 229,                   /* UMINUS  */
  YYSYMBOL_230_ = 230,                     /* ';'  */
  YYSYMBOL_231_ = 231,                     /* ','  */
  YYSYMBOL_232_ = 232,                     /* '('  */
  YYSYMBOL_233_ = 233,                     /* ')'  */
  YYSYMBOL_234_ = 234,                     /* '#'  */
  YYSYMBOL_YYACCEPT = 235,                 /* $accept  */
  YYSYMBOL_program_or_expression = 236,    /* program_or_expression  */
  YYSYMBOL_program = 237,                  /* program  */
  YYSYMBOL_statement_list = 238,           /* statement_list  */
  YYSYMBOL_239_1 = 239,                    /* $@1  */
  YYSYMBOL_240_2 = 240,                    /* $@2  */
  YYSYMBOL_assignment = 241,               /* assignment  */
  YYSYMBOL_statement = 242,                /* statement  */
  YYSYMBOL_243_3 = 243,                    /* $@3  */
  YYSYMBOL_244_4 = 244,                    /* $@4  */
  YYSYMBOL_245_5 = 245,                    /* $@5  */
  YYSYMBOL_246_6 = 246,                    /* $@6  */
  YYSYMBOL_247_7 = 247,                    /* $@7  */
  YYSYMBOL_248_8 = 248,                    /* $@8  */
  YYSYMBOL_clear_fill_clause = 249,        /* clear_fill_clause  */
  YYSYMBOL_string_assignment = 250,        /* string_assignment  */
  YYSYMBOL_to = 251,                       /* to  */
  YYSYMBOL_open_clause = 252,              /* open_clause  */
  YYSYMBOL_seek_clause = 253,              /* seek_clause  */
  YYSYMBOL_string_scalar_or_array = 254,   /* string_scalar_or_array  */
  YYSYMBOL_string_expression = 255,        /* string_expression  */
  YYSYMBOL_string_function = 256,          /* string_function  */
  YYSYMBOL_number_assignment = 257,        /* number_assignment  */
  YYSYMBOL_expression = 258,               /* expression  */
  YYSYMBOL_259_9 = 259,                    /* $@9  */
  YYSYMBOL_260_10 = 260,                   /* $@10  */
  YYSYMBOL_arrayref = 261,                 /* arrayref  */
  YYSYMBOL_string_arrayref = 262,          /* string_arrayref  */
  YYSYMBOL_coordinates = 263,              /* coordinates  */
  YYSYMBOL_function = 264,                 /* function  */
  YYSYMBOL_const = 265,                    /* const  */
  YYSYMBOL_number = 266,                   /* number  */
  YYSYMBOL_symbol_or_lineno = 267,         /* symbol_or_lineno  */
  YYSYMBOL_dimlist = 268,                  /* dimlist  */
  YYSYMBOL_function_or_array = 269,        /* function_or_array  */
  YYSYMBOL_stringfunction_or_array = 270,  /* stringfunction_or_array  */
  YYSYMBOL_call_list = 271,                /* call_list  */
  YYSYMBOL_272_11 = 272,                   /* $@11  */
  YYSYMBOL_calls = 273,                    /* calls  */
  YYSYMBOL_call_item = 274,                /* call_item  */
  YYSYMBOL_function_definition = 275,      /* function_definition  */
  YYSYMBOL_276_12 = 276,                   /* $@12  */
  YYSYMBOL_277_13 = 277,                   /* $@13  */
  YYSYMBOL_278_14 = 278,                   /* $@14  */
  YYSYMBOL_endsub = 279,                   /* endsub  */
  YYSYMBOL_function_name = 280,            /* function_name  */
  YYSYMBOL_export = 281,                   /* export  */
  YYSYMBOL_local_list = 282,               /* local_list  */
  YYSYMBOL_local_item = 283,               /* local_item  */
  YYSYMBOL_static_list = 284,              /* static_list  */
  YYSYMBOL_static_item = 285,              /* static_item  */
  YYSYMBOL_paramlist = 286,                /* paramlist  */
  YYSYMBOL_paramitem = 287,                /* paramitem  */
  YYSYMBOL_for_loop = 288,                 /* for_loop  */
  YYSYMBOL_289_15 = 289,                   /* $@15  */
  YYSYMBOL_290_16 = 290,                   /* $@16  */
  YYSYMBOL_291_17 = 291,                   /* $@17  */
  YYSYMBOL_292_18 = 292,                   /* $@18  */
  YYSYMBOL_next = 293,                     /* next  */
  YYSYMBOL_step_part = 294,                /* step_part  */
  YYSYMBOL_next_symbol = 295,              /* next_symbol  */
  YYSYMBOL_switch_number_or_string = 296,  /* switch_number_or_string  */
  YYSYMBOL_297_19 = 297,                   /* $@19  */
  YYSYMBOL_sep_list = 298,                 /* sep_list  */
  YYSYMBOL_number_or_string = 299,         /* number_or_string  */
  YYSYMBOL_case_list = 300,                /* case_list  */
  YYSYMBOL_301_20 = 301,                   /* $@20  */
  YYSYMBOL_default = 302,                  /* default  */
  YYSYMBOL_303_21 = 303,                   /* $@21  */
  YYSYMBOL_do_loop = 304,                  /* do_loop  */
  YYSYMBOL_305_22 = 305,                   /* $@22  */
  YYSYMBOL_loop = 306,                     /* loop  */
  YYSYMBOL_while_loop = 307,               /* while_loop  */
  YYSYMBOL_308_23 = 308,                   /* $@23  */
  YYSYMBOL_309_24 = 309,                   /* $@24  */
  YYSYMBOL_wend = 310,                     /* wend  */
  YYSYMBOL_repeat_loop = 311,              /* repeat_loop  */
  YYSYMBOL_312_25 = 312,                   /* $@25  */
  YYSYMBOL_until = 313,                    /* until  */
  YYSYMBOL_if_clause = 314,                /* if_clause  */
  YYSYMBOL_315_26 = 315,                   /* $@26  */
  YYSYMBOL_316_27 = 316,                   /* $@27  */
  YYSYMBOL_317_28 = 317,                   /* $@28  */
  YYSYMBOL_318_29 = 318,                   /* $@29  */
  YYSYMBOL_endif = 319,                    /* endif  */
  YYSYMBOL_short_if = 320,                 /* short_if  */
  YYSYMBOL_321_30 = 321,                   /* $@30  */
  YYSYMBOL_end_of_if = 322,                /* end_of_if  */
  YYSYMBOL_else_part = 323,                /* else_part  */
  YYSYMBOL_elsif_part = 324,               /* elsif_part  */
  YYSYMBOL_325_31 = 325,                   /* $@31  */
  YYSYMBOL_326_32 = 326,                   /* $@32  */
  YYSYMBOL_maybe_then = 327,               /* maybe_then  */
  YYSYMBOL_inputlist = 328,                /* inputlist  */
  YYSYMBOL_329_33 = 329,                   /* $@33  */
  YYSYMBOL_input = 330,                    /* input  */
  YYSYMBOL_readlist = 331,                 /* readlist  */
  YYSYMBOL_readitem = 332,                 /* readitem  */
  YYSYMBOL_datalist = 333,                 /* datalist  */
  YYSYMBOL_printlist = 334,                /* printlist  */
  YYSYMBOL_using = 335,                    /* using  */
  YYSYMBOL_inputbody = 336,                /* inputbody  */
  YYSYMBOL_337_34 = 337,                   /* $@34  */
  YYSYMBOL_338_35 = 338,                   /* $@35  */
  YYSYMBOL_339_36 = 339,                   /* $@36  */
  YYSYMBOL_340_37 = 340,                   /* $@37  */
  YYSYMBOL_341_38 = 341,                   /* $@38  */
  YYSYMBOL_prompt = 342,                   /* prompt  */
  YYSYMBOL_printintro = 343,               /* printintro  */
  YYSYMBOL_hashed_number = 344,            /* hashed_number  */
  YYSYMBOL_goto_list = 345,                /* goto_list  */
  YYSYMBOL_gosub_list = 346                /* gosub_list  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;



/* Unqualified %code blocks.  */
#line 907 "yabasic.bison"

void
yyerror(char *message) {
  error(sERROR,message);
}

void
lyyerror(int severity, char *message) {
  error(severity,message);
}

#line 579 "bison.c"

#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  229
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   8777

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  235
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  112
/* YYNRULES -- Number of rules.  */
#define YYNRULES  517
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1360

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   480


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,   234,     2,     2,     2,     2,
     232,   233,   227,   226,   231,   225,     2,   228,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   230,
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
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     229
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   204,   204,   205,   206,   207,   208,   211,   214,   215,
     215,   215,   218,   219,   220,   221,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   239,   240,   240,   241,   242,   243,   244,   245,
     246,   247,   247,   249,   249,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   261,   262,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   279,   280,
     281,   282,   283,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   318,   319,   320,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,   332,   333,
     334,   335,   336,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     355,   359,   360,   361,   362,   363,   367,   368,   369,   370,
     371,   372,   375,   376,   379,   380,   381,   382,   383,   386,
     387,   390,   391,   394,   395,   396,   397,   398,   399,   402,
     403,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,   439,   440,   441,   442,
     444,   445,   447,   448,   451,   452,   455,   455,   456,   456,
     457,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   491,   494,   497,   500,   501,   502,   503,   504,
     505,   506,   507,   508,   509,   510,   511,   512,   513,   514,
     515,   516,   517,   518,   519,   520,   521,   522,   523,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   550,   551,   552,   553,   554,
     555,   556,   557,   558,   559,   560,   561,   562,   563,   564,
     565,   566,   567,   568,   569,   570,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   583,   586,   587,   588,
     591,   592,   593,   594,   597,   598,   601,   602,   603,   604,
     607,   610,   613,   613,   616,   617,   618,   621,   622,   625,
     626,   629,   625,   634,   635,   638,   639,   642,   643,   644,
     645,   648,   649,   652,   653,   654,   655,   658,   659,   662,
     663,   664,   665,   668,   669,   670,   673,   674,   675,   676,
     679,   680,   685,   700,   679,   705,   706,   707,   708,   709,
     710,   713,   714,   717,   718,   723,   723,   727,   728,   731,
     732,   736,   738,   737,   742,   743,   743,   747,   747,   753,
     754,   755,   756,   757,   758,   762,   763,   762,   769,   770,
     774,   774,   779,   780,   781,   782,   783,   784,   787,   788,
     788,   790,   787,   794,   795,   796,   797,   798,   799,   802,
     802,   807,   808,   811,   812,   815,   817,   819,   816,   823,
     824,   827,   828,   828,   831,   832,   834,   835,   839,   840,
     843,   844,   846,   847,   851,   852,   853,   854,   857,   858,
     859,   860,   861,   864,   865,   866,   869,   869,   870,   870,
     871,   871,   872,   872,   873,   873,   876,   877,   880,   881,
     882,   883,   884,   885,   886,   887,   888,   889,   890,   891,
     892,   893,   896,   897,   899,   900,   903,   904
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "tFNUM", "tSYMBOL",
  "tSTRSYM", "tDOCU", "tDIGITS", "tHEXDIGITS", "tBINDIGITS", "tSTRING",
  "tFOR", "tTO", "tSTEP", "tNEXT", "tWHILE", "tWEND", "tREPEAT", "tUNTIL",
  "tIMPORT", "tGOTO", "tGOSUB", "tLABEL", "tON", "tSUB", "tENDSUB",
  "tLOCAL", "tSTATIC", "tEXPORT", "tERROR", "tEXECUTE", "tEXECUTE2",
  "tCOMPILE", "tRUNTIME_CREATED_SUB", "tINTERRUPT", "tBREAK", "tCONTINUE",
  "tSWITCH", "tSEND", "tCASE", "tDEFAULT", "tLOOP", "tDO", "tSEP",
  "tEOPROG", "tIF", "tTHEN", "tELSE", "tELSIF", "tENDIF", "tIMPLICITENDIF",
  "tUSING", "tPRINT", "tINPUT", "tRETURN", "tDIM", "tEND", "tEXIT", "tAT",
  "tSCREEN", "tREVERSE", "tCOLOUR", "tBACKCOLOUR", "tAND", "tOR", "tNOT",
  "tBITNOT", "tEOR", "tSHL", "tSHR", "tNEQ", "tLEQ", "tGEQ", "tLTN",
  "tGTN", "tEQU", "tEQU2", "tPOW", "tREAD", "tDATA", "tRESTORE", "tOPEN",
  "tCLOSE", "tSEEK", "tTELL", "tAS", "tREADING", "tWRITING", "tORIGIN",
  "tWINDOW", "tDOT", "tLINE", "tCIRCLE", "tTRIANGLE", "tTEXT", "tCLEAR",
  "tFILL", "tPRINTER", "tWAIT", "tBELL", "tLET", "tARDIM", "tARSIZE",
  "tBIND", "tRECT", "tGETBIT", "tPUTBIT", "tGETCHAR", "tPUTCHAR", "tNEW",
  "tCURVE", "tSIN", "tASIN", "tCOS", "tACOS", "tTAN", "tATAN", "tEXP",
  "tLOG", "tSQRT", "tSQR", "tMYEOF", "tABS", "tSIG", "tINT", "tCEIL",
  "tFLOOR", "tFRAC", "tROUND", "tMOD", "tRAN", "tVAL", "tLEFT", "tRIGHT",
  "tMID", "tLEN", "tMIN", "tMAX", "tSTR", "tINKEY", "tCHR", "tASC", "tHEX",
  "tDEC", "tBIN", "tUPPER", "tLOWER", "tMOUSEX", "tMOUSEY", "tMOUSEB",
  "tMOUSEMOD", "tTRIM", "tLTRIM", "tRTRIM", "tINSTR", "tRINSTR", "tCHOMP",
  "tSYSTEM", "tSYSTEM2", "tPEEK", "tPEEK2", "tPOKE", "tFRNFN_CALL",
  "tFRNFN_CALL2", "tFRNFN_SIZE", "tFRNBF_ALLOC", "tFRNBF_FREE",
  "tFRNBF_SIZE", "tFRNBF_DUMP", "tFRNBF_SET", "tFRNBF_GET", "tFRNBF_GET2",
  "tFRNBF_GET_BUFFER", "tFRNBF_SET_BUFFER", "tDATE", "tTIME", "tTOKEN",
  "tTOKENALT", "tSPLIT", "tSPLITALT", "tGLOB", "tSTART_PROGRAM",
  "tSTART_EXPRESSION", "tSTART_STRING_EXPRESSION", "tSTART_ASSIGNMENT",
  "tSTART_FUNCTION_DEFINITION", "tEVAL", "tEVAL2", "tBEAM_OPEN",
  "tBEAM_CLOSE", "tBEAM_TITLE", "tBEAM_SIZE", "tBEAM_RUNNING",
  "tBEAM_BEGIN", "tBEAM_END", "tBEAM_BUTTON", "tBEAM_LABEL", "tBEAM_TEXT",
  "tBEAM_INPUT", "tBEAM_CHECKBOX", "tBEAM_COMBO", "tBEAM_SLIDER",
  "tBEAM_PROGRESS", "tBEAM_VBAR", "tBEAM_SEPARATOR", "tBEAM_SPACING",
  "tBEAM_IMAGE", "tBEAM_ROW", "tBEAM_ROW_END", "tBEAM_GROUP_BEGIN",
  "tBEAM_GROUP_END", "tBEAM_PANEL_BEGIN", "tBEAM_PANEL_END",
  "tBEAM_MSGBOX", "tBEAM_CONFIRM", "tBEAM_OPEN_FILE", "tBEAM_SAVE_FILE",
  "tBEAM_SET_COLOR", "tBEAM_SET_STYLE", "tBEAM_TIME", "tBEAM_SLEEP",
  "tBEAM_NMEA_OPEN", "tBEAM_NMEA_CLOSE", "tBEAM_NMEA_READ",
  "tBEAM_NMEA_FIELD", "'-'", "'+'", "'*'", "'/'", "UMINUS", "';'", "','",
  "'('", "')'", "'#'", "$accept", "program_or_expression", "program",
  "statement_list", "$@1", "$@2", "assignment", "statement", "$@3", "$@4",
  "$@5", "$@6", "$@7", "$@8", "clear_fill_clause", "string_assignment",
  "to", "open_clause", "seek_clause", "string_scalar_or_array",
  "string_expression", "string_function", "number_assignment",
  "expression", "$@9", "$@10", "arrayref", "string_arrayref",
  "coordinates", "function", "const", "number", "symbol_or_lineno",
  "dimlist", "function_or_array", "stringfunction_or_array", "call_list",
  "$@11", "calls", "call_item", "function_definition", "$@12", "$@13",
  "$@14", "endsub", "function_name", "export", "local_list", "local_item",
  "static_list", "static_item", "paramlist", "paramitem", "for_loop",
  "$@15", "$@16", "$@17", "$@18", "next", "step_part", "next_symbol",
  "switch_number_or_string", "$@19", "sep_list", "number_or_string",
  "case_list", "$@20", "default", "$@21", "do_loop", "$@22", "loop",
  "while_loop", "$@23", "$@24", "wend", "repeat_loop", "$@25", "until",
  "if_clause", "$@26", "$@27", "$@28", "$@29", "endif", "short_if", "$@30",
  "end_of_if", "else_part", "elsif_part", "$@31", "$@32", "maybe_then",
  "inputlist", "$@33", "input", "readlist", "readitem", "datalist",
  "printlist", "using", "inputbody", "$@34", "$@35", "$@36", "$@37",
  "$@38", "prompt", "printintro", "hashed_number", "goto_list",
  "gosub_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-965)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-439)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     800,  4917,  4018,  4397,   231,   170,    77,   -61,   -27,  -965,
    -965,  -965,  -965,  -965,    72,    72,    72,  3620,  -965,  -965,
    -965,  4397,  -965,  -965,  4397,    10,    43,  -965,  -965,  -965,
    4018,    26,  -965,  4018,   239,  -965,  4018,  4018,  4018,   259,
      36,    72,  2227,  1456,  2625,     0,  4018,  3421,  4018,   110,
       2,  4018,  -965,   154,  4397,  4397,  4397,    -1,  -113,  -100,
     -72,   -51,   -35,  2625,  4397,  4397,  4397,   -12,     8,    39,
      42,    52,   155,   159,   167,   173,   184,   186,   190,   249,
     262,   268,   274,   276,   278,   299,   305,   307,   331,  -965,
     345,  -965,  -965,   -29,  -965,  -965,  -965,  -965,   388,   408,
    -965,   210,  -965,  -965,  -965,  -965,  -965,  -965,  -965,  -965,
     343,   368,  -965,  -965,  -965,  -965,   380,   383,   386,   389,
    4018,   413,   423,   433,   448,   457,   460,   468,   477,   496,
     502,   506,   530,   548,   578,   582,   598,   604,   615,   622,
     638,   650,   665,   672,   691,   708,   714,   717,   723,   738,
     740,   756,   759,   760,   761,   764,   766,   767,   770,   776,
     777,   782,   784,   785,   796,   797,   798,   801,   805,   806,
     811,   812,   813,   815,   819,   820,   821,   822,   823,   824,
     832,   833,   834,   835,   836,   837,   838,   839,   840,   841,
     842,   843,   845,   846,   848,   850,   851,   853,   854,   855,
     856,   858,   859,   860,   861,   862,   863,   864,   865,   867,
     868,   869,   870,   871,  4018,  4018,   236,  -965,   416,  -965,
    -965,  -965,  -965,  4397,   -41,   554,   388,   408,   704,  -965,
    4018,  -965,  4397,  -965,   726,  4018,  4707,  -965,  -965,  -965,
    -965,  -965,   195,    91,   300,   348,   567,  -965,  4018,  -965,
     567,  -965,  -965,  4018,  4707,   471,   872,   732,   873,    17,
    4018,   -32,   236,   887,   874,   875,   577,   887,   236,  6904,
     236,  6919,   876,   877,   597,  -965,  -965,   546,   546,  -965,
    -965,   601,  -965,  4018,  4397,  4018,    19,   887,   682,  -965,
    -965,  -965,  -965,   879,  4397,  6934,  -965,  4018,  -965,     7,
     891,  -965,  -965,  4018,  3819,  -965,  -965,   887,  -965,  -965,
     567,    11,    11,  -965,   912,   912,   912,  2824,  4397,   646,
     894,   567,   125,   302,  4018,  4018,  4018,  4018,  4018,  4397,
    4397,  4018,  4018,   642,  4018,  4397,  4018,   888,  4397,   893,
    4397,   899,  4018,  4397,  4018,  4018,  -965,  1003,  4018,  4018,
    4018,  4018,  4397,  -965,  -965,  -965,  4018,  4018,  1268,  4018,
    4018,  4018,  4018,  2426,  2625,   674,   674,  4018,  4018,  4018,
    4018,  4018,  4018,  4018,  4018,  4018,  4018,  4018,  4018,  2625,
    4018,  4018,  4018,  4018,  4018,  4018,  4018,  4018,  3023,  4397,
    4397,  4397,  4397,  4397,  4018,  4018,  4018,  3222,  4018,  4397,
    4018,  4397,  4018,  4397,  4397,   451,  1636,  1812,  1908,  4397,
    4397,  4397,  4397,  4397,  4397,  4397,  4397,  2625,  4397,  -965,
    -965,  4397,  4018,  4397,  4397,  4397,  4397,  4397,   900,   902,
    4397,   912,  4397,   912,  4397,  4397,  4397,  4018,  4018,  4397,
    4397,  4397,  4397,  4018,  4397,  4397,  4397,  4397,   904,  4397,
    4018,  4397,  1050,   353,  1122,  4397,  4397,  4397,  4397,  4397,
    4397,  4397,  4397,  -965,  -965,  -965,  4018,  4018,  4018,  4018,
    4018,  4018,  4018,  4018,  4018,  4018,  4018,  4018,  -127,  -965,
    -965,  -965,   887,   905,   567,   907,  1066,   887,   393,  -965,
    -965,  -965,  -965,   910,   911,   913,  -965,   916,   917,   919,
    -965,   236,   887,   920,  -965,   236,   887,  1110,   483,  1114,
    4707,  4018,   929,  4397,  -965,  -965,  4018,   236,   119,   219,
     931,    18,  -965,  1152,  -965,  -965,   686,  4018,  4018,  -965,
    -965,   259,  -965,  -965,    44,  6981,   567,   887,   479,  4197,
    4018,   567,  4018,  -965,   -32,  -965,  -965,  4018,  4397,  -965,
    4018,     7,  4018,  4018,   932,   934,   935,   936,  -965,  1148,
    -126,  4018,  4018,  4018,  4018,  1621,  7007,  7039,  1637,  1652,
     -81,   326,  7100,  7115,  -965,  1946,   375,  7147,  -965,  -148,
    -965,   398,  -965,  7173,    -8,  2027,  2042,  -965,   937,     7,
       7,   887,   567,   707,   938,   946,  7205,  7220,  2441,  7235,
    7281,  7313,   948,   102,   952,   951,   955,   957,   958,   967,
     959,   970,     7,  7339,  2640,  2839,  3038,  3237,  3436,   576,
    3635,   681,  3834,  4033,   969,  4215,  4415,  4622,  4755,  4811,
    5021,  5168,  7401,  -965,  5199,    -7,   437,   484,   566,    46,
    7416,  7447,   498,   700,  -965,  5231,  5287,    47,  5302,   -98,
    5334,    88,    94,  -965,   115,  -965,   171,  -965,   214,  -965,
     251,   252,   269,   270,   596,   600,   272,   297,   303,   561,
     972,   -97,   973,   974,   355,  5365,   361,   -80,   608,   617,
     618,  -965,  -965,   619,  -213,   620,  -135,   634,   366,   384,
    7479,  5397,   636,   637,   640,   643,  7505,   647,   667,   394,
     428,  -965,   670,  5412,   684,  -965,  -965,   567,   567,   567,
     567,   567,   567,   567,  -965,  4018,  4018,   814,   930,   445,
      28,    40,   111,   205,  -965,   -20,   -20,  1050,  1050,  -965,
    -965,  -965,  4707,  -965,  -965,  4018,  -965,  -965,  -965,  -965,
      72,    72,  -965,  -965,   300,  -965,  -965,   348,  4018,  -965,
    1160,  -965,  -965,  -965,  -965,  -965,  -965,  -965,  -965,   746,
    7520,  4018,   -47,  5427,  4493,  -965,  -965,  4018,  4018,  -965,
    -965,  4018,  -965,   890,   975,   977,   981,   982,  7535,  7582,
     983,   995,  -965,  -965,  -965,  4018,  1130,  1142,  -965,   685,
    7613,   887,  -965,  -965,   693,  -965,  4018,  7645,  7701,  -965,
    4018,  4018,  4018,  -965,  -965,   236,   887,   236,   887,  7716,
    7748,  -965,  4397,  4018,  -965,  -965,  -965,  4018,  4018,  4018,
    -965,  4018,  4018,  4018,  -965,  4018,  4018,  -965,  -965,  -965,
    4707,  4018,  4018,  4018,  -965,  -965,  -965,  -965,  -965,  4018,
    4018,  -965,  4018,  4018,  4018,  -965,  4397,  -965,  4293,  -965,
     996,   997,  -965,  -965,  4018,  4018,  4018,  4018,  -965,  -965,
    -965,  -965,  -965,  4018,  -965,  -965,  4018,  -965,  -965,  -965,
    -965,  -965,  -965,  -965,  -965,  -965,  -965,  -965,  4018,  -965,
    -965,  4018,  4018,  4018,  -965,  4018,  4018,  -965,  4397,  -965,
    -965,  -965,  -965,  -965,  4018,  -965,  -965,  -965,  -965,  -965,
    -965,  -965,  -965,  -965,  -965,  -965,  4397,  4397,  -965,  -965,
    -965,  -965,  -965,  4397,  -965,  -965,  -965,  -965,  -965,  -965,
    4018,  -965,  4018,  4018,  4018,  1226,  4397,  -965,  1226,  4397,
    -965,  4397,  -965,  -965,  4018,  -965,  4018,  4018,  4018,  4018,
    4018,  4397,  4397,  -965,  -965,  4018,  -965,  4018,  1268,   226,
    4018,    21,   887,  -965,  1001,  -965,  1002,  1004,  1010,  -965,
    1011,  1012,  -965,  -965,  -965,   914,  4707,  -965,  -965,  -965,
    4018,  7779,  4397,  1176,  -965,  4397,   567,   236,   119,  7811,
     890,   890,  5468,  1014,  1016,  -965,  1018,  -965,  -965,  -965,
    -965,  4018,  4018,  -965,  -965,  7826,  2625,  2625,  4397,  4397,
    4397,  -965,  4018,  4018,  1017,  5500,  5531,   903,  4397,  4397,
     431,  7841,  7882,  7914,  7945,  8007,  5593,  5608,  8022,  8048,
    -965,   887,     7,  -965,  1019,  5634,  5666,  5697,  5712,  5727,
     443,  1022,   -22,  -965,  -965,  5774,  5800,  1023,    -4,  5832,
    5893,  5908,  5940,  5966,   949,  5998,  6013,   -16,  6028,   177,
     188,   499,  6074,  8080,  8111,  6106,  -123,   503,   -84,   514,
     516,  8126,  8141,  8188,  6132,  8214,  8246,   517,   534,  6194,
    6209,    50,  -965,  -965,  -965,    72,    72,  -965,  -965,  -965,
    -965,  4018,  1216,  1222,  1218,  6240,  4018,   535,  1030,   212,
    -965,  4018,  -965,  -965,  -965,  -965,  -965,  -965,  1031,  1032,
     887,   887,  4397,  -965,  -965,   567,   567,   713,  8307,   887,
    -965,  1188,  1191,  4018,  1193,   721,   567,  -965,  4018,  4018,
    4018,  4018,  4018,  -965,  -965,  4018,  4018,  4018,   925,  -965,
    -965,  -965,  -965,  -965,  -965,  -965,  4397,  -965,  -965,  -965,
    -965,  4018,  -965,  -965,  -965,  -965,  -965,  4018,  -965,  -965,
    -965,  4397,  -965,  -965,  4018,  -965,  4018,  -965,  -965,  -965,
    4397,  4018,  -965,  4397,  -965,  -965,  4397,  -965,  -965,  -965,
    4397,  4018,  4018,  -965,  4018,  4018,  -965,  -965,  -965,  -965,
    4018,  -965,  -965,  -965,  -965,  -965,  1221,   926,  6272,  1212,
    4018,  4397,  6298,   890,  1038,  1039,   890,  -965,  -965,   567,
    4397,  4397,  4397,  4397,  6313,  4397,  4018,  6328,  6375,  8322,
    8354,  6406,  6438,  6494,  -965,  1041,  1042,   -17,  -965,   552,
    8380,  6509,   553,  6541,  6572,   555,  6604,   556,   558,   579,
    6619,  6634,  8412,  8427,    67,  4707,  5127,  4018,  1228,  -965,
    1044,  -965,  1045,  8442,   580,  -965,  -965,  -965,  -965,  -965,
     567,   567,   567,   567,  1207,   567,   887,  -965,  -965,  4018,
    4018,  -965,  -965,  -965,  1051,  1052,   925,  -965,  -965,  4018,
    -965,  -965,  -965,  -965,  -965,  -965,  -965,  -965,  -965,  -965,
    -965,  4018,  4018,  4018,  -965,  1218,  1245,   631,  4707,  -965,
    4397,  4018,  4018,  -965,  1152,  4397,  6675,  6707,  -965,  -965,
    -965,  4707,  6738,  8488,  8520,   887,  4707,  -965,  -965,  1218,
     564,   213,  8546,  6800,   890,   567,  -965,  -965,    30,  -965,
    4018,  4018,  1218,  4707,  -965,  -965,  -965,  -965,  -965,  -965,
    -965,  4397,  -965,  4018,  -965,  -965,  -965,  -965,  -965,  6815,
    6841,   644,  1218,   592,  6873,  -965,  -965,  -965,  -965,  -965,
    -965,  -965,  -965,  1282,  1221,  -965,  -965,  -965,  -965,  -965
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,   141,     0,     0,     0,   367,     0,     0,     0,   112,
     390,   425,   430,    18,     0,     0,     0,     0,    31,    33,
     368,     0,   352,   352,     0,   369,    25,    27,   405,   417,
       0,   498,    55,    67,     0,   109,   110,     0,     0,     0,
       0,    65,     0,     0,     0,     0,     0,     0,     0,   142,
     143,     0,   100,     0,     0,     0,     0,     0,     0,     0,
       0,   101,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     2,
       9,    17,     8,     0,    12,    46,    48,    14,    29,    30,
      28,     0,    20,    21,    24,    23,    22,    35,    36,   340,
     236,   163,   341,   342,   343,   166,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   177,
       0,     0,     0,     0,     0,     0,     0,   296,   299,   302,
     305,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     192,   194,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   164,     0,   250,
     230,   235,   165,     0,     0,     0,     0,     0,     0,     1,
       0,   352,     0,   352,     0,     0,    16,   345,   344,    37,
      38,    45,     0,     0,     0,     0,    19,    50,   354,    51,
      49,   370,    26,     0,    16,   449,     0,   502,     0,     0,
     478,   494,    69,    68,     0,     0,    70,   111,    60,     0,
      62,     0,   470,   472,    63,   468,   474,     0,     0,   475,
     337,    64,    66,     0,    96,     0,     0,   513,     0,    93,
      98,    86,    47,     0,     0,     0,    74,     0,    57,    79,
       0,    95,    94,     0,     0,   144,   145,    99,    13,    15,
     113,     0,     0,    85,     0,     0,     0,     0,     0,     0,
       0,   114,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     7,     0,     0,     0,
       0,     0,     0,   359,   352,   352,     0,     0,   220,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   352,
     352,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   242,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     3,   218,   216,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     4,
       5,     6,   214,     0,   146,     0,     0,   426,     9,    39,
      40,    41,    43,   373,   374,    32,   371,   379,   380,    34,
     377,   357,   358,   353,   355,   410,   409,     0,     9,     0,
      16,     0,     0,     0,   499,   500,     0,   481,   483,    52,
       0,     0,    56,   496,   352,   352,     0,     0,     0,   352,
     352,     0,   339,   338,     0,     0,    97,   512,     0,     0,
       0,    73,     0,    78,   494,   153,   152,     0,     0,    75,
       0,    81,     0,     0,   161,     0,     0,     0,   102,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   128,     0,     0,     0,   131,     0,
     134,     0,   136,     0,     0,     0,     0,    10,     0,     0,
       0,   215,   151,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   276,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   178,     0,     0,     0,     0,     0,
       0,     0,     0,   297,     0,   300,     0,   303,     0,   306,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   193,   195,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   333,     0,     0,     0,   168,   251,   245,   247,   249,
     246,   248,   243,   244,   167,     0,     0,   223,   225,   227,
     224,   226,   221,   222,   241,   238,   237,   239,   240,   350,
     351,   391,    16,   437,   435,     0,   436,   432,   434,   431,
       0,     0,   352,   352,     0,   352,   352,     0,     0,   407,
     411,   424,   422,   423,   420,   419,   421,   418,   439,     9,
       0,     0,     0,     0,     0,   479,    53,    54,     0,   486,
     488,     0,   497,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   469,   476,   477,     0,     0,     0,   156,   155,
     159,   254,    58,    76,    89,    80,     0,     0,     0,   352,
       0,     0,     0,   103,   104,   105,   106,   107,   108,     0,
       0,   118,     0,     0,   121,   122,   123,     0,     0,     0,
     129,     0,     0,     0,   132,     0,     0,   138,   139,   140,
      16,     0,     0,     0,   365,   366,   360,   318,   206,     0,
       0,   309,     0,     0,     0,   319,     0,   320,     0,   313,
       0,     0,   231,   232,     0,     0,     0,     0,   255,   256,
     257,   258,   259,     0,   260,   262,     0,   263,   265,   266,
     228,   272,   273,   267,   269,   270,   271,   268,     0,   275,
     280,     0,     0,     0,   279,     0,     0,   176,     0,   173,
     179,   180,   281,   204,     0,   282,   205,   181,   182,   295,
     298,   301,   304,   185,   183,   184,     0,     0,   186,   288,
     187,   294,   293,     0,   196,   289,   188,   290,   189,   292,
       0,   190,     0,     0,     0,     0,     0,   199,     0,     0,
     201,     0,   325,   209,     0,   327,     0,     0,     0,     0,
       0,     0,     0,   210,   211,     0,   212,     0,   219,   217,
       0,     9,   433,   514,    42,   516,    44,     0,     0,   372,
       0,     0,   378,   356,   408,   414,    16,   451,   452,   450,
       0,     0,     0,   503,   501,     0,   484,   482,   483,     0,
       0,     0,     0,   464,   466,   495,   461,   346,   348,   352,
     352,     0,     0,   471,   473,    71,     0,     0,     0,     0,
       0,    77,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      11,    87,     0,    92,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   252,   253,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   429,   428,   427,     0,     0,   375,   376,   381,
     382,     0,     0,     0,   440,     0,     0,     0,     0,     0,
     480,     0,   487,   489,   490,   352,   352,   462,     0,     0,
      59,    61,     0,   157,   158,   154,   160,    90,    83,    84,
     162,     0,     0,     0,     0,   116,   117,   119,     0,     0,
       0,     0,     0,   130,   133,     0,     0,     0,   383,   307,
     308,   310,   311,   312,   321,   322,     0,   323,   233,   234,
     202,     0,   261,   264,   274,   169,   170,     0,   172,   277,
     278,     0,   174,   283,     0,   284,     0,   286,   197,   191,
       0,     0,   208,     0,   315,   198,     0,   317,   200,   229,
       0,     0,     0,   330,     0,     0,   334,   335,   336,   213,
       0,   515,   517,   412,   415,   406,   455,   505,     0,   504,
       0,     0,     0,     0,     0,     0,     0,   347,   349,    72,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    88,   386,   387,     0,   384,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   401,    16,   141,     0,   453,   509,
       0,   506,     0,     0,     0,   492,   491,   465,   467,   463,
      91,    82,   149,   150,     0,   148,   115,   120,   124,     0,
       0,   125,   135,   137,     0,     0,     0,   361,   324,     0,
     171,   175,   285,   287,   291,   207,   314,   316,   326,   328,
     329,     0,     0,     0,   392,   413,     9,   459,    16,   441,
       0,     0,     0,   485,   496,     0,     0,     0,   388,   389,
     385,    16,     0,     0,     0,   402,    16,   460,   456,   454,
       0,     0,     0,     0,     0,   147,   126,   127,     9,   203,
       0,     0,   393,    16,   448,   445,   446,   447,   443,   444,
     442,     0,   510,     0,   507,   493,   364,   363,   362,     0,
       0,     0,   457,     0,     0,   331,   332,   396,   398,   399,
     400,   395,   397,   403,   455,   511,   508,   404,   394,   458
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -965,  -965,  -965,  -225,  -965,  -965,  1283,   462,  -965,  -965,
    -965,  -965,  -965,  -965,  -965,  1241,  -299,  -965,  -965,  -283,
     994,  -965,  1242,    -2,  -965,  -965,   933,  -361,   109,  -965,
     762,   -30,   -14,  -965,     3,     5,   157,  -965,  -965,   549,
    1293,  -965,  -965,  -965,  -965,  -965,  -965,  -965,   557,  -965,
     560,  -965,    34,  -965,  -965,  -965,  -965,  -965,  -965,  -965,
    -965,  -965,  -965,  -965,   221,  -965,  -965,  -965,  -965,  -965,
    -965,  -965,  -965,  -965,  -965,  -965,  -965,  -965,  -965,  -965,
    -965,  -965,  -965,  -965,  -965,  -965,  -965,  -965,  -965,   -49,
    -965,  -965,  -965,  -964,  -965,  -965,  -965,   772,  -965,  -965,
     330,   769,  -965,  -965,  -965,  -965,  -965,    16,  -965,    38,
    -965,  -965
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     6,    89,    90,   347,   830,    91,    92,   244,   245,
     740,   741,   261,   544,    93,    94,   547,    95,    96,   555,
     216,   217,    97,   295,   716,   715,   608,   609,   296,   219,
     279,   220,   239,   266,   221,   222,   247,   248,   503,   504,
     100,   593,  1024,  1301,  1338,   836,   101,   495,   496,   499,
     500,  1217,  1218,   102,   234,   950,  1306,  1341,  1353,  1284,
    1358,   103,   253,   750,   507,   965,  1235,  1083,  1236,   104,
     254,   757,   105,   235,   732,  1074,   106,   236,   739,   107,
     509,   966,  1186,  1310,  1330,   108,   510,   969,  1289,  1238,
    1323,  1354,  1308,   985,  1196,   986,   274,   275,   281,   519,
     765,   522,   980,   981,  1193,  1294,   523,   773,   260,   288,
     954,   956
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     218,   240,   241,   479,    98,   611,    99,   226,   545,   227,
     280,   488,   552,   553,   230,   243,  1092,  1093,   926,   545,
     927,   514,   769,   545,   515,   770,   520,   282,   255,   508,
     538,   263,   556,   557,   267,   269,   271,  1072,   251,   109,
     287,   287,   287,   112,   113,   114,   276,   109,   232,   307,
     252,   112,   113,   114,   783,  1336,   226,   473,   227,   464,
     465,   287,  1180,   348,   349,  1073,   466,   467,   468,   469,
     470,   471,   472,   473,  1337,   350,   237,   229,   462,   238,
    1283,   292,   293,   823,   256,   824,   257,   258,   294,   455,
     456,   457,   458,   459,   460,   461,   929,   306,   930,   462,
     462,   320,   470,   471,   472,   473,   705,   804,  1163,   313,
    1164,   491,   492,   464,   465,   471,   472,   473,   358,   314,
     466,   467,   468,   469,   470,   471,   472,   473,   462,   462,
     464,   465,   315,   894,   913,   895,   914,   466,   467,   468,
     469,   470,   471,   472,   473,   462,   462,  1166,   684,  1167,
     686,   920,   816,   921,   464,   465,   299,   300,     7,     8,
     316,   466,   467,   468,   469,   470,   471,   472,   473,   301,
     764,   231,   455,   456,   457,   458,   459,   460,   461,   462,
     249,   317,   464,   465,   972,   462,   973,   472,   473,   466,
     467,   468,   469,   470,   471,   472,   473,   318,    20,   302,
     303,   304,   521,    25,   462,   233,   305,   476,   477,  1136,
     462,  1137,   452,   454,  1266,  1151,  1267,  1152,   462,   462,
     324,   474,   475,   476,   477,   827,   880,   546,   482,  1246,
     489,   490,  1249,   487,   353,     7,     8,   462,   546,    98,
     325,    99,   546,   264,   265,   462,   502,   532,   533,   516,
     771,   506,   796,   474,   475,   476,   477,    98,   518,    99,
     259,   277,   278,   272,   273,   474,   475,   476,   477,   277,
     278,   326,   462,   462,   327,   474,   475,   476,   477,   884,
     892,   535,   473,   537,   328,   759,    58,    59,    60,   464,
     832,   833,   474,   475,   476,   477,   466,   467,   468,   469,
     470,   471,   472,   473,   493,   494,   455,   456,   457,   458,
     459,   460,   461,   856,   462,   559,   474,   475,   476,   477,
     462,   897,   565,   566,   567,   568,   569,   898,   462,   572,
     573,    53,   575,   846,   577,   847,   474,   475,   476,   477,
     583,   462,   585,   586,   474,   475,   476,   477,   899,   591,
    1335,   462,   497,   498,   596,   597,   563,   598,   599,   600,
     601,   287,   287,    58,    59,    60,   613,   614,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   287,   625,   626,
     627,   628,   629,   630,   631,   632,   634,   329,   483,   346,
     485,   330,   640,   641,   643,   645,   646,   462,   648,   331,
     650,   604,   605,   462,   900,   332,   543,   733,  1154,   734,
    1155,   735,   549,   551,   462,   287,   333,   624,   334,  1156,
     675,  1157,   335,   455,   456,   457,   458,   459,   460,   461,
     474,   475,   476,   477,   736,   690,   691,   737,   462,   462,
     462,   696,   738,  1191,  1331,   705,  1332,   901,   703,   766,
     767,   474,   475,   476,   477,   670,   111,   588,   589,   590,
     463,   115,   462,   351,   717,   718,   719,   720,   721,   722,
     723,   724,   725,   726,   727,   728,   612,   462,   462,   464,
     465,   336,   117,   352,   902,   903,   466,   467,   468,   469,
     470,   471,   472,   473,   337,   462,   462,   751,   462,   752,
     338,   753,   904,   905,   280,   908,   339,   951,   340,   760,
     341,   594,   595,    98,   763,    99,   467,  -438,   469,   470,
     471,   472,   473,   462,   754,   778,   779,   755,   462,   462,
     909,   342,   756,   564,   464,   465,   910,   343,   790,   344,
     791,   466,   467,   468,   469,   470,   471,   472,   473,   109,
     797,   798,   462,   112,   113,   114,   129,   817,   130,   806,
     808,   809,   810,   345,  1056,   786,   787,  1058,   455,   456,
     457,   458,   459,   460,   461,   231,   672,   673,  1324,   462,
    1325,   462,  1326,   152,   153,   154,   705,   462,   917,   158,
     159,   160,   462,   162,   919,   164,   165,   166,   480,   932,
     233,   462,   171,   172,   173,  1327,   821,   176,  1328,   178,
     462,   180,   354,  1329,   182,   355,   184,   933,   356,   186,
     462,   357,   188,   189,   462,   190,   191,   943,   193,   825,
     195,   455,   456,   457,   458,   459,   460,   461,   198,   464,
     465,   474,   475,   476,   477,   359,   466,   467,   468,   469,
     470,   471,   472,   473,   462,   360,   793,   462,  1347,   795,
    1348,   944,  1349,   462,  1117,   361,   208,   209,   881,   462,
     474,   475,   476,   477,   212,   213,  1134,  1307,   606,   607,
     362,   774,   775,   223,   653,  1350,   780,   781,  1351,   363,
     776,   777,   364,  1352,   464,   465,   474,   475,   476,   477,
     365,   466,   467,   468,   469,   470,   471,   472,   473,   366,
     462,   834,   835,   948,   949,   882,   455,   456,   457,   458,
     459,   460,   461,  1127,   462,   462,   953,   955,   367,   462,
     486,   887,  1158,   952,   368,    98,  1165,    99,   369,  1141,
     462,  1084,   462,   462,   464,   465,   502,  1168,   481,  1169,
    1176,   466,   467,   468,   469,   470,   471,   472,   473,   971,
     462,   462,   370,   464,   465,   978,   979,  1177,  1189,   982,
     466,   467,   468,   469,   470,   471,   472,   473,   462,   462,
     371,   462,   462,   995,   462,  1268,  1271,   462,  1274,  1276,
     512,  1277,   462,   462,   911,   967,   968,   883,  1005,  1006,
    1007,   474,   475,   476,   477,   462,   462,   863,   526,   864,
     372,  1011,  1278,  1293,   373,  1012,  1013,  1014,   462,  1015,
    1016,  1017,   462,  1018,  1019,  1355,   462,   906,   531,  1021,
     374,   907,   534,    98,   462,    99,   375,  1025,  1026,   922,
    1027,  1028,  1029,   462,   462,   462,   462,   376,   923,   924,
     925,   928,  1035,  1036,   377,  1038,   474,   475,   476,   477,
     462,  1039,   462,   462,  1040,   931,   462,   936,   937,   462,
     378,   938,   462,   462,   939,   574,  1041,   561,   941,  1042,
    1043,  1044,   379,  1045,  1046,   467,   468,   469,   470,   471,
     472,   473,  1048,   462,   983,   984,   462,   380,   942,   957,
     958,   945,   960,   961,   381,  1001,   474,   475,   476,   477,
     462,   462,   866,   539,   867,   947,   998,   554,  1052,   462,
    1053,  1054,  1055,   382,  1000,   474,   475,   476,   477,  1215,
    1216,   888,  1061,   889,  1062,  1063,  1064,  1065,  1066,   462,
     383,  1022,  1023,  1069,  1200,  1070,   384,   462,  1071,   385,
     464,   465,  1206,  1081,  1082,   386,  1004,   466,   467,   468,
     469,   470,   471,   472,   473,  1037,   464,   465,  1085,    98,
     387,    99,   388,   466,   467,   468,   469,   470,   471,   472,
     473,     1,     2,     3,     4,     5,  1239,  1240,   389,  1100,
    1101,   390,   391,   392,   287,   287,   393,   224,   394,   395,
    1108,  1109,   396,   469,   470,   471,   472,   473,   397,   398,
    1285,  1286,   464,   465,   399,   246,   400,   401,   250,   466,
     467,   468,   469,   470,   471,   472,   473,   262,   402,   403,
     404,   268,   270,   405,  1103,  1104,   286,   406,   407,   474,
     475,   476,   477,   408,   409,   410,   587,   411,   310,   311,
     312,   412,   413,   414,   415,   416,   417,   319,   321,   322,
     323,  1181,  1182,  1309,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,  1318,   430,   431,   506,
     432,  1322,   433,   434,  1188,   435,   436,   437,   438,  1192,
     439,   440,   441,   442,   443,   444,   445,   446,  1342,   447,
     448,   449,   450,   451,   511,   513,   524,   525,   529,   530,
     540,  1204,   474,   475,   476,   477,  1207,  1208,  1209,  1210,
    1211,   578,   548,  1212,  1213,   562,   580,   473,   474,   475,
     476,   477,   582,   681,  1113,   682,  1114,   701,   729,  1220,
     730,   731,   742,   743,   744,  1221,  1098,  1099,   745,   746,
     747,   748,  1223,   749,  1224,   474,   475,   476,   477,  1226,
     758,   761,   772,   768,   799,   800,   801,   802,   831,  1230,
    1231,   837,  1232,  1233,   474,   475,   476,   477,  1234,   838,
    1147,   845,  1148,   848,   849,   464,   465,   850,  1243,   851,
     854,   852,   466,   467,   468,   469,   470,   471,   472,   473,
     853,   855,   870,   964,  1256,   912,   915,   916,   987,   453,
     988,   464,   465,   989,   990,   996,   993,   478,   466,   467,
     468,   469,   470,   471,   472,   473,   484,   997,   994,  1033,
    1034,   607,  1075,  1076,  1088,  1287,  1214,  1077,    98,    98,
      99,    99,   501,  1078,  1079,  1080,  1095,   505,  1096,  1097,
    1110,  1128,  1194,  1195,   517,  1135,  1140,  1296,  1297,  1184,
    1185,    -9,  1190,  1202,  1197,  1198,  1203,  1302,  1205,  1237,
    1242,  1247,  1248,  1264,  1265,  1288,  1290,  1291,   536,  1303,
    1304,  1305,  1295,  -416,  1298,  1299,  1357,   225,   541,  1312,
    1313,    98,  1020,    99,   308,   309,   784,   963,   228,   610,
    1300,   959,  1183,   782,    98,  1359,    99,   962,  1090,    98,
    1314,    99,   560,   792,     0,     0,     0,     0,  1339,  1340,
       0,     0,     0,   570,   571,     0,    98,     0,    99,   576,
       0,  1344,   579,     0,   581,     0,     0,   584,   466,   467,
     468,   469,   470,   471,   472,   473,   592,   474,   475,   476,
     477,     0,     0,     0,     0,   706,     0,   603,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   474,   475,   476,   477,     0,     0,     0,
       0,   803,     0,   635,   636,   637,   638,   639,     0,     0,
     642,     0,     0,   647,     0,   649,     0,   651,   652,   654,
     656,   658,   660,   661,   662,   663,   664,   665,   666,   667,
     668,   669,   671,     0,     0,   674,     0,   676,   677,   678,
     679,   680,     0,     0,   683,     0,   685,     0,   687,   688,
     689,     0,     0,   692,   693,   694,   695,     0,   697,   698,
     699,   700,     0,   702,     0,   704,     0,     0,     0,   707,
     708,   709,   710,   711,   712,   713,   714,     0,     0,   109,
     110,   111,     0,   112,   113,   114,   115,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   116,   117,     0,     0,
       0,     0,     0,   474,   475,   476,   477,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   762,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   118,
     119,   120,   121,   122,   123,   124,     0,     0,     0,     0,
       0,     0,     0,   789,     0,     0,     0,   125,     0,     0,
     126,     0,   794,     0,     0,   289,     0,     0,     0,     0,
       0,     0,     0,   290,     0,   805,   807,   127,   128,     0,
       0,   129,     0,   130,     0,     0,   291,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,     0,   181,   182,
     183,   184,     0,   185,   186,     0,   187,   188,   189,     0,
     190,   191,   192,   193,   194,   195,   196,     0,     0,     0,
       0,   111,   197,   198,   199,     0,   115,     0,   200,     0,
       0,   201,     0,     0,   202,   203,   204,   205,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   117,     0,   206,
     207,   208,   209,     0,     0,   210,     0,   211,     0,   212,
     213,   214,     0,     0,   464,   465,     0,     0,   215,     0,
     285,   466,   467,   468,   469,   470,   471,   472,   473,     0,
     464,   465,     0,     0,     0,     0,     0,   466,   467,   468,
     469,   470,   471,   472,   473,   464,   465,     0,     0,     0,
       0,     0,   466,   467,   468,   469,   470,   471,   472,   473,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   129,   501,   130,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   976,     0,
       0,   977,     0,     0,     0,     0,     0,     0,   152,   153,
     154,     0,     0,     0,   158,   159,   160,     0,   162,     0,
     164,   165,   166,     0,     0,     0,     0,   171,   172,   173,
       0,     0,   176,     0,   178,     0,   180,     0,     0,   182,
       0,   184,     0,     0,   186,     0,  1010,   188,   189,     0,
     190,   191,     0,   193,     0,   195,     0,   111,     0,     0,
       0,     0,   115,   198,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1030,     0,  1032,   117,     0,     0,   474,   475,   476,   477,
       0,   208,   209,     0,   811,     0,     0,     0,     0,   212,
     213,     0,   474,   475,   476,   477,     0,     0,   223,   655,
     814,     0,     0,     0,     0,     0,     0,   474,   475,   476,
     477,     0,  1047,     0,     0,   815,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1049,  1050,     0,     0,     0,     0,     0,  1051,     0,     0,
       0,     0,     0,   111,     0,     0,     0,   129,   115,   130,
    1057,     0,     0,  1059,     0,  1060,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1067,  1068,     0,     0,   117,
       0,     0,     0,     0,   152,   153,   154,     0,     0,     0,
     158,   159,   160,     0,   162,     0,   164,   165,   166,     0,
       0,     0,     0,   171,   172,   173,  1087,     0,   176,  1089,
     178,     0,   180,     0,     0,   182,     0,   184,     0,     0,
     186,     0,     0,   188,   189,     0,   190,   191,     0,   193,
       0,   195,  1105,  1106,  1107,     0,     0,     0,     0,   198,
       0,     0,  1115,  1116,     0,     0,     0,     0,     0,   464,
     465,     0,     0,   129,     0,   130,   466,   467,   468,   469,
     470,   471,   472,   473,     0,     0,     0,   208,   209,     0,
       0,     0,     0,     0,     0,   212,   213,     0,     0,     0,
     152,   153,   154,     0,   223,   657,   158,   159,   160,     0,
     162,     0,   164,   165,   166,     0,     0,     0,     0,   171,
     172,   173,     0,     0,   176,     0,   178,     0,   180,     0,
       0,   182,     0,   184,     0,   505,   186,     0,     0,   188,
     189,     0,   190,   191,     0,   193,     0,   195,     0,     0,
     464,   465,     0,     0,     0,   198,  1199,   466,   467,   468,
     469,   470,   471,   472,   473,   464,   465,     0,     0,     0,
       0,     0,   466,   467,   468,   469,   470,   471,   472,   473,
       0,     0,     0,   208,   209,     0,     0,     0,     0,     0,
    1219,   212,   213,     0,     0,     0,     0,     0,     0,     0,
     223,   659,     0,     0,     0,  1222,     0,     0,     0,     0,
       0,     0,     0,     0,  1225,     0,     0,  1227,     0,     0,
    1228,     0,     0,     0,  1229,     0,     0,     0,     0,     0,
       0,   474,   475,   476,   477,     0,     0,     0,     0,   820,
       0,     0,     0,     0,     0,  1244,     0,     0,     0,     0,
       0,     0,     0,     0,  1250,  1251,  1252,  1253,     0,  1255,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     109,   110,   111,     0,   112,   113,   114,   115,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   474,   475,   476,   477,     0,   116,   117,     0,
     828,     0,     0,     0,     0,     0,     0,   474,   475,   476,
     477,     0,     0,     0,     0,   829,     0,     0,     0,     0,
       0,     0,     0,     0,  1311,     0,     0,     0,     0,  1315,
     118,   119,   120,   121,   122,   123,   124,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   125,     0,
       0,   126,     0,     0,     0,     0,   283,     0,     0,     0,
       0,     0,     0,     0,   284,  1343,     0,     0,   127,   128,
       0,     0,   129,     0,   130,     0,     0,     0,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,     0,   181,
     182,   183,   184,     0,   185,   186,     0,   187,   188,   189,
       0,   190,   191,   192,   193,   194,   195,   196,     0,     0,
       0,     0,     0,   197,   198,   199,     0,     0,     0,   200,
       0,     0,   201,     0,     0,   202,   203,   204,   205,   109,
     110,   111,     0,   112,   113,   114,   115,     0,     0,     0,
     206,   207,   208,   209,     0,     0,   210,     0,   211,     0,
     212,   213,   214,     0,     0,     0,   116,   117,     0,   215,
       0,   285,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   118,
     119,   120,   121,   122,   123,   124,     0,     0,     0,     0,
       0,     0,     0,     0,   464,   465,     0,   125,     0,     0,
     126,   466,   467,   468,   469,   470,   471,   472,   473,     0,
       0,     0,     0,   602,     0,     0,     0,   127,   128,     0,
       0,   129,     0,   130,     0,     0,     0,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,     0,   181,   182,
     183,   184,     0,   185,   186,     0,   187,   188,   189,     0,
     190,   191,   192,   193,   194,   195,   196,     0,     0,     0,
       0,     0,   197,   198,   199,     0,     0,     0,   200,     0,
       0,   201,     0,     0,   202,   203,   204,   205,   109,   110,
     111,     0,   112,   113,   114,   115,     0,     0,     0,   206,
     207,   208,   209,     0,     0,   210,     0,   211,     0,   212,
     213,   214,     0,     0,     0,   116,   117,     0,   215,     0,
     285,     0,     0,     0,     0,     0,   474,   475,   476,   477,
       0,     0,     0,     0,   841,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   118,   119,
     120,   121,   122,   123,   124,     0,     0,     0,     0,     0,
       0,     0,     0,   464,   465,     0,   125,     0,     0,   126,
     466,   467,   468,   469,   470,   471,   472,   473,     0,     0,
       0,     0,     0,     0,     0,     0,   127,   128,     0,     0,
     129,     0,   130,     0,     0,     0,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,     0,   181,   182,   183,
     184,     0,   185,   186,     0,   187,   188,   189,     0,   190,
     191,   192,   193,   194,   195,   196,     0,     0,     0,     0,
       0,   197,   198,   199,     0,     0,     0,   200,     0,     0,
     201,     0,     0,   202,   203,   204,   205,   109,   110,   111,
       0,   112,   113,   114,   115,     0,     0,     0,   206,   207,
     208,   209,     0,     0,   210,     0,   211,     0,   212,   213,
     214,     0,     0,     0,   116,   117,     0,   215,     0,   285,
       0,     0,     0,     0,     0,   474,   475,   476,   477,     0,
       0,     0,     0,   858,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   118,   119,   120,
     121,   122,   123,   124,     0,     0,     0,     0,     0,     0,
       0,     0,   464,   465,     0,   125,     0,     0,   126,   466,
     467,   468,   469,   470,   471,   472,   473,     0,     0,     0,
       0,     0,     0,     0,     0,   127,   128,     0,     0,   129,
       0,   130,     0,     0,     0,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,     0,   181,   182,   183,   184,
       0,   185,   186,     0,   187,   188,   189,     0,   190,   191,
     192,   193,   194,   195,   196,     0,     0,     0,     0,     0,
     197,   198,   199,     0,     0,     0,   200,     0,     0,   201,
       0,     0,   202,   203,   204,   205,   109,   110,   111,     0,
     112,   113,   114,   115,     0,     0,     0,   206,   207,   208,
     209,     0,     0,   210,     0,   211,     0,   212,   213,   214,
       0,     0,     0,   116,   117,     0,   215,   558,     0,     0,
       0,     0,     0,     0,   474,   475,   476,   477,     0,     0,
       0,     0,   859,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   118,   119,   120,   121,
     122,   123,   124,     0,     0,     0,     0,     0,     0,     0,
       0,   464,   465,     0,   125,     0,     0,   126,   466,   467,
     468,   469,   470,   471,   472,   473,     0,     0,     0,     0,
       0,     0,     0,     0,   127,   128,     0,     0,   129,     0,
     130,     0,     0,     0,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,     0,   181,   182,   183,   184,     0,
     185,   186,     0,   187,   188,   189,     0,   190,   191,   192,
     193,   194,   195,   196,     0,     0,     0,     0,     0,   197,
     198,   199,     0,     0,     0,   200,     0,     0,   201,     0,
       0,   202,   203,   204,   205,   109,   110,   111,     0,   112,
     113,   114,   115,     0,     0,     0,   206,   207,   208,   209,
       0,     0,   210,     0,   211,     0,   212,   213,   214,     0,
       0,     0,   116,   117,     0,   215,   633,     0,     0,     0,
       0,     0,     0,   474,   475,   476,   477,     0,     0,     0,
       0,   860,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   118,   119,   120,   121,   122,
     123,   124,     0,     0,     0,     0,     0,     0,     0,     0,
     464,   465,     0,   125,     0,     0,   126,   466,   467,   468,
     469,   470,   471,   472,   473,     0,     0,     0,     0,     0,
       0,     0,     0,   127,   128,     0,     0,   129,     0,   130,
       0,     0,     0,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,     0,   181,   182,   183,   184,     0,   185,
     186,     0,   187,   188,   189,     0,   190,   191,   192,   193,
     194,   195,   196,     0,     0,     0,     0,     0,   197,   198,
     199,     0,     0,     0,   200,     0,     0,   201,     0,     0,
     202,   203,   204,   205,   109,   110,   111,     0,   112,   113,
     114,   115,     0,   297,     0,   206,   207,   208,   209,     0,
       0,   210,     0,   211,     0,   212,   213,   214,     0,     0,
       0,   116,   117,     0,   215,   644,     0,     0,     0,     0,
       0,     0,   474,   475,   476,   477,     0,     0,     0,     0,
     861,     0,     0,     0,   298,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   118,   119,   120,   121,   122,   123,
     124,     0,     0,     0,     0,     0,     0,     0,     0,   464,
     465,     0,   125,     0,     0,   126,   466,   467,   468,   469,
     470,   471,   472,   473,     0,     0,     0,     0,     0,     0,
       0,     0,   127,   128,     0,     0,   129,     0,   130,     0,
       0,     0,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,     0,   181,   182,   183,   184,     0,   185,   186,
       0,   187,   188,   189,     0,   190,   191,   192,   193,   194,
     195,   196,     0,     0,     0,     0,     0,   197,   198,   199,
       0,     0,     0,   200,     0,     0,   201,     0,     0,   202,
     203,   204,   205,   109,   110,   111,     0,   112,   113,   114,
     115,     0,     0,     0,   206,   207,   208,   209,     0,     0,
     210,     0,   211,     0,   212,   213,   214,     0,     0,     0,
     116,   117,     0,   215,   242,     0,     0,     0,     0,     0,
       0,   474,   475,   476,   477,     0,     0,     0,     0,   862,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   118,   119,   120,   121,   122,   123,   124,
       0,     0,     0,     0,     0,     0,     0,     0,   464,   465,
       0,   125,     0,     0,   126,   466,   467,   468,   469,   470,
     471,   472,   473,     0,     0,     0,     0,     0,     0,     0,
       0,   127,   128,     0,     0,   129,     0,   130,     0,     0,
       0,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,     0,   181,   182,   183,   184,     0,   185,   186,     0,
     187,   188,   189,     0,   190,   191,   192,   193,   194,   195,
     196,     0,     0,     0,     0,     0,   197,   198,   199,     0,
       0,     0,   200,     0,     0,   201,     0,     0,   202,   203,
     204,   205,   109,   110,   111,     0,   112,   113,   114,   115,
       0,   550,     0,   206,   207,   208,   209,     0,     0,   210,
       0,   211,     0,   212,   213,   214,     0,     0,     0,   116,
     117,     0,   215,     0,     0,     0,     0,     0,     0,     0,
     474,   475,   476,   477,     0,     0,     0,     0,   865,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   118,   119,   120,   121,   122,   123,   124,     0,
       0,     0,     0,     0,     0,     0,     0,   464,   465,     0,
     125,     0,     0,   126,   466,   467,   468,   469,   470,   471,
     472,   473,     0,     0,     0,     0,     0,     0,     0,     0,
     127,   128,     0,     0,   129,     0,   130,     0,     0,     0,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
       0,   181,   182,   183,   184,     0,   185,   186,     0,   187,
     188,   189,     0,   190,   191,   192,   193,   194,   195,   196,
       0,     0,     0,     0,     0,   197,   198,   199,     0,     0,
       0,   200,     0,     0,   201,     0,     0,   202,   203,   204,
     205,   109,   110,   111,     0,   112,   113,   114,   115,     0,
       0,     0,   206,   207,   208,   209,     0,     0,   210,     0,
     211,     0,   212,   213,   214,     0,     0,     0,   116,   117,
       0,   215,     0,     0,     0,     0,     0,     0,     0,   474,
     475,   476,   477,     0,     0,     0,     0,   868,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   118,   119,   120,   121,   122,   123,   124,     0,     0,
       0,     0,     0,     0,     0,     0,   464,   465,     0,   125,
       0,     0,   126,   466,   467,   468,   469,   470,   471,   472,
     473,     0,     0,     0,     0,     0,     0,     0,     0,   127,
     128,     0,     0,   129,     0,   130,     0,     0,     0,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,     0,
     181,   182,   183,   184,     0,   185,   186,     0,   187,   188,
     189,     0,   190,   191,   192,   193,   194,   195,   196,     0,
       0,     0,   111,     0,   197,   198,   199,   115,     0,     0,
     200,     0,     0,   201,     0,     0,   202,   203,   204,   205,
       0,     0,     0,     0,     0,     0,     0,     0,   117,     0,
       0,   206,   207,   208,   209,     0,     0,   210,     0,   211,
       0,   212,   213,   214,     0,     0,     0,     0,     0,     0,
     215,     0,     0,     0,     0,     0,     0,     0,   474,   475,
     476,   477,     0,     0,     0,     0,   869,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   464,   465,
       0,     0,     0,     0,     0,   466,   467,   468,   469,   470,
     471,   472,   473,     0,   788,     0,     0,     0,   111,     0,
       0,     0,   129,   115,   130,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   117,     0,     0,     0,     0,   152,
     153,   154,     0,     0,     0,   158,   159,   160,     0,   162,
       0,   164,   165,   166,     0,     0,     0,     0,   171,   172,
     173,     0,     0,   176,     0,   178,     0,   180,     0,     0,
     182,     0,   184,     0,     0,   186,     0,     0,   188,   189,
       0,   190,   191,     0,   193,     0,   195,     0,     0,     0,
       0,     0,     0,     0,   198,     0,     0,     0,     0,     0,
    1031,     0,     0,     0,     0,     0,     0,     0,   129,     0,
     130,     0,   111,     0,     0,     0,     0,   115,     0,     0,
       0,     0,   208,   209,     0,     0,     0,     0,     0,     0,
     212,   213,     0,     0,     0,   152,   153,   154,   117,   223,
       0,   158,   159,   160,     0,   162,     0,   164,   165,   166,
     474,   475,   476,   477,   171,   172,   173,     0,   871,   176,
       0,   178,     0,   180,     0,     0,   182,     0,   184,     0,
       0,   186,     0,     0,   188,   189,     0,   190,   191,     0,
     193,     0,   195,     0,     0,     0,     0,     0,   464,   465,
     198,     0,     0,     0,     0,   466,   467,   468,   469,   470,
     471,   472,   473,     0,     0,     0,     0,     0,   111,     0,
       0,     0,   129,   115,   130,     0,     0,     0,   208,   209,
       0,     0,     0,     0,     0,     0,   212,   213,     0,     0,
       0,     0,     0,     0,   117,   223,     0,     0,     0,   152,
     153,   154,     0,     0,     0,   158,   159,   160,     0,   162,
       0,   164,   165,   166,     0,     0,     0,     0,   171,   172,
     173,     0,     0,   176,     0,   178,     0,   180,     0,     0,
     182,     0,   184,     0,     0,   186,     0,     0,   188,   189,
       0,   190,   191,     0,   193,     0,   195,     0,     0,     0,
       0,     0,     0,     0,   198,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   129,     0,
     130,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   208,   209,     0,     0,     0,     0,     0,     0,
     212,   213,     0,     0,     0,   152,   153,   154,     0,   223,
       0,   158,   159,   160,     0,   162,     0,   164,   165,   166,
     474,   475,   476,   477,   171,   172,   173,     0,   872,   176,
       0,   178,     0,   180,     0,     0,   182,     0,   184,     0,
       0,   186,     0,     0,   188,   189,     0,   190,   191,     0,
     193,     0,   195,     0,     0,     0,     0,     0,     0,     0,
     198,     0,     0,     0,     0,   464,   465,     0,     0,     0,
       0,     0,   466,   467,   468,   469,   470,   471,   472,   473,
       0,     0,     0,     0,     0,     0,     0,     0,   208,   209,
       0,     7,     8,     9,     0,     0,   212,   213,    10,     0,
       0,     0,    11,     0,    12,   975,    13,    14,    15,    16,
      17,  -367,     0,    18,    19,    20,    21,    22,    23,    24,
      25,     0,    26,    27,    28,     0,     0,     0,     0,    29,
       0,     0,    30,     0,     0,     0,     0,     0,     0,    31,
      32,    33,    34,    35,    36,     0,     0,     0,    37,    38,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    39,    40,    41,    42,    43,
      44,     0,     0,     0,     0,     0,    45,    46,    47,  -141,
    -141,    48,    49,    50,     0,    51,    52,    53,     0,     0,
      54,  -141,     0,    55,     0,    56,    57,     0,   464,   465,
       0,     0,     0,     0,     0,   466,   467,   468,   469,   470,
     471,   472,   473,     0,     0,     0,     0,     0,     0,    58,
      59,    60,     0,     0,     0,     0,    61,   474,   475,   476,
     477,     0,     0,     0,     0,   873,     0,     0,     0,     0,
       0,     0,     0,     0,    62,     0,     0,     0,    63,     0,
       0,     0,     0,    64,   464,   465,    65,     0,     0,     0,
      66,   466,   467,   468,   469,   470,   471,   472,   473,     0,
       0,     0,     0,     0,     0,     0,    67,    68,    69,     0,
      70,    71,     0,    72,    73,     0,     0,     0,     0,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
       0,     7,     8,     9,    85,    86,     0,    87,    10,    88,
       0,     0,    11,     0,    12,     0,    13,    14,    15,    16,
      17,  -367,     0,    18,    19,    20,    21,    22,    23,    24,
      25,     0,    26,    27,    28,     0,     0,     0,     0,    29,
     -16,   -16,    30,     0,     0,     0,     0,     0,     0,    31,
      32,    33,    34,    35,    36,     0,     0,     0,    37,    38,
     474,   475,   476,   477,     0,     0,     0,     0,   874,     0,
       0,     0,     0,     0,     0,    39,    40,    41,    42,    43,
      44,     0,     0,     0,     0,     0,    45,    46,    47,     0,
       0,    48,    49,    50,     0,    51,    52,    53,     0,     0,
      54,     0,     0,    55,     0,    56,    57,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   474,   475,   476,   477,
       0,     0,     0,     0,   875,     0,     0,     0,     0,    58,
      59,    60,     0,     0,     0,     0,    61,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    62,     0,     0,     0,    63,     0,
       0,     0,     0,    64,   464,   465,    65,     0,     0,     0,
      66,   466,   467,   468,   469,   470,   471,   472,   473,     0,
       0,     0,     0,     0,     0,     0,    67,    68,    69,     0,
      70,    71,     0,    72,    73,     0,     0,     0,     0,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
       0,     7,     8,     9,    85,    86,     0,    87,    10,    88,
       0,     0,    11,     0,    12,     0,    13,    14,    15,    16,
      17,  -367,     0,    18,    19,    20,    21,    22,    23,    24,
      25,     0,    26,    27,    28,   -16,     0,     0,     0,    29,
     -16,     0,    30,     0,     0,     0,     0,     0,     0,    31,
      32,    33,    34,    35,    36,     0,     0,     0,    37,    38,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    39,    40,    41,    42,    43,
      44,     0,     0,     0,     0,     0,    45,    46,    47,     0,
       0,    48,    49,    50,     0,    51,    52,    53,     0,     0,
      54,   464,   465,    55,     0,    56,    57,     0,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   475,   476,   477,
       0,     0,     0,     0,   876,     0,     0,     0,     0,    58,
      59,    60,   464,   465,     0,     0,    61,     0,     0,   466,
     467,   468,   469,   470,   471,   472,   473,     0,     0,     0,
       0,     0,     0,     0,    62,     0,     0,     0,    63,     0,
       0,     0,     0,    64,   464,   465,    65,     0,     0,     0,
      66,   466,   467,   468,   469,   470,   471,   472,   473,     0,
       0,     0,     0,     0,     0,     0,    67,    68,    69,     0,
      70,    71,     0,    72,    73,     0,     0,     0,     0,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
       0,     0,     0,     0,    85,    86,     0,    87,     0,    88,
     464,   465,     0,     0,     0,     0,     0,   466,   467,   468,
     469,   470,   471,   472,   473,   464,   465,     0,     0,     0,
       0,     0,   466,   467,   468,   469,   470,   471,   472,   473,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   474,   475,   476,   477,   464,   465,     0,
       0,   877,     0,     0,   466,   467,   468,   469,   470,   471,
     472,   473,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   474,   475,   476,   477,   464,   465,
       0,     0,   879,     0,     0,   466,   467,   468,   469,   470,
     471,   472,   473,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   474,   475,   476,   477,
     464,   465,     0,     0,   890,     0,     0,   466,   467,   468,
     469,   470,   471,   472,   473,   464,   465,     0,     0,     0,
       0,     0,   466,   467,   468,   469,   470,   471,   472,   473,
     464,   465,     0,     0,     0,     0,     0,   466,   467,   468,
     469,   470,   471,   472,   473,     0,     0,     0,     0,     0,
       0,     0,   474,   475,   476,   477,     0,     0,     0,     0,
     891,     0,     0,     0,     0,     0,     0,   474,   475,   476,
     477,   464,   465,     0,     0,   893,     0,     0,   466,   467,
     468,   469,   470,   471,   472,   473,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   474,
     475,   476,   477,   464,   465,     0,     0,   896,     0,     0,
     466,   467,   468,   469,   470,   471,   472,   473,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     474,   475,   476,   477,   464,   465,     0,     0,   918,     0,
       0,   466,   467,   468,   469,   470,   471,   472,   473,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   474,   475,   476,   477,     0,     0,     0,     0,
     935,     0,     0,     0,     0,     0,     0,   474,   475,   476,
     477,     0,     0,     0,     0,   946,     0,     0,     0,     0,
       0,     0,   474,   475,   476,   477,   464,   465,     0,     0,
     974,     0,     0,   466,   467,   468,   469,   470,   471,   472,
     473,   464,   465,     0,     0,     0,     0,     0,   466,   467,
     468,   469,   470,   471,   472,   473,     0,     0,     0,     0,
       0,     0,     0,   474,   475,   476,   477,   464,   465,     0,
       0,  1094,     0,     0,   466,   467,   468,   469,   470,   471,
     472,   473,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   474,   475,   476,   477,   464,
     465,     0,     0,  1111,     0,     0,   466,   467,   468,   469,
     470,   471,   472,   473,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   474,   475,   476,   477,
     464,   465,     0,     0,  1112,     0,     0,   466,   467,   468,
     469,   470,   471,   472,   473,   464,   465,     0,     0,     0,
       0,     0,   466,   467,   468,   469,   470,   471,   472,   473,
     464,   465,     0,     0,     0,     0,     0,   466,   467,   468,
     469,   470,   471,   472,   473,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   474,   475,
     476,   477,     0,     0,     0,     0,  1123,     0,     0,     0,
       0,     0,     0,   474,   475,   476,   477,   464,   465,     0,
       0,  1124,     0,     0,   466,   467,   468,   469,   470,   471,
     472,   473,     0,     0,     0,     0,     0,     0,     0,   474,
     475,   476,   477,   464,   465,     0,     0,  1129,     0,     0,
     466,   467,   468,   469,   470,   471,   472,   473,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   474,   475,   476,   477,   464,   465,     0,     0,  1130,
       0,     0,   466,   467,   468,   469,   470,   471,   472,   473,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   474,   475,   476,   477,     0,     0,     0,     0,
    1131,     0,     0,     0,     0,     0,     0,   474,   475,   476,
     477,     0,     0,     0,     0,  1132,     0,     0,     0,     0,
       0,     0,   474,   475,   476,   477,   464,   465,     0,     0,
    1133,     0,     0,   466,   467,   468,   469,   470,   471,   472,
     473,   464,   465,     0,     0,     0,     0,     0,   466,   467,
     468,   469,   470,   471,   472,   473,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   474,
     475,   476,   477,   464,   465,     0,     0,  1138,     0,     0,
     466,   467,   468,   469,   470,   471,   472,   473,     0,     0,
       0,     0,     0,     0,     0,   474,   475,   476,   477,   464,
     465,     0,     0,  1139,     0,     0,   466,   467,   468,   469,
     470,   471,   472,   473,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   474,   475,   476,
     477,   464,   465,     0,     0,  1142,     0,     0,   466,   467,
     468,   469,   470,   471,   472,   473,   464,   465,     0,     0,
       0,     0,     0,   466,   467,   468,   469,   470,   471,   472,
     473,   464,   465,     0,     0,     0,     0,     0,   466,   467,
     468,   469,   470,   471,   472,   473,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   474,   475,
     476,   477,     0,     0,     0,     0,  1143,     0,     0,     0,
       0,     0,     0,   474,   475,   476,   477,   464,   465,     0,
       0,  1144,     0,     0,   466,   467,   468,   469,   470,   471,
     472,   473,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   474,   475,   476,   477,   464,
     465,     0,     0,  1145,     0,     0,   466,   467,   468,   469,
     470,   471,   472,   473,     0,     0,     0,     0,     0,     0,
       0,   474,   475,   476,   477,   464,   465,     0,     0,  1146,
       0,     0,   466,   467,   468,   469,   470,   471,   472,   473,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   474,   475,   476,   477,     0,     0,     0,
       0,  1149,     0,     0,     0,     0,     0,     0,   474,   475,
     476,   477,     0,     0,     0,     0,  1150,     0,     0,     0,
       0,     0,     0,   474,   475,   476,   477,   464,   465,     0,
       0,  1153,     0,     0,   466,   467,   468,   469,   470,   471,
     472,   473,   464,   465,     0,     0,     0,     0,     0,   466,
     467,   468,   469,   470,   471,   472,   473,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   474,
     475,   476,   477,   464,   465,     0,     0,  1159,     0,     0,
     466,   467,   468,   469,   470,   471,   472,   473,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   474,   475,   476,   477,   464,   465,     0,     0,  1162,
       0,     0,   466,   467,   468,   469,   470,   471,   472,   473,
       0,     0,     0,     0,     0,     0,     0,   474,   475,   476,
     477,   464,   465,     0,     0,  1173,     0,     0,   466,   467,
     468,   469,   470,   471,   472,   473,   464,   465,     0,     0,
       0,     0,     0,   466,   467,   468,   469,   470,   471,   472,
     473,   464,   465,     0,     0,     0,     0,     0,   466,   467,
     468,   469,   470,   471,   472,   473,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   474,
     475,   476,   477,     0,     0,     0,     0,  1178,     0,     0,
       0,     0,     0,     0,   474,   475,   476,   477,   464,   465,
       0,     0,  1179,     0,     0,   466,   467,   468,   469,   470,
     471,   472,   473,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   474,   475,   476,   477,   464,
     465,     0,     0,  1187,     0,     0,   466,   467,   468,   469,
     470,   471,   472,   473,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   474,   475,   476,
     477,   464,   465,     0,     0,  1241,     0,     0,   466,   467,
     468,   469,   470,   471,   472,   473,     0,     0,     0,     0,
       0,     0,     0,   474,   475,   476,   477,     0,     0,     0,
       0,  1245,     0,     0,     0,     0,     0,     0,   474,   475,
     476,   477,     0,     0,     0,     0,  1254,     0,     0,     0,
       0,     0,     0,   474,   475,   476,   477,   464,   465,     0,
       0,  1257,     0,     0,   466,   467,   468,   469,   470,   471,
     472,   473,   464,   465,     0,     0,     0,     0,     0,   466,
     467,   468,   469,   470,   471,   472,   473,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     474,   475,   476,   477,   464,   465,     0,     0,  1258,     0,
       0,   466,   467,   468,   469,   470,   471,   472,   473,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   474,   475,   476,   477,   464,   465,     0,     0,  1261,
       0,     0,   466,   467,   468,   469,   470,   471,   472,   473,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   474,   475,   476,   477,   464,   465,     0,
       0,  1262,     0,     0,   466,   467,   468,   469,   470,   471,
     472,   473,   464,   465,     0,     0,     0,     0,     0,   466,
     467,   468,   469,   470,   471,   472,   473,   464,   465,     0,
       0,     0,     0,     0,   466,   467,   468,   469,   470,   471,
     472,   473,     0,     0,     0,     0,     0,     0,     0,   474,
     475,   476,   477,     0,     0,     0,     0,  1263,     0,     0,
       0,     0,     0,     0,   474,   475,   476,   477,   464,   465,
       0,     0,  1270,     0,     0,   466,   467,   468,   469,   470,
     471,   472,   473,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   474,   475,   476,   477,
     464,   465,     0,     0,  1272,     0,     0,   466,   467,   468,
     469,   470,   471,   472,   473,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   474,   475,   476,
     477,   464,   465,     0,     0,  1273,     0,     0,   466,   467,
     468,   469,   470,   471,   472,   473,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   474,
     475,   476,   477,     0,     0,     0,     0,  1275,     0,     0,
       0,     0,     0,     0,   474,   475,   476,   477,     0,     0,
       0,     0,  1279,     0,     0,     0,     0,     0,     0,   474,
     475,   476,   477,   464,   465,     0,     0,  1280,     0,     0,
     466,   467,   468,   469,   470,   471,   472,   473,   464,   465,
       0,     0,     0,     0,     0,   466,   467,   468,   469,   470,
     471,   472,   473,     0,     0,     0,     0,     0,     0,     0,
     474,   475,   476,   477,   464,   465,     0,     0,  1316,     0,
       0,   466,   467,   468,   469,   470,   471,   472,   473,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   474,   475,   476,   477,   464,   465,     0,     0,
    1317,     0,     0,   466,   467,   468,   469,   470,   471,   472,
     473,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   474,   475,   476,   477,   464,   465,     0,
       0,  1319,     0,     0,   466,   467,   468,   469,   470,   471,
     472,   473,   464,   465,     0,     0,     0,     0,     0,   466,
     467,   468,   469,   470,   471,   472,   473,   464,   465,     0,
       0,     0,     0,     0,   466,   467,   468,   469,   470,   471,
     472,   473,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   474,   475,   476,   477,     0,
       0,     0,     0,  1334,     0,     0,     0,     0,     0,     0,
     474,   475,   476,   477,   464,   465,     0,     0,  1345,     0,
       0,   466,   467,   468,   469,   470,   471,   472,   473,     0,
       0,     0,     0,     0,     0,     0,   474,   475,   476,   477,
     464,   465,     0,     0,  1346,     0,     0,   466,   467,   468,
     469,   470,   471,   472,   473,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   474,   475,
     476,   477,   464,   465,     0,     0,  1356,     0,     0,   466,
     467,   468,   469,   470,   471,   472,   473,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   474,
     475,   476,   477,     0,     0,   527,     0,     0,     0,     0,
       0,     0,     0,     0,   474,   475,   476,   477,     0,     0,
     528,     0,     0,     0,     0,     0,     0,     0,     0,   474,
     475,   476,   477,   464,   465,   542,     0,     0,     0,     0,
     466,   467,   468,   469,   470,   471,   472,   473,   464,   465,
       0,     0,     0,     0,     0,   466,   467,   468,   469,   470,
     471,   472,   473,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   474,   475,   476,   477,
     464,   465,   785,     0,     0,     0,     0,   466,   467,   468,
     469,   470,   471,   472,   473,     0,     0,     0,     0,     0,
       0,     0,   474,   475,   476,   477,   464,   465,   812,     0,
       0,     0,     0,   466,   467,   468,   469,   470,   471,   472,
     473,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   474,   475,   476,   477,   464,   465,
     813,     0,     0,     0,     0,   466,   467,   468,   469,   470,
     471,   472,   473,   464,   465,     0,     0,     0,     0,     0,
     466,   467,   468,   469,   470,   471,   472,   473,   464,   465,
       0,     0,     0,     0,     0,   466,   467,   468,   469,   470,
     471,   472,   473,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   474,   475,   476,   477,     0,
       0,   818,     0,     0,     0,     0,     0,     0,     0,     0,
     474,   475,   476,   477,   464,   465,   819,     0,     0,     0,
       0,   466,   467,   468,   469,   470,   471,   472,   473,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   474,   475,   476,   477,   464,   465,   822,     0,
       0,     0,     0,   466,   467,   468,   469,   470,   471,   472,
     473,     0,     0,     0,     0,     0,     0,     0,   474,   475,
     476,   477,   464,   465,   826,     0,     0,     0,     0,   466,
     467,   468,   469,   470,   471,   472,   473,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     474,   475,   476,   477,     0,     0,   839,     0,     0,     0,
       0,     0,     0,     0,     0,   474,   475,   476,   477,     0,
       0,   840,     0,     0,     0,     0,     0,     0,     0,     0,
     474,   475,   476,   477,   464,   465,   842,     0,     0,     0,
       0,   466,   467,   468,   469,   470,   471,   472,   473,   464,
     465,     0,     0,     0,     0,     0,   466,   467,   468,   469,
     470,   471,   472,   473,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   474,   475,   476,   477,
     464,   465,   843,     0,     0,     0,     0,   466,   467,   468,
     469,   470,   471,   472,   473,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   474,   475,
     476,   477,   464,   465,   844,     0,     0,     0,     0,   466,
     467,   468,   469,   470,   471,   472,   473,     0,     0,     0,
       0,     0,     0,     0,   474,   475,   476,   477,   464,   465,
     857,     0,     0,     0,     0,   466,   467,   468,   469,   470,
     471,   472,   473,   464,   465,     0,     0,     0,     0,     0,
     466,   467,   468,   469,   470,   471,   472,   473,   464,   465,
       0,     0,     0,     0,     0,   466,   467,   468,   469,   470,
     471,   472,   473,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   474,   475,   476,   477,
       0,     0,   878,     0,     0,     0,     0,     0,     0,     0,
       0,   474,   475,   476,   477,   464,   465,   885,     0,     0,
       0,     0,   466,   467,   468,   469,   470,   471,   472,   473,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   474,   475,   476,   477,   464,   465,   886,     0,
       0,     0,     0,   466,   467,   468,   469,   470,   471,   472,
     473,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   474,   475,   476,   477,   464,   465,
     934,     0,     0,     0,     0,   466,   467,   468,   469,   470,
     471,   472,   473,     0,     0,     0,     0,     0,     0,     0,
     474,   475,   476,   477,     0,     0,   940,     0,     0,     0,
       0,     0,     0,     0,     0,   474,   475,   476,   477,     0,
       0,   970,     0,     0,     0,     0,     0,     0,     0,     0,
     474,   475,   476,   477,   464,   465,   991,     0,     0,     0,
       0,   466,   467,   468,   469,   470,   471,   472,   473,   464,
     465,     0,     0,     0,     0,     0,   466,   467,   468,   469,
     470,   471,   472,   473,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   474,   475,   476,
     477,   464,   465,   992,     0,     0,     0,     0,   466,   467,
     468,   469,   470,   471,   472,   473,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   474,   475,
     476,   477,   464,   465,   999,     0,     0,     0,     0,   466,
     467,   468,   469,   470,   471,   472,   473,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     474,   475,   476,   477,   464,   465,  1002,     0,     0,     0,
       0,   466,   467,   468,   469,   470,   471,   472,   473,   464,
     465,     0,     0,     0,     0,     0,   466,   467,   468,   469,
     470,   471,   472,   473,   464,   465,     0,     0,     0,     0,
       0,   466,   467,   468,   469,   470,   471,   472,   473,     0,
       0,     0,     0,     0,     0,     0,   474,   475,   476,   477,
       0,     0,  1003,     0,     0,     0,     0,     0,     0,     0,
       0,   474,   475,   476,   477,   464,   465,  1008,     0,     0,
       0,     0,   466,   467,   468,   469,   470,   471,   472,   473,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   474,   475,   476,   477,   464,   465,  1009,
       0,     0,     0,     0,   466,   467,   468,   469,   470,   471,
     472,   473,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   474,   475,   476,   477,   464,   465,
    1086,     0,     0,     0,     0,   466,   467,   468,   469,   470,
     471,   472,   473,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   474,   475,   476,   477,
       0,     0,  1091,     0,     0,     0,     0,     0,     0,     0,
       0,   474,   475,   476,   477,     0,     0,  1102,     0,     0,
       0,     0,     0,     0,     0,     0,   474,   475,   476,   477,
     464,   465,  1118,     0,     0,     0,     0,   466,   467,   468,
     469,   470,   471,   472,   473,   464,   465,     0,     0,     0,
       0,     0,   466,   467,   468,   469,   470,   471,   472,   473,
       0,     0,     0,     0,     0,     0,     0,   474,   475,   476,
     477,   464,   465,  1119,     0,     0,     0,     0,   466,   467,
     468,   469,   470,   471,   472,   473,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   474,
     475,   476,   477,   464,   465,  1120,     0,     0,     0,     0,
     466,   467,   468,   469,   470,   471,   472,   473,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     474,   475,   476,   477,   464,   465,  1121,     0,     0,     0,
       0,   466,   467,   468,   469,   470,   471,   472,   473,   464,
     465,     0,     0,     0,     0,     0,   466,   467,   468,   469,
     470,   471,   472,   473,   464,   465,     0,     0,     0,     0,
       0,   466,   467,   468,   469,   470,   471,   472,   473,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   474,   475,   476,   477,     0,     0,  1122,     0,
       0,     0,     0,     0,     0,     0,     0,   474,   475,   476,
     477,   464,   465,  1125,     0,     0,     0,     0,   466,   467,
     468,   469,   470,   471,   472,   473,     0,     0,     0,     0,
       0,     0,     0,   474,   475,   476,   477,   464,   465,  1126,
       0,     0,     0,     0,   466,   467,   468,   469,   470,   471,
     472,   473,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   474,   475,   476,   477,   464,
     465,  1160,     0,     0,     0,     0,   466,   467,   468,   469,
     470,   471,   472,   473,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   474,   475,   476,   477,
       0,     0,  1161,     0,     0,     0,     0,     0,     0,     0,
       0,   474,   475,   476,   477,     0,     0,  1170,     0,     0,
       0,     0,     0,     0,     0,     0,   474,   475,   476,   477,
     464,   465,  1171,     0,     0,     0,     0,   466,   467,   468,
     469,   470,   471,   472,   473,   464,   465,     0,     0,     0,
       0,     0,   466,   467,   468,   469,   470,   471,   472,   473,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   474,   475,   476,   477,   464,   465,  1172,
       0,     0,     0,     0,   466,   467,   468,   469,   470,   471,
     472,   473,     0,     0,     0,     0,     0,     0,     0,   474,
     475,   476,   477,   464,   465,  1174,     0,     0,     0,     0,
     466,   467,   468,   469,   470,   471,   472,   473,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   474,   475,   476,   477,   464,   465,  1175,     0,     0,
       0,     0,   466,   467,   468,   469,   470,   471,   472,   473,
     464,   465,     0,     0,     0,     0,     0,   466,   467,   468,
     469,   470,   471,   472,   473,   464,   465,     0,     0,     0,
       0,     0,   466,   467,   468,   469,   470,   471,   472,   473,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   474,   475,   476,   477,     0,     0,  1201,     0,
       0,     0,     0,     0,     0,     0,     0,   474,   475,   476,
     477,   464,   465,  1259,     0,     0,     0,     0,   466,   467,
     468,   469,   470,   471,   472,   473,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   474,
     475,   476,   477,   464,   465,  1260,     0,     0,     0,     0,
     466,   467,   468,   469,   470,   471,   472,   473,     0,     0,
       0,     0,     0,     0,     0,   474,   475,   476,   477,   464,
     465,  1269,     0,     0,     0,     0,   466,   467,   468,   469,
     470,   471,   472,   473,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   474,   475,   476,
     477,     0,     0,  1281,     0,     0,     0,     0,     0,     0,
       0,     0,   474,   475,   476,   477,     0,     0,  1282,     0,
       0,     0,     0,     0,     0,     0,     0,   474,   475,   476,
     477,     0,     0,  1292,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   474,   475,   476,   477,     0,     0,  1320,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   474,   475,   476,   477,     0,
       0,  1321,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   474,   475,   476,   477,     0,     0,  1333
};

static const yytype_int16 yycheck[] =
{
       2,    15,    16,    44,     1,   366,     1,     4,    12,     4,
      40,   236,   311,   312,    75,    17,   980,   981,   231,    12,
     233,     4,     4,    12,     7,     7,    58,    41,    30,   254,
      11,    33,   315,   316,    36,    37,    38,    16,    28,     3,
      42,    43,    44,     7,     8,     9,    10,     3,    75,    51,
       7,     7,     8,     9,    10,    25,    53,    77,    53,    63,
      64,    63,    12,    92,    93,    44,    70,    71,    72,    73,
      74,    75,    76,    77,    44,   104,     4,     0,   226,     7,
      13,    43,    44,   231,    58,   233,    60,    61,    88,    70,
      71,    72,    73,    74,    75,    76,   231,    95,   233,   226,
     226,    63,    74,    75,    76,    77,   233,   233,   231,   110,
     233,    20,    21,    63,    64,    75,    76,    77,   120,   232,
      70,    71,    72,    73,    74,    75,    76,    77,   226,   226,
      63,    64,   232,   231,   231,   233,   233,    70,    71,    72,
      73,    74,    75,    76,    77,   226,   226,   231,   431,   233,
     433,   231,   233,   233,    63,    64,    47,    48,     4,     5,
     232,    70,    71,    72,    73,    74,    75,    76,    77,    59,
      51,   232,    70,    71,    72,    73,    74,    75,    76,   226,
      23,   232,    63,    64,   231,   226,   233,    76,    77,    70,
      71,    72,    73,    74,    75,    76,    77,   232,    28,    89,
      90,    91,   234,    33,   226,   232,    96,   227,   228,   231,
     226,   233,   214,   215,   231,   231,   233,   233,   226,   226,
     232,   225,   226,   227,   228,   233,   233,   231,   230,  1193,
      35,    36,  1196,   235,    24,     4,     5,   226,   231,   236,
     232,   236,   231,     4,     5,   226,   248,   277,   278,   232,
     232,   253,   551,   225,   226,   227,   228,   254,   260,   254,
     234,   225,   226,     4,     5,   225,   226,   227,   228,   225,
     226,   232,   226,   226,   232,   225,   226,   227,   228,   233,
     233,   283,    77,   285,   232,   510,   132,   133,   134,    63,
     589,   590,   225,   226,   227,   228,    70,    71,    72,    73,
      74,    75,    76,    77,     4,     5,    70,    71,    72,    73,
      74,    75,    76,   612,   226,   317,   225,   226,   227,   228,
     226,   233,   324,   325,   326,   327,   328,   233,   226,   331,
     332,   100,   334,   231,   336,   233,   225,   226,   227,   228,
     342,   226,   344,   345,   225,   226,   227,   228,   233,   351,
    1314,   226,     4,     5,   356,   357,   231,   359,   360,   361,
     362,   363,   364,   132,   133,   134,   368,   369,   370,   371,
     372,   373,   374,   375,   376,   377,   378,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   232,   231,    44,
     233,   232,   394,   395,   396,   397,   398,   226,   400,   232,
     402,   363,   364,   226,   233,   232,   297,    14,   231,    16,
     233,    18,   303,   304,   226,   417,   232,   379,   232,   231,
     422,   233,   232,    70,    71,    72,    73,    74,    75,    76,
     225,   226,   227,   228,    41,   437,   438,    44,   226,   226,
     226,   443,    49,   231,   231,   233,   233,   233,   450,   230,
     231,   225,   226,   227,   228,   417,     5,   348,   349,   350,
      44,    10,   226,    75,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   475,   476,   477,   367,   226,   226,    63,
      64,   232,    31,    75,   233,   233,    70,    71,    72,    73,
      74,    75,    76,    77,   232,   226,   226,    14,   226,    16,
     232,    18,   233,   233,   534,   233,   232,   732,   232,   511,
     232,   354,   355,   510,   516,   510,    71,    46,    73,    74,
      75,    76,    77,   226,    41,   527,   528,    44,   226,   226,
     233,   232,    49,   231,    63,    64,   233,   232,   540,   232,
     542,    70,    71,    72,    73,    74,    75,    76,    77,     3,
     552,   553,   226,     7,     8,     9,   105,   231,   107,   561,
     562,   563,   564,   232,   925,    86,    87,   928,    70,    71,
      72,    73,    74,    75,    76,   232,   419,   420,    14,   226,
      16,   226,    18,   132,   133,   134,   233,   226,   233,   138,
     139,   140,   226,   142,   233,   144,   145,   146,    44,   233,
     232,   226,   151,   152,   153,    41,   231,   156,    44,   158,
     226,   160,   232,    49,   163,   232,   165,   233,   232,   168,
     226,   232,   171,   172,   226,   174,   175,   233,   177,   231,
     179,    70,    71,    72,    73,    74,    75,    76,   187,    63,
      64,   225,   226,   227,   228,   232,    70,    71,    72,    73,
      74,    75,    76,    77,   226,   232,   547,   226,    14,   550,
      16,   233,    18,   226,   233,   232,   215,   216,   231,   226,
     225,   226,   227,   228,   223,   224,   233,    46,     4,     5,
     232,   524,   525,   232,   233,    41,   529,   530,    44,   232,
       4,     5,   232,    49,    63,    64,   225,   226,   227,   228,
     232,    70,    71,    72,    73,    74,    75,    76,    77,   232,
     226,     4,     5,   715,   716,   231,    70,    71,    72,    73,
      74,    75,    76,  1022,   226,   226,   740,   741,   232,   226,
       4,   233,   233,   735,   232,   732,   233,   732,   232,  1038,
     226,   966,   226,   226,    63,    64,   748,   233,    44,   233,
     233,    70,    71,    72,    73,    74,    75,    76,    77,   761,
     226,   226,   232,    63,    64,   767,   768,   233,   233,   771,
      70,    71,    72,    73,    74,    75,    76,    77,   226,   226,
     232,   226,   226,   785,   226,   233,   233,   226,   233,   233,
      58,   233,   226,   226,   233,    49,    50,   231,   800,   801,
     802,   225,   226,   227,   228,   226,   226,   231,   231,   233,
     232,   813,   233,   233,   232,   817,   818,   819,   226,   821,
     822,   823,   226,   825,   826,   233,   226,   231,   231,   831,
     232,   231,   231,   830,   226,   830,   232,   839,   840,   231,
     842,   843,   844,   226,   226,   226,   226,   232,   231,   231,
     231,   231,   854,   855,   232,   857,   225,   226,   227,   228,
     226,   863,   226,   226,   866,   231,   226,   231,   231,   226,
     232,   231,   226,   226,   231,   233,   878,   231,   231,   881,
     882,   883,   232,   885,   886,    71,    72,    73,    74,    75,
      76,    77,   894,   226,     4,     5,   226,   232,   231,   742,
     743,   231,   745,   746,   232,   796,   225,   226,   227,   228,
     226,   226,   231,   231,   233,   231,   231,     5,   920,   226,
     922,   923,   924,   232,   231,   225,   226,   227,   228,     4,
       5,   231,   934,   233,   936,   937,   938,   939,   940,   226,
     232,   832,   833,   945,   231,   947,   232,   226,   950,   232,
      63,    64,   231,    39,    40,   232,   799,    70,    71,    72,
      73,    74,    75,    76,    77,   856,    63,    64,   970,   966,
     232,   966,   232,    70,    71,    72,    73,    74,    75,    76,
      77,   181,   182,   183,   184,   185,    60,    61,   232,   991,
     992,   232,   232,   232,   996,   997,   232,     3,   232,   232,
    1002,  1003,   232,    73,    74,    75,    76,    77,   232,   232,
    1235,  1236,    63,    64,   232,    21,   232,   232,    24,    70,
      71,    72,    73,    74,    75,    76,    77,    33,   232,   232,
     232,    37,    38,   232,   996,   997,    42,   232,   232,   225,
     226,   227,   228,   232,   232,   232,    43,   232,    54,    55,
      56,   232,   232,   232,   232,   232,   232,    63,    64,    65,
      66,  1075,  1076,  1288,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,  1301,   232,   232,  1081,
     232,  1306,   232,   232,  1086,   232,   232,   232,   232,  1091,
     232,   232,   232,   232,   232,   232,   232,   232,  1323,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     231,  1113,   225,   226,   227,   228,  1118,  1119,  1120,  1121,
    1122,   233,   231,  1125,  1126,   231,   233,    77,   225,   226,
     227,   228,   233,   233,   231,   233,   233,   233,   233,  1141,
     233,    75,   232,   232,   231,  1147,   989,   990,   232,   232,
     231,   231,  1154,    43,  1156,   225,   226,   227,   228,  1161,
      46,   232,    10,   232,   232,   231,   231,   231,   231,  1171,
    1172,   233,  1174,  1175,   225,   226,   227,   228,  1180,   233,
     231,   233,   233,   231,   233,    63,    64,   232,  1190,   232,
     231,   233,    70,    71,    72,    73,    74,    75,    76,    77,
     233,   231,   233,    43,  1206,   233,   233,   233,   233,   215,
     233,    63,    64,   232,   232,    85,   233,   223,    70,    71,
      72,    73,    74,    75,    76,    77,   232,    85,   233,   233,
     233,     5,   231,   231,    58,  1237,  1127,   233,  1235,  1236,
    1235,  1236,   248,   233,   233,   233,   232,   253,   232,   231,
     233,   232,  1095,  1096,   260,   233,   233,  1259,  1260,    43,
      38,    43,   232,    75,   233,   233,    75,  1269,    75,    48,
      58,   233,   233,   232,   232,    47,   232,   232,   284,  1281,
    1282,  1283,    75,    38,   233,   233,     4,     4,   294,  1291,
    1292,  1288,   830,  1288,    53,    53,   534,   748,     5,   366,
    1266,   744,  1081,   531,  1301,  1354,  1301,   747,   978,  1306,
    1294,  1306,   318,   544,    -1,    -1,    -1,    -1,  1320,  1321,
      -1,    -1,    -1,   329,   330,    -1,  1323,    -1,  1323,   335,
      -1,  1333,   338,    -1,   340,    -1,    -1,   343,    70,    71,
      72,    73,    74,    75,    76,    77,   352,   225,   226,   227,
     228,    -1,    -1,    -1,    -1,   233,    -1,   363,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   225,   226,   227,   228,    -1,    -1,    -1,
      -1,   233,    -1,   389,   390,   391,   392,   393,    -1,    -1,
     396,    -1,    -1,   399,    -1,   401,    -1,   403,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   417,   418,    -1,    -1,   421,    -1,   423,   424,   425,
     426,   427,    -1,    -1,   430,    -1,   432,    -1,   434,   435,
     436,    -1,    -1,   439,   440,   441,   442,    -1,   444,   445,
     446,   447,    -1,   449,    -1,   451,    -1,    -1,    -1,   455,
     456,   457,   458,   459,   460,   461,   462,    -1,    -1,     3,
       4,     5,    -1,     7,     8,     9,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    -1,
      -1,    -1,    -1,   225,   226,   227,   228,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   513,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      64,    65,    66,    67,    68,    69,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   539,    -1,    -1,    -1,    81,    -1,    -1,
      84,    -1,   548,    -1,    -1,    89,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    97,    -1,   561,   562,   101,   102,    -1,
      -1,   105,    -1,   107,    -1,    -1,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,    -1,   162,   163,
     164,   165,    -1,   167,   168,    -1,   170,   171,   172,    -1,
     174,   175,   176,   177,   178,   179,   180,    -1,    -1,    -1,
      -1,     5,   186,   187,   188,    -1,    10,    -1,   192,    -1,
      -1,   195,    -1,    -1,   198,   199,   200,   201,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,   213,
     214,   215,   216,    -1,    -1,   219,    -1,   221,    -1,   223,
     224,   225,    -1,    -1,    63,    64,    -1,    -1,   232,    -1,
     234,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   105,   748,   107,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   764,    -1,
      -1,   767,    -1,    -1,    -1,    -1,    -1,    -1,   132,   133,
     134,    -1,    -1,    -1,   138,   139,   140,    -1,   142,    -1,
     144,   145,   146,    -1,    -1,    -1,    -1,   151,   152,   153,
      -1,    -1,   156,    -1,   158,    -1,   160,    -1,    -1,   163,
      -1,   165,    -1,    -1,   168,    -1,   812,   171,   172,    -1,
     174,   175,    -1,   177,    -1,   179,    -1,     5,    -1,    -1,
      -1,    -1,    10,   187,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     846,    -1,   848,    31,    -1,    -1,   225,   226,   227,   228,
      -1,   215,   216,    -1,   233,    -1,    -1,    -1,    -1,   223,
     224,    -1,   225,   226,   227,   228,    -1,    -1,   232,   233,
     233,    -1,    -1,    -1,    -1,    -1,    -1,   225,   226,   227,
     228,    -1,   888,    -1,    -1,   233,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     906,   907,    -1,    -1,    -1,    -1,    -1,   913,    -1,    -1,
      -1,    -1,    -1,     5,    -1,    -1,    -1,   105,    10,   107,
     926,    -1,    -1,   929,    -1,   931,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   941,   942,    -1,    -1,    31,
      -1,    -1,    -1,    -1,   132,   133,   134,    -1,    -1,    -1,
     138,   139,   140,    -1,   142,    -1,   144,   145,   146,    -1,
      -1,    -1,    -1,   151,   152,   153,   972,    -1,   156,   975,
     158,    -1,   160,    -1,    -1,   163,    -1,   165,    -1,    -1,
     168,    -1,    -1,   171,   172,    -1,   174,   175,    -1,   177,
      -1,   179,   998,   999,  1000,    -1,    -1,    -1,    -1,   187,
      -1,    -1,  1008,  1009,    -1,    -1,    -1,    -1,    -1,    63,
      64,    -1,    -1,   105,    -1,   107,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,   215,   216,    -1,
      -1,    -1,    -1,    -1,    -1,   223,   224,    -1,    -1,    -1,
     132,   133,   134,    -1,   232,   233,   138,   139,   140,    -1,
     142,    -1,   144,   145,   146,    -1,    -1,    -1,    -1,   151,
     152,   153,    -1,    -1,   156,    -1,   158,    -1,   160,    -1,
      -1,   163,    -1,   165,    -1,  1081,   168,    -1,    -1,   171,
     172,    -1,   174,   175,    -1,   177,    -1,   179,    -1,    -1,
      63,    64,    -1,    -1,    -1,   187,  1102,    70,    71,    72,
      73,    74,    75,    76,    77,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,   215,   216,    -1,    -1,    -1,    -1,    -1,
    1136,   223,   224,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     232,   233,    -1,    -1,    -1,  1151,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1160,    -1,    -1,  1163,    -1,    -1,
    1166,    -1,    -1,    -1,  1170,    -1,    -1,    -1,    -1,    -1,
      -1,   225,   226,   227,   228,    -1,    -1,    -1,    -1,   233,
      -1,    -1,    -1,    -1,    -1,  1191,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1200,  1201,  1202,  1203,    -1,  1205,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,    -1,     7,     8,     9,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   225,   226,   227,   228,    -1,    30,    31,    -1,
     233,    -1,    -1,    -1,    -1,    -1,    -1,   225,   226,   227,
     228,    -1,    -1,    -1,    -1,   233,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1290,    -1,    -1,    -1,    -1,  1295,
      63,    64,    65,    66,    67,    68,    69,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,
      -1,    84,    -1,    -1,    -1,    -1,    89,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    97,  1331,    -1,    -1,   101,   102,
      -1,    -1,   105,    -1,   107,    -1,    -1,    -1,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,    -1,   162,
     163,   164,   165,    -1,   167,   168,    -1,   170,   171,   172,
      -1,   174,   175,   176,   177,   178,   179,   180,    -1,    -1,
      -1,    -1,    -1,   186,   187,   188,    -1,    -1,    -1,   192,
      -1,    -1,   195,    -1,    -1,   198,   199,   200,   201,     3,
       4,     5,    -1,     7,     8,     9,    10,    -1,    -1,    -1,
     213,   214,   215,   216,    -1,    -1,   219,    -1,   221,    -1,
     223,   224,   225,    -1,    -1,    -1,    30,    31,    -1,   232,
      -1,   234,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      64,    65,    66,    67,    68,    69,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    64,    -1,    81,    -1,    -1,
      84,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    97,    -1,    -1,    -1,   101,   102,    -1,
      -1,   105,    -1,   107,    -1,    -1,    -1,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,    -1,   162,   163,
     164,   165,    -1,   167,   168,    -1,   170,   171,   172,    -1,
     174,   175,   176,   177,   178,   179,   180,    -1,    -1,    -1,
      -1,    -1,   186,   187,   188,    -1,    -1,    -1,   192,    -1,
      -1,   195,    -1,    -1,   198,   199,   200,   201,     3,     4,
       5,    -1,     7,     8,     9,    10,    -1,    -1,    -1,   213,
     214,   215,   216,    -1,    -1,   219,    -1,   221,    -1,   223,
     224,   225,    -1,    -1,    -1,    30,    31,    -1,   232,    -1,
     234,    -1,    -1,    -1,    -1,    -1,   225,   226,   227,   228,
      -1,    -1,    -1,    -1,   233,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,
      65,    66,    67,    68,    69,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    63,    64,    -1,    81,    -1,    -1,    84,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   101,   102,    -1,    -1,
     105,    -1,   107,    -1,    -1,    -1,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,    -1,   162,   163,   164,
     165,    -1,   167,   168,    -1,   170,   171,   172,    -1,   174,
     175,   176,   177,   178,   179,   180,    -1,    -1,    -1,    -1,
      -1,   186,   187,   188,    -1,    -1,    -1,   192,    -1,    -1,
     195,    -1,    -1,   198,   199,   200,   201,     3,     4,     5,
      -1,     7,     8,     9,    10,    -1,    -1,    -1,   213,   214,
     215,   216,    -1,    -1,   219,    -1,   221,    -1,   223,   224,
     225,    -1,    -1,    -1,    30,    31,    -1,   232,    -1,   234,
      -1,    -1,    -1,    -1,    -1,   225,   226,   227,   228,    -1,
      -1,    -1,    -1,   233,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    65,
      66,    67,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    63,    64,    -1,    81,    -1,    -1,    84,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   101,   102,    -1,    -1,   105,
      -1,   107,    -1,    -1,    -1,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,    -1,   162,   163,   164,   165,
      -1,   167,   168,    -1,   170,   171,   172,    -1,   174,   175,
     176,   177,   178,   179,   180,    -1,    -1,    -1,    -1,    -1,
     186,   187,   188,    -1,    -1,    -1,   192,    -1,    -1,   195,
      -1,    -1,   198,   199,   200,   201,     3,     4,     5,    -1,
       7,     8,     9,    10,    -1,    -1,    -1,   213,   214,   215,
     216,    -1,    -1,   219,    -1,   221,    -1,   223,   224,   225,
      -1,    -1,    -1,    30,    31,    -1,   232,   233,    -1,    -1,
      -1,    -1,    -1,    -1,   225,   226,   227,   228,    -1,    -1,
      -1,    -1,   233,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    65,    66,
      67,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    64,    -1,    81,    -1,    -1,    84,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   101,   102,    -1,    -1,   105,    -1,
     107,    -1,    -1,    -1,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,    -1,   162,   163,   164,   165,    -1,
     167,   168,    -1,   170,   171,   172,    -1,   174,   175,   176,
     177,   178,   179,   180,    -1,    -1,    -1,    -1,    -1,   186,
     187,   188,    -1,    -1,    -1,   192,    -1,    -1,   195,    -1,
      -1,   198,   199,   200,   201,     3,     4,     5,    -1,     7,
       8,     9,    10,    -1,    -1,    -1,   213,   214,   215,   216,
      -1,    -1,   219,    -1,   221,    -1,   223,   224,   225,    -1,
      -1,    -1,    30,    31,    -1,   232,   233,    -1,    -1,    -1,
      -1,    -1,    -1,   225,   226,   227,   228,    -1,    -1,    -1,
      -1,   233,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    63,    64,    65,    66,    67,
      68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      63,    64,    -1,    81,    -1,    -1,    84,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   101,   102,    -1,    -1,   105,    -1,   107,
      -1,    -1,    -1,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,    -1,   162,   163,   164,   165,    -1,   167,
     168,    -1,   170,   171,   172,    -1,   174,   175,   176,   177,
     178,   179,   180,    -1,    -1,    -1,    -1,    -1,   186,   187,
     188,    -1,    -1,    -1,   192,    -1,    -1,   195,    -1,    -1,
     198,   199,   200,   201,     3,     4,     5,    -1,     7,     8,
       9,    10,    -1,    12,    -1,   213,   214,   215,   216,    -1,
      -1,   219,    -1,   221,    -1,   223,   224,   225,    -1,    -1,
      -1,    30,    31,    -1,   232,   233,    -1,    -1,    -1,    -1,
      -1,    -1,   225,   226,   227,   228,    -1,    -1,    -1,    -1,
     233,    -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    64,    65,    66,    67,    68,
      69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      64,    -1,    81,    -1,    -1,    84,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   101,   102,    -1,    -1,   105,    -1,   107,    -1,
      -1,    -1,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,    -1,   162,   163,   164,   165,    -1,   167,   168,
      -1,   170,   171,   172,    -1,   174,   175,   176,   177,   178,
     179,   180,    -1,    -1,    -1,    -1,    -1,   186,   187,   188,
      -1,    -1,    -1,   192,    -1,    -1,   195,    -1,    -1,   198,
     199,   200,   201,     3,     4,     5,    -1,     7,     8,     9,
      10,    -1,    -1,    -1,   213,   214,   215,   216,    -1,    -1,
     219,    -1,   221,    -1,   223,   224,   225,    -1,    -1,    -1,
      30,    31,    -1,   232,    34,    -1,    -1,    -1,    -1,    -1,
      -1,   225,   226,   227,   228,    -1,    -1,    -1,    -1,   233,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    63,    64,    65,    66,    67,    68,    69,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,
      -1,    81,    -1,    -1,    84,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   101,   102,    -1,    -1,   105,    -1,   107,    -1,    -1,
      -1,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,    -1,   162,   163,   164,   165,    -1,   167,   168,    -1,
     170,   171,   172,    -1,   174,   175,   176,   177,   178,   179,
     180,    -1,    -1,    -1,    -1,    -1,   186,   187,   188,    -1,
      -1,    -1,   192,    -1,    -1,   195,    -1,    -1,   198,   199,
     200,   201,     3,     4,     5,    -1,     7,     8,     9,    10,
      -1,    12,    -1,   213,   214,   215,   216,    -1,    -1,   219,
      -1,   221,    -1,   223,   224,   225,    -1,    -1,    -1,    30,
      31,    -1,   232,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     225,   226,   227,   228,    -1,    -1,    -1,    -1,   233,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    63,    64,    65,    66,    67,    68,    69,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    -1,
      81,    -1,    -1,    84,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     101,   102,    -1,    -1,   105,    -1,   107,    -1,    -1,    -1,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
      -1,   162,   163,   164,   165,    -1,   167,   168,    -1,   170,
     171,   172,    -1,   174,   175,   176,   177,   178,   179,   180,
      -1,    -1,    -1,    -1,    -1,   186,   187,   188,    -1,    -1,
      -1,   192,    -1,    -1,   195,    -1,    -1,   198,   199,   200,
     201,     3,     4,     5,    -1,     7,     8,     9,    10,    -1,
      -1,    -1,   213,   214,   215,   216,    -1,    -1,   219,    -1,
     221,    -1,   223,   224,   225,    -1,    -1,    -1,    30,    31,
      -1,   232,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,
     226,   227,   228,    -1,    -1,    -1,    -1,   233,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    64,    65,    66,    67,    68,    69,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    -1,    81,
      -1,    -1,    84,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   101,
     102,    -1,    -1,   105,    -1,   107,    -1,    -1,    -1,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,    -1,
     162,   163,   164,   165,    -1,   167,   168,    -1,   170,   171,
     172,    -1,   174,   175,   176,   177,   178,   179,   180,    -1,
      -1,    -1,     5,    -1,   186,   187,   188,    10,    -1,    -1,
     192,    -1,    -1,   195,    -1,    -1,   198,   199,   200,   201,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,
      -1,   213,   214,   215,   216,    -1,    -1,   219,    -1,   221,
      -1,   223,   224,   225,    -1,    -1,    -1,    -1,    -1,    -1,
     232,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,   226,
     227,   228,    -1,    -1,    -1,    -1,   233,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    97,    -1,    -1,    -1,     5,    -1,
      -1,    -1,   105,    10,   107,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,   132,
     133,   134,    -1,    -1,    -1,   138,   139,   140,    -1,   142,
      -1,   144,   145,   146,    -1,    -1,    -1,    -1,   151,   152,
     153,    -1,    -1,   156,    -1,   158,    -1,   160,    -1,    -1,
     163,    -1,   165,    -1,    -1,   168,    -1,    -1,   171,   172,
      -1,   174,   175,    -1,   177,    -1,   179,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   187,    -1,    -1,    -1,    -1,    -1,
      97,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   105,    -1,
     107,    -1,     5,    -1,    -1,    -1,    -1,    10,    -1,    -1,
      -1,    -1,   215,   216,    -1,    -1,    -1,    -1,    -1,    -1,
     223,   224,    -1,    -1,    -1,   132,   133,   134,    31,   232,
      -1,   138,   139,   140,    -1,   142,    -1,   144,   145,   146,
     225,   226,   227,   228,   151,   152,   153,    -1,   233,   156,
      -1,   158,    -1,   160,    -1,    -1,   163,    -1,   165,    -1,
      -1,   168,    -1,    -1,   171,   172,    -1,   174,   175,    -1,
     177,    -1,   179,    -1,    -1,    -1,    -1,    -1,    63,    64,
     187,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,     5,    -1,
      -1,    -1,   105,    10,   107,    -1,    -1,    -1,   215,   216,
      -1,    -1,    -1,    -1,    -1,    -1,   223,   224,    -1,    -1,
      -1,    -1,    -1,    -1,    31,   232,    -1,    -1,    -1,   132,
     133,   134,    -1,    -1,    -1,   138,   139,   140,    -1,   142,
      -1,   144,   145,   146,    -1,    -1,    -1,    -1,   151,   152,
     153,    -1,    -1,   156,    -1,   158,    -1,   160,    -1,    -1,
     163,    -1,   165,    -1,    -1,   168,    -1,    -1,   171,   172,
      -1,   174,   175,    -1,   177,    -1,   179,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   187,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   105,    -1,
     107,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   215,   216,    -1,    -1,    -1,    -1,    -1,    -1,
     223,   224,    -1,    -1,    -1,   132,   133,   134,    -1,   232,
      -1,   138,   139,   140,    -1,   142,    -1,   144,   145,   146,
     225,   226,   227,   228,   151,   152,   153,    -1,   233,   156,
      -1,   158,    -1,   160,    -1,    -1,   163,    -1,   165,    -1,
      -1,   168,    -1,    -1,   171,   172,    -1,   174,   175,    -1,
     177,    -1,   179,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     187,    -1,    -1,    -1,    -1,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   215,   216,
      -1,     4,     5,     6,    -1,    -1,   223,   224,    11,    -1,
      -1,    -1,    15,    -1,    17,   232,    19,    20,    21,    22,
      23,    24,    -1,    26,    27,    28,    29,    30,    31,    32,
      33,    -1,    35,    36,    37,    -1,    -1,    -1,    -1,    42,
      -1,    -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,    52,
      53,    54,    55,    56,    57,    -1,    -1,    -1,    61,    62,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,
      83,    -1,    -1,    -1,    -1,    -1,    89,    90,    91,    92,
      93,    94,    95,    96,    -1,    98,    99,   100,    -1,    -1,
     103,   104,    -1,   106,    -1,   108,   109,    -1,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,   132,
     133,   134,    -1,    -1,    -1,    -1,   139,   225,   226,   227,
     228,    -1,    -1,    -1,    -1,   233,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   157,    -1,    -1,    -1,   161,    -1,
      -1,    -1,    -1,   166,    63,    64,   169,    -1,    -1,    -1,
     173,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   189,   190,   191,    -1,
     193,   194,    -1,   196,   197,    -1,    -1,    -1,    -1,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
      -1,     4,     5,     6,   217,   218,    -1,   220,    11,   222,
      -1,    -1,    15,    -1,    17,    -1,    19,    20,    21,    22,
      23,    24,    -1,    26,    27,    28,    29,    30,    31,    32,
      33,    -1,    35,    36,    37,    -1,    -1,    -1,    -1,    42,
      43,    44,    45,    -1,    -1,    -1,    -1,    -1,    -1,    52,
      53,    54,    55,    56,    57,    -1,    -1,    -1,    61,    62,
     225,   226,   227,   228,    -1,    -1,    -1,    -1,   233,    -1,
      -1,    -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,
      83,    -1,    -1,    -1,    -1,    -1,    89,    90,    91,    -1,
      -1,    94,    95,    96,    -1,    98,    99,   100,    -1,    -1,
     103,    -1,    -1,   106,    -1,   108,   109,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   225,   226,   227,   228,
      -1,    -1,    -1,    -1,   233,    -1,    -1,    -1,    -1,   132,
     133,   134,    -1,    -1,    -1,    -1,   139,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   157,    -1,    -1,    -1,   161,    -1,
      -1,    -1,    -1,   166,    63,    64,   169,    -1,    -1,    -1,
     173,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   189,   190,   191,    -1,
     193,   194,    -1,   196,   197,    -1,    -1,    -1,    -1,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
      -1,     4,     5,     6,   217,   218,    -1,   220,    11,   222,
      -1,    -1,    15,    -1,    17,    -1,    19,    20,    21,    22,
      23,    24,    -1,    26,    27,    28,    29,    30,    31,    32,
      33,    -1,    35,    36,    37,    38,    -1,    -1,    -1,    42,
      43,    -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,    52,
      53,    54,    55,    56,    57,    -1,    -1,    -1,    61,    62,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,
      83,    -1,    -1,    -1,    -1,    -1,    89,    90,    91,    -1,
      -1,    94,    95,    96,    -1,    98,    99,   100,    -1,    -1,
     103,    63,    64,   106,    -1,   108,   109,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,   225,   226,   227,   228,
      -1,    -1,    -1,    -1,   233,    -1,    -1,    -1,    -1,   132,
     133,   134,    63,    64,    -1,    -1,   139,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   157,    -1,    -1,    -1,   161,    -1,
      -1,    -1,    -1,   166,    63,    64,   169,    -1,    -1,    -1,
     173,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   189,   190,   191,    -1,
     193,   194,    -1,   196,   197,    -1,    -1,    -1,    -1,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
      -1,    -1,    -1,    -1,   217,   218,    -1,   220,    -1,   222,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   225,   226,   227,   228,    63,    64,    -1,
      -1,   233,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   225,   226,   227,   228,    63,    64,
      -1,    -1,   233,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   225,   226,   227,   228,
      63,    64,    -1,    -1,   233,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   225,   226,   227,   228,    -1,    -1,    -1,    -1,
     233,    -1,    -1,    -1,    -1,    -1,    -1,   225,   226,   227,
     228,    63,    64,    -1,    -1,   233,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,
     226,   227,   228,    63,    64,    -1,    -1,   233,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     225,   226,   227,   228,    63,    64,    -1,    -1,   233,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   225,   226,   227,   228,    -1,    -1,    -1,    -1,
     233,    -1,    -1,    -1,    -1,    -1,    -1,   225,   226,   227,
     228,    -1,    -1,    -1,    -1,   233,    -1,    -1,    -1,    -1,
      -1,    -1,   225,   226,   227,   228,    63,    64,    -1,    -1,
     233,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   225,   226,   227,   228,    63,    64,    -1,
      -1,   233,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   225,   226,   227,   228,    63,
      64,    -1,    -1,   233,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   225,   226,   227,   228,
      63,    64,    -1,    -1,   233,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,   226,
     227,   228,    -1,    -1,    -1,    -1,   233,    -1,    -1,    -1,
      -1,    -1,    -1,   225,   226,   227,   228,    63,    64,    -1,
      -1,   233,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,
     226,   227,   228,    63,    64,    -1,    -1,   233,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   225,   226,   227,   228,    63,    64,    -1,    -1,   233,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   225,   226,   227,   228,    -1,    -1,    -1,    -1,
     233,    -1,    -1,    -1,    -1,    -1,    -1,   225,   226,   227,
     228,    -1,    -1,    -1,    -1,   233,    -1,    -1,    -1,    -1,
      -1,    -1,   225,   226,   227,   228,    63,    64,    -1,    -1,
     233,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,
     226,   227,   228,    63,    64,    -1,    -1,   233,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   225,   226,   227,   228,    63,
      64,    -1,    -1,   233,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,   226,   227,
     228,    63,    64,    -1,    -1,   233,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,   226,
     227,   228,    -1,    -1,    -1,    -1,   233,    -1,    -1,    -1,
      -1,    -1,    -1,   225,   226,   227,   228,    63,    64,    -1,
      -1,   233,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   225,   226,   227,   228,    63,
      64,    -1,    -1,   233,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   225,   226,   227,   228,    63,    64,    -1,    -1,   233,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   225,   226,   227,   228,    -1,    -1,    -1,
      -1,   233,    -1,    -1,    -1,    -1,    -1,    -1,   225,   226,
     227,   228,    -1,    -1,    -1,    -1,   233,    -1,    -1,    -1,
      -1,    -1,    -1,   225,   226,   227,   228,    63,    64,    -1,
      -1,   233,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,
     226,   227,   228,    63,    64,    -1,    -1,   233,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   225,   226,   227,   228,    63,    64,    -1,    -1,   233,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,   226,   227,
     228,    63,    64,    -1,    -1,   233,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,
     226,   227,   228,    -1,    -1,    -1,    -1,   233,    -1,    -1,
      -1,    -1,    -1,    -1,   225,   226,   227,   228,    63,    64,
      -1,    -1,   233,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   225,   226,   227,   228,    63,
      64,    -1,    -1,   233,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,   226,   227,
     228,    63,    64,    -1,    -1,   233,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   225,   226,   227,   228,    -1,    -1,    -1,
      -1,   233,    -1,    -1,    -1,    -1,    -1,    -1,   225,   226,
     227,   228,    -1,    -1,    -1,    -1,   233,    -1,    -1,    -1,
      -1,    -1,    -1,   225,   226,   227,   228,    63,    64,    -1,
      -1,   233,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     225,   226,   227,   228,    63,    64,    -1,    -1,   233,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   225,   226,   227,   228,    63,    64,    -1,    -1,   233,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   225,   226,   227,   228,    63,    64,    -1,
      -1,   233,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,
     226,   227,   228,    -1,    -1,    -1,    -1,   233,    -1,    -1,
      -1,    -1,    -1,    -1,   225,   226,   227,   228,    63,    64,
      -1,    -1,   233,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   225,   226,   227,   228,
      63,    64,    -1,    -1,   233,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,   226,   227,
     228,    63,    64,    -1,    -1,   233,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,
     226,   227,   228,    -1,    -1,    -1,    -1,   233,    -1,    -1,
      -1,    -1,    -1,    -1,   225,   226,   227,   228,    -1,    -1,
      -1,    -1,   233,    -1,    -1,    -1,    -1,    -1,    -1,   225,
     226,   227,   228,    63,    64,    -1,    -1,   233,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     225,   226,   227,   228,    63,    64,    -1,    -1,   233,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   225,   226,   227,   228,    63,    64,    -1,    -1,
     233,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   225,   226,   227,   228,    63,    64,    -1,
      -1,   233,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   225,   226,   227,   228,    -1,
      -1,    -1,    -1,   233,    -1,    -1,    -1,    -1,    -1,    -1,
     225,   226,   227,   228,    63,    64,    -1,    -1,   233,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   225,   226,   227,   228,
      63,    64,    -1,    -1,   233,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,   226,
     227,   228,    63,    64,    -1,    -1,   233,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,
     226,   227,   228,    -1,    -1,   231,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   225,   226,   227,   228,    -1,    -1,
     231,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,
     226,   227,   228,    63,    64,   231,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   225,   226,   227,   228,
      63,    64,   231,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   225,   226,   227,   228,    63,    64,   231,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   225,   226,   227,   228,    63,    64,
     231,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   225,   226,   227,   228,    -1,
      -1,   231,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     225,   226,   227,   228,    63,    64,   231,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   225,   226,   227,   228,    63,    64,   231,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,   226,
     227,   228,    63,    64,   231,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     225,   226,   227,   228,    -1,    -1,   231,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   225,   226,   227,   228,    -1,
      -1,   231,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     225,   226,   227,   228,    63,    64,   231,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   225,   226,   227,   228,
      63,    64,   231,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,   226,
     227,   228,    63,    64,   231,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   225,   226,   227,   228,    63,    64,
     231,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   225,   226,   227,   228,
      -1,    -1,   231,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   225,   226,   227,   228,    63,    64,   231,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   225,   226,   227,   228,    63,    64,   231,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   225,   226,   227,   228,    63,    64,
     231,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     225,   226,   227,   228,    -1,    -1,   231,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   225,   226,   227,   228,    -1,
      -1,   231,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     225,   226,   227,   228,    63,    64,   231,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,   226,   227,
     228,    63,    64,   231,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,   226,
     227,   228,    63,    64,   231,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     225,   226,   227,   228,    63,    64,   231,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   225,   226,   227,   228,
      -1,    -1,   231,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   225,   226,   227,   228,    63,    64,   231,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   225,   226,   227,   228,    63,    64,   231,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   225,   226,   227,   228,    63,    64,
     231,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   225,   226,   227,   228,
      -1,    -1,   231,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   225,   226,   227,   228,    -1,    -1,   231,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   225,   226,   227,   228,
      63,    64,   231,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,   226,   227,
     228,    63,    64,   231,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,
     226,   227,   228,    63,    64,   231,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     225,   226,   227,   228,    63,    64,   231,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   225,   226,   227,   228,    -1,    -1,   231,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,   226,   227,
     228,    63,    64,   231,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   225,   226,   227,   228,    63,    64,   231,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   225,   226,   227,   228,    63,
      64,   231,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   225,   226,   227,   228,
      -1,    -1,   231,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   225,   226,   227,   228,    -1,    -1,   231,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   225,   226,   227,   228,
      63,    64,   231,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   225,   226,   227,   228,    63,    64,   231,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,
     226,   227,   228,    63,    64,   231,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   225,   226,   227,   228,    63,    64,   231,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   225,   226,   227,   228,    -1,    -1,   231,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,   226,   227,
     228,    63,    64,   231,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,
     226,   227,   228,    63,    64,   231,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   225,   226,   227,   228,    63,
      64,   231,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,   226,   227,
     228,    -1,    -1,   231,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   225,   226,   227,   228,    -1,    -1,   231,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,   226,   227,
     228,    -1,    -1,   231,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   225,   226,   227,   228,    -1,    -1,   231,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   225,   226,   227,   228,    -1,
      -1,   231,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   225,   226,   227,   228,    -1,    -1,   231
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   181,   182,   183,   184,   185,   236,     4,     5,     6,
      11,    15,    17,    19,    20,    21,    22,    23,    26,    27,
      28,    29,    30,    31,    32,    33,    35,    36,    37,    42,
      45,    52,    53,    54,    55,    56,    57,    61,    62,    78,
      79,    80,    81,    82,    83,    89,    90,    91,    94,    95,
      96,    98,    99,   100,   103,   106,   108,   109,   132,   133,
     134,   139,   157,   161,   166,   169,   173,   189,   190,   191,
     193,   194,   196,   197,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   217,   218,   220,   222,   237,
     238,   241,   242,   249,   250,   252,   253,   257,   269,   270,
     275,   281,   288,   296,   304,   307,   311,   314,   320,     3,
       4,     5,     7,     8,     9,    10,    30,    31,    63,    64,
      65,    66,    67,    68,    69,    81,    84,   101,   102,   105,
     107,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   162,   163,   164,   165,   167,   168,   170,   171,   172,
     174,   175,   176,   177,   178,   179,   180,   186,   187,   188,
     192,   195,   198,   199,   200,   201,   213,   214,   215,   216,
     219,   221,   223,   224,   225,   232,   255,   256,   258,   264,
     266,   269,   270,   232,   255,   241,   269,   270,   275,     0,
      75,   232,    75,   232,   289,   308,   312,     4,     7,   267,
     267,   267,    34,   258,   243,   244,   255,   271,   272,   271,
     255,    28,     7,   297,   305,   258,    58,    60,    61,   234,
     343,   247,   255,   258,     4,     5,   268,   258,   255,   258,
     255,   258,     4,     5,   331,   332,    10,   225,   226,   265,
     266,   333,   267,    89,    97,   234,   255,   258,   344,    89,
      97,   110,   344,   344,    88,   258,   263,    12,    53,   263,
     263,    59,    89,    90,    91,    96,    95,   258,   250,   257,
     255,   255,   255,   110,   232,   232,   232,   232,   232,   255,
     344,   255,   255,   255,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,    44,   239,    92,    93,
     104,    75,    75,    24,   232,   232,   232,   232,   258,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   258,   255,   258,    70,    71,    72,    73,    74,
      75,    76,   226,    44,    63,    64,    70,    71,    72,    73,
      74,    75,    76,    77,   225,   226,   227,   228,   255,    44,
      44,    44,   258,   271,   255,   271,     4,   258,   238,    35,
      36,    20,    21,     4,     5,   282,   283,     4,     5,   284,
     285,   255,   258,   273,   274,   255,   258,   299,   238,   315,
     321,   232,    58,   232,     4,     7,   232,   255,   258,   334,
      58,   234,   336,   341,   232,   232,   231,   231,   231,   232,
     232,   231,   266,   266,   231,   258,   255,   258,    11,   231,
     231,   255,   231,   263,   248,    12,   231,   251,   231,   263,
      12,   263,   251,   251,     5,   254,   254,   254,   233,   258,
     255,   231,   231,   231,   231,   258,   258,   258,   258,   258,
     255,   255,   258,   258,   233,   258,   255,   258,   233,   255,
     233,   255,   233,   258,   255,   258,   258,    43,   263,   263,
     263,   258,   255,   276,   271,   271,   258,   258,   258,   258,
     258,   258,    97,   255,   344,   344,     4,     5,   261,   262,
     261,   262,   263,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   258,   258,   344,   258,   258,   258,   258,   258,
     258,   258,   258,   233,   258,   255,   255,   255,   255,   255,
     258,   258,   255,   258,   233,   258,   258,   255,   258,   255,
     258,   255,   255,   233,   255,   233,   255,   233,   255,   233,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     344,   255,   271,   271,   255,   258,   255,   255,   255,   255,
     255,   233,   233,   255,   254,   255,   254,   255,   255,   255,
     258,   258,   255,   255,   255,   255,   258,   255,   255,   255,
     255,   233,   255,   258,   255,   233,   233,   255,   255,   255,
     255,   255,   255,   255,   255,   260,   259,   258,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   258,   233,
     233,    75,   309,    14,    16,    18,    41,    44,    49,   313,
     245,   246,   232,   232,   231,   232,   232,   231,   231,    43,
     298,    14,    16,    18,    41,    44,    49,   306,    46,   238,
     258,   232,   255,   258,    51,   335,   230,   231,   232,     4,
       7,   232,    10,   342,   271,   271,     4,     5,   258,   258,
     271,   271,   332,    10,   265,   231,    86,    87,    97,   255,
     258,   258,   336,   263,   255,   263,   251,   258,   258,   232,
     231,   231,   231,   233,   233,   255,   258,   255,   258,   258,
     258,   233,   231,   231,   233,   233,   233,   231,   231,   231,
     233,   231,   231,   231,   233,   231,   231,   233,   233,   233,
     240,   231,   251,   251,     4,     5,   280,   233,   233,   231,
     231,   233,   231,   231,   231,   233,   231,   233,   231,   233,
     232,   232,   233,   233,   231,   231,   251,   231,   233,   233,
     233,   233,   233,   231,   233,   233,   231,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   231,   233,
     233,   231,   231,   231,   233,   231,   231,   233,   231,   233,
     233,   233,   233,   233,   231,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   231,   231,   233,   233,
     233,   233,   233,   231,   233,   233,   233,   233,   233,   233,
     231,   233,   231,   231,   231,   231,   231,   233,   231,   231,
     233,   231,   233,   233,   231,   233,   231,   231,   231,   231,
     231,   231,   231,   233,   233,   231,   233,   231,   258,   258,
     290,   238,   258,   267,   345,   267,   346,   271,   271,   283,
     271,   271,   285,   274,    43,   300,   316,    49,    50,   322,
     231,   258,   231,   233,   233,   232,   255,   255,   258,   258,
     337,   338,   258,     4,     5,   328,   330,   233,   233,   232,
     232,   231,   231,   233,   233,   258,    85,    85,   231,   231,
     231,   263,   231,   231,   271,   258,   258,   258,   231,   231,
     255,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     242,   258,   263,   263,   277,   258,   258,   258,   258,   258,
     255,    97,   255,   233,   233,   258,   258,   263,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   255,   258,   255,
     255,   255,   258,   258,   258,   258,   262,   255,   262,   255,
     255,   258,   258,   258,   258,   258,   258,   255,   255,   258,
     258,   258,    16,    44,   310,   231,   231,   233,   233,   233,
     233,    39,    40,   302,   238,   258,   231,   255,    58,   255,
     335,   231,   328,   328,   233,   232,   232,   231,   271,   271,
     258,   258,   231,   344,   344,   255,   255,   255,   258,   258,
     233,   233,   233,   231,   233,   255,   255,   233,   231,   231,
     231,   231,   231,   233,   233,   231,   231,   251,   232,   233,
     233,   233,   233,   233,   233,   233,   231,   233,   233,   233,
     233,   251,   233,   233,   233,   233,   233,   231,   233,   233,
     233,   231,   233,   233,   231,   233,   231,   233,   233,   233,
     231,   231,   233,   231,   233,   233,   231,   233,   233,   233,
     231,   231,   231,   233,   231,   231,   233,   233,   233,   233,
      12,   267,   267,   299,    43,    38,   317,   233,   258,   233,
     232,   231,   258,   339,   271,   271,   329,   233,   233,   255,
     231,   231,    75,    75,   258,    75,   231,   258,   258,   258,
     258,   258,   258,   258,   263,     4,     5,   286,   287,   255,
     258,   258,   255,   258,   258,   255,   258,   255,   255,   255,
     258,   258,   258,   258,   258,   301,   303,    48,   324,    60,
      61,   233,    58,   258,   255,   233,   328,   233,   233,   328,
     255,   255,   255,   255,   233,   255,   258,   233,   233,   231,
     231,   233,   233,   233,   232,   232,   231,   233,   233,   231,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   231,   231,    13,   294,   238,   238,   258,    47,   323,
     232,   232,   231,   233,   340,    75,   258,   258,   233,   233,
     287,   278,   258,   258,   258,   258,   291,    46,   327,   238,
     318,   255,   258,   258,   342,   255,   233,   233,   238,   233,
     231,   231,   238,   325,    14,    16,    18,    41,    44,    49,
     319,   231,   233,   231,   233,   328,    25,    44,   279,   258,
     258,   292,   238,   255,   258,   233,   233,    14,    16,    18,
      41,    44,    49,   293,   326,   233,   233,     4,   295,   324
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   235,   236,   236,   236,   236,   236,   237,   238,   239,
     240,   238,   241,   241,   241,   241,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   243,   242,   244,   242,   242,   242,   242,   242,   242,
     242,   245,   242,   246,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   247,   242,   248,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   249,   249,   249,   249,   249,   250,   250,   250,   250,
     250,   250,   251,   251,   252,   252,   252,   252,   252,   253,
     253,   254,   254,   255,   255,   255,   255,   255,   255,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   257,   257,   259,   258,   260,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   261,   262,   263,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   265,   265,   265,
     266,   266,   266,   266,   267,   267,   268,   268,   268,   268,
     269,   270,   272,   271,   273,   273,   273,   274,   274,   276,
     277,   278,   275,   279,   279,   280,   280,   281,   281,   281,
     281,   282,   282,   283,   283,   283,   283,   284,   284,   285,
     285,   285,   285,   286,   286,   286,   287,   287,   287,   287,
     289,   290,   291,   292,   288,   293,   293,   293,   293,   293,
     293,   294,   294,   295,   295,   297,   296,   298,   298,   299,
     299,   300,   301,   300,   302,   303,   302,   305,   304,   306,
     306,   306,   306,   306,   306,   308,   309,   307,   310,   310,
     312,   311,   313,   313,   313,   313,   313,   313,   315,   316,
     317,   318,   314,   319,   319,   319,   319,   319,   319,   321,
     320,   322,   322,   323,   323,   324,   325,   326,   324,   327,
     327,   328,   329,   328,   330,   330,   330,   330,   331,   331,
     332,   332,   332,   332,   333,   333,   333,   333,   334,   334,
     334,   334,   334,   335,   335,   335,   337,   336,   338,   336,
     339,   336,   340,   336,   341,   336,   342,   342,   343,   343,
     343,   343,   343,   343,   343,   343,   343,   343,   343,   343,
     343,   343,   344,   344,   345,   345,   346,   346
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     3,     3,     3,     3,     2,     1,     0,
       0,     5,     1,     2,     1,     2,     0,     1,     1,     2,
       1,     1,     1,     1,     1,     1,     2,     1,     1,     1,
       1,     0,     3,     0,     3,     1,     1,     2,     2,     3,
       3,     0,     5,     0,     5,     2,     1,     2,     1,     2,
       2,     2,     3,     4,     4,     0,     3,     0,     4,     6,
       2,     6,     2,     2,     2,     1,     2,     1,     2,     2,
       2,     5,     7,     3,     2,     3,     4,     5,     3,     2,
       4,     3,     8,     6,     6,     2,     2,     5,     7,     4,
       6,     8,     5,     2,     2,     2,     2,     3,     2,     2,
       1,     1,     3,     4,     4,     4,     4,     4,     4,     1,
       1,     2,     1,     2,     2,     8,     6,     6,     4,     6,
       8,     4,     4,     4,     8,     8,    10,    10,     3,     4,
       6,     3,     4,     6,     3,     8,     3,     8,     4,     4,
       4,     0,     1,     1,     2,     2,     3,    10,     8,     8,
       8,     3,     1,     1,     6,     4,     4,     6,     6,     4,
       6,     1,     4,     1,     1,     1,     1,     3,     3,     6,
       6,     8,     6,     4,     6,     8,     4,     1,     3,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     6,     1,     3,     1,     3,     4,     6,     6,     4,
       6,     4,     6,    10,     4,     4,     4,     8,     6,     4,
       4,     4,     4,     6,     3,     3,     0,     4,     0,     4,
       2,     3,     3,     3,     3,     3,     3,     3,     4,     6,
       1,     4,     4,     6,     6,     1,     1,     3,     3,     3,
       3,     3,     2,     3,     3,     3,     3,     3,     3,     3,
       1,     3,     3,     3,     3,     4,     4,     4,     4,     4,
       4,     6,     4,     4,     6,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     6,     4,     3,     6,     6,     4,
       4,     4,     4,     6,     6,     8,     6,     8,     4,     4,
       4,     8,     4,     4,     4,     4,     1,     3,     4,     1,
       3,     4,     1,     3,     4,     1,     3,     6,     6,     4,
       6,     6,     6,     4,     8,     6,     8,     6,     4,     4,
       4,     6,     6,     6,     8,     4,     8,     4,     8,     8,
       6,    12,    12,     3,     6,     6,     6,     1,     2,     2,
       1,     1,     1,     1,     1,     1,     4,     6,     4,     6,
       4,     4,     0,     2,     0,     1,     3,     1,     1,     0,
       0,     0,    11,     1,     1,     1,     1,     0,     1,     1,
       2,     1,     3,     1,     1,     4,     4,     1,     3,     1,
       1,     4,     4,     0,     1,     3,     1,     1,     3,     3,
       0,     0,     0,     0,    14,     1,     1,     1,     1,     1,
       1,     0,     2,     0,     1,     0,     7,     1,     2,     1,
       1,     0,     0,     5,     0,     0,     4,     0,     4,     1,
       1,     1,     1,     1,     1,     0,     0,     6,     1,     1,
       0,     4,     1,     2,     1,     1,     1,     1,     0,     0,
       0,     0,    11,     1,     1,     1,     1,     1,     1,     0,
       5,     1,     1,     0,     2,     0,     0,     0,     7,     0,
       1,     1,     0,     4,     1,     4,     1,     4,     1,     3,
       1,     4,     1,     4,     1,     1,     3,     3,     0,     2,
       4,     1,     3,     0,     2,     6,     0,     4,     0,     4,
       0,     6,     0,     9,     0,     3,     0,     1,     0,     2,
       2,     4,     1,     4,     6,     6,     7,    10,    12,     7,
      10,    12,     2,     1,     1,     3,     1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 3: /* program_or_expression: tSTART_EXPRESSION expression tEOPROG  */
#line 205 "yabasic.bison"
                                         {YYACCEPT;}
#line 4050 "bison.c"
    break;

  case 4: /* program_or_expression: tSTART_STRING_EXPRESSION string_expression tEOPROG  */
#line 206 "yabasic.bison"
                                                       {YYACCEPT;}
#line 4056 "bison.c"
    break;

  case 5: /* program_or_expression: tSTART_ASSIGNMENT assignment tEOPROG  */
#line 207 "yabasic.bison"
                                         {YYACCEPT;}
#line 4062 "bison.c"
    break;

  case 6: /* program_or_expression: tSTART_FUNCTION_DEFINITION function_definition tEOPROG  */
#line 208 "yabasic.bison"
                                                           {YYACCEPT;}
#line 4068 "bison.c"
    break;

  case 7: /* program: statement_list tEOPROG  */
#line 211 "yabasic.bison"
                                {YYACCEPT;}
#line 4074 "bison.c"
    break;

  case 9: /* $@1: %empty  */
#line 215 "yabasic.bison"
                   {if (severity_so_far >= sERROR) {YYABORT;}}
#line 4080 "bison.c"
    break;

  case 10: /* $@2: %empty  */
#line 215 "yabasic.bison"
                                                                    {if (in_short_if > 0 && (yyvsp[0].nnl) > 0) lyyerror(sERROR,"short if-statement (i.e. without 'then' and ended by newline) does not contain any statements");}
#line 4086 "bison.c"
    break;

  case 18: /* statement: tIMPORT  */
#line 226 "yabasic.bison"
            {report_if_missing("can not import a library in a loop or an if-statement",FALSE);}
#line 4092 "bison.c"
    break;

  case 19: /* statement: tERROR string_expression  */
#line 227 "yabasic.bison"
                             {add_command(cERROR);}
#line 4098 "bison.c"
    break;

  case 25: /* statement: tBREAK  */
#line 233 "yabasic.bison"
           {add_command(cPOP_MULTI);create_mybreak(1);if (!loop_nesting && !switch_nesting) lyyerror(sERROR,"break outside loop or switch");}
#line 4104 "bison.c"
    break;

  case 26: /* statement: tBREAK tDIGITS  */
#line 234 "yabasic.bison"
                   {add_command(cPOP_MULTI);create_mybreak(atoi((yyvsp[0].digits)));if (!loop_nesting && !switch_nesting) lyyerror(sERROR,"break outside loop or switch");}
#line 4110 "bison.c"
    break;

  case 27: /* statement: tCONTINUE  */
#line 235 "yabasic.bison"
              {add_command(cPOP_MULTI);add_command_with_switch_state(cCONTINUE);if (!loop_nesting) lyyerror(sERROR,"continue outside loop");}
#line 4116 "bison.c"
    break;

  case 29: /* statement: function_or_array  */
#line 237 "yabasic.bison"
                      {create_call((yyvsp[0].symbol));add_command(cPOP);}
#line 4122 "bison.c"
    break;

  case 30: /* statement: stringfunction_or_array  */
#line 238 "yabasic.bison"
                            {create_call((yyvsp[0].symbol));add_command(cPOP);}
#line 4128 "bison.c"
    break;

  case 31: /* $@3: %empty  */
#line 239 "yabasic.bison"
           {if (function_type==ftNONE) lyyerror(sERROR,"no use for 'local' outside functions");}
#line 4134 "bison.c"
    break;

  case 33: /* $@4: %empty  */
#line 240 "yabasic.bison"
            {if (function_type==ftNONE) lyyerror(sERROR,"no use for 'static' outside functions");}
#line 4140 "bison.c"
    break;

  case 37: /* statement: tGOTO symbol_or_lineno  */
#line 243 "yabasic.bison"
                           {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));}
#line 4146 "bison.c"
    break;

  case 38: /* statement: tGOSUB symbol_or_lineno  */
#line 244 "yabasic.bison"
                            {create_gosub((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));}
#line 4152 "bison.c"
    break;

  case 39: /* statement: tON tINTERRUPT tBREAK  */
#line 245 "yabasic.bison"
                          {create_exception(TRUE);}
#line 4158 "bison.c"
    break;

  case 40: /* statement: tON tINTERRUPT tCONTINUE  */
#line 246 "yabasic.bison"
                             {create_exception(FALSE);}
#line 4164 "bison.c"
    break;

  case 41: /* $@5: %empty  */
#line 247 "yabasic.bison"
                         {add_command(cSKIPPER);}
#line 4170 "bison.c"
    break;

  case 42: /* statement: tON expression tGOTO $@5 goto_list  */
#line 248 "yabasic.bison"
              {add_command(cNOP);}
#line 4176 "bison.c"
    break;

  case 43: /* $@6: %empty  */
#line 249 "yabasic.bison"
                          {add_command(cSKIPPER);}
#line 4182 "bison.c"
    break;

  case 44: /* statement: tON expression tGOSUB $@6 gosub_list  */
#line 250 "yabasic.bison"
               {add_command(cNOP);}
#line 4188 "bison.c"
    break;

  case 45: /* statement: tLABEL symbol_or_lineno  */
#line 251 "yabasic.bison"
                            {create_label((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol),cLABEL);}
#line 4194 "bison.c"
    break;

  case 46: /* statement: open_clause  */
#line 252 "yabasic.bison"
                {add_command(cCHECKOPEN);}
#line 4200 "bison.c"
    break;

  case 47: /* statement: tCLOSE hashed_number  */
#line 253 "yabasic.bison"
                         {add_command(cCLOSE);}
#line 4206 "bison.c"
    break;

  case 48: /* statement: seek_clause  */
#line 254 "yabasic.bison"
                {add_command(cCHECKSEEK);}
#line 4212 "bison.c"
    break;

  case 49: /* statement: tCOMPILE string_expression  */
#line 255 "yabasic.bison"
                               {add_command(cCOMPILE);}
#line 4218 "bison.c"
    break;

  case 50: /* statement: tEXECUTE call_list  */
#line 256 "yabasic.bison"
                       {create_execute(0);add_command(cPOP);add_command(cPOP);}
#line 4224 "bison.c"
    break;

  case 51: /* statement: tEXECUTE2 call_list  */
#line 257 "yabasic.bison"
                        {create_execute(1);add_command(cPOP);add_command(cPOP);}
#line 4230 "bison.c"
    break;

  case 52: /* statement: tPRINT printintro printlist  */
#line 258 "yabasic.bison"
                                {create_colour(0);create_print('n');create_pps(cPOPSTREAM,0);}
#line 4236 "bison.c"
    break;

  case 53: /* statement: tPRINT printintro printlist ';'  */
#line 259 "yabasic.bison"
                                    {create_colour(0);create_pps(cPOPSTREAM,0);}
#line 4242 "bison.c"
    break;

  case 54: /* statement: tPRINT printintro printlist ','  */
#line 260 "yabasic.bison"
                                    {create_colour(0);create_print('t');create_pps(cPOPSTREAM,0);}
#line 4248 "bison.c"
    break;

  case 55: /* $@7: %empty  */
#line 261 "yabasic.bison"
           {tileol=FALSE;}
#line 4254 "bison.c"
    break;

  case 57: /* $@8: %empty  */
#line 262 "yabasic.bison"
                 {tileol=TRUE;}
#line 4260 "bison.c"
    break;

  case 59: /* statement: tCOLOUR expression ',' expression ',' expression  */
#line 263 "yabasic.bison"
                                                     {add_command(cGCOLOUR);}
#line 4266 "bison.c"
    break;

  case 60: /* statement: tCOLOUR string_expression  */
#line 264 "yabasic.bison"
                              {add_command(cGCOLOUR2);}
#line 4272 "bison.c"
    break;

  case 61: /* statement: tBACKCOLOUR expression ',' expression ',' expression  */
#line 265 "yabasic.bison"
                                                         {add_command(cGBACKCOLOUR);}
#line 4278 "bison.c"
    break;

  case 62: /* statement: tBACKCOLOUR string_expression  */
#line 266 "yabasic.bison"
                                  {add_command(cGBACKCOLOUR2);}
#line 4284 "bison.c"
    break;

  case 65: /* statement: tRESTORE  */
#line 269 "yabasic.bison"
             {create_restore("");}
#line 4290 "bison.c"
    break;

  case 66: /* statement: tRESTORE symbol_or_lineno  */
#line 270 "yabasic.bison"
                              {create_restore((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));}
#line 4296 "bison.c"
    break;

  case 67: /* statement: tRETURN  */
#line 271 "yabasic.bison"
            {if (function_type!=ftNONE) {
	       add_command(cCLEARSYMREFS);end_symref_chain();
	       add_command(cPOPSYMLIST);
               create_check_return_value(ftNONE,function_type);
               add_command(cRETURN_FROM_CALL);
             } else {
               add_command(cRETURN_FROM_GOSUB);
            }}
#line 4309 "bison.c"
    break;

  case 68: /* statement: tRETURN expression  */
#line 279 "yabasic.bison"
                       {if (function_type==ftNONE) {lyyerror(sERROR,"a value can only be returned from a subroutine"); YYABORT;} add_command(cCLEARSYMREFS);end_symref_chain();add_command(cPOPSYMLIST);create_check_return_value(ftNUMBER,function_type);add_command(cRETURN_FROM_CALL);}
#line 4315 "bison.c"
    break;

  case 69: /* statement: tRETURN string_expression  */
#line 280 "yabasic.bison"
                              {if (function_type==ftNONE) {lyyerror(sERROR,"can not return value"); YYABORT;} add_command(cCLEARSYMREFS);end_symref_chain();add_command(cPOPSYMLIST);create_check_return_value(ftSTRING,function_type);add_command(cRETURN_FROM_CALL);}
#line 4321 "bison.c"
    break;

  case 71: /* statement: tOPEN tWINDOW expression ',' expression  */
#line 282 "yabasic.bison"
                                            {create_openwin(FALSE);}
#line 4327 "bison.c"
    break;

  case 72: /* statement: tOPEN tWINDOW expression ',' expression ',' string_expression  */
#line 284 "yabasic.bison"
         {create_openwin(TRUE);}
#line 4333 "bison.c"
    break;

  case 73: /* statement: tWINDOW tORIGIN string_expression  */
#line 285 "yabasic.bison"
                                      {add_command(cMOVEORIGIN);}
#line 4339 "bison.c"
    break;

  case 74: /* statement: tDOT coordinates  */
#line 286 "yabasic.bison"
                     {add_command(cDOT);}
#line 4345 "bison.c"
    break;

  case 75: /* statement: tCLEAR tDOT coordinates  */
#line 287 "yabasic.bison"
                            {add_command(cDOT);putindrawmode(dmCLEAR);}
#line 4351 "bison.c"
    break;

  case 76: /* statement: tLINE coordinates to coordinates  */
#line 288 "yabasic.bison"
                                     {create_line(2);}
#line 4357 "bison.c"
    break;

  case 77: /* statement: tCLEAR tLINE coordinates to coordinates  */
#line 289 "yabasic.bison"
                                            {create_line(2);putindrawmode(dmCLEAR);}
#line 4363 "bison.c"
    break;

  case 78: /* statement: tLINE tTO coordinates  */
#line 290 "yabasic.bison"
                          {create_line(1);}
#line 4369 "bison.c"
    break;

  case 79: /* statement: tLINE coordinates  */
#line 291 "yabasic.bison"
                      {create_line(1);}
#line 4375 "bison.c"
    break;

  case 80: /* statement: tCLEAR tLINE tTO coordinates  */
#line 292 "yabasic.bison"
                                 {create_line(1);putindrawmode(dmCLEAR);}
#line 4381 "bison.c"
    break;

  case 81: /* statement: tCLEAR tLINE coordinates  */
#line 293 "yabasic.bison"
                             {create_line(1);putindrawmode(dmCLEAR);}
#line 4387 "bison.c"
    break;

  case 82: /* statement: tPUTBIT string_expression to expression ',' expression ',' string_expression  */
#line 294 "yabasic.bison"
                                                                                 {add_command(cPUTBIT);}
#line 4393 "bison.c"
    break;

  case 83: /* statement: tPUTBIT string_expression to expression ',' expression  */
#line 295 "yabasic.bison"
                                                           {create_pushstr("solid"); add_command(cPUTBIT);}
#line 4399 "bison.c"
    break;

  case 84: /* statement: tPUTCHAR string_expression to expression ',' expression  */
#line 296 "yabasic.bison"
                                                            {add_command(cPUTCHAR);}
#line 4405 "bison.c"
    break;

  case 85: /* statement: tNEW tCURVE  */
#line 297 "yabasic.bison"
                {create_line(-1);}
#line 4411 "bison.c"
    break;

  case 86: /* statement: tCLOSE tCURVE  */
#line 298 "yabasic.bison"
                  {create_line(0);}
#line 4417 "bison.c"
    break;

  case 87: /* statement: clear_fill_clause tCIRCLE coordinates ',' expression  */
#line 299 "yabasic.bison"
                                                         {add_command(cCIRCLE);putindrawmode(0);}
#line 4423 "bison.c"
    break;

  case 88: /* statement: clear_fill_clause tTRIANGLE coordinates to coordinates to coordinates  */
#line 300 "yabasic.bison"
                                                                          {add_command(cTRIANGLE);putindrawmode(0);}
#line 4429 "bison.c"
    break;

  case 89: /* statement: tTEXT coordinates ',' string_expression  */
#line 301 "yabasic.bison"
                                            {add_command(cTEXT1);}
#line 4435 "bison.c"
    break;

  case 90: /* statement: tTEXT coordinates ',' string_expression ',' string_expression  */
#line 302 "yabasic.bison"
                                                                  {add_command(cTEXT2);}
#line 4441 "bison.c"
    break;

  case 91: /* statement: tTEXT coordinates ',' string_expression ',' string_expression ',' string_expression  */
#line 303 "yabasic.bison"
                                                                                        {add_command(cTEXT3);}
#line 4447 "bison.c"
    break;

  case 92: /* statement: clear_fill_clause tRECT coordinates to coordinates  */
#line 304 "yabasic.bison"
                                                       {add_command(cRECT);putindrawmode(0);}
#line 4453 "bison.c"
    break;

  case 93: /* statement: tCLOSE tWINDOW  */
#line 305 "yabasic.bison"
                   {add_command(cCLOSEWIN);}
#line 4459 "bison.c"
    break;

  case 94: /* statement: tCLEAR tWINDOW  */
#line 306 "yabasic.bison"
                   {add_command(cCLEARWIN);}
#line 4465 "bison.c"
    break;

  case 95: /* statement: tCLEAR tSCREEN  */
#line 307 "yabasic.bison"
                   {add_command(cCLEARSCR);}
#line 4471 "bison.c"
    break;

  case 96: /* statement: tOPEN tPRINTER  */
#line 308 "yabasic.bison"
                   {create_openprinter(0);}
#line 4477 "bison.c"
    break;

  case 97: /* statement: tOPEN tPRINTER string_expression  */
#line 309 "yabasic.bison"
                                     {create_openprinter(1);}
#line 4483 "bison.c"
    break;

  case 98: /* statement: tCLOSE tPRINTER  */
#line 310 "yabasic.bison"
                    {add_command(cCLOSEPRN);}
#line 4489 "bison.c"
    break;

  case 99: /* statement: tWAIT expression  */
#line 311 "yabasic.bison"
                     {add_command(cWAIT);}
#line 4495 "bison.c"
    break;

  case 100: /* statement: tBELL  */
#line 312 "yabasic.bison"
          {add_command(cBELL);}
#line 4501 "bison.c"
    break;

  case 101: /* statement: tINKEY  */
#line 313 "yabasic.bison"
           {create_pushdbl(-1);create_function(fINKEY);add_command(cPOP);}
#line 4507 "bison.c"
    break;

  case 102: /* statement: tINKEY '(' ')'  */
#line 314 "yabasic.bison"
                   {create_pushdbl(-1);create_function(fINKEY);add_command(cPOP);}
#line 4513 "bison.c"
    break;

  case 103: /* statement: tINKEY '(' expression ')'  */
#line 315 "yabasic.bison"
                              {create_function(fINKEY);add_command(cPOP);}
#line 4519 "bison.c"
    break;

  case 104: /* statement: tSYSTEM '(' string_expression ')'  */
#line 316 "yabasic.bison"
                                      {create_function(fSYSTEM);
	add_command(cPOP);}
#line 4526 "bison.c"
    break;

  case 105: /* statement: tPOKE string_expression ',' string_expression  */
#line 318 "yabasic.bison"
                                                  {create_poke('s');}
#line 4532 "bison.c"
    break;

  case 106: /* statement: tPOKE string_expression ',' expression  */
#line 319 "yabasic.bison"
                                           {create_poke('d');}
#line 4538 "bison.c"
    break;

  case 107: /* statement: tPOKE hashed_number ',' string_expression  */
#line 320 "yabasic.bison"
                                              {create_poke('S');}
#line 4544 "bison.c"
    break;

  case 108: /* statement: tPOKE hashed_number ',' expression  */
#line 321 "yabasic.bison"
                                       {create_poke('D');}
#line 4550 "bison.c"
    break;

  case 109: /* statement: tEND  */
#line 322 "yabasic.bison"
         {add_command(cEND);}
#line 4556 "bison.c"
    break;

  case 110: /* statement: tEXIT  */
#line 323 "yabasic.bison"
          {create_pushdbl(0);add_command(cEXIT);}
#line 4562 "bison.c"
    break;

  case 111: /* statement: tEXIT expression  */
#line 324 "yabasic.bison"
                     {add_command(cEXIT);}
#line 4568 "bison.c"
    break;

  case 112: /* statement: tDOCU  */
#line 325 "yabasic.bison"
          {create_docu((yyvsp[0].symbol));}
#line 4574 "bison.c"
    break;

  case 113: /* statement: tBIND string_expression  */
#line 326 "yabasic.bison"
                            {add_command(cBIND);}
#line 4580 "bison.c"
    break;

  case 114: /* statement: tFRNBF_FREE string_expression  */
#line 327 "yabasic.bison"
                                  {add_command(cFRNBF_FREE);}
#line 4586 "bison.c"
    break;

  case 115: /* statement: tFRNBF_SET string_expression ',' expression ',' string_expression ',' expression  */
#line 328 "yabasic.bison"
                                                                                     {add_command(cFRNBF_SET_NUMBER);}
#line 4592 "bison.c"
    break;

  case 116: /* statement: tFRNBF_SET string_expression ',' expression ',' string_expression  */
#line 329 "yabasic.bison"
                                                                      {add_command(cFRNBF_SET_STRING);}
#line 4598 "bison.c"
    break;

  case 117: /* statement: tFRNBF_SET_BUFFER string_expression ',' expression ',' string_expression  */
#line 330 "yabasic.bison"
                                                                             {add_command(cFRNBF_SET_BUFFER);}
#line 4604 "bison.c"
    break;

  case 118: /* statement: tBEAM_CLOSE '(' expression ')'  */
#line 332 "yabasic.bison"
                                   {add_command(cBEAM_CLOSE);}
#line 4610 "bison.c"
    break;

  case 119: /* statement: tBEAM_TITLE '(' expression ',' string_expression ')'  */
#line 333 "yabasic.bison"
                                                         {add_command(cBEAM_TITLE);}
#line 4616 "bison.c"
    break;

  case 120: /* statement: tBEAM_SIZE '(' expression ',' expression ',' expression ')'  */
#line 334 "yabasic.bison"
                                                                {add_command(cBEAM_SIZE);}
#line 4622 "bison.c"
    break;

  case 121: /* statement: tBEAM_BEGIN '(' expression ')'  */
#line 335 "yabasic.bison"
                                   {add_command(cBEAM_BEGIN);}
#line 4628 "bison.c"
    break;

  case 122: /* statement: tBEAM_END '(' expression ')'  */
#line 336 "yabasic.bison"
                                 {add_command(cBEAM_END);}
#line 4634 "bison.c"
    break;

  case 123: /* statement: tBEAM_LABEL '(' string_expression ')'  */
#line 337 "yabasic.bison"
                                          {add_command(cBEAM_LABEL);}
#line 4640 "bison.c"
    break;

  case 124: /* statement: tBEAM_TEXT '(' string_expression ',' expression ',' expression ')'  */
#line 338 "yabasic.bison"
                                                                       {add_command(cBEAM_TEXT);}
#line 4646 "bison.c"
    break;

  case 125: /* statement: tBEAM_IMAGE '(' string_expression ',' expression ',' expression ')'  */
#line 339 "yabasic.bison"
                                                                        {add_command(cBEAM_IMAGE);}
#line 4652 "bison.c"
    break;

  case 126: /* statement: tBEAM_PROGRESS '(' expression ',' expression ',' expression ',' expression ')'  */
#line 340 "yabasic.bison"
                                                                                   {add_command(cBEAM_PROGRESS);}
#line 4658 "bison.c"
    break;

  case 127: /* statement: tBEAM_VBAR '(' expression ',' expression ',' expression ',' expression ')'  */
#line 341 "yabasic.bison"
                                                                               {add_command(cBEAM_VBAR);}
#line 4664 "bison.c"
    break;

  case 128: /* statement: tBEAM_SEPARATOR '(' ')'  */
#line 342 "yabasic.bison"
                            {add_command(cBEAM_SEPARATOR);}
#line 4670 "bison.c"
    break;

  case 129: /* statement: tBEAM_SPACING '(' expression ')'  */
#line 343 "yabasic.bison"
                                     {add_command(cBEAM_SPACING);}
#line 4676 "bison.c"
    break;

  case 130: /* statement: tBEAM_ROW '(' expression ',' expression ')'  */
#line 344 "yabasic.bison"
                                                {add_command(cBEAM_ROW);}
#line 4682 "bison.c"
    break;

  case 131: /* statement: tBEAM_ROW_END '(' ')'  */
#line 345 "yabasic.bison"
                          {add_command(cBEAM_ROW_END);}
#line 4688 "bison.c"
    break;

  case 132: /* statement: tBEAM_GROUP_BEGIN '(' string_expression ')'  */
#line 346 "yabasic.bison"
                                                {add_command(cBEAM_GROUP_BEGIN);}
#line 4694 "bison.c"
    break;

  case 133: /* statement: tBEAM_GROUP_BEGIN '(' string_expression ',' expression ')'  */
#line 347 "yabasic.bison"
                                                               {add_command(cBEAM_GROUP_BEGIN_H);}
#line 4700 "bison.c"
    break;

  case 134: /* statement: tBEAM_GROUP_END '(' ')'  */
#line 348 "yabasic.bison"
                            {add_command(cBEAM_GROUP_END);}
#line 4706 "bison.c"
    break;

  case 135: /* statement: tBEAM_PANEL_BEGIN '(' string_expression ',' expression ',' expression ')'  */
#line 349 "yabasic.bison"
                                                                              {add_command(cBEAM_PANEL_BEGIN);}
#line 4712 "bison.c"
    break;

  case 136: /* statement: tBEAM_PANEL_END '(' ')'  */
#line 350 "yabasic.bison"
                            {add_command(cBEAM_PANEL_END);}
#line 4718 "bison.c"
    break;

  case 137: /* statement: tBEAM_SET_COLOR '(' expression ',' expression ',' expression ')'  */
#line 351 "yabasic.bison"
                                                                     {add_command(cBEAM_SET_COLOR);}
#line 4724 "bison.c"
    break;

  case 138: /* statement: tBEAM_SET_STYLE '(' string_expression ')'  */
#line 352 "yabasic.bison"
                                              {add_command(cBEAM_SET_STYLE);}
#line 4730 "bison.c"
    break;

  case 139: /* statement: tBEAM_SLEEP '(' expression ')'  */
#line 353 "yabasic.bison"
                                   {add_command(cBEAM_SLEEP);}
#line 4736 "bison.c"
    break;

  case 140: /* statement: tBEAM_NMEA_CLOSE '(' expression ')'  */
#line 355 "yabasic.bison"
                                        {add_command(cBEAM_NMEA_CLOSE);}
#line 4742 "bison.c"
    break;

  case 141: /* clear_fill_clause: %empty  */
#line 359 "yabasic.bison"
                               {drawmode=0;}
#line 4748 "bison.c"
    break;

  case 142: /* clear_fill_clause: tCLEAR  */
#line 360 "yabasic.bison"
           {drawmode=dmCLEAR;}
#line 4754 "bison.c"
    break;

  case 143: /* clear_fill_clause: tFILL  */
#line 361 "yabasic.bison"
          {drawmode=dmFILL;}
#line 4760 "bison.c"
    break;

  case 144: /* clear_fill_clause: tCLEAR tFILL  */
#line 362 "yabasic.bison"
                 {drawmode=dmFILL+dmCLEAR;}
#line 4766 "bison.c"
    break;

  case 145: /* clear_fill_clause: tFILL tCLEAR  */
#line 363 "yabasic.bison"
                 {drawmode=dmFILL+dmCLEAR;}
#line 4772 "bison.c"
    break;

  case 146: /* string_assignment: tSTRSYM tEQU string_expression  */
#line 367 "yabasic.bison"
                                                  {add_command_with_sym_and_diag(cPOPSTRSYM,dotify((yyvsp[-2].symbol),FALSE),NULL);}
#line 4778 "bison.c"
    break;

  case 147: /* string_assignment: tMID '(' string_scalar_or_array ',' expression ',' expression ')' tEQU string_expression  */
#line 368 "yabasic.bison"
                                                                                             {create_changestring(fMID);}
#line 4784 "bison.c"
    break;

  case 148: /* string_assignment: tMID '(' string_scalar_or_array ',' expression ')' tEQU string_expression  */
#line 369 "yabasic.bison"
                                                                              {create_changestring(fMID2);}
#line 4790 "bison.c"
    break;

  case 149: /* string_assignment: tLEFT '(' string_scalar_or_array ',' expression ')' tEQU string_expression  */
#line 370 "yabasic.bison"
                                                                               {create_changestring(fLEFT);}
#line 4796 "bison.c"
    break;

  case 150: /* string_assignment: tRIGHT '(' string_scalar_or_array ',' expression ')' tEQU string_expression  */
#line 371 "yabasic.bison"
                                                                                {create_changestring(fRIGHT);}
#line 4802 "bison.c"
    break;

  case 151: /* string_assignment: stringfunction_or_array tEQU string_expression  */
#line 372 "yabasic.bison"
                                                   {create_doarray(dotify((yyvsp[-2].symbol),FALSE),ASSIGNSTRINGARRAY);}
#line 4808 "bison.c"
    break;

  case 154: /* open_clause: tOPEN hashed_number ',' string_expression ',' string_expression  */
#line 379 "yabasic.bison"
                                                                             {create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}
#line 4814 "bison.c"
    break;

  case 155: /* open_clause: tOPEN hashed_number ',' string_expression  */
#line 380 "yabasic.bison"
                                              {create_myopen(OPEN_HAS_STREAM);}
#line 4820 "bison.c"
    break;

  case 156: /* open_clause: tOPEN hashed_number ',' tPRINTER  */
#line 381 "yabasic.bison"
                                     {create_myopen(OPEN_HAS_STREAM+OPEN_PRINTER);}
#line 4826 "bison.c"
    break;

  case 157: /* open_clause: tOPEN string_expression tFOR tREADING tAS hashed_number  */
#line 382 "yabasic.bison"
                                                            {add_command(cSWAP);create_pushstr("r");create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}
#line 4832 "bison.c"
    break;

  case 158: /* open_clause: tOPEN string_expression tFOR tWRITING tAS hashed_number  */
#line 383 "yabasic.bison"
                                                            {add_command(cSWAP);create_pushstr("w");create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}
#line 4838 "bison.c"
    break;

  case 159: /* seek_clause: tSEEK hashed_number ',' expression  */
#line 386 "yabasic.bison"
                                                {add_command(cSEEK);}
#line 4844 "bison.c"
    break;

  case 160: /* seek_clause: tSEEK hashed_number ',' expression ',' string_expression  */
#line 387 "yabasic.bison"
                                                             {add_command(cSEEK2);}
#line 4850 "bison.c"
    break;

  case 161: /* string_scalar_or_array: tSTRSYM  */
#line 390 "yabasic.bison"
                                {add_command_with_sym_and_diag(cPUSHSTRPTR,dotify((yyvsp[0].symbol),FALSE),NULL);}
#line 4856 "bison.c"
    break;

  case 162: /* string_scalar_or_array: tSTRSYM '(' call_list ')'  */
#line 391 "yabasic.bison"
                              {create_doarray(dotify((yyvsp[-3].symbol),FALSE),GETSTRINGPOINTER);}
#line 4862 "bison.c"
    break;

  case 163: /* string_expression: tSTRSYM  */
#line 394 "yabasic.bison"
                           {add_command_with_sym_and_diag(cPUSHSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
#line 4868 "bison.c"
    break;

  case 165: /* string_expression: stringfunction_or_array  */
#line 396 "yabasic.bison"
                            {add_command_with_sym_and_diag(cSTRINGFUNCTION_OR_ARRAY,(yyvsp[0].symbol),NULL);}
#line 4874 "bison.c"
    break;

  case 166: /* string_expression: tSTRING  */
#line 397 "yabasic.bison"
            {if ((yyvsp[0].string)==NULL) {lyyerror(sERROR,"String not terminated");create_pushstr("");} else {create_pushstr((yyvsp[0].string));}}
#line 4880 "bison.c"
    break;

  case 167: /* string_expression: string_expression '+' string_expression  */
#line 398 "yabasic.bison"
                                            {add_command(cCONCAT);}
#line 4886 "bison.c"
    break;

  case 169: /* string_function: tLEFT '(' string_expression ',' expression ')'  */
#line 402 "yabasic.bison"
                                                                {create_function(fLEFT);}
#line 4892 "bison.c"
    break;

  case 170: /* string_function: tRIGHT '(' string_expression ',' expression ')'  */
#line 403 "yabasic.bison"
                                                    {create_function(fRIGHT);}
#line 4898 "bison.c"
    break;

  case 171: /* string_function: tMID '(' string_expression ',' expression ',' expression ')'  */
#line 404 "yabasic.bison"
                                                                 {create_function(fMID);}
#line 4904 "bison.c"
    break;

  case 172: /* string_function: tMID '(' string_expression ',' expression ')'  */
#line 405 "yabasic.bison"
                                                  {create_function(fMID2);}
#line 4910 "bison.c"
    break;

  case 173: /* string_function: tSTR '(' expression ')'  */
#line 406 "yabasic.bison"
                            {create_function(fSTR);}
#line 4916 "bison.c"
    break;

  case 174: /* string_function: tSTR '(' expression ',' string_expression ')'  */
#line 407 "yabasic.bison"
                                                  {create_function(fSTR2);}
#line 4922 "bison.c"
    break;

  case 175: /* string_function: tSTR '(' expression ',' string_expression ',' string_expression ')'  */
#line 408 "yabasic.bison"
                                                                        {create_function(fSTR3);}
#line 4928 "bison.c"
    break;

  case 176: /* string_function: tSTR '(' string_expression ')'  */
#line 409 "yabasic.bison"
                                   {create_function(fSTR4);}
#line 4934 "bison.c"
    break;

  case 177: /* string_function: tINKEY  */
#line 410 "yabasic.bison"
           {create_pushdbl(-1);create_function(fINKEY);}
#line 4940 "bison.c"
    break;

  case 178: /* string_function: tINKEY '(' ')'  */
#line 411 "yabasic.bison"
                   {create_pushdbl(-1);create_function(fINKEY);}
#line 4946 "bison.c"
    break;

  case 179: /* string_function: tINKEY '(' expression ')'  */
#line 412 "yabasic.bison"
                              {create_function(fINKEY);}
#line 4952 "bison.c"
    break;

  case 180: /* string_function: tCHR '(' expression ')'  */
#line 413 "yabasic.bison"
                            {create_function(fCHR);}
#line 4958 "bison.c"
    break;

  case 181: /* string_function: tUPPER '(' string_expression ')'  */
#line 414 "yabasic.bison"
                                     {create_function(fUPPER);}
#line 4964 "bison.c"
    break;

  case 182: /* string_function: tLOWER '(' string_expression ')'  */
#line 415 "yabasic.bison"
                                     {create_function(fLOWER);}
#line 4970 "bison.c"
    break;

  case 183: /* string_function: tLTRIM '(' string_expression ')'  */
#line 416 "yabasic.bison"
                                     {create_function(fLTRIM);}
#line 4976 "bison.c"
    break;

  case 184: /* string_function: tRTRIM '(' string_expression ')'  */
#line 417 "yabasic.bison"
                                     {create_function(fRTRIM);}
#line 4982 "bison.c"
    break;

  case 185: /* string_function: tTRIM '(' string_expression ')'  */
#line 418 "yabasic.bison"
                                    {create_function(fTRIM);}
#line 4988 "bison.c"
    break;

  case 186: /* string_function: tCHOMP '(' string_expression ')'  */
#line 419 "yabasic.bison"
                                     {create_function(fCHOMP);}
#line 4994 "bison.c"
    break;

  case 187: /* string_function: tSYSTEM2 '(' string_expression ')'  */
#line 420 "yabasic.bison"
                                       {create_function(fSYSTEM2);}
#line 5000 "bison.c"
    break;

  case 188: /* string_function: tFRNFN_CALL2 '(' call_list ')'  */
#line 421 "yabasic.bison"
                                   {create_function(fFRNFN_CALL2);}
#line 5006 "bison.c"
    break;

  case 189: /* string_function: tFRNBF_ALLOC '(' expression ')'  */
#line 422 "yabasic.bison"
                                    {create_function(fFRNBF_ALLOC);}
#line 5012 "bison.c"
    break;

  case 190: /* string_function: tFRNBF_DUMP '(' string_expression ')'  */
#line 423 "yabasic.bison"
                                          {create_function(fFRNBF_DUMP);}
#line 5018 "bison.c"
    break;

  case 191: /* string_function: tFRNBF_DUMP '(' string_expression ',' expression ')'  */
#line 424 "yabasic.bison"
                                                         {create_function(fFRNBF_DUMP2);}
#line 5024 "bison.c"
    break;

  case 192: /* string_function: tDATE  */
#line 425 "yabasic.bison"
          {create_function(fDATE);}
#line 5030 "bison.c"
    break;

  case 193: /* string_function: tDATE '(' ')'  */
#line 426 "yabasic.bison"
                  {create_function(fDATE);}
#line 5036 "bison.c"
    break;

  case 194: /* string_function: tTIME  */
#line 427 "yabasic.bison"
          {create_function(fTIME);}
#line 5042 "bison.c"
    break;

  case 195: /* string_function: tTIME '(' ')'  */
#line 428 "yabasic.bison"
                  {create_function(fTIME);}
#line 5048 "bison.c"
    break;

  case 196: /* string_function: tPEEK2 '(' string_expression ')'  */
#line 429 "yabasic.bison"
                                     {create_function(fPEEK2);}
#line 5054 "bison.c"
    break;

  case 197: /* string_function: tPEEK2 '(' string_expression ',' string_expression ')'  */
#line 430 "yabasic.bison"
                                                           {create_function(fPEEK3);}
#line 5060 "bison.c"
    break;

  case 198: /* string_function: tTOKENALT '(' string_scalar_or_array ',' string_expression ')'  */
#line 431 "yabasic.bison"
                                                                   {add_command(cTOKENALT2);}
#line 5066 "bison.c"
    break;

  case 199: /* string_function: tTOKENALT '(' string_scalar_or_array ')'  */
#line 432 "yabasic.bison"
                                             {add_command(cTOKENALT);}
#line 5072 "bison.c"
    break;

  case 200: /* string_function: tSPLITALT '(' string_scalar_or_array ',' string_expression ')'  */
#line 433 "yabasic.bison"
                                                                   {add_command(cSPLITALT2);}
#line 5078 "bison.c"
    break;

  case 201: /* string_function: tSPLITALT '(' string_scalar_or_array ')'  */
#line 434 "yabasic.bison"
                                             {add_command(cSPLITALT);}
#line 5084 "bison.c"
    break;

  case 202: /* string_function: tGETBIT '(' coordinates to coordinates ')'  */
#line 435 "yabasic.bison"
                                               {create_function(fGETBIT);}
#line 5090 "bison.c"
    break;

  case 203: /* string_function: tGETCHAR '(' expression ',' expression to expression ',' expression ')'  */
#line 436 "yabasic.bison"
                                                                            {create_function(fGETCHAR);}
#line 5096 "bison.c"
    break;

  case 204: /* string_function: tHEX '(' expression ')'  */
#line 437 "yabasic.bison"
                            {create_function(fHEX);}
#line 5102 "bison.c"
    break;

  case 205: /* string_function: tBIN '(' expression ')'  */
#line 438 "yabasic.bison"
                            {create_function(fBIN);}
#line 5108 "bison.c"
    break;

  case 206: /* string_function: tEXECUTE2 '(' call_list ')'  */
#line 439 "yabasic.bison"
                                {create_execute(1);add_command(cSWAP);add_command(cPOP);}
#line 5114 "bison.c"
    break;

  case 207: /* string_function: tFRNBF_GET2 '(' string_expression ',' expression ',' expression ')'  */
#line 440 "yabasic.bison"
                                                                        {create_function(fFRNBF_GET_STRING);}
#line 5120 "bison.c"
    break;

  case 208: /* string_function: tFRNBF_GET_BUFFER '(' string_expression ',' expression ')'  */
#line 441 "yabasic.bison"
                                                               {create_function(fFRNBF_GET_BUFFER);}
#line 5126 "bison.c"
    break;

  case 209: /* string_function: tEVAL2 '(' string_expression ')'  */
#line 442 "yabasic.bison"
                                     {create_eval(evSTRING);}
#line 5132 "bison.c"
    break;

  case 210: /* string_function: tBEAM_OPEN_FILE '(' string_expression ')'  */
#line 444 "yabasic.bison"
                                              {create_function(fBEAM_OPEN_FILE);}
#line 5138 "bison.c"
    break;

  case 211: /* string_function: tBEAM_SAVE_FILE '(' string_expression ')'  */
#line 445 "yabasic.bison"
                                              {create_function(fBEAM_SAVE_FILE);}
#line 5144 "bison.c"
    break;

  case 212: /* string_function: tBEAM_NMEA_READ '(' expression ')'  */
#line 447 "yabasic.bison"
                                       {create_function(fBEAM_NMEA_READ);}
#line 5150 "bison.c"
    break;

  case 213: /* string_function: tBEAM_NMEA_FIELD '(' string_expression ',' expression ')'  */
#line 448 "yabasic.bison"
                                                              {create_function(fBEAM_NMEA_FIELD);}
#line 5156 "bison.c"
    break;

  case 214: /* number_assignment: tSYMBOL tEQU expression  */
#line 451 "yabasic.bison"
                                           {add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[-2].symbol),FALSE),NULL);}
#line 5162 "bison.c"
    break;

  case 215: /* number_assignment: function_or_array tEQU expression  */
#line 452 "yabasic.bison"
                                      {create_doarray((yyvsp[-2].symbol),ASSIGNARRAY);}
#line 5168 "bison.c"
    break;

  case 216: /* $@9: %empty  */
#line 455 "yabasic.bison"
                           {add_command(cORSHORT);pushlabel();}
#line 5174 "bison.c"
    break;

  case 217: /* expression: expression tOR $@9 expression  */
#line 455 "yabasic.bison"
                                                                           {poplabel();create_boole('|');}
#line 5180 "bison.c"
    break;

  case 218: /* $@10: %empty  */
#line 456 "yabasic.bison"
                    {add_command(cANDSHORT);pushlabel();}
#line 5186 "bison.c"
    break;

  case 219: /* expression: expression tAND $@10 expression  */
#line 456 "yabasic.bison"
                                                                     {poplabel();create_boole('&');}
#line 5192 "bison.c"
    break;

  case 220: /* expression: tNOT expression  */
#line 457 "yabasic.bison"
                    {create_boole('!');}
#line 5198 "bison.c"
    break;

  case 221: /* expression: expression tEQU expression  */
#line 458 "yabasic.bison"
                               {create_dblrelop('=');}
#line 5204 "bison.c"
    break;

  case 222: /* expression: expression tEQU2 expression  */
#line 459 "yabasic.bison"
                                {create_dblrelop('=');}
#line 5210 "bison.c"
    break;

  case 223: /* expression: expression tNEQ expression  */
#line 460 "yabasic.bison"
                               {create_dblrelop('!');}
#line 5216 "bison.c"
    break;

  case 224: /* expression: expression tLTN expression  */
#line 461 "yabasic.bison"
                               {create_dblrelop('<');}
#line 5222 "bison.c"
    break;

  case 225: /* expression: expression tLEQ expression  */
#line 462 "yabasic.bison"
                               {create_dblrelop('{');}
#line 5228 "bison.c"
    break;

  case 226: /* expression: expression tGTN expression  */
#line 463 "yabasic.bison"
                               {create_dblrelop('>');}
#line 5234 "bison.c"
    break;

  case 227: /* expression: expression tGEQ expression  */
#line 464 "yabasic.bison"
                               {create_dblrelop('}');}
#line 5240 "bison.c"
    break;

  case 228: /* expression: tMYEOF '(' hashed_number ')'  */
#line 465 "yabasic.bison"
                                 {add_command(cTESTEOF);}
#line 5246 "bison.c"
    break;

  case 229: /* expression: tGLOB '(' string_expression ',' string_expression ')'  */
#line 466 "yabasic.bison"
                                                          {add_command(cGLOB);}
#line 5252 "bison.c"
    break;

  case 230: /* expression: number  */
#line 467 "yabasic.bison"
           {create_pushdbl((yyvsp[0].fnum));}
#line 5258 "bison.c"
    break;

  case 231: /* expression: tARDIM '(' arrayref ')'  */
#line 468 "yabasic.bison"
                            {add_command_with_sym_and_diag(cARDIM,"",NULL);}
#line 5264 "bison.c"
    break;

  case 232: /* expression: tARDIM '(' string_arrayref ')'  */
#line 469 "yabasic.bison"
                                   {add_command_with_sym_and_diag(cARDIM,"",NULL);}
#line 5270 "bison.c"
    break;

  case 233: /* expression: tARSIZE '(' arrayref ',' expression ')'  */
#line 470 "yabasic.bison"
                                            {add_command_with_sym_and_diag(cARSIZE,"",NULL);}
#line 5276 "bison.c"
    break;

  case 234: /* expression: tARSIZE '(' string_arrayref ',' expression ')'  */
#line 471 "yabasic.bison"
                                                   {add_command_with_sym_and_diag(cARSIZE,"",NULL);}
#line 5282 "bison.c"
    break;

  case 235: /* expression: function_or_array  */
#line 472 "yabasic.bison"
                      {add_command_with_sym_and_diag(cFUNCTION_OR_ARRAY,(yyvsp[0].symbol),NULL);}
#line 5288 "bison.c"
    break;

  case 236: /* expression: tSYMBOL  */
#line 473 "yabasic.bison"
            {add_command_with_sym_and_diag(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
#line 5294 "bison.c"
    break;

  case 237: /* expression: expression '+' expression  */
#line 474 "yabasic.bison"
                              {create_dblbin('+');}
#line 5300 "bison.c"
    break;

  case 238: /* expression: expression '-' expression  */
#line 475 "yabasic.bison"
                              {create_dblbin('-');}
#line 5306 "bison.c"
    break;

  case 239: /* expression: expression '*' expression  */
#line 476 "yabasic.bison"
                              {create_dblbin('*');}
#line 5312 "bison.c"
    break;

  case 240: /* expression: expression '/' expression  */
#line 477 "yabasic.bison"
                              {create_dblbin('/');}
#line 5318 "bison.c"
    break;

  case 241: /* expression: expression tPOW expression  */
#line 478 "yabasic.bison"
                               {create_dblbin('^');}
#line 5324 "bison.c"
    break;

  case 242: /* expression: '-' expression  */
#line 479 "yabasic.bison"
                                {add_command(cNEGATE);}
#line 5330 "bison.c"
    break;

  case 243: /* expression: string_expression tEQU string_expression  */
#line 480 "yabasic.bison"
                                             {create_strrelop('=');}
#line 5336 "bison.c"
    break;

  case 244: /* expression: string_expression tEQU2 string_expression  */
#line 481 "yabasic.bison"
                                              {create_strrelop('=');}
#line 5342 "bison.c"
    break;

  case 245: /* expression: string_expression tNEQ string_expression  */
#line 482 "yabasic.bison"
                                             {create_strrelop('!');}
#line 5348 "bison.c"
    break;

  case 246: /* expression: string_expression tLTN string_expression  */
#line 483 "yabasic.bison"
                                             {create_strrelop('<');}
#line 5354 "bison.c"
    break;

  case 247: /* expression: string_expression tLEQ string_expression  */
#line 484 "yabasic.bison"
                                             {create_strrelop('{');}
#line 5360 "bison.c"
    break;

  case 248: /* expression: string_expression tGTN string_expression  */
#line 485 "yabasic.bison"
                                             {create_strrelop('>');}
#line 5366 "bison.c"
    break;

  case 249: /* expression: string_expression tGEQ string_expression  */
#line 486 "yabasic.bison"
                                             {create_strrelop('}');}
#line 5372 "bison.c"
    break;

  case 252: /* arrayref: tSYMBOL '(' ')'  */
#line 491 "yabasic.bison"
                          {create_pusharrayref(dotify((yyvsp[-2].symbol),FALSE),stNUMBERARRAYREF);}
#line 5378 "bison.c"
    break;

  case 253: /* string_arrayref: tSTRSYM '(' ')'  */
#line 494 "yabasic.bison"
                                 {create_pusharrayref(dotify((yyvsp[-2].symbol),FALSE),stSTRINGARRAYREF);}
#line 5384 "bison.c"
    break;

  case 255: /* function: tSIN '(' expression ')'  */
#line 500 "yabasic.bison"
                                  {create_function(fSIN);}
#line 5390 "bison.c"
    break;

  case 256: /* function: tASIN '(' expression ')'  */
#line 501 "yabasic.bison"
                             {create_function(fASIN);}
#line 5396 "bison.c"
    break;

  case 257: /* function: tCOS '(' expression ')'  */
#line 502 "yabasic.bison"
                            {create_function(fCOS);}
#line 5402 "bison.c"
    break;

  case 258: /* function: tACOS '(' expression ')'  */
#line 503 "yabasic.bison"
                             {create_function(fACOS);}
#line 5408 "bison.c"
    break;

  case 259: /* function: tTAN '(' expression ')'  */
#line 504 "yabasic.bison"
                            {create_function(fTAN);}
#line 5414 "bison.c"
    break;

  case 260: /* function: tATAN '(' expression ')'  */
#line 505 "yabasic.bison"
                             {create_function(fATAN);}
#line 5420 "bison.c"
    break;

  case 261: /* function: tATAN '(' expression ',' expression ')'  */
#line 506 "yabasic.bison"
                                             {create_function(fATAN2);}
#line 5426 "bison.c"
    break;

  case 262: /* function: tEXP '(' expression ')'  */
#line 507 "yabasic.bison"
                            {create_function(fEXP);}
#line 5432 "bison.c"
    break;

  case 263: /* function: tLOG '(' expression ')'  */
#line 508 "yabasic.bison"
                            {create_function(fLOG);}
#line 5438 "bison.c"
    break;

  case 264: /* function: tLOG '(' expression ',' expression ')'  */
#line 509 "yabasic.bison"
                                           {create_function(fLOG2);}
#line 5444 "bison.c"
    break;

  case 265: /* function: tSQRT '(' expression ')'  */
#line 510 "yabasic.bison"
                             {create_function(fSQRT);}
#line 5450 "bison.c"
    break;

  case 266: /* function: tSQR '(' expression ')'  */
#line 511 "yabasic.bison"
                            {create_function(fSQR);}
#line 5456 "bison.c"
    break;

  case 267: /* function: tINT '(' expression ')'  */
#line 512 "yabasic.bison"
                            {create_function(fINT);}
#line 5462 "bison.c"
    break;

  case 268: /* function: tROUND '(' expression ')'  */
#line 513 "yabasic.bison"
                              {create_function(fROUND);}
#line 5468 "bison.c"
    break;

  case 269: /* function: tCEIL '(' expression ')'  */
#line 514 "yabasic.bison"
                             {create_function(fCEIL);}
#line 5474 "bison.c"
    break;

  case 270: /* function: tFLOOR '(' expression ')'  */
#line 515 "yabasic.bison"
                              {create_function(fFLOOR);}
#line 5480 "bison.c"
    break;

  case 271: /* function: tFRAC '(' expression ')'  */
#line 516 "yabasic.bison"
                             {create_function(fFRAC);}
#line 5486 "bison.c"
    break;

  case 272: /* function: tABS '(' expression ')'  */
#line 517 "yabasic.bison"
                            {create_function(fABS);}
#line 5492 "bison.c"
    break;

  case 273: /* function: tSIG '(' expression ')'  */
#line 518 "yabasic.bison"
                            {create_function(fSIG);}
#line 5498 "bison.c"
    break;

  case 274: /* function: tMOD '(' expression ',' expression ')'  */
#line 519 "yabasic.bison"
                                           {create_function(fMOD);}
#line 5504 "bison.c"
    break;

  case 275: /* function: tRAN '(' expression ')'  */
#line 520 "yabasic.bison"
                            {create_function(fRAN);}
#line 5510 "bison.c"
    break;

  case 276: /* function: tRAN '(' ')'  */
#line 521 "yabasic.bison"
                 {create_function(fRAN2);}
#line 5516 "bison.c"
    break;

  case 277: /* function: tMIN '(' expression ',' expression ')'  */
#line 522 "yabasic.bison"
                                           {create_function(fMIN);}
#line 5522 "bison.c"
    break;

  case 278: /* function: tMAX '(' expression ',' expression ')'  */
#line 523 "yabasic.bison"
                                           {create_function(fMAX);}
#line 5528 "bison.c"
    break;

  case 279: /* function: tLEN '(' string_expression ')'  */
#line 524 "yabasic.bison"
                                   {create_function(fLEN);}
#line 5534 "bison.c"
    break;

  case 280: /* function: tVAL '(' string_expression ')'  */
#line 525 "yabasic.bison"
                                   {create_function(fVAL);}
#line 5540 "bison.c"
    break;

  case 281: /* function: tASC '(' string_expression ')'  */
#line 526 "yabasic.bison"
                                   {create_function(fASC);}
#line 5546 "bison.c"
    break;

  case 282: /* function: tDEC '(' string_expression ')'  */
#line 527 "yabasic.bison"
                                   {create_function(fDEC);}
#line 5552 "bison.c"
    break;

  case 283: /* function: tDEC '(' string_expression ',' expression ')'  */
#line 528 "yabasic.bison"
                                                  {create_function(fDEC2);}
#line 5558 "bison.c"
    break;

  case 284: /* function: tINSTR '(' string_expression ',' string_expression ')'  */
#line 529 "yabasic.bison"
                                                           {if (check_compat) lyyerror(sWARNING,"instr() has changed in version 2.712"); create_function(fINSTR);}
#line 5564 "bison.c"
    break;

  case 285: /* function: tINSTR '(' string_expression ',' string_expression ',' expression ')'  */
#line 530 "yabasic.bison"
                                                                          {create_function(fINSTR2);}
#line 5570 "bison.c"
    break;

  case 286: /* function: tRINSTR '(' string_expression ',' string_expression ')'  */
#line 531 "yabasic.bison"
                                                            {create_function(fRINSTR);}
#line 5576 "bison.c"
    break;

  case 287: /* function: tRINSTR '(' string_expression ',' string_expression ',' expression ')'  */
#line 532 "yabasic.bison"
                                                                            {create_function(fRINSTR2);}
#line 5582 "bison.c"
    break;

  case 288: /* function: tSYSTEM '(' string_expression ')'  */
#line 533 "yabasic.bison"
                                      {create_function(fSYSTEM);}
#line 5588 "bison.c"
    break;

  case 289: /* function: tFRNFN_CALL '(' call_list ')'  */
#line 534 "yabasic.bison"
                                  {create_function(fFRNFN_CALL);}
#line 5594 "bison.c"
    break;

  case 290: /* function: tFRNFN_SIZE '(' string_expression ')'  */
#line 535 "yabasic.bison"
                                          {create_function(fFRNFN_SIZE);}
#line 5600 "bison.c"
    break;

  case 291: /* function: tFRNBF_GET '(' string_expression ',' expression ',' string_expression ')'  */
#line 536 "yabasic.bison"
                                                                              {create_function(fFRNBF_GET_NUMBER);}
#line 5606 "bison.c"
    break;

  case 292: /* function: tFRNBF_SIZE '(' string_expression ')'  */
#line 537 "yabasic.bison"
                                          {create_function(fFRNBF_SIZE);}
#line 5612 "bison.c"
    break;

  case 293: /* function: tPEEK '(' hashed_number ')'  */
#line 538 "yabasic.bison"
                                {create_function(fPEEK4);}
#line 5618 "bison.c"
    break;

  case 294: /* function: tPEEK '(' string_expression ')'  */
#line 539 "yabasic.bison"
                                    {create_function(fPEEK);}
#line 5624 "bison.c"
    break;

  case 295: /* function: tMOUSEX '(' string_expression ')'  */
#line 540 "yabasic.bison"
                                      {create_function(fMOUSEX);}
#line 5630 "bison.c"
    break;

  case 296: /* function: tMOUSEX  */
#line 541 "yabasic.bison"
            {create_pushstr("");create_function(fMOUSEX);}
#line 5636 "bison.c"
    break;

  case 297: /* function: tMOUSEX '(' ')'  */
#line 542 "yabasic.bison"
                    {create_pushstr("");create_function(fMOUSEX);}
#line 5642 "bison.c"
    break;

  case 298: /* function: tMOUSEY '(' string_expression ')'  */
#line 543 "yabasic.bison"
                                      {create_function(fMOUSEY);}
#line 5648 "bison.c"
    break;

  case 299: /* function: tMOUSEY  */
#line 544 "yabasic.bison"
            {create_pushstr("");create_function(fMOUSEY);}
#line 5654 "bison.c"
    break;

  case 300: /* function: tMOUSEY '(' ')'  */
#line 545 "yabasic.bison"
                    {create_pushstr("");create_function(fMOUSEY);}
#line 5660 "bison.c"
    break;

  case 301: /* function: tMOUSEB '(' string_expression ')'  */
#line 546 "yabasic.bison"
                                      {create_function(fMOUSEB);}
#line 5666 "bison.c"
    break;

  case 302: /* function: tMOUSEB  */
#line 547 "yabasic.bison"
            {create_pushstr("");create_function(fMOUSEB);}
#line 5672 "bison.c"
    break;

  case 303: /* function: tMOUSEB '(' ')'  */
#line 548 "yabasic.bison"
                    {create_pushstr("");create_function(fMOUSEB);}
#line 5678 "bison.c"
    break;

  case 304: /* function: tMOUSEMOD '(' string_expression ')'  */
#line 549 "yabasic.bison"
                                        {create_function(fMOUSEMOD);}
#line 5684 "bison.c"
    break;

  case 305: /* function: tMOUSEMOD  */
#line 550 "yabasic.bison"
              {create_pushstr("");create_function(fMOUSEMOD);}
#line 5690 "bison.c"
    break;

  case 306: /* function: tMOUSEMOD '(' ')'  */
#line 551 "yabasic.bison"
                      {create_pushstr("");create_function(fMOUSEMOD);}
#line 5696 "bison.c"
    break;

  case 307: /* function: tAND '(' expression ',' expression ')'  */
#line 552 "yabasic.bison"
                                           {create_function(fAND);}
#line 5702 "bison.c"
    break;

  case 308: /* function: tOR '(' expression ',' expression ')'  */
#line 553 "yabasic.bison"
                                          {create_function(fOR);}
#line 5708 "bison.c"
    break;

  case 309: /* function: tBITNOT '(' expression ')'  */
#line 554 "yabasic.bison"
                               {create_function(fBITNOT);}
#line 5714 "bison.c"
    break;

  case 310: /* function: tEOR '(' expression ',' expression ')'  */
#line 555 "yabasic.bison"
                                           {create_function(fEOR);}
#line 5720 "bison.c"
    break;

  case 311: /* function: tSHL '(' expression ',' expression ')'  */
#line 556 "yabasic.bison"
                                           {create_function(fSHL);}
#line 5726 "bison.c"
    break;

  case 312: /* function: tSHR '(' expression ',' expression ')'  */
#line 557 "yabasic.bison"
                                           {create_function(fSHR);}
#line 5732 "bison.c"
    break;

  case 313: /* function: tTELL '(' hashed_number ')'  */
#line 558 "yabasic.bison"
                                {create_function(fTELL);}
#line 5738 "bison.c"
    break;

  case 314: /* function: tTOKEN '(' string_expression ',' string_arrayref ',' string_expression ')'  */
#line 559 "yabasic.bison"
                                                                               {add_command(cTOKEN2);}
#line 5744 "bison.c"
    break;

  case 315: /* function: tTOKEN '(' string_expression ',' string_arrayref ')'  */
#line 560 "yabasic.bison"
                                                         {add_command(cTOKEN);}
#line 5750 "bison.c"
    break;

  case 316: /* function: tSPLIT '(' string_expression ',' string_arrayref ',' string_expression ')'  */
#line 561 "yabasic.bison"
                                                                               {add_command(cSPLIT2);}
#line 5756 "bison.c"
    break;

  case 317: /* function: tSPLIT '(' string_expression ',' string_arrayref ')'  */
#line 562 "yabasic.bison"
                                                         {add_command(cSPLIT);}
#line 5762 "bison.c"
    break;

  case 318: /* function: tEXECUTE '(' call_list ')'  */
#line 563 "yabasic.bison"
                               {create_execute(0);add_command(cSWAP);add_command(cPOP);}
#line 5768 "bison.c"
    break;

  case 319: /* function: tOPEN '(' tPRINTER ')'  */
#line 564 "yabasic.bison"
                           {create_myopen(OPEN_PRINTER);}
#line 5774 "bison.c"
    break;

  case 320: /* function: tOPEN '(' string_expression ')'  */
#line 565 "yabasic.bison"
                                    {create_myopen(0);}
#line 5780 "bison.c"
    break;

  case 321: /* function: tOPEN '(' string_expression ',' string_expression ')'  */
#line 566 "yabasic.bison"
                                                          {create_myopen(OPEN_HAS_MODE);}
#line 5786 "bison.c"
    break;

  case 322: /* function: tOPEN '(' hashed_number ',' tPRINTER ')'  */
#line 567 "yabasic.bison"
                                             {create_myopen(OPEN_PRINTER+OPEN_HAS_STREAM);}
#line 5792 "bison.c"
    break;

  case 323: /* function: tOPEN '(' hashed_number ',' string_expression ')'  */
#line 568 "yabasic.bison"
                                                      {create_myopen(OPEN_HAS_STREAM);}
#line 5798 "bison.c"
    break;

  case 324: /* function: tOPEN '(' hashed_number ',' string_expression ',' string_expression ')'  */
#line 569 "yabasic.bison"
                                                                            {create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}
#line 5804 "bison.c"
    break;

  case 325: /* function: tEVAL '(' string_expression ')'  */
#line 570 "yabasic.bison"
                                    {create_eval(evNUMBER);}
#line 5810 "bison.c"
    break;

  case 326: /* function: tBEAM_OPEN '(' expression ',' expression ',' string_expression ')'  */
#line 572 "yabasic.bison"
                                                                       {create_function(fBEAM_OPEN);}
#line 5816 "bison.c"
    break;

  case 327: /* function: tBEAM_RUNNING '(' expression ')'  */
#line 573 "yabasic.bison"
                                     {create_function(fBEAM_RUNNING);}
#line 5822 "bison.c"
    break;

  case 328: /* function: tBEAM_BUTTON '(' string_expression ',' expression ',' expression ')'  */
#line 574 "yabasic.bison"
                                                                         {create_function(fBEAM_BUTTON);}
#line 5828 "bison.c"
    break;

  case 329: /* function: tBEAM_INPUT '(' string_expression ',' expression ',' expression ')'  */
#line 575 "yabasic.bison"
                                                                        {create_function(fBEAM_INPUT);}
#line 5834 "bison.c"
    break;

  case 330: /* function: tBEAM_CHECKBOX '(' string_expression ',' expression ')'  */
#line 576 "yabasic.bison"
                                                            {create_function(fBEAM_CHECKBOX);}
#line 5840 "bison.c"
    break;

  case 331: /* function: tBEAM_COMBO '(' string_expression ',' expression ',' expression ',' expression ',' expression ')'  */
#line 577 "yabasic.bison"
                                                                                                      {create_function(fBEAM_COMBO);}
#line 5846 "bison.c"
    break;

  case 332: /* function: tBEAM_SLIDER '(' expression ',' expression ',' expression ',' expression ',' expression ')'  */
#line 578 "yabasic.bison"
                                                                                                {create_function(fBEAM_SLIDER);}
#line 5852 "bison.c"
    break;

  case 333: /* function: tBEAM_TIME '(' ')'  */
#line 579 "yabasic.bison"
                       {create_function(fBEAM_TIME);}
#line 5858 "bison.c"
    break;

  case 334: /* function: tBEAM_MSGBOX '(' string_expression ',' string_expression ')'  */
#line 580 "yabasic.bison"
                                                                 {create_function(fBEAM_MSGBOX);}
#line 5864 "bison.c"
    break;

  case 335: /* function: tBEAM_CONFIRM '(' string_expression ',' string_expression ')'  */
#line 581 "yabasic.bison"
                                                                  {create_function(fBEAM_CONFIRM);}
#line 5870 "bison.c"
    break;

  case 336: /* function: tBEAM_NMEA_OPEN '(' string_expression ',' expression ')'  */
#line 583 "yabasic.bison"
                                                             {create_function(fBEAM_NMEA_OPEN);}
#line 5876 "bison.c"
    break;

  case 337: /* const: number  */
#line 586 "yabasic.bison"
              {(yyval.fnum)=(yyvsp[0].fnum);}
#line 5882 "bison.c"
    break;

  case 338: /* const: '+' number  */
#line 587 "yabasic.bison"
               {(yyval.fnum)=(yyvsp[0].fnum);}
#line 5888 "bison.c"
    break;

  case 339: /* const: '-' number  */
#line 588 "yabasic.bison"
               {(yyval.fnum)=-(yyvsp[0].fnum);}
#line 5894 "bison.c"
    break;

  case 340: /* number: tFNUM  */
#line 591 "yabasic.bison"
              {(yyval.fnum)=(yyvsp[0].fnum);}
#line 5900 "bison.c"
    break;

  case 341: /* number: tDIGITS  */
#line 592 "yabasic.bison"
            {(yyval.fnum)=strtod((yyvsp[0].digits),NULL);}
#line 5906 "bison.c"
    break;

  case 342: /* number: tHEXDIGITS  */
#line 593 "yabasic.bison"
               {(yyval.fnum)=(double)strtoul((yyvsp[0].digits),NULL,16);}
#line 5912 "bison.c"
    break;

  case 343: /* number: tBINDIGITS  */
#line 594 "yabasic.bison"
               {(yyval.fnum)=(double)strtoul((yyvsp[0].digits),NULL,2);}
#line 5918 "bison.c"
    break;

  case 344: /* symbol_or_lineno: tDIGITS  */
#line 597 "yabasic.bison"
                          {(yyval.symbol)=my_strdup(dotify((yyvsp[0].digits),FALSE));}
#line 5924 "bison.c"
    break;

  case 345: /* symbol_or_lineno: tSYMBOL  */
#line 598 "yabasic.bison"
            {(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}
#line 5930 "bison.c"
    break;

  case 346: /* dimlist: tSYMBOL '(' call_list ')'  */
#line 601 "yabasic.bison"
                                   {create_dim(dotify((yyvsp[-3].symbol),FALSE),'D');}
#line 5936 "bison.c"
    break;

  case 347: /* dimlist: dimlist ',' tSYMBOL '(' call_list ')'  */
#line 602 "yabasic.bison"
                                          {create_dim(dotify((yyvsp[-3].symbol),FALSE),'D');}
#line 5942 "bison.c"
    break;

  case 348: /* dimlist: tSTRSYM '(' call_list ')'  */
#line 603 "yabasic.bison"
                              {create_dim(dotify((yyvsp[-3].symbol),FALSE),'S');}
#line 5948 "bison.c"
    break;

  case 349: /* dimlist: dimlist ',' tSTRSYM '(' call_list ')'  */
#line 604 "yabasic.bison"
                                          {create_dim(dotify((yyvsp[-3].symbol),FALSE),'S');}
#line 5954 "bison.c"
    break;

  case 350: /* function_or_array: tSYMBOL '(' call_list ')'  */
#line 607 "yabasic.bison"
                                             {(yyval.symbol)=my_strdup(dotify((yyvsp[-3].symbol),FALSE));}
#line 5960 "bison.c"
    break;

  case 351: /* stringfunction_or_array: tSTRSYM '(' call_list ')'  */
#line 610 "yabasic.bison"
                                                   {(yyval.symbol)=my_strdup(dotify((yyvsp[-3].symbol),FALSE));}
#line 5966 "bison.c"
    break;

  case 352: /* $@11: %empty  */
#line 613 "yabasic.bison"
           {add_command(cPUSHFREE);}
#line 5972 "bison.c"
    break;

  case 359: /* $@12: %empty  */
#line 625 "yabasic.bison"
                                 {missing_endsub++;missing_endsub_line=yylineno;pushlabel();report_if_missing("can not define a function in a loop or an if-statement",FALSE);if (function_type!=ftNONE) {lyyerror(sERROR,"nested functions not allowed");YYABORT;}}
#line 5978 "bison.c"
    break;

  case 360: /* $@13: %empty  */
#line 626 "yabasic.bison"
                      {if (exported) create_subr_link((yyvsp[0].symbol)); create_label((yyvsp[0].symbol),cUSER_FUNCTION);
	               add_command(cPUSHSYMLIST);add_command(cCLEARSYMREFS);start_symref_chain();
		       create_count_params();}
#line 5986 "bison.c"
    break;

  case 361: /* $@14: %empty  */
#line 629 "yabasic.bison"
                          {create_require(stFREE);add_command(cPOP);}
#line 5992 "bison.c"
    break;

  case 362: /* function_definition: export tSUB $@12 function_name $@13 '(' paramlist ')' $@14 statement_list endsub  */
#line 631 "yabasic.bison"
               {add_command(cCLEARSYMREFS);end_symref_chain();add_command(cPOPSYMLIST);create_check_return_value(ftNONE,function_type);function_type=ftNONE;add_command(cRETURN_FROM_CALL);create_endfunction();poplabel();}
#line 5998 "bison.c"
    break;

  case 363: /* endsub: tEOPROG  */
#line 634 "yabasic.bison"
                {if (missing_endsub) {sprintf(string,"subroutine starting at line %d has seen no 'end sub' at end of program",missing_endsub_line);error_without_position(sERROR,string);} YYABORT;}
#line 6004 "bison.c"
    break;

  case 364: /* endsub: tENDSUB  */
#line 635 "yabasic.bison"
            {missing_endsub--;}
#line 6010 "bison.c"
    break;

  case 365: /* function_name: tSYMBOL  */
#line 638 "yabasic.bison"
                       {function_type=ftNUMBER;current_function=my_strdup(dotify((yyvsp[0].symbol),FALSE));(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}
#line 6016 "bison.c"
    break;

  case 366: /* function_name: tSTRSYM  */
#line 639 "yabasic.bison"
            {function_type=ftSTRING;current_function=my_strdup(dotify((yyvsp[0].symbol),FALSE));(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}
#line 6022 "bison.c"
    break;

  case 367: /* export: %empty  */
#line 642 "yabasic.bison"
                    {exported=FALSE;}
#line 6028 "bison.c"
    break;

  case 368: /* export: tEXPORT  */
#line 643 "yabasic.bison"
            {exported=TRUE;}
#line 6034 "bison.c"
    break;

  case 369: /* export: tRUNTIME_CREATED_SUB  */
#line 644 "yabasic.bison"
                         {exported=FALSE;}
#line 6040 "bison.c"
    break;

  case 370: /* export: tRUNTIME_CREATED_SUB tEXPORT  */
#line 645 "yabasic.bison"
                                 {exported=TRUE;}
#line 6046 "bison.c"
    break;

  case 373: /* local_item: tSYMBOL  */
#line 652 "yabasic.bison"
                    {create_makelocal(dotify((yyvsp[0].symbol),FALSE),syNUMBER);}
#line 6052 "bison.c"
    break;

  case 374: /* local_item: tSTRSYM  */
#line 653 "yabasic.bison"
            {create_makelocal(dotify((yyvsp[0].symbol),FALSE),sySTRING);}
#line 6058 "bison.c"
    break;

  case 375: /* local_item: tSYMBOL '(' call_list ')'  */
#line 654 "yabasic.bison"
                              {create_makelocal(dotify((yyvsp[-3].symbol),FALSE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),FALSE),'d');}
#line 6064 "bison.c"
    break;

  case 376: /* local_item: tSTRSYM '(' call_list ')'  */
#line 655 "yabasic.bison"
                              {create_makelocal(dotify((yyvsp[-3].symbol),FALSE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),FALSE),'s');}
#line 6070 "bison.c"
    break;

  case 379: /* static_item: tSYMBOL  */
#line 662 "yabasic.bison"
                     {create_makestatic(dotify((yyvsp[0].symbol),TRUE),syNUMBER);}
#line 6076 "bison.c"
    break;

  case 380: /* static_item: tSTRSYM  */
#line 663 "yabasic.bison"
            {create_makestatic(dotify((yyvsp[0].symbol),TRUE),sySTRING);}
#line 6082 "bison.c"
    break;

  case 381: /* static_item: tSYMBOL '(' call_list ')'  */
#line 664 "yabasic.bison"
                              {create_makestatic(dotify((yyvsp[-3].symbol),TRUE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),TRUE),'D');}
#line 6088 "bison.c"
    break;

  case 382: /* static_item: tSTRSYM '(' call_list ')'  */
#line 665 "yabasic.bison"
                              {create_makestatic(dotify((yyvsp[-3].symbol),TRUE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),TRUE),'S');}
#line 6094 "bison.c"
    break;

  case 386: /* paramitem: tSYMBOL  */
#line 673 "yabasic.bison"
                   {create_require(stNUMBER);create_makelocal(dotify((yyvsp[0].symbol),FALSE),syNUMBER);add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
#line 6100 "bison.c"
    break;

  case 387: /* paramitem: tSTRSYM  */
#line 674 "yabasic.bison"
            {create_require(stSTRING);create_makelocal(dotify((yyvsp[0].symbol),FALSE),sySTRING);add_command_with_sym_and_diag(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
#line 6106 "bison.c"
    break;

  case 388: /* paramitem: tSYMBOL '(' ')'  */
#line 675 "yabasic.bison"
                    {create_require(stNUMBERARRAYREF);create_arraylink(dotify((yyvsp[-2].symbol),FALSE),stNUMBERARRAYREF);}
#line 6112 "bison.c"
    break;

  case 389: /* paramitem: tSTRSYM '(' ')'  */
#line 676 "yabasic.bison"
                    {create_require(stSTRINGARRAYREF);create_arraylink(dotify((yyvsp[-2].symbol),FALSE),stSTRINGARRAYREF);}
#line 6118 "bison.c"
    break;

  case 390: /* $@15: %empty  */
#line 679 "yabasic.bison"
               {loop_nesting++;add_command(cBEGIN_LOOP_MARK);missing_next++;missing_next_line=yylineno;}
#line 6124 "bison.c"
    break;

  case 391: /* $@16: %empty  */
#line 680 "yabasic.bison"
            {pushname(dotify((yyvsp[-1].symbol),FALSE)); /* will be used by next_symbol to check equality,NULL */
	     add_command(cRESETSKIPONCE);
	     add_command(cRESETSKIPONCE2);
	     pushgoto();add_command_with_switch_state(cCONTINUE_HERE);}
#line 6133 "bison.c"
    break;

  case 392: /* $@17: %empty  */
#line 685 "yabasic.bison"
                    { /* pushes another expression */
	     add_command(cSKIPONCE);
	     pushlabel();
	     add_command(cSTARTFOR);
	     add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[-6].symbol),FALSE),NULL);
	     poplabel();

	     add_command_with_sym_and_diag(cPUSHDBLSYM,dotify((yyvsp[-6].symbol),FALSE),NULL);
	     add_command(cSKIPONCE);
	     add_command(cFORINCREMENT);
	     add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[-6].symbol),FALSE),NULL);
	     add_command_with_sym_and_diag(cPUSHDBLSYM,dotify((yyvsp[-6].symbol),FALSE),NULL);
	     add_command(cFORCHECK);
	     add_command(cDECIDE);
             pushlabel();}
#line 6153 "bison.c"
    break;

  case 393: /* $@18: %empty  */
#line 700 "yabasic.bison"
                         {
             swap();popgoto();poplabel();}
#line 6160 "bison.c"
    break;

  case 394: /* for_loop: tFOR $@15 tSYMBOL tEQU $@16 expression tTO expression step_part $@17 statement_list $@18 next next_symbol  */
#line 702 "yabasic.bison"
                           {add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}
#line 6166 "bison.c"
    break;

  case 395: /* next: tEOPROG  */
#line 705 "yabasic.bison"
              {if (missing_next) {sprintf(string,"for-loop starting at line %d has seen no 'next' at end of program",missing_next_line);error_without_position(sERROR,string);} YYABORT;}
#line 6172 "bison.c"
    break;

  case 396: /* next: tNEXT  */
#line 706 "yabasic.bison"
          {missing_next--;}
#line 6178 "bison.c"
    break;

  case 397: /* next: tENDIF  */
#line 707 "yabasic.bison"
           {report_conflicting_close("a closing next is expected before endif",'e');}
#line 6184 "bison.c"
    break;

  case 398: /* next: tWEND  */
#line 708 "yabasic.bison"
          {report_conflicting_close("a closing next is expected before wend",'w');}
#line 6190 "bison.c"
    break;

  case 399: /* next: tUNTIL  */
#line 709 "yabasic.bison"
           {report_conflicting_close("a closing next is expected before until",'l');}
#line 6196 "bison.c"
    break;

  case 400: /* next: tLOOP  */
#line 710 "yabasic.bison"
          {report_conflicting_close("a closing next is expected before loop",'l');}
#line 6202 "bison.c"
    break;

  case 401: /* step_part: %empty  */
#line 713 "yabasic.bison"
           {create_pushdbl(1);}
#line 6208 "bison.c"
    break;

  case 403: /* next_symbol: %empty  */
#line 717 "yabasic.bison"
              {pop(stSTRING);}
#line 6214 "bison.c"
    break;

  case 404: /* next_symbol: tSYMBOL  */
#line 718 "yabasic.bison"
            {if (strcmp(pop(stSTRING)->pointer,dotify((yyvsp[0].symbol),FALSE))) 
             {lyyerror(sERROR,"'for' and 'next' do not match"); YYABORT;}
           }
#line 6222 "bison.c"
    break;

  case 405: /* $@19: %empty  */
#line 723 "yabasic.bison"
                                 {push_switch_id();add_command(cBEGIN_SWITCH_MARK);}
#line 6228 "bison.c"
    break;

  case 406: /* switch_number_or_string: tSWITCH $@19 number_or_string sep_list case_list default tSEND  */
#line 724 "yabasic.bison"
                                                                  {add_command(cBREAK_HERE);add_command(cPOP);add_command(cEND_SWITCH_MARK);pop_switch_id();}
#line 6234 "bison.c"
    break;

  case 412: /* $@20: %empty  */
#line 738 "yabasic.bison"
      {add_command(cSWITCH_COMPARE);add_command(cDECIDE);add_command(cNEXT_CASE);}
#line 6240 "bison.c"
    break;

  case 413: /* case_list: case_list tCASE number_or_string $@20 statement_list  */
#line 738 "yabasic.bison"
                                                                                                  {add_command(cNEXT_CASE_HERE);}
#line 6246 "bison.c"
    break;

  case 415: /* $@21: %empty  */
#line 743 "yabasic.bison"
                  {add_command(cNEXT_CASE_HERE);}
#line 6252 "bison.c"
    break;

  case 417: /* $@22: %empty  */
#line 747 "yabasic.bison"
             {loop_nesting++;add_command(cBEGIN_LOOP_MARK);add_command_with_switch_state(cCONTINUE_HERE);missing_loop++;missing_loop_line=yylineno;pushgoto();}
#line 6258 "bison.c"
    break;

  case 419: /* loop: tEOPROG  */
#line 753 "yabasic.bison"
              {if (missing_loop) {sprintf(string,"do-loop starting at at line %d has seen no 'loop' at end of program",missing_loop_line);error_without_position(sERROR,string);} YYABORT;}
#line 6264 "bison.c"
    break;

  case 420: /* loop: tLOOP  */
#line 754 "yabasic.bison"
          {missing_loop--;popgoto();add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}
#line 6270 "bison.c"
    break;

  case 421: /* loop: tENDIF  */
#line 755 "yabasic.bison"
           {report_conflicting_close("a closing loop is expected before endif",'e');}
#line 6276 "bison.c"
    break;

  case 422: /* loop: tWEND  */
#line 756 "yabasic.bison"
          {report_conflicting_close("a closing loop is expected before wend",'w');}
#line 6282 "bison.c"
    break;

  case 423: /* loop: tUNTIL  */
#line 757 "yabasic.bison"
           {report_conflicting_close("a closing loop is expected before until",'l');}
#line 6288 "bison.c"
    break;

  case 424: /* loop: tNEXT  */
#line 758 "yabasic.bison"
          {report_conflicting_close("a closing loop is expected before next",'n');}
#line 6294 "bison.c"
    break;

  case 425: /* $@23: %empty  */
#line 762 "yabasic.bison"
                   {loop_nesting++;add_command(cBEGIN_LOOP_MARK);add_command_with_switch_state(cCONTINUE_HERE);missing_wend++;missing_wend_line=yylineno;pushgoto();}
#line 6300 "bison.c"
    break;

  case 426: /* $@24: %empty  */
#line 763 "yabasic.bison"
              {add_command(cDECIDE);
	      pushlabel();}
#line 6307 "bison.c"
    break;

  case 428: /* wend: tEOPROG  */
#line 769 "yabasic.bison"
              {if (missing_wend) {sprintf(string,"while-loop starting at line %d has seen no 'wend' at end of program",missing_wend_line);error_without_position(sERROR,string);} YYABORT;}
#line 6313 "bison.c"
    break;

  case 429: /* wend: tWEND  */
#line 770 "yabasic.bison"
          {missing_wend--;swap();popgoto();poplabel();add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}
#line 6319 "bison.c"
    break;

  case 430: /* $@25: %empty  */
#line 774 "yabasic.bison"
                     {loop_nesting++;add_command(cBEGIN_LOOP_MARK);add_command_with_switch_state(cCONTINUE_HERE);missing_until++;missing_until_line=yylineno;pushgoto();}
#line 6325 "bison.c"
    break;

  case 432: /* until: tEOPROG  */
#line 779 "yabasic.bison"
               {if (missing_until) {sprintf(string,"repeat-loop starting at line %d has seen no 'until' at end of program",missing_until_line);error_without_position(sERROR,string);} YYABORT;}
#line 6331 "bison.c"
    break;

  case 433: /* until: tUNTIL expression  */
#line 780 "yabasic.bison"
                      {missing_until--;add_command(cDECIDE);popgoto();add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}
#line 6337 "bison.c"
    break;

  case 434: /* until: tENDIF  */
#line 781 "yabasic.bison"
           {report_conflicting_close("a closing until is expected before endif",'e');}
#line 6343 "bison.c"
    break;

  case 435: /* until: tWEND  */
#line 782 "yabasic.bison"
          {report_conflicting_close("a closing until is expected before wend",'w');}
#line 6349 "bison.c"
    break;

  case 436: /* until: tLOOP  */
#line 783 "yabasic.bison"
          {report_conflicting_close("a closing until is expected before loop",'l');}
#line 6355 "bison.c"
    break;

  case 437: /* until: tNEXT  */
#line 784 "yabasic.bison"
          {report_conflicting_close("a closing until is expected before next",'n');}
#line 6361 "bison.c"
    break;

  case 438: /* $@26: %empty  */
#line 787 "yabasic.bison"
                          {add_command(cDECIDE);storelabel();pushlabel();}
#line 6367 "bison.c"
    break;

  case 439: /* $@27: %empty  */
#line 788 "yabasic.bison"
                 {missing_endif++;missing_endif_line=yylineno;}
#line 6373 "bison.c"
    break;

  case 440: /* $@28: %empty  */
#line 788 "yabasic.bison"
                                                                               {swap();matchgoto();swap();poplabel();}
#line 6379 "bison.c"
    break;

  case 441: /* $@29: %empty  */
#line 790 "yabasic.bison"
                     {poplabel();}
#line 6385 "bison.c"
    break;

  case 443: /* endif: tEOPROG  */
#line 794 "yabasic.bison"
               {if (missing_endif) {sprintf(string,"if-clause starting at line %d has seen no 'fi' at end of program",missing_endif_line);error_without_position(sERROR,string);} YYABORT;}
#line 6391 "bison.c"
    break;

  case 444: /* endif: tENDIF  */
#line 795 "yabasic.bison"
           {missing_endif--;}
#line 6397 "bison.c"
    break;

  case 445: /* endif: tWEND  */
#line 796 "yabasic.bison"
          {report_conflicting_close("a closing endif is expected before wend",'w');}
#line 6403 "bison.c"
    break;

  case 446: /* endif: tUNTIL  */
#line 797 "yabasic.bison"
           {report_conflicting_close("a closing endif is expected before until",'l');}
#line 6409 "bison.c"
    break;

  case 447: /* endif: tLOOP  */
#line 798 "yabasic.bison"
          {report_conflicting_close("a closing endif is expected before loop",'l');}
#line 6415 "bison.c"
    break;

  case 448: /* endif: tNEXT  */
#line 799 "yabasic.bison"
          {report_conflicting_close("a closing endif is expected before next",'n');}
#line 6421 "bison.c"
    break;

  case 449: /* $@30: %empty  */
#line 802 "yabasic.bison"
                         {in_short_if++;add_command(cDECIDE);pushlabel();}
#line 6427 "bison.c"
    break;

  case 451: /* end_of_if: tENDIF  */
#line 807 "yabasic.bison"
                  {error(sERROR,"short if-statement (i.e. without 'then') does not allow 'endif'");}
#line 6433 "bison.c"
    break;

  case 452: /* end_of_if: tIMPLICITENDIF  */
#line 808 "yabasic.bison"
                   {poplabel();}
#line 6439 "bison.c"
    break;

  case 456: /* $@31: %empty  */
#line 817 "yabasic.bison"
        {add_command(cDECIDE);pushlabel();}
#line 6445 "bison.c"
    break;

  case 457: /* $@32: %empty  */
#line 819 "yabasic.bison"
        {swap();matchgoto();swap();poplabel();}
#line 6451 "bison.c"
    break;

  case 462: /* $@33: %empty  */
#line 828 "yabasic.bison"
              {add_command(cCHKPROMPT);}
#line 6457 "bison.c"
    break;

  case 464: /* input: tSYMBOL  */
#line 831 "yabasic.bison"
               {create_myread('d',tileol);add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
#line 6463 "bison.c"
    break;

  case 465: /* input: tSYMBOL '(' call_list ')'  */
#line 833 "yabasic.bison"
        {create_myread('d',tileol);create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNARRAY);}
#line 6469 "bison.c"
    break;

  case 466: /* input: tSTRSYM  */
#line 834 "yabasic.bison"
            {create_myread('s',tileol);add_command_with_sym_and_diag(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
#line 6475 "bison.c"
    break;

  case 467: /* input: tSTRSYM '(' call_list ')'  */
#line 836 "yabasic.bison"
        {create_myread('s',tileol);create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNSTRINGARRAY);}
#line 6481 "bison.c"
    break;

  case 470: /* readitem: tSYMBOL  */
#line 843 "yabasic.bison"
                  {create_readdata('d');add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
#line 6487 "bison.c"
    break;

  case 471: /* readitem: tSYMBOL '(' call_list ')'  */
#line 845 "yabasic.bison"
    {create_readdata('d');create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNARRAY);}
#line 6493 "bison.c"
    break;

  case 472: /* readitem: tSTRSYM  */
#line 846 "yabasic.bison"
            {create_readdata('s');add_command_with_sym_and_diag(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
#line 6499 "bison.c"
    break;

  case 473: /* readitem: tSTRSYM '(' call_list ')'  */
#line 848 "yabasic.bison"
    {create_readdata('s');create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNSTRINGARRAY);}
#line 6505 "bison.c"
    break;

  case 474: /* datalist: tSTRING  */
#line 851 "yabasic.bison"
                  {create_strdata((yyvsp[0].string));}
#line 6511 "bison.c"
    break;

  case 475: /* datalist: const  */
#line 852 "yabasic.bison"
          {create_dbldata((yyvsp[0].fnum));}
#line 6517 "bison.c"
    break;

  case 476: /* datalist: datalist ',' tSTRING  */
#line 853 "yabasic.bison"
                          {create_strdata((yyvsp[0].string));}
#line 6523 "bison.c"
    break;

  case 477: /* datalist: datalist ',' const  */
#line 854 "yabasic.bison"
                       {create_dbldata((yyvsp[0].fnum));}
#line 6529 "bison.c"
    break;

  case 481: /* printlist: string_expression  */
#line 860 "yabasic.bison"
                      {create_print('s');}
#line 6535 "bison.c"
    break;

  case 482: /* printlist: printlist ',' string_expression  */
#line 861 "yabasic.bison"
                                    {create_print('s');}
#line 6541 "bison.c"
    break;

  case 483: /* using: %empty  */
#line 864 "yabasic.bison"
       {create_print('d');}
#line 6547 "bison.c"
    break;

  case 484: /* using: tUSING string_expression  */
#line 865 "yabasic.bison"
                             {create_print('u');}
#line 6553 "bison.c"
    break;

  case 485: /* using: tUSING '(' string_expression ',' string_expression ')'  */
#line 866 "yabasic.bison"
                                                           {create_print('U');}
#line 6559 "bison.c"
    break;

  case 486: /* $@34: %empty  */
#line 869 "yabasic.bison"
                       {add_command_with_sym_and_diag(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);create_pps(cPUSHSTREAM,1);}
#line 6565 "bison.c"
    break;

  case 487: /* inputbody: '#' tSYMBOL $@34 inputlist  */
#line 869 "yabasic.bison"
                                                                                                                               {create_pps(cPOPSTREAM,0);}
#line 6571 "bison.c"
    break;

  case 488: /* $@35: %empty  */
#line 870 "yabasic.bison"
                {create_pushdbl(atoi((yyvsp[0].digits)));create_pps(cPUSHSTREAM,1);}
#line 6577 "bison.c"
    break;

  case 489: /* inputbody: '#' tDIGITS $@35 inputlist  */
#line 870 "yabasic.bison"
                                                                                {create_pps(cPOPSTREAM,0);}
#line 6583 "bison.c"
    break;

  case 490: /* $@36: %empty  */
#line 871 "yabasic.bison"
                           {create_pps(cPUSHSTREAM,1);}
#line 6589 "bison.c"
    break;

  case 491: /* inputbody: '#' '(' expression ')' $@36 inputlist  */
#line 871 "yabasic.bison"
                                                                  {create_pps(cPOPSTREAM,0);}
#line 6595 "bison.c"
    break;

  case 492: /* $@37: %empty  */
#line 872 "yabasic.bison"
                                          {add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
#line 6601 "bison.c"
    break;

  case 493: /* inputbody: tAT '(' expression ',' expression ')' $@37 prompt inputlist  */
#line 872 "yabasic.bison"
                                                                                                                                        {create_pps(cPOPSTREAM,0);}
#line 6607 "bison.c"
    break;

  case 494: /* $@38: %empty  */
#line 873 "yabasic.bison"
    {create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
#line 6613 "bison.c"
    break;

  case 495: /* inputbody: $@38 prompt inputlist  */
#line 873 "yabasic.bison"
                                                                               {create_pps(cPOPSTREAM,0);}
#line 6619 "bison.c"
    break;

  case 496: /* prompt: %empty  */
#line 876 "yabasic.bison"
                    {create_pushstr("?");create_print('s');}
#line 6625 "bison.c"
    break;

  case 497: /* prompt: tSTRING  */
#line 877 "yabasic.bison"
            {create_pushstr((yyvsp[0].string));create_print('s');}
#line 6631 "bison.c"
    break;

  case 498: /* printintro: %empty  */
#line 880 "yabasic.bison"
                               {create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
#line 6637 "bison.c"
    break;

  case 499: /* printintro: '#' tSYMBOL  */
#line 881 "yabasic.bison"
                {add_command_with_sym_and_diag(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);create_pps(cPUSHSTREAM,0);}
#line 6643 "bison.c"
    break;

  case 500: /* printintro: '#' tDIGITS  */
#line 882 "yabasic.bison"
                {create_pushdbl(atoi((yyvsp[0].digits)));create_pps(cPUSHSTREAM,0);}
#line 6649 "bison.c"
    break;

  case 501: /* printintro: '#' '(' expression ')'  */
#line 883 "yabasic.bison"
                           {create_pps(cPUSHSTREAM,0);}
#line 6655 "bison.c"
    break;

  case 502: /* printintro: tREVERSE  */
#line 884 "yabasic.bison"
             {create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
#line 6661 "bison.c"
    break;

  case 503: /* printintro: tCOLOUR '(' string_expression ')'  */
#line 885 "yabasic.bison"
                                      {create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
#line 6667 "bison.c"
    break;

  case 504: /* printintro: tCOLOUR '(' string_expression ',' string_expression ')'  */
#line 886 "yabasic.bison"
                                                            {create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
#line 6673 "bison.c"
    break;

  case 505: /* printintro: tAT '(' expression ',' expression ')'  */
#line 887 "yabasic.bison"
                                          {add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
#line 6679 "bison.c"
    break;

  case 506: /* printintro: tREVERSE tAT '(' expression ',' expression ')'  */
#line 888 "yabasic.bison"
                                                   {add_command(cMOVE);create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
#line 6685 "bison.c"
    break;

  case 507: /* printintro: tCOLOUR '(' string_expression ')' tAT '(' expression ',' expression ')'  */
#line 889 "yabasic.bison"
                                                                            {add_command(cMOVE);create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
#line 6691 "bison.c"
    break;

  case 508: /* printintro: tCOLOUR '(' string_expression ',' string_expression ')' tAT '(' expression ',' expression ')'  */
#line 890 "yabasic.bison"
                                                                                                  {add_command(cMOVE);create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
#line 6697 "bison.c"
    break;

  case 509: /* printintro: tAT '(' expression ',' expression ')' tREVERSE  */
#line 891 "yabasic.bison"
                                                   {create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);add_command(cMOVE);}
#line 6703 "bison.c"
    break;

  case 510: /* printintro: tAT '(' expression ',' expression ')' tCOLOUR '(' string_expression ')'  */
#line 892 "yabasic.bison"
                                                                            {create_colour(2);add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
#line 6709 "bison.c"
    break;

  case 511: /* printintro: tAT '(' expression ',' expression ')' tCOLOUR '(' string_expression ',' string_expression ')'  */
#line 893 "yabasic.bison"
                                                                                                  {create_colour(3);add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
#line 6715 "bison.c"
    break;

  case 514: /* goto_list: symbol_or_lineno  */
#line 899 "yabasic.bison"
                            {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP);}
#line 6721 "bison.c"
    break;

  case 515: /* goto_list: goto_list ',' symbol_or_lineno  */
#line 900 "yabasic.bison"
                                   {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP);}
#line 6727 "bison.c"
    break;

  case 516: /* gosub_list: symbol_or_lineno  */
#line 903 "yabasic.bison"
                             {create_gosub((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP);}
#line 6733 "bison.c"
    break;

  case 517: /* gosub_list: gosub_list ',' symbol_or_lineno  */
#line 904 "yabasic.bison"
                                    {create_gosub((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP);}
#line 6739 "bison.c"
    break;


#line 6743 "bison.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  yyerror_range[1] = yylloc;
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
                      yytoken, &yylval, &yylloc);
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

