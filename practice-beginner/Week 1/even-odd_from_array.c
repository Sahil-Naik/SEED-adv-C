// Q. Even-Odd numbers from Array (Dynamic)

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


void even_from_array(int my_arr[], int length){
    int count = 0;
    for(int i=0; i<length; i++){
        if (length!=1){
            if (my_arr[i]%2==0 && i!=length-1 && count>=0){
                printf("%d ", my_arr[i]);
                count++;
            } else if (i==length-1 && count==0) {
                printf("None!");
            } else if (my_arr[i]%2==0 && i==length-1 && count>=0) {
                printf("%d ", my_arr[i]);
                count++;
            }
        } else {
            if (my_arr[i]%2==0){
                printf("%d ", my_arr[i]);
            } else {
                printf("None!");
            }
        }
    }
}

void odd_from_array(int my_arr[], int length){
    int count = 0;
    for(int i=0; i<length; i++){
        if (length!=1){
            if (my_arr[i]%2!=0 && i!=length-1 && count>=0){
                printf("%d ", my_arr[i]);
                count++;
            } else if (i==length-1 && count==0) {
                printf("None!");
            } else if (my_arr[i]%2!=0 && i==length-1 && count>=0) {
                printf("%d ", my_arr[i]);
                count++;
            }
        } else {
            if (my_arr[i]%2!=0){
                printf("%d ", my_arr[i]);
            } else {
                printf("None!");
            }
        }
    }
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
    
    printf("}\nEven numbers are: ");
    even_from_array(arr, N);
    
    printf("\nOdd numbers are: ");
    odd_from_array(arr, N);
    
    return 0;
}