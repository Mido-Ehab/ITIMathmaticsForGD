//#include <iostream>
//#include <SFML/Graphics.hpp>
//#include <vector>
//#include <cmath>
//
//class DraggablePoint {
//    sf::CircleShape shape;
//    bool isDragging = false;
//
//public:
//    DraggablePoint(const sf::Vector2f& position) {
//        shape = sf::CircleShape(10);
//        shape.setOrigin(10, 10);
//        shape.setPosition(position);
//    }
//
//    void beginDrag(const sf::Vector2i& mousePos) {
//        isDragging = shape.getGlobalBounds().contains((sf::Vector2f)mousePos);
//    }
//
//    void drag(const sf::Vector2i& mousePos) {
//        if (isDragging) {
//            shape.setPosition((sf::Vector2f)mousePos);
//        }
//    }
//
//    void endDrag() {
//        isDragging = false;
//    }
//
//    void draw(sf::RenderWindow& window) {
//        window.draw(shape);
//    }
//
//    sf::Vector2f getPosition() {
//        return shape.getPosition();
//    }
//
//    void setPosition(const sf::Vector2f& position) {
//        shape.setPosition(position);
//    }
//};
//
//int main() {
//    
//    sf::RenderWindow window(sf::VideoMode(800, 600), "Mirror");
//    DraggablePoint point0(sf::Vector2f(400, 500));
//    DraggablePoint point1(sf::Vector2f(400, 100));
//
//    // Create mirrored points
//    DraggablePoint point2(sf::Vector2f(200, 300));
//    DraggablePoint point3(sf::Vector2f(point2.getPosition().x+400, 300));
//
//    sf::VertexArray controlLines(sf::LineStrip, 2);
//   
//
//    while (window.isOpen()) {
//        sf::Event event;
//        while (window.pollEvent(event)) {
//            if (event.type == sf::Event::Closed)
//                window.close();
//
//            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
//                window.close();
//            }
//
//            if (event.type == sf::Event::MouseButtonPressed) {
//                point0.beginDrag(sf::Mouse::getPosition(window));
//                point1.beginDrag(sf::Mouse::getPosition(window));
//                point2.beginDrag(sf::Mouse::getPosition(window));
//                point3.beginDrag(sf::Mouse::getPosition(window));
//            }
//
//            if (event.type == sf::Event::MouseButtonReleased) {
//                point0.endDrag();
//                point1.endDrag();
//                point2.endDrag();
//                point3.endDrag();
//            }
//        }
//
//        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
//            point0.drag(sf::Mouse::getPosition(window));
//            point1.drag(sf::Mouse::getPosition(window));
//            point2.drag(sf::Mouse::getPosition(window));
//            point3.drag(sf::Mouse::getPosition(window));
//        }
//
//        // Update control line
//        controlLines[0].position = point0.getPosition();
//        controlLines[1].position = point1.getPosition();
//
//      
//
//        DraggablePoint point3(sf::Vector2f(point2.getPosition().x + 400, point2.getPosition().y));
//
//        window.clear();
//
//        // Draw control points and lines
//        point0.draw(window);
//        point1.draw(window);
//        point2.draw(window);
//        point3.draw(window);
//
//        window.draw(controlLines);
//        
//
//        window.display();
//    }
//}


#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>

class DraggablePoint {
    sf::CircleShape shape;
    bool isDragging = false;

public:
    DraggablePoint(const sf::Vector2f& position) {
        shape = sf::CircleShape(10);
        shape.setOrigin(10, 10);
        shape.setPosition(position);
    }

    void beginDrag(const sf::Vector2i& mousePos) {
        isDragging = shape.getGlobalBounds().contains((sf::Vector2f)mousePos);
    }

    void drag(const sf::Vector2i& mousePos) {
        if (isDragging) {
            shape.setPosition((sf::Vector2f)mousePos);
        }
    }

    void endDrag() {
        isDragging = false;
    }

    void draw(sf::RenderWindow& window) {
        window.draw(shape);
    }

    sf::Vector2f getPosition() {
        return shape.getPosition();
    }

    void setPosition(const sf::Vector2f& position) {
        shape.setPosition(position);
    }
};

