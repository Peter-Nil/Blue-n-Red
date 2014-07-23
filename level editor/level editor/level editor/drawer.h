#ifndef DRAWER
#define DRAWER
class houses;

namespace sf{
	class RenderWindow;
	class Event;
};

class drawer{
public:
	static void mainDraw(sf::RenderWindow* window);
	
	static void keyboard(sf::Event *event_i);
	static void initialize();
	static void newDraw(sf::RenderWindow* window);
	static void destroyDraw(sf::RenderWindow* window);
	static void clickDraw(sf::RenderWindow* window);
};

#endif