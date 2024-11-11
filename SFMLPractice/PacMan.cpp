//
////----------------------------------------------------------------------------------------------------------PacMan
//
//#include <SFML/Graphics.hpp>
//#include <cmath>
//
//#define PI 22/7.f
//
//class Sine {
//public:
//    static float easeIn(float t, float b, float c, float d) {
//        return -c * cos(t / d * (PI / 2)) + c + b;
//    }
//
//    static float easeOut(float t, float b, float c, float d) {
//        return c * sin(t / d * (PI / 2)) + b;
//    }
//
//    static float easeInOut(float t, float b, float c, float d) {
//        return -c / 2 * (cos(PI * t / d) - 1) + b;
//    }
//};
//
//
//void updatePacManArc(sf::ConvexShape& shape, const sf::Vector2f& center, float radius, float startAngle, float endAngle)
//{
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
//    sf::RenderWindow window(sf::VideoMode(400, 400), "Smooth Pac-Man Animation");
//
//    sf::ConvexShape pacman(30);  // Adjust points to control smoothness of arc
//    sf::Vector2f center(200, 200);
//    float radius = 150;
//    float baseAngle = 30;  // Base angle for the mouth (degrees)
//    float duration = 1.0f;  // Duration of one open or close phase (seconds)
//    float elapsedTime  ;
//    bool isOpening = true;  // Track whether Pac-Man is opening or closing his mouth
//
//    pacman.setFillColor(sf::Color::Yellow);
//    pacman.setOrigin(center);
//    pacman.setPosition(center);
//    sf::Clock clock;
//
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
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)||(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))) {
//            pacman.setRotation(270);  // Rotate up
//        }
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))) {
//            pacman.setRotation(180);  // Rotate left
//        }
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))) {
//            pacman.setRotation(0);    // Rotate right
//        }
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))) {
//            pacman.setRotation(90);   // Rotate down
//        }
//        // Update elapsed time, and reset it when it reaches `duration`
//        elapsedTime = clock.getElapsedTime().asSeconds();
//
//        if (elapsedTime >= duration) {
//            clock.restart();
//            isOpening = !isOpening;  // Toggle between opening and closing
//        }
//
//        // Use easing functions for smooth opening and closing
//        float mouthAngle;
//        if (isOpening) {
//            mouthAngle = Sine::easeOut(elapsedTime, 0, baseAngle, duration);
//        }
//        else {
//            mouthAngle = Sine::easeIn(elapsedTime, baseAngle, -baseAngle, duration);
//        }
//
//        // Update arc to open and close Pac-Man's mouth
//        updatePacManArc(pacman, center, radius, mouthAngle, 360 - mouthAngle);
//
//        window.clear();
//        window.draw(pacman);
//        window.display();
//    }
//
//    return 0;
//}
