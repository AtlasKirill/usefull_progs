#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int is_prime(int i_byte, int shift, char *array_of_char) {
	int a = array_of_char[i_byte] & (1 << shift);
	return a;
}

void sieve_set_bit(int i, int j, char *array_of_char) {
	int i_byte = j / 8;
	int shift = j % 8;
	array_of_char[i_byte] = array_of_char[i_byte] & (~(1 << shift));
}

int main() {
	unsigned int roof = 0, buffer = 0;
	int n = 1000000;
	roof = n * (log(n) + log(log(n)));
	buffer = roof / (2*8) + 8;  //divide in 2 because we need two times shorter array (only for odd numbers)
	char * array_of_char = (char *)calloc(buffer, 1);
	int i, j, border = (int)sqrt(roof/2) + 1, i_byte = 0, shift = 0;
	int counter = 1;  //we consider that 2 is prime number

	//fil an array with units	
	for (i = 0; i < buffer; i++)
		array_of_char[i] = 255;

	//fill cells whith zeros if they contain composit number	
	for (i = 2; i <= border; i++) {
		i_byte = i / 8;
		shift = i % 8;
		if (is_prime(i_byte, shift, array_of_char)) {
			for (j = 3*i-1; j <= roof/2; j += 2*i-1) {
				sieve_set_bit(i, j, array_of_char);
			}
		}
	}

	//count the number of units and when it is 1_000_000 output on display result
	for (i = 2; i <= roof; i++) {
		i_byte = i / 8;
		shift = i % 8;
		if (is_prime(i_byte, shift, array_of_char))
			counter++;
		if (counter == 1000000) {
			int k = 2 * i - 1;
			printf("%d",k);
			return 0;
		}

	}
}
