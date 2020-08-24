#ifndef HOLDOUTVALIDATOR_H
#define HOLDOUTVALIDATOR_H

#include "machine-learning-header.h"

class HoldoutValidator
{
public:
    struct HoldoutStr
    {
        std::vector<unsigned int> trainingIndexes;
        std::vector<unsigned int> testIndexes;
    };
    static HoldoutStr makeHoldoutStr(const std::vector<unsigned int> &indexes, double testEntriesPercentage);
};


#endif // HOLDOUTVALIDATOR_H
