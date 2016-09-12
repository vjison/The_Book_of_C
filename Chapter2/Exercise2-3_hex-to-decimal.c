#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 20


int atoi2(char s[]);
int main(){

    char in[] = "1h357";
    int someVar;

    someVar = htoi2(in);

 //   printf("someVar = %d", someVar);



return 0;
}

//convert string of chars to int
int atoi2(char s[]){

    int n = 0;
    int i;

    for(i = 0; s[i] >= '0' && s[i] <= '9'; ++i){ // can also be written as for(i = 0; s[i] >= 48 && s[i] <= 57; ++i)
        n = 10 * n + (s[i] - '0');
        printf("n loop = %d\n", n);
    }
        printf("n = %d\n", n);
        return n;

}


//convert string of hex to int
int htoi2(char s2[]){

    int n = 0;
    int i;


    for(i = 0; (s2[i] >= '0' && s2[i] <= '9') || (s2[i] >= 'A' && s2[i] <= 'H') || (s2[i] >= 'a' && s2[i] <= 'h'); ++i){

        if(s2[i] >= '0' && s2[i] <= '9'){

             n = (s2[i] - '0');
            printf("%d", n);

        }
        else if(s2[i] >= 'A' && s2[i] <= 'H'){ //65, 72

            n = (s2[i] - 55);
            printf("%d", n);

        }
        else if(s2[i] >= 'a' && s2[i] <= 'h'){ //97, 104

            n = (s2[i] - 87);
            printf("%d", n);

        }


    }


       // printf("n = %d\n", n);
      //  return n;




}

