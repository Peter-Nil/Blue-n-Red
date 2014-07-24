#ifndef SINGLETON
#define SINGLETON

class Singleton{
	Singleton();
	Singleton(Singleton&);
public:
	static Singleton* newSingleton();
	const int getType();
	const int getSize();
	const char getColor();
	void changeSize(int newSize);
	void changeType();
	void changeColor(char newColor);
};


#endif