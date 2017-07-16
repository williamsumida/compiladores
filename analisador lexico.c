/*Trabalho de compiladores
	Analisador lexico
  William Hitoshi Sumida*/
%option noyywrap
%x commentario
%{
int collumn = 0;
int lines = 1;
%}

comentario_linha \/\/([^\n])*

%%
"/*"         {collumn+=strlen(yytext);}BEGIN(commentario);

<comentario>[^*\n]*        {collumn+=strlen(yytext);}
<comentario>"*"+[^*/\n]* 	{collumn+=strlen(yytext);}
<comentario>\n             lines++;{collumn=0;}
<comentario>"*"+"/"        {collumn+=strlen(yytext);}BEGIN(INITIAL);

{comentario_linha}  {lines++;}{collumn=0;}



"void"		{printf("VOID\n");}					{collumn+=strlen(yytext);}
"while"    	{printf("WHILE\n");}				{collumn+=strlen(yytext);}
"for"      	{printf("FOR\n");}					{collumn+=strlen(yytext);}
"if"       	{printf("IF\n");}					{collumn+=strlen(yytext);}
"else"     	{printf("ELSE\n");}					{collumn+=strlen(yytext);}
"int"		{printf("INT\n");}					{collumn+=strlen(yytext);}
"char"     	{printf("CHAR\n");}					{collumn+=strlen(yytext);}
"return"  	{printf("RETURN\n");}				{collumn+=strlen(yytext);}
"break"    	{printf("BREAK\n");}				{collumn+=strlen(yytext);}
"switch"   	{printf("SWITCH\n");}				{collumn+=strlen(yytext);}
"case"     	{printf("CASE\n");}					{collumn+=strlen(yytext);}
"default"  	{printf("DEFAULT\n");}				{collumn+=strlen(yytext);}
"do"       	{printf("DO\n");}					{collumn+=strlen(yytext);}
"+="       	{printf("ADD_ASSIGN\n");}			{collumn+=strlen(yytext);}
"-="       	{printf("MINUS_ASSIGN\n");}			{collumn+=strlen(yytext);}
"++"       	{printf("INC\n");}					{collumn+=strlen(yytext);}
"--"      	{printf("DEC\n");}					{collumn+=strlen(yytext);}
"+"       	{printf("PLUS\n");}					{collumn+=strlen(yytext);}
"-"        	{printf("MINUS\n");}				{collumn+=strlen(yytext);}
"*"        	{printf("MULTIPLY\n");}				{collumn+=strlen(yytext);}
"%"        	{printf("REMAINDER\n");}			{collumn+=strlen(yytext);}
"&"        	{printf("BITWISE_AND\n");}			{collumn+=strlen(yytext);}
"|"        	{printf("BITWISE_OR\n");}			{collumn+=strlen(yytext);}
"~"        	{printf("BITWISE_NOT\n");}			{collumn+=strlen(yytext);}
"^"        	{printf("BITWISE_XOR\n");}			{collumn+=strlen(yytext);}
"!"        	{printf("NOT\n");}					{collumn+=strlen(yytext);}
"&&"     	{printf("LOGICAL_AND\n");}			{collumn+=strlen(yytext);}
"||"       	{printf("LOGICAL_OR\n");}			{collumn+=strlen(yytext);}
"=="       	{printf("LOGICAL_OREQUAL\n");}		{collumn+=strlen(yytext);}
"!="       	{printf("LOGICAL_ORNOT_EQUAL\n");}	{collumn+=strlen(yytext);}
"<"        	{printf("LESS_THAN\n");}			{collumn+=strlen(yytext);}
">"        	{printf("GREATER_THAN\n");}			{collumn+=strlen(yytext);}
"<="      	{printf("LESS_EQUAL\n");}			{collumn+=strlen(yytext);}
">="       	{printf("GREATER_EQUAL\n");}		{collumn+=strlen(yytext);}
">>"       	{printf("R_SHIFT\n");}				{collumn+=strlen(yytext);}
"<<"       	{printf("L_SHIFT\n");}				{collumn+=strlen(yytext);}
"="        	{printf("ASSIGN\n");}				{collumn+=strlen(yytext);}
";"        	{printf("SEMICOLON\n");}			{collumn+=strlen(yytext);}
","        	{printf("COMMA\n");}				{collumn+=strlen(yytext);}
":"        	{printf("COLON\n");}				{collumn+=strlen(yytext);}
"("        	{printf("L_PAREN\n");}				{collumn+=strlen(yytext);}
")"        	{printf("R_PAREN\n");}				{collumn+=strlen(yytext);}
"{"        	{printf("L_CURLY_BRACKET\n");}		{collumn+=strlen(yytext);}
"}"        	{printf("R_BRACE_BRACKET\n");}		{collumn+=strlen(yytext);}
"?"        	{printf("TERNARY_CONDITIONAL\n");}	{collumn+=strlen(yytext);}
"#"        	{printf("NUMBER_SIGN\n");}			{collumn+=strlen(yytext);}
"printf"   	{printf("PRINTF\n");}				{collumn+=strlen(yytext);}
"scanf"    	{printf("SCANF\n");}				{collumn+=strlen(yytext);}
"define"   	{printf("DEFINE\n");}				{collumn+=strlen(yytext);}
"exit"     	{printf("EXIT\n");}					{collumn+=strlen(yytext);}



[0]["x"|"X"][0-9a-fA-F]+ 		{printf("NUM_HEXA(%s)\n",yytext);}{collumn+=strlen(yytext);}
"'"[\\]?[@a-zA-Z]"'"  			{printf("CHARACTER(%s)\n",yytext);}{collumn+=strlen(yytext);}
["][ a-zA-Z0-9]+["]				{printf("STRING(%s)\n",yytext);}{collumn+=strlen(yytext);}
[_a-zA-Z][a-zA-Z0-9]* 			{printf("IDENTIFIER(%s)\n",yytext);}{collumn+=strlen(yytext);}
[0][1-7][0-7]*					{printf("NUM_OCTAL(%s)\n",yytext);}{collumn+=strlen(yytext);}
[00]?[0-9]+ 					{printf("NUM_INTEGER(%s)\n",yytext);}{collumn+=strlen(yytext);}


[ \t]      				{collumn++;}
[\n]       				{lines++;}{collumn=0;}


//  error:lexical:1:4: @
.          	{collumn++;}printf( "error:lexical:%d:%d: %s\n", lines, collumn, yytext );
//.          	{collumn++;}printf( "ERRO: LINHA: %d COLUNA: %d\n", lines, collumn );

%%
int main(){
	yylex();
	return 0;
}
