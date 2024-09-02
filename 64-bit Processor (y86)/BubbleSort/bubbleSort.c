#include <stdio.h>

void bubbleSort(unsigned long *arr, int size){
    printf("Unsorted Array: \n");
    for (int i = 0; i < size; ++i)
        printf("%lu ", arr[i]);
    printf("\n");
    
    unsigned long place;
    for (int i = 1; i < size; ++ i) {
        for (int j = 0; j < size - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                place = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = place;
            }
        }
    }

    printf("Sorted Array: \n");
    for (int i = 0; i < size; ++i)
        printf("%lu ", arr[i]);
    printf("\n");
}


int main() {
    unsigned long arr[] = {2, 4, 5, 6, 2, 1};
    bubbleSort(arr, 6);

    return 0;
}
