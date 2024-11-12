//#include <SFML/Graphics.hpp>
//#include <vector>
//#include<math.h>
//#include"Elastic.h"
//#define PI 22/7.f
//
//
//
//class Trail {
//public:
//    sf::CircleShape circle;
//    float followSpeed;
//
//   
//    Trail(float radius, sf::Color color, float speed)
//        : followSpeed(speed) {
//        circle.setRadius(radius);
//        circle.setFillColor(color);
//        circle.setOrigin(radius, radius); 
//    }
//
//    // Linear interpolation function to follow a target position
//    void follow(const sf::Vector2f& target) {
//        sf::Vector2f position = circle.getPosition();
//        position.x += followSpeed * (target.x - position.x); //y2-y1 = a(x2-x1)
//        position.y += followSpeed * (target.y - position.y);
//        circle.setPosition(position);
//    }
//};
//
//int main() {
//    sf::RenderWindow window(sf::VideoMode(800, 600), "Trail Task");
//
//    // Number of Trails
//    const int numTrails = 10;
//
//    // Create a vector of Trail objects
//    std::vector<Trail> Trails;
//    for (int i = 0; i < numTrails; i++) {
//        float radius = 15.0f;                     // Radius 
//        sf::Color color(255-i*20,0,255-i*1);  
//        float speed = 0.01f - i * 0.000001f;          // Reduce speed slightly for each circle
//        Trails.emplace_back(radius, color, speed);
//    }
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
//        }
//
//       
//        sf::Vector2f mousePos = (sf::Vector2f)sf::Mouse::getPosition(window);
//        
//        // Update positions for each Trail
//
//
//        Trails[0].follow(mousePos); // First Trail  m3 el mouse
//
//
//        //trails btgry wara el ablaha 
//        for (size_t i = 1; i < Trails.size(); i++) {
//            Trails[i].follow(Trails[i - 1].circle.getPosition()); 
//        }
//
//        // Render
//        window.clear();
//        for (const auto& Trail : Trails) {
//            window.draw(Trail.circle);
//        }
//        window.display();
//    }
//
//    return 0;
//}
