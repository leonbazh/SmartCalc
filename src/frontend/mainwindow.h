#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class Calculator;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    Ui::Calculator *ui;

private slots:
    void on_actionSimple_triggered();
    void on_actionSmart_triggered();
    void on_actionFinance_triggered();
    void on_actionDeposit_triggered();

};
#endif // MAINWINDOW_H
