CC = gcc
CFLAGS = -Wall -std=c99

all: test

max_salary_naive.o: max_salary_naive.c max_salary.h
	$(CC) $(CFLAGS) -c max_salary_naive.c

max_salary_fast.o: max_salary_greedy.c max_salary.h
	$(CC) $(CFLAGS) -c max_salary_greedy.c

test.o: test.c max_salary.h
	$(CC) $(CFLAGS) -c test.c

test: max_salary_naive.o max_salary_greedy.o test.o
	$(CC) $(CFLAGS) -o test max_salary_naive.o max_salary_greedy.o test.o

clean:
	rm *.o test
