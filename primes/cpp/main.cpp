#include <iostream>
#include <string>
#include <math.h>

char* arr;
int prime = 2;
unsigned int max_prime;

inline int get_next_prime(unsigned int last_prime) {
	last_prime++;
	while (true) {
		if (arr[last_prime]) {
			return last_prime;
		}
		if (last_prime == max_prime) {
			return 0;
		}
		last_prime++;
	}
}

int main(int, char** argv) {
	max_prime = std::atol(argv[1]);

	arr = (char*) malloc(max_prime + 1);

	for (unsigned int i = 2; i <= max_prime; i++) {
		arr[i] = 1;
	}

	unsigned int prime = 2;

	unsigned int counter = 0;

	unsigned int root = (int)std::sqrt(max_prime);

	while (1) {
		for (unsigned int i = prime; i <= max_prime; i += prime) {
			arr[i] = 0;
		}
		//std::cout << prime << std::endl;
		counter++;
		prime = get_next_prime(prime);
		if (prime >= root) break;
	}

	while (1) {
		//std::cout << prime << std::endl;
		prime = get_next_prime(prime);
		counter++;
		if (prime == 0) break;
	}

	delete arr;

	std::cout << "number of primes to " << max_prime << ": " << counter << std::endl;;
	return 0;
}
