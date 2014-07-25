#include "houses.h"
#include "singleton.h"
#include <SFML\Graphics.hpp>
#include <sstream>
Singleton *singleton_p=Singleton::newSingleton();
using namespace std;


static sf::Color dumbdata(){
	char color=singleton_p->getColor();
	if (color=='B'){return sf::Color::Blue	;}
	if (color=='G'){return sf::Color::Green ;}
	if (color=='R'){return sf::Color::Red	;}
	if (color=='Y'){return sf::Color::Yellow;}
	if (color=='W'){return sf::Color::White ;}
}


houses::houses(int x,int y){
	d_size=singleton_p->getSize();
	d_type=singleton_p->getDirection();
	d_x=x;d_y=y;
	rectangles.resize(d_size);
	
	if (d_type==0){
		for(int i=0;i<d_size;i++)
		{
			
rectangles[i]=new sf::RectangleShape;
rectangles[i]->setPosition(x+i*32,y);
rectangles[i]->setSize(sf::Vector2f(28, 28));
rectangles[i]->setFillColor(dumbdata());
rectangles[i]->setOutlineColor(sf::Color::Cyan);
rectangles[i]->setOutlineThickness(2);
d_maX=d_size*34+x;
d_maxY=y+34;
		}
	}
	else if (d_type==1)
	{
	for(int i=0;i<d_size;i++)
		{
			
rectangles[i]=new sf::RectangleShape;
rectangles[i]->setPosition(x,y+i*32);
rectangles[i]->setSize(sf::Vector2f(28, 28));
rectangles[i]->setFillColor(dumbdata());
rectangles[i]->setOutlineColor(sf::Color::White);
rectangles[i]->setOutlineThickness(2);
d_maX=x+34;
d_maxY=d_size*34+y;
	
	};

}
}
;

houses::houses(string loaddata){
	std::stringstream ss;
	int x=1; int y=2;//placeholder
	d_size=singleton_p->getSize();
	d_type=singleton_p->getDirection();
	d_x=x;d_y=y;
	rectangles.resize(d_size);
	
	if (d_type==0){
		for(int i=0;i<d_size;i++)
		{
			
rectangles[i]=new sf::RectangleShape;
rectangles[i]->setPosition(x+i*32,y);
rectangles[i]->setSize(sf::Vector2f(28, 28));
rectangles[i]->setFillColor(dumbdata());
rectangles[i]->setOutlineColor(sf::Color::Cyan);
rectangles[i]->setOutlineThickness(2);
d_maX=d_size*34+x;
d_maxY=y+34;
		}
	}
	else if (d_type==1)
	{
	for(int i=0;i<d_size;i++)
		{
			
rectangles[i]=new sf::RectangleShape;
rectangles[i]->setPosition(x,y+i*32);
rectangles[i]->setSize(sf::Vector2f(28, 28));
rectangles[i]->setFillColor(dumbdata());
rectangles[i]->setOutlineColor(sf::Color::White);
rectangles[i]->setOutlineThickness(2);
d_maX=x+34;
d_maxY=d_size*34+y;
	
	};

}
}
;

void houses::change(sf::Color col)
{
	for(int i=0;i<d_size;i++)
		{
			rectangles[i]->setFillColor(col);}}
const int houses::getSize(){return d_size;}
const int houses::getX(){return d_x;}
const int houses::getY(){return d_y;}
const int houses::getDirection(){return d_type;}
const int houses::getMaX(){return d_maX;}
const int houses::getMaxY(){return d_maxY;}
const string houses::getDataAsString()
{
	std::stringstream ss;
	ss << d_size<<",";
	ss << d_x<<",";
	ss << d_y<<",";
	ss << d_type<<",";
	ss << d_maX<<",";
	ss << d_maxY;
	return ss.str();
}
houses::~houses()
{
	while(!rectangles.empty())  
	{rectangles.pop_back(); ;}
}