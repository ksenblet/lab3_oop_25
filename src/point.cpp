#include "point.h"

Point::Point(int x, int y) : x(x), y(y) {}

std::istream& operator>>(std::istream& is, Point& p) {
    return is >> p.x >> p.y;
}

std::ostream& operator<<(std::ostream& os, const Point& p) {
    return os << "(" << p.x << ", " << p.y << ")";
}

bool operator==(const Point& left, const Point& right) {
    return left.x == right.x && left.y == right.y;
}

bool operator!=(const Point& left, const Point& right) {
    return !(left == right);
}