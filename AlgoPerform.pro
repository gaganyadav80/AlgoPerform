QT       += core gui charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    sorting/sortingdialog.cpp \
    sorting/sortingresult.cpp \
    sorting/sortingwindow.cpp

HEADERS += \
    globalvariable.h \
    mainwindow.h \
    sorting/sortingalgo.h \
    sorting/sortingdialog.h \
    sorting/sortingperform.h \
    sorting/sortingresult.h \
    sorting/sortingwindow.h

FORMS += \
    mainwindow.ui \
    sorting/sortingdialog.ui \
    sorting/sortingresult.ui \
    sorting/sortingwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
