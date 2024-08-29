QT       += core gui network charts positioning webenginewidgets multimedia multimediawidgets svg
QMAKE_PROJECT_DEPTH = 0
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    audiostreamthread.cpp \
    browserwidget.cpp \
    calculatepath.cpp \
    chatwidget.cpp \
    colorgradient.cpp \
    facetime.cpp \
    hovereventfilter.cpp \
    indexwidget.cpp \
    main.cpp \
    mainwindow.cpp \
    mediawidget.cpp \
    naviwidget.cpp \
    painterWidget.cpp \
    settingwidget.cpp \
    streamthread.cpp \
    videoencoderthread.cpp \
    videoreceiver.cpp \
    weatherdata.cpp \
    widget.cpp

HEADERS += \
    audiostreamthread.h \
    browserwidget.h \
    calculatepath.h \
    chatwidget.h \
    colorgradient.h \
    facetime.h \
    hovereventfilter.h \
    indexwidget.h \
    mainwindow.h \
    mediawidget.h \
    multiWidget.h \
    naviwidget.h \
    painterWidget.h \
    settingwidget.h \
    streamthread.h \
    videoencoderthread.h \
    videoreceiver.h \
    weatherdata.h \
    widget.h

FORMS += \
    browserwidget.ui \
    chatwidget.ui \
    indexwidget.ui \
    mainwindow.ui \
    mediawidget.ui \
    naviwidget.ui \
    settingwidget.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc \
    qss.qrc \
    resources.qrc \
    text.qrc \
    citycode.qrc \
    resources.qrc

INCLUDEPATH +=$$PWD/ffmpeglib/include

LIBS += $$PWD/ffmpeglib/lib/avcodec.lib \
        $$PWD/ffmpeglib/lib/avfilter.lib \
        $$PWD/ffmpeglib/lib/avformat.lib \
        $$PWD/ffmpeglib/lib/avutil.lib \
        $$PWD/ffmpeglib/lib/postproc.lib \
        $$PWD/ffmpeglib/lib/swresample.lib \
        $$PWD/ffmpeglib/lib/swscale.lib

