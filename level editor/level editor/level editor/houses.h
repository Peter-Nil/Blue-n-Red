#ifndef HOUSES
#define HOUSES

#include <vector>


namespace sf{
	class RectangleShape;
	class Event;
	class Color;
};

class houses
{public:
const int getSize();
const int getX();
const int getY();
const int getType();
const int getMaX();
const int getMaxY();
houses(int x,int y);

std::vector<sf::RectangleShape*> rectangles;
void change(sf::Color col);
~houses();
private:

int d_size;
int d_x;
int d_y;
int d_type;
int d_maX;
int d_maxY;
}
;
#endif