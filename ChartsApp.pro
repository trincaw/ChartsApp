QT += charts
QT += xml
win32:RC_ICONS += ChartApp.ico

SOURCES += \
    Sources/AllCharts.cpp \
    Sources/ChartView.cpp \
    Sources/Controller.cpp \
    Sources/MainWindow.cpp \
    Sources/Model.cpp \
    Sources/TableData.cpp \
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
