#ifndef KNNREGRESSIONALGORITHM_H
#define KNNREGRESSIONALGORITHM_H

#include "knn-algorithm.h"

class KNNRegressionAlgorithm : public KNNAlgorithm <double>
{
public:
    KNNRegressionAlgorithm(unsigned int numOfAtts, unsigned int k);
    virtual double predictValue(const std::vector<double> &toBePredicted) override;
};


#endif // KNNREGRESSIONALGORITHM_H
