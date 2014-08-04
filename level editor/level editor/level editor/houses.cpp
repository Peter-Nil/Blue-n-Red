#include "houses.h"
#include "singleton.h"
#include <SFML\Graphics.hpp>
#include <sstream>
#include <iostream>
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

	stringstream ss(loaddata);
	string line;
	
	getline (ss,line,'¤');//converting the blocks seperated by "¤" into the relevant variables
	istringstream is(line);
	is>>d_size;

	getline (ss,line,'¤');
	istringstream is1(line);
	is1>>d_x;

	getline (ss,line,'¤');
	istringstream is2(line);
	is2>>d_y;
	cout<<line;
	getline (ss,line,'¤');
	istringstream is3(line);
	is3>>d_type;
	rectangles.resize(d_size);
	
	if (d_type==0){
		for(int i=0;i<d_size;i++)
		{			
rectangles[i]=new sf::RectangleShape;
rectangles[i]->setPosition(d_x+i*32,d_y);
rectangles[i]->setSize(sf::Vector2f(28, 28));
rectangles[i]->setFillColor(dumbdata());
rectangles[i]->setOutlineColor(sf::Color::Cyan);
rectangles[i]->setOutlineThickness(2);
d_maX=d_size*34+d_x;
d_maxY=d_y+34;
		}
	}
	else if (d_type==1)
	{
	for(int i=0;i<d_size;i++)
		{
			
rectangles[i]=new sf::RectangleShape;
rectangles[i]->setPosition(d_x,d_y+i*32);
rectangles[i]->setSize(sf::Vector2f(28, 28));
rectangles[i]->setFillColor(dumbdata());
rectangles[i]->setOutlineColor(sf::Color::White);
rectangles[i]->setOutlineThickness(2);
d_maX=d_x+34;
d_maxY=d_size*34+d_y;
	
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
	ss << d_size<<"¤";
	ss << d_x<<"¤";
	ss << d_y<<"¤";
	ss << d_type<<"¤";
	ss << d_maX<<"¤";//the last two variables are not loaded but is useful for a human reader
	ss << d_maxY;
	return ss.str();
}
houses::~houses()
{
	while(!rectangles.empty())  
	{rectangles.pop_back(); ;}
}