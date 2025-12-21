#include "contact.h"

int main(void)
{
	Contact con;
	if (InitContact(&con) != 0)
		return 1;
	DestoryContact(&con);
	return 0;
}
