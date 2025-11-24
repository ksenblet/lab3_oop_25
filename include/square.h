#pragma once

#include "figure.h"

class Square : public Figure {
public:
    Square();
    ~Square();
    Square(Point, Point, Point, Point);
    Point GeomCenter() const override;
    double AreaFigure() const override;
};