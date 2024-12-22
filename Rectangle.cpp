#include "Rectangle.h"
#include <SFML/Graphics.hpp>
void Rectangle::draw(sf::RenderWindow& window) {
    sf::RectangleShape rectangle(size_);
    rectangle.setPosition(position_);
    rectangle.setFillColor(color_);
    window.draw(rectangle);
}
void Rectangle::move(float x, float y) {
    position_.x = x;
    position_.y = y;
}
bool Rectangle::contains(float x, float y) {
    // Check if the given point is inside the rectangle
    return x >= position_.x && x <= position_.x + size_.x &&
        y >= position_.y && y <= position_.y + size_.y;
}sf::Vector2f Rectangle::getCenter() const {
    return position_ + size_ / 2.0f;
}
