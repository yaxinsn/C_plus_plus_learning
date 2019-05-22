#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Student.h"


int main()
{
	Student::getInstance()->set_name("abc");
	Student::getInstance()->show_info();
	return 0;
}	
