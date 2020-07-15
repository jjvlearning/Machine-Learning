#include "dataset-loader.h"
#include <fstream>

MatrixOfString DatasetLoader::load(const std::string &filename, unsigned int numOfAtts)
{
    std::ifstream file(filename);
    MatrixOfString entries;
    if (!file.is_open()) return entries;
    while (!file.eof())
    {
        entries.push_back({});
        std::string strRead;
        for (unsigned int i = 0; i < numOfAtts + 1; ++i)
        {
            file >> strRead;
            entries[entries.size() - 1].push_back(strRead);
        }
    }
    entries.pop_back();
    return entries;
}
