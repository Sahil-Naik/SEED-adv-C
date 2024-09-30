// Q. Sum of natural number
#include <stdio.h>

int sum_natural(int number){
    if (number!=0){
        return number + sum_natural(number-1);
    } else {
        return number;
    }
}

int main() {
    int user_num;
    printf("Enter number: ");
    scanf("%d", &user_num);
    
    printf("The sum of natural number from 1 to %d is %d.", user_num, sum_natural(user_num));

    return 0;
}