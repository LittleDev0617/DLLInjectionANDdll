#include <stdio.h>

int main()
{
	system("title TEST");
	
	int a = 1000;
	
	while(getch() == 'n')
	{
		printf("%p : %d\n",&a,a);
	}
	return 0;
}
