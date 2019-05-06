TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

HEADERS += \
    chainofresponsibility.h \
    command.h \
    common.h \
    controller.h \
    exceptions.h \
    interpreter.h \
    iterator.h \
    libraries.h \
    model.h \
    overload.h \
    passvalue.h \
    racingexample.h \
    singleton.h \
    view.h
