/*-------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utils.h"
#include "search.h"

int compare_ints(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main(void)
{
    int a[] = {
        42, 17, 93, 58, 12, 84, 39, 76, 5, 61,
        29, 73, 8, 67, 90, 21, 33, 48, 26, 99,
        13, 3, 55, 62, 87, 19, 70, 45, 31, 95,
        40, 1, 27, 64, 81, 6, 88, 23, 14, 36,
        59, 30, 78, 66, 25, 35, 16, 38, 94, 60,
        10, 89, 18, 71, 52, 7, 24, 80, 43, 91,
        4, 28, 97, 11, 75, 56, 50, 79, 46, 32,
        37, 63, 0, 20, 85, 2, 92, 15, 68, 44,
        34, 9, 86, 22, 98, 74, 51, 49, 83, 65,
        47, 53, 57, 77, 41, 72, 96, 69, 82, 54,
        121, 108, 117, 134, 101, 115, 103, 110, 122, 105,
        140, 137, 104, 123, 143, 106, 112, 138, 109, 145,
        113, 100, 107, 102, 114, 139, 116, 120, 118, 119,
        124, 125, 126, 127, 128, 129, 130, 131, 132, 133,
        135, 136, 141, 142, 144, 146, 147, 148, 149, 150,
        151, 152, 153, 154, 155, 156, 157, 158, 159, 160,
        161, 162, 163, 164, 165, 166, 167, 168, 169, 170,
        171, 172, 173, 174, 175, 176, 177, 178, 179, 180,
        181, 182, 183, 184, 185, 186, 187, 188, 189, 190,
        191, 192, 193, 194, 195, 196, 197, 198, 199, 200
    };

    int n = sizeof(a) / sizeof(a[0]);
    int target = 89;

    // Linear Search
    clock_t debut = clock();
    int index_linear = linear_search(a, n, target);
    clock_t fin = clock();
    double time_linear = (double)(fin - debut) * 1000 / CLOCKS_PER_SEC;
    printf("Linear search index: %d, Time: %.3f ms\n", index_linear, time_linear);

    // Jump Search (needs sorted array)
    int *arr_jump = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) arr_jump[i] = a[i];
    qsort(arr_jump, n, sizeof(int), compare_ints);

    debut = clock();
    int index_jump = jump_search(arr_jump, n, target);
    fin = clock();
    double time_jump = (double)(fin - debut) * 1000 / CLOCKS_PER_SEC;
    printf("Jump search index: %d, Time: %.3f ms\n", index_jump, time_jump);
    free(arr_jump);

    // Binary Search (needs sorted array)
    int *arr_bin = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) arr_bin[i] = a[i];
    qsort(arr_bin, n, sizeof(int), compare_ints);

    debut = clock();
    int index_binary = binary_search(arr_bin, n, target);
    fin = clock();
    double time_binary = (double)(fin - debut) * 1000 / CLOCKS_PER_SEC;
    printf("Binary search index: %d, Time: %.3f ms\n", index_binary, time_binary);
    free(arr_bin);

    return 0;
}

