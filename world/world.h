#ifndef WORLD_H_
#define WORLD_H_

//for world and chunk size
static int const MAXTILE = 50;
static int const MAXCHUNK = 10;

//all fo the carnal directions
typedef enum {
	UP, 
	DOWN, 
	LEFT, 
	RIGHT
} direction;

//all the diffrent types of entitys
typedef enum {
	TEST = 'T',
	PLAYER = '@'
} entity_type;	


//entity struct
typedef struct
{
	int x, y, index;
	direction dir;
	entity_type e;

} entity;


//all fo the world structs
typedef struct {
	int		 x, y;
	entity 	 *e;
} tile;

typedef struct {
	int 	x, y, e_index;
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

//methods for interacting with the world
void set_loaded_chunk(world *w, int x, int y);
void load_next_chunk(world *w, entity *player);
bool is_chunk_outofbounds(int x, int y);
bool is_outofbounds(int x, int y);
bool is_occupied(world *w, int x, int y);

//methods for minplating entitys
entity * create_entity(int x, int y, entity_type type);
int add_entity(world *w, int x, int y, entity_type type);

void turn_entity(world *w, int x, int y, direction d);
void turn_entity_obj(entity *e, direction d);

int move_entity(world *w, int x, int y);
int move_entity_obj(world *w, entity *e);



#endif //WORLD_H_