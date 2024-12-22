#ifndef GRAPHICEDITOR_H
#define GRAPHICEDITOR_H
#include "ShapeList.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <sstream>// Класс, реализующий графический редактор
class GraphicEditor {private:sf::RenderWindow window_;
ShapeList shapes_;
int selectedShape_ = -1; // Индекс выбранной фигуры (-1 - ничего не выбрано)

// Выбор фигуры для добавления
     Figure* createShapeFromInput(); public:
         // Конструктор
         GraphicEditor();
         // Запуск редактора
         void run();

         // Обработка событий ввода
         void handleInput(sf::Event& event);
};
#endif
