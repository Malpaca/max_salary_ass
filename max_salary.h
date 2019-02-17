#ifndef MAX_SALARY_H
#define MAX_SALARY_H

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SWAP(a,b) {int temp; temp=a; a=b; b=temp;}

void max_salary_naive(int a[], int size, int n, int * result);
int is_better (const void * a, const void * b);
int max_salary_greedy(int a[], int n);
void print_array(int *arr, int size);
int concatenate(int a, int b);

#endif
