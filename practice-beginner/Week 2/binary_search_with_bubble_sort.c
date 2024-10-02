#include <stdio.h>
#include <stdlib.h>

void print_array(int arr[], int size){
    printf("Elements are: ");
    for (int i=0; i<size; i++){
        printf("%d ", arr[i]);
    }
}


int* generate_array(int size){
    int* array = (int*)malloc(size * sizeof(int));
    for (int i=0; i<size; i++){
        int number = 0;
        printf("Enter %d element: ",i+1);
        scanf("%d", &number);
        array[i] = number;
    }
    return array;
}


int* bubble_sort(int unsorted_array[], int size){
    int temp;
    for (int i=0; i<size-1; i++){
        for (int j=0; j<size-1-i; j++)
            if (unsorted_array[j] > unsorted_array[j+1]){
                temp = unsorted_array[j];
                unsorted_array[j] = unsorted_array[j+1];
                unsorted_array[j+1] = temp;
            }
    }
    return unsorted_array;
}

void binary_search(int sorted_array[], int size, int to_find){
    int mid;
    if (size%2==0 && size>1){
        mid = sorted_array[size/2];
        if (to_find < mid){
            for(int i=0; i<size/2; i++){
                if (to_find == sorted_array[i] && i<size/2){
                    printf("\n%d found at position %d", to_find, i+1);
                } else {
                    continue;
                }
            }
        } else if (to_find == mid){
            printf("\n%d found at position %d", to_find, size/2);
        } else {
            for(int i=size/2; i<size; i++){
                if (to_find == sorted_array[i] && i<size/2){
                    printf("\n%d found at position %d", to_find, i+1);
                } else {
                    continue;
                }
            }
        }
    } else if (size%2!=0 && size>1){
        mid = sorted_array[size-1/2];
        if (to_find < mid){
            for(int i=0; i<size-1/2; i++){
                if (to_find == sorted_array[i] && i<size-1/2){
                    printf("\n%d found at position %d", to_find, i+1);
                } else {
                    continue;
                }
            }
        } else if (to_find == mid){
            printf("\n%d found at position %d", to_find, size-1/2);
        } else {
            for(int i=size-1/2; i<size; i++){
                if (to_find == sorted_array[i] && i<size-1/2){
                    printf("\n%d found at position %d", to_find, i+1);
                } else {
                    continue;
                }
            }
        }
    } else if (size==1){
        mid = sorted_array[0];
        if (to_find == mid){
            printf("\n%d found at position %d", to_find, 1);
        } else {
            printf("\n%d does not exist in the Array!");
        }
    } else {
        printf("Array size is NULL!");
    }
}

int main() {
    printf("Program for Binary Search!\n");
    int N;
    printf("Enter size of Array: ");
    scanf("%d", &N);

    int* my_array = generate_array(N);

    printf("\nArray: \n");
    print_array(my_array, N);

    // Sorting Array using bubble_sort
    my_array = bubble_sort(my_array, N);

    int to_search;

    printf("\nEnter element to find: ");
    scanf("%d", &to_search);

    binary_search(my_array, N, to_search);

    return 0;
}
