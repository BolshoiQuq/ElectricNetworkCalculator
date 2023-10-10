#include <QApplication>
#include <fstream>
#include <iostream>
#include <QTextStream>
//#include <QText>
#include <qdebug.h>

#include "myplot.h"


void scan(std::string path_file, QVector<double> &x, QVector<double> &y)
{
    x.clear();
    y.clear();

    std::string line;
    std::ifstream in1(path_file);
    if (in1.is_open())
    {

        std::getline(in1, line);
        std::string a;
        std::string b;
        for(int j = 0; j < line.size(); j++)
        {
            if (line[j] == ';')
                path_file = line.substr(0, j);
        }

        while(std::getline(in1, line))
        {
            std::getline(in1, line);
            for(int j = 1; j < line.size() - 1; j++)
            {
                if (line[j] == ';')
                {
                    a = line.substr(0, j);
                    b = line.substr(j + 1, line.size() - j);
                }
            }
            x.push_back(QString::fromStdString(a).toDouble());
            y.push_back(QString::fromStdString(b).toDouble());
        }

    }
    in1.close();
}



GraphWidget::GraphWidget(QWidget* parent)
    : QWidget(parent)
{

}

void GraphWidget::set_settings(std::string fpath)
{
    m_plot = new QCustomPlot(this);

    qDebug() << (QString::fromStdString(fpath));
    m_plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom ); // | QCP::iSelectPlottables
    QPushButton* button = new QPushButton("update", this);

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(m_plot);
    layout->addWidget(button);



    // Создаем график
    QCPGraph* graph = m_plot->addGraph();

    scan(fpath, this->x, this->y);

    graph->setPen(QPen(Qt::blue));
    //graph->setBrush(QBrush(QColor(0, 0, 255, 20)));

    graph->setData(x, y);

    m_plot->rescaleAxes();
    m_plot->replot();

    connect(button, &QPushButton::clicked, this, [this]()
            {

                m_plot->graph(0)->setData(x, y);
                m_plot->rescaleAxes();
                m_plot->replot();
            });
}
