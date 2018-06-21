#include <stdio.h>
#include "line.h"


int main()
{
	int t;
	t = line_get_len();
	line_set_len(2);
	
	t = line_get_len();
	printf(" t =%d \n ",t);

	return 0;
}
