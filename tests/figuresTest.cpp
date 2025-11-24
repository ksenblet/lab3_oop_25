#include <gtest/gtest.h>

#include "point.h"
#include "triangle.h"
#include "square.h"
#include "octagon.h"

TEST(TriangleTest, AreaCalculation) {
    Point p1(0, 0);
    Point p2(3, 0);
    Point p3(0, 4);
    Triangle triangle(p1, p2, p3);
    EXPECT_NEAR(triangle.AreaFigure(), 6.0, 1e-10);
}

TEST(TriangleTest, GeometricCenter) {
    Point p1(0, 0);
    Point p2(6, 0);
    Point p3(0, 6);
    Triangle triangle(p1, p2, p3);
    Point center = triangle.GeomCenter();
    EXPECT_EQ(center.x, 2);
    EXPECT_EQ(center.y, 2);
}

TEST(SquareTest, AreaCalculation) {
    Point p1(0, 0);
    Point p2(2, 0);
    Point p3(2, 2);
    Point p4(0, 2);
    Square square(p1, p2, p3, p4);
    EXPECT_NEAR(square.AreaFigure(), 4.0, 1e-10);
}

TEST(SquareTest, GeometricCenter) {
    Point p1(0, 0);
    Point p2(4, 0);
    Point p3(4, 4);
    Point p4(0, 4);
    Square square(p1, p2, p3, p4);
    Point center = square.GeomCenter();
    EXPECT_EQ(center.x, 2);
    EXPECT_EQ(center.y, 2);
}

TEST(OctagonTest, AreaCalculation) {
    Octagon octagon;
    EXPECT_GE(octagon.AreaFigure(), 0);
}

TEST(FigureTest, DoubleConversion) {
    Triangle triangle(Point(0,0), Point(3,0), Point(0,4));
    double area = static_cast<double>(triangle);
    EXPECT_NEAR(area, 6.0, 1e-10);
}

TEST(FigureTest, ComparisonOperators) {
    Triangle triangle1(Point(0,0), Point(3,0), Point(0,4));
    Triangle triangle2(Point(0,0), Point(3,0), Point(0,4));
    Triangle triangle3(Point(0,0), Point(5,0), Point(0,5));
    
    EXPECT_TRUE(triangle1 == triangle2);
    EXPECT_FALSE(triangle1 == triangle3);
    EXPECT_TRUE(triangle1 != triangle3);
}