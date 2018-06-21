#include <iostream>
#include "line.h"
using namespace std;
class Line
{
public:
	Line(int l=9);
	void set_len(int l);
	int get_len();
private:
	int m_len;
};


Line::Line(int l)
{
	m_len = l;
}



void Line::set_len(int l)
{
	m_len = l;
}
int Line::get_len()
{
	return m_len;
}



Line g_line;

void line_set_len(int l)
{
	return g_line.set_len(l);
}
int line_get_len()
{
	return g_line.get_len();
}
