#ifndef SMART_H
#define SMART_H

#include <QVector>
#include <QWidget>

#include "graph.h"
#include "qcustomplot.h"
#include "ui_graph.h"
#include "ui_smart.h"

namespace Ui {
class Smart;
}

extern "C" {
#include "../backend/s21_calc.h"
}

class Smart : public QWidget {
  Q_OBJECT

public:
  explicit Smart(QWidget *parent = nullptr);
  ~Smart();

private:
  Ui::Smart *ui;

private slots:
  void PushButton();
  void PushButtonFunc();
  void on_div_clicked();
  void on_mult_clicked();
  void on_c_clicked();
  void on_negative_clicked();
  void on_back_clicked();
  void on_result_clicked();
  void on_graph_clicked();
  void on_sqrt_clicked();
  void on_pow_clicked();
};

#endif // SMART_H
