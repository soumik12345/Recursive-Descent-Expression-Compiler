#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include "lex.h"

char *Names[] = {"t0", "t1", "t2", "t3", "t4", "t5", "t6", "t7"}; // Stack containing Variables Names
char **Name = Names;

// When a new Variable Name is required, it is popped off the stack
char *newname() {
    if(Name >= &Names[sizeof(Names) / sizeof(*Names)]) {
        fprintf(stderr, "Expression too complex for compiler to handle: %d\n", yylineno);
        exit(1);
    }
    return (*Name ++);
}

// When a variable is no longer needed, it is pushed back
freename(char *s) {
    if(Name <= Names)
        fprintf(stderr, "Name Stack Underflow: %d\n", yylineno);
    else
        *--Name = s;
    
}