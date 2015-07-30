#include <stdlib.h>
#include "world.h"

//change the seize of the chuncks and world if you want

/*
 * these methods initlise the world at game start and place  
 * the newly genrated world in to heep mem so i dont cluter the
 * stack
 */
tile * createTile(int x, int y){

	tile *t;
	t = (tile *) malloc(sizeof(tile));

	t->x = x;
	t->y = y; 

	return t; 
}

chunk * createChunk(int cx, int cy){

	chunk *c;
	c = (chunk *) malloc(sizeof(chunk));

	int x, y;

	for(x = 0; x < MAXTILE; x++){
		for(y = 0; y < MAXTILE; y++){
			c->grid[x][y] = createTile(x, y);
		}
	}

	c->x = cx; 
	c->y = cy;

	return c;
}

world * createWorld(){

	world *w;
	w = (world *) malloc(sizeof(world));

	int x, y;

	for(x = 0; x < MAXCHUNK; x++){
		for(y = 0; y < MAXCHUNK; y++){
			w->grid[x][y] = createChunk(x, y);
		}
	}

	w->loadedChunk = w->grid[0][0];
	return w;
}

/*
int setEntity(world *w, int x, int y){
	chunk *c = &w->loadedChunk;
	entity e =  {x, y};

	c->grid[x][y]->e = &e
}
*/