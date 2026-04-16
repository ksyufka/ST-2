// Copyright 2022 UNN-CS
#include <cmath>
#include <stdexcept>

#include "circle.h"

void Circle::validateValue(double value) {
    if (value < 0.0) {
        throw std::invalid_argument("Circle values must be non-negative");
    }
}

void Circle::updateFromRadius() {
    ference = 2.0 * kPi * radius;
    area = kPi * radius * radius;
}

Circle::Circle(double radiusValue) {
    setRadius(radiusValue);
}

void Circle::setRadius(double radiusValue) {
    validateValue(radiusValue);
    radius = radiusValue;
    updateFromRadius();
}

void Circle::setFerence(double ferenceValue) {
    validateValue(ferenceValue);
    ference = ferenceValue;
    radius = ference / (2.0 * kPi);
    area = kPi * radius * radius;
}

void Circle::setArea(double areaValue) {
    validateValue(areaValue);
    area = areaValue;
    radius = std::sqrt(area / kPi);
    ference = 2.0 * kPi * radius;
}

double Circle::getRadius() const {
    return radius;
}

double Circle::getFerence() const {
    return ference;
}

double Circle::getArea() const {
    return area;
}

