#ifndef S21_FINDEP_H
#define S21_FINDEP_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void annual(int term, double sum, double percent, double *monthly_payment,
            double *overpayment, double *total_payment);
void diff(int term, double sum, double percent, double *first_payment,
          double *last_payment, double *overpayment, double *total_payment);

void deposit(double deposit, int term, double percent, double tax,
             double *money, double *taxes, double *rate);
void deposit_capital(double deposit, int term, double percent, double tax,
                     int period, double *money, double *taxes, double *rate);

#endif