TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        dataset-indexes-generator.cpp \
        dataset-loader.cpp \
        distance-calculator.cpp \
        holdout-validator.cpp \
        knn-classification-algorithm.cpp \
        knn-regression-algorithm.cpp \
        main.cpp

HEADERS += \
    dataset-indexes-generator.h \
    dataset-loader.h \
    distance-calculator.h \
    holdout-validator.h \
    knn-algorithm.h \
    knn-classification-algorithm.h \
    knn-regression-algorithm.h \
    machine-learning-header.h
