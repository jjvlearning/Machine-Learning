#ifndef DATASETLOADER_H
#define DATASETLOADER_H

#include <vector>
#include <string>

using MatrixOfString = std::vector<std::vector<std::string>>;

class DatasetLoader
{
public:
    static MatrixOfString load(const std::string &filename, unsigned int numOfAtts);
};

#endif // DATASETLOADER_H
