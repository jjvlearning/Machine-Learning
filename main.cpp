#include <iostream>
#include "knn-classification-algorithm.h"
#include "knn-regression-algorithm.h"
#include "dataset-indexes-generator.h"

int main()
{
    KNNClassificationAlgorithm knn(4, 3);
    knn.loadDatasetFromFile("dataset-files/iris_complete.dataset");
    auto matrix = DatasetIndexesGenerator::generate(knn.getDatasetSize(), 10, true);
    std::cout << knn.getHoldoutAccuracy(matrix, 20.0) << "\n";
    return 0;
}
