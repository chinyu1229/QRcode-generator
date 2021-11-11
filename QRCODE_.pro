QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    qrencode-4.1.1/bitstream.c \
    qrencode-4.1.1/mask.c \
    qrencode-4.1.1/mmask.c \
    qrencode-4.1.1/mqrspec.c \
    qrencode-4.1.1/qrencode.c \
    qrencode-4.1.1/qrinput.c \
    qrencode-4.1.1/qrspec.c \
    qrencode-4.1.1/rsecc.c \
    qrencode-4.1.1/split.c \
    widget.cpp

HEADERS += \
    qrencode-4.1.1/bitstream.h \
    qrencode-4.1.1/config.h \
    qrencode-4.1.1/mask.h \
    qrencode-4.1.1/mmask.h \
    qrencode-4.1.1/mqrspec.h \
    qrencode-4.1.1/qrencode.h \
    qrencode-4.1.1/qrencode_inner.h \
    qrencode-4.1.1/qrinput.h \
    qrencode-4.1.1/qrspec.h \
    qrencode-4.1.1/rsecc.h \
    qrencode-4.1.1/split.h \
    widget.h

FORMS += \
    widget.ui

DEFINES += HAVE_CONFIG_H

#LIBS += -lqrencode
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    img.qrc
