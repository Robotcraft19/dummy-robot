#ifndef TELEOP_H
#define TELEOP_H

#include "RobotPosition.h"

Position* placeRobot(int** map, int size);
char getCharacter();
void moveUp   (int** map, int size, Position* posRobot);
void moveDown (int** map, int size, Position* posRobot);
void moveLeft (int** map, int size, Position* posRobot);
void moveRight(int** map, int size, Position* posRobot);
void moveRobot(int** map, int size, Position* posRobot);

#endif

