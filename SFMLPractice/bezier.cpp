#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>



float dot(sf::Vector2f v1, sf::Vector2f v2)  //func for dot
{
    return v1.x * v2.x + v1.y * v2.y;
}

sf::Vector2f project(sf::Vector2f v1, sf::Vector2f v2)  //function for projectile 
{
    float dot1 = dot(v1, v2);
    float dot2 = dot(v2, v2);

    return (dot1 / dot2) * v2;
}

class DraggablePoint {        //class for draggablePoint
    sf::CircleShape shape;
    bool isDragging = false;

public:
    DraggablePoint(const sf::Vector2f& position)  //constructor to define the shape size and pos and center
    {
        shape = sf::CircleShape(10);
        shape.setOrigin(10, 10);
        shape.setPosition(position);
    }

    void beginDrag(const sf::Vector2i& mousePos) //check if the dot is dragged by mouse return isDragging true
    {
        isDragging = shape.getGlobalBounds().contains((sf::Vector2f)mousePos);
    }

    void drag(const sf::Vector2i& mousePos)   //when dragged set dot position based on mouse pos
    {
        if (!isDragging) return;
        shape.setPosition((sf::Vector2f)mousePos);
    }

    void endDrag() // when mouse release --> end drag
    {
        isDragging = false;
    }

    void draw(sf::RenderWindow& window) 
    {
        window.draw(shape);
    }

    sf::Vector2f getPosition()
    {
        return shape.getPosition();
    }
};

sf::Vector2f bezierPoint(float t, sf::Vector2f p0, sf::Vector2f p1, sf::Vector2f p2, sf::Vector2f p3)  //
{
    float u = 1 - t;
    float tt = t * t;
    float uu = u * u;
    float uuu = uu * u;
    float ttt = tt * t;

    return uuu * p0 + 3 * uu * t * p1 + 3 * u * tt * p2 + ttt * p3; // (1-t)^3*p0 + 3(1-t)^2*t*p1 + 3(1-t)t^2p2 + t^3p3
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Cubic Bezier Curve with Control Lines");
    DraggablePoint point0(sf::Vector2f(100, 500));
    DraggablePoint point1(sf::Vector2f(300, 100));
    DraggablePoint point2(sf::Vector2f(500, 100));
    DraggablePoint point3(sf::Vector2f(700, 500));

    sf::CircleShape movingPoint(15);
    movingPoint.setFillColor(sf::Color::Green);
    movingPoint.setOrigin(15, 15);

    std::vector<sf::Vertex> bezierCurve;
    sf::VertexArray controlLines(sf::LineStrip, 4); // Line strip to connect the control points

    float t = 0;
    bool animate = false;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed)
            {
                point0.beginDrag(sf::Mouse::getPosition(window));
                point1.beginDrag(sf::Mouse::getPosition(window));
                point2.beginDrag(sf::Mouse::getPosition(window));
                point3.beginDrag(sf::Mouse::getPosition(window));
            }

            if (event.type == sf::Event::MouseButtonReleased)
            {
                point0.endDrag();
                point1.endDrag();
                point2.endDrag();
                point3.endDrag();
            }

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
            {
                animate = true;
                t = 0;
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            point0.drag(sf::Mouse::getPosition(window));
            point1.drag(sf::Mouse::getPosition(window));
            point2.drag(sf::Mouse::getPosition(window));
            point3.drag(sf::Mouse::getPosition(window));
        }

        // Update the control lines to connect the control points
        controlLines[0].position = point0.getPosition();
        controlLines[1].position = point1.getPosition();
        controlLines[2].position = point2.getPosition();
        controlLines[3].position = point3.getPosition();

        // Update the Bézier curve
        bezierCurve.clear();
        for (float i = 0; i <= 1; i += 0.01f)
        {
            sf::Vector2f point = bezierPoint(i, point0.getPosition(), point1.getPosition(), point2.getPosition(), point3.getPosition());
            bezierCurve.push_back(sf::Vertex(point, sf::Color::White));
        }

        // Move the point along the curve
        if (animate && t <= 1)
        {
            sf::Vector2f pos = bezierPoint(t, point0.getPosition(), point1.getPosition(), point2.getPosition(), point3.getPosition());
            movingPoint.setPosition(pos);
            t += 0.0005f; // Adjust speed here
        }

        window.clear();

        // Draw the control points and lines
        point0.draw(window);
        point1.draw(window);
        point2.draw(window);
        point3.draw(window);
        window.draw(controlLines);

        // Draw the bezier curve
        if (!bezierCurve.empty())
            window.draw(&bezierCurve[0], bezierCurve.size(), sf::LineStrip);

        // Draw the moving point
        window.draw(movingPoint);

        window.display();
    }

    return 0;
}

