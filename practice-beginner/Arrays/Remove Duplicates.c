#include <stdio.h>
#include <stdlib.h>

void print_array(int my_arr[], int length){
    printf(" {");
    for (int i=0; i<length; i++){
        if (i!=length-1){
            printf("%d, ", my_arr[i]);
        } else {
            printf("%d", my_arr[i]);
        }
    }
    printf("}\n");
}

void remove_duplicates(int old_array[], int *n){
    int i, j, k;
    for (i=0; i<*n; i++){
        for (j=i+1; j<*n; j++){
            if (old_array[i] == old_array[j]){
                for (k=j; k<*n-1; k++){
                    old_array[k] = old_array[k+1];
                }
                (*n)--;
                j--;
            }
        }
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

int main() {
    int N;

    printf("Enter size of array: ");
    scanf("%d", &N);

    int *user_array = generate_array(N);
    printf("\nOriginal array is:");
    print_array(user_array, N);

    printf("\nAfter removing duplicates:");
    remove_duplicates(user_array, &N);
    print_array(user_array, N);

    return 0;
}
