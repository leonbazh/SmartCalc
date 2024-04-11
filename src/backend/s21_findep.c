#include "s21_findep.h"

void annual(int term, double sum, double percent, double *monthly_payment,
            double *overpayment, double *total_payment) {
  percent /= 1200;
  *monthly_payment = (sum * percent) / (1 - pow(1 + percent, -term));
  *total_payment = *monthly_payment * term;
  *overpayment = *total_payment - sum;
}
void diff(int term, double sum, double percent, double *first_payment,
          double *last_payment, double *overpayment, double *total_payment) {
  percent /= 1200;
  *first_payment = sum / term + sum * percent;
  *last_payment = sum / term + sum * percent / 12;
  *overpayment = (sum / 12 + (sum * percent * (term + 1) / 2)) - sum / 12;
  *total_payment = *overpayment + sum;
}