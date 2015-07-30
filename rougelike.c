#include <stdio.h>
#include <stdlib.h>

//#include "entity.h"
#include "world.h"



int main(int n, char *args[]){

	world *w = create_world();
	printf("%d\n", w->grid[6][4]->x);

	free(w);

	
}