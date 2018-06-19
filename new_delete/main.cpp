#include <iostream>
#include <string>

using namespace std;


class DOG
{
public:
	DOG(int age ,string name);
	DOG();
	void init(int age, string name);
void 	show();

private:
	int 	age;
	string 	name;
};

DOG::DOG()
{

}
void DOG::init(int age,string name)
{
	this->age = age;
	this->name = name;
}

DOG::DOG(int age,string name)
{
	this->age = age;
	this->name = name;
}

void DOG::show()
{
	cout<<"age:"<<age<<"   ."<<"name:"<<name<<endl;
}


void array_dog()
{
	int i;
 	DOG* p=new DOG[3];
	p[0].init(1,"dog1");
	p[1].init(2,"dog2");
	p[2].init(3,"dog3");

	for(i=0;i<3;i++)
	{
		p[i].show();
	}

	delete []p;
}

int main()
{


	class DOG d1(3,"d1");

	class DOG* pd2=new(class DOG);
	pd2->init(4,"pd2");
	pd2->show();
	d1.show();

	delete pd2;

	array_dog();
	return 0;
}
