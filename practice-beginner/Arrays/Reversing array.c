// Q. Program to reverse an Array
#include <stdio.h>
#include <stdlib.h>

int *reverse_array(int my_array[], int length){
    if (length%2==0 && length!=1){
        for (int i=0; i<length/2; i++){
            int temp;
            temp = my_array[i];
            my_array[i] = my_array[length-(i+1)];
            my_array[length-(i+1)] = temp;
        }
    } else if (length%2!=0 && length!=1) {
        for (int i=0; i<(length-1)/2; i++){
            int temp;
            temp = my_array[i];
            my_array[i] = my_array[length-(i+1)];
            my_array[length-(i+1)] = temp;
        }
    } else {
        return my_array;
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
    
    printf("Enter length of array: ");
    scanf("%d", &length);
    
    int *user_array = insert_array(length);
    printf("\nOriginal array is: ");
    print_array(user_array, length);
    
    reverse_array(user_array, length);
    printf("\nReverse array is: ");
    print_array(user_array, length);

    return 0;
}