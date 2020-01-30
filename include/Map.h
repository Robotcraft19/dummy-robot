#ifndef map_h
#define map_h

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define clear()     printf("\033[H\033[J")

int** generateMap(int size);
void printMap(int** map, int size);
int** list_available_nodes(int** map, int size);

#endif