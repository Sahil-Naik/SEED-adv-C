#include<stdio.h>

int main(){
    int number1, number2;

    printf("Enter number 1: ");
    scanf("%d", &number1);

    printf("Enter number 2: ");
    scanf("%d", &number2);

    if (number1 > number2){
        printf("\n%d is greater than %d\n", number1, number2);
    } else if (number2 > number1){
        printf("\n%d is greater than %d\n", number2, number1);
    } else {
        printf("\nBoth numbers are equal!\n");
    }

    return 0;
}
