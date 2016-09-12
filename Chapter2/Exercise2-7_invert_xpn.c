#include <stdio.h>
#include <stdlib.h>

unsigned invert(unsigned x, int p, int n);
int main(void){


    printf("Hex value is %x\n",invert(0x9BA, 5, 4));


return 0;
}

//returns x with the n bits starting at position p inverted
unsigned invert(unsigned x, int p, int n){

    unsigned extract_inv_n_from_x;
    unsigned clear_n_in_x;

    extract_inv_n_from_x = ( ~( ( ~( ~((~(~0 << n))<<(p+1-n)) ) ) & x ));

    printf("extract = %x\n", extract_inv_n_from_x);

    clear_n_in_x = (~((~(~0 << n)) << (p+1-n)) & x)   |   ((~(~0 << n)) << (p+1-n)) ; //sets n bits at location p in x to all 1's: (set n bits at p to 0) | (set n bits to 1, all else 0)

    printf("clear = %x\n", clear_n_in_x);

    return (extract_inv_n_from_x & clear_n_in_x);

}
