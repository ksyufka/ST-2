// Copyright 2026 UNN-CS
#ifndef INCLUDE_TASKS_H_
#define INCLUDE_TASKS_H_

struct PoolCosts {
    double pavementCost;
    double fenceCost;
};

double calculateEarthRopeGap(double earthRadiusKm = 6378.1,
                             double addedRopeLengthMeters = 1.0);

PoolCosts calculatePoolCosts(double poolRadius = 3.0,
                             double pathWidth = 1.0,
                             double pavementCostPerSquareMeter = 1000.0,
                             double fenceCostPerMeter = 2000.0);

#endif  // INCLUDE_TASKS_H_
