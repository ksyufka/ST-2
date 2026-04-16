// Copyright 2026 UNN-CS
#include <stdexcept>

#include "circle.h"
#include "tasks.h"

double calculateEarthRopeGap(double earthRadiusKm,
                             double addedRopeLengthMeters) {
    if (earthRadiusKm < 0.0 || addedRopeLengthMeters < 0.0) {
        throw std::invalid_argument("Task parameters must be non-negative");
    }

    Circle earth(earthRadiusKm * 1000.0);
    Circle enlargedEarth(earth.getRadius());
    enlargedEarth.setFerence(earth.getFerence() + addedRopeLengthMeters);

    return enlargedEarth.getRadius() - earth.getRadius();
}

PoolCosts calculatePoolCosts(double poolRadius,
                             double pathWidth,
                             double pavementCostPerSquareMeter,
                             double fenceCostPerMeter) {
    if (poolRadius < 0.0 || pathWidth < 0.0 ||
        pavementCostPerSquareMeter < 0.0 || fenceCostPerMeter < 0.0) {
        throw std::invalid_argument("Task parameters must be non-negative");
    }

    Circle pool(poolRadius);
    Circle outer(poolRadius + pathWidth);

    const double pavementArea = outer.getArea() - pool.getArea();

    return {pavementArea * pavementCostPerSquareMeter,
            outer.getFerence() * fenceCostPerMeter};
}
