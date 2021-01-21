#include <SFML/Graphics.hpp>

int main()
{
    const int szerokosc = 800;
    const int wysokosc = 800;
    const int promien = 50;

    float dt = 1.0;

    const int N = 3;
    float x[3] = { 100.0, 100.0, 100.0 };
    float y[3] = { 50.0, 23.0, 38.9 };
    float vx[3] = { 0.005, 0.006, 0.012 };
    float vy[3] = { 0.05, 0.06, 0.12 };
    float g[3] = {10, 30, 50};

    sf::RenderWindow window(sf::VideoMode(szerokosc, wysokosc), "SFML is launched!");


    std::vector <sf::CircleShape> shapes(N);
    for (int i = 0; i < N; i++)
    {
        sf::CircleShape shape(promien);
        shape.setFillColor(sf::Color::Green);
        shapes[i] = shape;
    }

    while (window.isOpen())
    {
        for (int i = 0; i < N; i++)
        {
            if (x[i] > szerokosc-(2*promien))
            {
                vx[i] = -vx[i];
            }
            else if (x[i] < 0)
            {
                vx[i] = -vx[i];
            }
            if (y[i] > wysokosc-(2*promien))
            {
                vy[i] = -vy[i];
            }
            else if (y[i] < 0)
            {

                y[i] += dt;

            }
            x[i] = x[i] + (vx[i] * dt);
            y[i] = y[i] + (vy[i] * dt);
            vy[i] = vy[i] + 0.001 * dt;
            g[i] += vy[i];

            shapes[i].setFillColor(sf::Color(0 + g[i], 125, 0));
        }

        sf::Event event;
        while (window.pollEvent(event))
        {
           if (event.type == sf::Event::Closed)
                window.close();

            else if (event.key.code == sf::Keyboard::Escape)
                window.close();
        }

        window.clear();
        for (int i = 0; i < N; i++)
        {
            window.draw(shapes[i]);
            shapes[i].setPosition(x[i], y[i]);
        }
        window.display();
    }

    return 0;
}
