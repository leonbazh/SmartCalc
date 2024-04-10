#include "s21_calc.h"

double s21_smartcalc(char *input, double x, int *error) {
  double result = 0.0;
  char str[ENTER] = {0};
  *error = 1;
  if (!check(input, str)) {
    char valid[ENTER];
    if (!validate(str, valid)) {
      char notation[ENTER] = {0};
      pol(valid, notation);
      *error = calculate(notation, x, &result);
    }
  }
  return result;
}

void pol(char *input, char *str) {
  operations *oper = stack_oper(ENTER);
  int i = 0, k = 0;
  for (; i < (int)strlen(input); i++) {
    if (!priority(input[i])) {
      str[k++] = input[i];
      if (priority(input[i + 1]))
        str[k++] = ' ';
    } else if (priority(input[i]) == 1) {
      if (input[i] == '(') {
        oper_push(input[i], oper);
      } else if (input[i] == ')') {
        while (oper_peek(oper) != '(' && oper->index) {
          str[k++] = oper_pop(oper);
        }
        oper_pop(oper);
      }
    } else if (priority(input[i]) > 1) {
      if (priority(oper_peek(oper)) < priority(input[i])) {
        oper_push(input[i], oper);
      } else if (priority(oper_peek(oper)) >= priority(input[i])) {
        while (priority(oper_peek(oper)) >= priority(input[i]))
          str[k++] = oper_pop(oper);

        oper_push(input[i], oper);
      }
    }
  }
  while (oper->index)
    str[k++] = oper_pop(oper);
  oper_free(oper);
}

int calculate(char *input, double x, double *result) {
  numbers *num = stack_num(ENTER);
  int error = 0;
  for (int i = 0; i < (int)strlen(input); i++) {
    if (input[i] == 'x')
      num_push(x, num);
    if (is_number(input[i]) || input[i] == '.') {
      char numbers[ENTER] = {0};
      int j = 0;
      while (input[i] != ' ') {
        numbers[j++] = input[i++];
      }
      num_push(atof(numbers), num);
    } else if (!error &&
               !((input[i] == '-' || input[i] == '*' || input[i] == '/') &&
                 num->index == 1)) {
      error = count(input, i, num);
    }
  }
  *result = num_pop(num);
  num_free(num);
  return error;
}

int count(char *input, int index, numbers *stack) {
  int error = 0;
  if (input[index] == '+')
    num_push(num_pop(stack) + num_pop(stack), stack);
  if (input[index] == '*')
    num_push(num_pop(stack) * num_pop(stack), stack);
  if (input[index] == '-') {
    double num = num_pop(stack);
    num_push(num_pop(stack) - num, stack);
  }
  if (input[index] == '/') {
    double num = num_pop(stack);
    if (num != 0) {
      num_push(num_pop(stack) / num, stack);
    } else {
      error = 1;
    }
  }
  if (input[index] == '%') {
    double num = num_pop(stack);
    if (stack->index && num != 0) {
      num_push(fmodl(num_pop(stack), num), stack);
    } else {
      error = 1;
    }
  }
  if (input[index] == '^') {
    double num = num_pop(stack);
    if (stack->index != 0) {
      num_push(pow(num_pop(stack), num), stack);
    } else {
      error = 1;
    }
  }
  if (input[index] == 's')
    num_push(sin(num_pop(stack)), stack);
  if (input[index] == 'c')
    num_push(cos(num_pop(stack)), stack);
  if (input[index] == 't')
    num_push(tan(num_pop(stack)), stack);
  if (input[index] == 'i')
    num_push(asin(num_pop(stack)), stack);
  if (input[index] == 'o')
    num_push(acos(num_pop(stack)), stack);
  if (input[index] == 'a')
    num_push(atan(num_pop(stack)), stack);
  if (input[index] == 'q')
    num_push(sqrt(num_pop(stack)), stack);
  if (input[index] == 'l')
    num_push(log10(num_pop(stack)), stack);
  if (input[index] == 'n')
    num_push(log(num_pop(stack)), stack);
  return error;
}

int priority(char input) {
  int p = 0;
  char *abbr_functions = "sctioaqln";
  if (strchr(abbr_functions, input)) {
    input = 'y';
  }
  switch (input) {
  case 'y':
    p++;
  case '^':
    p++;
  case '*':
  case '/':
  case '%':
    p++;
  case '+':
  case '-':
    p++;
  case '(':
  case ')':
    p++;
    break;
  }
  return p;
}

int check(char *input, char *str) {
  int flag = ERROR;

  if ((int)strlen(input) <= ENTER && input != NULL) {
    removing_spaces(input, str);
    flag = OK;
  }
  if (str[0] == '\0' || str[0] == ')' || flag == ERROR)
    flag = ERROR;
  else if (symbols_check(str))
    flag = ERROR;
  else if (brackets_check(str))
    flag = ERROR;
  else if (repeat_check(str))
    flag = ERROR;
  else if (funcbracket_check(str))
    flag = ERROR;
  return flag;
}

int brackets_check(char *input) {
  int flag = OK, ok = 0;
  for (int i = 0; i < (int)strlen(input); i++) {
    if (input[i] == '(')
      ok++;
    if (input[i] == ')')
      ok--;
  }
  return flag = ok ? ERROR : OK;
}

