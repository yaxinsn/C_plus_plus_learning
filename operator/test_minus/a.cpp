#include <iostream>
using namespace std;


class Line
{
public:
	Line(int len);
	Line operator-();

	void show(void)
	{
		cout <<"len : "<<len<<endl;
	}
private:
	int len;

};

Line::Line(int len)
{
	this->len = len;
	cout<<"Line constructor: len "<<len<<endl;
}

Line Line::operator-()
{
	Line l(2);
	l.len=-this->len;
	len=-len; //修改自己的值；这包应该删除 
	return l;
}


int main()
{
	Line line(40);
	//cout<<"line : "<<line.len<<endl;
	line.show();
	Line line2=-line;

	line.show();
	line2.show();	
	return 0;
}
