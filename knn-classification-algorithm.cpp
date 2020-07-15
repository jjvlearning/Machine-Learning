#include "knn-classification-algorithm.h"
#include <map>

std::string KNNClassificationAlgorithm::getValueFromString(const std::string &value)
{
    return value;
}

KNNClassificationAlgorithm::KNNClassificationAlgorithm(unsigned int numOfAtts, unsigned int k)
    : KNNAlgorithm(numOfAtts, k)
{

}

std::string KNNClassificationAlgorithm::predictValue(const std::vector<double> &toBePredicted)
{
    auto dataIndexes = this->getVectorOfKIndexes(toBePredicted);
    std::map<std::string, unsigned int> mapCount;
    for (auto index : dataIndexes)
    {
        mapCount[this->dataset[index].value]++;
    }
    auto maxKv = std::max_element(mapCount.begin(), mapCount.end(),
        [](const std::pair<std::string, int>& p1, const std::pair<std::string, int>& p2) {
            return p1.second < p2.second; });
    return maxKv->first;
}
