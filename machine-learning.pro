TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        dataset-loader.cpp \
        distance-calculator.cpp \
        knn-classification-algorithm.cpp \
        knn-regression-algorithm.cpp \
        main.cpp

HEADERS += \
    dataset-loader.h \
    distance-calculator.h \
    knn-algorithm.h \
    knn-classification-algorithm.h \
    knn-regression-algorithm.h
