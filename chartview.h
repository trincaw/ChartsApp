#ifndef CHARTVIEW_H
#define CHARTVIEW_H

#include <QtCharts>
#include <QtWidgets/QRubberBand>

QT_USE_NAMESPACE

class ChartView : public QChartView
{
public:
    ChartView();
protected:
    void keyPressEvent(QKeyEvent *event);
private:
    bool m_isTouching;
};

#endif
