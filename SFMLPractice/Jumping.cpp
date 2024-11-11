////----------------------------------------------------------------------------------------------------task2 jumping
//
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
//
