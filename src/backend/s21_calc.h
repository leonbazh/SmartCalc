#ifndef S21_SMARTCALC_H
#define S21_SMARTCALC_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ENTER 255

#define OK 0
#define ERROR 1

typedef struct {
  double *num;
  int index;
} numbers;

typedef struct {
  char *oper;
  int index;
} operations;

// check

int check(char *input, char *str);
int symbols_check(char *input);
int brackets_check(char *input);
int repeat_check(char *input);
int funcbracket_check(char *input);
int is_number(char input);
int mult_condition(char first, char second);
int priority(char ch);

// stack

numbers *stack_num(int size);
void num_push(double num, numbers *stack);
double num_pop(numbers *stack);
double num_peek(numbers *stack);
void num_free(numbers *stack);

operations *stack_oper(int size);
void oper_push(char op, operations *stack);
char oper_pop(operations *stack);
char oper_peek(operations *stack);
void oper_free(operations *stack);

// proccess

double s21_smartcalc(char *input, double x, int *error);
void removing_spaces(char *input, char *str);
int validate(char *input, char *str);
void pol(char *input, char *str);
int calculate(char *input, double x, double *result);
int count(char *input, int index, numbers *stack);

#endif