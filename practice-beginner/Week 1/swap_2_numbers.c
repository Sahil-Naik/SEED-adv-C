// Q. Program to swap 2 numbers
#include <stdio.h>

int main() {
    int number1, number2;
    
    printf("Enter number 1: ");
    scanf("%d", &number1);
    
    printf("Enter number 2: ");
    scanf("%d", &number2);
    
    printf("\nBefore Swapping:\n1. %d\t2. %d",number1,number2);
    
    number1 = number1+number2;
    number2 = number1-number2;
    number1 = number1-number2;
    
    /*
    Eg. Number1 = 10
        Number2 = 15
        
        10 + 15 = 25 -> New Number1
        25 - 15 = 10 -> New Number2
        25 - 10 = 15 -> New Number1
    */
    
    printf("\nAfter Swapping:\n1. %d\t2. %d",number1,number2);

    return 0;
}