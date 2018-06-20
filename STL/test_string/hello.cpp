#include <iostream>
#include <string>

using namespace std;

#if 1 
string add_str(const string& a,const string& b)
{
	string ret=a+b;
	return ret;
	
}
#endif

int main()
{
	string a="abc";
	string b="bcd";
	cout<<"a "<<a<<endl;
	string a1(a);
	cout<<"a1 "<<a1<<endl;


	string cin1;
	cin>>cin1;
	cout<<"cin1:: "<<cin1<<endl;

	cout<<"b empty :"<< b.empty()<<endl;
	cout<<"b size :"<< b.size()<<endl;
	b=b+cin1;
	
	cout<<"b : "<<b<<endl;
        b=b+"end;";
	cout<<"b : "<<b<<endl;
	
	cout<< "add_str(abc,123): " <<add_str(a,cin1)<<endl;
	cout<< "add_str(abc,123): " <<add_str("abc ","123")<<endl;

return 0;


}
