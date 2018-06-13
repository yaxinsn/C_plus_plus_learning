#include <iostream>

/*
 * Animal 与Dog之间没有虚函数 
 * Animal Fish有一个eating的虚函数
 *  通过"基类的指针" 访问 子类(们)的成员函数。这叫动态多态。是用虚函数的技术完成的。这也叫动态绑定。]
 *  当我们使用基类的引用（或指针）调用一个虚函数时将发生动态绑定（dynamic binding） 因为我们直到运行时才能知道到底调用了哪个版本的虚函数，可能是基类中的版本也可能是派生类中的版本，判断的依据是引用（或指针）所绑 定的对象的真实类型。
 *  与非虚函数在编译时绑定不同，虚函数是在运行时选择函数的版本，所以动态绑定也叫运行时绑定（run-time binding）。
 *
 *
 * */
using namespace::std;


class Animal
{
public:
	void moving()
	{
		cout<<"animal can moving!"<<endl;
	}
	virtual void eating() //虚函数。
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
	return 0;
}
