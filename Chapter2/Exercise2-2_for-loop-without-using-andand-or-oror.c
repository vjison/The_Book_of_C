#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 25

int main(void){

    char s[MAXLEN], c;
    int i;

//    original from textbook
//    for (i = 0; i<MAXLEN-1 && (c=getchar()) != '\n' && c != EOF; ++i)
//        s[i] = c;



//     replicate above for loop without using && or ||
    for(i = 0; i < MAXLEN-1; ++i){

        if((c = getchar()) != '\n'){
            if(c != EOF){
                s[i] = c;
            }
        }
        else if(c = '\n'){
            break;
        }
        else if(c = EOF){
            break;
        }

    }





return 0;
}
