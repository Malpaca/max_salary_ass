#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include "max_salary.h"

void print_progress(size_t current, size_t user_min, size_t user_max){
  double count = 100*((double)current - (double)user_min)/((double)user_max-(double)user_min);
	const char prefix[] = "Progress: [";
	const char suffix[] = "]";
	const size_t prefix_length = sizeof(prefix) - 1;
	const size_t suffix_length = sizeof(suffix) - 1;
	char *buffer = calloc(100 + prefix_length + suffix_length + 1, 1); // +1 for \0
	size_t i = 0;

	strcpy(buffer, prefix);
	for (; i < 100; ++i)
	{
		buffer[prefix_length + i] = i < count ? '#' : ' ';
	}

	strcpy(&buffer[prefix_length + i], suffix);
	printf("\r%s progress:%.1f%%", buffer, count);
	fflush(stdout);
	free(buffer);
}

int power(int size){
  int base = 1;
  int word_length = 9/size;
  for (int i = 0; i < word_length; i++){
    base *=10;
  }
  return base;
}

void stress_test(int N){
  srand(time(NULL));   // Initialization, should only be called once.

  while (1) {
    int n = rand() % N + 1; // generate number between 1 to N

	  int *arr = malloc(n*sizeof(int));
    for (int i=0; i<n; i++){
      arr[i] = rand() % power(n);
    }

    printf("array is:");
    print_array(arr, n);

    int result1 = 0;
    max_salary_naive(arr, n, n, &result1);
    int result2 = max_salary_greedy(arr, n);

    if (result1==result2)
      printf("OK:%d\n",result2);
    else {
      printf("Wrong answer: correct=%d, got instead=%d\n", result1, result2);
      free(arr);
	    exit(0);
	  }
	free(arr);
  }
}

void short_test(int * arr, int n){
  printf("array is:");
  print_array(arr, n);

  int result1 = 0;
  max_salary_naive(arr, n, n, &result1);
  int result2 = max_salary_greedy(arr, n);

  if (result1==result2)
    printf("OK:%d\n",result2);
  else {
    printf("Wrong answer: correct=%d, got instead=%d\n", result1, result2);
    exit(0);
  }

}

int main(int argc, char **argv ){
  if (argc < 3){
    printf("To run: test <1> <array seperated by space>\n or test <2> <Number of element in array>\n");
    return 0;
  }

  int mode = atoi(argv[1]);

  if (mode == 1){
    int N = atoi(argv[2]);
    if (N > 18){
      printf("This exceed max data size, please use array length under 19\n");
    }

    stress_test(N);
    return 0;
  }
  else if (mode == 2){
    int n = argc - 2;
    int * arr = malloc(n*sizeof(int));
    for (int i = 0; i < n; i++){
      if (strlen(argv[i+2]) > 9){
        printf("Exceed max data size, please shorten the number at %dth element\n", i-2);
        free(arr);
        return 0;
      }
      arr[i] = atoi(argv[i+2]);
    }
    short_test(arr, n);
    return 0;
  }
  // else if (mode == 2){
  //   if (argc < 3){
  //     printf("To run: test <3> <number of iteration per N>\n");
  //     return 0;
  //   }
  //   int iteration = atoi(argv[2]);
  //   // performance_test(iteration);
  // }

  return 0;
}
