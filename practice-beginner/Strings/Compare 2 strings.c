#include<stdio.h>

int stringASCII(char *string){
    int ASCII = 0;
    for (int i=0; string[i]!='\0'; i++){
        ASCII += (int)string[i];
    }
    return ASCII;
}

void compareStrings(char *string1, char *string2){
    int length1, length2;

    for (length1=0; string1[length1]!='\0'; length1++);
    for (length2=0; string2[length2]!='\0'; length2++);

    if (length1==length2){
        int ASCII_string_1 = stringASCII(string1);
        int ASCII_string_2 = stringASCII(string2);
        if (ASCII_string_1==ASCII_string_2){
            printf("\n\nASCII value of %s: %d\nASCII value of %s: %d\n",string1,ASCII_string_1,string2,ASCII_string_2);
            printf("\nSince both the strings share same total ASCII value we can say that: ");
            printf("%s and %s are equal!\n",string1,string2);
        } else {
            printf("\n\nASCII value of %s: %d\nASCII value of %s: %d\n",string1,ASCII_string_1,string2,ASCII_string_2);
            printf("\nSince both the strings don't have same total ASCII value we can say that: ");
            printf("%s and %s are not equal!\n",string1,string2);
        }
    } else {
        printf("\n%s is not equal to %s\n",string1,string2);
    }
}

int main(){
    char string1[50], string2[20];

    printf("Enter string 1: ");
    scanf("%s", string1);

    printf("Enter string 2: ");
    scanf("%s", string2);

    printf("\nString 1 is: %s",string1);
    printf("\nString 2 is: %s",string2);

    compareStrings(string1, string2);

    return 0;
}
