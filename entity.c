#include <stdlib.h> 

#include "world.h"
#include "entity.h"

entity * create_entity(int x, int y, entity_type type){
	
	entity *e;
	e = (entity *) malloc(sizeof(entity));

	e->x = x;
	e->y = y;
	//by defalt all entitys are faceing up
	e->dir = UP;
	e->e = type;

	return e; 
}

int add_entity(world *w, int x, int y, entity_type type){

	chunk *c = w->loadedChunk;
	entity *new_e = create_entity(x, y, type);

	if(c->grid[x][y]->e == NULL){
		c->grid[x][y]->e = new_e;
		new_e->index = c->e_index;
		c->entitys[c->e_index] = new_e; 
		c->e_index++;
	}else{
		return -1;
	}
	return 0;
}

void turn_entity(world *w, int x, int y, direction d){
	chunk *c = w->loadedChunk;
	c->grid[x][y]->e->dir = d;
}

/*int move_entity(world *w, int x, int y){

	chunk *c = w->loadedChunk;
	entity *e = c->grid[x][y]->e;


}*/

