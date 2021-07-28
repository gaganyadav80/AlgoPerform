QT       += core gui charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    deletion/deletionresult.cpp \
    deletion/deletionwindow.cpp \
    insertion/insertionresult.cpp \
    insertion/insertionwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    searching/searchingresult.cpp \
    searching/searchingwindow.cpp \
    sorting/sortingresult.cpp \
    sorting/sortingwindow.cpp \
    visualizer/visualwindow.cpp \
    visualizer/bheap.cpp \
    visualizer/stack.cpp \
    visualizer/queue.cpp \
    visualizer/visualizer.cpp

HEADERS += \
    deletion/deletionalgo.h \
    deletion/deletionperform.h \
    deletion/deletionresult.h \
    deletion/deletionwindow.h \
    globalvariable.h \
    insertion/insertionalgo.h \
    insertion/insertionperform.h \
    insertion/insertionresult.h \
    insertion/insertionwindow.h \
    mainwindow.h \
    searching/searchingalgo.h \
    searching/searchingperform.h \
    searching/searchingresult.h \
    searching/searchingwindow.h \
    sorting/sortingalgo.h \
    sorting/sortingperform.h \
    sorting/sortingresult.h \
    sorting/sortingwindow.h \
    visualizer/visualwindow.h \
    visualizer/bheap.h \
    visualizer/stack.h \
    visualizer/queue.h \
    visualizer/visualizer.h

FORMS += \
    deletion/deletionresult.ui \
    deletion/deletionwindow.ui \
    insertion/insertionresult.ui \
    insertion/insertionwindow.ui \
    mainwindow.ui \
    searching/searchingresult.ui \
    searching/searchingwindow.ui \
    sorting/sortingresult.ui \
    sorting/sortingwindow.ui \
    visualizer/visualwindow.ui \
    visualizer/bheap.ui \
    visualizer/stack.ui \
    visualizer/queue.ui \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
