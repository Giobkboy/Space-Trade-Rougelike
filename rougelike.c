#include <stdio.h>
#include <stdlib.h>

#include "world.h"
#include "entity.h"



int main(int n, char *args[]){

	world *w = create_world();
	add_entity(w, 6, 4, TEST);
	turn_entity(w, 6, 4, RIGHT);

	printf("%d\n", w->grid[0][0]->grid[6][4]->e->dir);



	deconstruct_world(w);

}