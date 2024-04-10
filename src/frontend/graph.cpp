#include "graph.h"
#include "ui_graph.h"
#include "qcustomplot.h"


Graph::Graph(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Graph)
{
    ui->setupUi(this);
    ui->graphic->setBackground(QColor(0, 0, 0));
    ui->graphic->xAxis->setBasePen(QPen(QColor(81, 81, 81)));
    ui->graphic->yAxis->setBasePen(QPen(QColor(81, 81, 81)));
    ui->graphic->xAxis->setTickLabelColor(QColor(81, 81, 81));
    ui->graphic->yAxis->setTickLabelColor(QColor(81, 81, 81));
    ui->graphic->xAxis->setTickPen(QPen(QColor(81, 81, 81)));
    ui->graphic->yAxis->setTickPen(QPen(QColor(81, 81, 81)));
    ui->graphic->xAxis->setSubTickPen(QPen(QColor(81, 81, 81)));
    ui->graphic->yAxis->setSubTickPen(QPen(QColor(81, 81, 81)));
    ui->graphic->xAxis->grid()->setPen(QPen(QColor(81,81,81)));
    ui->graphic->yAxis->grid()->setPen(QPen(QColor(81,81,81)));
}

Graph::~Graph()
{
    delete ui;
}

void Graph::createGraph(const QVector <double>& x, const QVector <double>& y){
    QCPGraph* graph = ui->graphic->addGraph();
    graph->setData(x, y);
    ui->graphic->graph(0)->setPen(QColor(255, 159, 10));
    ui->graphic->rescaleAxes();
    ui->graphic->replot();
}