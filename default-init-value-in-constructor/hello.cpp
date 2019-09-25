#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
/*
 *  类的构造函数 1 参数的默认值；2 使用参数把类成员进行初始化
 *  
 * 
 *
 *
 * */
class Line{

public:
//	Line();
	Line(int l);
	~Line(){};
#if 0
Line(int l = 0):m_length(l)
{
	cout<<"AAA "<<m_length<<endl;
}
#endif
private:
	int m_length;
};
#if 1
Line::Line(int l = 0):m_length(l)
{
	cout<<"AAA "<<m_length<<endl;
}
#endif
int main()
{
	Line a;
	Line b(99);
	return 2;
}	
