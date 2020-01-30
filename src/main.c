#include "Teleop.h"
#include "Map.h"

int main() {
    /*int x1, y1, x2, y2;
    Position* pos1;
    Position* pos2;
    Position** posArray;
    float distance;
    int sizeofArray;

    printf("\nEnter X1 postion : ");
    scanf("%d", &x1);
    printf("\nEnter Y1 postion : ");
    scanf("%d", &y1);
    printf("\nEnter X2 postion : ");
    scanf("%d", &x2);
    printf("\nEnter Y2 postion : ");
    scanf("%d", &y2);

    pos1 = CreatePosition(x1, y1);
    pos2 = CreatePosition(x2, y2);

    distance = DistancePositions(pos1, pos2);

    printf("\nDistance between POS1 and POS2 is : %f %c", distance, '\n');


    printf("\nEnter size of generated array : ");
    scanf("%d", &sizeofArray);
    posArray = GenerateArrayOfPositions(sizeofArray);

    PrintArray(posArray, sizeofArray);

    DestroyArrayOfPositions(posArray);

    //PrintArray(posArray, sizeofArray);

    printf("\n Array of random positions has been DESTROYED.\n");
    */
    /********************/

    int **map;
    int mapDimensions;
    char quit = 'm';
    
    Position *robotPosition;

    printf("\nEnter map dimensions (square map) : ");
    scanf("%d", &mapDimensions);
    map = generateMap(mapDimensions);
    robotPosition = placeRobot(map, mapDimensions);
    moveRobot(map, mapDimensions, robotPosition);

    return 0;
}