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
	//entity 	*entitys[100];
} chunk;

typedef struct {
	chunk 	*grid[MAXCHUNK][MAXCHUNK];
	chunk 	*loadedChunk; 

} world;

tile * createTile(int x, int y);
chunk * createChunk(int x, int y);
world * createWorld();

//int setEntity(int x, int y);

#endif //WORLD_H_