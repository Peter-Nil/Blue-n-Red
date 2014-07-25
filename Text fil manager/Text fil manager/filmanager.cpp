#include "filmanager.h"

bool filmanager::addFile(string name, string type){
	bool success = false;
	if(find(filenames.begin(), filenames.end(), name+'.'+type) != filenames.end()){
		filenames.push_back(name+'.'+type);
		files.push_back(fil(name,type));
		success = true;
	}
	return success;
}