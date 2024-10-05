#include<stdio.h>

int stringASCII(char *string){
    int ASCII = 0;
    for (int i=0; string[i]!='\0'; i++){
        ASCII += (int)string[i];
    }
    return ASCII;
}

int compareStrings(char *string1, char *string2){
    int length1, length2;

    for (length1=0; string1[length1]!='\0'; length1++);
    for (length2=0; string2[length2]!='\0'; length2++);

    if (length1>length2){
        return 1;
    } else if (length1<length2) {
        return -1;
    } else {
        return 0;
    }
}

int main(){
    char string1[50], string2[20];

    printf("Enter string 1: ");
    scanf("%s", string1);

    printf("Enter string 2: ");
    scanf("%s", string2);

    printf("\nString 1 is: '%s'",string1);
    printf("\nString 2 is: '%s'",string2);

    int flag = compareStrings(string1, string2);
    if (flag==0){
        printf("\n\nBoth strings are equal in length!");
        int ASCII_string_1 = stringASCII(string1);
        int ASCII_string_2 = stringASCII(string2);
        if (ASCII_string_1==ASCII_string_2){
            printf("\n\nASCII value of '%s': %d\nASCII value of '%s': %d\n",string1,ASCII_string_1,string2,ASCII_string_2);
            printf("\nSince both the strings share same total ASCII value we can say that: ");
            printf("'%s' and '%s' are equal!\n",string1,string2);
        } else {
            printf("\n\nASCII value of %s: %d\nASCII value of %s: %d\n",string1,ASCII_string_1,string2,ASCII_string_2);
            printf("\nSince both the strings don't have same total ASCII value we can say that: ");
            printf("'%s' and '%s' are not equal!\n",string1,string2);
        }
    } else if (flag==1){
        printf("\n\n%s length is greater than %s\n",string1,string2);
    } else {
        printf("\n\n%s length is greater than %s\n",string2,string1);
    }

    return 0;
}
