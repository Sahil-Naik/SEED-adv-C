// Q. Write a Program to find the Sum of two numbers entered by the user
#include <stdio.h>

int main() {
    int num1, num2;
    printf("Enter number 1: ");
    scanf("%d", &num1);
    printf("Enter number 2: ");
    scanf("%d", &num2);
    
    int sum = num1 + num2;
    printf("%d+%d=%d",num1,num2,num1+num2);

    return 0;
}