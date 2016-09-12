#include <stdio.h>
#include <stdlib.h>


char text[] = "ould";

int strrindex(char s[], char t[]);
/*another protoype format: " int strrindex(char [], char[]); " also works */
int main(void){

    char s_in[] = "What would you do if you could fly";
    int index = strrindex(s_in, text);

    if(index > 0)
    printf("Right most occurence of ""%s"" occurs at index %d\n", text, strrindex(s_in, text));
    else
    printf("No instance of ""%s"" found\n", text);



return 0;
}


//return the index of the right most occurence of t in s
int strrindex(char s[], char t[]){

    int i, j, k;
    int found = -1;

    for(i = 0; s[i] != '\0'; i++){
        for(j=i, k=0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if(k > 0 && t[k] == '\0')
            found = i;

    }
    return found;

}
