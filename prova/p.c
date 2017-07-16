#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printToken(int n){
    if(n==1)
        printf("ID");
    if(n==2)
        printf("IF");
    if(n==3)
        printf("ID");
    if(n==4)
        printf("NUM");
    if(n==5)
        printf("REAL");
    if(n==6)
        printf("ERRO");
    if(n==9)
        printf("REAL");
    if(n==10)
        printf("WHITE SPACE");
}

void createTable(int tabela[12][11]){

    int i=0;
    int j=0;
    // wtf man
    while(i!=12){
        j=0;
        while(j!=11){
            tabela[i][j] = -1;
            j++;
        }
    i++;
    }
    i=0;
    tabela[0][0]=3;
    tabela[0][1]=1;
    tabela[0][2]=3;
    tabela[0][3]=4;
    tabela[0][5]=6;
    tabela[0][8]=3;
    tabela[0][7]=11;
    tabela[0][10]=3;

    tabela[1][0]=3;
    tabela[1][1]=3;
    tabela[1][2]=2;
    tabela[1][3]=3;
    tabela[1][8]=3;

    tabela[2][0]=3;
    tabela[2][1]=3;
    tabela[2][2]=3;
    tabela[2][3]=3;
    tabela[2][8]=3;

    tabela[3][0]=3;
    tabela[3][1]=3;
    tabela[3][2]=3;
    tabela[3][3]=3;
    tabela[3][8]=3;

    tabela[4][3]=4;
    tabela[4][5]=5;
    tabela[4][8]=7;

    tabela[5][3]=5;

    tabela[7][3]=9;
    tabela[7][9]=8;
    tabela[7][10]=8;

    tabela[8][3]=9;

    tabela[9][3]=9;

    int tabela2[12][11] = {
//    0     1       2       3           4           5           6           7       8       9       10
//  a-z     i       f       0-9       whitesp       .        other         \n       e       +       -
     3,     1,      3,       4,          6,         -1,         10,        11,      3,     -1,     -1, // 0
     3,     3,      2,       3,         -1,         -1,         -1,        -1,      3,     -1,     -1, // 1
     3,     3,      3,       3,         -1,         -1,         -1,        -1,      3,     -1,     -1, // 2
     3,     3,      3,       3,         -1,         -1,         -1,        -1,      3,     -1,     -1, // 3
    -1,    -1,     -1,       4,         -1,          5,         -1,        -1,      7,     -1,     -1, // 4
    -1,    -1,     -1,       5,         -1,         -1,         -1,        -1,     -1,     -1,     -1, // 5
    -1,    -1,     -1,      -1,         -1,         -1,         -1,        -1,     -1,     -1,     -1, // 6
    -1,    -1,     -1,       9,         -1,         -1,         -1,        -1,     -1,      8,      8, // 7
    -1,    -1,     -1,       9,         -1,         -1,         -1,        -1,     -1,     -1,     -1, // 8
    -1,    -1,     -1,       9,         -1,         -1,         -1,        -1,     -1,     -1,     -1, // 9
    -1,    -1,     -1,      -1,         -1,         -1,         -1,        -1,     -1,     -1,     -1, // 10
    -1,    -1,     -1,      -1,         -1,         -1,         -1,        -1,     -1,     -1,     -1, // 11
    };
}


int getSymbol(char valor){
	if(valor=='+'){return(10);}
	else if(valor=='-'){return(9);}
	else if(valor=='i'){return(1);}
	else if(valor=='f'){return(2);}
	else if(valor=='.'){return(5);}
    else if(valor=='e'){return(8);}
	else if(valor>='a' && valor<='z'){return(0);}
    else if(valor>='0' && valor<='9'){return(3);}
	else if(valor==' '){return(4);}
	else if(valor=='\n'){return(7);}
	/* ERRO */
	else{return(6);}
}

int isFinal(int valor){
    int vetor[12] = {0,1,1,1,1,1,1,0,0,1,1,1};
    return vetor[valor];
}

int main(){
	int c_pointer,b_pointer,t_pointer,estado,token,indice,tamanho,first;
    int aux_p1,aux_p2;
	char leitura[300000],aux_leitura;
	int tabela_lexica[12][11];

	/* Leitura de dados */
	indice = 0;
	while(scanf("%c",&leitura[indice])!=EOF){indice++;}
	/* Iniciar Tabela Léxica */
	createTable(tabela_lexica);
	/* Analisar entrada */
	tamanho = strlen(leitura);
	c_pointer=0;
	t_pointer=0;
	b_pointer=0;
    first=0;
	while(c_pointer<tamanho){
		/* Encontrar a maior substring */
		estado=0;
		token=10;
		while(1){
			estado = tabela_lexica[estado][getSymbol(leitura[b_pointer])];
			if(estado==-1){break;}
			else if(isFinal(estado)){
				token = estado;
				t_pointer = b_pointer;
			}
			b_pointer++;
			if(b_pointer>tamanho){break;}
		}
		/* Ignorar tokens de \n e White space */
		if(token!=11){
		if(first){printf("\n");}else{first=1;}
            printToken(token);
		}
		/* Correr com os ponteiros */
		while(c_pointer<=t_pointer){
			c_pointer++;
		}
		t_pointer = c_pointer;
		b_pointer = t_pointer;

	}
	return(0);
}
