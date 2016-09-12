#include <stdio.h>
#include <stdio.h>


int any1(char s1[], char s2[]);
int main(void){

    char in1[] = "zzzez";
    char in2[] = "abcde";
    int result;

    result = any1(in1, in2);

    if(result == -1){
        printf("No match found between s1 and s2 characters.\n");
    }
    else{
        printf("Match occurs in s1[] at index %d\n", result);
    }


return 0;
}


//return the first location in string s1 where any character from s2 occurs, or -1 if no matches
int any1(char s1[], char s2[]){

    int i, j, index_match, index_s1_save;
    index_match = 0;


    for(i = 0; s1[i] != '\0' && (index_match != 1); i++){

        for(j = 0; s2[j] != '\0' && (index_match != 1); j++){

//              if(s1[i] != s2[j]){ //this is redundant and can be removed

                //continue to iterate through s2
//            }
                if(s1[i] == s2[j]){

                //exit both for loops, save index in s1[i] where match was found, set index-match = 1
                index_match = 1;
                index_s1_save = i;

            }
        }
    }

    if(index_match == 1){
        return index_s1_save;
    }
    else{
        return -1;
    }


}
