#include <stdio.h>
#include <stdlib.h>

void lower(char in[]);
int main(void){

    char sentin[] = "HeLlo ThERe! what Is a ZoO?";

    lower(sentin);


return 0;
}


void lower(char in[]){

    char c;
    int i;

    for(i = 0; in[i] != '\0' && in[i] != '\n'; i++){

        in[i] = ((in[i] > 96) && (in[i] < 123)) ? in[i]-32 : in[i];

    }

    printf("in[] = %s \n", in);


}
