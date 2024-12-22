#include "Ellipse.h"
#include <SFML/Graphics.hpp>
void Ellipse::draw(sf::RenderWindow& window) {
    sf::CircleShape ellipse(radius_.x);
    ellipse.setRadius(radius_.x);
    ellipse.setScale(radius_.x / radius_.x, radius_.y / radius_.x);
    ellipse.setFillColor(color_);
    ellipse.setOrigin(radius_.x, radius_.y);
    ellipse.setPosition(center_);
    window.draw(ellipse);
}
void Ellipse::move(float x, float y) {
    center_.x = x;
    center_.y = y;
}
bool Ellipse::contains(float x, float y) {
    // Normalize the position of the point relative to the center of the ellipse
    float dx = x - center_.x;
    float dy = y - center_.y;

    // Check if the point is within the ellipse using the ellipse equation
    return (dx * dx) / (radius_.x * radius_.x) + (dy * dy) / (radius_.y * radius_.y) <= 1.0f;

}sf::Vector2f Ellipse::getCenter() const {
    return center_;
}
