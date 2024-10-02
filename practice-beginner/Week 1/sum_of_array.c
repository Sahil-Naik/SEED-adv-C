// Q. Sum from Array (Dynamic)

#include <stdio.h>
#include <stdlib.h>

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


int sum_of_array(int my_arr[], int length){
    int sum = 0;
    for(int i=0; i<length; i++){
        sum += my_arr[i];
    }
    return sum;
}


void print_array(int my_arr[], int length){
    for (int i=0; i<length; i++){
        if (i!=length-1){
            printf("%d, ", my_arr[i]);
        } else {
            printf("%d", my_arr[i]);
        }
    }
}


int main() {
    int N;
    printf("Enter size of array: ");
    scanf("%d", &N);
    int *arr = insert_array(N);
    
    printf("\nArray is: {");
    print_array(arr, N);
    
    printf("}\nSum is: %d", sum_of_array(arr, N));
    
    return 0;
}