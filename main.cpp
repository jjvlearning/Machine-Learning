#include <iostream>
#include "knn-classification-algorithm.h"
#include "knn-regression-algorithm.h"
#include "dataset-indexes-generator.h"


/* 70000 - 100
 * 10000 - x
 * x = (10000 * 100) / 70000
 * */

int main()
{
    KNNClassificationAlgorithm knn(784, 4);
    knn.loadDatasetFromFile("dataset-files/mnist.dataset");
    auto matrix = DatasetIndexesGenerator::generate(knn.getDatasetSize(), 1, false);
    knn.getHoldoutAccuracy(matrix, 14.285714285714286, true);
    return 0;
}
