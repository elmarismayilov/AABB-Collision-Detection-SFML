#include <iostream>
#include <SFML/Graphics.hpp>

struct Player
{
    sf::RectangleShape sprite;
    static const int HEIGHT = 100.0f;
    static const int WIDTH = 100.0f;

    float movementSpeed = 200.0f;
    sf::Vector2f direction;

    sf::Vector2f velocity;

    void init()
    {
        sprite = sf::RectangleShape(sf::Vector2f(WIDTH, HEIGHT));
        sprite.setPosition(sf::Vector2f(1280 / 2, 768/ 2));
        sprite.setFillColor(sf::Color::White);
    }

    void draw(sf::RenderWindow &window)
    {
        window.draw(sprite);
    }

    void update(float& deltaTime)
    {

        velocity.x = 0;
        velocity.y = 0;
        direction.x = 0;
        direction.y = 0;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            direction.x += 1.0f;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            direction.x += -1.0f;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            direction.y += 1.0f;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            direction.y += -1.0f;
        }

        float length = sqrt(direction.x * direction.x + direction.y * direction.y);
        if (length > 0)
        {
            direction.x /= length;
            direction.y /= length;
        }
        velocity = direction * movementSpeed;

        sf::Vector2f position = sprite.getPosition();
        position += velocity * deltaTime;
        sprite.setPosition(position);
    }

    void checkCollision(sf::RectangleShape &coin)
    {
        float x_max = sprite.getPosition().x + sprite.getSize().x;
        float y_max = sprite.getPosition().y + sprite.getSize().y;
        float x_min = sprite.getPosition().x;
        float y_min = sprite.getPosition().y;

        float c_x_max = coin.getPosition().x + coin.getSize().x;
        float c_y_max = coin.getPosition().y + coin.getSize().y;
        float c_x_min = coin.getPosition().x;
        float c_y_min = coin.getPosition().y;

        if (x_max > c_x_min && y_max > c_y_min && x_min < c_x_max && y_min < c_y_max)
        {
            coin.setFillColor(sf::Color::Red);
        }
        else
        {
            coin.setFillColor(sf::Color::Yellow);
        }
    }
};

struct Coin
{
    sf::RectangleShape sprite;
    static const int HEIGHT = 50.0f;
    static const int WIDTH = 50.0f;

    void init()
    {
        sprite = sf::RectangleShape(sf::Vector2f(WIDTH, HEIGHT));
        sprite.setPosition(sf::Vector2f(1280 / 2 + 150.0f, 768 / 2));
        sprite.setFillColor(sf::Color::Yellow);
    }

    void draw(sf::RenderWindow &window)
    {
        window.draw(sprite);
    }
};

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 768), "AABBCollision", sf::Style::Close);
    window.setFramerateLimit(60);
    Player player;
    player.init();

    Coin coin;
    coin.init();

    sf::Clock clock;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        float deltaTime = clock.restart().asSeconds();
        player.update(deltaTime);
        player.checkCollision(coin.sprite);
        window.clear();

        player.draw(window);
        coin.draw(window);

        window.display();
    }

    return 0;
}
