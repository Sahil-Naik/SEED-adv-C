// Q. Binary to Decimal
#include <stdio.h>

int binary_to_decimal(int binary){
    int result = 0;
    int base = 1;
    
    int temp = binary;
    
    while(temp){
        int last_digit = temp % 10;
        temp /= 10;
        
        result += last_digit * base;
        
        base *= 2;
    }
    return result;
}

int main() {
    int user_binary;
    printf("Enter binary: ");
    scanf("%d", &user_binary);
    
    int answer = binary_to_decimal(user_binary);
    printf("Binary %d to Decimal is %d",user_binary, answer);

    return 0;
}