#include <iostream>

#include "arrayFigures.h"
#include "figure.h"
#include "octagon.h"
#include "square.h"
#include "triangle.h"

int main() {
    ArrayFigure figures;
    std::cout << "Enter number of figures: ";
    int count;
    std::cin >> count;
    
    for (int i = 0; i < count; ++i) {
        std::cout << "\nFigure " << i << " - Choose type (1=Triangle, 2=Square, 3=Octagon): ";
        int type;
        std::cin >> type;
        Figure* figure = nullptr;
        
        if (type == 1) {
            std::cout << "Enter 3 points for triangle (x1 y1 x2 y2 x3 y3): ";
            figure = new Triangle();
        } else if (type == 2) {
            std::cout << "Enter 4 points for square (x1 y1 x2 y2 x3 y3 x4 y4): ";
            figure = new Square();
        } else if (type == 3) {
            std::cout << "Enter 8 points for octagon (x1 y1 x2 y2 ... x8 y8): ";
            figure = new Octagon();
        }
        if (figure) {
            std::cin >> *figure; 
            figures.push(figure);
        }
    }

    double totalArea = 0.0;
    for (size_t i = 0; i < figures.getSize(); ++i) {
        totalArea += figures.getFigure(i)->AreaFigure();
    }
    std::cout << "Total area: " << totalArea << std::endl;
    
    std::cout << "Enter index to remove: ";
    size_t index;
    std::cin >> index;
    if (index < figures.getSize()) {
        figures.erase(index);
    }
    
    totalArea = 0.0;
    for (size_t i = 0; i < figures.getSize(); ++i) {
        totalArea += figures.getFigure(i)->AreaFigure();
    }
    std::cout << "Total area after remove: " << totalArea << std::endl;
    
    return 0;
}
