#ifndef LOGIC_H
#define LOGIC_H

int* create_array(size_t size);

int* filling_array();

void randomize_board(int* arr);

void swapvalues(int* arr, int x, int y);

int mask_build(int* arr, int* mask);

int check_board(int* arr);

#endif
