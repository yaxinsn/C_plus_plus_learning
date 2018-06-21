#include <iostream>
#include <string>
using namespace std;

/*
 *
 *
 * */
class Line
{
public:
	Line(int l);
	Line& operator=(Line const& t);
	Line(Line const& t);
	int operator()(string& );
	int operator()(int );
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
	int Line::operator()(string & name) 
	{
		cout<<"I name is "<<name<<endl;
		return 0;
	}
	int Line::operator()(int age) 
	{
		cout<<"my length is "<<this->len<<endl;
		cout<<"my age is "<<age<<endl;
		return 0;
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

#if 0
	Line t(125);
	t.color="red";
	cout<<t<<endl;
	Line block=t;
	cout<<"block Line: "<<block<<endl;
	block=t;

	cout<<"block Line: "<<block<<endl;
#endif

	Line t(1);
	string name="red_line";
	t(name);
	t(30);
	return 0;
}
