#include<stdio.h>

void print_every_n(int lower_limit, int upper_limit, int N){
    int count = 0;
    printf("\nNumbers after every %d index are:", N);
    for (int i=lower_limit; i<=upper_limit; i++){
        count++;
        if(count==N){
            printf("\n%d ",i);
            count = 0;
        } else {
            continue;
        }
    }
    printf("\n");
}

int main(){
    int lower, upper, N;

    printf("Enter lower limit: ");
    scanf("%d", &lower);

    printf("Enter upper limit: ");
    scanf("%d", &upper);

    printf("Enter steps: ");
    scanf("%d", &N);

    print_every_n(lower, upper, N);

    return 0;
}
