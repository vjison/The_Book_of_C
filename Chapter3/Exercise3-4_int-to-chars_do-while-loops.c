#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define abs(x) ((x) < 0 ? -(x):(x))

void itoa(int n, char s[]);
void reverse(char s[]);
int main(void){

    int var = 978;
    char str[100];

    itoa(var, str);

    printf("str = %s\n", str);


return 0;
}

//converts n to characters in s
void itoa(int n, char s[]){

    int i, sign;

//    if((sign = n) < 0) /*record sign*/
//        n = -n; //this statement will not work
                //the largest negative number in 2s compliment, regardless of machine,
                //is -(2^(wordsize-1)) but the largest positive number is
                //(2^(wordsize-1))-1
                //A better way is to use the macro abs(x) below to find the absolute
                //value of n % 10

                /*
                http://www.stevenscs.com/programs/KR/$progs/KR-EX3-04.html
                Taking the two’s complement of the largest negative integer results in an unchanged bit pattern.
                The original version of function itoa attempts to change the integer’s sign by multiplying by -1,
                and therefore it cannot handle the largest negative integer.  The modified function itoa does
                not attempt to change the integer’s sign.  Instead, the loop that computes each digit character
                corrects for sign to yield a positive result.
                */


    sign = n; //records sign

    i = 0;
    do{                         //generates digits in reverse order
        s[i++] = abs(n % 10) + '0'; //get next digit

    } while ((n /= 10) > 0);    //delete it

    if (sign < 0){
        s[i++] = '-';
    }
    s[i] = '\0';

    printf("s before reverse = %s\n", s);

    reverse(s);


}

void reverse(char s[]){

    int c, i, j;

    printf("strlen(s) = %d\n", strlen(s));

    for(i = 0, j = strlen(s)-1; i<j; i++, j--){
        c = s[i];
        s[i] = s[j];
        s[j] = c;


    }



}
