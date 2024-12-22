#ifndef LINE_H
#define LINE_H

#include "Figure.h"

class Line : public Figure {
private:
    sf::Vector2f start_point_;
    sf::Vector2f end_point_;
    sf::Color color_;
    float thickness_;

public:
    Line(float x1, float y1, float x2, float y2, const sf::Color& color = sf::Color::Black, float thickness = 1.0f);

    void draw(sf::RenderWindow& window) override;
    void move(float x, float y) override;
    bool contains(float x, float y) override;
    sf::Vector2f getCenter() const override;
};

#endif