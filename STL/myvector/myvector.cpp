#include <iostream>
using namespace ::std;


template <class T>
class myvector{
public:
	void push_back(T const& elem);
	myvector(int size);
	T pop_head();
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
	this->m_size = size;
	this->m_head = 0;
	this->m_end = 0;
}

template <class T>
void myvector<T>::push_back(T const& elem)
{
	m_entry[m_end] = elem;
	//m_size++;
	m_end++;
}
template <class T>
int myvector<T>::size()
{
	return m_end-m_head;
}

template <class T>
T myvector<T>::pop_head()
{
	if(m_end - m_head >0)
	{
		m_size--;
		return m_entry[m_head++];
	}
	else
	{
		throw "vector is empty";
	}
}

int main()
{
	myvector<int> t(20);
	t.push_back(5);
	t.push_back(6);
	t.push_back(7);

	cout<<"size: "<<t.size()<<endl;
	int p=t.pop_head();
	cout<<"pop return :"<<p<<endl;
try{	
	cout<<"size: "<<t.size()<<endl;
	t.pop_head();
	cout<<"size: "<<t.size()<<endl;
	t.pop_head();
	cout<<"size: "<<t.size()<<endl;
	t.pop_head();
	cout<<"size: "<<t.size()<<endl;
}
catch(char const* msg)
{
	cout<<msg<<endl;
}

	return 0;
}
