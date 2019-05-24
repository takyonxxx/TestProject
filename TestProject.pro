TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    complex.cpp \
    fractal.cpp \
    main.cpp \
    object.cpp \
    Fractal/Bitmap.cpp \
    Fractal/FractalCreator.cpp \
    Fractal/Mandelbrot.cpp \
    Fractal/RGB.cpp \
    Fractal/ZoomList.cpp


HEADERS += \
    Fractal/Bitmap.h \
    Fractal/BitmapFileHeader.h \
    Fractal/BitmapInfoHeader.h \
    Fractal/FractalCreator.h \
    Fractal/Mandelbrot.h \
    Fractal/RGB.h \
    Fractal/Zoom.h \
    Fractal/ZoomList.h \
    accessmodifiers.h \
    algorithm.h \
    bind.h \   
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
    functional.h \
    functors.h \
    inheritance.h \
    initialization.h \
    interface.h \
    lambda.h \
    libraries.h \
    linkedlist.h \
    lvalue_rvalue.h \    
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
    singleton.h \
    stack_queue.h \
    stream.h \
    template.h \
    vectors_maps.h \
    view.h
