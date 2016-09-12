#include <stdio.h>
#define MAXLINE 1000 /*max input line size*/




void copy(char copy_to[], char copy_from[]);
int lineLen(char line_in[], int maxLen);


void main(){

    char line_1[] = "Hello and greetings \n sir";
    char line_2[] = "Goodbye";

    int lineLength;

    lineLength = lineLen(line_1, 40);

    printf("\nlineLength = %d", lineLength);

return 0;
}

int lineLen(char line_in[], int maxLen){ //calculates length of a line

    int outLen, i;
    i = 0;

    for (i=0; i < maxLen - 1 && (outLen = getchar())!= EOF && outLen != '\n'; i++){
        printf("Uh oh\n");
    }

printf("done!");
return i;

}

//copies array 'from' into 'to'
void copy(char copy_to[], char copy_from[]){

    int i = 0;

    while((copy_to[i] = copy_from[i]) != '\0'){
        i++;
    }


}
