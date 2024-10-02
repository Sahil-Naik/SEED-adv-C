// Q. Simple 2 numbers calculator
#include <stdio.h>

int addition(int num1, int num2){
    int result = num1 + num2;
    return result;
}

int subtraction(int num1, int num2){
    int result = num1 - num2;
    return result;
}

int multiplication(int num1, int num2){
    int result = num1 * num2;
    return result;
}

int division(int num1, int num2, int *quotient, int *remain){
    *quotient = num1 / num2;
    *remain = num1 % num2;
}

int main() {
    int number1, number2, f_result;
    char operation;
    
    printf("Enter operation: ");
    scanf("%d%c%d",&number1, &operation, &number2);
    
    switch(operation){
        case '+':
            f_result = addition(number1, number2);
            printf("%d+%d=%d",number1, number2, f_result);
            break;
        
        case '-':
            f_result = subtraction(number1, number2);
            printf("%d-%d=%d", number1, number2, f_result);
            break;
            
        case '*':
            f_result = multiplication(number1, number2);
            printf("%d*%d=%d", number1, number2, f_result);
            break;
            
        case '/':
            int Q, R;
            division(number1, number2, &Q, &R);
            printf("%d/%d is:\nQuotient=%d\nRemainder=%d",number1, number2, Q, R);
            break;
        
        default:
            printf("Operation invalid!");
    }

    return 0;
}