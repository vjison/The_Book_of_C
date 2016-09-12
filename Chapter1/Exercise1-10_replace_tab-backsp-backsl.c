#include <stdio.h>



void main(){


    long input, count;

    printf("Say something.\n");
    scanf("%ld", input);

    int i = 0;
    int backsp = 0, backsl =0;


    do {
        count = getchar();

        if(count == '\t')
            printf("\\t");

        else if(count == '\b'){
            backsp++;
            printf("\\b");
        }
        else if(count == '\\'){
            backsl++;
            printf("\\");
        }
        else
            putchar(count);


    }while((count) != '\n');

        printf("backsp: %d\n",backsp);
        printf("backsl: %d\n", backsl);

return 0;
}
