#include "distance-calculator.h"
#include <cmath>

double DistanceCalculator::euclidianDistance(const std::vector<double> &p, const std::vector<double> &q, unsigned int numOfAtts)
{
    double distance = 0.0;
    for (unsigned int i = 0; i < numOfAtts; ++i)
    {
        distance += std::pow(p[i] - q[i], 2.0);
    }
    return std::sqrt(distance);
}
