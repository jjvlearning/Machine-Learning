#ifndef DATASETINDEXESGENERATOR_H
#define DATASETINDEXESGENERATOR_H

#include "machine-learning-header.h"

class DatasetIndexesGenerator
{
public:
    /*!
     * \brief generate
     * \param datasetSize
     * \param numIt
     * \param shuffle
     * \return
     */
    static UintMatrix generate(unsigned int datasetSize, unsigned int numIt, bool shuffle);
};


#endif // DATASETINDEXESGENERATOR_H
