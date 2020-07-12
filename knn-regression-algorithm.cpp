#include "knn-regression-algorithm.h"
#include <map>

KNNRegressionAlgorithm::KNNRegressionAlgorithm(unsigned int numOfAtts, unsigned int k)
    : KNNAlgorithm(numOfAtts, k)
{

}

double KNNRegressionAlgorithm::predictValue(const std::vector<double> &toBePredicted)
{
    auto dataIndexes = this->getVectorOfKIndexes(toBePredicted);
    double sumOfvalues = 0.0;
    for (auto index : dataIndexes)
    {
        sumOfvalues += this->dataset[index].value;
    }
    return sumOfvalues / dataIndexes.size();
}
