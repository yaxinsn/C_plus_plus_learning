#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Singleton.h"


int main()
{
	Singleton::getInstance()->set_name("abc");
	Singleton::getInstance()->show_info();
	return 0;
}	
