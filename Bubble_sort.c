// Online C compiler to run C program online
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
        printf("Enter %d element: ",i);
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

int main() {
    printf("Program for Bubble Sorting!\n");
    int N;
    printf("Enter size of Array: ");
    scanf("%d", &N);
    
    int* my_array = generate_array(N);
    
    printf("\nArray before Sorting: \n");
    print_array(my_array, N);
    
    printf("\nArray after Sorting: \n");
    my_array = bubble_sort(my_array, N);
    print_array(my_array, N);

    return 0;
}