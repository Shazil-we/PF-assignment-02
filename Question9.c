#include <stdio.h>

int moveup(int coordX, int coordY, char upchar);
int movedown(int coordX, int coordY, char downchar);
int moveleft(int coordX, int coordY, char leftchar);
int moveright(int coordX, int coordY, char rightchar);

int main() {
    char grid[5][5] = {
        {' ', ' ', 'I', 'X', 'I'},
        {' ', 'X', ' ', ' ', ' '},
        {'I', ' ', 'X', 'X', ' '},
        {' ', ' ', ' ', 'I', 'X'},
        {' ', 'X', ' ', ' ', 'P'}
    };
    int PlayerX = 4, PlayerY = 4;
    char input;
    printf("\t\t\t\t\tADVENTURE GAME\n\n");
    while (1) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                if (j == PlayerX && k == PlayerY) {
                    printf(" \"P\" ");
                } else {
                    printf(" \"%c\" ", grid[j][k]);
                }
            }
            printf("\n");
        }
        printf("Enter your move:\nW for Up\nS for Down\nA for Left\nD for Right\nQ for Quit: ");
        scanf(" %c", &input);
        char upchar = grid[PlayerX - 1][PlayerY];
        char downchar = grid[PlayerX + 1][PlayerY];
        char leftchar = grid[PlayerX][PlayerY - 1];
        char rightchar = grid[PlayerX][PlayerY + 1];
        if (input == 'W' || input == 'w') {
            if (moveup(PlayerX, PlayerY, upchar)) {
                grid[PlayerX][PlayerY] = ' ';
                PlayerX--;
            }
        } else if (input == 'S' || input == 's') {
            if (movedown(PlayerX, PlayerY, downchar)) {
                grid[PlayerX][PlayerY] = ' ';
                PlayerX++;
            }
        } else if (input == 'A' || input == 'a') {
            if (moveleft(PlayerX, PlayerY, leftchar)) {
                grid[PlayerX][PlayerY] = ' ';
                PlayerY--;
            }
        } else if (input == 'D' || input == 'd') {
            if (moveright(PlayerX, PlayerY, rightchar)) {
                grid[PlayerX][PlayerY] = ' ';
                PlayerY++;
            }
        } else if (input == 'Q' || input == 'q') {
            printf("Quitting Program...........\n");
            return 0;
        } else {
            printf("\nInvalid input!!!\n");
        }
    }
}
int moveup(int coordX, int coordY, char upchar) {
    if (upchar == 'X' || coordX == 0) {
        printf("\nCannot move up!!\n");
        return 0;
    } else if(upchar == 'I'){
      printf("\nYou collected an Item!!\n");
      return 1;
    }else{
        return 1;
    }
}
int movedown(int coordX, int coordY, char downchar) {
    if (downchar == 'X' || coordX == 4) {
        printf("\nCannot move down!!\n");
        return 0;
    } else if(downchar == 'I'){
      printf("\nYou collected an Item!!\n");
      return 1;
    }else {
        return 1;
    }
}
int moveleft(int coordX, int coordY, char leftchar) {
    if (leftchar == 'X' || coordY == 0) {
        printf("\nCannot move left!!\n");
        return 0;
    } else if(leftchar == 'I'){
      printf("\nYou collected an Item!!\n");
      return 1;
    }else {
        return 1;
    }
}
int moveright(int coordX, int coordY, char rightchar) {
    if (rightchar == 'X' || coordY == 4) {
        printf("\nCannot move right!!\n");
        return 0;
    } else if(rightchar == 'I'){
      printf("\nYou collected an Item!!\n");
      return 1;
    }else {
        return 1;
    }
}