int symbols_check(char *input) {
  int flag = OK;
  char *symbols = "sincostalgqrx.(0123456789)+-*/^%";
  for (int i = 0; i < (int)strlen(input) && flag == OK; i++) {
    if (!strchr(symbols, input[i]))
      flag = ERROR;
  }
  return flag;
}

int repeat_check(char *input) {
  int flag = OK;
  char *opers = "+-*/^%";
  for (int i = 0; i < (int)strlen(input) && flag == OK; i++) {
    if (strchr(opers, input[i]) && strchr(opers, input[i + 1]))
      flag = ERROR;
  }
  return flag;
}

int funcbracket_check(char *input) {
  int flag = OK;
  char *functions[9] = {"sin",  "cos",  "tan", "asin", "acos",
                        "atan", "sqrt", "log", "ln"};
  char *start_functions = "sctal";
  for (int i = 0; i < 9 && flag == OK; i++) {
    for (int j = 0; j < (int)strlen(input) && flag == OK; j++)
      if (strncmp(input + j, functions[i], strlen(functions[i])) == 0) {
        if (input[j + strlen(functions[i])] != '(') {
          flag = ERROR;
        }
      }
  }

  return flag;
}

void removing_spaces(char *input, char *str) {
  for (int i = 0, j = 0; i < (int)strlen(input) + 1; i++) {
    if (input[i] != ' ') {
      str[j++] = input[i];
    }
  }
}

int validate(char *input, char *str) {
  int ok = 0, flag = 0;
  char *functions[10] = {"sin",  "cos",  "tan", "asin", "acos",
                         "atan", "sqrt", "log", "ln",   "error"};
  char *abbr_functions = "sctioaqln";
  char *start_functions = "sctal";
  char *operators = "()%/^*+-.x";
  char temp[ENTER];
  for (int i = 0; i < (int)strlen(input) && flag != 2; i++) {
    flag = 0;
    if (strchr(start_functions, input[i])) {
      for (int j = 0; j < 10 && flag == 0; j++) {
        if (!strncmp(input + i, functions[j], strlen(functions[j]))) {
          temp[ok++] = abbr_functions[j];
          i += (int)strlen(functions[j]);
          flag = 1;
        }
      }
    } else if ((i == 0 && input[i] == '-') ||
               (input[i] == '(' && input[i + 1] == '-')) {
      temp[ok++] = '0';
    } else if (input[i] == ')' && input[i - 1] == '(') {
      flag = 2;
    }

    if ((is_number(input[i]) || strchr(operators, input[i])) &&
        !(input[i] == 'x' && strchr(abbr_functions, input[i - 1]))) {
      if (mult_condition(input[i], input[i + 1])) {
        temp[ok++] = input[i];
        temp[ok++] = '*';
      } else {
        temp[ok++] = input[i];
      }
    } else
      flag = 2;
  }
  strncpy(str, temp, ok);
  str[ok++] = '\0';
  return flag;
}

int is_number(char input) { return input >= '0' && input <= '9' ? 1 : 0; }

int mult_condition(char first, char second) {
  int flag = 0;
  char *start_functions = "sctal(";
  if (second != '\0') {
    if (((is_number(first) || first == ')') &&
         ((strchr(start_functions, second))))) {
      flag = 1;
    } else if (first == ')' && (is_number(second) || second == 'x')) {
      flag = 1;
    } else if (second == '(' && (is_number(first) || first == 'x')) {
      flag = 1;
    } else if ((first == 'x' &&
                (is_number(second) || (strchr(start_functions, second)))) ||
               (is_number(first) && second == 'x')) {

      flag = 1;
    } else if (first == 'x' && second == 'x') {
      flag = 1;
    }
  }
  return flag;
}

operations *stack_oper(int size) {
  operations *stack = malloc(sizeof(operations));
  if (stack) {
    stack->oper = malloc(size * sizeof(char));
    stack->index = 0;
  }
  return stack;
}

numbers *stack_num(int size) {
  numbers *stack = malloc(sizeof(numbers));
  if (stack) {
    stack->num = malloc(size * sizeof(double));
    stack->index = 0;
  }
  return stack;
}

void oper_push(char op, operations *stack) {
  stack->oper[stack->index] = op;
  stack->index++;
}

void num_push(double num, numbers *stack) {
  stack->num[stack->index] = num;
  stack->index++;
}

char oper_pop(operations *stack) {
  char op = '0';
  if (stack->index != 0) {
    op = stack->oper[stack->index - 1];
    stack->index--;
  }
  return op;
}

char oper_peek(operations *stack) {
  char op = '0';
  if (stack->index != 0) {
    op = stack->oper[stack->index - 1];
  }
  return op;
}

double num_pop(numbers *stack) {
  double num = 0.0;
  if (stack->index != 0) {
    num = stack->num[stack->index - 1];
    stack->index--;
  }
  return num;
}

double num_peek(numbers *stack) {
  double num = 52.525252;
  if (stack->index != 0) {
    num = stack->num[stack->index - 1];
  }
  return num;
}

void oper_free(operations *stack) {
  if (stack != NULL) {
    if (stack->oper != NULL) {
      free(stack->oper);
      stack->index = 0;
    }
    free(stack);
  }
}

void num_free(numbers *stack) {
  if (stack != NULL) {
    if (stack->num != NULL) {
      free(stack->num);
      stack->index = 0;
    }
    free(stack);
  }
}