#include <stdio.h>
#include <stdlib.h>

#define TABLEN 8
#define MAXLEN 30


void entab();
int main(){


    printf("Enter a sentence with multiple spaces: \n");

    entab();
    printf("!"); // ! is used to indicate the end

return 0;
}

void entab(){

    char c;
    int count = 0, pos  = 0;

    while((c = getchar()) != EOF && c != '\n'){
        if(c == ' ' && (pos < TABLEN)){
            count++;   //keeps track of how many ' ' are seen before a char appears
            pos++;
            if(pos == TABLEN && count > 0){
                putchar('\t');
                pos = 0;
                count = 0;
            }
        }
        else{
            for(; count > 0 ; count--){
                putchar(' ');
            }
            count = 0;
            putchar(c); //prints char to screen
            pos++;
        }


    }


}
