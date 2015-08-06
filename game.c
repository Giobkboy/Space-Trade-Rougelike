#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <curses.h>

#include "world.h"
#include "entity.h"
#include "game.h"

/**
 * all the act methods for diffreen tyes of entitys
*/

void test_act(world *w, entity *e){
 	turn_entity_obj(e, UP);
 	move_entity_obj(w, e);
 	//printf("ENTITY %d: %d,%d\n", e->index, e->x, e->y);
}

/**
 * main act method calls all the acts based on what type they
 * are
*/
void act(world *w){
	chunk *c = w->loadedChunk;
	int i;

	for(i = 0; i < c->e_index+1; i++){
		if(c->entitys[i] != NULL){
			switch(c->entitys[i]->e){
				case TEST:
					test_act(w, c->entitys[i]);
					break;
				//add cases for other entitys @TODO
			}
		}
	}
}


/*
 * this is the main game loop all game logic gose in here
*/
void gameloop(world *w){
	act(w); 
}

