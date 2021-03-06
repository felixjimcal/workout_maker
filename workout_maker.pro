QT       += core gui charts network

greaterThan(QT_MAJOR_VERSION, 6): QT += widgets printsupport

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    exerciseswindow.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    exerciseswindow.h \
    mainwindow.h

FORMS += \
    exerciseswindow.ui \
    mainwindow.ui

TRANSLATIONS += \
    workout_maker_en_GB.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
