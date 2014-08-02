#include "iostream"
#include "string"
using namespace std;
class b{
public:
	char d;
	int c;
};
int main(){
	b a, *e;
	e = &a;
	e->c =  1;
	e->d = 'a';

	
	void* voidy = e; 
	char* chary = (char*)voidy; 
	string stringy(chary, sizeof(e)); 
	char* chary2 = (char*)stringy.c_str(); 
	void* voidy2 = chary2; 
	b *f = (b*)voidy2;
	cout<<a.c<<endl<<f->c<<endl;
	system("pause");
	return 0;
}