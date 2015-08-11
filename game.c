#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <curses.h>

#include "world.h"
//#include "entity.h"
#include "game.h"

/**
 * all the act methods for diffreen tyes of entitys
*/

void test_act(world *w, entity *e){
 	turn_entity_obj(e, UP);
 	move_entity_obj(w, e);
 	//printf("ENTITY %d: %d,%d\n", e->index, e->x, e->y);
}

void player_act(world *w, entity *e, char op){
	
	int can_move = 0;
	direction dir;

	switch (op){
		case 's':
			dir = UP;
			break;
		case 'w':
			dir = DOWN;
			break;
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		default:
			can_move = 1;
			break;

	}
	int err_code = 0;
	if(can_move == 0){
		turn_entity_obj(e, dir);
		err_code = move_entity_obj(w, e);
	}

	if(err_code == -1){
		load_next_chunk(w, e);
	}
}

/**
 * main act method calls all the acts based on what type they
 * are
*/
void act(world *w, char op){
	chunk *c = w->loadedChunk;
	int i;

	for(i = 0; i < (MAXTILE*MAXTILE); i++){
		if(c->entitys[i] != NULL){
			//when you add a new type of enityt you add it to this swich statment
			switch(c->entitys[i]->e){
				case TEST:
					test_act(w, c->entitys[i]);
					break;
				case PLAYER:
					player_act(w, c->entitys[i], op);
					break;
				//add cases for other entitys @TODO
			}
		}
	}
}


/*
 * this is the main game loop all game logic gose in here
*/
void gameloop(world *w, char op){
	act(w, op); 
}

