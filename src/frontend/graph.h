#ifndef GRAPH_H
#define GRAPH_H

#include <QMainWindow>
#include "QVector"


#include "smart.h"
#include "qcustomplot.h"

extern "C"{
#include "../backend/s21_calc.h"
}

namespace Ui {
class Graph;
}

class Graph : public QMainWindow
{
    Q_OBJECT

public:
    explicit Graph(QWidget *parent = nullptr);
    ~Graph();
    void createGraph(const QVector <double>& x, const QVector <double>& y);
private:
    Ui::Graph *ui;
    
};

#endif // GRAPH_H
