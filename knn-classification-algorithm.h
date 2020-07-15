#ifndef KNNCLASSIFICATIONALGORITHM_H
#define KNNCLASSIFICATIONALGORITHM_H

#include "knn-algorithm.h"

class KNNClassificationAlgorithm : public KNNAlgorithm <std::string>
{
protected:
    std::string getValueFromString(const std::string &value) override;
public:
    KNNClassificationAlgorithm(unsigned int numOfAtts, unsigned int k);
    virtual std::string predictValue(const std::vector<double> &toBePredicted) override;
};


#endif // KNNCLASSIFICATIONALGORITHM_H
