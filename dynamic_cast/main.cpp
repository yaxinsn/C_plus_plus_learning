
#include <iostream>
#include <stdio.h>
#include <unistd.h>

using namespace std;
class animal
{
	public:
		int m_iNum;
/*
 * 必需要有虚函数，不然会有如下的错误：
 * error: cannot dynamic_cast ‘pb’ (of type ‘class B*’) to type ‘class D*’ (source type is not polymorphic)
 * */
		virtual void foo()
		{
			printf("I am an animal\n");
		}
		void who()
		{
			printf("I am an animal\n");
		}

};
 
class dog:public animal
{
	public:
		char* m_szName[100];
		virtual void foo()
		{
			printf("I am a dog\n");
		}
		void who()
		{
			printf("%s : I am an dog\n",__FUNCTION__);
		}
};
 
class puppy:public dog
{
	public:
		int idNum;
		virtual void foo()
		{
			printf("I ma a puppy\n");
		}
		void who()
		{
			printf("%s : I am an puppy\n",__FUNCTION__);
		}
};

void func(animal* pb)
{
	dog* pd1=static_cast<dog*>(pb);
	dog* pd2=dynamic_cast<dog*>(pb);

	cout<< "static_cast ret "<<pd1<<endl;
	cout<< "dynamic_cast ret "<<pd2<<endl;
	cout<<"call pd2-> virtual function"<<endl;
	if(pd2)
		pd2->foo();
	else
		cout<<"pd2 is null , can't call this function"<<endl;

	cout<<"call pd2->no virtual function"<<endl;
	if(pd2)
		pd2->who();
	else
		cout<<"pd2 is null , can't call this function"<<endl;

}

int main()
{
	animal* b=new(animal);
	dog* d=new(dog);
	puppy* e=new(puppy);
	cout<<"func(b)"<<endl;
	func(b);
	cout<<"func(d)"<<endl;
	func(d);
	cout<<"func(e) e "<<endl;
	func(e);
}	
