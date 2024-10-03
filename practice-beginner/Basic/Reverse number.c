#include <stdio.h>

int main(){
    int number;

    printf("Enter number: ");
    scanf("%d", &number);

    while(number!=0){
        printf("%d",number%10);
        number /=10;
    }
    printf("\n");

    return 0;
}
