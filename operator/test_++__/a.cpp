#include <iostream>
using namespace std;


class Line
{
public:
	Line(int l);
	Line(const Line& T);
	Line & operator--();//perfix
	Line operator--(int);//postfix

	int len;
	void show(void)
	{
		cout <<"len : "<<len<<endl;
	}

};

Line::Line(const Line &T )
{

	this->len = T.len;
	cout<<"Line copy constructor: len "<<len<<endl;
}
Line::Line(int l=99)
{
	this->len = l;
	cout<<"Line constructor: len "<<len<<endl;
}

Line & Line::operator--()
{
	--this->len; //前减量。
	return *this;
}

Line Line::operator--(int)
{
	Line t;
	t.len=this->len;
	this->len--;//postfix 后减量。
	return t;
}

int main()
{
	Line line(40);
	Line line2;
	line2=line--;
	cout<<"line : "<<line.len<<endl;
	cout<<"line2 : "<<line2.len<<endl;
	Line line3=--line;
	cout<<"line : "<<line.len<<endl;
	cout<<"line3 : "<<line3.len<<endl;

	return 0;
}
