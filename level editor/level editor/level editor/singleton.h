#ifndef SINGLETON
#define SINGLETON

class Singleton{
	Singleton();
	Singleton(Singleton&);
public:
	static Singleton* newSingleton();
	const int getDirection();
	const int getSize();
	const char getColor();
	void changeSize(int newSize);
	void changeDirection();
	void changeColor(char newColor);
};


#endif