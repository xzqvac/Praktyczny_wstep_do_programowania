#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <windows.h>
#include <string>
#include <cstdlib>

const int NDUCKS = 0;


int main()
{
    srand (time(NULL));

    sf::RenderWindow window(sf::VideoMode(1280,720), "DUCK HUNTER");
    //cursor
    window.setMouseCursorVisible(false);
    sf::View fixed = window.getView();
    sf::Texture CursorTexture;
    CursorTexture.loadFromFile("crosshair.png");
    sf::Sprite Crosshair(CursorTexture);
    Crosshair.scale(0.033,0.033);

    window.setFramerateLimit(60);

    //background texture
    sf::Texture background;
    background.loadFromFile("background.png");
    sf::RectangleShape bckgshape(sf::Vector2f(1280,720));
    bckgshape.setTexture(&background);

    //DUCK DIRECT MOVES
    std::vector<int> dir(NDUCKS, 1);

    //gun and duck sound
    sf::SoundBuffer Fireshot;
    sf::SoundBuffer DyingDuck;
    if (!Fireshot.loadFromFile("FireGun.wav"))
        return -1;
    if (!DyingDuck.loadFromFile("DyingDuckSound.wav"))
        return -1;
    sf::Sound soundOfGun;
    soundOfGun.setBuffer(Fireshot);
    sf::Sound soundOfDuck;
    soundOfDuck.setBuffer(DyingDuck);

    //duck texture
    sf::Texture ducktexture;
    ducktexture.setSmooth(true);
    ducktexture.loadFromFile("Custom.png");
    sf::IntRect duckframe(128, 116, 40, 34);

    //shooted duck
    sf::Texture dying;
    if (!dying.loadFromFile("Custom.png"))
        return -1;
    sf::IntRect deathframe(129, 235, 40, 34);

    //duck flying down
    sf::Texture duckdown;
    if (!duckdown.loadFromFile("Custom.png"))
        return -1;
    sf::IntRect downframe(167, 232, 34, 35);

    //health
    sf::Texture health;
    if (!health.loadFromFile("health.png"))
        return -1;
    sf::IntRect healthframe(6, 95, 123, 35);
    sf::Sprite healthbar(health);
    healthbar = sf::Sprite(health, healthframe);
    healthbar.setPosition(1110,650);

    //Text time counting
    int counter = 10;
    sf::Font font;
    if (!font.loadFromFile("Nintendo-DS-BIOS.ttf"))
        return -1;

    sf::Text timetext;
    timetext.setFont(font);
    timetext.setCharacterSize(64);
    timetext.setPosition(90,650);

    sf::Text texth;
    texth.setFont(font);
    texth.setCharacterSize(60);
    texth.setPosition(30,590);
    texth.setString("GAME TIME");

    sf::Text number;
    number.setFont(font);
    number.setCharacterSize(64);
    number.setPosition(600,650);

    sf::Text stats;
    stats.setFont(font);
    stats.setCharacterSize(60);
    stats.setPosition(500,590);
    stats.setString("KILLED DUCKS");

    std::vector<sf::Sprite> duck(NDUCKS);
    for(int i = 0; i<NDUCKS; i++)
    {
        duck[i] = sf::Sprite(ducktexture, duckframe);
        duck[i].scale(2, 2);
        duck[i].setPosition(rand() % 1280 + 20, rand() % 470 + 20);
    }

    sf::Clock zegar;
    sf::Clock spawn;
    sf::Clock goingdown;
    sf::Clock gametime;

    int HP = 3;
    int killed =0;

    while (window.isOpen())
    {
        //CURSOR
        Crosshair.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
        //POSITION OF MOUSE
        int mouseX = sf::Mouse::getPosition(window).x;
        int mouseY = sf::Mouse::getPosition(window).y;

        sf::Event event{};
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window.close();
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    soundOfGun.play();
                    for(int i = 0; i<duck.size();i++)
                    {
                        if ((mouseX >= duck[i].getPosition().x && mouseX <= duck[i].getPosition().x + 47) && (mouseY >= duck[i].getPosition().y && mouseY <= duck[i].getPosition().y + 30))
                        {
                            soundOfDuck.play();
                            killed++;
                            std::string d = std::to_string(killed);
                            number.setString(d);
                            dir[i] = 2;

                        }

                    }
                }
            }
        }
            for(int i = 0;i<duck.size();i++)
            {
                if(duck[i].getPosition().x <= -47*2)
                    dir[i] = 1;
                else if (duck[i].getPosition().x + 47 >= window.getSize().x + 47)
                    dir[i] = 0;

                if (dir[i] == 2)
                {
                    duck[i].setTextureRect(deathframe);
                    duck[i].move(0,5.f);


                    if (duck[i].getPosition().y >= 520)
                    {
                        duck.erase(duck.begin()+i);
                        dir.erase(dir.begin()+i);
                        --i;
                        continue;
                    }
                }
                else if (dir[i] == 1)
                {
                    duck[i].move(10,0);
                    if(zegar.getElapsedTime().asSeconds() > 0.175)
                    {
                        if(duckframe.left>128 + 40)
                            duckframe.left -= 40*2;
                        else
                            duckframe.left += 40;
                        if(duck[i].getPosition().x >= 1210)
                        {
                            std::cout<<"POSITION X"<<duck[i].getPosition().x<<std::endl;
                            healthframe.top += 37;
                            healthbar.setTextureRect(healthframe);
                            duck.erase(duck.begin()+i);
                            dir.erase(dir.begin()+i);
                            --i;
                            HP--;
                            if(HP == 0)
                            {
                                break;
                            }
                           continue;
                        }
                        duck[i].setTextureRect(duckframe);
                        if(i == duck.size()-1)
                            zegar.restart();
                    }
                }
                else if(dir[i] == 5)
                {
                    break;
                }

            }


        if (spawn.getElapsedTime().asSeconds() > 1 && counter > 0)
        {
            sf::Sprite tempduck(ducktexture, duckframe);
            tempduck.scale(2, 2);
            tempduck.setPosition( - 47, rand() % 470 + 20);
            duck.push_back(tempduck);
            dir.push_back(1);
            spawn.restart();

        }

        if (gametime.getElapsedTime().asSeconds() > 1.0)
        {
            counter--;
            if (counter == 0)
            {
                for (int i = 0; i < duck.size(); i++)
                {
                    dir[i] = 5;
                }

            }
            gametime.restart();

        }


        std::string s = std::to_string(counter);
        timetext.setString(s);


        window.draw(bckgshape);
        for(int i=0;i<duck.size();i++)
        {
            window.draw(duck[i]);
        }

        window.setView(fixed);
        window.draw(stats);
        window.draw(number);
        window.draw(texth);
        window.draw(timetext);
        window.draw(healthbar);
        window.draw(Crosshair);
        window.display();
    }
    return 0;
}
