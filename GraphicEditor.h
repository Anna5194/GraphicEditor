#ifndef GRAPHICEDITOR_H
#define GRAPHICEDITOR_H
#include "ShapeList.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <sstream>// �����, ����������� ����������� ��������
class GraphicEditor {private:sf::RenderWindow window_;
ShapeList shapes_;
int selectedShape_ = -1; // ������ ��������� ������ (-1 - ������ �� �������)

// ����� ������ ��� ����������
     Figure* createShapeFromInput(); public:
         // �����������
         GraphicEditor();
         // ������ ���������
         void run();

         // ��������� ������� �����
         void handleInput(sf::Event& event);
};
#endif
