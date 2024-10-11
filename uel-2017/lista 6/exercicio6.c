#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * leituraString(){
    int i = 0;
    // String "infinita"
    char *s = malloc(1);

    // pega a entrada ate o fim de arquivo
    while(scanf("%c", &s[i++]) != -1){
        // Realoca mais um
        s = realloc(s, i+1);
    }
    s[i-2] = '\0';
    return s;
}

void printSubString(char * s, int first_substring_char, int current_substring_char){
    while(first_substring_char != current_substring_char+1){
        if(s[first_substring_char] != '\n')
            printf("%c", s[first_substring_char]);
        first_substring_char++;
    }
    if(s[first_substring_char] != '\n')
        printf("\n");
}

int nextState(int current_state, char s){

    //printf("current_state dentro da func: %d\n", current_state);
    int M[10][7]={
    //  0   1   2   3   4   5   6
    //  +   -   e  0-9 a-z '\n' erro
        2,  3,  1,  4,  1,  8,  9,
        0,  0,  1,  1,  1,  0,  0,
        0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,
        0,  0,  5,  4,  0,  0,  0,
        6,  6,  0,  7,  0,  0,  0,
        0,  0,  0,  7,  0,  0,  0,
        0,  0,  0,  7,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0
    };

    if(s == '+')
        return M[current_state][0];
    else if(s == '-')
        return M[current_state][1];
    else if(s == 'e')
        return M[current_state][2];
    else if(s >= '0' && s <= '9')
        return M[current_state][3];
    else if(s >= 'a' && s <= 'z')
        return M[current_state][4];
    else if(s == '\n')
        return M[current_state][5];
    else
        return M[current_state][6];
}
