#include "knn-classification-algorithm.h"
#include "holdout-validator.h"
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

double KNNClassificationAlgorithm::getHoldoutAccuracy(const UintMatrix &indexesMatrix, double testEntriesPercentage)
{
    double accuracy = 0;
    for (auto &indexes : indexesMatrix)
    {
        Dataset backupDataset = this->dataset;
        Dataset curDataset;
        auto holdoutStr = HoldoutValidator::makeHoldoutStr(indexes, testEntriesPercentage);
        for (auto index : holdoutStr.trainingIndexes)
        {
            curDataset.push_back(backupDataset[index]);
        }
        this->dataset = curDataset;
        unsigned int numberOfCorrectPredicts = 0;
        for (auto index : holdoutStr.testIndexes)
        {
            std::string predictValue = this->predictValue(backupDataset[index].attributes);
            numberOfCorrectPredicts += (predictValue == backupDataset[index].value);
        }
        accuracy += (((double)numberOfCorrectPredicts / (double) holdoutStr.testIndexes.size()) * 100.0);
        this->dataset = backupDataset;
    }
    return accuracy / indexesMatrix.size();
}
