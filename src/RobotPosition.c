#include "RobotPosition.h"

/**
 * @brief Print the position of the robot.
 * 
 * @param pos 
 */
void PrintPosition(Position *pos) {
    printf("\n Robot Position : x = %d , y = %d \n", pos->posX, pos->posY);
}

/**
 * @brief Create a Position object
 * 
 * @param positionX 
 * @param positionY 
 * @return Position* 
 */
Position* CreatePosition(int positionX, int positionY) {
    Position *posRobot;
    posRobot = (Position*) malloc (sizeof(Position));
    posRobot->posX = positionX;
    posRobot->posY = positionY;
    return posRobot;
}

/**
 * @brief Destroy a position object
 * 
 */
void DestroyPosition(Position *pos) {
    free(pos);
}

/**
 * @brief calculate distance between to positions
 * 
 * @param pos1 
 * @param pos2 
 * @return float 
 */
float DistancePositions(Position *pos1, Position *pos2) {
    float resDistance;
    double posPow1 = pow((pos2->posX - pos1->posX), 2);
    double posPow2 = pow((pos2->posY - pos1->posY), 2);
    resDistance = sqrt( posPow1 + posPow2 );
    return resDistance;
}

/**
 * @brief Generate an Array of positions
 * 
 * @param N 
 * @return Position** 
 */
Position** GenerateArrayOfPositions(int N) {
    Position** RobPosArray;
    RobPosArray = (Position**) malloc ( N * sizeof(Position));
    for (int i = 0 ; i < N ; ++i) {
        RobPosArray[i] = CreatePosition((rand() % 11), (rand() % 11));
    }
    return RobPosArray;
}

/**
 * @brief Print an array of positions
 * 
 * @param pos 
 * @param size 
 */
void PrintArray(Position **pos, int size) {
    printf("| ");
    for (int i = 0 ; i < size ; ++i) {
        printf("( ");
        printf("%d", pos[i]->posX);
        printf(" ; ");
        printf("%d", pos[i]->posY);
        printf(" )");
        printf(" | ");
        printf("%c", '\n');
    }
    printf("%c", '\n');
}

/**
 * @brief Destroys an Array of positions
 * 
 * @param pos 
 */
void DestroyArrayOfPositions(Position **pos) {
    free(pos);
}
