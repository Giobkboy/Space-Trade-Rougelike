#include <stdlib.h> 
#include <stdbool.h>
#include <stdio.h>

#include "world.h"

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
		
		if(type == PLAYER){
			c->entitys[(MAXTILE*MAXTILE) - 2] = new_e;
			new_e->index = (MAXTILE*MAXTILE) - 2;
		}else{
			new_e->index = c->e_index;
			c->entitys[c->e_index] = new_e; 
			c->e_index++;
		}
	}else{
		return -1;
	}
	return 0;
}

/**
 * this method turns the entity in a given direction
 */
void turn_entity(world *w, int x, int y, direction d){
	chunk *c = w->loadedChunk;
	c->grid[x][y]->e->dir = d;
}

/**
 * turns entiyt in given direction given a pointer
 */
void turn_entity_obj(entity *e, direction d){
	e->dir = d; 
}


/*
* this method moves an entity
* the x and y valuse are that of the current location of
* of the entity
* 
* the enity moves in the driection it is faceing
*/

int move_entity(world *w, int x, int y){

	chunk *c = w->loadedChunk;
	entity *e = c->grid[x][y]->e;

	int new_x, new_y;

	switch (e->dir){
		case UP:
			new_x = e->x;
			new_y = e->y + 1;
			break;
		case DOWN:
			new_x = e->x; 
			new_y = e->y - 1;
			break;
		case RIGHT:
			new_x = e->x + 1;
			new_y = e->y; 
			break;
		case LEFT:
			new_x = e->x - 1;
			new_y = e->y;
			break; 		
	}

	if(is_outofbounds(new_x, new_y)){
		return -1; //out of bounds
	}else if(!is_occupied(w, new_x, new_y)){
		return -2; //space occupide
	}

	c->grid[new_x][new_y]->e = e;
	e->x = new_x;
	e->y = new_y;

	c->grid[x][y]->e = NULL;
	return 0;
}

int move_entity_obj(world *w, entity *e){
	return move_entity(w, e->x, e->y);
}

