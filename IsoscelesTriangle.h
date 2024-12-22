#ifndef ISOSCELESTRIANGLE_H
#define ISOSCELESTRIANGLE_H
#include "Figure.h"
// �����, �������������� �������������� �����������
class IsoscelesTriangle : public Figure {private:sf::Vector2f position_;
float base_;
float height_;
    sf::Color color_; public:
        // ����������� � �����������
        IsoscelesTriangle(float x, float y, float base, float height, const sf::Color& color = sf::Color::Black) :
            position_({ x, y }), base_(base), height_(height), color_(color) {}

        // ����� ��� ��������� ��������������� ������������
        void draw(sf::RenderWindow& window) override;

        // ����� ��� ����������� ��������������� ������������
        void move(float x, float y) override;

        bool contains(float x, float y) override;
        sf::Vector2f getCenter() const override;
};
#endif
