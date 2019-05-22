#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;
class Student{

private:
	~Student(){Destory();};
	Student(){};
	//copy-construct:
	Student(Student& s); 
	
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
	static Student* getInstance(); //C2
	void Destory();
	
	static Student* m_instance; //C1
};
