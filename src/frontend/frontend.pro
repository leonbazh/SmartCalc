QT       += core gui
QT += printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    deposit.cpp \
    finance.cpp \
    graph.cpp \
    main.cpp \
    mainwindow.cpp \
    simple.cpp \
    ../backend/s21_findep.c \
    ../backend/s21_calc.c \
    smart.cpp \
    qcustomplot.cpp

HEADERS += \
    deposit.h \
    finance.h \
    graph.h \
    mainwindow.h \
    simple.h \
    ../backend/s21_findep.h \
    ../backend/s21_calc.h \
    smart.h \
    qcustomplot.h

FORMS += \
    deposit.ui \
    finance.ui \
    graph.ui \
    mainwindow.ui \
    simple.ui \
    smart.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
