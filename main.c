#include <stdio.h>
#include <stdlib.h>

//Task 2------------------------
void array_fill(int *arr){
    for(int i = 0; i < 10; i++){
        scanf("%d", &arr[i]);
    }
}

void array_print(int* arr){
    for(int i = 0; i < 10; i++){
    printf("%d ", arr[i]);
    }
}

void bucketSort(int* arr, int len){
    const int max = len;
    const int b = 10;

    int buckets[b][max+1];
    for(int i = 0; i < b; ++i){
        buckets[i][max] = 0;
    }

    for(int digit = 1; digit < 1000000; digit = digit*10){
        for(int i = 0; i < max; ++i){
            int d = (arr[i]/digit)%b;
            int counter = buckets[d][max];
            buckets[d][counter] = arr[i];
            counter++;
            buckets[d][max] = counter;
        }
        int idx = 0;
        for(int i = 0; i < b; ++i){
            for(int j = 0; j < buckets[i][max]; ++j){
                arr[idx++] = buckets[i][j];
            }
            buckets[i][max] = 0;
        }
    }
}

int main()
{
    const int len = 10;
    int array [len];

    printf("Inpur 10 numbers: ");
    array_fill(array);

    bucketSort(array, len);

    array_print(array);

    return 0;
}