// Function to calculate the reflection of point2 over the line formed by point0 and point1
sf::Vector2f reflectAcrossLine(const sf::Vector2f& point0, const sf::Vector2f& point1, const sf::Vector2f& point2) {
    sf::Vector2f lineDir = point1 - point0;
    sf::Vector2f lineNormal(-lineDir.y, lineDir.x); // Perpendicular vector

    // Normalize lineNormal
    float length = std::sqrt(lineNormal.x * lineNormal.x + lineNormal.y * lineNormal.y);
    lineNormal /= length;

    // Calculate the distance from point2 to the line
    float distance = (point2 - point0).x * lineNormal.x + (point2 - point0).y * lineNormal.y;

    // Reflect point2 across the line
    sf::Vector2f reflectedPoint = point2 - 2.0f * distance * lineNormal;
    return reflectedPoint;
}

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Mirror Reflection");
    DraggablePoint point0(sf::Vector2f(400, 500));
    DraggablePoint point1(sf::Vector2f(400, 100));

    // Create mirrored points
    DraggablePoint point2(sf::Vector2f(200, 300));
    DraggablePoint point3(reflectAcrossLine(point0.getPosition(), point1.getPosition(), point2.getPosition()));
    
    DraggablePoint point4(sf::Vector2f(300, 400));
    DraggablePoint point5(reflectAcrossLine(point0.getPosition(), point1.getPosition(), point4.getPosition()));
    
    DraggablePoint point6(sf::Vector2f(300, 200));
    DraggablePoint point7(reflectAcrossLine(point0.getPosition(), point1.getPosition(), point6.getPosition()));

    sf::VertexArray controlLines(sf::LineStrip, 2);
    sf::VertexArray OGTrainagle(sf::Triangles, 4);
    sf::VertexArray Reflected(sf::Triangles, 4);
    


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                point0.beginDrag(sf::Mouse::getPosition(window));
                point1.beginDrag(sf::Mouse::getPosition(window));
                point2.beginDrag(sf::Mouse::getPosition(window));
                point4.beginDrag(sf::Mouse::getPosition(window));
                point6.beginDrag(sf::Mouse::getPosition(window));
            }

            if (event.type == sf::Event::MouseButtonReleased) {
                point0.endDrag();
                point1.endDrag();
                point2.endDrag();
                point4.endDrag();
                point6.endDrag();
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            point0.drag(sf::Mouse::getPosition(window));
            point1.drag(sf::Mouse::getPosition(window));
            point2.drag(sf::Mouse::getPosition(window));
            point4.drag(sf::Mouse::getPosition(window));
            point6.drag(sf::Mouse::getPosition(window));

            // Update point3 to reflect point2 across the line defined by point0 and point1
            point3.setPosition(reflectAcrossLine(point0.getPosition(), point1.getPosition(), point2.getPosition()));
            point5.setPosition(reflectAcrossLine(point0.getPosition(), point1.getPosition(), point4.getPosition()));
            point7.setPosition(reflectAcrossLine(point0.getPosition(), point1.getPosition(), point6.getPosition()));
        }

        // Update control line
        controlLines[0].position = point0.getPosition();
        controlLines[1].position = point1.getPosition();

        OGTrainagle[0].position = point2.getPosition();
        OGTrainagle[3].position = point2.getPosition();
        OGTrainagle[1].position = point4.getPosition();
        OGTrainagle[2].position = point6.getPosition();
      

        Reflected[0].position = point3.getPosition();
        Reflected[3].position = point3.getPosition();
        Reflected[1].position = point5.getPosition();
        Reflected[2].position = point7.getPosition();

        Reflected[0].color = sf::Color::Red;
        Reflected[1].color = sf::Color::Blue;
        Reflected[2].color = sf::Color::Cyan;

        window.clear();

        // Draw control points and lines
        point0.draw(window);
        point1.draw(window);
        point2.draw(window);
       /* point3.draw(window);*/
        point4.draw(window);
       /* point5.draw(window);*/
        point6.draw(window);
     /*   point7.draw(window);*/

        window.draw(controlLines);
        window.draw(OGTrainagle);
        window.draw(Reflected);

        window.display();
    }
}
