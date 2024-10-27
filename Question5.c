#include <stdio.h>

int maxfinder(int count, int arr[count]) {
    int max = 0;
    for (int i = 0; i < count; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void horizontal(int count, int arr[count]) {
    printf("\n\n\t\t\t\tHORIZONTAL HISTOGRAM:\n");
    for (int i = 0; i < count; i++) {
        printf("Value %d: ", i + 1);
        for (int j = 0; j < arr[i]; j++) {
            printf("*");
        }
        printf("\n");
    }
}

void vertical(int count, int arr[count], int max) {
    printf("\n\n\t\t\tVERTICAL HISTOGRAM:\n");
    for (int i = max; i >= 0; i--) {
        for (int j = 0; j < count; j++) {
          if(i==0){
            printf("%d " , arr[j]);
          }else{
            if (arr[j] >= i) {
                printf("* ");
            } else {
                printf("  "); 
            }
          }
        }
        printf("\n");
    }
}
int main() {
    int count, max;
    int input[100];
    printf("Enter the size of the array: ");
    scanf("%d", &count);
    for (int i = 0; i < count; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &input[i]);
    }
    max = maxfinder(count, input);
    horizontal(count, input);
    vertical(count, input, max);
    return 0; 
}
