#include <stdio.h>
#include <stdlib.h>

#define N 4

void fold();
int main(){

    printf("Enter a sentence with long lines: \n");

    fold();


return 0;
}

void fold(){

    char c;
    int track = 0; //keeps track of chars in a line before a space or tab is encountered


    while((c = getchar()) != EOF && c != '\n'){

        if(c != ' '){ //if c is a char
            putchar(c);
            track++;
        }
        else if(c == ' '){
            putchar(c);
        }
        if(track == N){
            putchar(' ');
            track = 0;
        }

    }
}
