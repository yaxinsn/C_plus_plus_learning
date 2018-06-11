#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
/*
 *  拷贝构造函数
 *  如果类带有指针变量，并有动态内存分配，则它必须由程序员编写一个拷贝构造函数，如Hello.hello
 * 
 *
 *
 * */
class Hello{

	char* hello;
public:
	int show_hello(char* who)
	{
		cout  <<hello << "," << who<<endl;
		return 0;
	}
	// 所以在class体以外定义的方法（函数）都必须在class体内进行声明。
	void set_hello(char* new_hello);
	~Hello();
	Hello(const char* h);//必须在class里进行声明。
	Hello(const Hello &obj);
};
Hello::Hello(const Hello &obj)
{
	cout <<"call copy constructor "<<endl;
	hello = strdup(obj.hello);
}
#if 1
Hello::Hello(const char* h)
{
	hello=strdup(h);

}
#endif

#if 1
Hello::~Hello()
{
	if(this->hello)
		free(this->hello);
}

void Hello::set_hello(char* new_hello)
{
	if(hello)
		free(hello);
	hello=strdup(new_hello);

}
#endif


int main()
{
	Hello Mh("Hi");
	Mh.show_hello("abl");
	Mh.set_hello("welcome ");
	Mh.show_hello("lisa");

	Hello Mh2=Mh;
	Mh2.show_hello("sheryl");
	Mh2.set_hello("Mh2 welcome");
	Mh.set_hello("Mh1 welcome");
	cout<< "Mh2 and Mh show hello"<<endl;
	Mh.show_hello("sheryl");
	Mh2.show_hello("sheryl");
}	
