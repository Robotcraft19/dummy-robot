#include "MazeEscape.h"

Position findEscape(int** map, int size) {
    Position posEscape;
    for (int i = 0 ; i < size ; ++i) {
        for (int j = 0 ; i < size ; ++j) {
            if ( (i == 0) || (j == 0) || (i == (size - 1)) || (j == (size - 1))) {
                if (map[i][j] == 2) {
                    posEscape.posX = i;
                    posEscape.posY = j;
                    return posEscape;
                }
            }
        }
    }
}

char* shortestPath(int** map, int size, Position* posRobot, Position posEscape) {
}

void robotEscape(int** map, int size, Position* posRobot, char* shortestPath) {

}

/**
 * @brief Moves the robot until the user wants to quit.
 * 
 * @param map 
 * @param size 
 * @param posRobot 
 */
void moveRobot(int** map, int size, Position* posRobot, Position escapePosition) {
    printMap(map, size);
    char quit = 'u';
    while (1) {
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
            PrintPosition(posRobot);
            PrintPosition(&escapePosition);
            if ((posRobot->posX == escapePosition.posX) && (posRobot->posY == escapePosition.posY)) {
                break;
            }
            printMap(map, size);
        }

        if ((posRobot->posX == escapePosition.posX) && (posRobot->posY == escapePosition.posY)) {
            printf("\n You found the exit !\n");
            break;
        }

        if (quit == 'y') {
            clear();
            printf("\n You abandonned the game !\n");
            break;
        }

    }


}