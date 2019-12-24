#include "Teleop.h"

void printColor(char color, char* printNumb) {
    switch(color) {
        case('r'):
            printf("\033[1;31m");
            printf("%s", printNumb);
            printf("\033[0m");
            break;
        case('b'):
            printf("\033[1;34m");
            printf("%s", printNumb);
            printf("\033[0m");
            break;
        case('y'):
            printf("\033[0;33m");
            printf("%s", printNumb);
            printf("\033[0m");
            break;

    }
}

int **generateMap(int size)
{
    int **map = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++)
        map[i] = (int *)malloc(size * sizeof(int));

    for (int i2 = 0; i2 < size; i2++) {
        for (int j2 = 0; j2 < size; j2++) {
            int wallornot = rand() % 101;
            if (wallornot > 20) {
                if ((i2 == 0) || (j2 == 0) || (i2 == (size - 1)) || (j2 == (size - 1))) {
                    map[i2][j2] = 1;
                } else {
                    map[i2][j2] = 0;
                }
            } else
            {
                map[i2][j2] = 1;
            }
        }
    }

    return map;
}

void printMap(int **map, int size) {
    clear();
    for (int i3 = 0; i3 < size; i3++) {
        for (int j3 = 0; j3 < size; j3++) {
            switch(map[i3][j3]) {
                case(0):
                    printColor('b', ".");
                    break;
                case(1):
                    printColor('r', "█");
                    break;
                case(-1):
                    printColor('y', "¤");
                    break;
            }
        }
        printf("%c", '\n');
    }
}

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