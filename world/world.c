#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "world.h"


//change the seize of the chuncks and world if you want

/*
 * these methods initlise the world at game start and place  
 * the newly genrated world in to heep mem so i dont cluter the
 * stack
 */
tile * create_tile(int x, int y){

	tile *t;
	t = (tile *) malloc(sizeof(tile));

	t->x = x;
	t->y = y; 
	t->e = NULL;

	return t; 
}

chunk * create_chunk(int cx, int cy){

	chunk *c;
	c = (chunk *) malloc(sizeof(chunk));

	int x, y;

	for(x = 0; x < MAXTILE; x++){
		for(y = 0; y < MAXTILE; y++){
			c->grid[x][y] = create_tile(x, y);
		}
	}

	c->x = cx; 
	c->y = cy;
	c->e_index = 0;

	return c;
}

world * create_world(){

	world *w;
	w = (world *) malloc(sizeof(world));

	int x, y;

	for(x = 0; x < MAXCHUNK; x++){
		for(y = 0; y < MAXCHUNK; y++){
			w->grid[x][y] = create_chunk(x, y);
		}
	}

	w->loadedChunk = w->grid[0][0];
	return w;
}


/*
 * these methods alow you to free up the memory
 * when the program is done, realy just a little
 * house keeping, you know 
 */

void deconstruct_chunk(chunk *c){

	int x, y, i;
	for(x = 0; x < MAXTILE; x++){
		for(y = 0; y < MAXTILE; y++){
			free(c->grid[x][y]);
		}
	}

	for(i = 0; i < (MAXTILE*MAXTILE); i++){
		free(c->entitys[i]);
	}

}

void deconstruct_world(world *w){

	int x, y;
	for(x = 0; x < MAXCHUNK; x++){
		for(y = 0; y < MAXCHUNK; y++){
			deconstruct_chunk(w->grid[x][y]);
		}
	}
}

/*
 * this method changes the currnet loaded chunk of the
 * world
 * takes in the cords of the chunk and a world obj
 */
void set_loaded_chunk(world *w, int x, int y){
	w->loadedChunk = w->grid[x][y];
}

/**
* checks to see if the chunks cords are out of bounds
* 
*/
bool is_chunk_outofbounds(int x, int y){
	return (x >= MAXTILE-1 || y >= MAXTILE-1 || x < 0 || y < 0);
}

/**
* if this method loads the next chunk
*/
void load_next_chunk(world *w, entity *player){

 	//grabs the direction of the player
	direction player_direction = player->dir;	
	chunk *current_chunk = w->loadedChunk;

	//all the cords in scope
	int new_x, new_y, new_cx, new_cy;
	
	switch (player_direction){
		case UP:
			//new chunk cords
			new_cx = current_chunk->x;
			new_cy = current_chunk->y + 1;
			
			//where to place player
			new_y = 0;
			new_x = player->x;
			break;
		case DOWN:
			//new chunk cords
			new_cx = current_chunk->x;
			new_cy = current_chunk->y - 1;
			
			//where to place player
			new_y = MAXTILE-1;
			new_x = player->x;
			break;
		case LEFT:
			//new chunk cords
			new_cx = current_chunk->x - 1;
			new_cy = current_chunk->y;

			//where to place player
			new_y = player->y;
			new_x = MAXTILE-1;
			break;
		case RIGHT:
			//new chunk cords
			new_cx = current_chunk->x + 1;
			new_cy = current_chunk->y;
			
			//where to place player
			new_y = player->y;
			new_x = 0;
			break;
	}

	if(!is_chunk_outofbounds(new_cx, new_cy)){
		//loads new chunk
		w->loadedChunk = (chunk *) w->grid[new_cx][new_cy];
		
		current_chunk->entitys[player->index] = NULL;
		current_chunk->grid[player->x][player->y]->e = NULL; 

		w->loadedChunk->entitys[player->index] = player;

		w->loadedChunk->grid[new_x][new_y]->e = player; 
		player->x = new_x;  player->y = new_y;
	}
	
}

/*
 * this method checks to see if two cord of out of bouns
 * if they are it will return true other wise it will reutrn false
 */
bool is_outofbounds(int x, int y){

	if(x >= MAXTILE || y >= MAXTILE){
		return 1; //too high
	}else if(x < 0 || y < 0){
		return 1; //too low
	}

	return 0;
}

/*
* this method checks to see if a tile is occupided by an entity
*/
bool is_occupied(world *w, int x, int y){
	chunk *c = w->loadedChunk;

	if(c->grid[x][y]->e == NULL){
		return 1;
	}
	//printf("occupido\n");
	return 0;
}


/**
* entity contorl methods for contolring the actions of an entity
*/

