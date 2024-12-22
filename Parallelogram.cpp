#include "Parallelogram.h"
#include <SFML/Graphics.hpp>
#include <cmath>
void Parallelogram::draw(sf::RenderWindow& window) {
    sf::ConvexShape parallelogram;
    parallelogram.setPointCount(4);
    float angleRad = angle_ * 3.14159265f / 180.0f; // Convert angle to radians
    float x1 = position_.x;
    float y1 = position_.y;
    float x2 = position_.x + size_.x;
    float y2 = position_.y;
    float x3 = position_.x + size_.x + size_.y * std::cos(angleRad);
    float y3 = position_.y + size_.y * std::sin(angleRad);
    float x4 = position_.x + size_.y * std::cos(angleRad);
    float y4 = position_.y + size_.y * std::sin(angleRad);


    parallelogram.setPoint(0, sf::Vector2f(x1, y1));
    parallelogram.setPoint(1, sf::Vector2f(x2, y2));
    parallelogram.setPoint(2, sf::Vector2f(x3, y3));
    parallelogram.setPoint(3, sf::Vector2f(x4, y4));
    parallelogram.setFillColor(color_);
    window.draw(parallelogram);
}
void Parallelogram::move(float x, float y) {
    position_.x = x;
    position_.y = y;
}
bool Parallelogram::contains(float x, float y) {
    sf::ConvexShape parallelogram;
    parallelogram.setPointCount(4);
    float angleRad = angle_ * 3.14159265f / 180.0f; // Convert angle to radians
    float x1 = position_.x;
    float y1 = position_.y;
    float x2 = position_.x + size_.x;
    float y2 = position_.y;
    float x3 = position_.x + size_.x + size_.y * std::cos(angleRad);
    float y3 = position_.y + size_.y * std::sin(angleRad);
    float x4 = position_.x + size_.y * std::cos(angleRad);
    float y4 = position_.y + size_.y * std::sin(angleRad);

    parallelogram.setPoint(0, sf::Vector2f(x1, y1));
    parallelogram.setPoint(1, sf::Vector2f(x2, y2));
    parallelogram.setPoint(2, sf::Vector2f(x3, y3));
    parallelogram.setPoint(3, sf::Vector2f(x4, y4));

    // Create a bounding box for the parallelogram
    sf::FloatRect bounds = parallelogram.getGlobalBounds();

    // Check if the point is inside the bounding box first
    if (!bounds.contains(x, y)) {
        return false; // Point is outside the bounding box, so it's not in the parallelogram
    }
    // Use the ray casting algorithm to determine if a point is inside the polygon
    int n = 4;
    int crossings = 0;
    sf::Vector2f point({ x, y });
    for (int i = 0; i < n; i++) {
        sf::Vector2f p1 = parallelogram.getPoint(i);
        sf::Vector2f p2 = parallelogram.getPoint((i + 1) % n);

        if ((p1.y > point.y) != (p2.y > point.y)) {
            float crossX = (point.y - p1.y) * (p2.x - p1.x) / (p2.y - p1.y) + p1.x;
            if (point.x < crossX) {
                crossings++;
            }
        }
    }
    return crossings % 2 != 0;
}sf::Vector2f Parallelogram::getCenter() const {
    float angleRad = angle_ * 3.14159265f / 180.0f; // Convert angle to radians

    // Calculate center based on the parallelogram's vertices
    sf::Vector2f center;
    center.x = position_.x + size_.x / 2.0f + size_.y * std::cos(angleRad) / 2.0f;
    center.y = position_.y + size_.y * std::sin(angleRad) / 2.0f;

    return center;
}
