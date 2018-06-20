#include <iostream>
using namespace ::std;


template <class T>
class myvector{
public:
	void push_back(T const& elem);
	myvector(int size);
	int size();
	
	
private:
	T* m_entry;
	int m_size;
	int m_head;
	int m_end;

};

template <class T>
myvector<T>::myvector(int size)
{
	m_entry=new T[size];
	this->m_size = 0;
}

template <class T>
void myvector<T>::push_back(T const& elem)
{
	m_entry[m_size] = elem;
	m_size++;
}
template <class T>
int myvector<T>::size()
{
	return m_size;
}

template <class T>
T myvector<T>::pop()
{
	return m_entry[
}

int main()
{
	myvector<int> t(20);
	t.push_back(5);
	t.push_back(5);
	t.push_back(5);

	cout<<"size: "<<t.size()<<endl;
	return 0;
}
