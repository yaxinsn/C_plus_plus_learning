

#include <iostream>
#include <string.h>
using namespace std;
/*
 *  学习友元函数，友元类。
 *
 * 
 *
 *
 * */
class Box{


	int length;
	int width;
	int highth;
	
	void __show_info()
	{
		cout<<"length:"<<length<<endl;
		cout<<"width:"<<width<<endl;
		cout<<"highth:"<<highth<<endl;
	}
public:
	void set_length(int len)
	{
		length = len;
	}
	void show_info()
	{
		__show_info();
		cout<<"volume is "<<volume()<<endl;
	}
	int volume()
	{
		return length*width*highth;
	}
	Box(int l,int w, int h)
	{
		length = l;
		width = w;
		highth = h;
	}	
	Box(Box &b)
	{
		length = b.length;
		width = b.width;
		highth = b.highth;
	}
	//友元函数
	friend void print_box(Box b);
};

void print_box(Box b)
{
	b.show_info();
}


int main()
{
	Box b1(2,3,4);
	print_box(b1);
}	
