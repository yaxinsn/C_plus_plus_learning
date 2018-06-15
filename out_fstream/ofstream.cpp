#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;


class my_file
{
public:
void	open(char* name);
void	write(char* buf,int len);
void	close();
private:
	char* name;
	ofstream handle;
};

void my_file::open(char* name)
{
	if(!this->name)
		this->name=strdup(name);
	this->handle.open(name,ios::out);
}

void my_file::write(char* buf,int len)
{
	this->handle<<buf<<endl;
}
void my_file::close()
{
	this->handle.close();
}
int main(void)
{
	class my_file a;
	char b[30]="123455667";
	a.open("./a.txt");
	a.write(b,100);
	a.close();
}
