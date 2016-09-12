#include <stdio.h>
#include <stdlib.h>


void squeeze(char s1[], char s2[]);

int main(void){

    char s1[] = "ccaHcw Hyiecccsisosllo";
    char s2[] = "cHillo";

    squeeze(s1, s2);

    printf("s1 = %s", s1);


return 0;
}

//deletes each character in s1 that matches any character in string s2
void squeeze(char s1[], char s2[]){

    char c;
    int i, j, ihold;

    for(i = 0; s1[i] != '\0';i++){ //for-loop1

        for(j = 0; s2[j] != '\0'; j++){ //for-loop2
            if(s1[i] != s2[j]){

                //if not equal, do not move i index in s1[i].
                //check next j index in s2[j] by j++. this is done in second for loop



            }
            else if(s1[i] == s2[j]){

                //if equal, hold i index until next i index replaces it
                ihold = i;

                //shift all indexes in s1[i] by 1:

                do{
                    s1[i] = s1[++i];
                }while(s1[i] != '\0');
                //debug: printf("s1! = %s   ", s1);
                i = ihold-1; //once you jump out of for-loop2, i++ occurs. the ihold-1 ensures index s1[ihold] is checked, not s1[ihold + 1]
                //debug: printf("i! = %d  ", i);

            }
        }
    }

}
