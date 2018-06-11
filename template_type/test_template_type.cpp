#include <iostream>
#include <stdio.h>
#include <stdlib.h>



using namespace std;

template <typename A>
A mint(A a,A b)
{
	if (a > b)
		return b;
	else
		return a;
}


int main(void)
{

	int a=3,b=4;
	float f=3.123, t=4.567;

	cout<<"min(3,4) : "<<mint(a,b)<<endl;
	cout<<"min(3.123, 4,567 : "<<mint(f,t)<<endl;
	return 0;
}
