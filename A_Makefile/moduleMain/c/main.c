#include <stdio.h>  
#include "moduleC.h"  

int main(int arg, char **agv)  
{
	printf("Begin ====== I Am MAin ======\n");
	printf("↓↓↓↓↓↓ I Call ModuleC ↓↓↓↓↓↓\n");
	module_c();
	printf("↑↑↑↑↑↑ I Call ModuleC ↑↑↑↑↑↑\n");
	printf("End   ====== I Am MAin ======\n");

    return 0;
}
