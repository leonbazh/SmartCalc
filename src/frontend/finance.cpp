#include "finance.h"
#include "QStyle"
#include "ui_deposit.h"
#include "ui_finance.h"

Credit::Credit(QWidget *parent) : QWidget(parent), ui(new Ui::Credit) {
  ui->setupUi(this);
  ui->comboBox->setStyleSheet(
      "QComboBox::drop-down {image: none; background-color:rgba(51,51,51,0); "
      "border-radius:10px; } QComboBox{background-color:rgb(51,51,51); "
      "border-radius:20px; padding-left:28px;}");
  connect(ui->calculate, SIGNAL(clicked()), this, SLOT(calculate()));
}

Credit::~Credit() { delete ui; }

void Credit::calculate() {
  if (ui->sum->text() != "0" && ui->percent->text() != "0" &&
      ui->time->text() != "0") {
    double sum = ui->sum->text().toDouble();
    double percent = ui->percent->text().toDouble();
    int time = ui->time->text().toInt();
    if ((ui->comboBox->currentIndex()) == 0) {
      double monthly_payment;
      double total_payment;
      double overpayment;
      annual(time, sum, percent, &monthly_payment, &overpayment,
             &total_payment);
      ui->monthly->setText(QString::number(monthly_payment, 'f', 2));
      ui->over->setText(QString::number(overpayment, 'f', 2));
      ui->total->setText(QString::number(total_payment, 'f', 2));
    } else {
      double first_payment;
      double last_payment;
      double total_payment;
      double overpayment;
      diff(time, sum, percent, &first_payment, &last_payment, &overpayment,
           &total_payment);
      ui->monthly->setText(QString::number(first_payment, 'f', 2) + "..." +
                           QString::number(last_payment, 'f', 2));
      ui->over->setText(QString::number(overpayment, 'f', 2));
      ui->total->setText(QString::number(total_payment, 'f', 2));
    }
  }
}