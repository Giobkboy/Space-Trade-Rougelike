#ifndef ENTITY_H_
#define ENTITY_H_


//methods for minplating entitys
entity * create_entity(int x, int y, entity_type type);
int add_entity(world *w, int x, int y, entity_type type);

void turn_entity(world *w, int x, int y, direction d);
void turn_entity_obj(entity *e, direction d);

int move_entity(world *w, int x, int y);
int move_entity_obj(world *w, entity *e);

#endif //ENTITY_H_