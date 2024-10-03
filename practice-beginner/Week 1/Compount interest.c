// Q. Program to find Compound Interest
#include <stdio.h>

double power_num(double t_amount, int power){
    while(power!=1){
        t_amount *= t_amount;
        power--;
    }
    return t_amount;
}

int main() {
    double pa, rate;
    int t_time;
    
    printf("Enter principal amount (PA): ");
    scanf("%lf", &pa);
    
    printf("Enter rate (%): ");
    scanf("%lf", &rate);
    
    printf("Enter Time (years): ");
    scanf("%d", &t_time);
    
    double amount = (1 + rate/100);
    double power = power_num(amount, t_time);
    
    printf("\nPrincipal = %lf", pa);
    printf("\nRate = %lf", rate);
    printf("\nTime = %d\n", t_time);
    
    double compound = pa * power - pa;
    
    printf("\nCompound Interest is: %lf", compound);

    return 0;
}