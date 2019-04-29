#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
/*
 *  拷贝构造函数
 * 
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

struct addr_st
{
	int address[4];
	char country[32];
};
int main()
{
	auto i=10;
	auto str="abc";
	//auto x;//error
	auto c='5';
	
	Hello Mh("Hi");
	//Hello Mx(Mh);
	auto autoHe(Mh);
	auto autoHe2 = Mh;
	struct addr_st a;
	auto autoA = a;	

}	
