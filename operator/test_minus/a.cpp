#include <iostream>
using namespace std;


class Line
{
public:
	Line(int l);
	Line operator-();
	Line operator-(Line const& t);

	int len;
	void show(void)
	{
		cout <<"len : "<<len<<endl;
	}

};

Line::Line(int l=99)
{
	this->len = l;
	cout<<"Line constructor: len "<<len<<endl;
}

Line Line::operator-()
{
	Line l(2);
	l.len=-this->len;
	len=-len; //修改自己的值；这包应该删除 
	return l;
}

Line Line::operator-(Line const& t)
{
	Line l(3);
	l.len=this->len-t.len;
	return l;
}

int main()
{
	Line line(40);
	//line.show();
	cout<<"line : "<<line.len<<endl;
	Line line2=-line;

	cout<<"line2 : "<<line2.len<<endl;
//	line.show();
//	line2.show();	

	Line t;
	cout<<"t: "<<t.len<<endl;
	Line t2=t-line;
	cout<<"t2: "<<t2.len<<endl;
	return 0;
}
