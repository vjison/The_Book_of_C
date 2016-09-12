#include <stdio.h>



void main(){

    long count;

    printf("Say something.\n");
    scanf("%ld", count);

    int i = 0;
    int tab = 0, newln = 0, blank =0;


    do {
        count = getchar();

        if(count == '\n'){
            newln++;
        }
        if(count == '\t'){
            tab++;
        }
        if(count == ' '){
            blank++;
        }

    }while((count) != '\n');

        printf("tab: %d\n", tab);
        printf("newln: %d\n", newln);
        printf("blank: %d\n", blank);

return 0;
}
