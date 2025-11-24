#include <cmath>

#include "figure.h"

Figure::Figure() {}
Figure::~Figure() {}

Point Figure::GeomCenter() const {
    return ResultCentr(v);
}

double Figure::AreaFigure() const {
    return ResultArea(v);
}

Figure::operator double() const {
    return AreaFigure();
}

double Figure::ResultArea(const ArrayPoints& t) const {
    double res = 0.0;
    size_t n = t.getSize();
    for (size_t i = 0; i + 1 < n; ++i) {
        res += t.getP(i).x * t.getP(i + 1).y;
        res -= t.getP(i + 1).x * t.getP(i).y;
    }
    res += t.getP(n - 1).x * t.getP(0).y;
    res -= t.getP(0).x * t.getP(n - 1).y;
    return std::abs(res / 2.0);
}

Point Figure::ResultCentr(const ArrayPoints& t) const {
    int x = 0, y = 0;
    size_t n = t.getSize();
    for (size_t i = 0; i < n; ++i) {
        x += t.getP(i).x;
        y += t.getP(i).y;
    }
    return Point(x / n, y / n);
}

void Figure::ReadPoints(std::istream& is) {
    for (size_t i = 0; i < v.getSize(); ++i) {
        Point p;
        is >> p.x >> p.y;
        v.set(i, p);
    }
}

void Figure::PrintPoints(std::ostream& os) const {
    for (size_t i = 0; i < v.getSize(); ++i) {
        Point p = v.getP(i);
        os << "( " << p.x << ", " << p.y << ") ";
    }
}

std::istream& operator>>(std::istream& is, Figure& f) {
    f.ReadPoints(is);
    return is;
}

std::ostream& operator<<(std::ostream& os, const Figure& f) {
    f.PrintPoints(os);
    return os;
}

bool operator==(const Figure& a, const Figure& b) {
    if (a.v.getSize() != b.v.getSize()) return false;
    for (size_t i = 0; i < a.v.getSize(); ++i) {
        if (a.v.getP(i) != b.v.getP(i)) return false;
    }
    return true;
}

bool operator!=(const Figure& a, const Figure& b) {
    return !(a == b);
}