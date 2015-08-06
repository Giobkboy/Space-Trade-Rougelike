#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ncurses.h>

#include "world.h"
#include "entity.h"
#include "game.h"
#include "graphics.h"



int main(int n, char *args[]){

	world *w = create_world();
	add_entity(w, 6, 4, TEST);
	add_entity(w, 6, 5, TEST);

    //inits ncurese window
	initscr();

	int i;
	char op; 
	for(i = 0; i < 20; i++){
		//runs game logic
		gameloop(w, op);
		//displays the current chunk
		render_chunk(w);
		refresh();

		//waits the char is set
		op = getch();

		//moves the curser to 0, 0
		move(0, 0);
		
	}

	//kills ncurese
	endwin();
	deconstruct_world(w);

	//printw(test);		/* Print Hello World		  */
	//refresh();			/* Print it on to the real screen */
	//getch();			/* Wait for user input */
		

	//printf("\033[2J\033[;H"); /*clear screen*/
	//printf("but not me\n");
	/*turn_entity(w, 6, 4, RIGHT);
	move_entity(w, 6, 4);

	printf("%d\n", w->loadedChunk->grid[7][4]->e->dir);
	//printf("%d\n", move_entity(w, 6, 4));
	//printf("%d\n", is_occupied(w, 7, 4));
	*/

	
}