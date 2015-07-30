#ifndef WORLD_H_
#define WORLD_H_

#define UP 		0;
#define RIGHT 	1;
#define DOWN 	2;
#define LEFT	3;

static int const MAXTILE = 10;
static int const MAXCHUNK = 10;

typedef struct {
	int x, y;

} player;

typedef struct
{
	int x, y;

} entity;

typedef struct {
	int		 x, y;
	entity 	 *e;
} tile;

typedef struct {
	int 	x, y;
	tile 	*grid[MAXTILE][MAXTILE];
	entity 	*entitys[MAXTILE*MAXTILE];
} chunk;

typedef struct {
	chunk 	*grid[MAXCHUNK][MAXCHUNK];
	chunk 	*loadedChunk; 

} world;

tile * create_tile(int x, int y);
chunk * create_chunk(int x, int y);
world * create_world();
void deconstruct_chunk(chunk *c);
void deconstruct_world(world *w);

//int setEntity(int x, int y);

#endif //WORLD_H_