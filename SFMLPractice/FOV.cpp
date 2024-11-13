//#include <iostream>
//#include <SFML/Graphics.hpp>
//#include <vector>
//#include <cmath>
//
//#define PI 3.14159265f  // Use more accurate value of PI
//
//struct Circle {
//    sf::CircleShape circle;
//
//    Circle(float radius, sf::Vector2f origin, sf::Vector2f cPos, sf::Color color) {
//        circle.setRadius(radius);
//        circle.setFillColor(color);
//        circle.setOrigin(origin);
//        circle.setPosition(cPos);
//    }
//};
//
//// Function to calculate the angle between two points in degrees
//float calculateAngle(const sf::Vector2f& point1, const sf::Vector2f& point2) {
//    float dx = point2.x - point1.x;
//    float dy = point2.y - point1.y;
//    return atan2(dy, dx) * 180 / PI; // Convert to degrees
//}
//
//void updateArc(sf::ConvexShape& shape, const sf::Vector2f& center, float radius, float startAngle, float endAngle) {
//    int pointsCount = shape.getPointCount();
//
//    // Convert angles to radians
//    float startRad = startAngle * PI / 180.f;
//    float endRad = endAngle * PI / 180.f;
//
//    // First point is the center of the arc (for the "mouth" effect)
//    shape.setPoint(0, center);
//
//    // Calculate points along the arc
//    float deltaAngle = (endRad - startRad) / (pointsCount - 2); // -2 for center points
//    float angle = startRad;
//
//    for (size_t i = 1; i < pointsCount - 1; i++) {
//        sf::Vector2f point;
//        point.x = center.x + radius * cos(angle);
//        point.y = center.y + radius * sin(angle);
//        shape.setPoint(i, point);
//        angle += deltaAngle;
//    }
//
//    // Last point returns to the center for a closed "mouth"
//    shape.setPoint(pointsCount - 1, center);
//}
//
//int main() {
//    sf::RenderWindow window(sf::VideoMode(800, 600), "FOV");
//
//    Circle enemy(25.f, sf::Vector2f(25, 25), sf::Vector2f(100, 400), sf::Color::Black);
//    Circle player(30.f, sf::Vector2f(30, 30), sf::Vector2f(300, 300), sf::Color::Cyan);
//
//    float fovAngle = 60.f; // Field of View angle
//    float fovRadius = 200.f; // FOV distance
//
//    sf::ConvexShape Hover(30);
//    Hover.setFillColor(sf::Color(0, 200, 0, 50));
//    Hover.setPointCount(30);
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
//            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
//                player.circle.move(0, -10);
//            }
//
//            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
//                player.circle.move(-10, 0);
//            }
//
//            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
//                player.circle.move(10, 0);
//            }
//
//            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
//                player.circle.move(0, 10);
//            }
//        }
//
//        // Calculate the angle between player and enemy
//        float playerToEnemyAngle = calculateAngle(player.circle.getPosition(), enemy.circle.getPosition());
//
//        // Calculate the player's facing angle based on mouse position
//        sf::Vector2f mousePos = (sf::Vector2f)sf::Mouse::getPosition(window);
//        float playerFacingAngle = calculateAngle(player.circle.getPosition(), mousePos);
//
//        // Normalize angle difference to the range [-180, 180]
//        float angleDifference = playerToEnemyAngle - playerFacingAngle; 
//        if (angleDifference > 180.f) angleDifference -= 360.f;
//        if (angleDifference < -180.f) angleDifference += 360.f;
//
//        // Calculate distance between player and enemy
//        float distance = sqrt(pow(player.circle.getPosition().x - enemy.circle.getPosition().x, 2) +
//                              pow(player.circle.getPosition().y - enemy.circle.getPosition().y, 2));
//
//        // Check both distance and angle conditions
//        if (distance <= fovRadius+25 && std::abs(angleDifference) <= fovAngle / 2) {
//            Hover.setFillColor(sf::Color(250, 0, 0, 50)); // Enemy within FOV
//        } else {
//            Hover.setFillColor(sf::Color(0, 200, 0, 50)); // Enemy outside FOV
//        }
//
//        // Update the arc shape to show FOV
//        updateArc(Hover, player.circle.getPosition(), fovRadius, playerFacingAngle - fovAngle / 2, playerFacingAngle + fovAngle / 2);
//
//        // Render everything
//        window.clear(sf::Color(70, 70, 70));
//        window.draw(enemy.circle);
//        window.draw(Hover);
//        window.draw(player.circle);
//        window.display();
//    }
//}
