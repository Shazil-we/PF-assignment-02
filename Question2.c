#include <stdio.h>
#include <string.h>

int main() {
    char slogans[3][60] = {
        "buy now",
        "save big",
        "limited offer"
    };
    
    int numSlogans = 3;
    int frequency[256]; 

    for (int j = 0; j < numSlogans; j++) {
        for (int k = 0; k < 256; k++) {
            frequency[k] = 0; 
        }
        for (int i = 0; slogans[j][i] != '\0'; i++) {
            frequency[(unsigned char)slogans[j][i]]++;
        }
        printf("For \"%s\": {", slogans[j]);
        for (int i = 0; i < 256; i++) {
            if (frequency[i] > 0) {
                printf("'%c': %d", i, frequency[i]);
                if (i < 255) {
                    printf(", ");
                }
            }
        }
        printf("}\n");
    }
    return 0;
}