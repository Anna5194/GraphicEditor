#include "IsoscelesTriangle.h"
#include <SFML/Graphics.hpp>
#include <cmath>
void IsoscelesTriangle::draw(sf::RenderWindow& window) {
    sf::ConvexShape triangle;
    triangle.setPointCount(3);
    triangle.setPoint(0, sf::Vector2f(position_.x, position_.y));
    triangle.setPoint(1, sf::Vector2f(position_.x + base_, position_.y));
    triangle.setPoint(2, sf::Vector2f(position_.x + base_ / 2, position_.y - height_));
    triangle.setFillColor(color_);
    window.draw(triangle);
}

void IsoscelesTriangle::move(float x, float y) {
    position_.x = x;
    position_.y = y;
}
bool IsoscelesTriangle::contains(float x, float y) {
    // Define the vertices of the triangle
    sf::Vector2f p1(position_.x, position_.y);
    sf::Vector2f p2(position_.x + base_, position_.y);
    sf::Vector2f p3(position_.x + base_ / 2, position_.y - height_);

    // Check if the point is inside the triangle using barycentric coordinates
    float area = 0.5f * (-p2.y * p3.x + p1.y * (-p2.x + p3.x) + p1.x * (p2.y - p3.y) + p2.x * p3.y);
    float s = 1.0f / (2 * area) * (p1.y * p3.x - p1.x * p3.y + (p3.y - p1.y) * x + (p1.x - p3.x) * y);
    float t = 1.0f / (2 * area) * (p1.x * p2.y - p1.y * p2.x + (p1.y - p2.y) * x + (p2.x - p1.x) * y);

    return s > 0 && t > 0 && 1 - s - t > 0;
}
sf::Vector2f IsoscelesTriangle::getCenter() const {
    return sf::Vector2f(position_.x + base_ / 2.0f, position_.y - height_ / 3.0f);
}
