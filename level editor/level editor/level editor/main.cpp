#include "drawer.h"
#include <SFML\Graphics.hpp>
using namespace std;

static int spawnRate=0;
static int destroyRate=0;

// Startpunkt för programmet
int main()
{	
sf::VideoMode Video1(800, 600) ;
sf::RenderWindow window(Video1, "Red And Blue");

sf::RenderWindow*window_p=&window;
drawer::initialize();

while (window.isOpen())
	{
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event1;
        while (window.pollEvent(event1))
        {
			if (spawnRate>0)
			{
				spawnRate--;
			}
			if (destroyRate>0)
			{
				destroyRate--;
			}
            // "close requested" event: we close the window
            if (event1.type == sf::Event::Closed)
                window.close();
			if (event1.type == sf::Event::KeyPressed) 
			{drawer::keyboard(&event1);
			goto END;
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				drawer::clickDraw(window_p);
				goto END;
			} 
			if ((sf::Mouse::isButtonPressed(sf::Mouse::Right))&&(spawnRate<1))
			{
				drawer::newDraw(window_p);
				spawnRate=5;
				goto END;
			}
			if ((sf::Mouse::isButtonPressed(sf::Mouse::Middle))&&(destroyRate<1))
			{
				drawer::destroyDraw(window_p); 
				destroyRate=5;
			}
			END:
		;}
		window.clear();

		drawer::mainDraw(window_p);
		window.display();	
		}
		
		
	
	
	return 0;
}
	

	

