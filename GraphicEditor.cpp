#include "GraphicEditor.h"
#include "Line.h"
#include "Ellipse.h"
#include "Rectangle.h"
#include "Parallelogram.h"
#include "IsoscelesTriangle.h"
#include <iostream>
#include <sstream>
#include <limits>

GraphicEditor::GraphicEditor() : window_(sf::VideoMode(800, 600), "Graphic Editor") {
    // Статическая инициализация
    shapes_.addShape(new IsoscelesTriangle(100, 200, 100, 50, sf::Color::Red));
    shapes_.addShape(new Ellipse(300, 150, 60, 40, sf::Color::Blue));
    shapes_.addShape(new Rectangle(50, 300, 80, 60, sf::Color::Green));
    shapes_.addShape(new Parallelogram(300, 400, 100, 60, 30.0f, sf::Color::Yellow));
    shapes_.addShape(new Line(50, 50, 250, 50, sf::Color::Magenta, 2.0f));
}
Figure* GraphicEditor::createShapeFromInput() {
    int shapeType;
    float x, y, param1, param2, param3;

    // Ввод типа фигуры
    std::cout << "Enter shape type (1 - IsoscelesTriangle, 2 - Ellipse, 3 - Rectangle, 4 - Parallelogram, 5 - Line): ";
    std::cin >> shapeType;

    // Ввод координат и размеров
    std::cout << "Enter x: ";
    std::cin >> x;
    std::cout << "Enter y: ";
    std::cin >> y;

    switch (shapeType) {
    case 1: // IsoscelesTriangle
        std::cout << "Enter base: ";
        std::cin >> param1;
        std::cout << "Enter height: ";
        std::cin >> param2;
        return new IsoscelesTriangle(x, y, param1, param2, sf::Color::Red);
        break;
    case 2: // Ellipse
        std::cout << "Enter radiusX: ";
        std::cin >> param1;
        std::cout << "Enter radiusY: ";
        std::cin >> param2;
        return new Ellipse(x, y, param1, param2, sf::Color::Blue);
        break;
    case 3: // Rectangle
        std::cout << "Enter width: ";
        std::cin >> param1;
        std::cout << "Enter height: ";
        std::cin >> param2;
        return new Rectangle(x, y, param1, param2, sf::Color::Green);
        break;
    case 4: // Parallelogram
        std::cout << "Enter width: ";
        std::cin >> param1;
        std::cout << "Enter height: ";
        std::cin >> param2;
        std::cout << "Enter angle: ";
        std::cin >> param3;
        return new Parallelogram(x, y, param1, param2, param3, sf::Color::Yellow);
        break;
    case 5: // Line
        std::cout << "Enter x2: ";
        std::cin >> param1;
        std::cout << "Enter y2: ";
        std::cin >> param2;
        return new Line(x, y, param1, param2, sf::Color::Magenta, 2.0f);
        break;

    default:
        std::cout << "Invalid shape type." << std::endl;
        return nullptr;
        break;
    }
    return nullptr;
}

void GraphicEditor::run() {
    while (window_.isOpen()) {
        sf::Event event;
        while (window_.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window_.close();

            handleInput(event);
        }

        window_.clear(sf::Color::White);
        shapes_.drawAll(window_);
        window_.display();
    }
}
void GraphicEditor::handleInput(sf::Event& event) {
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        float mouseX = static_cast<float>(event.mouseButton.x);
        float mouseY = static_cast<float>(event.mouseButton.y);
        selectedShape_ = shapes_.contains(mouseX, mouseY);
    }
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::A) {
            Figure* newShape = createShapeFromInput();
            if (newShape)
                shapes_.addShape(newShape);
        }
        else if (event.key.code == sf::Keyboard::M && selectedShape_ != -1)
        {
            float newX, newY;
            std::cout << "Enter new x: ";
            std::cin >> newX;
            std::cout << "Enter new y: ";
            std::cin >> newY;
            shapes_.moveSelected(selectedShape_, newX, newY);
        }
        else if (event.key.code == sf::Keyboard::Escape)
        {
            selectedShape_ = -1;
        }
    }
}
