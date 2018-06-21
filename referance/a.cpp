#include <iostream>
using namespace std;


/*
 * 把局部变量的引用当个返回值返回，这是不正确的。
 *  reference to local variable ‘a’ returned 
 * */
int& func( int b)
{
	int a = b;
	return a;
}
int max(int a, int b)
{
	return a>b?a:b;
}

int main()
{
	int b=9;
	int c=func(b);
	int d[20]={0};
	int e=max(10,20);
	cout<<"c : "<<c<<endl;
	return 0;
}
