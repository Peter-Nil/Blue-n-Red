#include "iostream"
#include "fil.h"
#include <string>
#include <cstring>
struct b{int c;char d;};
int main()
{
	fil text("text fil test", "txt");
	cout<<text.getData();
	cout<<endl<<"switch out content with: ";
	string temp;
	getline(cin,temp);
	text.setData(temp);
	cout<<temp<<endl;
	system("pause");
	return 0;
}