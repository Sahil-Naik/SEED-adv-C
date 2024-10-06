#include<stdio.h>

void find_prime(int start, int end){
    int i, j, flag;
    for (i=start; i<=end; ++i) {
        flag=0;
        if (i==0 || i==1){
            continue;
        }
        for (j=2; j<=i/2; ++j) {
          if (i%j==0) {
            flag=1;
            break;
          }
        }

    if (flag == 0)
      printf("%d ", i);
  }
}

int main(){
    int lower_limit, upper_limit;

    printf("Enter lower limit: ");
    scanf("%d", &lower_limit);

    printf("Enter upper limit: ");
    scanf("%d", &upper_limit);

    find_prime(lower_limit, upper_limit);

    return 0;
}
