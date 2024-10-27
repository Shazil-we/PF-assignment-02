#include <stdio.h>
int matchsticks_to_win(int N) {
    if (N % 5 == 0) {
        return -1;
    } else {
        return N % 5;
    }
}
int main() {
    int N;
    printf("Enter the number of matchsticks: ");
    scanf("%d", &N);

    int result = matchsticks_to_win(N);

    if (result == -1) {
        printf("It's impossible for Player A to guarantee a win.\n");
    } else {
        printf("Player A should pick %d matchstick(s) on the first turn to guarantee a win.\n", result);
    }

    return 0;
}
