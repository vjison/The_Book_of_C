#include <stdio.h>
#include <stdlib.h>

void reverse(char sr[]);
void itob(int input, char s[], int base);
int main(void){

    int in = 5;
    char s_in[100];
    int base = 2;

    itob(in, s_in, base);


return 0;
}

//convert the integer n into a base b character representation in string s
//ex. (n, s, 16) formats n as a hexadecimal integer in s
void itob(int input, char s[], int base){


    int remainder, n;
    int nextNum = input;

    for(n = 0; nextNum >= base; n++){

        remainder = nextNum % base;

        if(remainder >= 10 && remainder <= 15){
            s[n] = (remainder += 55); //for HEX A-F
        }
        else{
            s[n] = 48 + remainder; //for 0-9
        }
        nextNum = nextNum / base;
    }


    if(nextNum >= 10 && nextNum <= 15){
        s[n] = (nextNum += 55); //for HEX A-F
    }
    else{
        s[n] = nextNum + 48; //for 0-9
    }

    s[n+1] = '\0';
    reverse(s);

    printf("s[n] is %s", s);


}

void reverse(char sr[]){

    int c, i, j;

//    printf("strlen(s) = %d\n", strlen(s));

    for(i = 0, j = strlen(sr)-1; i<j; i++, j--){
        c = sr[i];
        sr[i] = sr[j];
        sr[j] = c;
    }
}
