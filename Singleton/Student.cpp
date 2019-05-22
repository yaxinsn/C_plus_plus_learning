#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Student.h"
using namespace std;

/*  
单例模式：
C1 getInstance 和m_instance必是static变量，
C2 m_instance必被明确的初始化。
C3 构造函数与拷贝构造函数，析构函数 全是private，可以只声明。
C4 需要有明确的Destory函数
C5 需要在线程安全。
*/

Student* Student::getInstance()
{
	if(m_instance == NULL)
	{
		m_instance = new Student;
	}
	return m_instance;
}
void Student::Destory()
{
	delete this;
}
void Student::set_name(char* new_name)
{
	m_name=new_name;
	//m_id=9;//A1 m_id是不可以再被修改的。

}
Student* Student::m_instance = NULL; //C1 C2