#include <stdio.h>

int main() {
    char transactions[6][99] = {"eat", "tea", "tan", "ate", "nat", "bat"};
    int counter[6][6] = {0};
    for (int i = 0; i < 6; i++) {
        for (int l = 0; l < 6; l++) {
            if (i != l) {
                int match_count = 0;
                for (int j = 0; j < 3; j++) {
                    for (int k = 0; k < 3; k++) {
                        if (transactions[i][j] == transactions[l][k]) {
                            match_count++;
                            break;
                        }
                    }
                }
                counter[i][l] = match_count;
            }
        }
    }
    int printed[6] = {0};
    for (int i = 0; i < 6; i++) {
        if (printed[i] == 1) continue;
        printf("%s", transactions[i]);
        printed[i] = 1;
        for (int j = i + 1; j < 6; j++) {
            if (counter[i][j] == 3) {
                printf(", %s", transactions[j]);
                printed[j] = 1;
            }
        }
        printf("\n");
    }
    return 0;
}