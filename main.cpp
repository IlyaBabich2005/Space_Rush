#include "Player.h"
#include "Timer.h"
#include "Debug.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Space Rush");
    sf::CircleShape shape(50.f);

    //RectangleShape rect;

    //Texture text;
    //text.loadFromFile(GAME::RES::SHIP::TEXTURES::SHIP_ONE_DEFAULT);

    //rect.setTexture(&text);
    //rect.setSize({200, 200});
    //rect.setOrigin({ 50, 100 });
    //rect.rotate(180);
    //rect.setPosition({ 400,400 });

    //Vector2f vect;

    //float radians = 3.1415926536 / 180 * rect.getRotation();

    //vect.x = cos(radians);
    //vect.y = sin(radians);

    Timer timer;
    
    Player player;

    Debug debug;

    while (window.isOpen())
    {
        timer.RefreshTimer();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

       //player.rotate(timer.getTime() * 120);

       // player.setOrigin(vf);
        player.KeyboardRotatingMoveSet(timer.getTime());
        player.KeyboardMotionMoveSet(timer.getTime());

        
        //rect.rotate(timer.getTime() * 30);


        /*radians = 3.1415926536 / 180 * rect.getRotation();
        vect.x = timer.getTime() * 50 * cos(radians);
        vect.y = timer.getTime() * 50 * sin(radians);

        if (Keyboard::isKeyPressed(Keyboard::D))
        {
            rect.rotate(timer.getTime() * 120);
        }
        if (Keyboard::isKeyPressed(Keyboard::A))
        {
            rect.rotate(timer.getTime() * -120);
        }
        if (Keyboard::isKeyPressed(Keyboard::W))
        {
            rect.move( vect);
        }
        if (Keyboard::isKeyPressed(Keyboard::S))
        {
            rect.move(-vect);
        }*/


        window.clear();
        debug.ShowPlayerInfo(&player, window);
        player.show(window);
        //window.draw(rect);
        window.display();

    }

    return 0;
}