#include "shape.hpp"


inline void Shape::SetShapeColor(const sf::Color &a_color) {
    m_shape->setFillColor(a_color);
}

inline sf::Color Shape::Color() {
    return m_shape->getFillColor();
}

inline void Shape::SetShapePosition(float a_xPos, float a_yPos) {
    m_shape->setPosition(a_xPos, a_yPos);
}

inline float Shape::xPos() {
    return m_shape->getPosition().x;
}


inline float Shape::yPos() {
    return m_shape->getPosition().y;
}

inline void Shape::Draw(sf::RenderWindow& a_window) {
    a_window.draw(*m_shape);
}