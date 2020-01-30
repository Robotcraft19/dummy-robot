#include "Map.h"

int n_available = 0;

/**
 * @brief 
 * 
 * @param color 
 * @param printNumb 
 */
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


/**
 * @brief 
 * 
 * @param size 
 * @return int** 
 */
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
                    if ((i2 == (size - 2)) && (j2 == (size - 2))) { 
                        map[i2][j2] = 2;
                        n_available++;
                    }
                } else {
                    map[i2][j2] = 0;
                    n_available++;
                }
            } else
            {
                map[i2][j2] = 1;
            }
        }
    }

    return map;
}


/**
 * @brief 
 * 
 * @param map 
 * @param size 
 */
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
                case(2):
                    printColor('b', "█");
            }
        }
        printf("%c", '\n');
    }
}


int** list_available_nodes(int** map, int size) {
    // List available nodes
}