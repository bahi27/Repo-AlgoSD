#include <stdio.h>

#include "fibonacci.h"

int fibonacci(int n){
	int k =0;
	if  (n==0 || n==1)
		return n;
	else{


		return fibonacci(n-1) + fibonacci(n-2);
	}
}
int  fibonacci_dp(int n){ // Dynamique progamming
	int fibo[n+1];
	if (n==0 || n== 1)
		return n;
	int k ;
	fibo[0]=0;
	fibo[1]=1;
	for (k = 2; k<=n; k++){
		fibo[k]=fibo[k-1] + fibo[k-2];
	}
	return fibo[n];
}

int afficher_dp(int n) {
    for (int i = 0; i < n; i++) {
        printf("Fibo(%d) = %d\n", i, fibonacci_dp(i));
    }
    return 0;
}





int afficher(int n) {
    for (int i = 0; i < n; i++) {
        printf("Fibo(%d) = %d\n", i, fibonacci(i));
    }
    return 0;
}
