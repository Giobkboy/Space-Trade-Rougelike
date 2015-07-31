#include <stdlib.h> 

#include "entity.h"
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
