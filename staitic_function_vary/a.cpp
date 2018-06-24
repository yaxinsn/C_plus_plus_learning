#include <iostream>

using namespace::std;

class Line{
private:
/*
 * ISO C++ forbids in-class initialization of non-const static member ‘Line::count’
 *   static int count=9;
	static int count=9;
*/
	static int count;
	int len;
public:
	static int pub_count;
	static void show_count();
	Line();
	~Line();

};
//这里是对类里静态变量的定义，类里只是声明。
int Line::count=0;
int Line::pub_count=0;
Line::Line()
{
	len=9;
	count++;
	pub_count++;
}
void Line::show_count()
{
	cout<<"static count "<<count<<endl;
	cout<<"public static count "<<pub_count<<endl;
/*
 *invalid use of member ‘Line::len’ in static member function
  int len;
静态函数里，不能使用类里的非静态变量。
静态函数只能使用类里的静态变量。
	cout<<"private len "<<len<<endl;
 * */

}
Line::~Line()
{
	count--;
	pub_count--;
}

int main(void)
{
	Line a;
	Line b;
	a.show_count();

	cout<<"class Line pub count: "<<Line::pub_count<<endl;
	return 0;
}
