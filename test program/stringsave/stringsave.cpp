/*class b{
public:
	char d;
	int c;
};
int main(){
	b a, *e;
	e = &a;
	e->c =  1;
	e->d = 'a';

	
	//void* voidy = e; 
	char* chary = (char*)((void*)e); 
	char* chary2;
	string stringy(chary, sizeof(*e)); 
	{
		chary2 = (char*)stringy.c_str();
	}
	void* voidy2 = chary2; 
	b *f = (b*)voidy2;

	cout<<a.c<<endl<<f->c<<endl;
	cout<<a.d<<endl<<f->d<<endl;
	*/