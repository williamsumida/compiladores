#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char * leituraString(){
    char *s = malloc(1);
    int i = 0;

    while(scanf("%c", &s[i++]) != -1){
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




main(){

}
