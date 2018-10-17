#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "logic.h"

int* create_array(size_t size)
{
	int* result = malloc(sizeof(int) * size);
	memset(result, 0, sizeof(int) * size);
	return result;
}

int* filling_array()
{

	size_t size = 16;

	int* arr = create_array(size);

	for (int i = 0; i < size; i++) {
		arr[i] = i;
	}

	return arr;
}

void swapvalues(int* arr, int x, int y)
{
	int sv;
	sv = arr[x];
	arr[x] = arr[y];
	arr[y] = sv;
}

int mask_build(int* arr, int* mask)
{
	int zero_pos = 0;

	while (arr[zero_pos] != 0) {
		zero_pos++;
	}

	if (zero_pos < 4) {
		mask[2] = 0;
	} else {
		mask[2] = 1;
	} 

	if (zero_pos > 11) {
		mask[1] = 0;
	} else {
		mask[1] = 1;
	} 
	
	if (zero_pos != 0 && (zero_pos + 1) % 4 == 0) {
		mask[3] = 0;
	} else {
		mask[3] = 1;
	} 
	
	if (zero_pos == 0 || zero_pos % 4 == 0) {
		mask[0] = 0;
	} else {
		mask[0] = 1;
	}
 
	return zero_pos;
}

void randomize_board(int* arr)
{
	srand(time(NULL));
	int c, j, a, b;
	int i = rand()%(71) + 30;

	for (j = 1; j < i; j++) {
		a = rand()%(16) + 0;
		b = rand()%(16) + 0;
		c = arr[a];
		arr[a] = arr[b];
		arr[b] = c;
	}
}

int check_board(int* arr)
{
	for (int i = 0; i < 16; i++) {
		if (i != 15 && arr[i] != i + 1) {
			return 0;
		} else if (i == 15 && arr[i] != 0) {
			return 0;
		}
	}

	return 1;
}
