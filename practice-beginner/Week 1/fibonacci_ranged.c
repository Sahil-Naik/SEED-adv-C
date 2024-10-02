// Q. Program to find fibonacci of given range
#include <stdio.h>

void fibonacci(int range){
    int previous1=1, previous2=0;
    int current;
    
    if (range<0){
        printf("Enter positive range only!");
        return;
    }
    
    for (int i=1; i<=range; i++)
    if(i==1){
        printf("%d ",previous2);
    } else if(i==2){
        printf("%d ", previous1);
    } else if (range>2){
        current = previous1 + previous2;
        previous2 = previous1;
        previous1 = current;
        printf("%d ", current);
    }
}

int main() {
    int user_range;
    printf("Enter range: ");
    scanf("%d", &user_range);
    printf("\nSeries is: ");
    fibonacci(user_range);

    return 0;
}