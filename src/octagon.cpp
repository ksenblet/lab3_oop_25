#include <cmath>

#include "octagon.h"

Octagon::Octagon() {
    for (int i = 0; i < 8; ++i) {
        double angle = 2 * M_PI * i / 8;
        v.push(Point(static_cast<int>(cos(angle) * 10), static_cast<int>(sin(angle) * 10)));
    }
}

Octagon::Octagon(Point p1, Point p2, Point p3, Point p4, Point p5, Point p6, Point p7, Point p8) {
    v.push(p1);
    v.push(p2);
    v.push(p3);
    v.push(p4);
    v.push(p5);
    v.push(p6);
    v.push(p7);
    v.push(p8);
}

Octagon::~Octagon() {}

Point Octagon::GeomCenter() const {
    return ResultCentr(v);
}

double Octagon::AreaFigure() const {
    return ResultArea(v);
}