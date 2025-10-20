#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>     // pour memcpy
#include "sort.h"
#include "utils.h"

#define N 50000   // Taille du tableau

void benchmark_sort(void (*sort_fn)(int *, int), int *original, int n, const char *name)
{
    int *copy = malloc(n * sizeof(int));
    if (!copy) {
        fprintf(stderr, "Erreur d'allocation mémoire\n");
        return;
    }

    memcpy(copy, original, n * sizeof(int));

    clock_t start = clock();
    sort_fn(copy, n);
    clock_t end = clock();

    double duration = (double)(end - start) / CLOCKS_PER_SEC;
    printf("%s : %.6f secondes | Trié ? %s\n", name, duration,
           is_sorted_nondecreasing(copy, n) ? "Oui" : "Non");

    free(copy);
}

int main(void)
{
    // Initialiser le générateur de nombres aléatoires
    srand((unsigned int)time(NULL));

    // Créer le tableau original
    int *arr = malloc(N * sizeof(int));
    if (!arr) {
        fprintf(stderr, "Erreur d'allocation mémoire\n");
        return 1;
    }

    // Remplir le tableau avec des valeurs aléatoires
    for (int i = 0; i < N; i++) {
        arr[i] = rand();
    }

    // Benchmarks des différents tris
    printf("Comparaison des algorithmes de tri sur %d éléments :\n\n", N);
    benchmark_sort(bubble_sort, arr, N, "Tri à bulles     ");
    benchmark_sort(insertion_sort, arr, N, "Tri par insertion");
    benchmark_sort(selection_sort, arr, N, "Tri par sélection");
    benchmark_sort(merge_sort, arr, N, "Tri fusion        ");
    benchmark_sort(quick_sort, arr, N, "Tri rapide        ");

    free(arr);
    return 0;
}

