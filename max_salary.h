#ifndef MAX_SALARY_H
#define MAX_SALARY_H

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SWAP(a,b) {int temp; temp=a; a=b; b=temp;}

void max_salary_naive(int a[], int size, int n, unsigned long long int * max);
int is_better (const void * a, const void * b);
unsigned long long int max_salary_greedy(int a[], int n);
void print_array(int *arr, int size);
unsigned long long int concatenate(unsigned long long int a, unsigned long long int b);

#endif
