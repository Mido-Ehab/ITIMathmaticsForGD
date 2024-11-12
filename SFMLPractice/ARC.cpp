//#include <SFML/Graphics.hpp>
//#include<math.h>
//#include"Elastic.h"
//#define PI 22/7.f
//
/////////----------------------------------------------------------------------------------------------------------Task4 Arc
//
//
//void updateArc(sf::ConvexShape& shape, const sf::Vector2f& center, float radius, float startAngle, float endAngle)
//{
//    int pointsCount = shape.getPointCount();
//
//    // Convert angles to radians
//    float startRad = startAngle * PI / 180.f;
//    float endRad = endAngle * PI / 180.f;
//
//    // First point is the center of the arc (for the "mouth" effect)
//    shape.setPoint(0, center);  // size & v2f
//
//    // Calculate points along the arc
//    float deltaAngle = (endRad - startRad) / (pointsCount - 2);     // -2 for center points
//    float angle = startRad;
//
//    for (size_t i = 1; i < pointsCount - 1; i++)  // Start at 1, leave last point for center
//    {
//        sf::Vector2f point;
//        point.x = center.x + radius * cos(angle);
//        point.y = center.y + radius * sin(angle);
//
//        shape.setPoint(i, point);
//        angle += deltaAngle;
//    }
//
//    // Last point returns to the center for a closed "mouth"
//    shape.setPoint(pointsCount - 1, center);
//}
//
//int main()
//{
//    sf::RenderWindow window(sf::VideoMode(400, 400), "Pac-Man Arc");
//    sf::ConvexShape pacman(30);  // Adjust points to control smoothness of arc
//
//    // Configure the Pac-Man arc
//    updateArc(pacman, sf::Vector2f(200, 200), 150, 300, 360);  // 30 to 330 degrees for a "mouth" shape
//
//    pacman.setFillColor(sf::Color::Yellow);
//
//    while (window.isOpen())
//    {
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }
//
//        window.clear();
//        window.draw(pacman);
//        window.display();
//    }
//
//    return 0;
//}
