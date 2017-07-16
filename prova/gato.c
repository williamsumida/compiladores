#include <stdio.h>
#include <string.h>

/* Imprimir Tokens */
void printToken(int valor){
	/* Tokens */
	if(valor==1){printf("ID");}
	else if(valor==2){printf("IF");}
	else if(valor==3){printf("ID");}
	else if(valor==4){printf("NUM");}
	else if(valor==5){printf("REAL");}
	else if(valor==6){printf("WHITE SPACE");}
	else if(valor==9){printf("REAL");}
	else if(valor==11){printf("pula");}
	else if(valor==10){printf("ERRO");}
}


int getSymbol(char valor){
	if(valor=='+'){return(10);}
	else if(valor=='-'){return(11);}
	else if(valor=='i'){return(2);}
	else if(valor=='f'){return(3);}
	else if(valor=='.'){return(6);}
	else if(valor=='e'){return(9);}
	else if(valor>='0' && valor<='9'){return(4);}
	else if(valor>='a' && valor<='z'){return(1);}
	else if(valor==' '){return(5);}
	else if(valor=='\n'){return(8);}
	/* ERRO */
	else{return(7);}

/* Tabela léxica de relações */
void createTable(char tabela[25][15]){
	int linha,coluna;
	for(linha=0;linha<25;linha++){
		for(coluna=0;coluna<15;coluna++){
			tabela[linha][coluna] = -1;
		}
	}

	tabela[1][0]=0;
	tabela[2][0]=0;
	tabela[5][0]=0;
	tabela[6][0]=0;
	tabela[7][0]=0;
	tabela[8][0]=0;
	tabela[9][0]=0;
	tabela[10][0]=0;
	tabela[11][0]=0;

    tabela[0][1]=3;
    tabela[0][2]=1;
    tabela[0][3]=3;
    tabela[0][4]=4;
    tabela[0][6]=6;
    tabela[0][9]=10;
    tabela[0][10]=11;
    tabela[0][11]=3;

    tabela[1][1]=3;
    tabela[1][2]=3;
    tabela[1][3]=2;
    tabela[1][4]=3;
    tabela[1][9]=3;

    tabela[2][1]=3;
    tabela[2][2]=3;
    tabela[2][3]=3;
    tabela[2][4]=3;
    tabela[2][9]=3;

    tabela[3][1]=3;
    tabela[3][2]=3;
    tabela[3][3]=3;
    tabela[3][4]=3;
    tabela[3][9]=3;

    tabela[4][4]=4;
    tabela[4][6]=5;
    tabela[4][9]=7;

    tabela[5][4]=5;

    tabela[7][4]=9;
    tabela[7][10]=8;
    tabela[7][11]=8;

    tabela[8][4]=9;

    tabela[9][4]=9;
}

int main(){
	int c_pointer,b_pointer,t_pointer,estado,token,indice,tamanho,first;
  int aux_p1,aux_p2;
	char leitura[300000],aux_leitura;
	char tabela_lexica[25][15];

	/* Leitura de dados */
	indice = 0;
	while(scanf("%c",&leitura[indice])!=EOF){indice++;}
    printf("%s\n", leitura);

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
			else if(tabela_lexica[estado][0]==0){
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
