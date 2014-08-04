#include "fil.h"
#include "fstream" //för filebuf

fil::fil(string NAMN, string TYP):
	namn(NAMN),
	typ(TYP){
}

string	fil::getFilename(){
	std::string temp = namn + "." + typ;
	return temp;
}

string	fil::getName()
{
	return namn;
}

string	fil::getType()
{
	return typ;
}

string	fil::getData(){
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
}

void	fil::setData(string Data){
	filebuf fb;
	if (fb.open(getFilename().c_str(), ios::out)){
		ostream file(&fb);
		file.write(Data.c_str(), Data.length());
		fb.close();
	}
};

string	fil::serialization(void* pointertovariable, int sizeofvariable)
{
	return string((char*)(pointertovariable), sizeofvariable);
}

void*	fil::deserialization()
{
	ds = getData();
	return (void*)((char*)ds.c_str());
}
