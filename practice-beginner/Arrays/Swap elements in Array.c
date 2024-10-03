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

int *swap_array(int my_arr[], int size){

    if (size%2==0){
        int first;
        for (int i=0; i<size; i++){
            if (i%2==0){
                first = my_arr[i];
                my_arr[i] = my_arr[i+1];
                my_arr[i+1] = first;
            } else {
                continue;
            }
        }
    } else {
        int first;
        for(int i=0; i<size; i++){
            if(i%2==0 && i!=size-1){
                first = my_arr[i];
                my_arr[i] = my_arr[i+1];
                my_arr[i+1] = first;
            } else if (i%2!=0 && i==size-1){
                continue;
            }
        }
    }
    return my_arr;
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
    int array_size;

    printf("Enter array size: ");
    scanf("%d", &array_size);

    int *user_array = insert_array(array_size);

    printf("\nOriginal array is: ");
    print_array(user_array, array_size);

    printf("\n\nSwapped array is: ");
    user_array = swap_array(user_array, array_size);
    print_array(user_array, array_size);

    printf("\n");

    return 0;
}

