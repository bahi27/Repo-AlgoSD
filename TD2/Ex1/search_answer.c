/*---------------------------------------------------------------------*/
#include <math.h>
#include <stdio.h>
#include "search.h"
#include "utils.h"

// Linear search: cherche séquentiellement dans le tableau
int linear_search(int *arr, int n, int target)
{
    for (int k = 0; k < n; k++) {
        if (arr[k] == target)
            return k;
    }
    return -1; // pas trouvé
}

// Jump search: utilise des sauts de √n pour rechercher plus vite dans un tableau trié
int jump_search(int *arr, int n, int target)
{
    // Équivalent simple à sqrt(n), sans math.h
    int step = 1;
    while (step * step < n)
        step++;

    int prev = 0;

    // Trouver le bloc où le target peut être
    while (arr[(step < n ? step : n) - 1] < target) {
        prev = step;
        step += 1; // avance par pas de 1 pour rester simple
        if (prev >= n)
            return -1;
    }

    // Recherche linéaire dans le bloc trouvé
    int end = (step < n) ? step : n;
    for (int i = prev; i < end; i++) {
        if (arr[i] == target)
            return i;
    }

    return -1;
}

// Binary search: divise le tableau trié en 2 à chaque itération
int binary_search(int *arr, int n, int target)
{
    int min = 0;
    int max = n - 1;

    while (min <= max) {
        int mid = (min + max) / 2;

        if (arr[mid] == target)
            return mid;

        if (arr[mid] < target)
            min = mid + 1;
        else
            max = mid - 1;
    }

    return -1; // pas trouvé
}

