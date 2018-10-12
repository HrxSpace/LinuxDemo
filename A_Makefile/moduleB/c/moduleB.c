#include <stdio.h>
#include "moduleA.h" 
#include "moduleB.h"

void module_b()
{
    printf("Begin ===== I Am ModuleB =====\n");
	printf("↓↓ I Call ModuleA ↓↓\n");
	module_a();
	printf("↑↑ I Call ModuleA ↑↑\n");
	printf("End   ===== I Am ModuleB =====\n");
}
