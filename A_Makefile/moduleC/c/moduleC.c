#include <stdio.h>
#include "moduleC.h" 
#include "moduleB.h"

void module_c()
{
    printf("Begin === I Am ModuleC ===\n");
	printf("↓↓↓↓ I Call ModuleB ↓↓↓↓\n");
	module_b();
	printf("↑↑↑↑ I Call ModuleB ↑↑↑↑\n");
	printf("End   === I Am ModuleC ===\n");
}
