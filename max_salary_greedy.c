#include "max_salary.h"

int concatenate(int a, int b) {
    int pow = 10;
    while(b >= pow)
        pow *= 10;
    return a*pow + b;
}

int is_better (const void * a, const void * b) {
   return concatenate(*(int*)b,*(int*)a) - concatenate(*(int*)a,*(int*)b);
}

// Generating permutation using Heap Algorithm
int max_salary_greedy(int a[], int n){
  qsort(a, n, sizeof(int), is_better);
  int salary = a[0];
  for (int i = 1; i < n; i++){
    salary = concatenate(salary,a[i]);
  }
  return salary;
}

// Code to test greedy
// int main() {
//     int a[] = {1, 2, 3, 4};
//     int n = sizeof a/sizeof a[0];
//     int result = max_salary_greedy(a, n);
//     printf("%d\n",result);
//     return 0;
// }
