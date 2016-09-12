#include <stdio.h>
#include <stdlib.h>

int bitcount(unsigned x);
int main(void){

    unsigned num = 0xF9;

    printf("Number of 1's in %x is %d \n", num, bitcount(num));

return 0;
}


int bitcount(unsigned x){

    int count = 0;

    while(x!=0){
        x &= (x-1);
        count++;
    }
    return count;
}
