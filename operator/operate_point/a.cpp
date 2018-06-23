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

	cout<<"line : len  "<<mp->len<<endl;
	return 0;
}
