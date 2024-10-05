#include<stdio.h>

void mergeStrings(char *string1, char *string2){
    int length1;

    for (length1=0; string1[length1]!='\0'; length1++);

    for (int j=0; string2[j]!='\0'; j++, length1++){
        string1[length1] = string2[j];
    }
    string1[length1]='\0';
}

int main(){
    char string1[50], string2[20];

    printf("Enter string 1: ");
    scanf("%s", string1);

    printf("Enter string 2: ");
    scanf("%s", string2);

    printf("\nString 1 is: %s",string1);
    printf("\nString 2 is: %s",string2);

    mergeStrings(string1, string2);

    printf("\n\nMerged string is: %s\n",string1);

    return 0;
}
