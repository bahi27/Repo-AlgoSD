#include <stdio.h>
#include "fibonacci.h"
#include <time.h>
void main(){
	afficher(10);
	clock_t start = clock();
	fibonacci(40);
	clock_t end = clock();
	int times = (end - start)*1000/CLOCKS_PER_SEC;
	printf("Time_for_naive_algo:%d\n",times);

	// pour la programmation dynamique
	afficher_dp(10);
	clock_t start_dp = clock();
        fibonacci_dp(40);
        clock_t end_dp = clock();
        int times_dp = (end_dp - start_dp)*1000/CLOCKS_PER_SEC;
        printf("Time_for_dynamique_algo:%d\n",times_dp);


}
