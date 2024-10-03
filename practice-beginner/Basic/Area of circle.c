#include <stdio.h>

float area_circle(float radius){
    const float PI = 3.14;
    return (PI * radius * radius);
}

int main(){
    float user_radius;

    printf("Enter radius: ");
    scanf("%f", &user_radius);

    float area = area_circle(user_radius);
    printf("\nArea of circle is: %.2f\n",area);

    return 0;
}
