#include <stdio.h>
#include <stdbool.h>
#include "prime_number.h"

// Fonction récursive pour compter les nombres premiers jusqu'à n
int prime_number(int n) {
    if (n < 0)
        return 0;

    if (prime(n))
        return 1 + prime_number(n - 1);
    else
        return prime_number(n - 1);
}

// Fonction pour vérifier si un nombre est premier
bool prime(int n) {
    if (n <= 1)
        return false;

    for (int i = 2; i < n; i++) {
        if (n % i == 0)
            return false;
    }

    return true;
}
