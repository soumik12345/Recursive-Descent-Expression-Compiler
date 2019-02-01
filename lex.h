#define EOI 	0;		// 	End of Input
#define SEMI 	1;		// 	;
#define PLUS 	2;		// 	+
#define MULT 	3;		// 	*
#define LB	 	4;		// 	(
#define RB	 	5;		// 	)
#define NUM_ID	6;		//	Decimal Number or ID

extern char* yytext;	//	Current Lexeme
extern int yyleng; 		//	Length of Lexeme
extern int yylineno;	//	Current Input Line no
