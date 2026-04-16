// Copyright 2022 UNN-CS
#ifndef INCLUDE_CIRCLE_H_
#define INCLUDE_CIRCLE_H_

class Circle {
 private:
    double radius{};
    double ference{};
    double area{};

    static constexpr double kPi = 3.14159265358979323846;

    static void validateValue(double value);
    void updateFromRadius();

 public:
    explicit Circle(double radiusValue);

    void setRadius(double radiusValue);
    void setFerence(double ferenceValue);
    void setArea(double areaValue);

    double getRadius() const;
    double getFerence() const;
    double getArea() const;
};

#endif  // INCLUDE_CIRCLE_H_
