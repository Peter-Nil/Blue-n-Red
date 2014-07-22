#include "drawer.h"
#include "singleton.h"
#include <vector>
#include "houses.h"
#include <SFML\Graphics.hpp>
using namespace std;
Singleton*singleton_P=Singleton::newSingleton();
std::vector<houses*> house_v;
static bool clear=1;

static sf::Color dumbdata(){
	char color=singleton_P->getColor();
	if (color=='B'){return sf::Color::Blue;}
	if (color=='G'){return sf::Color::Green;}
	if (color=='R'){return sf::Color::Red;}
	if (color=='Y'){return sf::Color::Yellow;}
	if (color=='W'){return sf::Color::White;}
}
void drawer::initialize()
{house_v.push_back(new houses(128,128));}

void drawer::mainDraw(sf::RenderWindow* window)
{
	if (house_v.empty()==false)
	{
	int house_number=house_v.size();
	for (int j=0;j<house_number;j++)
	{
		int size=house_v[j]->getSize(); 
		for(int i =0;i<size;i++)
		{
			window->draw(*house_v[j]->rectangles[i]);
		}
	}
		
	}
}

int overlapX()
{if (singleton_P->getType()==1)
{return 34;}
else 
{return (34*(singleton_P->getSize()));
}}

int overlapY(){if (singleton_P->getType()==0){return 34;}
else {return (34*(singleton_P->getSize()));
}}

void drawer::clickDraw (sf::RenderWindow*window)
{
	if (house_v.empty()==false)
	{	
		
		int j = 60;
		int y=sf::Mouse::getPosition(*window).y;
		int x=sf::Mouse::getPosition(*window).x;
		
		int number=house_v.size();
		for(int i=0;i<number;i++)
					{
					
						if(	
							(x>=house_v[i]->getX())
							&&(x<(house_v[i]->getMaX()))
							&&(y>(house_v[i]->getY()))
							&&(y<=(house_v[i]->getMaxY()))
						  )
						{
							house_v[i]->change(dumbdata());
							break;
						}

					}
		
	}
}

void drawer::newDraw(sf::RenderWindow* window_p)
{	

	clear=1;
	int y=sf::Mouse::getPosition(*window_p).y;
	int x=sf::Mouse::getPosition(*window_p).x;
	int size=house_v.size();
	int x2=overlapX();
	int y2=overlapY();
	for(int i=0;i<size;i++)
				{				
					
					if(
					(x>(house_v[i]->getX()-x2))
					&&(x<(house_v[i]->getMaX()))
					&&(y>(house_v[i]->getY()-y2))
					&&(y<(house_v[i]->getMaxY()))
					){clear=0;
					break;}
				}
	if (clear==1)
	{
		int j = 64;
		y -= y % 64;
		x -= x % 64;
		house_v.push_back(new houses(sf::Mouse::getPosition(*window_p).x,sf::Mouse::getPosition(*window_p).y));
	}
	}
void drawer::destroyDraw(sf::RenderWindow* window)
{
	if (house_v.empty()==false)
	{
	int y=sf::Mouse::getPosition(*window).y;
	int x=sf::Mouse::getPosition(*window).x;
	int size=house_v.size();
	for(int i=0;i<size;i++)
				{
					
				if(	
					(x>=house_v[i]->getX())
					&&(x<(house_v[i]->getMaX()))
					&&(y>(house_v[i]->getY()))
					&&(y<=(house_v[i]->getMaxY()))
					)
				{
					delete house_v[i];
					house_v.erase(house_v.begin()+i);
				}
				
				}
	}
};



void drawer::keyboard(sf::Event *event_i){
{
				switch(event_i->key.code)
					{
				case sf::Keyboard::Num1:
					{singleton_P->changeSize(1);
					break;}
				case sf::Keyboard::Num2:
					{singleton_P->changeSize(2)	;
					break;}

				case sf::Keyboard::Num3:
					{singleton_P->changeSize(3)	;
					break;}

				case sf::Keyboard::Num4:
					{singleton_P->changeSize(4)	;
					break;}
					
				case sf::Keyboard::Num5:
					{singleton_P->changeSize(5)	;
					break;}
				case sf::Keyboard::Num6:
					{singleton_P->changeSize(6)	;
					break;}
				case sf::Keyboard::B:
					{singleton_P->changeColor('B');
					break;}
				case sf::Keyboard::G:
					{singleton_P->changeColor('G');
					break;}
				case sf::Keyboard::R:
					{singleton_P->changeColor('R')	;
					break;}
				case sf::Keyboard::Y:
					{singleton_P->changeColor('Y')	;
					break;}	
				case sf::Keyboard::W:
					{singleton_P->changeColor('W')	;
					break;}
				case sf::Keyboard::T:
					{singleton_P->changeType();
					break;}
				
				}
			}}
