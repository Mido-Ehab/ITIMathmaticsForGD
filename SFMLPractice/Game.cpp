#include <SFML/Graphics.hpp>
#include<math.h>
#include"Elastic.h"
#define PI 22/7.f

//----------------------------------------------------------------------------------------------------task1 Easing Elastic
//int main()
//{
//    sf::RenderWindow window(sf::VideoMode(800, 600), "Elastic");
//    sf::CircleShape shape(20);
//    shape.setOrigin(20, 20);
//
//
//    sf::Vector2f position(20, 20);
//    sf::Vector2f targetPosition(position);
//    sf::Vector2f startPosition(position);
//
//
//    sf::Color color(sf::Color::Red);
//    sf::Color targetColor(sf::Color::Red);
//    sf::Color startColor(sf::Color::Blue);
//
//
//    sf::Clock clock;
//    float time;
//
//    float d = 2;
//
//    while (window.isOpen())
//    {
//
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == sf::Event::Closed)
//                window.close();
//
//            if (event.type == sf::Event::MouseButtonReleased)
//            {
//                targetPosition = (sf::Vector2f)sf::Mouse::getPosition(window);
//                startPosition = position;
//                clock.restart();
//            }
//        }
//
     /*   time = clock.getElapsedTime().asSeconds();

        if (time < d)
        {
            position.x = Elastic::easeInOut(time, startPosition.x, targetPosition.x - startPosition.x, d);
            position.y = Elastic::easeInOut(time, startPosition.y, targetPosition.y - startPosition.y, d);

            color.r = Elastic::easeInOut(time, startColor.r, targetColor.r - startColor.r, d);
            color.g = Elastic::easeInOut(time, startColor.g, targetColor.g - startColor.g, d);
            color.b = Elastic::easeInOut(time, startColor.b, targetColor.b - startColor.b, d);
        }

        shape.setFillColor(color);
        shape.setPosition(position);

        window.clear();

        window.draw(shape);

        window.display();*/
//    }
//
//    return 0;
//}


//----------------------------------------------------------------------------------------------------task2 jumping
//#include <SFML/Graphics.hpp>
//
//int main() {
//    sf::RenderWindow window(sf::VideoMode(800, 600), "Jumping");
//
//    sf::CircleShape shape(20);
//    shape.setOrigin(20, 20);
//    shape.setFillColor(sf::Color::Cyan);
//
//    sf::Vector2f startPosition(400, 300);
//    sf::Vector2f position = startPosition;
//
//    // Jump parameters
//    float d = 2.f;            // Total jump duration (1 second)
//    float peakTime = d/2 ; // Time to reach the peak (half of the total duration)
//    float peakHeight = -400.0f; // How high the shape will jump (negative for upward)
//
//    // Calculate coefficients for the quadratic function f(t) = a * t^2 + b * t + c
//    float c = startPosition.y;
//    float b = (peakHeight-1)/0.75f;       // Ensures it reaches peak height at t = peakTime
//    float a = (peakHeight-(peakHeight/0.75))/0.25;  // Ensures it returns to start after duration d
//
//    sf::Clock clock;
//    bool isJumping = false;
//
//    while (window.isOpen()) {
//        sf::Event event;
//        while (window.pollEvent(event)) {
//            if (event.type == sf::Event::Closed)
//                window.close();
//
//            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
//                if (!isJumping) {
//                    isJumping = true;
//                    clock.restart();  // Start timing the jump
//                }
//            }
//        }
//
//        float time = clock.getElapsedTime().asSeconds();
//
//        if (isJumping) {
//            if (time <= d/2) {
//                // Follow quadratic function for entire jump (up and down phases)
//                position.y = (a * time * time) + (b * time) + c;
//            }
//           /* else if (time <= d && time >= d / 2) {
//                position.y = startPosition.y + (peakHeight * (1 - (time - peakTime) / peakTime));
//            }*/
//            else {
//                // End the jump and reset position
//                isJumping = false;
//                position = startPosition;
//            }
//        }
//
//        shape.setPosition(position);
//
//        window.clear();
//        window.draw(shape);
//        window.display();
//    }
//
//    return 0;
//}


//----------------------------------------------------------------------------------------------------------Task4 Arc

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
//    updateArc(pacman, sf::Vector2f(200, 200), 150, 30, 340);  // 30 to 330 degrees for a "mouth" shape
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

//----------------------------------------------------------------------------------------------------------PacMan

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




//-------------------------------------------------------------------------------------------------Practice
//#include <SFML/Graphics.hpp>
//
//float getX(float totalTime, float totalDistance, float t, float k)
//{
//    return (totalDistance * (1 - exp(k * t))) / (1 - exp(k * totalTime));
//}
//
//int main()
//{
//    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Template!");
//    sf::CircleShape shape(20);
//    shape.setOrigin(20, 20);
//    shape.setFillColor(sf::Color::Green);
//
//    sf::Vector2f position(20, 300);
//
//    sf::Clock clock;
//    float time;
//
//    while (window.isOpen())
//    {
//        time = clock.getElapsedTime().asSeconds();
//
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }
//
//        if (time < 3)
//            position.x = getX(3, 800, time, 3);
//        else {}
//
//        shape.setPosition(position);
//
//        window.clear();
//
//        window.draw(shape);
//
//        window.display();
//    }
//
//    return 0;
//}



