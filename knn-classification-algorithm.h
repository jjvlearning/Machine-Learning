#ifndef KNNCLASSIFICATIONALGORITHM_H
#define KNNCLASSIFICATIONALGORITHM_H

#include "knn-algorithm.h"

class KNNClassificationAlgorithm : public KNNAlgorithm <std::string>
{
public:
    KNNClassificationAlgorithm(unsigned int numOfAtts, unsigned int k);
    virtual std::string predictValue(const std::vector<double> &toBePredicted) override;
};


#endif // KNNCLASSIFICATIONALGORITHM_H
