#ifndef MAZEESCAPE_H
#define MAZEESCAPE_H

#include "Teleop.h"
#include "time.h"

Position findEscape(int** map, int size);
char* shortestPath(int** map, int size, Position *posRobot, Position posEscape);
void robotEscape(int** map, int size, Position *posRobot, char* shortestPath);
void moveRobotAutonomous(int** map, int size, Position *posRobot, Position posEscape);
Position* getChildren(int** map, int mapsize, Position* posRobot);


#endif //MAZEESCAPE_H

