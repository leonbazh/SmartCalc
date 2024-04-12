#include "smart.h"
#include "graph.h"
#include "ui_graph.h"

Smart::Smart(QWidget *parent) : QWidget(parent), ui(new Ui::Smart) {
  ui->setupUi(this);
  connect(ui->point, SIGNAL(clicked()), this, SLOT(PushButton()));
  connect(ui->mod, SIGNAL(clicked()), this, SLOT(PushButton()));
  connect(ui->plus, SIGNAL(clicked()), this, SLOT(PushButton()));
  connect(ui->minus, SIGNAL(clicked()), this, SLOT(PushButton()));
  connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(PushButton()));
  connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(PushButton()));
  connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(PushButton()));
  connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(PushButton()));
  connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(PushButton()));
  connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(PushButton()));
  connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(PushButton()));
  connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(PushButton()));
  connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(PushButton()));
  connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(PushButton()));
  connect(ui->sin, SIGNAL(clicked()), this, SLOT(PushButtonFunc()));
  connect(ui->cos, SIGNAL(clicked()), this, SLOT(PushButtonFunc()));
  connect(ui->tan, SIGNAL(clicked()), this, SLOT(PushButtonFunc()));
  connect(ui->asin, SIGNAL(clicked()), this, SLOT(PushButtonFunc()));
  connect(ui->acos, SIGNAL(clicked()), this, SLOT(PushButtonFunc()));
  connect(ui->atan, SIGNAL(clicked()), this, SLOT(PushButtonFunc()));
  connect(ui->log, SIGNAL(clicked()), this, SLOT(PushButtonFunc()));
  connect(ui->ln, SIGNAL(clicked()), this, SLOT(PushButtonFunc()));
}

Smart::~Smart() { delete ui; }

void Smart::PushButton() {
  QPushButton *button = (QPushButton *)sender();
  ui->lineEdit->setText(ui->lineEdit->text() + button->text());
}

void Smart::PushButtonFunc() {
  QPushButton *button = (QPushButton *)sender();
  ui->lineEdit->setText(ui->lineEdit->text() + button->text() + "()");
}

void Smart::on_sqrt_clicked() {
  ui->lineEdit->setText(ui->lineEdit->text() + "sqrt()");
}

void Smart::on_pow_clicked() {
  ui->lineEdit->setText(ui->lineEdit->text() + "^2");
}

void Smart::on_div_clicked() {
  ui->lineEdit->setText(ui->lineEdit->text() + "/");
}

void Smart::on_mult_clicked() {
  ui->lineEdit->setText(ui->lineEdit->text() + "*");
}

void Smart::on_c_clicked() { ui->lineEdit->clear(); }

void Smart::on_negative_clicked() {
  ui->lineEdit->setText("-(" + ui->lineEdit->text() + ")");
}

void Smart::on_back_clicked() { ui->lineEdit->backspace(); }

void Smart::on_result_clicked() {
  int error = OK;
  double x = ui->ikas->text().toDouble();
  std::string str = ui->lineEdit->text().toStdString();
  char *arr_str = const_cast<char *>(str.c_str());
  double result = s21_smartcalc(arr_str, x, &error);
  if (!error) {
    ui->lineEdit->setText(QString::number(result, 'g', 7));
  } else {
    ui->lineEdit->setText("error");
  }
}

void Smart::on_graph_clicked() {
  int error = 0;
  double xmax = ui->xymax->text().toDouble();
  double ymax = xmax;
  double xmin = -xmax;
  double ymin = -xmax;
  if (xmin < xmax && ymin < ymax) {
    double step = 0.1;
    int N = (xmax - xmin) / step + 2;
    int i = 0;
    QVector<double> xValue(N), y(N);
    std::string str = ui->lineEdit->text().toStdString();
    char *arr_str = const_cast<char *>(str.c_str());
    for (double start = xmin; start < xmax && !error; start += step, i++) {
      xValue[i] = start;
      y[i] = s21_smartcalc(arr_str, start, &error);
    }
    if (!error) {
      Graph *graphWindow = new Graph(nullptr);
      graphWindow->createGraph(xValue, y);
      graphWindow->show();
    } else {
      ui->lineEdit->setText("error");
    }
  } else {
    ui->lineEdit->setText("error");
  }
}
