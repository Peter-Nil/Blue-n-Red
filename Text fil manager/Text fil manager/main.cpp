#include "iostream"
#include "fil.h"

int main()
{
	fil text("text fil test", "txt");
	cout<<text.getData();
	cout<<endl<<"switch out content with: ";
	string temp;
	cin>>temp;
	text.setData(temp);
	cin.get();
	return 0;
}