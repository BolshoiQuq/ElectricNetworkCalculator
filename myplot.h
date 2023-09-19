#ifndef MYPLOT_H
#define MYPLOT_H

#include <QWidget>

#include "qcustomplot.h"

class GraphWidget: public QWidget
{

    Q_OBJECT

public:
    GraphWidget(QWidget* parent = nullptr);
    void set_settings(std::string fpath);
private:
    QWidget* m_widget;
    double xBegin, xEnd, yBegin, yEnd, h;
    int N;
    QVector<double> x,y;

    QCustomPlot* m_plot;
};


#endif // MYPLOT_H