//#include <SFML/Graphics.hpp>
//
//int main()
//{
//    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Template!");
//    sf::RectangleShape shape;
//    shape.setSize(sf::Vector2f(100, 20));
//    shape.setOrigin(50, 10);
//
//    shape.setFillColor(sf::Color::Green);
//
//    sf::Vector2f startPos(400, 300);
//    sf::Vector2f position(400, 300);
//
//    sf::Clock clock;
//    float time;
//
//    float amp = 100;
//    float f = 3;
//
//    while (window.isOpen())
//    {
//        time = clock.getElapsedTime().asSeconds();
//
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }
//
//        position.y = startPos.y + (amp * cos(time) * sin(f * time));
//        position.x = startPos.x + (amp * cos(time) * sin(f * time));
//
//        shape.setPosition(position);
//
//        window.clear();
//        window.draw(shape);
//        window.display();
//    }
//
//    return 0;
//}











// 
//
//#include <SFML/Graphics.hpp>
//
//int main()
//{
//    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Template!");
//
//    sf::CircleShape shape(20);
//    shape.setOrigin(20, 20);
//
//    shape.setFillColor(sf::Color::Green);
//
//    sf::Vector2f position(20, 300); //start pos
//
//    float speedX = 100;
//    float speedY = 20;
//
//    sf::Clock deltaTimeClock;
//    float deltaTime;
//
//    sf::Clock timeClock;
//    float time;
//
//    while (window.isOpen())
//    {
//        time = timeClock.getElapsedTime().asSeconds();
//        deltaTime = deltaTimeClock.restart().asSeconds();
//
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }
//
//        position calculations
//
//        float deltaX = speedX * deltaTime;
//        float deltaY = speedY * deltaTime;
//
//        position.x = time * speedX;  // distance = speed * time
//        position.y += deltaY;
//
//        shape.setPosition(position);
//
//        window.clear();
//
//        window.draw(shape);
//
//        window.display();
//    }
//
//    return 0;
//}
//







//void getCircle(sf::ConvexShape& shape, const sf::Vector2f& center, float radius)
//{
//    int pointsCount = shape.getPointCount();
//    float angle = 0;   // rad
//    float deltaAngle = (2 * PI) / pointsCount;
//
//    for (size_t i = 0; i < pointsCount; i++)
//    {
//        sf::Vector2f point;
//        point.x = center.x + radius * cos(angle);   // r * cos(0)
//        point.y = center.y + radius * sin(angle);   // r * sin(0)
//
//        shape.setPoint(i, point);
//        angle += deltaAngle;
//    }
//}
//
//
//int main()
//{
//    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML Template!");
//    sf::ConvexShape shape(1000);
//    sf::ConvexShape shape2(1000);
//    getCircle(shape, sf::Vector2f(100, 100), 100);
//    
//    shape.setFillColor(sf::Color::Green);
//    shape2.setFillColor(sf::Color::Black);
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
//        window.draw(shape);
//        window.draw(shape2);
//        window.display();
//    }
//
//    return 0;
//}



#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(400, 300), "Parallax Task");

    
    sf::Texture textureFar, textureMid, textureNear;
    if (!textureFar.loadFromFile("background_far.png") ||
        !textureMid.loadFromFile("background_mid.png") ||
        !textureNear.loadFromFile("background_near.png")) {
        return -1;  
    }

    textureFar.setRepeated(true);
    textureMid.setRepeated(true);
    textureNear.setRepeated(true);

    sf::FloatRect farRect(0.f, 0.f, window.getSize().x * 2.f, window.getSize().y);
    sf::FloatRect midRect(0.f, 0.f, window.getSize().x * 2.f, window.getSize().y);
    sf::FloatRect nearRect(0.f, 0.f, window.getSize().x * 2.f, window.getSize().y);


    sf::Sprite farLayer(textureFar);
    sf::Sprite midLayer(textureMid);
    sf::Sprite nearLayer(textureNear);

    float farSpeed = 0.f;   //msh far2aaaaaa mogrd loooon
    float midSpeed = 60.f;   
    float nearSpeed = 100.f; 

    sf::Clock clock;

    // Horizontal scrolling direction
    float movementDirection = 1.f;  

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Get delta time for smooth movement each frame
        float deltaTime = clock.restart().asSeconds();

        // Adjust each layer's FloatRect for smooth scrolling
        farRect.left += farSpeed * deltaTime * movementDirection;
        midRect.left += midSpeed * deltaTime * movementDirection;
        nearRect.left += nearSpeed * deltaTime * movementDirection;

        // Reset texture rectangles for seamless looping
      /*  if (farRect.left >= textureFar.getSize().x) farRect.left = 0.f;*/
      /*  if (midRect.left >= textureMid.getSize().x) midRect.left = 0.f;
        if (nearRect.left >= textureNear.getSize().x) nearRect.left = 0.f;*/


        // Convert FloatRect to IntRect for applying texture rectangles
        farLayer.setTextureRect(sf::IntRect(static_cast<int>(farRect.left), 0, farRect.width, farRect.height));
        midLayer.setTextureRect(sf::IntRect(static_cast<int>(midRect.left), 0, midRect.width, midRect.height));
        nearLayer.setTextureRect(sf::IntRect(static_cast<int>(nearRect.left), 0, nearRect.width, nearRect.height));

        // Draw layers from back to front
        window.clear();
        window.draw(farLayer);
        window.draw(midLayer);
        window.draw(nearLayer);
        window.display();
    }

    return 0;
}

