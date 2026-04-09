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
  YYSYMBOL_tBEAM_SEPARATOR = 203,          /* tBEAM_SEPARATOR  */
  YYSYMBOL_tBEAM_SPACING = 204,            /* tBEAM_SPACING  */
  YYSYMBOL_tBEAM_IMAGE = 205,              /* tBEAM_IMAGE  */
  YYSYMBOL_tBEAM_ROW = 206,                /* tBEAM_ROW  */
  YYSYMBOL_tBEAM_ROW_END = 207,            /* tBEAM_ROW_END  */
  YYSYMBOL_tBEAM_GROUP_BEGIN = 208,        /* tBEAM_GROUP_BEGIN  */
  YYSYMBOL_tBEAM_GROUP_END = 209,          /* tBEAM_GROUP_END  */
  YYSYMBOL_tBEAM_PANEL_BEGIN = 210,        /* tBEAM_PANEL_BEGIN  */
  YYSYMBOL_tBEAM_PANEL_END = 211,          /* tBEAM_PANEL_END  */
  YYSYMBOL_tBEAM_MSGBOX = 212,             /* tBEAM_MSGBOX  */
  YYSYMBOL_tBEAM_CONFIRM = 213,            /* tBEAM_CONFIRM  */
  YYSYMBOL_tBEAM_OPEN_FILE = 214,          /* tBEAM_OPEN_FILE  */
  YYSYMBOL_tBEAM_SAVE_FILE = 215,          /* tBEAM_SAVE_FILE  */
  YYSYMBOL_tBEAM_SET_COLOR = 216,          /* tBEAM_SET_COLOR  */
  YYSYMBOL_tBEAM_SET_STYLE = 217,          /* tBEAM_SET_STYLE  */
  YYSYMBOL_tBEAM_TIME = 218,               /* tBEAM_TIME  */
  YYSYMBOL_tBEAM_SLEEP = 219,              /* tBEAM_SLEEP  */
  YYSYMBOL_220_ = 220,                     /* '-'  */
  YYSYMBOL_221_ = 221,                     /* '+'  */
  YYSYMBOL_222_ = 222,                     /* '*'  */
  YYSYMBOL_223_ = 223,                     /* '/'  */
  YYSYMBOL_UMINUS = 224,                   /* UMINUS  */
  YYSYMBOL_225_ = 225,                     /* ';'  */
  YYSYMBOL_226_ = 226,                     /* ','  */
  YYSYMBOL_227_ = 227,                     /* '('  */
  YYSYMBOL_228_ = 228,                     /* ')'  */
  YYSYMBOL_229_ = 229,                     /* '#'  */
  YYSYMBOL_YYACCEPT = 230,                 /* $accept  */
  YYSYMBOL_program_or_expression = 231,    /* program_or_expression  */
  YYSYMBOL_program = 232,                  /* program  */
  YYSYMBOL_statement_list = 233,           /* statement_list  */
  YYSYMBOL_234_1 = 234,                    /* $@1  */
  YYSYMBOL_235_2 = 235,                    /* $@2  */
  YYSYMBOL_assignment = 236,               /* assignment  */
  YYSYMBOL_statement = 237,                /* statement  */
  YYSYMBOL_238_3 = 238,                    /* $@3  */
  YYSYMBOL_239_4 = 239,                    /* $@4  */
  YYSYMBOL_240_5 = 240,                    /* $@5  */
  YYSYMBOL_241_6 = 241,                    /* $@6  */
  YYSYMBOL_242_7 = 242,                    /* $@7  */
  YYSYMBOL_243_8 = 243,                    /* $@8  */
  YYSYMBOL_clear_fill_clause = 244,        /* clear_fill_clause  */
  YYSYMBOL_string_assignment = 245,        /* string_assignment  */
  YYSYMBOL_to = 246,                       /* to  */
  YYSYMBOL_open_clause = 247,              /* open_clause  */
  YYSYMBOL_seek_clause = 248,              /* seek_clause  */
  YYSYMBOL_string_scalar_or_array = 249,   /* string_scalar_or_array  */
  YYSYMBOL_string_expression = 250,        /* string_expression  */
  YYSYMBOL_string_function = 251,          /* string_function  */
  YYSYMBOL_number_assignment = 252,        /* number_assignment  */
  YYSYMBOL_expression = 253,               /* expression  */
  YYSYMBOL_254_9 = 254,                    /* $@9  */
  YYSYMBOL_255_10 = 255,                   /* $@10  */
  YYSYMBOL_arrayref = 256,                 /* arrayref  */
  YYSYMBOL_string_arrayref = 257,          /* string_arrayref  */
  YYSYMBOL_coordinates = 258,              /* coordinates  */
  YYSYMBOL_function = 259,                 /* function  */
  YYSYMBOL_const = 260,                    /* const  */
  YYSYMBOL_number = 261,                   /* number  */
  YYSYMBOL_symbol_or_lineno = 262,         /* symbol_or_lineno  */
  YYSYMBOL_dimlist = 263,                  /* dimlist  */
  YYSYMBOL_function_or_array = 264,        /* function_or_array  */
  YYSYMBOL_stringfunction_or_array = 265,  /* stringfunction_or_array  */
  YYSYMBOL_call_list = 266,                /* call_list  */
  YYSYMBOL_267_11 = 267,                   /* $@11  */
  YYSYMBOL_calls = 268,                    /* calls  */
  YYSYMBOL_call_item = 269,                /* call_item  */
  YYSYMBOL_function_definition = 270,      /* function_definition  */
  YYSYMBOL_271_12 = 271,                   /* $@12  */
  YYSYMBOL_272_13 = 272,                   /* $@13  */
  YYSYMBOL_273_14 = 273,                   /* $@14  */
  YYSYMBOL_endsub = 274,                   /* endsub  */
  YYSYMBOL_function_name = 275,            /* function_name  */
  YYSYMBOL_export = 276,                   /* export  */
  YYSYMBOL_local_list = 277,               /* local_list  */
  YYSYMBOL_local_item = 278,               /* local_item  */
  YYSYMBOL_static_list = 279,              /* static_list  */
  YYSYMBOL_static_item = 280,              /* static_item  */
  YYSYMBOL_paramlist = 281,                /* paramlist  */
  YYSYMBOL_paramitem = 282,                /* paramitem  */
  YYSYMBOL_for_loop = 283,                 /* for_loop  */
  YYSYMBOL_284_15 = 284,                   /* $@15  */
  YYSYMBOL_285_16 = 285,                   /* $@16  */
  YYSYMBOL_286_17 = 286,                   /* $@17  */
  YYSYMBOL_287_18 = 287,                   /* $@18  */
  YYSYMBOL_next = 288,                     /* next  */
  YYSYMBOL_step_part = 289,                /* step_part  */
  YYSYMBOL_next_symbol = 290,              /* next_symbol  */
  YYSYMBOL_switch_number_or_string = 291,  /* switch_number_or_string  */
  YYSYMBOL_292_19 = 292,                   /* $@19  */
  YYSYMBOL_sep_list = 293,                 /* sep_list  */
  YYSYMBOL_number_or_string = 294,         /* number_or_string  */
  YYSYMBOL_case_list = 295,                /* case_list  */
  YYSYMBOL_296_20 = 296,                   /* $@20  */
  YYSYMBOL_default = 297,                  /* default  */
  YYSYMBOL_298_21 = 298,                   /* $@21  */
  YYSYMBOL_do_loop = 299,                  /* do_loop  */
  YYSYMBOL_300_22 = 300,                   /* $@22  */
  YYSYMBOL_loop = 301,                     /* loop  */
  YYSYMBOL_while_loop = 302,               /* while_loop  */
  YYSYMBOL_303_23 = 303,                   /* $@23  */
  YYSYMBOL_304_24 = 304,                   /* $@24  */
  YYSYMBOL_wend = 305,                     /* wend  */
  YYSYMBOL_repeat_loop = 306,              /* repeat_loop  */
  YYSYMBOL_307_25 = 307,                   /* $@25  */
  YYSYMBOL_until = 308,                    /* until  */
  YYSYMBOL_if_clause = 309,                /* if_clause  */
  YYSYMBOL_310_26 = 310,                   /* $@26  */
  YYSYMBOL_311_27 = 311,                   /* $@27  */
  YYSYMBOL_312_28 = 312,                   /* $@28  */
  YYSYMBOL_313_29 = 313,                   /* $@29  */
  YYSYMBOL_endif = 314,                    /* endif  */
  YYSYMBOL_short_if = 315,                 /* short_if  */
  YYSYMBOL_316_30 = 316,                   /* $@30  */
  YYSYMBOL_end_of_if = 317,                /* end_of_if  */
  YYSYMBOL_else_part = 318,                /* else_part  */
  YYSYMBOL_elsif_part = 319,               /* elsif_part  */
  YYSYMBOL_320_31 = 320,                   /* $@31  */
  YYSYMBOL_321_32 = 321,                   /* $@32  */
  YYSYMBOL_maybe_then = 322,               /* maybe_then  */
  YYSYMBOL_inputlist = 323,                /* inputlist  */
  YYSYMBOL_324_33 = 324,                   /* $@33  */
  YYSYMBOL_input = 325,                    /* input  */
  YYSYMBOL_readlist = 326,                 /* readlist  */
  YYSYMBOL_readitem = 327,                 /* readitem  */
  YYSYMBOL_datalist = 328,                 /* datalist  */
  YYSYMBOL_printlist = 329,                /* printlist  */
  YYSYMBOL_using = 330,                    /* using  */
  YYSYMBOL_inputbody = 331,                /* inputbody  */
  YYSYMBOL_332_34 = 332,                   /* $@34  */
  YYSYMBOL_333_35 = 333,                   /* $@35  */
  YYSYMBOL_334_36 = 334,                   /* $@36  */
  YYSYMBOL_335_37 = 335,                   /* $@37  */
  YYSYMBOL_336_38 = 336,                   /* $@38  */
  YYSYMBOL_prompt = 337,                   /* prompt  */
  YYSYMBOL_printintro = 338,               /* printintro  */
  YYSYMBOL_hashed_number = 339,            /* hashed_number  */
  YYSYMBOL_goto_list = 340,                /* goto_list  */
  YYSYMBOL_gosub_list = 341                /* gosub_list  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;



/* Unqualified %code blocks.  */

void
yyerror(char *message) {
  error(sERROR,message);
}

