// Q. Find largest number among 3 numbers

#include <stdio.h>

void largest(int number1, int number2, int number3){
    if(number1>number2 && number1>number3){
        printf("%d is the Largest!", number1);
    } else if (number2>number1 && number2>number3){
        printf("%d is the Largest!", number2);
    } else {
        printf("%d is the Largest!", number3);
    }
}

int main() {
    int num1, num2, num3;
    printf("Enter number 1: ");
    scanf("%d", &num1);
    
    printf("Enter number 2: ");
    scanf("%d", &num2);
    
    printf("Enter number 3: ");
    scanf("%d", &num3);
    
    largest(num1, num2, num3);

    return 0;
}