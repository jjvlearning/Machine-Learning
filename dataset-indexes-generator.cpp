#include "dataset-indexes-generator.h"
#include <numeric>
#include <random>
#include <chrono>
#include <algorithm>


UintMatrix DatasetIndexesGenerator::generate(unsigned int datasetSize, unsigned int numIt, bool shuffle)
{
    UintMatrix result;
    std::vector<unsigned int> indexes;
    indexes.resize(datasetSize);
    std::iota(std::begin(indexes), std::end(indexes), 0);
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    for (unsigned int i = 0; i < numIt; ++i)
    {
        if (shuffle) std::shuffle(indexes.begin(), indexes.end(), std::default_random_engine(seed));
        result.push_back(indexes);
    }
    return result;
}
