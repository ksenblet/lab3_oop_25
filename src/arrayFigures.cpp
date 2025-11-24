#include "arrayFigures.h"
#include "figure.h"

ArrayFigure::ArrayFigure() : size(0), capacity(2), data(new Figure*[capacity]) {}

ArrayFigure::ArrayFigure(const ArrayFigure& other)
    : size(other.size), capacity(other.capacity), data(new Figure*[capacity]) {
    for (size_t i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
}

ArrayFigure::ArrayFigure(ArrayFigure&& other) noexcept
    : size(other.size), capacity(other.capacity), data(other.data) {
    other.data = nullptr;
    other.size = 0;
    other.capacity = 0;
}

ArrayFigure::~ArrayFigure() {
    clear();
    delete[] data;
}

void ArrayFigure::resize(size_t newCapacity) {
    Figure** newData = new Figure*[newCapacity];
    for (size_t i = 0; i < size; ++i) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    capacity = newCapacity;
}

void ArrayFigure::push(Figure* figure) {
    if (size >= capacity) {
        resize(capacity * 2);
    }
    data[size++] = figure;
}

void ArrayFigure::pop() {
    if (size > 0) {
        delete data[--size];
    }
}

void ArrayFigure::clear() {
    for (size_t i = 0; i < size; ++i) {
        delete data[i];
    }
    size = 0;
}

void ArrayFigure::erase(size_t index) {
    delete data[index];
    for (size_t i = index; i < size - 1; ++i) {
        data[i] = data[i + 1];
    }
    --size;
}

Figure* ArrayFigure::getFigure(size_t index) {
    return data[index];
}

size_t ArrayFigure::getSize() const {
    return size;
}