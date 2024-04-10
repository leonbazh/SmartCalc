#ifndef FINANCE_H
#define FINANCE_H

#include <QWidget>

namespace Ui {
class finance;
}

class finance : public QWidget
{
    Q_OBJECT

public:
    explicit finance(QWidget *parent = nullptr);
    ~finance();

private:
    Ui::finance *ui;
};

#endif // FINANCE_H
