
#include <iostream>

using namespace std;
class B
{
	public:
		int m_iNum;
/*
 * 必需要有虚函数，不然会有如下的错误：
 * error: cannot dynamic_cast ‘pb’ (of type ‘class B*’) to type ‘class D*’ (source type is not polymorphic)
 * */
		virtual void foo()
		{
			printf("foo class B");
		}
};
 
class D:public B
{
	public:
		char* m_szName[100];
		virtual void foo()
		{
			printf("foo class D");
		}
};
 
class E:public D
{
	public:
		int idNum;
		virtual void foo()
		{
			printf("foo class E");
		}
};

void func(B* pb)
{
	D* pd1=static_cast<D*>(pb);
	D* pd2=dynamic_cast<D*>(pb);

	cout<< "static_cast ret "<<pd1<<endl;
	cout<< "dynamic_cast ret "<<pd2<<endl;
}

int main()
{
	B* b=new(B);
	D* d=new(D);
	E* e=new(E);
	cout<<"func(b)"<<endl;
	func(b);
	cout<<"func(d)"<<endl;
	func(d);
	cout<<"func(e) e "<<endl;
	func(e);
}	
