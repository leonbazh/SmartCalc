#ifndef FINANCE_H
#define FINANCE_H

#include <QWidget>

#include "ui_finance.h"

extern "C"{
    #include "../backend/s21_findep.h"
}

namespace Ui {
class Credit : public Ui_finance{};
}

class Credit : public QWidget
{
    Q_OBJECT

public:
    explicit Credit(QWidget *parent = nullptr);
    ~Credit();

private:
    Ui::Credit *ui;

private slots:
    void calculate();
};

#endif // FINANCE_H
