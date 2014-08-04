#ifndef FIL
#define FIL
#include "string"

using namespace std;

class fil{
public:

	fil(string NAMN, string TYP);
	string	getFilename();
	string	getName();
	string	getType();
	string	getData();
	void	setData(string Data);
	string	serialization(void* pointertovariable, int sizeofvariable);
	void*	deserialization();
	
private:
	string namn;
	string typ;
	string ds;
};

#endif