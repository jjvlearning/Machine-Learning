#ifndef DISTANCECALCULATOR_H
#define DISTANCECALCULATOR_H

#include <vector>

class DistanceCalculator
{
public:
    static double euclidianDistance
    (
        const std::vector<double> &p,
        const std::vector<double> &q,
        unsigned int numOfAtts
    );
};


#endif // DISTANCECALCULATOR_H
