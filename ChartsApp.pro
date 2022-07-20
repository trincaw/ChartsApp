QT += charts
QT += xml
win32:RC_ICONS += ChartApp.ico

SOURCES += \
    Surces/AllCharts.cpp \
    Surces/ChartView.cpp \
    Surces/Controller.cpp \
    Surces/MainWindow.cpp \
    Surces/Model.cpp \
    Surces/TableData.cpp \
    main.cpp \

HEADERS += \
    Headers/Chart.h \
    Headers/AllCharts.h \
    Headers/ChartTypes.h \
    Headers/ChartView.h \
    Headers/Controller.h \
    Headers/MainWindow.h \
    Headers/Model.h \
    Headers/TableData.h

RESOURCES += \
    images.qrc
