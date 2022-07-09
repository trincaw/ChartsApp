QT += charts
QT += xml
win32:RC_ICONS += ChartApp.ico

SOURCES += \
    ChartView.cpp \
    Controller.cpp \
    MainWindow.cpp \
    Model.cpp \
    TableData.cpp \
    main.cpp

HEADERS += \
    Chart.h \
    AllCharts.h \
    ChartTypes.h \
    ChartView.h \
    Controller.h \
    MainWindow.h \
    Model.h \
    TableData.h

RESOURCES += \
    images.qrc
