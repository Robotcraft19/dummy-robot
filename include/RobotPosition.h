#ifndef ROBOTPOSITION_H
#define ROBOTPOSITION_H


#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct {
    int posX;
    int posY;
} Position;

void PrintPosition(Position *pos);
Position* CreatePosition(int positionX, int positionY);
void DestroyPosition(Position *pos);
float DistancePositions(Position *pos1, Position *pos2);
Position** GenerateArrayOfPositions(int N);
void DestroyArrayOfPositions(Position **pos);
void PrintArray(Position **pos, int size);

#endif