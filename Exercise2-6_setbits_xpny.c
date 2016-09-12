#include <stdio.h>
#include <stdlib.h>


unsigned setbits(unsigned x, int p, int n, unsigned y);
int main(void){


    //n <= p

    printf("Hex value is %x\n",setbits(0x9BA, 5, 3, 0xA9D));


return 0;
}

//return x with the n bits that begin at position p set to the rightmost n bits of y
unsigned setbits(unsigned x, int p, int n, unsigned y){

    //thought process notes for y:
    //111111
    //111000 <<n=3
    //000111
    //& with (y = xxx101)
    //000101
    //00101..<<p+1-n

    //thought process notes for x:
    //111111
    //111000 <<n=3
    //000111
    //011100 <<p+1-n
    //100011

    printf("x = %x, p = %d, n = %d, y = %x\n\n", x, p, n, y);
/* //DEBUG OUTPUT:
    printf("! %x\n",((~(~(~0 << n)<<(p+1-n))) & x));



    printf("!! %x\n", ((y & (~(~0 << n)))<<(p+1-n)) );
*/
    return( ((y & (~(~0 << n)))<<(p+1-n)) | ((~(~(~0 << n)<<(p+1-n))) & x) );

}
