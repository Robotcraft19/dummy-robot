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

Position* getChildren(int** map, int mapsize, Position* posRobot) {
    Position children[4];
    int i = 0;
    int x = posRobot->posX;
    int y = posRobot->posY;
    if (x < 0 || y < 0 || x >= mapsize || y >= mapsize || map[x][y] == 1) {
        return 0;
    } else {
        if (map[x+1][y] != 1) {
            children[i].posX = x + 1;
            children[i].posY = y;
            if (i < 4) i++;
        } 
        if (map[x][y+1] != 1) {
            children[i].posX = x + 1;
            children[i].posY = y;
            if (i < 4) i++;
        }
        if (map[x][y-1] != 1) {
            children[i].posX = x + 1;
            children[i].posY = y;
            if (i < 4) i++;
        }
        if (map[x-1][y] != 1) {
            children[i].posX = x + 1;
            children[i].posY = y;
            if (i < 4) i++;
        }
    }

    Position fixedChildren[i + 1];
    for (int j = 0 ; j < (i+1) ; j++) {
        fixedChildren[j] = children[j];
    }

    return fixedChildren;
    
}

char* shortestPath(int** map, int size, Position* posRobot, Position posEscape) {
}

void robotEscape(int** map, int size, Position* posRobot, char* shortestPath) {

}