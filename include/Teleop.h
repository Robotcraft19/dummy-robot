#ifndef TELEOP_H
#define TELEOP_H

#include "RobotPosition.h"

#define clear()     printf("\033[H\033[J")


int** generateMap(int size);
void printMap(int** map, int size);
Position* placeRobot(int** map, int size);
char getCharacter();
void moveUp   (int** map, int size, Position* posRobot);
void moveDown (int** map, int size, Position* posRobot);
void moveLeft (int** map, int size, Position* posRobot);
void moveRight(int** map, int size, Position* posRobot);
void moveRobot(int** map, int size, Position* posRobot);

#endif

