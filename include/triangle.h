#pragma once

#include "figure.h"

class Triangle : public Figure {
public:
    Triangle();
    Triangle(Point a, Point b, Point c);
    ~Triangle();
    Point GeomCenter() const override;
    double AreaFigure() const override;
};