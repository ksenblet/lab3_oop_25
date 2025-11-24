#pragma once

#include <iostream>

#include "point.h"

class ArrayPoints {
public:
    ArrayPoints();
    ArrayPoints(size_t);
    ArrayPoints(const ArrayPoints&);
    ArrayPoints(ArrayPoints&&) noexcept;
    ~ArrayPoints();

    void push(Point);
    void pop();
    void clear();
    void set(size_t, Point);
    void resize(size_t newSize);

    Point getP(size_t) const;
    size_t getSize() const;

private:
    size_t size;
    size_t capacity;
    Point* data;
};