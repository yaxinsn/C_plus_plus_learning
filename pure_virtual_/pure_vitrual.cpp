
/*
 *
 *abstract type ‘device’ 抽象类不可以实例成对象。
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
