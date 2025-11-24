#include "square.h"

Square::Square() {
    v.push(Point(0, 0));
    v.push(Point(1, 0));
    v.push(Point(1, 1));
    v.push(Point(0, 1));
}

Square::Square(Point p1, Point p2, Point p3, Point p4) {
    v.push(p1);
    v.push(p2);
    v.push(p3);
    v.push(p4);
}

Square::~Square() {}

Point Square::GeomCenter() const {
    return ResultCentr(v);
}

double Square::AreaFigure() const {
    return ResultArea(v);
}