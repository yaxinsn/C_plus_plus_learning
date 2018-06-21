#include <iostream>
#include <string>
using namespace std;


class Line
{
public:
	Line(int l);
	Line operator-();
	Line operator-(Line const& t);
	bool operator>(Line const& t);
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

bool Line::operator>(Line const& t)
{
	return this->len > t.len;
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

	cin>>t;
	cout<<t<<endl;	
	return 0;
}
