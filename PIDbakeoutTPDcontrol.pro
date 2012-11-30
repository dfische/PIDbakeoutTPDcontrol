DEFINES += QT_DLL QWT_DLL

SOURCES += \
    main.cpp \
    dialog335.cpp \
    dialogrga.cpp \
    serial.cpp \
    serialrequest.cpp \
    combivac.cpp \
    form.cpp \
    trackingplot.cpp \
    speczoomer.cpp
INCLUDEPATH+=C:\\Qwt-6.0.1\\include

LIBS+= -lqwtd -LC:\\Qwt-6.0.1\\lib

include(C:/Users/Administrator/Downloads/qextserialport-1.2beta2/src/qextserialport.pri)

QT += testlib

HEADERS += \
    dialog335.h \
    dialogrga.h \
    serial.h \
    serialrequest.h \
    combivac.h \
    form.h \
    trackingplot.h \
    speczoomer.h

FORMS += \
    form.ui
