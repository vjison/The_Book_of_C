#include <stdio.h>
#include <stdlib.h>

void expand(char s1[], char s2[]);
int main(void){

    char si1[] = "2-5-8a-d-h-j1-5";
    char si2[100];

    expand(si1, si2);


return 0;
}

//expands short hand notation in s1 (ex. a-z, 0-9) into its complete list (ex. abcde...xyz, 0123...789) into s2
void expand(char s1[], char s2[]){

    int i, j, z;
    char start, start_found, end, end_found, dash;

    start_found = end_found = 0;
    dash = 0;

    //dash = 1 when a dash is found


    for(i = j = 0; s1[i] != '\0'; i++){


        if(((s1[i] <= 'z' && s1[i] >= 'a' )||(s1[i] <= '9' && s1[i] >= '0' )) && dash == 0){        //if a letter or number is encountered, save it
            start = s1[i];
            start_found = 1;
       //     printf("start! %d\n", start);
        }

        if(((s1[i] <= 'z' && s1[i] >= 'a' )||(s1[i] <= '9' && s1[i] >= '0' )) && dash == 1){       //if a letter or number is encountered, save it

            if(s1[i+1] == '-'){ //look ahead. covers 'a-c-h' cases
              //  printf("post dash found\n");
                end_found = 0;
            }
            else{

                end = s1[i];
                end_found = 1;
                //printf("end! %d\n", end);
            }
        }

        if(s1[i] == '-' && start_found == 1){ //- is 45 in ASCII

            dash = 1;
           // printf("dash!\n");

        }

       if(end_found == 1){

            while(start <= end){

                s2[j] = start;
                start++;
                j++;
            }

                dash = 0;
                start_found = 0;
                end_found = 0;

       }

    }

    s2[j] = '\0';
    printf("s2 = %s\n", s2);
}
