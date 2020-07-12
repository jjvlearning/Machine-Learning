#ifndef KNNALGORITHM_H
#define KNNALGORITHM_H

#include <vector>
#include <algorithm>
#include "distance-calculator.h"


template <class T>
class KNNAlgorithm
{
    struct Data
    {
        std::vector<double> attributes;
        T value;
    };
protected:
    using Dataset = std::vector<Data>;
    Dataset dataset;
    unsigned int numOfAtts;
    unsigned int k;
    struct DistanceStr
    {
        unsigned int dataIndex;
        double distance;
    };
    std::vector<DistanceStr> getVectorOfDistanceStr(const std::vector<double> &toBePredicted)
    {
        std::vector<DistanceStr> distanceVector;
        for (unsigned int index = 0; index < this->dataset.size(); ++index)
        {
            distanceVector.push_back
            (
                {index, DistanceCalculator::euclidianDistance(toBePredicted, this->dataset[index].attributes, this->numOfAtts)}
            );
        }
        return distanceVector;
    }
    std::vector<unsigned int> getVectorOfKIndexes(const std::vector<double> &toBePredicted)
    {
        std::vector<unsigned int> indexes;
        auto distanceVector = this->getVectorOfDistanceStr(toBePredicted);
        std::sort(distanceVector.begin(), distanceVector.end(), [](const DistanceStr &a, const DistanceStr &b)
        {
            return a.distance < b.distance;
        });
        for (unsigned int i = 0; i < k; ++i)
        {
            indexes.push_back(distanceVector[i].dataIndex);
        }
        return indexes;
    }
public:
    KNNAlgorithm(unsigned int numOfAtts, unsigned int k):
        numOfAtts(numOfAtts), k(k){}
    void addEntry(const Data &data)
    {
        if (data.attributes.size() != this->numOfAtts)
        {
            throw std::invalid_argument("invalid numOfAtts");
        }
        this->dataset.push_back(data);
    }
    void clearDatas()
    {
        this->dataset.clear();
    }
    virtual T predictValue(const std::vector<double> &toBePredicted) = 0;
};

#endif // KNNALGORITHM_H
