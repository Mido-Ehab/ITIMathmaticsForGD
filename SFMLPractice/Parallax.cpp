//-----------------------------------------------------------------task3 Parallax

//
//#include <SFML/Graphics.hpp>
//
//int main() {
//    sf::RenderWindow window(sf::VideoMode(400, 300), "Parallax Task");
//
//
//    sf::Texture textureFar, textureMid, textureNear;
//    if (!textureFar.loadFromFile("background_far.png") ||
//        !textureMid.loadFromFile("background_mid.png") ||
//        !textureNear.loadFromFile("background_near.png")) {
//        return -1;
//    }
//
//    textureFar.setRepeated(true);
//    textureMid.setRepeated(true);
//    textureNear.setRepeated(true);
//
//    sf::FloatRect farRect(0.f, 0.f, window.getSize().x * 2.f, window.getSize().y);
//    sf::FloatRect midRect(0.f, 0.f, window.getSize().x * 2.f, window.getSize().y);
//    sf::FloatRect nearRect(0.f, 0.f, window.getSize().x * 2.f, window.getSize().y);
//
//
//    sf::Sprite farLayer(textureFar);
//    sf::Sprite midLayer(textureMid);
//    sf::Sprite nearLayer(textureNear);
//
//    float farSpeed = 0.f;   //msh far2aaaaaa mogrd loooon
//    float midSpeed = 60.f;
//    float nearSpeed = 100.f;
//
//    sf::Clock clock;
//
//    // Horizontal scrolling direction
//    float movementDirection = 1.f;
//
//    while (window.isOpen()) {
//        sf::Event event;
//        while (window.pollEvent(event)) {
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }
//
//        // Get delta time for smooth movement each frame
//        float deltaTime = clock.restart().asSeconds();
//
//        // Adjust each layer's FloatRect for smooth scrolling
//        farRect.left += farSpeed * deltaTime * movementDirection;
//        midRect.left += midSpeed * deltaTime * movementDirection;
//        nearRect.left += nearSpeed * deltaTime * movementDirection;
//
//        // Reset texture rectangles for seamless looping
//      /*  if (farRect.left >= textureFar.getSize().x) farRect.left = 0.f;*/
//      /*  if (midRect.left >= textureMid.getSize().x) midRect.left = 0.f;
//        if (nearRect.left >= textureNear.getSize().x) nearRect.left = 0.f;*/
//
//
//        // Convert FloatRect to IntRect for applying texture rectangles
//        farLayer.setTextureRect(sf::IntRect(static_cast<int>(farRect.left), 0, farRect.width, farRect.height));
//        midLayer.setTextureRect(sf::IntRect(static_cast<int>(midRect.left), 0, midRect.width, midRect.height));
//        nearLayer.setTextureRect(sf::IntRect(static_cast<int>(nearRect.left), 0, nearRect.width, nearRect.height));
//
//        // Draw layers from back to front
//        window.clear();
//        window.draw(farLayer);
//        window.draw(midLayer);
//        window.draw(nearLayer);
//        window.display();
//    }
//
//    return 0;
//}
//
