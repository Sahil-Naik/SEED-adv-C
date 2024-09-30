// Q. Factorial of a number
#include <stdio.h>

int factorial(int number){
    int fact = 1;
    for(int i=1; i<=number; i++){
        fact *= i;
    }
    return fact;
}

int main() {
    int user_number;
    printf("Enter number: ");
    scanf("%d", &user_number);
    
    int result = factorial(user_number);
    printf("%d! is %d", user_number, result);

    return 0;
}