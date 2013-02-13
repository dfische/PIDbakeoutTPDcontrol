DEFINES += QT_DLL QWT_DLL

SOURCES += \
    main.cpp \
    dialogrga.cpp \
    serial.cpp \
    serialrequest.cpp \
    combivac.cpp \
    form.cpp \
    trackingplot.cpp \
    speczoomer.cpp \
    dialog335.cpp \
    timerbutton.cpp \
    serialconfigdialog.cpp \
    filamentbutton.cpp \
    cdembutton.cpp

win32 {
    include(C:/Users/Administrator/Downloads/qextserialport-1.2beta2/src/qextserialport.pri)
    LIBS+= -lqwtd -LC:\\Qwt-6.0.1\\lib
    INCLUDEPATH+=C:\\Qwt-6.0.1\\include
    DEFINES += QT_DLL \
            QWT_DLL
}
unix {
    include(../qextserialport-1.2beta2/src/qextserialport.pri)
    LIBS += -lqwt
    INCLUDEPATH += /usr/include/qwt6
}

QT += testlib

HEADERS += \
    dialogrga.h \
    serial.h \
    serialrequest.h \
    combivac.h \
    form.h \
    trackingplot.h \
    speczoomer.h \
    dialog335.h \
    timerbutton.h \
    serialconfigdialog.h \
    filamentbutton.h \
    cdembutton.h \
    massplot.h

FORMS += \
    form.ui \
    serialconfigdialog.ui
