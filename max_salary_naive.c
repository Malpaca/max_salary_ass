#include "max_salary.h"

void print_array(int *arr, int size){
  for (int i=0; i<size; i++){
    printf("%d ",arr[i]);
  }
  printf("\n");
}

// Generating permutation using Heap Algorithm
void max_salary_naive(int a[], int size, int n, unsigned long long * max)
{
    // if size becomes 1 then do something with the obtained permutation
    if (size == 1)
    {
        //TO DO - instead of printing, insert your code for evaluating the next candidate array
        unsigned long long salary = (unsigned long long)a[0];
        for (int i = 1; i < n; i++){
          salary = concatenate(salary,a[i]);
        }
        // print_array(a, n);
        if (salary > *max) *max = salary;
        return;
    }

    for (int i=0; i<size; i++)
    {
        max_salary_naive(a,size-1,n, max);

        // if size is odd, swap first and last element
        if (size%2==1) {
            SWAP(a[0], a[size-1]);
		}
        // If size is even, swap ith and last element
        else{
            SWAP(a[i], a[size-1]);
		}
    }
}

// Code to test permutations
// int main() {
//     int a[] = {1, 2, 3, 4};
//     int n = sizeof a/sizeof a[0];
//     int result = 0;
//     max_salary_naive(a, n, n, &result);
//     printf("%d\n",result);
//     return 0;
// }
