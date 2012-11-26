SOURCES += \
    main.cpp \
    dialog335.cpp \
    dialogcombivac.cpp \
    dialogrga.cpp
INCLUDEPATH+=C:\\Qwt-6.0.1\\include

LIBS+= -lqwtd -LC:\\Qwt-6.0.1\\lib

include(C:/Users/Administrator/Downloads/qextserialport-1.2beta2/src/qextserialport.pri)

QT += testlib

HEADERS += \
    dialog335.h \
    dialogcombivac.h \
    dialogrga.h
