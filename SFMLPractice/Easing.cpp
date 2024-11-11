//#include <SFML/Graphics.hpp>
//#include<math.h>
//#include"Elastic.h"
//#define PI 22/7.f
//
////----------------------------------------------------------------------------------------------------task1 Easing Elastic
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
//        time = clock.getElapsedTime().asSeconds();
//
//        if (time < d)
//        {
//            position.x = Elastic::easeInOut(time, startPosition.x, targetPosition.x - startPosition.x, d);
//            position.y = Elastic::easeInOut(time, startPosition.y, targetPosition.y - startPosition.y, d);
//
//            color.r = Elastic::easeInOut(time, startColor.r, targetColor.r - startColor.r, d);
//            color.g = Elastic::easeInOut(time, startColor.g, targetColor.g - startColor.g, d);
//            color.b = Elastic::easeInOut(time, startColor.b, targetColor.b - startColor.b, d);
//        }
//
//        shape.setFillColor(color);
//        shape.setPosition(position);
//
//        window.clear();
//
//        window.draw(shape);
//
//        window.display();
//            }
//        
//            return 0;
//        }
