// Copyright 2025 UNN-CS Team

#include <gtest/gtest.h>

#include "circle.h"
#include "tasks.h"

namespace {
constexpr double kEps = 1e-9;
constexpr double kPi = 3.14159265358979323846;
}  // namespace

TEST(CircleTest, ConstructorSetsRadius) {
    Circle circle(5.0);

    EXPECT_NEAR(circle.getRadius(), 5.0, kEps);
}

TEST(CircleTest, ConstructorCalculatesFerence) {
    Circle circle(5.0);

    EXPECT_NEAR(circle.getFerence(), 10.0 * kPi, kEps);
}

TEST(CircleTest, ConstructorCalculatesArea) {
    Circle circle(5.0);

    EXPECT_NEAR(circle.getArea(), 25.0 * kPi, kEps);
}

TEST(CircleTest, ConstructorAllowsZeroRadius) {
    Circle circle(0.0);

    EXPECT_NEAR(circle.getRadius(), 0.0, kEps);
    EXPECT_NEAR(circle.getFerence(), 0.0, kEps);
    EXPECT_NEAR(circle.getArea(), 0.0, kEps);
}

TEST(CircleTest, ConstructorThrowsOnNegativeRadius) {
    EXPECT_THROW(Circle(-1.0), std::invalid_argument);
}

TEST(CircleTest, SetRadiusRecalculatesFerence) {
    Circle circle(1.0);

    circle.setRadius(2.5);

    EXPECT_NEAR(circle.getFerence(), 5.0 * kPi, kEps);
}

TEST(CircleTest, SetRadiusRecalculatesArea) {
    Circle circle(1.0);

    circle.setRadius(2.5);

    EXPECT_NEAR(circle.getArea(), 6.25 * kPi, kEps);
}

TEST(CircleTest, SetRadiusAllowsZero) {
    Circle circle(2.0);

    circle.setRadius(0.0);

    EXPECT_NEAR(circle.getRadius(), 0.0, kEps);
    EXPECT_NEAR(circle.getFerence(), 0.0, kEps);
    EXPECT_NEAR(circle.getArea(), 0.0, kEps);
}

TEST(CircleTest, SetRadiusThrowsOnNegativeValue) {
    Circle circle(1.0);

    EXPECT_THROW(circle.setRadius(-0.1), std::invalid_argument);
}

TEST(CircleTest, SetFerenceRecalculatesRadius) {
    Circle circle(1.0);

    circle.setFerence(4.0 * kPi);

    EXPECT_NEAR(circle.getRadius(), 2.0, kEps);
}

TEST(CircleTest, SetFerenceRecalculatesArea) {
    Circle circle(1.0);

    circle.setFerence(4.0 * kPi);

    EXPECT_NEAR(circle.getArea(), 4.0 * kPi, kEps);
}

TEST(CircleTest, SetFerenceAllowsZero) {
    Circle circle(1.0);

    circle.setFerence(0.0);

    EXPECT_NEAR(circle.getRadius(), 0.0, kEps);
    EXPECT_NEAR(circle.getFerence(), 0.0, kEps);
    EXPECT_NEAR(circle.getArea(), 0.0, kEps);
}

TEST(CircleTest, SetFerenceThrowsOnNegativeValue) {
    Circle circle(1.0);

    EXPECT_THROW(circle.setFerence(-1.0), std::invalid_argument);
}

TEST(CircleTest, SetAreaRecalculatesRadius) {
    Circle circle(1.0);

    circle.setArea(9.0 * kPi);

    EXPECT_NEAR(circle.getRadius(), 3.0, kEps);
}

TEST(CircleTest, SetAreaRecalculatesFerence) {
    Circle circle(1.0);

    circle.setArea(9.0 * kPi);

    EXPECT_NEAR(circle.getFerence(), 6.0 * kPi, kEps);
}

TEST(CircleTest, SetAreaAllowsZero) {
    Circle circle(1.0);

    circle.setArea(0.0);

    EXPECT_NEAR(circle.getRadius(), 0.0, kEps);
    EXPECT_NEAR(circle.getFerence(), 0.0, kEps);
    EXPECT_NEAR(circle.getArea(), 0.0, kEps);
}

