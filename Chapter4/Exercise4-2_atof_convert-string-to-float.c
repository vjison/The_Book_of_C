#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

double atofloat(char s[]);
int main(void){

    char in[] = "123.45E-0";
//    double atofloat(char []); //declaration that explicitly states atofloat will return a double
                              //^this is an alternative to a function prototype declaration above main() but
                              //it must be declared everytime it is used

    printf("Float is %f\n", atofloat(in));


return 0;
}

//converts a string to float
double atofloat(char s[]){

    double val, power;
    int i, sign, expfound, expNeg;

    expfound = 0;



    for(i =0 ; isspace(s[i]);i++)    //ignore white space in s[] until a -/+ is encountered
        ;

    sign = (s[i] == '-') ? -1 : 1;

    if(s[i] == '-' || s[i] == '+')
        i++;

    for(val = 0.0 ; isdigit(s[i]); i++)
        val = (val * 10.0) + (s[i] - 48); //s[i] returns the decimal value of ASCII value of the number, and subtracts 48 to return actual number.
                                          //Ex: char 2 = 50 decimal value. subtract 48 to give you 2 decimal value, which can be used in calculations
                                          //you also could have just typed s[i] - '0', it's the same thing

    if(s[i] == '.')
        i++;

    for(power = 1.0; isdigit(s[i]); i++){
        val = (val * 10.0) + (s[i] - 48);
        power *= 10.0;
    }


//the following code takes care of scientific notation for exponents less than 10
    if(s[i] == 'E' || s[i] == 'e'){
        i++;
    }

    if(expNeg = (s[i] == '-') ? 1 : 0){
        i++;

            expfound = s[i] - '0';
            while(expfound > 0){
                power *= 10.0;
                expfound--;
            }
    }
    else{
        expfound = s[i] - '0';
        while(expfound > 0){
            power /= 10.0;
            expfound--;

        }

    }

return sign * val / power;

}

