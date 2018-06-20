#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;


class Person
{
	public:
		Person(int age,string name);
	void show();
friend	ostream& operator<<(ostream& out, Person& );
private:
	int age;
	string name;		
};

ostream& operator<<(ostream& out, Person& p)
	{	
   		 out<<"age : "<<p.age<<" name: "<<p.name;
    		return out;
	}
void Person::show()
{
	//string ret;
	//ret=ret+"age:"+" name: "+this->name;
	//return ret;
	cout <<"age : "<<this->age<<" name:"<<this->name<<endl;
}

Person::Person(int age, string name)
{
	this->age = age;
	this->name = name;
}



int main(void)
{
	int i;
#if 0
	string x = x+"abc";
	cout<<"x "<<x<<endl;
	return 0;
#endif
	vector<Person> Vp;
// 显示 vec 的原始大小
	    cout << "vector size = " << Vp.size() << endl;	
	Person a(4,"a");
	Person b(5,"b");
cout<<"operator < < "<<endl;
	cout<<b<<endl;

	Vp.push_back(a);
	Vp.push_back(b);

	    cout << "vector size = " << Vp.size() << endl;
	for(i = 0; i < Vp.size(); i++){
     		 cout << "value of vec [" << i << "] = ";
		Vp[i].show();
  	 }

	 vector<Person>::iterator v = Vp.begin();
   while( v != Vp.end()) {
      cout << "value of v = ";
	v->show();
      v++;
   }	
}
