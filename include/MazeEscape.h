#ifndef MAZEESCAPE_H
#define MAZEESCAPE_H

#include "Teleop.h"
#include "time.h"

Position findEscape(int** map, int size);
char* shortestPath(int** map, int size, Position *posRobot, Position posEscape);
void robotEscape(int** map, int size, Position *posRobot, char* shortestPath);
void moveRobot(int** map, int size, Position *posRobot, Position posEscape);


#endif //MAZEESCAPE_H

