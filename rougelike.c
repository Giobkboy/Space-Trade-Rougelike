#include <stdio.h>
#include <stdlib.h>

//#include "entity.h"
#include "world.h"



int main(int n, char *args[]){

	chunk *c = createChunk(5, 6);
	printf("%d\n", c->grid[6][4]->x);

	free(c);

	
}