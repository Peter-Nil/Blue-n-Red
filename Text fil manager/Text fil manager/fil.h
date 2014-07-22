#ifndef FIL
#define FIL
#include "fstream" //för filebuf
#include "string"

using namespace std;

class fil{
public:

	fil(string NAMN, string TYP):
		namn(NAMN),
		typ(TYP){
		}
	string	getFilename(){
		std::string temp = namn + "." + typ;
		return temp;};
	string	getName(){return namn;};
	string	getType(){return typ;};
	string	getData(){
		filebuf fb;
		string temp2;
		if (fb.open(getFilename().c_str(), ios::in)){
			istream file(&fb);
			while(!file.eof()){
				temp2 += file.get();
			}
			fb.close();
		}
		return temp2;
	};
	void	setData(string Data){
		filebuf fb;
		if (fb.open(getFilename().c_str(), ios::out)){
			ostream file(&fb);
			file.write(Data.c_str(), Data.length());
			fb.close();
		}
	};
private:
	string namn;
	string typ;
};

#endif