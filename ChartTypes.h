#ifndef CHARTTYPES_H
#define CHARTTYPES_H
#include <QChart>

#include <vector>
#include <string>

#include "Chart.h"

using QtCharts::QChart;
class BarredChart: public Chart{};
class RoundChart: public Chart{};
class ContinuousChart: public Chart{};

#endif // CHARTTYPES_H
