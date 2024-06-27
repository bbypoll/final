#pragma once
#include <SFML/Graphics.hpp>

class chel
{
public:
    sf::Sprite huggywuggy;
    int dir = 0;
    float x, y, vx, vy, speed = 0;
    chel(int X, int Y, sf::String NAME)
    {
        x = X;
        y = Y;
        name = NAME;
        image.loadFromFile("img/" + name);
        texture.loadFromImage(image);
        huggywuggy.setTexture(texture);
        huggywuggy.setPosition(x, y);
        huggywuggy.setOrigin(150,180);
    }
    ~chel()
    {

    }
    void dvig(float time, int w, int h)
    {
        switch (dir)
        {
        case 0:
            vx = -speed;
            vy = 0;
            break;
        case 1:
            vx = speed;
            vy = 0;
            break;
        }
        x += vx * time;
        y += vy * time;
        if (x > w)
        {
            x = 0;
        }
        if (x < 0)
        {
            x = w;
        }
    
        speed = 0;
        huggywuggy.setPosition(x, y);
    }
private:
    sf::String name;
    sf::Image image;
    sf::Texture texture;
};

