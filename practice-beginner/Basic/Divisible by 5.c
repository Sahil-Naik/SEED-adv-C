#include <stdio.h>

int main(){
    int number;

    printf("Enter number: ");
    scanf("%d", &number);

    if (number % 5 == 0){
        printf("\n%d is divisible by 5\n", number);
    } else {
        printf("\n%d is not divisible by 5\n", number);
    }

    return 0;
}
