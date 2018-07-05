
/*
 *
 *abstract type ‘device’ 抽象类不可以实例成对象。
含有纯虚函数的类叫做抽象类（纯虚类），抽象类是一种特殊的类，它是为了抽象和设计的目的而建立的，它处于继承层次结构的较上层。
 *
 *
 * */


#include <iostream>




using namespace std;


class device
{
public:
	virtual void show_info() = 0;
//	virtual void show_info() const = 0;
private:
	char name[32];
	char type[32];
};

class usb: public device
{
public:
	virtual	void show_info()
//	virtual	void show_info() const
	{
		cout<<"usb device"<<endl;
	}

};


int main(void)
{
//	class device dev;  抽象类不可以实例化
	class usb u;

	u.show_info();	
}
