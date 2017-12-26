#include <iostream>
#include <string.h>
using namespace std;
/*
 *  学习了简单的构造函数与析构函数。带参数的构造函数
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
};
Hello::Hello(const char* h)
{
	hello=strdup(h);

}
#if 1
Hello::~Hello()
{
	if(hello)
		free(hello);
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
}	
