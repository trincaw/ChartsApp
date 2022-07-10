#include "ChartView.h"
#include <QtGui/QMouseEvent>

ChartView::ChartView() : QChartView(){

}
void ChartView::keyPressEvent(QKeyEvent *event)
{
    if (chart()->series().count()>1 && dynamic_cast<QXYSeries*>(chart()->series().at(0))) {
        switch (event->key()) {
        case Qt::Key_Plus:
            chart()->zoomIn();
            break;
        case Qt::Key_Minus:
            chart()->zoomOut();
            break;
        case Qt::Key_Left:
            chart()->scroll(-10, 0);
            break;
        case Qt::Key_Right:
            chart()->scroll(10, 0);
            break;
        case Qt::Key_Up:
            chart()->scroll(0, 10);
            break;
        case Qt::Key_Down:
            chart()->scroll(0, -10);
            break;
        default:
            QGraphicsView::keyPressEvent(event);
            break;
        }
    }

}
