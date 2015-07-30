#ifndef WORLD_H_
#define WORLD_H_

//for world and chunk size
static int const MAXTILE = 10;
static int const MAXCHUNK = 10;

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

//methods for createing the world
tile * create_tile(int x, int y);
chunk * create_chunk(int x, int y);
world * create_world();

//methods for distorying the world (HA HA HA HA >:D)
void deconstruct_chunk(chunk *c);
void deconstruct_world(world *w);

//int setEntity(int x, int y);

#endif //WORLD_H_