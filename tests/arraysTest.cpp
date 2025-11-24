#include <gtest/gtest.h>

#include "arrayPoints.h"
#include "arrayFigures.h"
#include "point.h"
#include "triangle.h"
#include "square.h"
#include "octagon.h"

TEST(ArrayPointsTest, AddAndGetPoints) {
    ArrayPoints ap;
    Point p1(1, 2);
    Point p2(3, 4);
    ap.push(p1);
    ap.push(p2);
    EXPECT_EQ(ap.getSize(), 2);
    EXPECT_TRUE(ap.getP(0) == p1);
    EXPECT_TRUE(ap.getP(1) == p2);
}

TEST(ArrayPointsTest, PopAndClear) {
    ArrayPoints ap;
    ap.push(Point(1, 1));
    ap.push(Point(2, 2));
    EXPECT_EQ(ap.getSize(), 2);
    
    ap.pop();
    EXPECT_EQ(ap.getSize(), 1);
    
    ap.clear();
    EXPECT_EQ(ap.getSize(), 0);
}

TEST(ArrayFigureTest, AddFigures) {
    ArrayFigure af;
    Triangle* triangle = new Triangle(Point(0,0), Point(3,0), Point(0,4));
    Square* square = new Square();
    
    af.push(triangle);
    af.push(square);
    
    EXPECT_EQ(af.getSize(), 2);
}

TEST(ArrayFigureTest, TotalAreaCalculation) {
    ArrayFigure af;
    af.push(new Triangle(Point(0,0), Point(3,0), Point(0,4)));    // Area = 6
    af.push(new Square(Point(0,0), Point(2,0), Point(2,2), Point(0,2))); // Area = 4
    
    double totalArea = 0.0;
    for (size_t i = 0; i < af.getSize(); ++i) {
        totalArea += af.getFigure(i)->AreaFigure();
    }
    
    EXPECT_NEAR(totalArea, 10.0, 1e-10);
}

TEST(ArrayFigureTest, EraseFigure) {
    ArrayFigure af;
    af.push(new Triangle());
    af.push(new Square());
    af.push(new Octagon());
    
    EXPECT_EQ(af.getSize(), 3);
    af.erase(1); // - квадр
    EXPECT_EQ(af.getSize(), 2);
}