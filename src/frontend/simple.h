 #ifndef SIMPLE_H
#define SIMPLE_H

#include <QWidget>
#include "ui_simple.h"


extern "C" {
#include "../backend/s21_calc.h"
};

namespace Ui{
class Simple;
}

class Simple : public QWidget
{
    Q_OBJECT
public:
    explicit Simple(QWidget *parent = nullptr);
    ~Simple();

private slots:
    void PushButton();
    void on_div_clicked();
    void on_mult_clicked();
    void on_c_clicked();
    void on_x_clicked();
    void on_back_clicked();
    void on_result_clicked();
private:
    Ui::Simple* ui;

};

#endif // SIMPLE_H
