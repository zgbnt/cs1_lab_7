#include <stdio.h>
#include <stdlib.h>

int selection_sort(int* array, int* swap_array) {
    int temp = 0, flag = 0;
    int total_swaps = 0;
    int min = array[0];
    int min_index = 0;

    for(int i = 0; i < 9; i++) {
        min = array[i];
        for(int j = i; j < 9; j++) {
            if(min > array[j]) {
                min = array[j];
                min_index = j;
                flag = 1;
            }
        }
        if(flag == 1) {
            temp = array[i];
            array[i] = array[min_index];
            array[min_index] = temp;
            swap_array[array[i]]++;
            swap_array[array[min_index]]++;
            total_swaps++;
            flag = 0;
            for(int i = 0; i < 9; i++) {
                printf("%d\n", array[i]);
            }
            printf("\n");
        }
    }
    return total_swaps;
}

int bubble_sort(int* array, int* swap_array) {
    int temp;
    int n;
    int total_swaps = 0;
    
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 8 - i; j++) {
            if(array[j] > array[j+1]) {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
                swap_array[array[j]]++;
                swap_array[array[j+1]]++;
                total_swaps++;
            }
        }
    }
    return total_swaps;
}

int main() {
    int arr1swaps = 0;
    int arr2swaps = 0;

    int* arr1 = (int*)malloc(9 * sizeof(int));
    arr1[0] = 97;
    arr1[1] = 16;
    arr1[2] = 45;
    arr1[3] = 63;
    arr1[4] = 13;
    arr1[5] = 22;
    arr1[6] = 7;
    arr1[7] = 58;
    arr1[8] = 72;
    int* swap_array1 = (int*)calloc(100, sizeof(int));
    int* arr2 = (int*)malloc(9 * sizeof(int));
    arr2[0] = 90;
    arr2[1] = 80;
    arr2[2] = 70;
    arr2[3] = 60;
    arr2[4] = 50;
    arr2[5] = 40;
    arr2[6] = 30;
    arr2[7] = 20;
    arr2[8] = 10;
    int* swap_array2 = (int*)calloc(100, sizeof(int));

    arr1swaps += bubble_sort(arr1, swap_array1);
    arr1[0] = 97;
    arr1[1] = 16;
    arr1[2] = 45;
    arr1[3] = 63;
    arr1[4] = 13;
    arr1[5] = 22;
    arr1[6] = 7;
    arr1[7] = 58;
    arr1[8] = 72;
    arr1swaps += selection_sort(arr1, swap_array1);
    arr1[0] = 97;
    arr1[1] = 16;
    arr1[2] = 45;
    arr1[3] = 63;
    arr1[4] = 13;
    arr1[5] = 22;
    arr1[6] = 7;
    arr1[7] = 58;
    arr1[8] = 72;

    arr2swaps += bubble_sort(arr2, swap_array2);
    arr2[0] = 90;
    arr2[1] = 80;
    arr2[2] = 70;
    arr2[3] = 60;
    arr2[4] = 50;
    arr2[5] = 40;
    arr2[6] = 30;
    arr2[7] = 20;
    arr2[8] = 10;
    arr2swaps += selection_sort(arr2, swap_array2);
    arr2[0] = 90;
    arr2[1] = 80;
    arr2[2] = 70;
    arr2[3] = 60;
    arr2[4] = 50;
    arr2[5] = 40;
    arr2[6] = 30;
    arr2[7] = 20;
    arr2[8] = 10;

    printf("array1: \n");
    for(int i = 0; i < 9; i++) {
        printf("%d: %d\n", arr1[i], swap_array1[arr1[i]]);
    }
    printf("Total swaps: %d\n", arr1swaps);
    printf("array2: \n");
    for(int i = 0; i < 9; i++) {
        printf("%d: %d\n", arr2[i], swap_array2[arr2[i]]);
    }
    printf("Total swaps: %d\n", arr2swaps);
}