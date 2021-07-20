QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    acerca.cpp \
    calcularsalario.cpp \
    main.cpp \
    principal.cpp

HEADERS += \
    acerca.h \
    calcularsalario.h \
    principal.h

FORMS += \
    acerca.ui \
    principal.ui

TRANSLATIONS += \
    Salario_es_EC.ts \
    Salario_en_US.ts \
    Salario_ja_JP.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Recursos/Recursos.qrc
