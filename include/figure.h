#pragma once

#include <iostream>

#include "arrayPoints.h"

class Figure {
public:
    Figure();
    virtual ~Figure();
    
    void ReadPoints(std::istream& is);
    void PrintPoints(std::ostream& os) const;
    virtual Point GeomCenter() const;
    virtual double AreaFigure() const;
    operator double() const;
    
    friend bool operator==(const Figure& f1, const Figure& f2);
    friend bool operator!=(const Figure& f1, const Figure& f2);

protected:
    ArrayPoints v;
    double ResultArea(const ArrayPoints&) const;
    Point ResultCentr(const ArrayPoints&) const;
};

std::istream& operator>>(std::istream& is, Figure& f);
std::ostream& operator<<(std::ostream& os, const Figure& f);