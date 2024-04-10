#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculator)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionSimple_triggered(){
    ui->Calcs->setCurrentIndex(0);
}

void MainWindow::on_actionSmart_triggered(){
    ui->Calcs->setCurrentIndex(1);
}

void MainWindow::on_actionFinance_triggered(){
    ui->Calcs->setCurrentIndex(2);
}

void MainWindow::on_actionDeposit_triggered(){
    ui->Calcs->setCurrentIndex(3);
}
