#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "Singleton.h"
using namespace std;

/*  
单例模式：
C1 getInstance 和m_instance必是static变量，
C2 m_instance必被明确的初始化。
C3 构造函数与拷贝构造函数，析构函数 全是private，可以只声明。
C4 需要有明确的Destory函数
C5 需要在线程安全。
*/

Singleton* Singleton::getInstance()
{
	if(m_instance == NULL) //如果真的空的话，再会加锁，再去完成原子的操作。
	{
		pthread_mutex_lock(&m_mutex); //互斥锁
		if(m_instance == NULL)
		{
			m_instance = new Singleton;
		}
		pthread_mutex_unlock(&m_mutex); //互斥锁
	}
	return m_instance;
}
void Singleton::Destory()
{
	delete this;
}
void Singleton::set_name(char* new_name)
{
	m_name=new_name;
	//m_id=9;//A1 m_id是不可以再被修改的。

}
Singleton* Singleton::m_instance = NULL; //C1 C2
pthread_mutex_t Singleton::m_mutex = PTHREAD_MUTEX_INITIALIZER;