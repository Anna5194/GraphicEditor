#ifndef SHAPELIST_H
#define SHAPELIST_H
#include <vector>
#include "Figure.h"
// �����, �������� ������ �����
class ShapeList {private:
std::vector<Figure*> shapes_;
public:
    // ���������� ������ � ������
    void addShape(Figure* shape);

    // ��������� ���� �����
    void drawAll(sf::RenderWindow& window);

    ~ShapeList();

    // ����������� ��������� ������
    void moveSelected(int index, float x, float y);

    // ��������� ������ �� �������
    Figure* getShape(int index);

    // ��������, �������� �� �����-���� ������ �����
    int contains(float x, float y);

    // ���������� ����� � ������
    int size();
};
#endif
