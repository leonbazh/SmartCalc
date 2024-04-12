#ifndef DEPOSIT_H
#define DEPOSIT_H

#include <QWidget>

extern "C" {
#include "../backend/s21_findep.h"
}

namespace Ui {
class Deposit;
}

class Deposit : public QWidget {
  Q_OBJECT

public:
  explicit Deposit(QWidget *parent = nullptr);
  ~Deposit();

private:
  Ui::Deposit *ui;

private slots:
  void calculate();
};

#endif // DEPOSIT_H
