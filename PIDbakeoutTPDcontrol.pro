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
    filamentbutton.cpp \
    cdembutton.cpp
INCLUDEPATH+=C:\\Qwt-6.0.1\\include

LIBS+= -lqwtd -LC:\\Qwt-6.0.1\\lib

include(C:/Users/Administrator/Downloads/qextserialport-1.2beta2/src/qextserialport.pri)

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
    filamentbutton.h \
    cdembutton.h

FORMS += \
    form.ui
