#include <iostream>
#include <string.h>
#include <stdio.h>
#include <pthread.h>

using namespace std;
class Singleton{

private:
	~Singleton(){Destory();};
	Singleton(){};
	//copy-construct:
	Singleton(Singleton& s); 
	
	string m_name;
	int m_id; //A1
	int m_score;
public:
	int show_info_no_const(void) 
	{
		cout  <<"no const function: name "<< m_name << ", id " << m_id<<endl;
		return 0;
	}
	int show_info(void) const 
	{
		cout  <<"name "<< m_name << ", id " << m_id<<endl;
	//	m_score=90; //A2 此处会有编译错误，原因就是show_info 被const来修饰了。
		return 0;
	}
	void set_name(char* new_name);
	static Singleton* getInstance(); //C2
	void Destory();
	
	static Singleton* m_instance; //C1
	 
	static pthread_mutex_t m_mutex;
};
