#ifndef ENTITY_H_
#define ENTITY_H_

//cardnal directions
typedef enum {
	UP, 
	DOWN, 
	LEFT, 
	RIGHT
} direction;

typedef enum {
	TEST
} entity_type;

typedef struct {
	int x, y;
	direction dir;
} player;

typedef struct
{
	int x, y;
	direction dir;
	entity_type e;

} entity;

entity * create_entity(int x, int y, entity_type type);

#endif //ENTITY_H_