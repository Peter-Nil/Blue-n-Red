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
private:
	string namn;
	string typ;
};

#endif