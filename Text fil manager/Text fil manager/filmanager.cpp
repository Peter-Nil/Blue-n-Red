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

//you get null pointer if it doesnt exist
fil* filmanager::getFile(string name, string type){
	fil* rfil = 0;
	for(auto temp = files.begin(); temp != files.end(); temp++){
		if(temp._Ptr->getFilename() == (name+'.'+type))		{
			rfil = temp._Ptr;
			break;
		}
	}
	return rfil;
}

//you get null pointer if it doesnt exist
	fil* filmanager::getFile(string name){
	fil* rfil = 0;
	for(auto temp = files.begin(); temp != files.end(); temp++){
		if(temp._Ptr->getName() == (name))		{
			rfil = temp._Ptr;
			break;
		}
	}
	return rfil;
}