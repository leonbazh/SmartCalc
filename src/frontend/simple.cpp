#include "simple.h"


Simple::Simple(QWidget *parent) : QWidget(parent), ui(new Ui::Simple)
{
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
}

Simple::~Simple(){
    delete ui;
}

void Simple::PushButton(){
    QPushButton* button = (QPushButton*)sender();
    ui->lineEdit->setText(ui->lineEdit->text()+button->text());
}

void Simple::on_div_clicked(){
    ui->lineEdit->setText(ui->lineEdit->text() + "/");    
}

void Simple::on_mult_clicked(){
    ui->lineEdit->setText(ui->lineEdit->text() + "*");    
}

void Simple::on_c_clicked(){
    ui->lineEdit->clear();
}

void Simple::on_x_clicked(){
    ui->lineEdit->setText("-(" + ui->lineEdit->text() +")");
}

void Simple::on_back_clicked(){
    ui->lineEdit->backspace();
}

void Simple::on_result_clicked(){
    int error = OK;
    double x = 1;
    std::string str = ui->lineEdit->text().toStdString();
    char *arr_str = const_cast<char *>(str.c_str());
    double result = s21_smartcalc(arr_str, x, &error);
    if(!error){
        ui->lineEdit->setText(QString::number(result, 'g', 7));
    }
    else{
        ui->lineEdit->setText("error");
    }
}