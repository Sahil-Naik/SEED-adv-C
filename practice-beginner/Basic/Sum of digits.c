#include <stdio.h>

int sum_digits(int number){
    int sum=0;

    while(number!=0){
        sum+=number%10;
        number /=10;
    }
    return sum;
}

int main(){
    int number, sum;

    printf("Enter number: ");
    scanf("%d", &number);

    sum = sum_digits(number);
    printf("\nSum of digits from %d is %d.\n",number,sum);

    return 0;
}
