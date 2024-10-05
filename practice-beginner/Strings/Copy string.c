#include<stdio.h>

void copyString(char *string1, char *string2){
    for (int i=0; string1[i]!='\0'; i++){
        string2[i] = string1[i];
    }
}

int main(){
    char string1[50], string2[20];

    printf("Enter string 1: ");
    scanf("%s", string1);

    printf("\nString 1 is: '%s'",string1);
    printf("\nString 2 is: ' '");

    copyString(string1, string2);
    printf("\n\nCopying...\n");
    printf("\nString 1 is: '%s'",string1);
    printf("\nString 2 is: '%s'\n",string2);

    return 0;
}
