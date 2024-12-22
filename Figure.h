#ifndef FIGURE_H
#define FIGURE_H
#include <SFML/Graphics.hpp>
// ������� ����� ��� ���� �����
class Figure {public:
    // ����������� �� ���������
Figure() = default;

// ����������� ����������
virtual ~Figure() = default;

// ����������� ����� ��� ��������� ������ (��������� ������)
virtual void draw(sf::RenderWindow& window) = 0;

// ����������� ����� ��� ����������� ������
virtual void move(float x, float y) = 0;

// ����������� ����� ��� ��������, �������� �� ������ �����
virtual bool contains(float x, float y) = 0;

// ����������� ����� ��� ��������� ������ ������
virtual sf::Vector2f getCenter() const = 0;
};
#endif
