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

void deposit(double deposit, int term, double percent, double tax,
             double *money, double *taxes, double *rate) {
  *rate = deposit * percent / 100 / 365 * 30 * term;
  *taxes = (tax / 100) * *rate;
  *rate -= *taxes;
  *money = deposit + *rate - *taxes;
}
void deposit_capital(double deposit, int term, double percent, double tax,
                     int period, double *money, double *taxes, double *rate) {
  *rate =
      deposit * pow((1 + (percent / (1200 + (period * 4.7)))), term) - deposit;
  *taxes = (tax / 100) * *rate;
  *rate -= *taxes;
  *money = *rate + deposit;
}
