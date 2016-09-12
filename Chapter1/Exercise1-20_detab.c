#include <stdio.h>
#include <stdlib.h>

#define TABLEN 8
#define MAXLEN 30

void detab(char sentOut[]);
int main(){

    char sentenceOut[MAXLEN];

    printf("Enter a sentence with tabs: \n");

    detab(sentenceOut);

return 0;
}

void detab(char sentOut[]){

    char c;
    int count = 0;
    int pos = 0; //keeps track of the position of each char in a string being printed

    while((c = getchar()) != EOF && c != '\n'){
        if(c == '\t'){
            while(pos < TABLEN){
            sentOut[count] = ' ';
            pos++;
            count++;
            }
        }
        else{
            sentOut[count] = c;
            pos++;
            count++;
        }

        if(pos == 8){
            pos = 0;
        }
    }

printf("sentOut: \n%s", sentOut);
}
