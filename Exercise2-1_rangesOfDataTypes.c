#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>


int main(void){

    printf("The max range of INT is %d\n", INT_MAX);
    printf("The min range of INT is %d\n", INT_MIN);
    printf("The max range of char is %d\n", CHAR_MAX);
    printf("The min range of char is %d\n", CHAR_MAX);

    printf("The max range of SHORT is %d\n", SHRT_MAX);
    printf("The min range of SHORT is %d\n", SHRT_MIN);
    printf("The max range of LONG is %ld\n", LONG_MAX);
    printf("The min range of LONG is %ld\n", LONG_MIN);

//UNSIGNED:

    printf("The max range of UNSIGNED INT is %u", UINT_MAX);
    printf("The max range of UNSIGNED char is %u\n", UCHAR_MAX);

    printf("The max range of UNSIGNED SHORT is %u\n", USHRT_MAX);
    printf("The max range of UNSIGNED LONG is %lu\n", ULONG_MAX);



return 0;
}
