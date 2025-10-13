#include <stdio.h>
#include "prime_number.h"

int main(){
	int res ;
	res = prime_number(15);
	printf("Il y a %d premier inferieur a 15\n",res );
	return 0;
}
