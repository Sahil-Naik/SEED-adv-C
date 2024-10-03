#include<stdio.h>

void are_same(int number){
    int rev_number=0;
    int temp = number;
    while(temp != 0){
        rev_number = rev_number * 10 + temp%10;
        temp /= 10;
    }
    if (number == rev_number){
        printf("\nThe reverse of given number is same!\n");
    } else {
        printf("\nThe reverse of given number is not same!\n");
    }
}

int main(){
    int number;

    printf("Enter: ");
    scanf("%d", &number);

    are_same(number);

    return 0;
}
