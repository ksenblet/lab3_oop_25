#pragma once

#include <iostream>

struct Point {
    int x{0}, y{0};
    Point() = default;
    Point(int x, int y);
    friend std::istream& operator>>(std::istream& is, Point& p);
    friend std::ostream& operator<<(std::ostream& os, const Point& p); // конст - не меняется!!
    friend bool operator==(const Point& left, const Point& right);
    friend bool operator!=(const Point& left, const Point& right);
};