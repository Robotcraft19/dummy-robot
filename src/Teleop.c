#include "Teleop.h"

/**
 * @brief Place the robot at a random FREE space of the map
 * 
 * @param map 
 * @param size 
 * @return Position* 
 */
Position* placeRobot(int **map, int size) {
    Position *posRobot;
    int rand1 = rand() % size;
    int rand2 = rand() % size;
    while (map[rand1][rand2] == 1) {
        rand1 = rand() % size;
        rand2 = rand() % size;
    }
    map[rand1][rand2] = -1;
    posRobot = CreatePosition(rand1, rand2);
    return posRobot;
}

char getCharacter() {
    char c;
    c = getc(stdin);
    return c;
}

void moveUp(int** map, int size, Position* posRobot) {
    int x = posRobot->posX;
    int y = posRobot->posY;
    if ((map[x - 1][y] != 1) && ((x - 1) < size)) {
        posRobot->posX--;
        map[x - 1][y] = -1;
        map[x][y] = 0;
    } else {
        printf("\nYou can't go there !\n");
    }
}

void moveDown(int** map, int size, Position* posRobot) {
    int x = posRobot->posX;
    int y = posRobot->posY;
    if ((map[x + 1][y] != 1) && ((x + 1) < size)) {
        posRobot->posX++;
        map[x + 1][y] = -1;
        map[x][y] = 0;
    } else {
        printf("\nYou can't go there !\n");
    }
}

void moveLeft(int** map, int size, Position* posRobot) {
    int x = posRobot->posX;
    int y = posRobot->posY;
    if ((map[x][y - 1] != 1) && ((y - 1) < size)) {
        posRobot->posY--;
        map[x][y] = 0;
        map[x][y - 1] = -1;
    } else {
        printf("\nYou can't go there !\n");
    }
}

void moveRight(int** map, int size, Position* posRobot) {
    int x = posRobot->posX;
    int y = posRobot->posY;
    if (( map[x][y + 1] != 1 ) && ((y + 1) < size)) {
        posRobot->posY++;
        map[x][y] = 0;
        map[x][y + 1] = -1;
    } else {
        printf("\nYou can't go there !\n");
    }
}

/**
 * @brief Moves the robot until the user wants to quit.
 * 
 * @param map 
 * @param size 
 * @param posRobot 
 */
void moveRobot(int** map, int size, Position* posRobot) {
    printMap(map, size);
    char quit = 'u';
    while (quit != 'y') {
        char command;
        command = getCharacter();
        while(command == '\n') command = getCharacter();
        switch (command) {
            case 'z':
                moveUp(map, size, posRobot);
                break;
            case 'q':
                moveLeft(map, size, posRobot);
                break;
            case 's':
                moveDown(map, size, posRobot);
                break;
            case 'd':
                moveRight(map, size, posRobot);
                break;
            case '\n':
                printf("\nWarning : a funny thing is happening with character entered...\n");
                break;
            default:
                printf("Are you sure you want to quit the game ? y/n\n");
                quit = getCharacter();
                while(quit == '\n') quit = getCharacter();
        }

        printMap(map, size);
    }
}