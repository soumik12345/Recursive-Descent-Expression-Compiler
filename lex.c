#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include "lex.h"

char* yytext;	//	Current Lexeme
int yyleng;		//	Length of Lexeme
int yylineno;	//	Current Input Line no

/*	Global Variables	*/
static int Lookahead = -1; // Lookahead Token

lex() {
	static char input_buffer[128];
	char *current;
	
	current = yytext + yyleng; // Skip current lexeme
	
	while(1) {
		
		while(!current) {
			
			current = input_buffer;
			
			if(!gets(input_buffer)) { // Gets line
				*current = '\0';
				return EOI;
			}
			
			++yylineno; // Increments Line no
			
			while(isspace(*current)) // Skips past blank lines
				++current;
		}
		
		for(; *current; ++current) {
			yytext = current;
			yyleng = 1;
			
			switch(*current) {
				
				case EOF: return EOI;
				
				case ';': return SEMI;
				
				case '+': return PLUS;
				
				case '*': return MULT;
				
				case '(': return LB;
				
				case ')': return RB;
				
				case '\n': // Fall Through
				case '\t': // Fall Through
				case ' ' : break;
				
				default:
					if(!isalnum(*current))
						fprintf(stderr, "Illegeal Character: %c\n", *current);
					else {
						while(isalnum(*current))
							++current;
						yyleng = current - yytext;
						return NUM_ID;
					}
					break;
			}
		}
	}
}

int match(int token) {
	if(Lookahead == 1)
		Lookahead = lex();
	return token == Lookahead; 
}

void advance() {
	Lookahead = lex();
}

// int main() {
// 	printf("%x\n", lex());
// 	return 0;
// }
