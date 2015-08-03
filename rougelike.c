#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "world.h"
#include "entity.h"



int main(int n, char *args[]){

	world *w = create_world();
	add_entity(w, 6, 4, TEST);

	turn_entity(w, 6, 4, RIGHT);
	move_entity(w, 6, 4);

	printf("%d\n", w->loadedChunk->grid[7][4]->e->dir);
	//printf("%d\n", move_entity(w, 6, 4));
	//printf("%d\n", is_occupied(w, 7, 4));


	deconstruct_world(w);

}