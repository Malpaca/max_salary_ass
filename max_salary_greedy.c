#include "max_salary.h"

unsigned long long int concatenate(unsigned long long int a, unsigned long long int b) {
    unsigned long long int pow = 10;
    while(b >= pow) pow *= 10;
    // printf("%llu, %llu, %llu\n",a,b, pow);
    // printf("%llu\n", a*pow + b);
    return a*pow + b;
}

int is_better (const void * a, const void * b) {
  unsigned long long int first = concatenate((unsigned long long int)*(int*)b,(unsigned long long int)*(int*)a);
  unsigned long long int second = concatenate((unsigned long long int)*(int*)a,(unsigned long long int)*(int*)b);
  if (first > second) return 1;
  else if (second > first) return -1;
  else return 0;
}

// Generating permutation using Heap Algorithm
unsigned long long int max_salary_greedy(int a[], int n){
  qsort(a, n, sizeof(int), is_better);
  unsigned long long int salary = a[0];
  // printf("start conbining\n");
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
