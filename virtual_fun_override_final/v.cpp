#include <iostream>

/*
 * override 在子类里明确表示要覆盖基类里的虚函数。
 * final 定义在基类里，明确表示基类不可继承，函数不可被覆盖。
 * 编译器会进行检查，并进行报错。
 * */
using namespace::std;


class Animal
{
public:
	void moving()
	{
		cout<<"animal can moving!"<<endl;
	}
	virtual void eating() final //虚函数。
	{
		cout<<"animal must eat something!"<<endl;
	}

};

class DOG: public Animal
{
public:
	void moving()
	{
		cout<<"dog move fast!"<<endl;
	}	
};



class Fish: public Animal
{
public:
	void eating()
	{
		cout<<"fish eat in the water"<<endl;
	}	
};

/*
 * 由于moving不是虚函数，所以p->moving，使用了animal里的 moving
 * */
void test_moving(class Animal *p)
{
	p->moving();
}
/*
 * eating在基类中是一个虚函数，所以test_eating的入参是animal类型，但在程序运行过程中 “动态地”找到真正的数据类型，并调用真正的方法函数。
 * 这也是多态的一种方式。
 *
 * */
void test_eating(class Animal* p)
{
	p->eating();
}


void test_eating_moving(class Animal& p)
{
	p.eating();
	p.moving();
}
int main(void)
{
	class DOG dog;
	class Animal a;
	class Fish fish;
	dog.moving();
	a.moving();
	cout<<"dog is test_moving"<<endl;
	test_moving(&dog);
	cout<<"fish test eating"<<endl;
	test_eating(&fish);
	cout<<"----------------"<<endl;
	test_eating_moving(dog);
	test_eating_moving(fish);

	cout <<"----------------sizeof(dog),sizeof(animal)and sizeof(fish)"<<endl;

	cout<<"dog size:"<<sizeof(dog)<<endl;
	cout<<"animal size:"<<sizeof(a)<<endl;
	cout<<"class Fish size:"<<sizeof(class Fish)<<endl;
	cout <<"size=8, this is a virtial_function_table 's size, this table has only function point. so is 8"<<endl;
	return 0;
}
