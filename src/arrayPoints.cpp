#include "arrayPoints.h"
#include "point.h"

ArrayPoints::ArrayPoints() : size(0), capacity(2), data(new Point[capacity]) {}

ArrayPoints::ArrayPoints(size_t n) : size(n), capacity(n * 2), data(new Point[capacity]) {}

ArrayPoints::ArrayPoints(const ArrayPoints& other)
    : size(other.size), capacity(other.capacity), data(new Point[capacity]) {
    for (size_t i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
}

ArrayPoints::ArrayPoints(ArrayPoints&& other) noexcept
    : size(other.size), capacity(other.capacity), data(other.data) {
    other.data = nullptr;
    other.size = 0;
    other.capacity = 0;
}

ArrayPoints::~ArrayPoints() {
    delete[] data;
}

void ArrayPoints::resize(size_t newCapacity) {
    Point* newData = new Point[newCapacity];
    for (size_t i = 0; i < size; ++i) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    capacity = newCapacity;
}

void ArrayPoints::push(Point p) {
    if (size >= capacity) {
        resize(capacity * 2);
    }
    data[size++] = p;
}

void ArrayPoints::pop() {
    if (size > 0) {
        --size;
    }
}

void ArrayPoints::clear() {
    size = 0;
    capacity = 2;
    delete[] data;
    data = new Point[capacity];
}

void ArrayPoints::set(size_t i, Point p) {
    data[i] = p;
}

Point ArrayPoints::getP(size_t index) const {
    return data[index];
}

size_t ArrayPoints::getSize() const {
    return size;
}