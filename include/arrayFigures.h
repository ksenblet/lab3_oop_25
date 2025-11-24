#pragma once

#include <iostream>

#include "figure.h"

class ArrayFigure {
public:
    ArrayFigure();
    ArrayFigure(const ArrayFigure&);
    ArrayFigure(ArrayFigure&&) noexcept;
    ~ArrayFigure();

    void push(Figure*);
    void pop();
    void clear();
    void erase(size_t index);

    Figure* getFigure(size_t index);
    size_t getSize() const;

private:
    size_t size;
    size_t capacity;
    Figure** data;
    void resize(size_t newSize);
};
