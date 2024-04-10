#ifndef S21_FINDEP_H
#define S21_FINDEP_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void annual(int term, double sum, double percent, double *monthly_payment,
            double *overpayment, double *total_payment);
void diff(int term, double sum, double percent, double *first_payment,
          double *last_payment, double *overpayment, double *total_payment);

#endif