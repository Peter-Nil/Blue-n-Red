#include "iostream"
#include "string"
#include "istream"
#include <sstream>
using namespace std;
int main(){
	string stringy1 = "hello world";
	istringstream load(stringy1);
	string line;
	getline(load,line,' ');
	cout<<'"'<<line<<'"'<<endl;
	system("pause");
	return 0;
}