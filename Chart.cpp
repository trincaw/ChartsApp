#include "Chart.h"

void Chart::decolor(){
    QString seriesColorHex = "#FFFFFF";
    for (u_int i(0); i < model->getTable()->getRowCount(); i++) {
        for (u_int j=0;j < model->getTable()->getColumnCount();++j){
        model->addMapping(seriesColorHex, QRect(j, i,model->getTable()->getColumnCount() ,model->getTable()->getRowCount()));
        }
    }
}
