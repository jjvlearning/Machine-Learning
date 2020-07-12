#include <iostream>
#include "knn-classification-algorithm.h"
#include "knn-regression-algorithm.h"

int main()
{
    KNNClassificationAlgorithm knnClassification(2, 3);
    knnClassification.addEntry({{2.5, 4.0}, "A"});
    knnClassification.addEntry({{3.0, 4.2}, "A"});
    knnClassification.addEntry({{2.0, 2.0}, "B"});
    knnClassification.addEntry({{1.5, 1.8}, "B"});
    knnClassification.addEntry({{3.5, 3.8}, "C"});
    knnClassification.addEntry({{3.4, 4.0}, "C"});
    std::cout << knnClassification.predictValue({3.9, 4.2}) << "\n";

    KNNRegressionAlgorithm knnRegression(2, 3);
    knnRegression.addEntry({{2.5, 4.0}, 1.2});
    knnRegression.addEntry({{3.0, 4.2}, 5.0});
    knnRegression.addEntry({{2.0, 2.0}, 2.2});
    knnRegression.addEntry({{1.5, 1.8}, 3.4});
    knnRegression.addEntry({{3.5, 3.8}, 4.2});
    knnRegression.addEntry({{3.4, 4.0}, 6.0});
    std::cout << knnRegression.predictValue({3.9, 4.2}) << "\n";

    return 0;
}
