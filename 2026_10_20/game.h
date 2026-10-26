#pragma once
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ROW 9
#define LIN 9
#define ROWS ROW + 2
#define LINS LIN + 2

void print_array(char arr[ROWS][LINS], int rows, int lins);
void set_array(char arr[ROWS][LINS], int rows, int lins, char bit);
void set_array_to_one(char arr[ROWS][LINS]);
void find_lei(char shade[ROWS][LINS], char show[ROWS][LINS], int rows, int lins);