void
lyyerror(int severity, char *message) {
  error(severity,message);
}


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
#define YYFINAL  224
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   8136

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  230
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  112
/* YYNRULES -- Number of rules.  */
#define YYNRULES  511
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1327

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   475


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
       2,     2,     2,     2,     2,   229,     2,     2,     2,     2,
     227,   228,   222,   221,   226,   220,     2,   223,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   225,
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
     215,   216,   217,   218,   219,   224
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   201,   201,   202,   203,   204,   205,   208,   211,   212,
     212,   212,   215,   216,   217,   218,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   236,   237,   237,   238,   239,   240,   241,   242,
     243,   244,   244,   246,   246,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   258,   259,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   276,   277,
     278,   279,   280,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   315,   316,   317,   318,   319,
     320,   321,   322,   323,   324,   325,   326,   327,   329,   330,
     331,   332,   333,   334,   335,   336,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,   352,   353,
     354,   355,   356,   360,   361,   362,   363,   364,   365,   368,
     369,   372,   373,   374,   375,   376,   379,   380,   383,   384,
     387,   388,   389,   390,   391,   392,   395,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,   417,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   437,   438,   441,
     442,   445,   445,   446,   446,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   475,   476,   477,   478,   481,   484,   487,
     490,   491,   492,   493,   494,   495,   496,   497,   498,   499,
     500,   501,   502,   503,   504,   505,   506,   507,   508,   509,
     510,   511,   512,   513,   514,   515,   516,   517,   518,   519,
     520,   521,   522,   523,   524,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   547,   548,   549,
     550,   551,   552,   553,   554,   555,   556,   557,   558,   559,
     560,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   574,   575,   576,   579,   580,   581,   582,   585,   586,
     589,   590,   591,   592,   595,   598,   601,   601,   604,   605,
     606,   609,   610,   613,   614,   617,   613,   622,   623,   626,
     627,   630,   631,   632,   633,   636,   637,   640,   641,   642,
     643,   646,   647,   650,   651,   652,   653,   656,   657,   658,
     661,   662,   663,   664,   667,   668,   673,   688,   667,   693,
     694,   695,   696,   697,   698,   701,   702,   705,   706,   711,
     711,   715,   716,   719,   720,   724,   726,   725,   730,   731,
     731,   735,   735,   741,   742,   743,   744,   745,   746,   750,
     751,   750,   757,   758,   762,   762,   767,   768,   769,   770,
     771,   772,   775,   776,   776,   778,   775,   782,   783,   784,
     785,   786,   787,   790,   790,   795,   796,   799,   800,   803,
     805,   807,   804,   811,   812,   815,   816,   816,   819,   820,
     822,   823,   827,   828,   831,   832,   834,   835,   839,   840,
     841,   842,   845,   846,   847,   848,   849,   852,   853,   854,
     857,   857,   858,   858,   859,   859,   860,   860,   861,   861,
     864,   865,   868,   869,   870,   871,   872,   873,   874,   875,
     876,   877,   878,   879,   880,   881,   884,   885,   887,   888,
     891,   892
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
  "tBEAM_PROGRESS", "tBEAM_SEPARATOR", "tBEAM_SPACING", "tBEAM_IMAGE",
  "tBEAM_ROW", "tBEAM_ROW_END", "tBEAM_GROUP_BEGIN", "tBEAM_GROUP_END",
  "tBEAM_PANEL_BEGIN", "tBEAM_PANEL_END", "tBEAM_MSGBOX", "tBEAM_CONFIRM",
  "tBEAM_OPEN_FILE", "tBEAM_SAVE_FILE", "tBEAM_SET_COLOR",
  "tBEAM_SET_STYLE", "tBEAM_TIME", "tBEAM_SLEEP", "'-'", "'+'", "'*'",
  "'/'", "UMINUS", "';'", "','", "'('", "')'", "'#'", "$accept",
  "program_or_expression", "program", "statement_list", "$@1", "$@2",
  "assignment", "statement", "$@3", "$@4", "$@5", "$@6", "$@7", "$@8",
  "clear_fill_clause", "string_assignment", "to", "open_clause",
  "seek_clause", "string_scalar_or_array", "string_expression",
  "string_function", "number_assignment", "expression", "$@9", "$@10",
  "arrayref", "string_arrayref", "coordinates", "function", "const",
  "number", "symbol_or_lineno", "dimlist", "function_or_array",
  "stringfunction_or_array", "call_list", "$@11", "calls", "call_item",
  "function_definition", "$@12", "$@13", "$@14", "endsub", "function_name",
  "export", "local_list", "local_item", "static_list", "static_item",
  "paramlist", "paramitem", "for_loop", "$@15", "$@16", "$@17", "$@18",
  "next", "step_part", "next_symbol", "switch_number_or_string", "$@19",
  "sep_list", "number_or_string", "case_list", "$@20", "default", "$@21",
  "do_loop", "$@22", "loop", "while_loop", "$@23", "$@24", "wend",
  "repeat_loop", "$@25", "until", "if_clause", "$@26", "$@27", "$@28",
  "$@29", "endif", "short_if", "$@30", "end_of_if", "else_part",
  "elsif_part", "$@31", "$@32", "maybe_then", "inputlist", "$@33", "input",
  "readlist", "readitem", "datalist", "printlist", "using", "inputbody",
  "$@34", "$@35", "$@36", "$@37", "$@38", "prompt", "printintro",
  "hashed_number", "goto_list", "gosub_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-952)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-433)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     686,  4608,  3782,  4118,   339,    17,    25,   -52,   -31,  -952,
    -952,  -952,  -952,  -952,   123,   123,   123,  3384,  -952,  -952,
    -952,  4118,  -952,  -952,  4118,     1,    32,  -952,  -952,  -952,
    3782,   -28,  -952,  3782,   109,  -952,  3782,  3782,  3782,   205,
      45,   123,  1988,  1788,  2388,   -37,  3782,  3185,  3782,   216,
     -36,  3782,  -952,   299,  4118,  4118,  4118,   -13,  -154,   -80,
     -41,   -33,    -3,  2388,  4118,  4118,  4118,     0,     8,    18,
      47,    50,    84,   106,   157,   168,   211,   213,   239,   241,
     262,   270,   278,   280,   315,   341,   411,  -952,   126,  -952,
    -952,    14,  -952,  -952,  -952,  -952,   218,   334,  -952,   265,
    -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,   445,   460,
    -952,  -952,  -952,  -952,   484,   490,   536,   552,  3782,   562,
     563,   571,   585,   589,   591,   598,   605,   614,   622,   632,
     633,   637,   645,   646,   648,   649,   650,   652,   653,   656,
     659,   660,   662,   663,   664,   665,   666,   667,   668,   669,
     670,   671,   672,   674,   678,   679,   680,   681,   682,   683,
     684,   694,   695,   698,   699,   702,   703,   707,   708,   710,
     712,   713,   714,   715,   716,   718,   719,   722,   726,   740,
     743,   744,   745,   748,   749,   750,   751,   759,   760,   763,
     765,   767,   784,   785,   787,   796,   798,   802,   803,   808,
     815,   816,   828,   829,   830,   831,   833,   834,   835,  3782,
    3782,    12,  -952,    28,  -952,  -952,  -952,  -952,  4118,   -32,
     219,   218,   334,   337,  -952,  3782,  -952,  4118,  -952,   407,
    3782,  4399,  -952,  -952,  -952,  -952,  -952,   310,   516,   353,
     420,   300,  -952,  3782,  -952,   300,  -952,  -952,  3782,  4399,
     535,   836,   368,   838,    15,  3782,   -44,    12,  7913,   839,
     840,   307,  7913,    12,  6359,    12,  6390,   841,   842,   573,
    -952,  -952,   758,   758,  -952,  -952,   588,  -952,  3782,  4118,
    3782,     5,  7913,   687,  -952,  -952,  -952,  -952,   689,  4118,
    6428,  -952,  3782,  -952,    -1,   730,  -952,  -952,  3782,  3583,
    -952,  -952,  7913,  -952,  -952,   300,    -9,    -9,  -952,   690,
     690,   690,  2588,  4118,   630,   844,   300,  -161,   -29,  3782,
    3782,  3782,  3782,  3782,  4118,  4118,  3782,   263,  3782,  4118,
    3782,   485,  4118,   534,  4118,   560,  3782,  4118,  3782,  -952,
     909,  3782,  3782,  3782,  3782,  4118,  -952,  -952,  -952,  3782,
    3782,  1343,  3782,  3782,  3782,  3782,  2188,  2388,   448,   448,
    3782,  3782,  3782,  3782,  3782,  3782,  3782,  3782,  3782,  3782,
    3782,  3782,  2388,  3782,  3782,  3782,  3782,  3782,  3782,  3782,
    3782,  2787,  4118,  4118,  4118,  4118,  4118,  3782,  3782,  3782,
    2986,  3782,  4118,  3782,  4118,  3782,  4118,  4118,    16,  1162,
    1321,  1466,  4118,  4118,  4118,  4118,  4118,  4118,  4118,  4118,
    2388,  4118,  -952,  -952,  4118,  3782,  4118,  4118,  4118,  4118,
    4118,   843,   845,  4118,   690,  4118,   690,  4118,  4118,  4118,
    3782,  3782,  4118,  4118,  4118,  4118,  3782,  4118,  4118,  4118,
    4118,   846,   998,   326,  1467,  4118,  4118,  4118,  4118,  4118,
    4118,  4118,  4118,  -952,  -952,  -952,  3782,  3782,  3782,  3782,
    3782,  3782,  3782,  3782,  3782,  3782,  3782,  3782,   -10,  -952,
    -952,  -952,  7913,   848,   300,   849,  1003,  7913,   188,  -952,
    -952,  -952,  -952,   852,   853,   855,  -952,   856,   858,   861,
    -952,    12,  7913,   862,  -952,    12,  7913,  1039,   482,  1044,
    4399,  3782,   868,  4118,  -952,  -952,  3782,    12,   607,   294,
     871,    20,  -952,  1090,  -952,  -952,   540,  3782,  3782,  -952,
    -952,   205,  -952,  -952,    60,  6443,   300,  7913,   483,  3961,
    3782,   300,  3782,  -952,   -44,  -952,  -952,  3782,  4118,  -952,
    3782,    -1,  3782,  3782,   872,   875,   877,   878,  -952,  1586,
      58,  3782,  3782,  3782,  3782,  1639,  6458,  6473,  1950,  2150,
      69,   -21,  6488,  -952,  2203,    87,  6520,  -952,   102,  -952,
     215,  -952,  6551,   104,  2403,  -952,   880,    -1,    -1,  7913,
     300,   578,   883,   886,  6566,  6649,  2603,  6681,  6727,  6742,
     888,    70,   891,   892,   894,   897,   898,   901,   893,   904,
      -1,  6757,  2802,  3001,  3200,  3399,  3598,   887,  3765,  1158,
    3797,  4009,   903,  4087,  4170,  4248,  4451,  4472,  4503,  4681,
    6772,  -952,  4712,   128,   374,   404,   413,   162,  6787,  6810,
     487,  1293,  -952,  4889,  4921,   182,  4967,  -132,  4982,   191,
     199,  -952,   202,  -952,   214,  -952,   223,  -952,   246,   267,
     285,   296,   430,   440,   297,   301,   306,   543,   905,  -109,
     906,   907,   318,  4997,   327,  -106,   548,   551,   554,  -952,
    -952,   555,  -133,   561,   -75,   565,   373,   375,  6842,  5012,
     576,   584,   587,   610,  6857,   612,   618,   376,   403,  -952,
    -952,  -952,   300,   300,   300,   300,   300,   300,   300,  -952,
    3782,  3782,  1089,   194,   264,   225,   184,    34,   -57,  -952,
     -40,   -40,   998,   998,  -952,  -952,  -952,  4399,  -952,  -952,
    3782,  -952,  -952,  -952,  -952,   123,   123,  -952,  -952,   353,
    -952,  -952,   420,  3782,  -952,  1093,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,   626,  6948,  3782,   -97,  5027,  4197,
    -952,  -952,  3782,  3782,  -952,  -952,  3782,  -952,   580,   910,
     911,   913,   914,  6971,  7018,   916,   919,  -952,  -952,  -952,
    3782,  1063,  1067,  -952,   619,  7033,  7913,  -952,  -952,   627,
    -952,  3782,  7048,  7063,  -952,  3782,  3782,  3782,  -952,  -952,
      12,  7913,    12,  7913,  7078,  7109,  -952,  4118,  3782,  -952,
    -952,  -952,  3782,  3782,  -952,  3782,  3782,  -952,  3782,  3782,
    -952,  -952,  4399,  3782,  3782,  3782,  -952,  -952,  -952,  -952,
    -952,  3782,  3782,  -952,  3782,  3782,  3782,  -952,  4118,  -952,
    4040,  -952,   925,   926,  -952,  -952,  3782,  3782,  3782,  3782,
    -952,  -952,  -952,  -952,  -952,  3782,  -952,  -952,  3782,  -952,
    -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,
    3782,  -952,  -952,  3782,  3782,  3782,  -952,  3782,  3782,  -952,
    4118,  -952,  -952,  -952,  -952,  -952,  3782,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  4118,  4118,
    -952,  -952,  -952,  -952,  -952,  4118,  -952,  -952,  -952,  -952,
    -952,  -952,  3782,  -952,  3782,  3782,  3782,  1150,  4118,  -952,
    1150,  4118,  -952,  4118,  -952,  -952,  3782,  -952,  3782,  3782,
    3782,  3782,  3782,  4118,  4118,  -952,  -952,  1343,   572,  3782,
      22,  7913,  -952,   930,  -952,   931,   940,   941,  -952,   943,
     945,  -952,  -952,  -952,   582,  4399,  -952,  -952,  -952,  3782,
    7132,  4118,  1100,  -952,  4118,   300,    12,   607,  7147,   580,
     580,  5050,   947,   949,  -952,   951,  -952,  -952,  -952,  -952,
    3782,  3782,  -952,  -952,  7239,  2388,  2388,  4118,  4118,  4118,
    -952,  3782,  3782,   950,  5082,  5097,  1334,  4118,  4118,   412,
    7270,  7308,  7323,  7338,  5188,  7353,  7368,  -952,  7913,    -1,
    -952,   952,  5211,  5258,  5273,  5288,  5303,   429,   953,   -69,
    -952,  -952,  5318,  5349,   954,    62,  5372,  5387,  5479,  5510,
    5548,  1368,  5563,  5578,    -7,  5593,    -6,    66,   431,  5608,
    7400,  7431,  5640,   -48,   439,    36,   464,   465,  7446,  7529,
    7561,  5671,  7607,  7622,   468,   469,   406,  -952,  -952,  -952,
     123,   123,  -952,  -952,  -952,  -952,  3782,  1137,  1145,  1141,
    5686,  3782,   486,   958,    88,  -952,  3782,  -952,  -952,  -952,
    -952,  -952,  -952,   961,   962,  7913,  7913,  4118,  -952,  -952,
     300,   300,   629,  7637,  7913,  -952,  1111,  1116,  3782,  1117,
     631,   300,  -952,  3782,  3782,  3782,  3782,  -952,  3782,  3782,
    3782,   725,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  4118,
    -952,  -952,  -952,  -952,  3782,  -952,  -952,  -952,  -952,  -952,
    3782,  -952,  -952,  -952,  4118,  -952,  -952,  3782,  -952,  3782,
    -952,  -952,  -952,  4118,  3782,  -952,  4118,  -952,  -952,  4118,
    -952,  -952,  -952,  4118,  3782,  3782,  -952,  3782,  3782,  -952,
    -952,  3782,  -952,  -952,  -952,  -952,  -952,  1154,   688,  5769,
    1146,  3782,  4118,  5801,   580,   975,   978,   580,  -952,  -952,
     300,  4118,  4118,  4118,  4118,  5847,  4118,  3782,  5862,  5877,
    7652,  5892,  5907,  5930,  -952,   980,   983,   166,  -952,   488,
    7667,  5962,   491,  5977,  6068,   504,  6091,   512,   513,   514,
    6138,  6153,  7690,  7722,   501,  4399,  4817,  3782,  1164,  -952,
     985,  -952,   986,  7737,   525,  -952,  -952,  -952,  -952,  -952,
     300,   300,   300,   300,  1142,   300,  7913,  -952,  -952,  3782,
    -952,  -952,  -952,   988,   990,   725,  -952,  -952,  3782,  -952,
    -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,
    3782,  3782,  3782,  -952,  1141,  1181,  1124,  4399,  -952,  4118,
    3782,  3782,  -952,  1090,  4118,  6168,  -952,  -952,  -952,  4399,
    6183,  7828,  7851,  7913,  4399,  -952,  -952,  1141,   494,   101,
    7898,  6198,   580,   300,  -952,    46,  -952,  3782,  3782,  1141,
    4399,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  4118,  -952,
    3782,  -952,  -952,  -952,  -952,  -952,  6229,  6252,   729,  1141,
     531,  6267,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,
    1216,  1154,  -952,  -952,  -952,  -952,  -952
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,   138,     0,     0,     0,   361,     0,     0,     0,   112,
     384,   419,   424,    18,     0,     0,     0,     0,    31,    33,
     362,     0,   346,   346,     0,   363,    25,    27,   399,   411,
       0,   492,    55,    67,     0,   109,   110,     0,     0,     0,
       0,    65,     0,     0,     0,     0,     0,     0,     0,   139,
     140,     0,   100,     0,     0,     0,     0,     0,     0,     0,
       0,   101,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     2,     9,    17,
       8,     0,    12,    46,    48,    14,    29,    30,    28,     0,
      20,    21,    24,    23,    22,    35,    36,   334,   231,   160,
     335,   336,   337,   163,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   174,     0,     0,
       0,     0,     0,     0,     0,   291,   294,   297,   300,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   189,   191,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   161,     0,   245,   225,   230,   162,     0,     0,
       0,     0,     0,     0,     1,     0,   346,     0,   346,     0,
       0,    16,   339,   338,    37,    38,    45,     0,     0,     0,
       0,    19,    50,   348,    51,    49,   364,    26,     0,    16,
     443,     0,   496,     0,     0,   472,   488,    69,    68,     0,
       0,    70,   111,    60,     0,    62,     0,   464,   466,    63,
     462,   468,     0,     0,   469,   331,    64,    66,     0,    96,
       0,     0,   507,     0,    93,    98,    86,    47,     0,     0,
       0,    74,     0,    57,    79,     0,    95,    94,     0,     0,
     141,   142,    99,    13,    15,   113,     0,     0,    85,     0,
       0,     0,     0,     0,     0,     0,   114,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     7,
       0,     0,     0,     0,     0,     0,   353,   346,   346,     0,
       0,   215,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   346,   346,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   237,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     3,   213,   211,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     4,
       5,     6,   209,     0,   143,     0,     0,   420,     9,    39,
      40,    41,    43,   367,   368,    32,   365,   373,   374,    34,
     371,   351,   352,   347,   349,   404,   403,     0,     9,     0,
      16,     0,     0,     0,   493,   494,     0,   475,   477,    52,
       0,     0,    56,   490,   346,   346,     0,     0,     0,   346,
     346,     0,   333,   332,     0,     0,    97,   506,     0,     0,
       0,    73,     0,    78,   488,   150,   149,     0,     0,    75,
       0,    81,     0,     0,   158,     0,     0,     0,   102,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   127,     0,     0,     0,   130,     0,   132,
       0,   134,     0,     0,     0,    10,     0,     0,     0,   210,
     148,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   271,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   175,     0,     0,     0,     0,     0,     0,     0,
       0,   292,     0,   295,     0,   298,     0,   301,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   190,
     192,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   328,
     165,   246,   240,   242,   244,   241,   243,   238,   239,   164,
       0,     0,   218,   220,   222,   219,   221,   216,   217,   236,
     233,   232,   234,   235,   344,   345,   385,    16,   431,   429,
       0,   430,   426,   428,   425,     0,     0,   346,   346,     0,
     346,   346,     0,     0,   401,   405,   418,   416,   417,   414,
     413,   415,   412,   433,     9,     0,     0,     0,     0,     0,
     473,    53,    54,     0,   480,   482,     0,   491,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   463,   470,   471,
       0,     0,     0,   153,   152,   156,   249,    58,    76,    89,
      80,     0,     0,     0,   346,     0,     0,     0,   103,   104,
     105,   106,   107,   108,     0,     0,   118,     0,     0,   121,
     122,   123,     0,     0,   128,     0,     0,   131,     0,     0,
     136,   137,    16,     0,     0,     0,   359,   360,   354,   313,
     203,     0,     0,   304,     0,     0,     0,   314,     0,   315,
       0,   308,     0,     0,   226,   227,     0,     0,     0,     0,
     250,   251,   252,   253,   254,     0,   255,   257,     0,   258,
     260,   261,   223,   267,   268,   262,   264,   265,   266,   263,
       0,   270,   275,     0,     0,     0,   274,     0,     0,   173,
       0,   170,   176,   177,   276,   201,     0,   277,   202,   178,
     179,   290,   293,   296,   299,   182,   180,   181,     0,     0,
     183,   283,   184,   289,   288,     0,   193,   284,   185,   285,
     186,   287,     0,   187,     0,     0,     0,     0,     0,   196,
       0,     0,   198,     0,   320,   206,     0,   322,     0,     0,
       0,     0,     0,     0,     0,   207,   208,   214,   212,     0,
       9,   427,   508,    42,   510,    44,     0,     0,   366,     0,
       0,   372,   350,   402,   408,    16,   445,   446,   444,     0,
       0,     0,   497,   495,     0,   478,   476,   477,     0,     0,
       0,     0,   458,   460,   489,   455,   340,   342,   346,   346,
       0,     0,   465,   467,    71,     0,     0,     0,     0,     0,
      77,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    11,    87,     0,
      92,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     247,   248,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   423,   422,   421,
       0,     0,   369,   370,   375,   376,     0,     0,     0,   434,
       0,     0,     0,     0,     0,   474,     0,   481,   483,   484,
     346,   346,   456,     0,     0,    59,    61,     0,   154,   155,
     151,   157,    90,    83,    84,   159,     0,     0,     0,     0,
     116,   117,   119,     0,     0,     0,     0,   129,     0,     0,
       0,   377,   302,   303,   305,   306,   307,   316,   317,     0,
     318,   228,   229,   199,     0,   256,   259,   269,   166,   167,
       0,   169,   272,   273,     0,   171,   278,     0,   279,     0,
     281,   194,   188,     0,     0,   205,     0,   310,   195,     0,
     312,   197,   224,     0,     0,     0,   325,     0,     0,   329,
     330,     0,   509,   511,   406,   409,   400,   449,   499,     0,
     498,     0,     0,     0,     0,     0,     0,     0,   341,   343,
      72,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    88,   380,   381,     0,   378,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   395,    16,   138,     0,   447,   503,
       0,   500,     0,     0,     0,   486,   485,   459,   461,   457,
      91,    82,   146,   147,     0,   145,   115,   120,   124,     0,
     125,   133,   135,     0,     0,     0,   355,   319,     0,   168,
     172,   280,   282,   286,   204,   309,   311,   321,   323,   324,
       0,     0,     0,   386,   407,     9,   453,    16,   435,     0,
       0,     0,   479,   490,     0,     0,   382,   383,   379,    16,
       0,     0,     0,   396,    16,   454,   450,   448,     0,     0,
       0,     0,     0,   144,   126,     9,   200,     0,     0,   387,
      16,   442,   439,   440,   441,   437,   438,   436,     0,   504,
       0,   501,   487,   358,   357,   356,     0,     0,     0,   451,
       0,     0,   326,   327,   390,   392,   393,   394,   389,   391,
     397,   449,   505,   502,   398,   388,   452
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -952,  -952,  -952,  -185,  -952,  -952,  1219,   414,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,  1184,  -305,  -952,  -952,  -253,
     599,  -952,  1185,    -2,  -952,  -952,   881,  -354,   151,  -952,
     717,   -34,     2,  -952,     3,     9,   154,  -952,  -952,   506,
    1237,  -952,  -952,  -952,  -952,  -952,  -952,  -952,   515,  -952,
     511,  -952,    10,  -952,  -952,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,   190,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,   -74,
    -952,  -952,  -952,  -951,  -952,  -952,  -952,   731,  -952,  -952,
     298,   720,  -952,  -952,  -952,  -952,  -952,     7,  -952,    65,
    -952,  -952
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     6,    87,    88,   340,   812,    89,    90,   239,   240,
     725,   726,   256,   534,    91,    92,   537,    93,    94,   545,
     211,   212,    95,   290,   701,   700,   596,   597,   291,   214,
     274,   215,   234,   261,   216,   217,   242,   243,   493,   494,
      98,   581,  1001,  1269,  1305,   818,    99,   485,   486,   489,
     490,  1187,  1188,   100,   229,   929,  1274,  1308,  1320,  1253,
    1325,   101,   248,   735,   497,   944,  1205,  1058,  1206,   102,
     249,   742,   103,   230,   717,  1049,   104,   231,   724,   105,
     499,   945,  1157,  1278,  1297,   106,   500,   948,  1258,  1208,
    1290,  1321,  1276,   964,  1167,   965,   269,   270,   276,   509,
     750,   512,   959,   960,  1164,  1263,   513,   758,   255,   283,
     933,   935
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     213,   542,   543,   535,    96,   599,   275,   221,  1067,  1068,
      97,   535,   469,   222,   510,   238,   528,   235,   236,   504,
     463,   109,   505,   225,   754,   224,   113,   755,   250,   246,
     251,   258,   252,   253,   262,   264,   266,   463,  1047,   247,
     282,   282,   282,   277,   227,    20,   478,   115,   107,   302,
      25,   289,   110,   111,   112,   271,   221,   546,   547,   301,
     452,   282,   222,   107,   498,   553,  1048,   110,   111,   112,
     768,  1303,   453,   309,   535,   445,   446,   447,   448,   449,
     450,   451,   445,   446,   447,   448,   449,   450,   451,   452,
    1304,   454,   455,   908,   876,   909,   877,   308,   456,   457,
     458,   459,   460,   461,   462,   463,   341,   342,   287,   288,
     462,   463,   452,   259,   260,   452,   351,   895,   343,   896,
     902,   127,   903,   128,   452,   454,   455,   232,   315,   951,
     233,   952,   456,   457,   458,   459,   460,   461,   462,   463,
     445,   446,   447,   448,   449,   450,   451,   310,   150,   151,
     152,   911,   452,   912,   156,   157,   158,  1109,   160,  1110,
     162,   163,   164,   464,   465,   466,   467,   169,   170,   171,
     339,   672,   174,   674,   176,   226,   178,   244,  1136,   180,
    1137,   182,   466,   467,   184,   511,   311,   186,   187,   452,
     188,   189,   452,   191,   312,   193,   228,   554,   294,   295,
     452,   254,   718,   196,   719,   802,   720,   442,   444,   267,
     268,   452,   452,  1216,   452,   452,  1219,   536,   690,  1124,
    1127,  1125,  1128,   472,   313,   536,   452,   319,   477,   721,
     206,   207,   722,   452,    96,   320,   781,   723,   522,   523,
      97,   492,   506,   218,   641,   321,   496,   756,   464,   465,
     466,   467,    96,   508,   464,   465,   466,   467,    97,   461,
     462,   463,  1139,   470,  1140,   272,   273,   459,   460,   461,
     462,   463,   814,   815,   322,   296,   525,   323,   527,   452,
     272,   273,   464,   465,   466,   467,   789,   452,   536,   346,
     452,   452,  1129,   344,  1130,   838,   828,   801,   829,   460,
     461,   462,   463,     7,     8,   297,   298,   299,   452,   452,
     549,   324,   300,   805,  1162,   744,   690,   555,   556,   557,
     558,   559,   452,   452,   562,   452,   564,  1298,   566,  1299,
     807,  1302,   810,   325,   572,   457,   574,   459,   460,   461,
     462,   463,   579,     7,     8,   479,   480,   584,   585,   452,
     586,   587,   588,   589,   282,   282,   862,   483,   484,   601,
     602,   603,   604,   605,   606,   607,   608,   609,   610,   611,
     282,   613,   614,   615,   616,   617,   618,   619,   620,   622,
     473,   471,   475,   452,   326,   628,   629,   631,   633,   634,
     866,   636,  1235,   638,  1236,   327,   445,   446,   447,   448,
     449,   450,   451,   452,   464,   465,   466,   467,   282,   345,
     874,   476,   452,   663,   464,   465,   466,   467,  1151,   879,
     452,   592,   593,   452,   487,   488,   502,   880,   678,   679,
     881,    58,    59,    60,   684,   452,   452,   612,   328,    53,
     329,   808,   882,   533,   452,   464,   465,   466,   467,   539,
     541,   883,   594,   595,   702,   703,   704,   705,   706,   707,
     708,   709,   710,   711,   712,   713,   330,   452,   331,   454,
     455,    58,    59,    60,   884,   658,   456,   457,   458,   459,
     460,   461,   462,   463,   464,   465,   466,   467,   452,   332,
     275,   563,   576,   577,   578,   885,   736,   333,   737,   745,
     738,   582,   583,    96,   748,   334,   452,   335,  1291,    97,
    1292,   600,  1293,   886,  1252,   763,   764,   452,   452,   751,
     752,   452,   452,   739,   887,   890,   740,   452,   775,   891,
     776,   741,   930,   516,   892,  1294,   481,   482,  1295,   452,
     782,   783,   336,  1296,   761,   762,   899,   452,   452,   791,
     793,   794,   795,  1033,   690,   901,  1035,   445,   446,   447,
     448,   449,   450,   451,   454,   455,   660,   661,   337,   771,
     772,   456,   457,   458,   459,   460,   461,   462,   463,   454,
     455,  -432,   816,   817,   962,   963,   456,   457,   458,   459,
     460,   461,   462,   463,   452,   452,   452,   452,   454,   455,
     863,   914,   219,   915,   925,   456,   457,   458,   459,   460,
     461,   462,   463,   445,   446,   447,   448,   449,   450,   451,
     241,  1056,  1057,   245,   452,   452,   464,   465,   466,   467,
     864,   926,   257,   452,   452,   454,   263,   265,   338,   865,
    1092,   281,   456,   457,   458,   459,   460,   461,   462,   463,
     452,   452,   452,   305,   306,   307,   888,  1107,   749,  1131,
     452,   452,   314,   316,   317,   318,   889,  1138,   759,   760,
     454,   455,   226,   765,   766,   946,   947,   456,   457,   458,
     459,   460,   461,   462,   463,   452,   452,   228,   778,   452,
     452,   780,  1141,  1142,  1100,   544,  1149,  1150,   927,   928,
     445,   446,   447,   448,   449,   450,   451,   452,   452,   452,
    1114,   347,   452,   567,  1160,   869,  1237,   348,   931,  1240,
      96,   464,   465,   466,   467,   452,    97,   932,   934,  1185,
    1186,   492,  1243,   452,   452,   452,   464,   465,   466,   467,
    1245,  1246,  1247,  1314,   950,  1315,   452,  1316,  1209,  1210,
     957,   958,   452,  1262,   961,   464,   465,   466,   467,  1322,
    1059,   107,   569,   349,   452,   110,   111,   112,   974,   452,
    1317,   893,   452,  1318,   904,   452,   452,   905,  1319,   350,
     906,   907,   452,   984,   985,   986,   452,   910,   571,   352,
     353,   913,   464,   465,   466,   467,   990,   452,   354,   521,
     991,   992,   918,   993,   994,   452,   995,   996,   452,   443,
     919,   998,   355,   920,   524,    96,   356,   468,   357,  1002,
    1003,    97,  1004,  1005,  1006,   358,   474,   464,   465,   466,
     467,   452,   359,   452,  1012,  1013,   921,  1015,   923,   452,
     452,   360,   491,  1016,   924,   977,  1017,   495,   452,   361,
     452,   452,   452,   979,   507,  1171,   551,  1177,  1018,   362,
     363,  1019,  1020,  1021,   364,  1022,  1023,     1,     2,     3,
       4,     5,   365,   366,  1025,   367,   368,   369,   526,   370,
     371,   936,   937,   372,   939,   940,   373,   374,   531,   375,
     376,   377,   378,   379,   380,   381,   382,   383,   384,   385,
    1029,   386,  1030,  1031,  1032,   387,   388,   389,   390,   391,
     392,   393,   550,   529,  1038,   530,  1039,  1040,  1041,  1042,
    1043,   394,   395,   560,   561,   396,   397,  1046,   565,   398,
     399,   568,   980,   570,   400,   401,   573,   402,   983,   403,
     404,   405,   406,   407,   580,   408,   409,  1060,    96,   410,
     454,   455,   575,   411,    97,   591,   538,   456,   457,   458,
     459,   460,   461,   462,   463,   999,  1000,   412,  1075,  1076,
     413,   414,   415,   282,   282,   416,   417,   418,   419,  1083,
    1084,   623,   624,   625,   626,   627,   420,   421,   630,  1014,
     422,   635,   423,   637,   424,   639,   640,   642,   644,   646,
     648,   649,   650,   651,   652,   653,   654,   655,   656,   657,
     659,   425,   426,   662,   427,   664,   665,   666,   667,   668,
    1254,  1255,   671,   428,   673,   429,   675,   676,   677,   430,
     431,   680,   681,   682,   683,   432,   685,   686,   687,   688,
    1078,  1079,   433,   434,   692,   693,   694,   695,   696,   697,
     698,   699,  1152,  1153,   496,   435,   436,   437,   438,  1159,
     439,   440,   441,   501,  1163,   503,   514,   515,   519,   520,
     552,   669,  1277,   670,   689,   463,   714,   715,   716,   727,
     728,   729,   734,   730,  1285,   731,  1175,   732,   733,  1289,
     743,  1178,  1179,  1180,  1181,   746,  1182,  1183,   753,   784,
     757,   785,   747,   786,   787,  1309,   813,   464,   465,   466,
     467,   819,  1190,   845,   820,   846,   827,   830,  1191,   836,
     831,   832,  1073,  1074,   833,  1193,   834,  1194,   774,   835,
     837,   852,  1196,   894,   897,   898,   943,   779,   966,   967,
     968,   969,  1200,  1201,   972,  1202,  1203,   973,   975,  1204,
     790,   792,   976,  1010,  1011,   595,  1050,  1051,  1063,  1213,
     457,   458,   459,   460,   461,   462,   463,   109,  1052,  1053,
    1275,  1054,   113,  1055,  1070,  1226,  1071,  1072,  1085,  1101,
    1155,  1108,  1113,  1156,    -9,  1161,  1173,   454,   455,  1168,
    1169,  1174,  1176,   115,   456,   457,   458,   459,   460,   461,
     462,   463,  1207,  1217,  1212,  1256,  1218,  1233,    96,    96,
    1234,  1257,  1259,  1260,    97,    97,  1266,  1264,  1267,  -410,
    1324,   454,   455,   220,  1165,  1166,   997,  1265,   456,   457,
     458,   459,   460,   461,   462,   463,  1270,   303,   304,   942,
     598,   769,   223,   941,   938,  1268,  1154,  1326,  1271,  1272,
    1273,  1184,   767,     0,   777,  1065,     0,     0,  1280,  1281,
      96,     0,     0,     0,     0,     0,    97,   127,     0,   128,
    1282,     0,    96,     0,     0,     0,     0,    96,    97,     0,
       0,     0,     0,    97,     0,  1306,  1307,     0,     0,     0,
       0,     0,     0,    96,   150,   151,   152,     0,  1311,    97,
     156,   157,   158,     0,   160,     0,   162,   163,   164,   464,
     465,   466,   467,   169,   170,   171,     0,     0,   174,     0,
     176,     0,   178,     0,     0,   180,   109,   182,     0,     0,
     184,   113,   491,   186,   187,     0,   188,   189,     0,   191,
       0,   193,     0,     0,   464,   465,   466,   467,   955,   196,
       0,   956,   115,     0,     0,     0,   454,   455,     0,     0,
       0,     0,     0,   456,   457,   458,   459,   460,   461,   462,
     463,     0,     0,     0,     0,     0,   206,   207,   464,   465,
     466,   467,     0,     0,   848,     0,   849,     0,     0,   218,
     643,     0,     0,     0,     0,     0,   989,   454,   455,     0,
       0,     0,     0,     0,   456,   457,   458,   459,   460,   461,
     462,   463,     0,   456,   457,   458,   459,   460,   461,   462,
     463,     0,     0,     0,     0,     0,   127,  1007,   128,  1009,
       0,   454,   455,     0,     0,     0,     0,     0,   456,   457,
     458,   459,   460,   461,   462,   463,     0,     0,     0,     0,
       0,     0,     0,   150,   151,   152,     0,     0,     0,   156,
     157,   158,     0,   160,     0,   162,   163,   164,     0,  1024,
       0,   109,   169,   170,   171,     0,   113,   174,     0,   176,
       0,   178,     0,     0,   180,     0,   182,  1026,  1027,   184,
       0,     0,   186,   187,  1028,   188,   189,   115,   191,     0,
     193,     0,     0,     0,     0,     0,     0,  1034,   196,     0,
    1036,     0,  1037,   464,   465,   466,   467,     0,     0,   870,
       0,   871,  1044,  1045,     0,     0,     0,     0,     0,     0,
     454,   455,     0,     0,     0,   206,   207,   456,   457,   458,
     459,   460,   461,   462,   463,     0,     0,     0,   218,   645,
    1062,     0,     0,  1064,   464,   465,   466,   467,     0,     0,
    1088,     0,  1089,   464,   465,   466,   467,     0,     0,     0,
       0,   127,     0,   128,     0,     0,  1080,  1081,  1082,     0,
       0,     0,     0,     0,     0,     0,  1090,  1091,   464,   465,
     466,   467,     0,     0,  1120,     0,  1121,     0,   150,   151,
     152,     0,     0,     0,   156,   157,   158,     0,   160,     0,
     162,   163,   164,     0,     0,     0,     0,   169,   170,   171,
       0,     0,   174,     0,   176,     0,   178,     0,     0,   180,
       0,   182,     0,     0,   184,     0,     0,   186,   187,     0,
     188,   189,     0,   191,     0,   193,     0,     0,     0,   454,
     455,     0,     0,   196,     0,   495,   456,   457,   458,   459,
     460,   461,   462,   463,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1170,     0,     0,     0,
     206,   207,     0,     0,     0,     0,     0,   464,   465,   466,
     467,     0,     0,   218,   647,   691,     0,     0,     0,     0,
       0,     0,   454,   455,     0,     0,     0,     0,  1189,   456,
     457,   458,   459,   460,   461,   462,   463,     0,     0,     0,
       0,     0,     0,  1192,     0,     0,     0,     0,     0,     0,
       0,     0,  1195,     0,     0,  1197,     0,     0,  1198,     0,
       0,     0,  1199,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1214,     0,     0,     0,     0,     0,     0,     0,     0,
    1220,  1221,  1222,  1223,     0,  1225,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   107,   108,   109,     0,   110,   111,   112,   113,     0,
       0,     0,     0,     0,     0,     0,   464,   465,   466,   467,
       0,     0,     0,     0,   788,     0,     0,     0,   114,   115,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   116,   117,   118,   119,   120,   121,   122,  1279,   464,
     465,   466,   467,  1283,     0,     0,     0,   796,     0,   123,
       0,     0,   124,     0,     0,     0,     0,   284,     0,     0,
       0,     0,     0,     0,     0,   285,     0,     0,     0,   125,
     126,     0,     0,   127,     0,   128,     0,  1310,   286,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,     0,
     179,   180,   181,   182,     0,   183,   184,     0,   185,   186,
     187,     0,   188,   189,   190,   191,   192,   193,   194,     0,
       0,     0,     0,     0,   195,   196,   197,     0,     0,     0,
     198,     0,     0,   199,     0,     0,   200,   201,   202,   203,
       0,   107,   108,   109,     0,   110,   111,   112,   113,     0,
     204,   205,   206,   207,     0,     0,   208,     0,   209,     0,
       0,     0,     0,   454,   455,   210,     0,   280,   114,   115,
     456,   457,   458,   459,   460,   461,   462,   463,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   116,   117,   118,   119,   120,   121,   122,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   123,
       0,     0,   124,     0,     0,     0,     0,   278,     0,     0,
       0,     0,     0,     0,     0,   279,     0,     0,     0,   125,
     126,     0,     0,   127,     0,   128,     0,     0,     0,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,     0,
     179,   180,   181,   182,     0,   183,   184,     0,   185,   186,
     187,     0,   188,   189,   190,   191,   192,   193,   194,     0,
     464,   465,   466,   467,   195,   196,   197,     0,   799,     0,
     198,     0,     0,   199,     0,     0,   200,   201,   202,   203,
       0,   107,   108,   109,     0,   110,   111,   112,   113,     0,
     204,   205,   206,   207,     0,     0,   208,     0,   209,     0,
       0,     0,     0,   454,   455,   210,     0,   280,   114,   115,
     456,   457,   458,   459,   460,   461,   462,   463,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   116,   117,   118,   119,   120,   121,   122,     0,     0,
       0,     0,     0,     0,     0,     0,   454,   455,     0,   123,
       0,     0,   124,   456,   457,   458,   459,   460,   461,   462,
     463,     0,     0,     0,     0,   590,     0,     0,     0,   125,
     126,     0,     0,   127,     0,   128,     0,     0,     0,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,     0,
     179,   180,   181,   182,     0,   183,   184,     0,   185,   186,
     187,     0,   188,   189,   190,   191,   192,   193,   194,     0,
     464,   465,   466,   467,   195,   196,   197,     0,   800,     0,
     198,     0,     0,   199,     0,     0,   200,   201,   202,   203,
       0,   107,   108,   109,     0,   110,   111,   112,   113,     0,
     204,   205,   206,   207,     0,     0,   208,     0,   209,     0,
       0,     0,     0,     0,     0,   210,     0,   280,   114,   115,
       0,     0,     0,   464,   465,   466,   467,     0,     0,     0,
       0,   804,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   116,   117,   118,   119,   120,   121,   122,     0,     0,
       0,     0,     0,     0,     0,     0,   454,   455,     0,   123,
       0,     0,   124,   456,   457,   458,   459,   460,   461,   462,
     463,     0,     0,     0,     0,     0,     0,     0,     0,   125,
     126,     0,     0,   127,     0,   128,     0,     0,     0,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,     0,
     179,   180,   181,   182,     0,   183,   184,     0,   185,   186,
     187,     0,   188,   189,   190,   191,   192,   193,   194,     0,
       0,     0,     0,     0,   195,   196,   197,     0,     0,     0,
     198,     0,     0,   199,     0,     0,   200,   201,   202,   203,
       0,   107,   108,   109,     0,   110,   111,   112,   113,     0,
     204,   205,   206,   207,     0,     0,   208,     0,   209,     0,
       0,     0,     0,     0,     0,   210,     0,   280,   114,   115,
       0,     0,     0,   464,   465,   466,   467,     0,     0,     0,
       0,   811,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   116,   117,   118,   119,   120,   121,   122,     0,     0,
       0,     0,     0,     0,     0,     0,   454,   455,     0,   123,
       0,     0,   124,   456,   457,   458,   459,   460,   461,   462,
     463,     0,     0,     0,     0,     0,     0,     0,     0,   125,
     126,     0,     0,   127,     0,   128,     0,     0,     0,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,     0,
     179,   180,   181,   182,     0,   183,   184,     0,   185,   186,
     187,     0,   188,   189,   190,   191,   192,   193,   194,     0,
       0,     0,     0,     0,   195,   196,   197,     0,     0,     0,
     198,     0,     0,   199,     0,     0,   200,   201,   202,   203,
     107,   108,   109,     0,   110,   111,   112,   113,     0,     0,
     204,   205,   206,   207,     0,     0,   208,     0,   209,     0,
       0,     0,     0,     0,     0,   210,   548,   114,   115,     0,
       0,     0,     0,   464,   465,   466,   467,     0,     0,     0,
       0,   823,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     116,   117,   118,   119,   120,   121,   122,     0,     0,     0,
       0,     0,     0,     0,     0,   454,   455,     0,   123,     0,
       0,   124,   456,   457,   458,   459,   460,   461,   462,   463,
       0,     0,     0,     0,     0,     0,     0,     0,   125,   126,
       0,     0,   127,     0,   128,     0,     0,     0,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,     0,   179,
     180,   181,   182,     0,   183,   184,     0,   185,   186,   187,
       0,   188,   189,   190,   191,   192,   193,   194,     0,     0,
       0,     0,     0,   195,   196,   197,     0,     0,     0,   198,
       0,     0,   199,     0,     0,   200,   201,   202,   203,   107,
     108,   109,     0,   110,   111,   112,   113,     0,     0,   204,
     205,   206,   207,     0,     0,   208,     0,   209,     0,     0,
       0,     0,     0,     0,   210,   621,   114,   115,     0,     0,
       0,     0,   464,   465,   466,   467,     0,     0,     0,     0,
     840,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   116,
     117,   118,   119,   120,   121,   122,     0,     0,     0,     0,
       0,     0,     0,     0,   454,   455,     0,   123,     0,     0,
     124,   456,   457,   458,   459,   460,   461,   462,   463,     0,
       0,     0,     0,     0,     0,     0,     0,   125,   126,     0,
       0,   127,     0,   128,     0,     0,     0,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,     0,   179,   180,
     181,   182,     0,   183,   184,     0,   185,   186,   187,     0,
     188,   189,   190,   191,   192,   193,   194,     0,     0,     0,
       0,     0,   195,   196,   197,     0,     0,     0,   198,     0,
       0,   199,     0,     0,   200,   201,   202,   203,   107,   108,
     109,     0,   110,   111,   112,   113,     0,   292,   204,   205,
     206,   207,     0,     0,   208,     0,   209,     0,     0,     0,
       0,     0,     0,   210,   632,   114,   115,     0,     0,     0,
       0,   464,   465,   466,   467,     0,     0,     0,     0,   841,
       0,     0,     0,     0,     0,     0,     0,     0,   293,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   116,   117,
     118,   119,   120,   121,   122,     0,     0,     0,     0,     0,
       0,     0,     0,   454,   455,     0,   123,     0,     0,   124,
     456,   457,   458,   459,   460,   461,   462,   463,     0,     0,
       0,     0,     0,     0,     0,     0,   125,   126,     0,     0,
     127,     0,   128,     0,     0,     0,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,     0,   179,   180,   181,
     182,     0,   183,   184,     0,   185,   186,   187,     0,   188,
     189,   190,   191,   192,   193,   194,     0,     0,     0,     0,
       0,   195,   196,   197,     0,     0,     0,   198,     0,     0,
     199,     0,     0,   200,   201,   202,   203,   107,   108,   109,
       0,   110,   111,   112,   113,     0,     0,   204,   205,   206,
     207,     0,     0,   208,     0,   209,     0,     0,     0,     0,
       0,     0,   210,     0,   114,   115,     0,     0,   237,     0,
     464,   465,   466,   467,     0,     0,     0,     0,   842,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   116,   117,   118,
     119,   120,   121,   122,     0,     0,     0,     0,     0,     0,
       0,     0,   454,   455,     0,   123,     0,     0,   124,   456,
     457,   458,   459,   460,   461,   462,   463,     0,     0,     0,
       0,     0,     0,     0,     0,   125,   126,     0,     0,   127,
       0,   128,     0,     0,     0,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,     0,   179,   180,   181,   182,
       0,   183,   184,     0,   185,   186,   187,     0,   188,   189,
     190,   191,   192,   193,   194,     0,     0,     0,     0,     0,
     195,   196,   197,     0,     0,     0,   198,     0,     0,   199,
       0,     0,   200,   201,   202,   203,   107,   108,   109,     0,
     110,   111,   112,   113,     0,   540,   204,   205,   206,   207,
       0,     0,   208,     0,   209,     0,     0,     0,     0,     0,
       0,   210,     0,   114,   115,     0,     0,     0,     0,   464,
     465,   466,   467,     0,     0,     0,     0,   843,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   116,   117,   118,   119,
     120,   121,   122,     0,     0,     0,     0,     0,     0,     0,
       0,   454,   455,     0,   123,     0,     0,   124,   456,   457,
     458,   459,   460,   461,   462,   463,     0,     0,     0,     0,
       0,     0,     0,     0,   125,   126,     0,     0,   127,     0,
     128,     0,     0,     0,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,     0,   179,   180,   181,   182,     0,
     183,   184,     0,   185,   186,   187,     0,   188,   189,   190,
     191,   192,   193,   194,     0,     0,     0,     0,     0,   195,
     196,   197,     0,     0,     0,   198,     0,     0,   199,     0,
       0,   200,   201,   202,   203,   107,   108,   109,     0,   110,
     111,   112,   113,     0,     0,   204,   205,   206,   207,     0,
       0,   208,     0,   209,     0,     0,     0,     0,     0,     0,
     210,     0,   114,   115,     0,     0,     0,     0,   464,   465,
     466,   467,     0,     0,     0,     0,   844,     0,   454,   455,
       0,     0,     0,     0,     0,   456,   457,   458,   459,   460,
     461,   462,   463,     0,     0,   116,   117,   118,   119,   120,
     121,   122,     0,     0,     0,     0,     0,     0,     0,     0,
     454,   455,     0,   123,     0,     0,   124,   456,   457,   458,
     459,   460,   461,   462,   463,     0,     0,     0,     0,     0,
       0,     0,     0,   125,   126,     0,     0,   127,     0,   128,
       0,     0,     0,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,     0,   179,   180,   181,   182,     0,   183,
     184,     0,   185,   186,   187,     0,   188,   189,   190,   191,
     192,   193,   194,     0,     0,     0,   109,     0,   195,   196,
     197,   113,     0,     0,   198,     0,     0,   199,     0,     0,
     200,   201,   202,   203,     0,   464,   465,   466,   467,     0,
       0,     0,   115,   847,   204,   205,   206,   207,     0,     0,
     208,     0,   209,     0,     0,     0,     0,     0,     0,   210,
       0,     0,     0,     0,     0,     0,     0,   464,   465,   466,
     467,     0,     0,     0,     0,   850,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   109,     0,     0,     0,     0,
     113,     0,     0,     0,     0,     0,     0,     0,   773,     0,
       0,     0,     0,     0,     0,     0,   127,     0,   128,     0,
       0,   115,   454,   455,     0,     0,     0,     0,     0,   456,
     457,   458,   459,   460,   461,   462,   463,     0,     0,     0,
       0,     0,     0,   150,   151,   152,     0,     0,     0,   156,
     157,   158,     0,   160,     0,   162,   163,   164,     0,     0,
       0,     0,   169,   170,   171,     0,     0,   174,     0,   176,
       0,   178,     0,   109,   180,     0,   182,     0,   113,   184,
       0,     0,   186,   187,     0,   188,   189,  1008,   191,     0,
     193,     0,     0,     0,     0,   127,     0,   128,   196,   115,
     454,   455,     0,     0,     0,     0,     0,   456,   457,   458,
     459,   460,   461,   462,   463,     0,     0,     0,     0,     0,
       0,     0,   150,   151,   152,   206,   207,     0,   156,   157,
     158,     0,   160,     0,   162,   163,   164,     0,   218,     0,
       0,   169,   170,   171,     0,     0,   174,     0,   176,     0,
     178,     0,   109,   180,     0,   182,     0,   113,   184,     0,
       0,   186,   187,     0,   188,   189,     0,   191,     0,   193,
       0,     0,     0,   127,     0,   128,     0,   196,   115,   464,
     465,   466,   467,   454,   455,     0,     0,   851,     0,     0,
     456,   457,   458,   459,   460,   461,   462,   463,     0,     0,
     150,   151,   152,     0,   206,   207,   156,   157,   158,     0,
     160,     0,   162,   163,   164,     0,     0,   218,     0,   169,
     170,   171,     0,     0,   174,     0,   176,     0,   178,     0,
       0,   180,     0,   182,     0,     0,   184,     0,     0,   186,
     187,     0,   188,   189,     0,   191,     0,   193,     0,     0,
       0,     0,   127,     0,   128,   196,     0,   464,   465,   466,
     467,   454,   455,     0,     0,   853,     0,     0,   456,   457,
     458,   459,   460,   461,   462,   463,     0,     0,     0,   150,
     151,   152,   206,   207,     0,   156,   157,   158,     0,   160,
       0,   162,   163,   164,     0,   218,     0,     0,   169,   170,
     171,     0,     0,   174,     0,   176,     0,   178,     0,     0,
     180,     0,   182,     0,     0,   184,     0,     0,   186,   187,
       0,   188,   189,     0,   191,     0,   193,     0,     0,     0,
       0,     0,     0,     0,   196,     0,     0,     0,     0,     0,
     464,   465,   466,   467,     0,     0,     0,     0,   854,     0,
       0,     0,     0,     7,     8,     9,     0,     0,     0,     0,
      10,   206,   207,     0,    11,     0,    12,     0,    13,    14,
      15,    16,    17,  -361,   954,    18,    19,    20,    21,    22,
      23,    24,    25,     0,    26,    27,    28,     0,     0,     0,
       0,    29,     0,     0,    30,     0,     0,     0,     0,     0,
       0,    31,    32,    33,    34,    35,    36,     0,     0,     0,
      37,    38,     0,     0,     0,     0,     0,     0,   464,   465,
     466,   467,     0,     0,     0,     0,   855,    39,    40,    41,
      42,    43,    44,     0,     0,     0,     0,     0,    45,    46,
      47,  -138,  -138,    48,    49,    50,     0,    51,    52,    53,
       0,     0,    54,  -138,     0,    55,     0,    56,    57,     0,
       0,     0,     0,     0,   454,   455,     0,     0,     0,     0,
       0,   456,   457,   458,   459,   460,   461,   462,   463,     0,
       0,    58,    59,    60,     0,   454,   455,     0,    61,     0,
       0,     0,   456,   457,   458,   459,   460,   461,   462,   463,
       0,     0,     0,     0,     0,     0,    62,     0,     0,     0,
      63,     0,     0,     0,     0,    64,   454,   455,    65,     0,
       0,     0,    66,   456,   457,   458,   459,   460,   461,   462,
     463,     0,     0,     0,     0,     0,     0,     0,    67,    68,
      69,     0,    70,    71,     0,    72,    73,     0,     0,     0,
       0,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,     0,     7,     8,     9,    84,    85,     0,    86,    10,
       0,     0,     0,    11,     0,    12,     0,    13,    14,    15,
      16,    17,  -361,     0,    18,    19,    20,    21,    22,    23,
      24,    25,     0,    26,    27,    28,     0,     0,     0,     0,
      29,   -16,   -16,    30,     0,     0,     0,     0,     0,     0,
      31,    32,    33,    34,    35,    36,     0,     0,     0,    37,
      38,   464,   465,   466,   467,     0,     0,     0,     0,   856,
       0,     0,     0,     0,     0,     0,    39,    40,    41,    42,
      43,    44,   464,   465,   466,   467,     0,    45,    46,    47,
     857,     0,    48,    49,    50,     0,    51,    52,    53,     0,
       0,    54,     0,     0,    55,     0,    56,    57,     0,     0,
       0,     0,     0,   464,   465,   466,   467,     0,     0,     0,
       0,   858,     0,     0,     0,     0,     0,     0,     0,     0,
      58,    59,    60,     0,   454,   455,     0,    61,     0,     0,
       0,   456,   457,   458,   459,   460,   461,   462,   463,     0,
       0,     0,     0,     0,     0,    62,     0,     0,     0,    63,
       0,     0,     0,     0,    64,   454,   455,    65,     0,     0,
       0,    66,   456,   457,   458,   459,   460,   461,   462,   463,
       0,     0,     0,     0,     0,     0,     0,    67,    68,    69,
       0,    70,    71,     0,    72,    73,     0,     0,     0,     0,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
       0,     7,     8,     9,    84,    85,     0,    86,    10,     0,
       0,     0,    11,     0,    12,     0,    13,    14,    15,    16,
      17,  -361,     0,    18,    19,    20,    21,    22,    23,    24,
      25,     0,    26,    27,    28,   -16,     0,     0,     0,    29,
     -16,     0,    30,     0,     0,     0,     0,     0,     0,    31,
      32,    33,    34,    35,    36,     0,     0,     0,    37,    38,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    39,    40,    41,    42,    43,
      44,   464,   465,   466,   467,     0,    45,    46,    47,   859,
       0,    48,    49,    50,     0,    51,    52,    53,     0,     0,
      54,     0,     0,    55,     0,    56,    57,     0,     0,     0,
       0,     0,   464,   465,   466,   467,     0,     0,     0,     0,
     861,     0,     0,     0,     0,     0,     0,     0,     0,    58,
      59,    60,   454,   455,     0,     0,    61,     0,     0,   456,
     457,   458,   459,   460,   461,   462,   463,     0,     0,     0,
       0,     0,     0,     0,    62,     0,     0,     0,    63,     0,
       0,     0,     0,    64,   454,   455,    65,     0,     0,     0,
      66,   456,   457,   458,   459,   460,   461,   462,   463,     0,
       0,     0,     0,     0,     0,     0,    67,    68,    69,     0,
      70,    71,     0,    72,    73,     0,     0,     0,     0,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,     0,
     454,   455,     0,    84,    85,     0,    86,   456,   457,   458,
     459,   460,   461,   462,   463,   454,   455,     0,     0,     0,
       0,     0,   456,   457,   458,   459,   460,   461,   462,   463,
     454,   455,     0,     0,     0,     0,     0,   456,   457,   458,
     459,   460,   461,   462,   463,   454,   455,     0,     0,     0,
       0,     0,   456,   457,   458,   459,   460,   461,   462,   463,
     454,   455,     0,     0,     0,     0,     0,   456,   457,   458,
     459,   460,   461,   462,   463,     0,     0,     0,     0,   464,
     465,   466,   467,   454,   455,     0,     0,   872,     0,     0,
     456,   457,   458,   459,   460,   461,   462,   463,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   464,   465,   466,   467,   454,   455,     0,     0,   873,
       0,     0,   456,   457,   458,   459,   460,   461,   462,   463,
     454,   455,     0,     0,     0,     0,     0,   456,   457,   458,
     459,   460,   461,   462,   463,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   464,   465,   466,
     467,     0,     0,     0,     0,   875,     0,     0,     0,     0,
       0,     0,   464,   465,   466,   467,     0,     0,     0,     0,
     878,     0,     0,     0,     0,     0,     0,   464,   465,   466,
     467,     0,     0,     0,     0,   900,     0,     0,     0,     0,
       0,     0,   464,   465,   466,   467,     0,     0,     0,     0,
     917,     0,     0,     0,     0,     0,     0,   464,   465,   466,
     467,   454,   455,     0,     0,   953,     0,     0,   456,   457,
     458,   459,   460,   461,   462,   463,     0,     0,     0,     0,
     464,   465,   466,   467,   454,   455,     0,     0,  1069,     0,
       0,   456,   457,   458,   459,   460,   461,   462,   463,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   464,   465,   466,   467,     0,     0,     0,     0,
    1086,     0,     0,     0,     0,     0,     0,   464,   465,   466,
     467,   454,   455,     0,     0,  1087,     0,     0,   456,   457,
     458,   459,   460,   461,   462,   463,   454,   455,     0,     0,
       0,     0,     0,   456,   457,   458,   459,   460,   461,   462,
     463,   454,   455,     0,     0,     0,     0,     0,   456,   457,
     458,   459,   460,   461,   462,   463,   454,   455,     0,     0,
       0,     0,     0,   456,   457,   458,   459,   460,   461,   462,
     463,   454,   455,     0,     0,     0,     0,     0,   456,   457,
     458,   459,   460,   461,   462,   463,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   464,   465,
     466,   467,   454,   455,     0,     0,  1097,     0,     0,   456,
     457,   458,   459,   460,   461,   462,   463,     0,     0,     0,
       0,   464,   465,   466,   467,   454,   455,     0,     0,  1102,
       0,     0,   456,   457,   458,   459,   460,   461,   462,   463,
     454,   455,     0,     0,     0,     0,     0,   456,   457,   458,
     459,   460,   461,   462,   463,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   464,   465,
     466,   467,     0,     0,     0,     0,  1103,     0,     0,     0,
       0,     0,     0,   464,   465,   466,   467,     0,     0,     0,
       0,  1104,     0,     0,     0,     0,     0,     0,   464,   465,
     466,   467,     0,     0,     0,     0,  1105,     0,     0,     0,
       0,     0,     0,   464,   465,   466,   467,     0,     0,     0,
       0,  1106,     0,     0,     0,     0,     0,     0,   464,   465,
     466,   467,   454,   455,     0,     0,  1111,     0,     0,   456,
     457,   458,   459,   460,   461,   462,   463,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   464,
     465,   466,   467,   454,   455,     0,     0,  1112,     0,     0,
     456,   457,   458,   459,   460,   461,   462,   463,     0,     0,
       0,     0,   464,   465,   466,   467,     0,     0,     0,     0,
    1115,     0,     0,     0,     0,     0,     0,   464,   465,   466,
     467,   454,   455,     0,     0,  1116,     0,     0,   456,   457,
     458,   459,   460,   461,   462,   463,   454,   455,     0,     0,
       0,     0,     0,   456,   457,   458,   459,   460,   461,   462,
     463,   454,   455,     0,     0,     0,     0,     0,   456,   457,
     458,   459,   460,   461,   462,   463,   454,   455,     0,     0,
       0,     0,     0,   456,   457,   458,   459,   460,   461,   462,
     463,   454,   455,     0,     0,     0,     0,     0,   456,   457,
     458,   459,   460,   461,   462,   463,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   464,
     465,   466,   467,   454,   455,     0,     0,  1117,     0,     0,
     456,   457,   458,   459,   460,   461,   462,   463,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     464,   465,   466,   467,   454,   455,     0,     0,  1118,     0,
       0,   456,   457,   458,   459,   460,   461,   462,   463,   454,
     455,     0,     0,     0,     0,     0,   456,   457,   458,   459,
     460,   461,   462,   463,     0,     0,     0,     0,   464,   465,
     466,   467,     0,     0,     0,     0,  1119,     0,     0,     0,
       0,     0,     0,   464,   465,   466,   467,     0,     0,     0,
       0,  1122,     0,     0,     0,     0,     0,     0,   464,   465,
     466,   467,     0,     0,     0,     0,  1123,     0,     0,     0,
       0,     0,     0,   464,   465,   466,   467,     0,     0,     0,
       0,  1126,     0,     0,     0,     0,     0,     0,   464,   465,
     466,   467,   454,   455,     0,     0,  1132,     0,     0,   456,
     457,   458,   459,   460,   461,   462,   463,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     464,   465,   466,   467,   454,   455,     0,     0,  1135,     0,
       0,   456,   457,   458,   459,   460,   461,   462,   463,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   464,   465,   466,   467,     0,     0,     0,     0,  1146,
       0,     0,     0,     0,     0,     0,   464,   465,   466,   467,
     454,   455,     0,     0,  1158,     0,     0,   456,   457,   458,
     459,   460,   461,   462,   463,   454,   455,     0,     0,     0,
       0,     0,   456,   457,   458,   459,   460,   461,   462,   463,
     454,   455,     0,     0,     0,     0,     0,   456,   457,   458,
     459,   460,   461,   462,   463,   454,   455,     0,     0,     0,
       0,     0,   456,   457,   458,   459,   460,   461,   462,   463,
     454,   455,     0,     0,     0,     0,     0,   456,   457,   458,
     459,   460,   461,   462,   463,     0,     0,     0,     0,   464,
     465,   466,   467,   454,   455,     0,     0,  1211,     0,     0,
     456,   457,   458,   459,   460,   461,   462,   463,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   464,   465,   466,   467,   454,   455,     0,     0,  1215,
       0,     0,   456,   457,   458,   459,   460,   461,   462,   463,
     454,   455,     0,     0,     0,     0,     0,   456,   457,   458,
     459,   460,   461,   462,   463,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   464,   465,   466,
     467,     0,     0,     0,     0,  1224,     0,     0,     0,     0,
       0,     0,   464,   465,   466,   467,     0,     0,     0,     0,
    1227,     0,     0,     0,     0,     0,     0,   464,   465,   466,
     467,     0,     0,     0,     0,  1228,     0,     0,     0,     0,
       0,     0,   464,   465,   466,   467,     0,     0,     0,     0,
    1230,     0,     0,     0,     0,     0,     0,   464,   465,   466,
     467,   454,   455,     0,     0,  1231,     0,     0,   456,   457,
     458,   459,   460,   461,   462,   463,     0,     0,     0,     0,
     464,   465,   466,   467,   454,   455,     0,     0,  1232,     0,
       0,   456,   457,   458,   459,   460,   461,   462,   463,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   464,   465,   466,   467,     0,     0,     0,     0,
    1239,     0,     0,     0,     0,     0,     0,   464,   465,   466,
     467,   454,   455,     0,     0,  1241,     0,     0,   456,   457,
     458,   459,   460,   461,   462,   463,   454,   455,     0,     0,
       0,     0,     0,   456,   457,   458,   459,   460,   461,   462,
     463,   454,   455,     0,     0,     0,     0,     0,   456,   457,
     458,   459,   460,   461,   462,   463,   454,   455,     0,     0,
       0,     0,     0,   456,   457,   458,   459,   460,   461,   462,
     463,   454,   455,     0,     0,     0,     0,     0,   456,   457,
     458,   459,   460,   461,   462,   463,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   464,   465,
     466,   467,   454,   455,     0,     0,  1242,     0,     0,   456,
     457,   458,   459,   460,   461,   462,   463,     0,     0,     0,
       0,   464,   465,   466,   467,   454,   455,     0,     0,  1244,
       0,     0,   456,   457,   458,   459,   460,   461,   462,   463,
     454,   455,     0,     0,     0,     0,     0,   456,   457,   458,
     459,   460,   461,   462,   463,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   464,   465,
     466,   467,     0,     0,     0,     0,  1248,     0,     0,     0,
       0,     0,     0,   464,   465,   466,   467,     0,     0,     0,
       0,  1249,     0,     0,     0,     0,     0,     0,   464,   465,
     466,   467,     0,     0,     0,     0,  1284,     0,     0,     0,
       0,     0,     0,   464,   465,   466,   467,     0,     0,     0,
       0,  1286,     0,     0,     0,     0,     0,     0,   464,   465,
     466,   467,   454,   455,     0,     0,  1301,     0,     0,   456,
     457,   458,   459,   460,   461,   462,   463,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   464,
     465,   466,   467,   454,   455,     0,     0,  1312,     0,     0,
     456,   457,   458,   459,   460,   461,   462,   463,     0,     0,
       0,     0,   464,   465,   466,   467,     0,     0,     0,     0,
    1313,     0,     0,     0,     0,     0,     0,   464,   465,   466,
     467,   454,   455,     0,     0,  1323,     0,     0,   456,   457,
     458,   459,   460,   461,   462,   463,   454,   455,     0,     0,
       0,     0,     0,   456,   457,   458,   459,   460,   461,   462,
     463,   454,   455,     0,     0,     0,     0,     0,   456,   457,
     458,   459,   460,   461,   462,   463,   454,   455,     0,     0,
       0,     0,     0,   456,   457,   458,   459,   460,   461,   462,
     463,   454,   455,     0,     0,     0,     0,     0,   456,   457,
     458,   459,   460,   461,   462,   463,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   464,
     465,   466,   467,   454,   455,   517,     0,     0,     0,     0,
     456,   457,   458,   459,   460,   461,   462,   463,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     464,   465,   466,   467,   454,   455,   518,     0,     0,     0,
       0,   456,   457,   458,   459,   460,   461,   462,   463,   454,
     455,     0,     0,     0,     0,     0,   456,   457,   458,   459,
     460,   461,   462,   463,     0,     0,     0,     0,   464,   465,
     466,   467,     0,     0,   532,     0,     0,     0,     0,     0,
       0,     0,     0,   464,   465,   466,   467,     0,     0,   770,
       0,     0,     0,     0,     0,     0,     0,     0,   464,   465,
     466,   467,     0,     0,   797,     0,     0,     0,     0,     0,
       0,     0,     0,   464,   465,   466,   467,     0,     0,   798,
       0,     0,     0,     0,     0,     0,     0,     0,   464,   465,
     466,   467,   454,   455,   803,     0,     0,     0,     0,   456,
     457,   458,   459,   460,   461,   462,   463,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     464,   465,   466,   467,   454,   455,   806,     0,     0,     0,
       0,   456,   457,   458,   459,   460,   461,   462,   463,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   464,   465,   466,   467,     0,     0,   809,     0,     0,
       0,     0,     0,     0,     0,     0,   464,   465,   466,   467,
     454,   455,   821,     0,     0,     0,     0,   456,   457,   458,
     459,   460,   461,   462,   463,   454,   455,     0,     0,     0,
       0,     0,   456,   457,   458,   459,   460,   461,   462,   463,
     454,   455,     0,     0,     0,     0,     0,   456,   457,   458,
     459,   460,   461,   462,   463,   454,   455,     0,     0,     0,
       0,     0,   456,   457,   458,   459,   460,   461,   462,   463,
     454,   455,     0,     0,     0,     0,     0,   456,   457,   458,
     459,   460,   461,   462,   463,     0,     0,     0,     0,   464,
     465,   466,   467,   454,   455,   822,     0,     0,     0,     0,
     456,   457,   458,   459,   460,   461,   462,   463,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   464,   465,   466,   467,   454,   455,   824,     0,     0,
       0,     0,   456,   457,   458,   459,   460,   461,   462,   463,
     454,   455,     0,     0,     0,     0,     0,   456,   457,   458,
     459,   460,   461,   462,   463,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   464,   465,   466,
     467,     0,     0,   825,     0,     0,     0,     0,     0,     0,
       0,     0,   464,   465,   466,   467,     0,     0,   826,     0,
       0,     0,     0,     0,     0,     0,     0,   464,   465,   466,
     467,     0,     0,   839,     0,     0,     0,     0,     0,     0,
       0,     0,   464,   465,   466,   467,     0,     0,   860,     0,
       0,     0,     0,     0,     0,     0,     0,   464,   465,   466,
     467,   454,   455,   867,     0,     0,     0,     0,   456,   457,
     458,   459,   460,   461,   462,   463,     0,     0,     0,     0,
     464,   465,   466,   467,   454,   455,   868,     0,     0,     0,
       0,   456,   457,   458,   459,   460,   461,   462,   463,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   464,   465,   466,   467,     0,     0,   916,     0,
       0,     0,     0,     0,     0,     0,     0,   464,   465,   466,
     467,   454,   455,   922,     0,     0,     0,     0,   456,   457,
     458,   459,   460,   461,   462,   463,   454,   455,     0,     0,
       0,     0,     0,   456,   457,   458,   459,   460,   461,   462,
     463,   454,   455,     0,     0,     0,     0,     0,   456,   457,
     458,   459,   460,   461,   462,   463,   454,   455,     0,     0,
       0,     0,     0,   456,   457,   458,   459,   460,   461,   462,
     463,   454,   455,     0,     0,     0,     0,     0,   456,   457,
     458,   459,   460,   461,   462,   463,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   464,   465,
     466,   467,   454,   455,   949,     0,     0,     0,     0,   456,
     457,   458,   459,   460,   461,   462,   463,     0,     0,     0,
       0,   464,   465,   466,   467,   454,   455,   970,     0,     0,
       0,     0,   456,   457,   458,   459,   460,   461,   462,   463,
     454,   455,     0,     0,     0,     0,     0,   456,   457,   458,
     459,   460,   461,   462,   463,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   464,   465,
     466,   467,     0,     0,   971,     0,     0,     0,     0,     0,
       0,     0,     0,   464,   465,   466,   467,     0,     0,   978,
       0,     0,     0,     0,     0,     0,     0,     0,   464,   465,
     466,   467,     0,     0,   981,     0,     0,     0,     0,     0,
       0,     0,     0,   464,   465,   466,   467,     0,     0,   982,
       0,     0,     0,     0,     0,     0,     0,     0,   464,   465,
     466,   467,   454,   455,   987,     0,     0,     0,     0,   456,
     457,   458,   459,   460,   461,   462,   463,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   464,
     465,   466,   467,   454,   455,   988,     0,     0,     0,     0,
     456,   457,   458,   459,   460,   461,   462,   463,     0,     0,
       0,     0,   464,   465,   466,   467,     0,     0,  1061,     0,
       0,     0,     0,     0,     0,     0,     0,   464,   465,   466,
     467,   454,   455,  1066,     0,     0,     0,     0,   456,   457,
     458,   459,   460,   461,   462,   463,   454,   455,     0,     0,
       0,     0,     0,   456,   457,   458,   459,   460,   461,   462,
     463,   454,   455,     0,     0,     0,     0,     0,   456,   457,
     458,   459,   460,   461,   462,   463,   454,   455,     0,     0,
       0,     0,     0,   456,   457,   458,   459,   460,   461,   462,
     463,   454,   455,     0,     0,     0,     0,     0,   456,   457,
     458,   459,   460,   461,   462,   463,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   464,
     465,   466,   467,   454,   455,  1077,     0,     0,     0,     0,
     456,   457,   458,   459,   460,   461,   462,   463,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     464,   465,   466,   467,   454,   455,  1093,     0,     0,     0,
       0,   456,   457,   458,   459,   460,   461,   462,   463,   454,
     455,     0,     0,     0,     0,     0,   456,   457,   458,   459,
     460,   461,   462,   463,     0,     0,     0,     0,   464,   465,
     466,   467,     0,     0,  1094,     0,     0,     0,     0,     0,
       0,     0,     0,   464,   465,   466,   467,     0,     0,  1095,
       0,     0,     0,     0,     0,     0,     0,     0,   464,   465,
     466,   467,     0,     0,  1096,     0,     0,     0,     0,     0,
       0,     0,     0,   464,   465,   466,   467,     0,     0,  1098,
       0,     0,     0,     0,     0,     0,     0,     0,   464,   465,
     466,   467,   454,   455,  1099,     0,     0,     0,     0,   456,
     457,   458,   459,   460,   461,   462,   463,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     464,   465,   466,   467,   454,   455,  1133,     0,     0,     0,
       0,   456,   457,   458,   459,   460,   461,   462,   463,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   464,   465,   466,   467,     0,     0,  1134,     0,     0,
       0,     0,     0,     0,     0,     0,   464,   465,   466,   467,
     454,   455,  1143,     0,     0,     0,     0,   456,   457,   458,
     459,   460,   461,   462,   463,   454,   455,     0,     0,     0,
       0,     0,   456,   457,   458,   459,   460,   461,   462,   463,
     454,   455,     0,     0,     0,     0,     0,   456,   457,   458,
     459,   460,   461,   462,   463,   454,   455,     0,     0,     0,
       0,     0,   456,   457,   458,   459,   460,   461,   462,   463,
     454,   455,     0,     0,     0,     0,     0,   456,   457,   458,
     459,   460,   461,   462,   463,     0,     0,     0,     0,   464,
     465,   466,   467,   454,   455,  1144,     0,     0,     0,     0,
     456,   457,   458,   459,   460,   461,   462,   463,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   464,   465,   466,   467,   454,   455,  1145,     0,     0,
       0,     0,   456,   457,   458,   459,   460,   461,   462,   463,
     454,   455,     0,     0,     0,     0,     0,   456,   457,   458,
     459,   460,   461,   462,   463,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   464,   465,   466,
     467,     0,     0,  1147,     0,     0,     0,     0,     0,     0,
       0,     0,   464,   465,   466,   467,     0,     0,  1148,     0,
       0,     0,     0,     0,     0,     0,     0,   464,   465,   466,
     467,     0,     0,  1172,     0,     0,     0,     0,     0,     0,
       0,     0,   464,   465,   466,   467,     0,     0,  1229,     0,
       0,     0,     0,     0,     0,     0,     0,   464,   465,   466,
     467,   454,   455,  1238,     0,     0,     0,     0,   456,   457,
     458,   459,   460,   461,   462,   463,     0,     0,     0,     0,
     464,   465,   466,   467,   454,   455,  1250,     0,     0,     0,
       0,   456,   457,   458,   459,   460,   461,   462,   463,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   464,   465,   466,   467,     0,     0,  1251,     0,
       0,     0,     0,     0,     0,     0,     0,   464,   465,   466,
     467,   454,   455,  1261,     0,     0,     0,     0,   456,   457,
     458,   459,   460,   461,   462,   463,   454,   455,     0,     0,
       0,     0,     0,   456,   457,   458,   459,   460,   461,   462,
     463,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   464,   465,
     466,   467,     0,     0,  1287,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   464,   465,   466,   467,     0,     0,  1288,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   464,   465,
     466,   467,     0,     0,  1300,     0,     0,     0,     0,     0,
       0,     0,     0,   464,   465,   466,   467
};

