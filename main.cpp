#include <iostream>
#include "knn-classification-algorithm.h"
#include "knn-regression-algorithm.h"

int main()
{
    KNNClassificationAlgorithm knn(4, 20);
    knn.loadDatasetFromFile("dataset-files/iris_complete.dataset");
    std::cout << knn.predictValue({5.2, 3.9, 1.6, 0.3}) << "\n";
    std::cout << knn.predictValue({5.5, 2.7, 3.5, 1.2}) << "\n";
    std::cout << knn.predictValue({6.5, 2.7, 5.4, 2.2}) << "\n";
    return 0;
}
