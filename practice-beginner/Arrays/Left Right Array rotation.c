// Q. Program to rotate an Array Left or Right
#include <stdio.h>
#include <stdlib.h>

int *rotate_L_array(int my_array[], int length, int steps){
    int first;
    for (int i=0; i<steps; i++){
        first  = my_array[0];
        for (int j=0; j<length; j++){
            my_array[j] = my_array[j+1];
        }
        my_array[length-1] = first;
    }
    
    return my_array;
}

int *rotate_R_array(int my_array[], int length, int steps){
    int last;
    length--;
    for (int i=0; i<steps; i++){
        last = my_array[length];
        for (int j=length; j>=0; j--){
            my_array[j] = my_array[j-1];
        }
        my_array[0] = last;
    }
    
    return my_array;
}

void print_array(int my_array[], int length){
    for (int i=0; i<length; i++){
        printf("%d ", my_array[i]);
    }
}

int *insert_array(int size){
    int* array = (int*)malloc(size * sizeof(int));
    int inserter;
    
    if (array == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    for (int i = 0; i < size; i++) {
        printf("Enter element %d: ", i+1);
        scanf("%d", &inserter);
        array[i] = inserter;
    }
    return array;
}

int main() {
    int length;
    int choice, user_steps;
    
    printf("Enter length of array: ");
    scanf("%d", &length);
    
    int *user_array = insert_array(length);
    printf("\nOriginal array is: ");
    print_array(user_array, length);
    
    printf("\n\nOptions:\n1 = Rotate Left\t2 = Rotate Right");
    printf("\nChoose: ");
    scanf("%d",&choice);
    
    if (choice == 1){
        printf("\nEnter step: ");
        scanf("%d", &user_steps);
        rotate_L_array(user_array, length, user_steps);
        printf("Left rotate array by %d is: ",user_steps);
        print_array(user_array, length);
    } else if (choice == 2){
        printf("\nEnter step: ");
        scanf("%d", &user_steps);
        rotate_R_array(user_array, length, user_steps);
        printf("Right rotate array by %d is: ",user_steps);
        print_array(user_array, length);
    } else {
        printf("Invalid Choice!");
    }

    return 0;
}