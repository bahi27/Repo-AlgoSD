#include "utils.h"

#include <stdbool.h>

// Échange deux entiers via leurs pointeurs
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    // swap two elements
}

// Vérifie si le tableau est trié en ordre non décroissant
bool is_sorted_nondecreasing(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
    // check if array is sorted, if yes return true, if not return false
}

// Copie les éléments d'un tableau source dans un tableau destination
void copy_array(int *src, int *dst, int n)
{
    for (int k = 0; k < n; k++) {
        dst[k] = src[k];
    }
    // copy array elements src into dst
}

