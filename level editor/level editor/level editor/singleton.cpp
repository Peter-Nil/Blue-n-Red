#include "singleton.h"


static int selectedDirection=1;
static int selectedSize=1;
static char selectedColor='R';
static Singleton* singleton_p=0;

Singleton* Singleton::newSingleton()
{if (singleton_p==0)
{singleton_p=new Singleton;}
return singleton_p;}
Singleton::Singleton(){


}

const int Singleton::getDirection(){
return selectedDirection;
}

const int Singleton::getSize()
{return selectedSize;
}

const char Singleton::getColor()
{return selectedColor;
}

void Singleton::changeDirection()
{if (selectedDirection==1)
{selectedDirection=0;}
else {selectedDirection++;}
;
}
void Singleton::changeSize(int newSize)
{selectedSize=newSize;}

void Singleton::changeColor(char newColor)
{selectedColor=newColor;}
