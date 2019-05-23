TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        bitmap.cpp \
        complex.cpp \
        fractal.cpp \
        fractalcreator.cpp \
        main.cpp \
        mandelbrot.cpp \
        object.cpp \
        rgb.cpp \
        zoomlist.cpp

HEADERS += \
    accessmodifiers.h \
    algorithm.h \
    bind.h \
    bitmap.h \
    bitmapfileheader.h \
    bitmapinfoheader.h \
    casting.h \
    chainofresponsibility.h \
    common.h \
    complex.h \
    constructors.h \
    controller.h \
    database.h \
    decltype.h \
    delegating.h \
    encapsulation.h \
    enhancedloops.h \
    enumaration.h \
    exceptions.h \
    fractal.h \
    fractalcreator.h \
    functional.h \
    functors.h \
    inheritance.h \
    initialization.h \
    interface.h \
    lambda.h \
    libraries.h \
    linkedlist.h \
    lvalue_rvalue.h \
    mandelbrot.h \
    model.h \
    namespace.h \
    nestedtemplate.h \
    object.h \
    optimization.h \
    overloadfunction.h \
    overloadoperator.h \
    passvalue.h \
    perfectforwarding.h \
    pointers.h \
    polymorphism.h \
    pragmadirective.h \
    racingexample.h \
    rgb.h \
    singleton.h \
    stack_queue.h \
    stream.h \
    template.h \
    vectors_maps.h \
    view.h \
    zoom.h \
    zoomlist.h

DISTFILES += \
    ../build-TestProject/fractal.bmp
