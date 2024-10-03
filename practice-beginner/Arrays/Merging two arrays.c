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

int *merge_array(int my_arr1[], int size1, int my_arr2[], int size2){
    int total = size1 + size2;
    int* array = (int*)malloc(total * sizeof(int));

    if (array == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    for (int i = 0; i < total; i++) {
        if (i!=size1 && i<size1){
            array[i] = my_arr1[i];
        } else {
            array[i] = my_arr2[i-size1];
        }
    }
    return array;
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
    int N1, N2;
    printf("Enter size of array 1: ");
    scanf("%d", &N1);
    int *U_arr1 = insert_array(N1);

    printf("Enter size of array 2: ");
    scanf("%d", &N2);
    int *U_arr2 = insert_array(N2);

    printf("\nArray 1 is: {");
    print_array(U_arr1, N1);

    printf("}\nArray 2 is: {");
    print_array(U_arr2, N2);

    int *merged_array = merge_array(U_arr1, N1, U_arr2, N2);
    printf("}\nMerged array is: {");
    print_array(merged_array, N1+N2);
    printf("}\n");

    return 0;
}

