#include <iostream>

using namespace std;


class Line{

public:
	Line(int l)
	{
		len=l;
	}
	void show()
	{
		cout<<"Len : "<<len<<endl;
	}

//private:
	int len;

};


class mypoint{
	public:
		Line *p;
	Line *operator->()
	{
		return p;
	}
};


int main(void)
{
	Line t(9);
	mypoint mp;
	mp.p=&t;
	//这里的mp只是一个对象，不是一个指针。但可以使用mp->len。
	cout<<"line : len  "<<mp->len<<endl;
	return 0;
}
