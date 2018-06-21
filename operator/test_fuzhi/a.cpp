#include <iostream>
#include <string>
using namespace std;

/*
 *
 * 拷贝构造函数使用已有的对象创建一个新的对象，赋值运算符是将一个对象的值复制给另一个已存在的对象。区分是调用拷贝构造函数还是赋值运算符，主要是否有新的对象产生。
 *
 * */
class Line
{
public:
	Line(int l);
	Line& operator=(Line const& t);
	Line(Line const& t);
	friend ostream &operator<<(ostream &output,Line &t);
	friend istream &operator>>(istream &input,Line &t);
	int len;
	string color;
	void show(void)
	{
		cout <<"len : "<<len<<endl;
		cout <<"color : "<<color<<endl;
	}

};

Line::Line(int l=99)
{
	this->len = l;
	cout<<"Line constructor: len "<<len<<endl;
}
Line::Line(Line const& t)
{
       this->len = t.len;
	this->color="block"; 
	cout << "Copy Constructor" << endl; 
}
Line& Line::operator=(Line const& t)
{
	this->len = t.len;
	this->color = t.color;
	cout << "Assign" << endl;
	return *this;
}

ostream &operator<<(ostream &output,Line &t)
{
	output<<"len: "<<t.len<<endl;
	output<<"color: "<<t.color<<endl;
	return output;
}
istream &operator>>(istream &input,Line &t)
{
	input>>t.len;
	input>>t.color;
	return input;
}
int main()
{
#if 0
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

	Line big(21);
	Line small(20);
	if(big>small)
	{
		cout<<"big > small "<<endl;
	}
#endif
	Line t(125);
	t.color="red";
	cout<<t<<endl;
	Line block=t;
	cout<<"block Line: "<<block<<endl;
	block=t;

	cout<<"block Line: "<<block<<endl;

	return 0;
}
