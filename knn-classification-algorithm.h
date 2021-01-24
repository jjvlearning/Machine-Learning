#ifndef KNNCLASSIFICATIONALGORITHM_H
#define KNNCLASSIFICATIONALGORITHM_H

#include "knn-algorithm.h"
#include "machine-learning-header.h"

class KNNClassificationAlgorithm : public KNNAlgorithm <std::string>
{
protected:
    std::string getValueFromString(const std::string &value) override;
public:
    KNNClassificationAlgorithm(unsigned int numOfAtts, unsigned int k);
    virtual std::string predictValue(const std::vector<double> &toBePredicted) override;
    double getHoldoutAccuracy(const UintMatrix &indexesMatrix, double testEntriesPercentage, bool showMsg);
    double optimizeKHoldout(unsigned int kMin, unsigned int kMax, const UintMatrix &indexesMatrix, double testEntriesPercentage);
};


#endif // KNNCLASSIFICATIONALGORITHM_H
