#include <stdio.h>
#include <stdlib.h>


void escape(char s[], char t[]);
int main(void){

    char si[50];
    char ti[] = "blank\n  space \t!";

    escape(si, ti);

    printf("si[] = %s\n", si);



return 0;
}

//convert new line and tab characters into visible escape sequencers \n and \t. copies string t into s
void escape(char s[], char t[]){

    int i, j;


    for(i = j = 0; t[i] != '\0'; i++){

        switch(t[i]){

            case '\n' :
                s[j++] = '\\';
                s[j++] = 'n';
                break;
            case '\t' :
                s[j++] = '\\';
                s[j++] = 't';
                break;
            default:
                s[j++] = t[i];
                break;
        }
    }

    if(t[i] == '\0'){

        s[j] = '\0';

    }


}
