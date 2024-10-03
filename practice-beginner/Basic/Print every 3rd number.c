#include<stdio.h>

void print_every_3(int lower_limit, int upper_limit){
    int count = 0;
    for (int i=lower_limit; i<=upper_limit; i++){
        count++;
        if(count==3){
            printf("\n%d ",i);
            count = 0;
        } else {
            continue;
        }
    }
}

int main(){
    int lower, upper;

    printf("Enter lower limit: ");
    scanf("%d", &lower);

    printf("Enter upper limit: ");
    scanf("%d", &upper);

    print_every_3(lower, upper);

    return 0;
}
