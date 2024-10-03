#include <stdio.h>

int main(){
    int year;

    printf("Enter year: ");
    scanf("%d", &year);

    if (year%4==0){
        printf("\n%d is a Leap year!\n",year);
    } else {
        printf("\n%d is not a Leap year!\n",year);
    }

    return 0;
}
