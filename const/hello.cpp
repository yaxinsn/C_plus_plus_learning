#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
/*
 * 
 * A1 const 修饰一个类中成员变量，则此变量必要用初始化列表来进行初始化。
 * A2 const 修饰一个类中成员函数，则表示此成员函数不会修改类中所有成员变量。
 * A3 const 修饰一个函数入参的引用时，表示此引用的内容不得在此函数中发生变化。
 * 
 *
 *
 * */
class Student{

	string m_name;
	const int m_id; //A1
	int m_score;
public:
	int show_info(void) const 
	{
		cout  <<"name "<< m_name << ", id " << m_id<<endl;
	//	m_score=90; //A2 此处会有编译错误，原因就是show_info 被const来修饰了。
		return 0;
	}
	// 所以在class体以外定义的方法（函数）都必须在class体内进行声明。
	void set_name(char* new_name);
	~Student();
	Student():m_id(999){};
	Student(const char* h);
	Student(const Student &obj); //A3
};
Student::Student(const Student &obj):m_id(888)
{
	cout <<"call copy constructor "<<endl;
	m_name = obj.m_name;
}
#if 1
Student::Student(const char* h):m_id(777)
{
	m_name=h;

}
#endif

#if 1
Student::~Student()
{
}

void Student::set_name(char* new_name)
{
	m_name=new_name;
	//m_id=9;//A1 m_id是不可以再被修改的。

}
#endif


int main()
{
	Student A1;
	A1.set_name("A1");
	A1.show_info();
	Student A2("abl");
	A2.show_info();
	
		
	Student A3(A2);
	A3.show_info();

	return 0;
}	
