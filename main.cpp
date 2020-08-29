#include <iostream>
#include "knn-classification-algorithm.h"
#include "knn-regression-algorithm.h"
#include "dataset-indexes-generator.h"

int main()
{
    KNNClassificationAlgorithm knn(4, 3);
    knn.loadDatasetFromFile("dataset-files/iris_complete.dataset");
    auto matrix = DatasetIndexesGenerator::generate(knn.getDatasetSize(), 10, true);
    std::cout << knn.optimizeKHoldout(1, 50, matrix, 30.0) << "\n";
    std::cout << knn.getK() << "\n";
    return 0;
}
