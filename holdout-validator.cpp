#include "holdout-validator.h"


HoldoutValidator::HoldoutStr HoldoutValidator::makeHoldoutStr(const std::vector<unsigned int> &indexes, double testEntriesPercentage)
{
    HoldoutStr holdoutStr;
    unsigned int numberOfTestEntries = indexes.size() * (testEntriesPercentage / 100.0);
    unsigned int i;
    unsigned int trainningSize = indexes.size() - numberOfTestEntries;
    for (i = 0; i < trainningSize; ++i)
    {
        holdoutStr.trainingIndexes.push_back(indexes[i]);
    }
    for (; i < indexes.size(); ++i)
    {
        holdoutStr.testIndexes.push_back(indexes[i]);
    }
    return holdoutStr;
}
