// Q. Program to check given number is Even or Odd

#include <stdio.h>

void even_odd(int number){
    if (number%2==0){
        printf("%d is Even!",number);
    } else {
        printf("%d is Odd!",number);
    }
}

int main() {
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    even_odd(number);

    return 0;
}