#include <stdio.h>

unsigned int findInt(int, int*, unsigned int);
void selectionSort(int*, unsigned int, unsigned int);
void print(int*, unsigned int);
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<MAIN
int main(void) {
    int n = 10, value = 0;

    int array[10] = {49, -9, 44, 49, -22, 32, 47, -42, -24, -99};
    print(array, n);

    printf("Enter the desired number:\n>");
    scanf("%d", &value);

    selectionSort(array, n, 1 + findInt(value, array, n));
    print(array, n);

    return 0;
}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void print(int* arr, unsigned int len) {
    puts("\tCurrent state of the array:");
    for (int i = 0; i < len; ++i) {
        printf("%4d", arr[i]);
    }
    fflush(stdin);
    getchar();
}
unsigned int findInt(int value, int* arr, unsigned int arrLen) {
    for (unsigned int i = 0; i < arrLen; ++i) {
        if (arr[i] == value) return i;
    }
}
void selectionSort(int* arr, unsigned int arrLen, unsigned int start) {
    for (int i = start; i < arrLen; ++i) {
        int min = arr[i], /*баль*/buff = 0;
        unsigned int minIndex = i;

        for (int j = 0; j < arrLen - i; ++j) {
            if (arr[i+j] < min) {
                min = arr[i+j];
                minIndex = i+j;
            }
        }

        buff = arr[i];
        arr[i] = min;
        arr[minIndex] = buff;
    }
}