static const yytype_int16 yycheck[] =
{
       2,   306,   307,    12,     1,   359,    40,     4,   959,   960,
       1,    12,    44,     4,    58,    17,    11,    15,    16,     4,
      77,     5,     7,    75,     4,     0,    10,     7,    30,    28,
      58,    33,    60,    61,    36,    37,    38,    77,    16,     7,
      42,    43,    44,    41,    75,    28,   231,    31,     3,    51,
      33,    88,     7,     8,     9,    10,    53,   310,   311,    95,
     221,    63,    53,     3,   249,   226,    44,     7,     8,     9,
      10,    25,    44,   227,    12,    70,    71,    72,    73,    74,
      75,    76,    70,    71,    72,    73,    74,    75,    76,   221,
      44,    63,    64,   226,   226,   228,   228,   110,    70,    71,
      72,    73,    74,    75,    76,    77,    92,    93,    43,    44,
      76,    77,   221,     4,     5,   221,   118,   226,   104,   228,
     226,   105,   228,   107,   221,    63,    64,     4,    63,   226,
       7,   228,    70,    71,    72,    73,    74,    75,    76,    77,
      70,    71,    72,    73,    74,    75,    76,   227,   132,   133,
     134,   226,   221,   228,   138,   139,   140,   226,   142,   228,
     144,   145,   146,   220,   221,   222,   223,   151,   152,   153,
      44,   424,   156,   426,   158,   227,   160,    23,   226,   163,
     228,   165,   222,   223,   168,   229,   227,   171,   172,   221,
     174,   175,   221,   177,   227,   179,   227,   226,    47,    48,
     221,   229,    14,   187,    16,   226,    18,   209,   210,     4,
       5,   221,   221,  1164,   221,   221,  1167,   226,   228,   226,
     226,   228,   228,   225,   227,   226,   221,   227,   230,    41,
     214,   215,    44,   221,   231,   227,   541,    49,   272,   273,
     231,   243,   227,   227,   228,   227,   248,   227,   220,   221,
     222,   223,   249,   255,   220,   221,   222,   223,   249,    75,
      76,    77,   226,    44,   228,   220,   221,    73,    74,    75,
      76,    77,   577,   578,   227,    59,   278,   227,   280,   221,
     220,   221,   220,   221,   222,   223,   228,   221,   226,    24,
     221,   221,   226,    75,   228,   600,   226,   228,   228,    74,
      75,    76,    77,     4,     5,    89,    90,    91,   221,   221,
     312,   227,    96,   226,   226,   500,   228,   319,   320,   321,
     322,   323,   221,   221,   326,   221,   328,   226,   330,   228,
     228,  1282,   228,   227,   336,    71,   338,    73,    74,    75,
      76,    77,   344,     4,     5,    35,    36,   349,   350,   221,
     352,   353,   354,   355,   356,   357,   228,     4,     5,   361,
     362,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,   375,   376,   377,   378,   379,   380,   381,
     226,    44,   228,   221,   227,   387,   388,   389,   390,   391,
     228,   393,   226,   395,   228,   227,    70,    71,    72,    73,
      74,    75,    76,   221,   220,   221,   222,   223,   410,    75,
     228,     4,   221,   415,   220,   221,   222,   223,    12,   228,
     221,   356,   357,   221,     4,     5,    58,   228,   430,   431,
     228,   132,   133,   134,   436,   221,   221,   372,   227,   100,
     227,   226,   228,   292,   221,   220,   221,   222,   223,   298,
     299,   228,     4,     5,   456,   457,   458,   459,   460,   461,
     462,   463,   464,   465,   466,   467,   227,   221,   227,    63,
      64,   132,   133,   134,   228,   410,    70,    71,    72,    73,
      74,    75,    76,    77,   220,   221,   222,   223,   221,   227,
     524,   228,   341,   342,   343,   228,    14,   227,    16,   501,
      18,   347,   348,   500,   506,   227,   221,   227,    14,   500,
      16,   360,    18,   228,    13,   517,   518,   221,   221,   225,
     226,   221,   221,    41,   228,   228,    44,   221,   530,   228,
     532,    49,   717,   226,   228,    41,    20,    21,    44,   221,
     542,   543,   227,    49,     4,     5,   228,   221,   221,   551,
     552,   553,   554,   907,   228,   228,   910,    70,    71,    72,
      73,    74,    75,    76,    63,    64,   412,   413,   227,    86,
      87,    70,    71,    72,    73,    74,    75,    76,    77,    63,
      64,    46,     4,     5,     4,     5,    70,    71,    72,    73,
      74,    75,    76,    77,   221,   221,   221,   221,    63,    64,
     226,   228,     3,   228,   228,    70,    71,    72,    73,    74,
      75,    76,    77,    70,    71,    72,    73,    74,    75,    76,
      21,    39,    40,    24,   221,   221,   220,   221,   222,   223,
     226,   228,    33,   221,   221,    63,    37,    38,   227,   226,
     228,    42,    70,    71,    72,    73,    74,    75,    76,    77,
     221,   221,   221,    54,    55,    56,   226,   228,    51,   228,
     221,   221,    63,    64,    65,    66,   226,   228,   514,   515,
      63,    64,   227,   519,   520,    49,    50,    70,    71,    72,
      73,    74,    75,    76,    77,   221,   221,   227,   537,   221,
     221,   540,   228,   228,   999,     5,   228,   228,   700,   701,
      70,    71,    72,    73,    74,    75,    76,   221,   221,   221,
    1015,   227,   221,   228,   228,   228,   228,   227,   720,   228,
     717,   220,   221,   222,   223,   221,   717,   725,   726,     4,
       5,   733,   228,   221,   221,   221,   220,   221,   222,   223,
     228,   228,   228,    14,   746,    16,   221,    18,    60,    61,
     752,   753,   221,   228,   756,   220,   221,   222,   223,   228,
     945,     3,   228,   227,   221,     7,     8,     9,   770,   221,
      41,   228,   221,    44,   226,   221,   221,   226,    49,   227,
     226,   226,   221,   785,   786,   787,   221,   226,   228,   227,
     227,   226,   220,   221,   222,   223,   798,   221,   227,   226,
     802,   803,   226,   805,   806,   221,   808,   809,   221,   210,
     226,   813,   227,   226,   226,   812,   227,   218,   227,   821,
     822,   812,   824,   825,   826,   227,   227,   220,   221,   222,
     223,   221,   227,   221,   836,   837,   226,   839,   226,   221,
     221,   227,   243,   845,   226,   226,   848,   248,   221,   227,
     221,   221,   221,   226,   255,   226,   226,   226,   860,   227,
     227,   863,   864,   865,   227,   867,   868,   181,   182,   183,
     184,   185,   227,   227,   876,   227,   227,   227,   279,   227,
     227,   727,   728,   227,   730,   731,   227,   227,   289,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     902,   227,   904,   905,   906,   227,   227,   227,   227,   227,
     227,   227,   313,   226,   916,   226,   918,   919,   920,   921,
     922,   227,   227,   324,   325,   227,   227,   929,   329,   227,
     227,   332,   781,   334,   227,   227,   337,   227,   784,   227,
     227,   227,   227,   227,   345,   227,   227,   949,   945,   227,
      63,    64,    43,   227,   945,   356,   226,    70,    71,    72,
      73,    74,    75,    76,    77,   814,   815,   227,   970,   971,
     227,   227,   227,   975,   976,   227,   227,   227,   227,   981,
     982,   382,   383,   384,   385,   386,   227,   227,   389,   838,
     227,   392,   227,   394,   227,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   409,   410,
     411,   227,   227,   414,   227,   416,   417,   418,   419,   420,
    1205,  1206,   423,   227,   425,   227,   427,   428,   429,   227,
     227,   432,   433,   434,   435,   227,   437,   438,   439,   440,
     975,   976,   227,   227,   445,   446,   447,   448,   449,   450,
     451,   452,  1050,  1051,  1056,   227,   227,   227,   227,  1061,
     227,   227,   227,   227,  1066,   227,   227,   227,   227,   227,
     226,   228,  1257,   228,   228,    77,   228,   228,    75,   227,
     227,   226,    43,   227,  1269,   227,  1088,   226,   226,  1274,
      46,  1093,  1094,  1095,  1096,   227,  1098,  1099,   227,   227,
      10,   226,   503,   226,   226,  1290,   226,   220,   221,   222,
     223,   228,  1114,   226,   228,   228,   228,   226,  1120,   226,
     228,   227,   968,   969,   227,  1127,   228,  1129,   529,   228,
     226,   228,  1134,   228,   228,   228,    43,   538,   228,   228,
     227,   227,  1144,  1145,   228,  1147,  1148,   228,    85,  1151,
     551,   552,    85,   228,   228,     5,   226,   226,    58,  1161,
      71,    72,    73,    74,    75,    76,    77,     5,   228,   228,
      46,   228,    10,   228,   227,  1177,   227,   226,   228,   227,
      43,   228,   228,    38,    43,   227,    75,    63,    64,   228,
     228,    75,    75,    31,    70,    71,    72,    73,    74,    75,
      76,    77,    48,   228,    58,  1207,   228,   227,  1205,  1206,
     227,    47,   227,   227,  1205,  1206,   228,    75,   228,    38,
       4,    63,    64,     4,  1070,  1071,   812,  1229,    70,    71,
      72,    73,    74,    75,    76,    77,  1238,    53,    53,   733,
     359,   524,     5,   732,   729,  1235,  1056,  1321,  1250,  1251,
    1252,  1100,   521,    -1,   534,   957,    -1,    -1,  1260,  1261,
    1257,    -1,    -1,    -1,    -1,    -1,  1257,   105,    -1,   107,
    1263,    -1,  1269,    -1,    -1,    -1,    -1,  1274,  1269,    -1,
      -1,    -1,    -1,  1274,    -1,  1287,  1288,    -1,    -1,    -1,
      -1,    -1,    -1,  1290,   132,   133,   134,    -1,  1300,  1290,
     138,   139,   140,    -1,   142,    -1,   144,   145,   146,   220,
     221,   222,   223,   151,   152,   153,    -1,    -1,   156,    -1,
     158,    -1,   160,    -1,    -1,   163,     5,   165,    -1,    -1,
     168,    10,   733,   171,   172,    -1,   174,   175,    -1,   177,
      -1,   179,    -1,    -1,   220,   221,   222,   223,   749,   187,
      -1,   752,    31,    -1,    -1,    -1,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,    -1,    -1,    -1,   214,   215,   220,   221,
     222,   223,    -1,    -1,   226,    -1,   228,    -1,    -1,   227,
     228,    -1,    -1,    -1,    -1,    -1,   797,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,    -1,    -1,    -1,   105,   828,   107,   830,
      -1,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   132,   133,   134,    -1,    -1,    -1,   138,
     139,   140,    -1,   142,    -1,   144,   145,   146,    -1,   870,
      -1,     5,   151,   152,   153,    -1,    10,   156,    -1,   158,
      -1,   160,    -1,    -1,   163,    -1,   165,   888,   889,   168,
      -1,    -1,   171,   172,   895,   174,   175,    31,   177,    -1,
     179,    -1,    -1,    -1,    -1,    -1,    -1,   908,   187,    -1,
     911,    -1,   913,   220,   221,   222,   223,    -1,    -1,   226,
      -1,   228,   923,   924,    -1,    -1,    -1,    -1,    -1,    -1,
      63,    64,    -1,    -1,    -1,   214,   215,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,   227,   228,
     951,    -1,    -1,   954,   220,   221,   222,   223,    -1,    -1,
     226,    -1,   228,   220,   221,   222,   223,    -1,    -1,    -1,
      -1,   105,    -1,   107,    -1,    -1,   977,   978,   979,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   987,   988,   220,   221,
     222,   223,    -1,    -1,   226,    -1,   228,    -1,   132,   133,
     134,    -1,    -1,    -1,   138,   139,   140,    -1,   142,    -1,
     144,   145,   146,    -1,    -1,    -1,    -1,   151,   152,   153,
      -1,    -1,   156,    -1,   158,    -1,   160,    -1,    -1,   163,
      -1,   165,    -1,    -1,   168,    -1,    -1,   171,   172,    -1,
     174,   175,    -1,   177,    -1,   179,    -1,    -1,    -1,    63,
      64,    -1,    -1,   187,    -1,  1056,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1077,    -1,    -1,    -1,
     214,   215,    -1,    -1,    -1,    -1,    -1,   220,   221,   222,
     223,    -1,    -1,   227,   228,   228,    -1,    -1,    -1,    -1,
      -1,    -1,    63,    64,    -1,    -1,    -1,    -1,  1109,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,  1124,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1133,    -1,    -1,  1136,    -1,    -1,  1139,    -1,
      -1,    -1,  1143,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1162,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1171,  1172,  1173,  1174,    -1,  1176,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,    -1,     7,     8,     9,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   220,   221,   222,   223,
      -1,    -1,    -1,    -1,   228,    -1,    -1,    -1,    30,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    64,    65,    66,    67,    68,    69,  1259,   220,
     221,   222,   223,  1264,    -1,    -1,    -1,   228,    -1,    81,
      -1,    -1,    84,    -1,    -1,    -1,    -1,    89,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    97,    -1,    -1,    -1,   101,
     102,    -1,    -1,   105,    -1,   107,    -1,  1298,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,    -1,
     162,   163,   164,   165,    -1,   167,   168,    -1,   170,   171,
     172,    -1,   174,   175,   176,   177,   178,   179,   180,    -1,
      -1,    -1,    -1,    -1,   186,   187,   188,    -1,    -1,    -1,
     192,    -1,    -1,   195,    -1,    -1,   198,   199,   200,   201,
      -1,     3,     4,     5,    -1,     7,     8,     9,    10,    -1,
     212,   213,   214,   215,    -1,    -1,   218,    -1,   220,    -1,
      -1,    -1,    -1,    63,    64,   227,    -1,   229,    30,    31,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    64,    65,    66,    67,    68,    69,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,
      -1,    -1,    84,    -1,    -1,    -1,    -1,    89,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    97,    -1,    -1,    -1,   101,
     102,    -1,    -1,   105,    -1,   107,    -1,    -1,    -1,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,    -1,
     162,   163,   164,   165,    -1,   167,   168,    -1,   170,   171,
     172,    -1,   174,   175,   176,   177,   178,   179,   180,    -1,
     220,   221,   222,   223,   186,   187,   188,    -1,   228,    -1,
     192,    -1,    -1,   195,    -1,    -1,   198,   199,   200,   201,
      -1,     3,     4,     5,    -1,     7,     8,     9,    10,    -1,
     212,   213,   214,   215,    -1,    -1,   218,    -1,   220,    -1,
      -1,    -1,    -1,    63,    64,   227,    -1,   229,    30,    31,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    64,    65,    66,    67,    68,    69,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    -1,    81,
      -1,    -1,    84,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,    -1,    -1,    97,    -1,    -1,    -1,   101,
     102,    -1,    -1,   105,    -1,   107,    -1,    -1,    -1,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,    -1,
     162,   163,   164,   165,    -1,   167,   168,    -1,   170,   171,
     172,    -1,   174,   175,   176,   177,   178,   179,   180,    -1,
     220,   221,   222,   223,   186,   187,   188,    -1,   228,    -1,
     192,    -1,    -1,   195,    -1,    -1,   198,   199,   200,   201,
      -1,     3,     4,     5,    -1,     7,     8,     9,    10,    -1,
     212,   213,   214,   215,    -1,    -1,   218,    -1,   220,    -1,
      -1,    -1,    -1,    -1,    -1,   227,    -1,   229,    30,    31,
      -1,    -1,    -1,   220,   221,   222,   223,    -1,    -1,    -1,
      -1,   228,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,   186,   187,   188,    -1,    -1,    -1,
     192,    -1,    -1,   195,    -1,    -1,   198,   199,   200,   201,
      -1,     3,     4,     5,    -1,     7,     8,     9,    10,    -1,
     212,   213,   214,   215,    -1,    -1,   218,    -1,   220,    -1,
      -1,    -1,    -1,    -1,    -1,   227,    -1,   229,    30,    31,
      -1,    -1,    -1,   220,   221,   222,   223,    -1,    -1,    -1,
      -1,   228,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,   186,   187,   188,    -1,    -1,    -1,
     192,    -1,    -1,   195,    -1,    -1,   198,   199,   200,   201,
       3,     4,     5,    -1,     7,     8,     9,    10,    -1,    -1,
     212,   213,   214,   215,    -1,    -1,   218,    -1,   220,    -1,
      -1,    -1,    -1,    -1,    -1,   227,   228,    30,    31,    -1,
      -1,    -1,    -1,   220,   221,   222,   223,    -1,    -1,    -1,
      -1,   228,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      63,    64,    65,    66,    67,    68,    69,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    63,    64,    -1,    81,    -1,
      -1,    84,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   101,   102,
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
       4,     5,    -1,     7,     8,     9,    10,    -1,    -1,   212,
     213,   214,   215,    -1,    -1,   218,    -1,   220,    -1,    -1,
      -1,    -1,    -1,    -1,   227,   228,    30,    31,    -1,    -1,
      -1,    -1,   220,   221,   222,   223,    -1,    -1,    -1,    -1,
     228,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      64,    65,    66,    67,    68,    69,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    64,    -1,    81,    -1,    -1,
      84,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   101,   102,    -1,
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
       5,    -1,     7,     8,     9,    10,    -1,    12,   212,   213,
     214,   215,    -1,    -1,   218,    -1,   220,    -1,    -1,    -1,
      -1,    -1,    -1,   227,   228,    30,    31,    -1,    -1,    -1,
      -1,   220,   221,   222,   223,    -1,    -1,    -1,    -1,   228,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,
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
      -1,     7,     8,     9,    10,    -1,    -1,   212,   213,   214,
     215,    -1,    -1,   218,    -1,   220,    -1,    -1,    -1,    -1,
      -1,    -1,   227,    -1,    30,    31,    -1,    -1,    34,    -1,
     220,   221,   222,   223,    -1,    -1,    -1,    -1,   228,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
       7,     8,     9,    10,    -1,    12,   212,   213,   214,   215,
      -1,    -1,   218,    -1,   220,    -1,    -1,    -1,    -1,    -1,
      -1,   227,    -1,    30,    31,    -1,    -1,    -1,    -1,   220,
     221,   222,   223,    -1,    -1,    -1,    -1,   228,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
       8,     9,    10,    -1,    -1,   212,   213,   214,   215,    -1,
      -1,   218,    -1,   220,    -1,    -1,    -1,    -1,    -1,    -1,
     227,    -1,    30,    31,    -1,    -1,    -1,    -1,   220,   221,
     222,   223,    -1,    -1,    -1,    -1,   228,    -1,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    63,    64,    65,    66,    67,
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
     178,   179,   180,    -1,    -1,    -1,     5,    -1,   186,   187,
     188,    10,    -1,    -1,   192,    -1,    -1,   195,    -1,    -1,
     198,   199,   200,   201,    -1,   220,   221,   222,   223,    -1,
      -1,    -1,    31,   228,   212,   213,   214,   215,    -1,    -1,
     218,    -1,   220,    -1,    -1,    -1,    -1,    -1,    -1,   227,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   220,   221,   222,
     223,    -1,    -1,    -1,    -1,   228,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     5,    -1,    -1,    -1,    -1,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   105,    -1,   107,    -1,
      -1,    31,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,   132,   133,   134,    -1,    -1,    -1,   138,
     139,   140,    -1,   142,    -1,   144,   145,   146,    -1,    -1,
      -1,    -1,   151,   152,   153,    -1,    -1,   156,    -1,   158,
      -1,   160,    -1,     5,   163,    -1,   165,    -1,    10,   168,
      -1,    -1,   171,   172,    -1,   174,   175,    97,   177,    -1,
     179,    -1,    -1,    -1,    -1,   105,    -1,   107,   187,    31,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   132,   133,   134,   214,   215,    -1,   138,   139,
     140,    -1,   142,    -1,   144,   145,   146,    -1,   227,    -1,
      -1,   151,   152,   153,    -1,    -1,   156,    -1,   158,    -1,
     160,    -1,     5,   163,    -1,   165,    -1,    10,   168,    -1,
      -1,   171,   172,    -1,   174,   175,    -1,   177,    -1,   179,
      -1,    -1,    -1,   105,    -1,   107,    -1,   187,    31,   220,
     221,   222,   223,    63,    64,    -1,    -1,   228,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
     132,   133,   134,    -1,   214,   215,   138,   139,   140,    -1,
     142,    -1,   144,   145,   146,    -1,    -1,   227,    -1,   151,
     152,   153,    -1,    -1,   156,    -1,   158,    -1,   160,    -1,
      -1,   163,    -1,   165,    -1,    -1,   168,    -1,    -1,   171,
     172,    -1,   174,   175,    -1,   177,    -1,   179,    -1,    -1,
      -1,    -1,   105,    -1,   107,   187,    -1,   220,   221,   222,
     223,    63,    64,    -1,    -1,   228,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,   132,
     133,   134,   214,   215,    -1,   138,   139,   140,    -1,   142,
      -1,   144,   145,   146,    -1,   227,    -1,    -1,   151,   152,
     153,    -1,    -1,   156,    -1,   158,    -1,   160,    -1,    -1,
     163,    -1,   165,    -1,    -1,   168,    -1,    -1,   171,   172,
      -1,   174,   175,    -1,   177,    -1,   179,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   187,    -1,    -1,    -1,    -1,    -1,
     220,   221,   222,   223,    -1,    -1,    -1,    -1,   228,    -1,
      -1,    -1,    -1,     4,     5,     6,    -1,    -1,    -1,    -1,
      11,   214,   215,    -1,    15,    -1,    17,    -1,    19,    20,
      21,    22,    23,    24,   227,    26,    27,    28,    29,    30,
      31,    32,    33,    -1,    35,    36,    37,    -1,    -1,    -1,
      -1,    42,    -1,    -1,    45,    -1,    -1,    -1,    -1,    -1,
      -1,    52,    53,    54,    55,    56,    57,    -1,    -1,    -1,
      61,    62,    -1,    -1,    -1,    -1,    -1,    -1,   220,   221,
     222,   223,    -1,    -1,    -1,    -1,   228,    78,    79,    80,
      81,    82,    83,    -1,    -1,    -1,    -1,    -1,    89,    90,
      91,    92,    93,    94,    95,    96,    -1,    98,    99,   100,
      -1,    -1,   103,   104,    -1,   106,    -1,   108,   109,    -1,
      -1,    -1,    -1,    -1,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,   132,   133,   134,    -1,    63,    64,    -1,   139,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,   157,    -1,    -1,    -1,
     161,    -1,    -1,    -1,    -1,   166,    63,    64,   169,    -1,
      -1,    -1,   173,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   189,   190,
     191,    -1,   193,   194,    -1,   196,   197,    -1,    -1,    -1,
      -1,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,    -1,     4,     5,     6,   216,   217,    -1,   219,    11,
      -1,    -1,    -1,    15,    -1,    17,    -1,    19,    20,    21,
      22,    23,    24,    -1,    26,    27,    28,    29,    30,    31,
      32,    33,    -1,    35,    36,    37,    -1,    -1,    -1,    -1,
      42,    43,    44,    45,    -1,    -1,    -1,    -1,    -1,    -1,
      52,    53,    54,    55,    56,    57,    -1,    -1,    -1,    61,
      62,   220,   221,   222,   223,    -1,    -1,    -1,    -1,   228,
      -1,    -1,    -1,    -1,    -1,    -1,    78,    79,    80,    81,
      82,    83,   220,   221,   222,   223,    -1,    89,    90,    91,
     228,    -1,    94,    95,    96,    -1,    98,    99,   100,    -1,
      -1,   103,    -1,    -1,   106,    -1,   108,   109,    -1,    -1,
      -1,    -1,    -1,   220,   221,   222,   223,    -1,    -1,    -1,
      -1,   228,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     132,   133,   134,    -1,    63,    64,    -1,   139,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,   157,    -1,    -1,    -1,   161,
      -1,    -1,    -1,    -1,   166,    63,    64,   169,    -1,    -1,
      -1,   173,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   189,   190,   191,
      -1,   193,   194,    -1,   196,   197,    -1,    -1,    -1,    -1,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
      -1,     4,     5,     6,   216,   217,    -1,   219,    11,    -1,
      -1,    -1,    15,    -1,    17,    -1,    19,    20,    21,    22,
      23,    24,    -1,    26,    27,    28,    29,    30,    31,    32,
      33,    -1,    35,    36,    37,    38,    -1,    -1,    -1,    42,
      43,    -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,    52,
      53,    54,    55,    56,    57,    -1,    -1,    -1,    61,    62,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,
      83,   220,   221,   222,   223,    -1,    89,    90,    91,   228,
      -1,    94,    95,    96,    -1,    98,    99,   100,    -1,    -1,
     103,    -1,    -1,   106,    -1,   108,   109,    -1,    -1,    -1,
      -1,    -1,   220,   221,   222,   223,    -1,    -1,    -1,    -1,
     228,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   132,
     133,   134,    63,    64,    -1,    -1,   139,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   157,    -1,    -1,    -1,   161,    -1,
      -1,    -1,    -1,   166,    63,    64,   169,    -1,    -1,    -1,
     173,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   189,   190,   191,    -1,
     193,   194,    -1,   196,   197,    -1,    -1,    -1,    -1,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,    -1,
      63,    64,    -1,   216,   217,    -1,   219,    70,    71,    72,
      73,    74,    75,    76,    77,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,   220,
     221,   222,   223,    63,    64,    -1,    -1,   228,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   220,   221,   222,   223,    63,    64,    -1,    -1,   228,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   220,   221,   222,
     223,    -1,    -1,    -1,    -1,   228,    -1,    -1,    -1,    -1,
      -1,    -1,   220,   221,   222,   223,    -1,    -1,    -1,    -1,
     228,    -1,    -1,    -1,    -1,    -1,    -1,   220,   221,   222,
     223,    -1,    -1,    -1,    -1,   228,    -1,    -1,    -1,    -1,
      -1,    -1,   220,   221,   222,   223,    -1,    -1,    -1,    -1,
     228,    -1,    -1,    -1,    -1,    -1,    -1,   220,   221,   222,
     223,    63,    64,    -1,    -1,   228,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
     220,   221,   222,   223,    63,    64,    -1,    -1,   228,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   220,   221,   222,   223,    -1,    -1,    -1,    -1,
     228,    -1,    -1,    -1,    -1,    -1,    -1,   220,   221,   222,
     223,    63,    64,    -1,    -1,   228,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   220,   221,
     222,   223,    63,    64,    -1,    -1,   228,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,   220,   221,   222,   223,    63,    64,    -1,    -1,   228,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   220,   221,
     222,   223,    -1,    -1,    -1,    -1,   228,    -1,    -1,    -1,
      -1,    -1,    -1,   220,   221,   222,   223,    -1,    -1,    -1,
      -1,   228,    -1,    -1,    -1,    -1,    -1,    -1,   220,   221,
     222,   223,    -1,    -1,    -1,    -1,   228,    -1,    -1,    -1,
      -1,    -1,    -1,   220,   221,   222,   223,    -1,    -1,    -1,
      -1,   228,    -1,    -1,    -1,    -1,    -1,    -1,   220,   221,
     222,   223,    63,    64,    -1,    -1,   228,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   220,
     221,   222,   223,    63,    64,    -1,    -1,   228,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,   220,   221,   222,   223,    -1,    -1,    -1,    -1,
     228,    -1,    -1,    -1,    -1,    -1,    -1,   220,   221,   222,
     223,    63,    64,    -1,    -1,   228,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   220,
     221,   222,   223,    63,    64,    -1,    -1,   228,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     220,   221,   222,   223,    63,    64,    -1,    -1,   228,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,   220,   221,
     222,   223,    -1,    -1,    -1,    -1,   228,    -1,    -1,    -1,
      -1,    -1,    -1,   220,   221,   222,   223,    -1,    -1,    -1,
      -1,   228,    -1,    -1,    -1,    -1,    -1,    -1,   220,   221,
     222,   223,    -1,    -1,    -1,    -1,   228,    -1,    -1,    -1,
      -1,    -1,    -1,   220,   221,   222,   223,    -1,    -1,    -1,
      -1,   228,    -1,    -1,    -1,    -1,    -1,    -1,   220,   221,
     222,   223,    63,    64,    -1,    -1,   228,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     220,   221,   222,   223,    63,    64,    -1,    -1,   228,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   220,   221,   222,   223,    -1,    -1,    -1,    -1,   228,
      -1,    -1,    -1,    -1,    -1,    -1,   220,   221,   222,   223,
      63,    64,    -1,    -1,   228,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,   220,
     221,   222,   223,    63,    64,    -1,    -1,   228,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   220,   221,   222,   223,    63,    64,    -1,    -1,   228,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   220,   221,   222,
     223,    -1,    -1,    -1,    -1,   228,    -1,    -1,    -1,    -1,
      -1,    -1,   220,   221,   222,   223,    -1,    -1,    -1,    -1,
     228,    -1,    -1,    -1,    -1,    -1,    -1,   220,   221,   222,
     223,    -1,    -1,    -1,    -1,   228,    -1,    -1,    -1,    -1,
      -1,    -1,   220,   221,   222,   223,    -1,    -1,    -1,    -1,
     228,    -1,    -1,    -1,    -1,    -1,    -1,   220,   221,   222,
     223,    63,    64,    -1,    -1,   228,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
     220,   221,   222,   223,    63,    64,    -1,    -1,   228,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   220,   221,   222,   223,    -1,    -1,    -1,    -1,
     228,    -1,    -1,    -1,    -1,    -1,    -1,   220,   221,   222,
     223,    63,    64,    -1,    -1,   228,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   220,   221,
     222,   223,    63,    64,    -1,    -1,   228,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,   220,   221,   222,   223,    63,    64,    -1,    -1,   228,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   220,   221,
     222,   223,    -1,    -1,    -1,    -1,   228,    -1,    -1,    -1,
      -1,    -1,    -1,   220,   221,   222,   223,    -1,    -1,    -1,
      -1,   228,    -1,    -1,    -1,    -1,    -1,    -1,   220,   221,
     222,   223,    -1,    -1,    -1,    -1,   228,    -1,    -1,    -1,
      -1,    -1,    -1,   220,   221,   222,   223,    -1,    -1,    -1,
      -1,   228,    -1,    -1,    -1,    -1,    -1,    -1,   220,   221,
     222,   223,    63,    64,    -1,    -1,   228,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   220,
     221,   222,   223,    63,    64,    -1,    -1,   228,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,   220,   221,   222,   223,    -1,    -1,    -1,    -1,
     228,    -1,    -1,    -1,    -1,    -1,    -1,   220,   221,   222,
     223,    63,    64,    -1,    -1,   228,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   220,
     221,   222,   223,    63,    64,   226,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     220,   221,   222,   223,    63,    64,   226,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,   220,   221,
     222,   223,    -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   220,   221,   222,   223,    -1,    -1,   226,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   220,   221,
     222,   223,    -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   220,   221,   222,   223,    -1,    -1,   226,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   220,   221,
     222,   223,    63,    64,   226,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     220,   221,   222,   223,    63,    64,   226,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   220,   221,   222,   223,    -1,    -1,   226,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   220,   221,   222,   223,
      63,    64,   226,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,   220,
     221,   222,   223,    63,    64,   226,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   220,   221,   222,   223,    63,    64,   226,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   220,   221,   222,
     223,    -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   220,   221,   222,   223,    -1,    -1,   226,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   220,   221,   222,
     223,    -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   220,   221,   222,   223,    -1,    -1,   226,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   220,   221,   222,
     223,    63,    64,   226,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
     220,   221,   222,   223,    63,    64,   226,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   220,   221,   222,   223,    -1,    -1,   226,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   220,   221,   222,
     223,    63,    64,   226,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   220,   221,
     222,   223,    63,    64,   226,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,   220,   221,   222,   223,    63,    64,   226,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   220,   221,
     222,   223,    -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   220,   221,   222,   223,    -1,    -1,   226,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   220,   221,
     222,   223,    -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   220,   221,   222,   223,    -1,    -1,   226,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   220,   221,
     222,   223,    63,    64,   226,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   220,
     221,   222,   223,    63,    64,   226,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,   220,   221,   222,   223,    -1,    -1,   226,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   220,   221,   222,
     223,    63,    64,   226,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   220,
     221,   222,   223,    63,    64,   226,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     220,   221,   222,   223,    63,    64,   226,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,   220,   221,
     222,   223,    -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   220,   221,   222,   223,    -1,    -1,   226,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   220,   221,
     222,   223,    -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   220,   221,   222,   223,    -1,    -1,   226,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   220,   221,
     222,   223,    63,    64,   226,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     220,   221,   222,   223,    63,    64,   226,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   220,   221,   222,   223,    -1,    -1,   226,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   220,   221,   222,   223,
      63,    64,   226,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,   220,
     221,   222,   223,    63,    64,   226,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   220,   221,   222,   223,    63,    64,   226,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   220,   221,   222,
     223,    -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   220,   221,   222,   223,    -1,    -1,   226,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   220,   221,   222,
     223,    -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   220,   221,   222,   223,    -1,    -1,   226,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   220,   221,   222,
     223,    63,    64,   226,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
     220,   221,   222,   223,    63,    64,   226,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   220,   221,   222,   223,    -1,    -1,   226,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   220,   221,   222,
     223,    63,    64,   226,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   220,   221,
     222,   223,    -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   220,   221,   222,   223,    -1,    -1,   226,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   220,   221,
     222,   223,    -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   220,   221,   222,   223
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   181,   182,   183,   184,   185,   231,     4,     5,     6,
      11,    15,    17,    19,    20,    21,    22,    23,    26,    27,
      28,    29,    30,    31,    32,    33,    35,    36,    37,    42,
      45,    52,    53,    54,    55,    56,    57,    61,    62,    78,
      79,    80,    81,    82,    83,    89,    90,    91,    94,    95,
      96,    98,    99,   100,   103,   106,   108,   109,   132,   133,
     134,   139,   157,   161,   166,   169,   173,   189,   190,   191,
     193,   194,   196,   197,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   216,   217,   219,   232,   233,   236,
     237,   244,   245,   247,   248,   252,   264,   265,   270,   276,
     283,   291,   299,   302,   306,   309,   315,     3,     4,     5,
       7,     8,     9,    10,    30,    31,    63,    64,    65,    66,
      67,    68,    69,    81,    84,   101,   102,   105,   107,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   162,
     163,   164,   165,   167,   168,   170,   171,   172,   174,   175,
     176,   177,   178,   179,   180,   186,   187,   188,   192,   195,
     198,   199,   200,   201,   212,   213,   214,   215,   218,   220,
     227,   250,   251,   253,   259,   261,   264,   265,   227,   250,
     236,   264,   265,   270,     0,    75,   227,    75,   227,   284,
     303,   307,     4,     7,   262,   262,   262,    34,   253,   238,
     239,   250,   266,   267,   266,   250,    28,     7,   292,   300,
     253,    58,    60,    61,   229,   338,   242,   250,   253,     4,
       5,   263,   253,   250,   253,   250,   253,     4,     5,   326,
     327,    10,   220,   221,   260,   261,   328,   262,    89,    97,
     229,   250,   253,   339,    89,    97,   110,   339,   339,    88,
     253,   258,    12,    53,   258,   258,    59,    89,    90,    91,
      96,    95,   253,   245,   252,   250,   250,   250,   110,   227,
     227,   227,   227,   227,   250,   339,   250,   250,   250,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,    44,
     234,    92,    93,   104,    75,    75,    24,   227,   227,   227,
     227,   253,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   253,   250,   253,    70,    71,    72,    73,    74,
      75,    76,   221,    44,    63,    64,    70,    71,    72,    73,
      74,    75,    76,    77,   220,   221,   222,   223,   250,    44,
      44,    44,   253,   266,   250,   266,     4,   253,   233,    35,
      36,    20,    21,     4,     5,   277,   278,     4,     5,   279,
     280,   250,   253,   268,   269,   250,   253,   294,   233,   310,
     316,   227,    58,   227,     4,     7,   227,   250,   253,   329,
      58,   229,   331,   336,   227,   227,   226,   226,   226,   227,
     227,   226,   261,   261,   226,   253,   250,   253,    11,   226,
     226,   250,   226,   258,   243,    12,   226,   246,   226,   258,
      12,   258,   246,   246,     5,   249,   249,   249,   228,   253,
     250,   226,   226,   226,   226,   253,   253,   253,   253,   253,
     250,   250,   253,   228,   253,   250,   253,   228,   250,   228,
     250,   228,   253,   250,   253,    43,   258,   258,   258,   253,
     250,   271,   266,   266,   253,   253,   253,   253,   253,   253,
      97,   250,   339,   339,     4,     5,   256,   257,   256,   257,
     258,   253,   253,   253,   253,   253,   253,   253,   253,   253,
     253,   253,   339,   253,   253,   253,   253,   253,   253,   253,
     253,   228,   253,   250,   250,   250,   250,   250,   253,   253,
     250,   253,   228,   253,   253,   250,   253,   250,   253,   250,
     250,   228,   250,   228,   250,   228,   250,   228,   250,   250,
     250,   250,   250,   250,   250,   250,   250,   250,   339,   250,
     266,   266,   250,   253,   250,   250,   250,   250,   250,   228,
     228,   250,   249,   250,   249,   250,   250,   250,   253,   253,
     250,   250,   250,   250,   253,   250,   250,   250,   250,   228,
     228,   228,   250,   250,   250,   250,   250,   250,   250,   250,
     255,   254,   253,   253,   253,   253,   253,   253,   253,   253,
     253,   253,   253,   253,   228,   228,    75,   304,    14,    16,
      18,    41,    44,    49,   308,   240,   241,   227,   227,   226,
     227,   227,   226,   226,    43,   293,    14,    16,    18,    41,
      44,    49,   301,    46,   233,   253,   227,   250,   253,    51,
     330,   225,   226,   227,     4,     7,   227,    10,   337,   266,
     266,     4,     5,   253,   253,   266,   266,   327,    10,   260,
     226,    86,    87,    97,   250,   253,   253,   331,   258,   250,
     258,   246,   253,   253,   227,   226,   226,   226,   228,   228,
     250,   253,   250,   253,   253,   253,   228,   226,   226,   228,
     228,   228,   226,   226,   228,   226,   226,   228,   226,   226,
     228,   228,   235,   226,   246,   246,     4,     5,   275,   228,
     228,   226,   226,   228,   226,   226,   226,   228,   226,   228,
     226,   228,   227,   227,   228,   228,   226,   226,   246,   226,
     228,   228,   228,   228,   228,   226,   228,   228,   226,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     226,   228,   228,   226,   226,   226,   228,   226,   226,   228,
     226,   228,   228,   228,   228,   228,   226,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   226,   226,
     228,   228,   228,   228,   228,   226,   228,   228,   228,   228,
     228,   228,   226,   228,   226,   226,   226,   226,   226,   228,
     226,   226,   228,   226,   228,   228,   226,   228,   226,   226,
     226,   226,   226,   226,   226,   228,   228,   253,   253,   285,
     233,   253,   262,   340,   262,   341,   266,   266,   278,   266,
     266,   280,   269,    43,   295,   311,    49,    50,   317,   226,
     253,   226,   228,   228,   227,   250,   250,   253,   253,   332,
     333,   253,     4,     5,   323,   325,   228,   228,   227,   227,
     226,   226,   228,   228,   253,    85,    85,   226,   226,   226,
     258,   226,   226,   266,   253,   253,   253,   226,   226,   250,
     253,   253,   253,   253,   253,   253,   253,   237,   253,   258,
     258,   272,   253,   253,   253,   253,   253,   250,    97,   250,
     228,   228,   253,   253,   258,   253,   253,   253,   253,   253,
     253,   253,   253,   253,   250,   253,   250,   250,   250,   253,
     253,   253,   253,   257,   250,   257,   250,   250,   253,   253,
     253,   253,   253,   253,   250,   250,   253,    16,    44,   305,
     226,   226,   228,   228,   228,   228,    39,    40,   297,   233,
     253,   226,   250,    58,   250,   330,   226,   323,   323,   228,
     227,   227,   226,   266,   266,   253,   253,   226,   339,   339,
     250,   250,   250,   253,   253,   228,   228,   228,   226,   228,
     250,   250,   228,   226,   226,   226,   226,   228,   226,   226,
     246,   227,   228,   228,   228,   228,   228,   228,   228,   226,
     228,   228,   228,   228,   246,   228,   228,   228,   228,   228,
     226,   228,   228,   228,   226,   228,   228,   226,   228,   226,
     228,   228,   228,   226,   226,   228,   226,   228,   228,   226,
     228,   228,   228,   226,   226,   226,   228,   226,   226,   228,
     228,    12,   262,   262,   294,    43,    38,   312,   228,   253,
     228,   227,   226,   253,   334,   266,   266,   324,   228,   228,
     250,   226,   226,    75,    75,   253,    75,   226,   253,   253,
     253,   253,   253,   253,   258,     4,     5,   281,   282,   250,
     253,   253,   250,   253,   253,   250,   253,   250,   250,   250,
     253,   253,   253,   253,   253,   296,   298,    48,   319,    60,
      61,   228,    58,   253,   250,   228,   323,   228,   228,   323,
     250,   250,   250,   250,   228,   250,   253,   228,   228,   226,
     228,   228,   228,   227,   227,   226,   228,   228,   226,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     226,   226,    13,   289,   233,   233,   253,    47,   318,   227,
     227,   226,   228,   335,    75,   253,   228,   228,   282,   273,
     253,   253,   253,   253,   286,    46,   322,   233,   313,   250,
     253,   253,   337,   250,   228,   233,   228,   226,   226,   233,
     320,    14,    16,    18,    41,    44,    49,   314,   226,   228,
     226,   228,   323,    25,    44,   274,   253,   253,   287,   233,
     250,   253,   228,   228,    14,    16,    18,    41,    44,    49,
     288,   321,   228,   228,     4,   290,   319
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   230,   231,   231,   231,   231,   231,   232,   233,   234,
     235,   233,   236,   236,   236,   236,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   238,   237,   239,   237,   237,   237,   237,   237,   237,
     237,   240,   237,   241,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   242,   237,   243,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   244,   244,
     244,   244,   244,   245,   245,   245,   245,   245,   245,   246,
     246,   247,   247,   247,   247,   247,   248,   248,   249,   249,
     250,   250,   250,   250,   250,   250,   251,   251,   251,   251,
     251,   251,   251,   251,   251,   251,   251,   251,   251,   251,
     251,   251,   251,   251,   251,   251,   251,   251,   251,   251,
     251,   251,   251,   251,   251,   251,   251,   251,   251,   251,
     251,   251,   251,   251,   251,   251,   251,   251,   251,   252,
     252,   254,   253,   255,   253,   253,   253,   253,   253,   253,
     253,   253,   253,   253,   253,   253,   253,   253,   253,   253,
     253,   253,   253,   253,   253,   253,   253,   253,   253,   253,
     253,   253,   253,   253,   253,   253,   253,   256,   257,   258,
     259,   259,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   260,   260,   260,   261,   261,   261,   261,   262,   262,
     263,   263,   263,   263,   264,   265,   267,   266,   268,   268,
     268,   269,   269,   271,   272,   273,   270,   274,   274,   275,
     275,   276,   276,   276,   276,   277,   277,   278,   278,   278,
     278,   279,   279,   280,   280,   280,   280,   281,   281,   281,
     282,   282,   282,   282,   284,   285,   286,   287,   283,   288,
     288,   288,   288,   288,   288,   289,   289,   290,   290,   292,
     291,   293,   293,   294,   294,   295,   296,   295,   297,   298,
     297,   300,   299,   301,   301,   301,   301,   301,   301,   303,
     304,   302,   305,   305,   307,   306,   308,   308,   308,   308,
     308,   308,   310,   311,   312,   313,   309,   314,   314,   314,
     314,   314,   314,   316,   315,   317,   317,   318,   318,   319,
     320,   321,   319,   322,   322,   323,   324,   323,   325,   325,
     325,   325,   326,   326,   327,   327,   327,   327,   328,   328,
     328,   328,   329,   329,   329,   329,   329,   330,   330,   330,
     332,   331,   333,   331,   334,   331,   335,   331,   336,   331,
     337,   337,   338,   338,   338,   338,   338,   338,   338,   338,
     338,   338,   338,   338,   338,   338,   339,   339,   340,   340,
     341,   341
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
       8,     4,     4,     4,     8,     8,    10,     3,     4,     6,
       3,     4,     3,     8,     3,     8,     4,     4,     0,     1,
       1,     2,     2,     3,    10,     8,     8,     8,     3,     1,
       1,     6,     4,     4,     6,     6,     4,     6,     1,     4,
       1,     1,     1,     1,     3,     3,     6,     6,     8,     6,
       4,     6,     8,     4,     1,     3,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     6,     1,
       3,     1,     3,     4,     6,     6,     4,     6,     4,     6,
      10,     4,     4,     4,     8,     6,     4,     4,     4,     3,
       3,     0,     4,     0,     4,     2,     3,     3,     3,     3,
       3,     3,     3,     4,     6,     1,     4,     4,     6,     6,
       1,     1,     3,     3,     3,     3,     3,     2,     3,     3,
       3,     3,     3,     3,     3,     1,     3,     3,     3,     3,
       4,     4,     4,     4,     4,     4,     6,     4,     4,     6,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     6,
       4,     3,     6,     6,     4,     4,     4,     4,     6,     6,
       8,     6,     8,     4,     4,     4,     8,     4,     4,     4,
       4,     1,     3,     4,     1,     3,     4,     1,     3,     4,
       1,     3,     6,     6,     4,     6,     6,     6,     4,     8,
       6,     8,     6,     4,     4,     4,     6,     6,     6,     8,
       4,     8,     4,     8,     8,     6,    12,    12,     3,     6,
       6,     1,     2,     2,     1,     1,     1,     1,     1,     1,
       4,     6,     4,     6,     4,     4,     0,     2,     0,     1,
       3,     1,     1,     0,     0,     0,    11,     1,     1,     1,
       1,     0,     1,     1,     2,     1,     3,     1,     1,     4,
       4,     1,     3,     1,     1,     4,     4,     0,     1,     3,
       1,     1,     3,     3,     0,     0,     0,     0,    14,     1,
       1,     1,     1,     1,     1,     0,     2,     0,     1,     0,
       7,     1,     2,     1,     1,     0,     0,     5,     0,     0,
       4,     0,     4,     1,     1,     1,     1,     1,     1,     0,
       0,     6,     1,     1,     0,     4,     1,     2,     1,     1,
       1,     1,     0,     0,     0,     0,    11,     1,     1,     1,
       1,     1,     1,     0,     5,     1,     1,     0,     2,     0,
       0,     0,     7,     0,     1,     1,     0,     4,     1,     4,
       1,     4,     1,     3,     1,     4,     1,     4,     1,     1,
       3,     3,     0,     2,     4,     1,     3,     0,     2,     6,
       0,     4,     0,     4,     0,     6,     0,     9,     0,     3,
       0,     1,     0,     2,     2,     4,     1,     4,     6,     6,
       7,    10,    12,     7,    10,    12,     2,     1,     1,     3,
       1,     3
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
                                         {YYACCEPT;}
    break;

  case 4: /* program_or_expression: tSTART_STRING_EXPRESSION string_expression tEOPROG  */
                                                       {YYACCEPT;}
    break;

  case 5: /* program_or_expression: tSTART_ASSIGNMENT assignment tEOPROG  */
                                         {YYACCEPT;}
    break;

  case 6: /* program_or_expression: tSTART_FUNCTION_DEFINITION function_definition tEOPROG  */
                                                           {YYACCEPT;}
    break;

  case 7: /* program: statement_list tEOPROG  */
                                {YYACCEPT;}
    break;

  case 9: /* $@1: %empty  */
                   {if (severity_so_far >= sERROR) {YYABORT;}}
    break;

  case 10: /* $@2: %empty  */
                                                                    {if (in_short_if > 0 && (yyvsp[0].nnl) > 0) lyyerror(sERROR,"short if-statement (i.e. without 'then' and ended by newline) does not contain any statements");}
    break;

  case 18: /* statement: tIMPORT  */
            {report_if_missing("can not import a library in a loop or an if-statement",FALSE);}
    break;

  case 19: /* statement: tERROR string_expression  */
                             {add_command(cERROR);}
    break;

  case 25: /* statement: tBREAK  */
           {add_command(cPOP_MULTI);create_mybreak(1);if (!loop_nesting && !switch_nesting) lyyerror(sERROR,"break outside loop or switch");}
    break;

  case 26: /* statement: tBREAK tDIGITS  */
                   {add_command(cPOP_MULTI);create_mybreak(atoi((yyvsp[0].digits)));if (!loop_nesting && !switch_nesting) lyyerror(sERROR,"break outside loop or switch");}
    break;

  case 27: /* statement: tCONTINUE  */
              {add_command(cPOP_MULTI);add_command_with_switch_state(cCONTINUE);if (!loop_nesting) lyyerror(sERROR,"continue outside loop");}
    break;

  case 29: /* statement: function_or_array  */
                      {create_call((yyvsp[0].symbol));add_command(cPOP);}
    break;

  case 30: /* statement: stringfunction_or_array  */
                            {create_call((yyvsp[0].symbol));add_command(cPOP);}
    break;

  case 31: /* $@3: %empty  */
           {if (function_type==ftNONE) lyyerror(sERROR,"no use for 'local' outside functions");}
    break;

  case 33: /* $@4: %empty  */
            {if (function_type==ftNONE) lyyerror(sERROR,"no use for 'static' outside functions");}
    break;

  case 37: /* statement: tGOTO symbol_or_lineno  */
                           {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));}
    break;

  case 38: /* statement: tGOSUB symbol_or_lineno  */
                            {create_gosub((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));}
    break;

  case 39: /* statement: tON tINTERRUPT tBREAK  */
                          {create_exception(TRUE);}
    break;

  case 40: /* statement: tON tINTERRUPT tCONTINUE  */
                             {create_exception(FALSE);}
    break;

  case 41: /* $@5: %empty  */
                         {add_command(cSKIPPER);}
    break;

  case 42: /* statement: tON expression tGOTO $@5 goto_list  */
              {add_command(cNOP);}
    break;

  case 43: /* $@6: %empty  */
                          {add_command(cSKIPPER);}
    break;

  case 44: /* statement: tON expression tGOSUB $@6 gosub_list  */
               {add_command(cNOP);}
    break;

  case 45: /* statement: tLABEL symbol_or_lineno  */
                            {create_label((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol),cLABEL);}
    break;

  case 46: /* statement: open_clause  */
                {add_command(cCHECKOPEN);}
    break;

  case 47: /* statement: tCLOSE hashed_number  */
                         {add_command(cCLOSE);}
    break;

  case 48: /* statement: seek_clause  */
                {add_command(cCHECKSEEK);}
    break;

  case 49: /* statement: tCOMPILE string_expression  */
                               {add_command(cCOMPILE);}
    break;

  case 50: /* statement: tEXECUTE call_list  */
                       {create_execute(0);add_command(cPOP);add_command(cPOP);}
    break;

  case 51: /* statement: tEXECUTE2 call_list  */
                        {create_execute(1);add_command(cPOP);add_command(cPOP);}
    break;

  case 52: /* statement: tPRINT printintro printlist  */
                                {create_colour(0);create_print('n');create_pps(cPOPSTREAM,0);}
    break;

  case 53: /* statement: tPRINT printintro printlist ';'  */
                                    {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 54: /* statement: tPRINT printintro printlist ','  */
                                    {create_colour(0);create_print('t');create_pps(cPOPSTREAM,0);}
    break;

  case 55: /* $@7: %empty  */
           {tileol=FALSE;}
    break;

  case 57: /* $@8: %empty  */
                 {tileol=TRUE;}
    break;

  case 59: /* statement: tCOLOUR expression ',' expression ',' expression  */
                                                     {add_command(cGCOLOUR);}
    break;

  case 60: /* statement: tCOLOUR string_expression  */
                              {add_command(cGCOLOUR2);}
    break;

  case 61: /* statement: tBACKCOLOUR expression ',' expression ',' expression  */
                                                         {add_command(cGBACKCOLOUR);}
    break;

  case 62: /* statement: tBACKCOLOUR string_expression  */
                                  {add_command(cGBACKCOLOUR2);}
    break;

  case 65: /* statement: tRESTORE  */
             {create_restore("");}
    break;

  case 66: /* statement: tRESTORE symbol_or_lineno  */
                              {create_restore((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));}
    break;

  case 67: /* statement: tRETURN  */
            {if (function_type!=ftNONE) {
	       add_command(cCLEARSYMREFS);end_symref_chain();
	       add_command(cPOPSYMLIST);
               create_check_return_value(ftNONE,function_type);
               add_command(cRETURN_FROM_CALL);
             } else {
               add_command(cRETURN_FROM_GOSUB);
            }}
    break;

  case 68: /* statement: tRETURN expression  */
                       {if (function_type==ftNONE) {lyyerror(sERROR,"a value can only be returned from a subroutine"); YYABORT;} add_command(cCLEARSYMREFS);end_symref_chain();add_command(cPOPSYMLIST);create_check_return_value(ftNUMBER,function_type);add_command(cRETURN_FROM_CALL);}
    break;

  case 69: /* statement: tRETURN string_expression  */
                              {if (function_type==ftNONE) {lyyerror(sERROR,"can not return value"); YYABORT;} add_command(cCLEARSYMREFS);end_symref_chain();add_command(cPOPSYMLIST);create_check_return_value(ftSTRING,function_type);add_command(cRETURN_FROM_CALL);}
    break;

  case 71: /* statement: tOPEN tWINDOW expression ',' expression  */
                                            {create_openwin(FALSE);}
    break;

  case 72: /* statement: tOPEN tWINDOW expression ',' expression ',' string_expression  */
         {create_openwin(TRUE);}
    break;

  case 73: /* statement: tWINDOW tORIGIN string_expression  */
                                      {add_command(cMOVEORIGIN);}
    break;

  case 74: /* statement: tDOT coordinates  */
                     {add_command(cDOT);}
    break;

  case 75: /* statement: tCLEAR tDOT coordinates  */
                            {add_command(cDOT);putindrawmode(dmCLEAR);}
    break;

  case 76: /* statement: tLINE coordinates to coordinates  */
                                     {create_line(2);}
    break;

  case 77: /* statement: tCLEAR tLINE coordinates to coordinates  */
                                            {create_line(2);putindrawmode(dmCLEAR);}
    break;

  case 78: /* statement: tLINE tTO coordinates  */
                          {create_line(1);}
    break;

  case 79: /* statement: tLINE coordinates  */
                      {create_line(1);}
    break;

  case 80: /* statement: tCLEAR tLINE tTO coordinates  */
                                 {create_line(1);putindrawmode(dmCLEAR);}
    break;

  case 81: /* statement: tCLEAR tLINE coordinates  */
                             {create_line(1);putindrawmode(dmCLEAR);}
    break;

  case 82: /* statement: tPUTBIT string_expression to expression ',' expression ',' string_expression  */
                                                                                 {add_command(cPUTBIT);}
    break;

  case 83: /* statement: tPUTBIT string_expression to expression ',' expression  */
                                                           {create_pushstr("solid"); add_command(cPUTBIT);}
    break;

  case 84: /* statement: tPUTCHAR string_expression to expression ',' expression  */
                                                            {add_command(cPUTCHAR);}
    break;

  case 85: /* statement: tNEW tCURVE  */
                {create_line(-1);}
    break;

  case 86: /* statement: tCLOSE tCURVE  */
                  {create_line(0);}
    break;

  case 87: /* statement: clear_fill_clause tCIRCLE coordinates ',' expression  */
                                                         {add_command(cCIRCLE);putindrawmode(0);}
    break;

  case 88: /* statement: clear_fill_clause tTRIANGLE coordinates to coordinates to coordinates  */
                                                                          {add_command(cTRIANGLE);putindrawmode(0);}
    break;

  case 89: /* statement: tTEXT coordinates ',' string_expression  */
                                            {add_command(cTEXT1);}
    break;

  case 90: /* statement: tTEXT coordinates ',' string_expression ',' string_expression  */
                                                                  {add_command(cTEXT2);}
    break;

  case 91: /* statement: tTEXT coordinates ',' string_expression ',' string_expression ',' string_expression  */
                                                                                        {add_command(cTEXT3);}
    break;

  case 92: /* statement: clear_fill_clause tRECT coordinates to coordinates  */
                                                       {add_command(cRECT);putindrawmode(0);}
    break;

  case 93: /* statement: tCLOSE tWINDOW  */
                   {add_command(cCLOSEWIN);}
    break;

  case 94: /* statement: tCLEAR tWINDOW  */
                   {add_command(cCLEARWIN);}
    break;

  case 95: /* statement: tCLEAR tSCREEN  */
                   {add_command(cCLEARSCR);}
    break;

  case 96: /* statement: tOPEN tPRINTER  */
                   {create_openprinter(0);}
    break;

  case 97: /* statement: tOPEN tPRINTER string_expression  */
                                     {create_openprinter(1);}
    break;

  case 98: /* statement: tCLOSE tPRINTER  */
                    {add_command(cCLOSEPRN);}
    break;

  case 99: /* statement: tWAIT expression  */
                     {add_command(cWAIT);}
    break;

  case 100: /* statement: tBELL  */
          {add_command(cBELL);}
    break;

  case 101: /* statement: tINKEY  */
           {create_pushdbl(-1);create_function(fINKEY);add_command(cPOP);}
    break;

  case 102: /* statement: tINKEY '(' ')'  */
                   {create_pushdbl(-1);create_function(fINKEY);add_command(cPOP);}
    break;

  case 103: /* statement: tINKEY '(' expression ')'  */
                              {create_function(fINKEY);add_command(cPOP);}
    break;

  case 104: /* statement: tSYSTEM '(' string_expression ')'  */
                                      {create_function(fSYSTEM);
	add_command(cPOP);}
    break;

  case 105: /* statement: tPOKE string_expression ',' string_expression  */
                                                  {create_poke('s');}
    break;

  case 106: /* statement: tPOKE string_expression ',' expression  */
                                           {create_poke('d');}
    break;

  case 107: /* statement: tPOKE hashed_number ',' string_expression  */
                                              {create_poke('S');}
    break;

  case 108: /* statement: tPOKE hashed_number ',' expression  */
                                       {create_poke('D');}
    break;

  case 109: /* statement: tEND  */
         {add_command(cEND);}
    break;

  case 110: /* statement: tEXIT  */
          {create_pushdbl(0);add_command(cEXIT);}
    break;

  case 111: /* statement: tEXIT expression  */
                     {add_command(cEXIT);}
    break;

  case 112: /* statement: tDOCU  */
          {create_docu((yyvsp[0].symbol));}
    break;

  case 113: /* statement: tBIND string_expression  */
                            {add_command(cBIND);}
    break;

  case 114: /* statement: tFRNBF_FREE string_expression  */
                                  {add_command(cFRNBF_FREE);}
    break;

  case 115: /* statement: tFRNBF_SET string_expression ',' expression ',' string_expression ',' expression  */
                                                                                     {add_command(cFRNBF_SET_NUMBER);}
    break;

  case 116: /* statement: tFRNBF_SET string_expression ',' expression ',' string_expression  */
                                                                      {add_command(cFRNBF_SET_STRING);}
    break;

  case 117: /* statement: tFRNBF_SET_BUFFER string_expression ',' expression ',' string_expression  */
                                                                             {add_command(cFRNBF_SET_BUFFER);}
    break;

  case 118: /* statement: tBEAM_CLOSE '(' expression ')'  */
                                   {add_command(cBEAM_CLOSE);}
    break;

  case 119: /* statement: tBEAM_TITLE '(' expression ',' string_expression ')'  */
                                                         {add_command(cBEAM_TITLE);}
    break;

  case 120: /* statement: tBEAM_SIZE '(' expression ',' expression ',' expression ')'  */
                                                                {add_command(cBEAM_SIZE);}
    break;

  case 121: /* statement: tBEAM_BEGIN '(' expression ')'  */
                                   {add_command(cBEAM_BEGIN);}
    break;

  case 122: /* statement: tBEAM_END '(' expression ')'  */
                                 {add_command(cBEAM_END);}
    break;

  case 123: /* statement: tBEAM_LABEL '(' string_expression ')'  */
                                          {add_command(cBEAM_LABEL);}
    break;

  case 124: /* statement: tBEAM_TEXT '(' string_expression ',' expression ',' expression ')'  */
                                                                       {add_command(cBEAM_TEXT);}
    break;

  case 125: /* statement: tBEAM_IMAGE '(' string_expression ',' expression ',' expression ')'  */
                                                                        {add_command(cBEAM_IMAGE);}
    break;

  case 126: /* statement: tBEAM_PROGRESS '(' expression ',' expression ',' expression ',' expression ')'  */
                                                                                   {add_command(cBEAM_PROGRESS);}
    break;

  case 127: /* statement: tBEAM_SEPARATOR '(' ')'  */
                            {add_command(cBEAM_SEPARATOR);}
    break;

  case 128: /* statement: tBEAM_SPACING '(' expression ')'  */
                                     {add_command(cBEAM_SPACING);}
    break;

  case 129: /* statement: tBEAM_ROW '(' expression ',' expression ')'  */
                                                {add_command(cBEAM_ROW);}
    break;

  case 130: /* statement: tBEAM_ROW_END '(' ')'  */
                          {add_command(cBEAM_ROW_END);}
    break;

  case 131: /* statement: tBEAM_GROUP_BEGIN '(' string_expression ')'  */
                                                {add_command(cBEAM_GROUP_BEGIN);}
    break;

  case 132: /* statement: tBEAM_GROUP_END '(' ')'  */
                            {add_command(cBEAM_GROUP_END);}
    break;

  case 133: /* statement: tBEAM_PANEL_BEGIN '(' string_expression ',' expression ',' expression ')'  */
                                                                              {add_command(cBEAM_PANEL_BEGIN);}
    break;

  case 134: /* statement: tBEAM_PANEL_END '(' ')'  */
                            {add_command(cBEAM_PANEL_END);}
    break;

  case 135: /* statement: tBEAM_SET_COLOR '(' expression ',' expression ',' expression ')'  */
                                                                     {add_command(cBEAM_SET_COLOR);}
    break;

  case 136: /* statement: tBEAM_SET_STYLE '(' string_expression ')'  */
                                              {add_command(cBEAM_SET_STYLE);}
    break;

  case 137: /* statement: tBEAM_SLEEP '(' expression ')'  */
                                   {add_command(cBEAM_SLEEP);}
    break;

  case 138: /* clear_fill_clause: %empty  */
                               {drawmode=0;}
    break;

  case 139: /* clear_fill_clause: tCLEAR  */
           {drawmode=dmCLEAR;}
    break;

  case 140: /* clear_fill_clause: tFILL  */
          {drawmode=dmFILL;}
    break;

  case 141: /* clear_fill_clause: tCLEAR tFILL  */
                 {drawmode=dmFILL+dmCLEAR;}
    break;

  case 142: /* clear_fill_clause: tFILL tCLEAR  */
                 {drawmode=dmFILL+dmCLEAR;}
    break;

  case 143: /* string_assignment: tSTRSYM tEQU string_expression  */
                                                  {add_command_with_sym_and_diag(cPOPSTRSYM,dotify((yyvsp[-2].symbol),FALSE),NULL);}
    break;

  case 144: /* string_assignment: tMID '(' string_scalar_or_array ',' expression ',' expression ')' tEQU string_expression  */
                                                                                             {create_changestring(fMID);}
    break;

  case 145: /* string_assignment: tMID '(' string_scalar_or_array ',' expression ')' tEQU string_expression  */
                                                                              {create_changestring(fMID2);}
    break;

  case 146: /* string_assignment: tLEFT '(' string_scalar_or_array ',' expression ')' tEQU string_expression  */
                                                                               {create_changestring(fLEFT);}
    break;

  case 147: /* string_assignment: tRIGHT '(' string_scalar_or_array ',' expression ')' tEQU string_expression  */
                                                                                {create_changestring(fRIGHT);}
    break;

  case 148: /* string_assignment: stringfunction_or_array tEQU string_expression  */
                                                   {create_doarray(dotify((yyvsp[-2].symbol),FALSE),ASSIGNSTRINGARRAY);}
    break;

  case 151: /* open_clause: tOPEN hashed_number ',' string_expression ',' string_expression  */
                                                                             {create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}
    break;

  case 152: /* open_clause: tOPEN hashed_number ',' string_expression  */
                                              {create_myopen(OPEN_HAS_STREAM);}
    break;

  case 153: /* open_clause: tOPEN hashed_number ',' tPRINTER  */
                                     {create_myopen(OPEN_HAS_STREAM+OPEN_PRINTER);}
    break;

  case 154: /* open_clause: tOPEN string_expression tFOR tREADING tAS hashed_number  */
                                                            {add_command(cSWAP);create_pushstr("r");create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}
    break;

  case 155: /* open_clause: tOPEN string_expression tFOR tWRITING tAS hashed_number  */
                                                            {add_command(cSWAP);create_pushstr("w");create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}
    break;

  case 156: /* seek_clause: tSEEK hashed_number ',' expression  */
                                                {add_command(cSEEK);}
    break;

  case 157: /* seek_clause: tSEEK hashed_number ',' expression ',' string_expression  */
                                                             {add_command(cSEEK2);}
    break;

  case 158: /* string_scalar_or_array: tSTRSYM  */
                                {add_command_with_sym_and_diag(cPUSHSTRPTR,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 159: /* string_scalar_or_array: tSTRSYM '(' call_list ')'  */
                              {create_doarray(dotify((yyvsp[-3].symbol),FALSE),GETSTRINGPOINTER);}
    break;

  case 160: /* string_expression: tSTRSYM  */
                           {add_command_with_sym_and_diag(cPUSHSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 162: /* string_expression: stringfunction_or_array  */
                            {add_command_with_sym_and_diag(cSTRINGFUNCTION_OR_ARRAY,(yyvsp[0].symbol),NULL);}
    break;

  case 163: /* string_expression: tSTRING  */
            {if ((yyvsp[0].string)==NULL) {lyyerror(sERROR,"String not terminated");create_pushstr("");} else {create_pushstr((yyvsp[0].string));}}
    break;

  case 164: /* string_expression: string_expression '+' string_expression  */
                                            {add_command(cCONCAT);}
    break;

  case 166: /* string_function: tLEFT '(' string_expression ',' expression ')'  */
                                                                {create_function(fLEFT);}
    break;

  case 167: /* string_function: tRIGHT '(' string_expression ',' expression ')'  */
                                                    {create_function(fRIGHT);}
    break;

  case 168: /* string_function: tMID '(' string_expression ',' expression ',' expression ')'  */
                                                                 {create_function(fMID);}
    break;

  case 169: /* string_function: tMID '(' string_expression ',' expression ')'  */
                                                  {create_function(fMID2);}
    break;

  case 170: /* string_function: tSTR '(' expression ')'  */
                            {create_function(fSTR);}
    break;

  case 171: /* string_function: tSTR '(' expression ',' string_expression ')'  */
                                                  {create_function(fSTR2);}
    break;

  case 172: /* string_function: tSTR '(' expression ',' string_expression ',' string_expression ')'  */
                                                                        {create_function(fSTR3);}
    break;

  case 173: /* string_function: tSTR '(' string_expression ')'  */
                                   {create_function(fSTR4);}
    break;

  case 174: /* string_function: tINKEY  */
           {create_pushdbl(-1);create_function(fINKEY);}
    break;

  case 175: /* string_function: tINKEY '(' ')'  */
                   {create_pushdbl(-1);create_function(fINKEY);}
    break;

  case 176: /* string_function: tINKEY '(' expression ')'  */
                              {create_function(fINKEY);}
    break;

  case 177: /* string_function: tCHR '(' expression ')'  */
                            {create_function(fCHR);}
    break;

  case 178: /* string_function: tUPPER '(' string_expression ')'  */
                                     {create_function(fUPPER);}
    break;

  case 179: /* string_function: tLOWER '(' string_expression ')'  */
                                     {create_function(fLOWER);}
    break;

  case 180: /* string_function: tLTRIM '(' string_expression ')'  */
                                     {create_function(fLTRIM);}
    break;

  case 181: /* string_function: tRTRIM '(' string_expression ')'  */
                                     {create_function(fRTRIM);}
    break;

  case 182: /* string_function: tTRIM '(' string_expression ')'  */
                                    {create_function(fTRIM);}
    break;

  case 183: /* string_function: tCHOMP '(' string_expression ')'  */
                                     {create_function(fCHOMP);}
    break;

  case 184: /* string_function: tSYSTEM2 '(' string_expression ')'  */
                                       {create_function(fSYSTEM2);}
    break;

  case 185: /* string_function: tFRNFN_CALL2 '(' call_list ')'  */
                                   {create_function(fFRNFN_CALL2);}
    break;

  case 186: /* string_function: tFRNBF_ALLOC '(' expression ')'  */
                                    {create_function(fFRNBF_ALLOC);}
    break;

  case 187: /* string_function: tFRNBF_DUMP '(' string_expression ')'  */
                                          {create_function(fFRNBF_DUMP);}
    break;

  case 188: /* string_function: tFRNBF_DUMP '(' string_expression ',' expression ')'  */
                                                         {create_function(fFRNBF_DUMP2);}
    break;

  case 189: /* string_function: tDATE  */
          {create_function(fDATE);}
    break;

  case 190: /* string_function: tDATE '(' ')'  */
                  {create_function(fDATE);}
    break;

  case 191: /* string_function: tTIME  */
          {create_function(fTIME);}
    break;

  case 192: /* string_function: tTIME '(' ')'  */
                  {create_function(fTIME);}
    break;

  case 193: /* string_function: tPEEK2 '(' string_expression ')'  */
                                     {create_function(fPEEK2);}
    break;

  case 194: /* string_function: tPEEK2 '(' string_expression ',' string_expression ')'  */
                                                           {create_function(fPEEK3);}
    break;

  case 195: /* string_function: tTOKENALT '(' string_scalar_or_array ',' string_expression ')'  */
                                                                   {add_command(cTOKENALT2);}
    break;

  case 196: /* string_function: tTOKENALT '(' string_scalar_or_array ')'  */
                                             {add_command(cTOKENALT);}
    break;

  case 197: /* string_function: tSPLITALT '(' string_scalar_or_array ',' string_expression ')'  */
                                                                   {add_command(cSPLITALT2);}
    break;

  case 198: /* string_function: tSPLITALT '(' string_scalar_or_array ')'  */
                                             {add_command(cSPLITALT);}
    break;

  case 199: /* string_function: tGETBIT '(' coordinates to coordinates ')'  */
                                               {create_function(fGETBIT);}
    break;

  case 200: /* string_function: tGETCHAR '(' expression ',' expression to expression ',' expression ')'  */
                                                                            {create_function(fGETCHAR);}
    break;

  case 201: /* string_function: tHEX '(' expression ')'  */
                            {create_function(fHEX);}
    break;

  case 202: /* string_function: tBIN '(' expression ')'  */
                            {create_function(fBIN);}
    break;

  case 203: /* string_function: tEXECUTE2 '(' call_list ')'  */
                                {create_execute(1);add_command(cSWAP);add_command(cPOP);}
    break;

  case 204: /* string_function: tFRNBF_GET2 '(' string_expression ',' expression ',' expression ')'  */
                                                                        {create_function(fFRNBF_GET_STRING);}
    break;

  case 205: /* string_function: tFRNBF_GET_BUFFER '(' string_expression ',' expression ')'  */
                                                               {create_function(fFRNBF_GET_BUFFER);}
    break;

  case 206: /* string_function: tEVAL2 '(' string_expression ')'  */
                                     {create_eval(evSTRING);}
    break;

  case 207: /* string_function: tBEAM_OPEN_FILE '(' string_expression ')'  */
                                              {create_function(fBEAM_OPEN_FILE);}
    break;

  case 208: /* string_function: tBEAM_SAVE_FILE '(' string_expression ')'  */
                                              {create_function(fBEAM_SAVE_FILE);}
    break;

  case 209: /* number_assignment: tSYMBOL tEQU expression  */
                                           {add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[-2].symbol),FALSE),NULL);}
    break;

  case 210: /* number_assignment: function_or_array tEQU expression  */
                                      {create_doarray((yyvsp[-2].symbol),ASSIGNARRAY);}
    break;

  case 211: /* $@9: %empty  */
                           {add_command(cORSHORT);pushlabel();}
    break;

  case 212: /* expression: expression tOR $@9 expression  */
                                                                           {poplabel();create_boole('|');}
    break;

  case 213: /* $@10: %empty  */
                    {add_command(cANDSHORT);pushlabel();}
    break;

  case 214: /* expression: expression tAND $@10 expression  */
                                                                     {poplabel();create_boole('&');}
    break;

  case 215: /* expression: tNOT expression  */
                    {create_boole('!');}
    break;

  case 216: /* expression: expression tEQU expression  */
                               {create_dblrelop('=');}
    break;

  case 217: /* expression: expression tEQU2 expression  */
                                {create_dblrelop('=');}
    break;

  case 218: /* expression: expression tNEQ expression  */
                               {create_dblrelop('!');}
    break;

  case 219: /* expression: expression tLTN expression  */
                               {create_dblrelop('<');}
    break;

  case 220: /* expression: expression tLEQ expression  */
                               {create_dblrelop('{');}
    break;

  case 221: /* expression: expression tGTN expression  */
                               {create_dblrelop('>');}
    break;

  case 222: /* expression: expression tGEQ expression  */
                               {create_dblrelop('}');}
    break;

  case 223: /* expression: tMYEOF '(' hashed_number ')'  */
                                 {add_command(cTESTEOF);}
    break;

  case 224: /* expression: tGLOB '(' string_expression ',' string_expression ')'  */
                                                          {add_command(cGLOB);}
    break;

  case 225: /* expression: number  */
           {create_pushdbl((yyvsp[0].fnum));}
    break;

  case 226: /* expression: tARDIM '(' arrayref ')'  */
                            {add_command_with_sym_and_diag(cARDIM,"",NULL);}
    break;

  case 227: /* expression: tARDIM '(' string_arrayref ')'  */
                                   {add_command_with_sym_and_diag(cARDIM,"",NULL);}
    break;

  case 228: /* expression: tARSIZE '(' arrayref ',' expression ')'  */
                                            {add_command_with_sym_and_diag(cARSIZE,"",NULL);}
    break;

  case 229: /* expression: tARSIZE '(' string_arrayref ',' expression ')'  */
                                                   {add_command_with_sym_and_diag(cARSIZE,"",NULL);}
    break;

  case 230: /* expression: function_or_array  */
                      {add_command_with_sym_and_diag(cFUNCTION_OR_ARRAY,(yyvsp[0].symbol),NULL);}
    break;

  case 231: /* expression: tSYMBOL  */
            {add_command_with_sym_and_diag(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 232: /* expression: expression '+' expression  */
                              {create_dblbin('+');}
    break;

  case 233: /* expression: expression '-' expression  */
                              {create_dblbin('-');}
    break;

  case 234: /* expression: expression '*' expression  */
                              {create_dblbin('*');}
    break;

  case 235: /* expression: expression '/' expression  */
                              {create_dblbin('/');}
    break;

  case 236: /* expression: expression tPOW expression  */
                               {create_dblbin('^');}
    break;

  case 237: /* expression: '-' expression  */
                                {add_command(cNEGATE);}
    break;

  case 238: /* expression: string_expression tEQU string_expression  */
                                             {create_strrelop('=');}
    break;

  case 239: /* expression: string_expression tEQU2 string_expression  */
                                              {create_strrelop('=');}
    break;

  case 240: /* expression: string_expression tNEQ string_expression  */
                                             {create_strrelop('!');}
    break;

  case 241: /* expression: string_expression tLTN string_expression  */
                                             {create_strrelop('<');}
    break;

  case 242: /* expression: string_expression tLEQ string_expression  */
                                             {create_strrelop('{');}
    break;

  case 243: /* expression: string_expression tGTN string_expression  */
                                             {create_strrelop('>');}
    break;

  case 244: /* expression: string_expression tGEQ string_expression  */
                                             {create_strrelop('}');}
    break;

  case 247: /* arrayref: tSYMBOL '(' ')'  */
                          {create_pusharrayref(dotify((yyvsp[-2].symbol),FALSE),stNUMBERARRAYREF);}
    break;

  case 248: /* string_arrayref: tSTRSYM '(' ')'  */
                                 {create_pusharrayref(dotify((yyvsp[-2].symbol),FALSE),stSTRINGARRAYREF);}
    break;

  case 250: /* function: tSIN '(' expression ')'  */
                                  {create_function(fSIN);}
    break;

  case 251: /* function: tASIN '(' expression ')'  */
                             {create_function(fASIN);}
    break;

  case 252: /* function: tCOS '(' expression ')'  */
                            {create_function(fCOS);}
    break;

  case 253: /* function: tACOS '(' expression ')'  */
                             {create_function(fACOS);}
    break;

  case 254: /* function: tTAN '(' expression ')'  */
                            {create_function(fTAN);}
    break;

  case 255: /* function: tATAN '(' expression ')'  */
                             {create_function(fATAN);}
    break;

  case 256: /* function: tATAN '(' expression ',' expression ')'  */
                                             {create_function(fATAN2);}
    break;

  case 257: /* function: tEXP '(' expression ')'  */
                            {create_function(fEXP);}
    break;

  case 258: /* function: tLOG '(' expression ')'  */
                            {create_function(fLOG);}
    break;

  case 259: /* function: tLOG '(' expression ',' expression ')'  */
                                           {create_function(fLOG2);}
    break;

  case 260: /* function: tSQRT '(' expression ')'  */
                             {create_function(fSQRT);}
    break;

  case 261: /* function: tSQR '(' expression ')'  */
                            {create_function(fSQR);}
    break;

  case 262: /* function: tINT '(' expression ')'  */
                            {create_function(fINT);}
    break;

  case 263: /* function: tROUND '(' expression ')'  */
                              {create_function(fROUND);}
    break;

  case 264: /* function: tCEIL '(' expression ')'  */
                             {create_function(fCEIL);}
    break;

  case 265: /* function: tFLOOR '(' expression ')'  */
                              {create_function(fFLOOR);}
    break;

  case 266: /* function: tFRAC '(' expression ')'  */
                             {create_function(fFRAC);}
    break;

  case 267: /* function: tABS '(' expression ')'  */
                            {create_function(fABS);}
    break;

  case 268: /* function: tSIG '(' expression ')'  */
                            {create_function(fSIG);}
    break;

  case 269: /* function: tMOD '(' expression ',' expression ')'  */
                                           {create_function(fMOD);}
    break;

  case 270: /* function: tRAN '(' expression ')'  */
                            {create_function(fRAN);}
    break;

  case 271: /* function: tRAN '(' ')'  */
                 {create_function(fRAN2);}
    break;

  case 272: /* function: tMIN '(' expression ',' expression ')'  */
                                           {create_function(fMIN);}
    break;

  case 273: /* function: tMAX '(' expression ',' expression ')'  */
                                           {create_function(fMAX);}
    break;

  case 274: /* function: tLEN '(' string_expression ')'  */
                                   {create_function(fLEN);}
    break;

  case 275: /* function: tVAL '(' string_expression ')'  */
                                   {create_function(fVAL);}
    break;

  case 276: /* function: tASC '(' string_expression ')'  */
                                   {create_function(fASC);}
    break;

  case 277: /* function: tDEC '(' string_expression ')'  */
                                   {create_function(fDEC);}
    break;

  case 278: /* function: tDEC '(' string_expression ',' expression ')'  */
                                                  {create_function(fDEC2);}
    break;

  case 279: /* function: tINSTR '(' string_expression ',' string_expression ')'  */
                                                           {if (check_compat) lyyerror(sWARNING,"instr() has changed in version 2.712"); create_function(fINSTR);}
    break;

  case 280: /* function: tINSTR '(' string_expression ',' string_expression ',' expression ')'  */
                                                                          {create_function(fINSTR2);}
    break;

  case 281: /* function: tRINSTR '(' string_expression ',' string_expression ')'  */
                                                            {create_function(fRINSTR);}
    break;

  case 282: /* function: tRINSTR '(' string_expression ',' string_expression ',' expression ')'  */
                                                                            {create_function(fRINSTR2);}
    break;

  case 283: /* function: tSYSTEM '(' string_expression ')'  */
                                      {create_function(fSYSTEM);}
    break;

  case 284: /* function: tFRNFN_CALL '(' call_list ')'  */
                                  {create_function(fFRNFN_CALL);}
    break;

  case 285: /* function: tFRNFN_SIZE '(' string_expression ')'  */
                                          {create_function(fFRNFN_SIZE);}
    break;

  case 286: /* function: tFRNBF_GET '(' string_expression ',' expression ',' string_expression ')'  */
                                                                              {create_function(fFRNBF_GET_NUMBER);}
    break;

  case 287: /* function: tFRNBF_SIZE '(' string_expression ')'  */
                                          {create_function(fFRNBF_SIZE);}
    break;

  case 288: /* function: tPEEK '(' hashed_number ')'  */
                                {create_function(fPEEK4);}
    break;

  case 289: /* function: tPEEK '(' string_expression ')'  */
                                    {create_function(fPEEK);}
    break;

  case 290: /* function: tMOUSEX '(' string_expression ')'  */
                                      {create_function(fMOUSEX);}
    break;

  case 291: /* function: tMOUSEX  */
            {create_pushstr("");create_function(fMOUSEX);}
    break;

  case 292: /* function: tMOUSEX '(' ')'  */
                    {create_pushstr("");create_function(fMOUSEX);}
    break;

  case 293: /* function: tMOUSEY '(' string_expression ')'  */
                                      {create_function(fMOUSEY);}
    break;

  case 294: /* function: tMOUSEY  */
            {create_pushstr("");create_function(fMOUSEY);}
    break;

  case 295: /* function: tMOUSEY '(' ')'  */
                    {create_pushstr("");create_function(fMOUSEY);}
    break;

  case 296: /* function: tMOUSEB '(' string_expression ')'  */
                                      {create_function(fMOUSEB);}
    break;

  case 297: /* function: tMOUSEB  */
            {create_pushstr("");create_function(fMOUSEB);}
    break;

  case 298: /* function: tMOUSEB '(' ')'  */
                    {create_pushstr("");create_function(fMOUSEB);}
    break;

  case 299: /* function: tMOUSEMOD '(' string_expression ')'  */
                                        {create_function(fMOUSEMOD);}
    break;

  case 300: /* function: tMOUSEMOD  */
              {create_pushstr("");create_function(fMOUSEMOD);}
    break;

  case 301: /* function: tMOUSEMOD '(' ')'  */
                      {create_pushstr("");create_function(fMOUSEMOD);}
    break;

  case 302: /* function: tAND '(' expression ',' expression ')'  */
                                           {create_function(fAND);}
    break;

  case 303: /* function: tOR '(' expression ',' expression ')'  */
                                          {create_function(fOR);}
    break;

  case 304: /* function: tBITNOT '(' expression ')'  */
                               {create_function(fBITNOT);}
    break;

  case 305: /* function: tEOR '(' expression ',' expression ')'  */
                                           {create_function(fEOR);}
    break;

  case 306: /* function: tSHL '(' expression ',' expression ')'  */
                                           {create_function(fSHL);}
    break;

  case 307: /* function: tSHR '(' expression ',' expression ')'  */
                                           {create_function(fSHR);}
    break;

  case 308: /* function: tTELL '(' hashed_number ')'  */
                                {create_function(fTELL);}
    break;

  case 309: /* function: tTOKEN '(' string_expression ',' string_arrayref ',' string_expression ')'  */
                                                                               {add_command(cTOKEN2);}
    break;

  case 310: /* function: tTOKEN '(' string_expression ',' string_arrayref ')'  */
                                                         {add_command(cTOKEN);}
    break;

  case 311: /* function: tSPLIT '(' string_expression ',' string_arrayref ',' string_expression ')'  */
                                                                               {add_command(cSPLIT2);}
    break;

  case 312: /* function: tSPLIT '(' string_expression ',' string_arrayref ')'  */
                                                         {add_command(cSPLIT);}
    break;

  case 313: /* function: tEXECUTE '(' call_list ')'  */
                               {create_execute(0);add_command(cSWAP);add_command(cPOP);}
    break;

  case 314: /* function: tOPEN '(' tPRINTER ')'  */
                           {create_myopen(OPEN_PRINTER);}
    break;

  case 315: /* function: tOPEN '(' string_expression ')'  */
                                    {create_myopen(0);}
    break;

  case 316: /* function: tOPEN '(' string_expression ',' string_expression ')'  */
                                                          {create_myopen(OPEN_HAS_MODE);}
    break;

  case 317: /* function: tOPEN '(' hashed_number ',' tPRINTER ')'  */
                                             {create_myopen(OPEN_PRINTER+OPEN_HAS_STREAM);}
    break;

  case 318: /* function: tOPEN '(' hashed_number ',' string_expression ')'  */
                                                      {create_myopen(OPEN_HAS_STREAM);}
    break;

  case 319: /* function: tOPEN '(' hashed_number ',' string_expression ',' string_expression ')'  */
                                                                            {create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}
    break;

  case 320: /* function: tEVAL '(' string_expression ')'  */
                                    {create_eval(evNUMBER);}
    break;

  case 321: /* function: tBEAM_OPEN '(' expression ',' expression ',' string_expression ')'  */
                                                                       {create_function(fBEAM_OPEN);}
    break;

  case 322: /* function: tBEAM_RUNNING '(' expression ')'  */
                                     {create_function(fBEAM_RUNNING);}
    break;

  case 323: /* function: tBEAM_BUTTON '(' string_expression ',' expression ',' expression ')'  */
                                                                         {create_function(fBEAM_BUTTON);}
    break;

  case 324: /* function: tBEAM_INPUT '(' string_expression ',' expression ',' expression ')'  */
                                                                        {create_function(fBEAM_INPUT);}
    break;

  case 325: /* function: tBEAM_CHECKBOX '(' string_expression ',' expression ')'  */
                                                            {create_function(fBEAM_CHECKBOX);}
    break;

  case 326: /* function: tBEAM_COMBO '(' string_expression ',' expression ',' expression ',' expression ',' expression ')'  */
                                                                                                      {create_function(fBEAM_COMBO);}
    break;

  case 327: /* function: tBEAM_SLIDER '(' expression ',' expression ',' expression ',' expression ',' expression ')'  */
                                                                                                {create_function(fBEAM_SLIDER);}
    break;

  case 328: /* function: tBEAM_TIME '(' ')'  */
                       {create_function(fBEAM_TIME);}
    break;

  case 329: /* function: tBEAM_MSGBOX '(' string_expression ',' string_expression ')'  */
                                                                 {create_function(fBEAM_MSGBOX);}
    break;

  case 330: /* function: tBEAM_CONFIRM '(' string_expression ',' string_expression ')'  */
                                                                  {create_function(fBEAM_CONFIRM);}
    break;

  case 331: /* const: number  */
              {(yyval.fnum)=(yyvsp[0].fnum);}
    break;

  case 332: /* const: '+' number  */
               {(yyval.fnum)=(yyvsp[0].fnum);}
    break;

  case 333: /* const: '-' number  */
               {(yyval.fnum)=-(yyvsp[0].fnum);}
    break;

  case 334: /* number: tFNUM  */
              {(yyval.fnum)=(yyvsp[0].fnum);}
    break;

  case 335: /* number: tDIGITS  */
            {(yyval.fnum)=strtod((yyvsp[0].digits),NULL);}
    break;

  case 336: /* number: tHEXDIGITS  */
               {(yyval.fnum)=(double)strtoul((yyvsp[0].digits),NULL,16);}
    break;

  case 337: /* number: tBINDIGITS  */
               {(yyval.fnum)=(double)strtoul((yyvsp[0].digits),NULL,2);}
    break;

  case 338: /* symbol_or_lineno: tDIGITS  */
                          {(yyval.symbol)=my_strdup(dotify((yyvsp[0].digits),FALSE));}
    break;

  case 339: /* symbol_or_lineno: tSYMBOL  */
            {(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}
    break;

  case 340: /* dimlist: tSYMBOL '(' call_list ')'  */
                                   {create_dim(dotify((yyvsp[-3].symbol),FALSE),'D');}
    break;

  case 341: /* dimlist: dimlist ',' tSYMBOL '(' call_list ')'  */
                                          {create_dim(dotify((yyvsp[-3].symbol),FALSE),'D');}
    break;

  case 342: /* dimlist: tSTRSYM '(' call_list ')'  */
                              {create_dim(dotify((yyvsp[-3].symbol),FALSE),'S');}
    break;

  case 343: /* dimlist: dimlist ',' tSTRSYM '(' call_list ')'  */
                                          {create_dim(dotify((yyvsp[-3].symbol),FALSE),'S');}
    break;

  case 344: /* function_or_array: tSYMBOL '(' call_list ')'  */
                                             {(yyval.symbol)=my_strdup(dotify((yyvsp[-3].symbol),FALSE));}
    break;

  case 345: /* stringfunction_or_array: tSTRSYM '(' call_list ')'  */
                                                   {(yyval.symbol)=my_strdup(dotify((yyvsp[-3].symbol),FALSE));}
    break;

  case 346: /* $@11: %empty  */
           {add_command(cPUSHFREE);}
    break;

  case 353: /* $@12: %empty  */
                                 {missing_endsub++;missing_endsub_line=yylineno;pushlabel();report_if_missing("can not define a function in a loop or an if-statement",FALSE);if (function_type!=ftNONE) {lyyerror(sERROR,"nested functions not allowed");YYABORT;}}
    break;

  case 354: /* $@13: %empty  */
                      {if (exported) create_subr_link((yyvsp[0].symbol)); create_label((yyvsp[0].symbol),cUSER_FUNCTION);
	               add_command(cPUSHSYMLIST);add_command(cCLEARSYMREFS);start_symref_chain();
		       create_count_params();}
    break;

  case 355: /* $@14: %empty  */
                          {create_require(stFREE);add_command(cPOP);}
    break;

  case 356: /* function_definition: export tSUB $@12 function_name $@13 '(' paramlist ')' $@14 statement_list endsub  */
               {add_command(cCLEARSYMREFS);end_symref_chain();add_command(cPOPSYMLIST);create_check_return_value(ftNONE,function_type);function_type=ftNONE;add_command(cRETURN_FROM_CALL);create_endfunction();poplabel();}
    break;

  case 357: /* endsub: tEOPROG  */
                {if (missing_endsub) {sprintf(string,"subroutine starting at line %d has seen no 'end sub' at end of program",missing_endsub_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 358: /* endsub: tENDSUB  */
            {missing_endsub--;}
    break;

  case 359: /* function_name: tSYMBOL  */
                       {function_type=ftNUMBER;current_function=my_strdup(dotify((yyvsp[0].symbol),FALSE));(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}
    break;

  case 360: /* function_name: tSTRSYM  */
            {function_type=ftSTRING;current_function=my_strdup(dotify((yyvsp[0].symbol),FALSE));(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}
    break;

  case 361: /* export: %empty  */
                    {exported=FALSE;}
    break;

  case 362: /* export: tEXPORT  */
            {exported=TRUE;}
    break;

  case 363: /* export: tRUNTIME_CREATED_SUB  */
                         {exported=FALSE;}
    break;

  case 364: /* export: tRUNTIME_CREATED_SUB tEXPORT  */
                                 {exported=TRUE;}
    break;

  case 367: /* local_item: tSYMBOL  */
                    {create_makelocal(dotify((yyvsp[0].symbol),FALSE),syNUMBER);}
    break;

  case 368: /* local_item: tSTRSYM  */
            {create_makelocal(dotify((yyvsp[0].symbol),FALSE),sySTRING);}
    break;

  case 369: /* local_item: tSYMBOL '(' call_list ')'  */
                              {create_makelocal(dotify((yyvsp[-3].symbol),FALSE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),FALSE),'d');}
    break;

  case 370: /* local_item: tSTRSYM '(' call_list ')'  */
                              {create_makelocal(dotify((yyvsp[-3].symbol),FALSE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),FALSE),'s');}
    break;

  case 373: /* static_item: tSYMBOL  */
                     {create_makestatic(dotify((yyvsp[0].symbol),TRUE),syNUMBER);}
    break;

  case 374: /* static_item: tSTRSYM  */
            {create_makestatic(dotify((yyvsp[0].symbol),TRUE),sySTRING);}
    break;

  case 375: /* static_item: tSYMBOL '(' call_list ')'  */
                              {create_makestatic(dotify((yyvsp[-3].symbol),TRUE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),TRUE),'D');}
    break;

  case 376: /* static_item: tSTRSYM '(' call_list ')'  */
                              {create_makestatic(dotify((yyvsp[-3].symbol),TRUE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),TRUE),'S');}
    break;

  case 380: /* paramitem: tSYMBOL  */
                   {create_require(stNUMBER);create_makelocal(dotify((yyvsp[0].symbol),FALSE),syNUMBER);add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 381: /* paramitem: tSTRSYM  */
            {create_require(stSTRING);create_makelocal(dotify((yyvsp[0].symbol),FALSE),sySTRING);add_command_with_sym_and_diag(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 382: /* paramitem: tSYMBOL '(' ')'  */
                    {create_require(stNUMBERARRAYREF);create_arraylink(dotify((yyvsp[-2].symbol),FALSE),stNUMBERARRAYREF);}
    break;

  case 383: /* paramitem: tSTRSYM '(' ')'  */
                    {create_require(stSTRINGARRAYREF);create_arraylink(dotify((yyvsp[-2].symbol),FALSE),stSTRINGARRAYREF);}
    break;

  case 384: /* $@15: %empty  */
               {loop_nesting++;add_command(cBEGIN_LOOP_MARK);missing_next++;missing_next_line=yylineno;}
    break;

  case 385: /* $@16: %empty  */
            {pushname(dotify((yyvsp[-1].symbol),FALSE)); /* will be used by next_symbol to check equality,NULL */
	     add_command(cRESETSKIPONCE);
	     add_command(cRESETSKIPONCE2);
	     pushgoto();add_command_with_switch_state(cCONTINUE_HERE);}
    break;

  case 386: /* $@17: %empty  */
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
    break;

  case 387: /* $@18: %empty  */
                         {
             swap();popgoto();poplabel();}
    break;

  case 388: /* for_loop: tFOR $@15 tSYMBOL tEQU $@16 expression tTO expression step_part $@17 statement_list $@18 next next_symbol  */
                           {add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}
    break;

  case 389: /* next: tEOPROG  */
              {if (missing_next) {sprintf(string,"for-loop starting at line %d has seen no 'next' at end of program",missing_next_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 390: /* next: tNEXT  */
          {missing_next--;}
    break;

  case 391: /* next: tENDIF  */
           {report_conflicting_close("a closing next is expected before endif",'e');}
    break;

  case 392: /* next: tWEND  */
          {report_conflicting_close("a closing next is expected before wend",'w');}
    break;

  case 393: /* next: tUNTIL  */
           {report_conflicting_close("a closing next is expected before until",'l');}
    break;

  case 394: /* next: tLOOP  */
          {report_conflicting_close("a closing next is expected before loop",'l');}
    break;

  case 395: /* step_part: %empty  */
           {create_pushdbl(1);}
    break;

  case 397: /* next_symbol: %empty  */
              {pop(stSTRING);}
    break;

  case 398: /* next_symbol: tSYMBOL  */
            {if (strcmp(pop(stSTRING)->pointer,dotify((yyvsp[0].symbol),FALSE))) 
             {lyyerror(sERROR,"'for' and 'next' do not match"); YYABORT;}
           }
    break;

  case 399: /* $@19: %empty  */
                                 {push_switch_id();add_command(cBEGIN_SWITCH_MARK);}
    break;

  case 400: /* switch_number_or_string: tSWITCH $@19 number_or_string sep_list case_list default tSEND  */
                                                                  {add_command(cBREAK_HERE);add_command(cPOP);add_command(cEND_SWITCH_MARK);pop_switch_id();}
    break;

  case 406: /* $@20: %empty  */
      {add_command(cSWITCH_COMPARE);add_command(cDECIDE);add_command(cNEXT_CASE);}
    break;

  case 407: /* case_list: case_list tCASE number_or_string $@20 statement_list  */
                                                                                                  {add_command(cNEXT_CASE_HERE);}
    break;

  case 409: /* $@21: %empty  */
                  {add_command(cNEXT_CASE_HERE);}
    break;

  case 411: /* $@22: %empty  */
             {loop_nesting++;add_command(cBEGIN_LOOP_MARK);add_command_with_switch_state(cCONTINUE_HERE);missing_loop++;missing_loop_line=yylineno;pushgoto();}
    break;

  case 413: /* loop: tEOPROG  */
              {if (missing_loop) {sprintf(string,"do-loop starting at at line %d has seen no 'loop' at end of program",missing_loop_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 414: /* loop: tLOOP  */
          {missing_loop--;popgoto();add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}
    break;

  case 415: /* loop: tENDIF  */
           {report_conflicting_close("a closing loop is expected before endif",'e');}
    break;

  case 416: /* loop: tWEND  */
          {report_conflicting_close("a closing loop is expected before wend",'w');}
    break;

  case 417: /* loop: tUNTIL  */
           {report_conflicting_close("a closing loop is expected before until",'l');}
    break;

  case 418: /* loop: tNEXT  */
          {report_conflicting_close("a closing loop is expected before next",'n');}
    break;

  case 419: /* $@23: %empty  */
                   {loop_nesting++;add_command(cBEGIN_LOOP_MARK);add_command_with_switch_state(cCONTINUE_HERE);missing_wend++;missing_wend_line=yylineno;pushgoto();}
    break;

  case 420: /* $@24: %empty  */
              {add_command(cDECIDE);
	      pushlabel();}
    break;

  case 422: /* wend: tEOPROG  */
              {if (missing_wend) {sprintf(string,"while-loop starting at line %d has seen no 'wend' at end of program",missing_wend_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 423: /* wend: tWEND  */
          {missing_wend--;swap();popgoto();poplabel();add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}
    break;

  case 424: /* $@25: %empty  */
                     {loop_nesting++;add_command(cBEGIN_LOOP_MARK);add_command_with_switch_state(cCONTINUE_HERE);missing_until++;missing_until_line=yylineno;pushgoto();}
    break;

  case 426: /* until: tEOPROG  */
               {if (missing_until) {sprintf(string,"repeat-loop starting at line %d has seen no 'until' at end of program",missing_until_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 427: /* until: tUNTIL expression  */
                      {missing_until--;add_command(cDECIDE);popgoto();add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}
    break;

  case 428: /* until: tENDIF  */
           {report_conflicting_close("a closing until is expected before endif",'e');}
    break;

  case 429: /* until: tWEND  */
          {report_conflicting_close("a closing until is expected before wend",'w');}
    break;

  case 430: /* until: tLOOP  */
          {report_conflicting_close("a closing until is expected before loop",'l');}
    break;

  case 431: /* until: tNEXT  */
          {report_conflicting_close("a closing until is expected before next",'n');}
    break;

  case 432: /* $@26: %empty  */
                          {add_command(cDECIDE);storelabel();pushlabel();}
    break;

  case 433: /* $@27: %empty  */
                 {missing_endif++;missing_endif_line=yylineno;}
    break;

  case 434: /* $@28: %empty  */
                                                                               {swap();matchgoto();swap();poplabel();}
    break;

  case 435: /* $@29: %empty  */
                     {poplabel();}
    break;

  case 437: /* endif: tEOPROG  */
               {if (missing_endif) {sprintf(string,"if-clause starting at line %d has seen no 'fi' at end of program",missing_endif_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 438: /* endif: tENDIF  */
           {missing_endif--;}
    break;

  case 439: /* endif: tWEND  */
          {report_conflicting_close("a closing endif is expected before wend",'w');}
    break;

  case 440: /* endif: tUNTIL  */
           {report_conflicting_close("a closing endif is expected before until",'l');}
    break;

  case 441: /* endif: tLOOP  */
          {report_conflicting_close("a closing endif is expected before loop",'l');}
    break;

  case 442: /* endif: tNEXT  */
          {report_conflicting_close("a closing endif is expected before next",'n');}
    break;

  case 443: /* $@30: %empty  */
                         {in_short_if++;add_command(cDECIDE);pushlabel();}
    break;

  case 445: /* end_of_if: tENDIF  */
                  {error(sERROR,"short if-statement (i.e. without 'then') does not allow 'endif'");}
    break;

  case 446: /* end_of_if: tIMPLICITENDIF  */
                   {poplabel();}
    break;

  case 450: /* $@31: %empty  */
        {add_command(cDECIDE);pushlabel();}
    break;

  case 451: /* $@32: %empty  */
        {swap();matchgoto();swap();poplabel();}
    break;

  case 456: /* $@33: %empty  */
              {add_command(cCHKPROMPT);}
    break;

  case 458: /* input: tSYMBOL  */
               {create_myread('d',tileol);add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 459: /* input: tSYMBOL '(' call_list ')'  */
        {create_myread('d',tileol);create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNARRAY);}
    break;

  case 460: /* input: tSTRSYM  */
            {create_myread('s',tileol);add_command_with_sym_and_diag(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 461: /* input: tSTRSYM '(' call_list ')'  */
        {create_myread('s',tileol);create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNSTRINGARRAY);}
    break;

  case 464: /* readitem: tSYMBOL  */
                  {create_readdata('d');add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 465: /* readitem: tSYMBOL '(' call_list ')'  */
    {create_readdata('d');create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNARRAY);}
    break;

  case 466: /* readitem: tSTRSYM  */
            {create_readdata('s');add_command_with_sym_and_diag(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 467: /* readitem: tSTRSYM '(' call_list ')'  */
    {create_readdata('s');create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNSTRINGARRAY);}
    break;

  case 468: /* datalist: tSTRING  */
                  {create_strdata((yyvsp[0].string));}
    break;

  case 469: /* datalist: const  */
          {create_dbldata((yyvsp[0].fnum));}
    break;

  case 470: /* datalist: datalist ',' tSTRING  */
                          {create_strdata((yyvsp[0].string));}
    break;

  case 471: /* datalist: datalist ',' const  */
                       {create_dbldata((yyvsp[0].fnum));}
    break;

  case 475: /* printlist: string_expression  */
                      {create_print('s');}
    break;

  case 476: /* printlist: printlist ',' string_expression  */
                                    {create_print('s');}
    break;

  case 477: /* using: %empty  */
       {create_print('d');}
    break;

  case 478: /* using: tUSING string_expression  */
                             {create_print('u');}
    break;

  case 479: /* using: tUSING '(' string_expression ',' string_expression ')'  */
                                                           {create_print('U');}
    break;

  case 480: /* $@34: %empty  */
                       {add_command_with_sym_and_diag(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);create_pps(cPUSHSTREAM,1);}
    break;

  case 481: /* inputbody: '#' tSYMBOL $@34 inputlist  */
                                                                                                                               {create_pps(cPOPSTREAM,0);}
    break;

  case 482: /* $@35: %empty  */
                {create_pushdbl(atoi((yyvsp[0].digits)));create_pps(cPUSHSTREAM,1);}
    break;

  case 483: /* inputbody: '#' tDIGITS $@35 inputlist  */
                                                                                {create_pps(cPOPSTREAM,0);}
    break;

  case 484: /* $@36: %empty  */
                           {create_pps(cPUSHSTREAM,1);}
    break;

  case 485: /* inputbody: '#' '(' expression ')' $@36 inputlist  */
                                                                  {create_pps(cPOPSTREAM,0);}
    break;

  case 486: /* $@37: %empty  */
                                          {add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 487: /* inputbody: tAT '(' expression ',' expression ')' $@37 prompt inputlist  */
                                                                                                                                        {create_pps(cPOPSTREAM,0);}
    break;

  case 488: /* $@38: %empty  */
    {create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 489: /* inputbody: $@38 prompt inputlist  */
                                                                               {create_pps(cPOPSTREAM,0);}
    break;

  case 490: /* prompt: %empty  */
                    {create_pushstr("?");create_print('s');}
    break;

  case 491: /* prompt: tSTRING  */
            {create_pushstr((yyvsp[0].string));create_print('s');}
    break;

  case 492: /* printintro: %empty  */
                               {create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 493: /* printintro: '#' tSYMBOL  */
                {add_command_with_sym_and_diag(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);create_pps(cPUSHSTREAM,0);}
    break;

  case 494: /* printintro: '#' tDIGITS  */
                {create_pushdbl(atoi((yyvsp[0].digits)));create_pps(cPUSHSTREAM,0);}
    break;

  case 495: /* printintro: '#' '(' expression ')'  */
                           {create_pps(cPUSHSTREAM,0);}
    break;

  case 496: /* printintro: tREVERSE  */
             {create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 497: /* printintro: tCOLOUR '(' string_expression ')'  */
                                      {create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 498: /* printintro: tCOLOUR '(' string_expression ',' string_expression ')'  */
                                                            {create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 499: /* printintro: tAT '(' expression ',' expression ')'  */
                                          {add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 500: /* printintro: tREVERSE tAT '(' expression ',' expression ')'  */
                                                   {add_command(cMOVE);create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 501: /* printintro: tCOLOUR '(' string_expression ')' tAT '(' expression ',' expression ')'  */
                                                                            {add_command(cMOVE);create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 502: /* printintro: tCOLOUR '(' string_expression ',' string_expression ')' tAT '(' expression ',' expression ')'  */
                                                                                                  {add_command(cMOVE);create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 503: /* printintro: tAT '(' expression ',' expression ')' tREVERSE  */
                                                   {create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);add_command(cMOVE);}
    break;

  case 504: /* printintro: tAT '(' expression ',' expression ')' tCOLOUR '(' string_expression ')'  */
                                                                            {create_colour(2);add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 505: /* printintro: tAT '(' expression ',' expression ')' tCOLOUR '(' string_expression ',' string_expression ')'  */
                                                                                                  {create_colour(3);add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 508: /* goto_list: symbol_or_lineno  */
                            {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP);}
    break;

  case 509: /* goto_list: goto_list ',' symbol_or_lineno  */
                                   {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP);}
    break;

  case 510: /* gosub_list: symbol_or_lineno  */
                             {create_gosub((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP);}
    break;

  case 511: /* gosub_list: gosub_list ',' symbol_or_lineno  */
                                    {create_gosub((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP);}
    break;



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

