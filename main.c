#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <memory.h>

int main(int argc, char *argv[]) {

	if (argc != 2) {
		printf("Usage: ./lucky <n>\n");
		return -1;
	}

	char *endptr;
	long long int sn_count = strtoll(argv[1], &endptr, 10);
	if (*endptr != 0) {
		printf("the number of sku is invalid.\n");
		return -1;
	}

	char sn[11] = { 0 };
	char tail_numbers[6] = { "666666" };

	srand((unsigned int)time(0));

	for (int benchmark = 0; benchmark < 10; ++benchmark) {
		int lucky_count = 0;
		clock_t start_clock = clock();
		for (long long int x = 0; x < sn_count; x++) {
			for (int i = 0; i < 10; ++i) {
				sn[i] = rand() % 10 + '0';
			}
			if (memcmp(sn + 4, tail_numbers, 6) == 0) {
				lucky_count++;
			}
		}
		double time_cost = ((double)(clock() - start_clock)) / CLOCKS_PER_SEC;
		printf("Round %d: lucky_count=%2d time_cost=%fs\n", benchmark, lucky_count, time_cost);
	}

	return 0;
}

