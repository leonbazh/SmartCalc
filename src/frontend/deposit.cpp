#include "deposit.h"
#include "ui_deposit.h"

Deposit::Deposit(QWidget *parent) : QWidget(parent), ui(new Ui::Deposit) {
  ui->setupUi(this);
  ui->payout->setStyleSheet(
      "QComboBox::drop-down {border:none;} "
      "QComboBox{background-color:rgb(51,51,51); border-radius:20px; "
      "padding-left:55px; padding-right:auto; color:white;}");
  ui->capital->setStyleSheet(
      "QComboBox::drop-down {border:none;} "
      "QComboBox{background-color:rgb(51,51,51); border-radius:20px; "
      "padding-left:55px; padding-right:auto; color:white;}");
  connect(ui->calculate, SIGNAL(clicked()), this, SLOT(calculate()));
}

Deposit::~Deposit() { delete ui; }

void Deposit::calculate() {
  if (ui->sum->text() != "0" && ui->term->text() != "0" &&
      ui->percent->text() != "0") {
    double sum = ui->sum->text().toDouble();
    double percent = ui->percent->text().toDouble();
    double tax = ui->tax->text().toDouble();
    int term = ui->term->text().toInt();
    if ((ui->capital->currentIndex()) == 0) {
      double money = 0;
      double taxes = 0;
      double rate = 0;
      deposit(sum, term, percent, tax, &money, &taxes, &rate);
      ui->money->setText(QString::number(money, 'f', 2));
      ui->taxes->setText(QString::number(taxes, 'f', 2));
      ui->rate->setText(QString::number(rate, 'f', 2));
    } else {
      double money = 0;
      double taxes = 0;
      double rate = 0;
      int capital = 0;
      if ((ui->capital->currentIndex()) == 1) {
        capital = 1;
      } else if (ui->capital->currentIndex() == 2) {
        capital = 3;
      } else {
        capital = 12;
      }
      deposit_capital(sum, term, percent, tax, capital, &money, &taxes, &rate);
      ui->money->setText(QString::number(money, 'f', 2));
      ui->taxes->setText(QString::number(taxes, 'f', 2));
      ui->rate->setText(QString::number(rate, 'f', 2));
    }
  }
}