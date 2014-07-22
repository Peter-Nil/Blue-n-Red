#include "singleton.h"


static int selectedType=1;
static int selectedSize=1;
static char selectedColor='R';
static Singleton* singleton_p=0;

Singleton* Singleton::newSingleton()
{if (singleton_p==0)
{singleton_p=new Singleton;}
return singleton_p;}
Singleton::Singleton(){


}

const int Singleton::getType(){
return selectedType;
}

const int Singleton::getSize()
{return selectedSize;
}

const char Singleton::getColor()
{return selectedColor;
}

void Singleton::changeType()
{if (selectedType==1)
{selectedType=0;}
else {selectedType++;}
;
}
void Singleton::changeSize(int newSize)
{selectedSize=newSize;}

void Singleton::changeColor(char newColor)
{selectedColor=newColor;}
