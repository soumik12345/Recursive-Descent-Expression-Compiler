#include<stdio.h>
#include "lex.h"

//	statements	->	expression SEMI | expression SEMI statements
//	expression	->	term E
//	E			->	PLUS term E | NULL
//	term		->	factor T
//	T			->	MULT factor T | NULL
//	factor		->	NUM_ID | LB expression RB

statements() {
	
	//	statements	->	expression SEMI | expression SEMI statements
	
	expression();
	
	if(match(SEMI))
		advance();
	
	else
		fprintf(stderr, "Missiong Semicolor at Line: %d\n", yylineno);
		
	if(!match(EOI))
		expression();
}

expression() {
	
	//	expression	->	term E
	
	term();
	E();
}

E() {
	
	//	E	->	PLUS term E | NULL	
	
	if(match(PLUS)) {
		advance();
		term();
		E();
	}
}

term() {
	
	//	term	->	factor T
	
	factor();
	T();
}

T() {
	
	//	T	->	MULT factor T | NULL
	
	if(match(MULT)) {
		advance();
		factor();
		T();
	}
}

factor() {
	
	//	factor	->	NUM_ID | LB expression RB
	
	if(match(NUM_ID))
		advance();
	else if(match(LB)) {
		advance();
		expression();
		if(match(RB))
			advance();
		else
			fprintf(stderr, "Parentesis Mismatch: %d\n", yylineno);
	}
	else
		fprintf(stderr, "Constant or Identifier Expected: %d\n", yylineno);
}
