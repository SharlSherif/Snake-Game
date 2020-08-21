#include <iostream>
#include <SFML/Graphics.hpp>
#include <windows.h>

using namespace std;

class Pos {
    public:
        float speed = 2.f;
        float X = speed;
        float Y = 0.f;
};

class Snake {
    public:
        Pos pos;
        sf::RenderWindow board;
        sf::RectangleShape snakeBlock;
        sf::RectangleShape snakeHead;


    Snake() {
        board.create(sf::VideoMode(600.f, 600.f), "TXT");
    }
    
    void CheckActions() {
        sf::Event event;

        while (board.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                board.close();
        }
    }

    void Movement() {

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            cout << "W Pressed!";

            pos.Y = pos.Y - pos.speed;

        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            cout << "D Pressed!";
            pos.X = pos.X + pos.speed;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            cout << "A Pressed!";
            pos.X = pos.X - pos.speed;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            cout << "S Pressed!";
            pos.Y = pos.Y + pos.speed;
        }
    }
    void DrawAxis() {
        for (int i = 0; i <= 600; i += 50) {
            for (int k = 0; k <= 600; k += 50) {
                sf::RectangleShape BOX;
                BOX.setSize(sf::Vector2f(50, 50));
                BOX.setFillColor(sf::Color::Blue);
                BOX.setPosition(i, k);

                board.draw(BOX);
            }
        }
    }
    int main()
    {
        snakeHead.setSize(sf::Vector2f(20, 20));
        snakeHead.setFillColor(sf::Color::Green);

        snakeBlock.setSize(sf::Vector2f(5, 5));
        snakeBlock.setFillColor(sf::Color::Red);
   
        while (board.isOpen())
        {
            CheckActions();
            Movement();
            board.clear();
            DrawAxis();

            snakeBlock.setPosition(pos.X, pos.Y);
            snakeHead.setPosition(pos.X, pos.Y+20);
            board.draw(snakeBlock);
            board.draw(snakeHead);
            board.display();
            Sleep(16);
        }

        return 0;
    }
};

int main() {
    Snake snake;
    snake.main();
}
