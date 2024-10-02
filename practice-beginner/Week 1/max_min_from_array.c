// Q. Maximum from Array (Dynamic)

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

int max_array(int my_arr[], int length){
    int maximum;
    
    for(int i=0; i<length; i++){
        if (i==0){
            maximum = my_arr[i];
            //printf("\nCurrent max: %d",maximum);
        } else {
            if (my_arr[i]>maximum){
                maximum = my_arr[i];
                //printf("\nCurrent max: %d",maximum);
            }
        }
    }
    return maximum;
}

int min_array(int my_arr[], int length){
    int minimum;
    
    for(int i=0; i<length; i++){
        if (i==0){
            minimum = my_arr[i];
            //printf("\nCurrent min: %d",minimum);
        } else {
            if (my_arr[i]<minimum){
                minimum = my_arr[i];
                //printf("\nCurrent min: %d",minimum);
            }
        }
    }
    return minimum;
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
    
    printf("}\nMaximum is: %d", max_array(arr, N));
    printf("\nMinimum is: %d", min_array(arr, N));
    
    return 0;
}