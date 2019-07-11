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

	char* hello = 0;//A1 类对象成员变量的默认值; 
public:
	~Hello();
	Hello(const char* h);
	Hello(const char* h,const char* j);
	Hello(std::initializer_list<char*>);//B1 初始值列
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
	cout <<__func__<<endl;

}
Hello::Hello(const char* h,const char* j)
{
	hello=strdup(h);
	cout <<__func__<<":" <<__LINE__<<" Hello(char* h,char* j)"<<endl;

}
Hello::Hello(std::initializer_list<char*> vals)
{
	char* x=(char*)vals.begin();
	hello=strdup(x);
	cout <<__func__<<":" <<__LINE__<<" Hello(std::initializer_list<const char*>)"<<endl;
}
#endif

#if 1
Hello::~Hello()
{
	if(this->hello)
		free(this->hello);
}

#endif

int main()
{
	int a{0};
	int b(0);
//	int c{0.3}; error 不可窄化
	int d(0.3);

	Hello H1("H1","H1");
	Hello H2{"H2","H2"}; //使用初始值列initializer_list
	Hello H3{"H2","H2","XX"}; //使用初始值列initializer_list
	return 0;
}	
