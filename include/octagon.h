#pragma once

#include "figure.h"

class Octagon : public Figure {
public:
    Octagon();
    ~Octagon();
    Octagon(Point, Point, Point, Point, Point, Point, Point, Point);
    Point GeomCenter() const override;
    double AreaFigure() const override;
};