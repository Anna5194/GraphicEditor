#include "Line.h"
#include <SFML/Graphics.hpp>
#include <cmath>

Line::Line(float x1, float y1, float x2, float y2, const sf::Color& color, float thickness)
    : start_point_({ x1, y1 }), end_point_({ x2, y2 }), color_(color), thickness_(thickness) {}

void Line::draw(sf::RenderWindow& window) {
    sf::Vertex line[] = {
        sf::Vertex(start_point_, color_),
        sf::Vertex(end_point_, color_)
    };
    window.draw(line, 2, sf::Lines);
}

void Line::move(float x, float y) {
    float dx = x - start_point_.x;
    float dy = y - start_point_.y;
    start_point_.x += dx;
    start_point_.y += dy;
    end_point_.x += dx;
    end_point_.y += dy;
}

bool Line::contains(float x, float y) {
    float dx = end_point_.x - start_point_.x;
    float dy = end_point_.y - start_point_.y;
    float length = std::sqrt(dx * dx + dy * dy);

    // ѕровер€ем, что точка находитс€ в пределах линии
    float tolerance = thickness_ / 2.0f;
    float distance = std::abs((y - start_point_.y) * dx - (x - start_point_.x) * dy) / length;
    return distance <= tolerance;
}

sf::Vector2f Line::getCenter() const {
    return sf::Vector2f((start_point_.x + end_point_.x) / 2, (start_point_.y + end_point_.y) / 2);
}