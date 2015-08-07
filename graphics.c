#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ncurses.h>

#include "world.h"
#include "entity.h"
#include "game.h"
#include "graphics.h"


void render_status(chunk *c){
	printw("============================================================\n");
	int i;
	printw("Chunk: %d, %d | ", c->x, c->y);
	for(i = 0; i < c->e_index; i++){
		printw("Entity %d: %d,%d; ", i, c->entitys[i]->x, c->entitys[i]->y);
	}

}

void render_chunk(world *w){
	chunk *c = w->loadedChunk;

	int x, y;
	for(y = 0; y < MAXTILE; y++){

		char grid_line[MAXTILE+1];
		for(x = 0; x < MAXTILE; x++){

			if(!is_occupied(w, x, y)){
				//entiy *e = c->grid[x][y]->e;   //@TODO add spcal chars for stuff
				grid_line[x] = (char) c->grid[x][y]->e->e;
			}else{
				grid_line[x] = ' ';
			}
		}

		//grid_line[MAXTILE] = '';
		printw(grid_line);
		printw("\n");
	}	
	render_status(c);

}