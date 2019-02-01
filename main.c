#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include "lex.h"

//	statements	->	expression SEMI | expression SEMI statements
//	expression	->	term E
//	E			->	PLUS term E | NULL
//	term		->	factor T
//	T			->	MULT factor T | NULL
//	factor		->	NUM_ID | LB expression RB

main() {
	statements();
}
