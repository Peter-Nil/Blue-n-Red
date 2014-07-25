#ifndef FILMANAGER
#define FILMANAGER
#include "fil.h"
#include "vector"

class filmanager{
public:
	bool addFile(string name, string type);
	//fil* getFile(string name, string type);
	//fil* getFile(string name);
private:
	vector<fil> files;
	vector<string> filenames;
};

#endif