TEST(CircleTest, SetAreaThrowsOnNegativeValue) {
    Circle circle(1.0);

    EXPECT_THROW(circle.setArea(-1.0), std::invalid_argument);
}

TEST(CircleTest, RepeatedUpdatesKeepValuesConsistent) {
    Circle circle(4.0);

    circle.setFerence(8.0 * kPi);
    circle.setArea(16.0 * kPi);
    circle.setRadius(2.0);

    EXPECT_NEAR(circle.getRadius(), 2.0, kEps);
    EXPECT_NEAR(circle.getFerence(), 4.0 * kPi, kEps);
    EXPECT_NEAR(circle.getArea(), 4.0 * kPi, kEps);
}

TEST(CircleTest, FerenceMatchesFormulaAfterAreaUpdate) {
    Circle circle(1.0);

    circle.setArea(2.25 * kPi);

    EXPECT_NEAR(circle.getFerence(), 2.0 * kPi * circle.getRadius(), kEps);
}

TEST(CircleTest, AreaMatchesFormulaAfterFerenceUpdate) {
    Circle circle(1.0);

    circle.setFerence(3.0 * kPi);

    EXPECT_NEAR(circle.getArea(),
                kPi * circle.getRadius() * circle.getRadius(),
                kEps);
}

TEST(TaskTest, EarthRopeGapMatchesKnownValue) {
    EXPECT_NEAR(calculateEarthRopeGap(), 1.0 / (2.0 * kPi), kEps);
}

TEST(TaskTest, EarthRopeGapDoesNotDependOnEarthRadius) {
    const double gap1 = calculateEarthRopeGap(1000.0, 1.0);
    const double gap2 = calculateEarthRopeGap(1.0, 1.0);

    EXPECT_NEAR(gap1, gap2, kEps);
}

TEST(TaskTest, EarthRopeGapScalesWithAddedLength) {
    EXPECT_NEAR(calculateEarthRopeGap(6378.1, 2.0), 1.0 / kPi, kEps);
}

TEST(TaskTest, EarthRopeGapThrowsOnNegativeArguments) {
    EXPECT_THROW(calculateEarthRopeGap(-1.0, 1.0), std::invalid_argument);
    EXPECT_THROW(calculateEarthRopeGap(6378.1, -1.0), std::invalid_argument);
}

TEST(TaskTest, PoolPavementCostMatchesKnownValue) {
    const PoolCosts costs = calculatePoolCosts();

    EXPECT_NEAR(costs.pavementCost, 7000.0 * kPi, kEps);
}

TEST(TaskTest, PoolFenceCostMatchesKnownValue) {
    const PoolCosts costs = calculatePoolCosts();

    EXPECT_NEAR(costs.fenceCost, 16000.0 * kPi, kEps);
}

TEST(TaskTest, PoolCostsRespectCustomParameters) {
    const PoolCosts costs = calculatePoolCosts(2.0, 3.0, 10.0, 5.0);

    EXPECT_NEAR(costs.pavementCost, 210.0 * kPi, kEps);
    EXPECT_NEAR(costs.fenceCost, 50.0 * kPi, kEps);
}

TEST(TaskTest, PoolCostsWithZeroPathWidthAreStillValid) {
    const PoolCosts costs = calculatePoolCosts(3.0, 0.0, 1000.0, 2000.0);

    EXPECT_NEAR(costs.pavementCost, 0.0, kEps);
    EXPECT_NEAR(costs.fenceCost, 12000.0 * kPi, kEps);
}

TEST(TaskTest, PoolCostsThrowOnNegativeArguments) {
    EXPECT_THROW(calculatePoolCosts(-1.0, 1.0, 1000.0, 2000.0),
                 std::invalid_argument);
    EXPECT_THROW(calculatePoolCosts(1.0, -1.0, 1000.0, 2000.0),
                 std::invalid_argument);
    EXPECT_THROW(calculatePoolCosts(1.0, 1.0, -1000.0, 2000.0),
                 std::invalid_argument);
    EXPECT_THROW(calculatePoolCosts(1.0, 1.0, 1000.0, -2000.0),
                 std::invalid_argument);
}


