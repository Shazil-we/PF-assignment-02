#include <stdio.h>
#include <string.h>
#include <math.h>
int BinaryToDecimal(int number);
int DecimalToBinary(int number);
void DecimalToHexadecimal(int number);
void HexadecimalToDecimal(char hexNumber[]);
void BinaryToHexadecimal(int number);
void HexadecimalToBinary(char hexNumber[]);
int main() {
    int choice, number;
    char hexNumber[20];

    while (1) {
        printf("\nMenu:\n");
        printf("1. Binary to Decimal\n");
        printf("2. Decimal to Binary\n");
        printf("3. Decimal to Hexadecimal\n");
        printf("4. Hexadecimal to Decimal\n");
        printf("5. Binary to Hexadecimal\n");
        printf("6. Hexadecimal to Binary\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a binary number: ");
                scanf("%d", &number);
                printf("Decimal: %d\n", BinaryToDecimal(number));
                break;
            case 2:
                printf("Enter a decimal number: ");
                scanf("%d", &number);
                printf("Binary: %d\n", DecimalToBinary(number));
                break;
            case 3:
                printf("Enter a decimal number: ");
                scanf("%d", &number);
                DecimalToHexadecimal(number);
                break;
            case 4:
                printf("Enter a hexadecimal number: ");
                scanf("%s", hexNumber);
                HexadecimalToDecimal(hexNumber);
                break;
            case 5:
                printf("Enter a binary number: ");
                scanf("%d", &number);
                BinaryToHexadecimal(number);
                break;
            case 6:
                printf("Enter a hexadecimal number: ");
                scanf("%s", hexNumber);
                HexadecimalToBinary(hexNumber);
                break;
            case 7:
                printf("Exiting...\n");
                return 2;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
int BinaryToDecimal(int number) {
    int decimal = 0, base = 1, remainder;
    while (number > 0) {
        remainder = number % 10;
        decimal += remainder * base;
        number /= 10;
        base *= 2;
    }
    return decimal;
}
int DecimalToBinary(int number) {
    int binary = 0, base = 1;
    while (number > 0) {
        int remainder = number % 2;
        binary += remainder * base;
        number /= 2;
        base *= 10;
    }
    return binary;
}
void DecimalToHexadecimal(int number) {
    if (number < 0) {
        printf("Invalid input: negative numbers cannot be converted to hexadecimal.\n");
        return;
    }
    char hex[20];
    int index = 0;
    while (number != 0) {
        int remainder = number % 16;
        if (remainder < 10) {
            hex[index++] = remainder + '0';
        } else {
            hex[index++] = remainder - 10 + 'A';
        }
        number /= 16;
    }
    hex[index] = '\0';
    for (int i = 0; i < index / 2; i++) {
        char temp = hex[i];
        hex[i] = hex[index - i - 1];
        hex[index - i - 1] = temp;
    }

    printf("Hexadecimal: %s\n", hex);
}
void HexadecimalToDecimal(char hexNumber[]) {
    int decimal = 0;
    int length = strlen(hexNumber);
    for (int i = 0; i < length; i++) {
        char digit = hexNumber[length - i - 1];
        if (digit >= '0' && digit <= '9') {
            decimal += (digit - '0') * pow(16, i);
        } else if (digit >= 'A' && digit <= 'F') {
            decimal += (digit - 'A' + 10) * pow(16, i);
        } else {
            printf("Invalid hexadecimal input.\n");
            return;
        }
    }
    printf("Decimal: %d\n", decimal);
}
void BinaryToHexadecimal(int number) {
    int decimal = 0, base = 1, remainder;
    while (number > 0) {
        remainder = number % 10;
        decimal += remainder * base;
        number /= 10;
        base *= 2;
    }
    char hex[20];
    int index = 0;
    while (decimal != 0) {
        int remainder = decimal % 16;
        if (remainder < 10) {
            hex[index++] = remainder + '0';
        } else {
            hex[index++] = remainder - 10 + 'A';
        }
        decimal /= 16;
    }
    hex[index] = '\0';
    for (int i = 0; i < index / 2; i++) {
        char temp = hex[i];
        hex[i] = hex[index - i - 1];
        hex[index - i - 1] = temp;
    }

    printf("Hexadecimal: %s\n", hex);
}
void HexadecimalToBinary(char hexNumber[]) {
    int decimal = 0;
    int length = strlen(hexNumber);
    for (int i = 0; i < length; i++) {
        char digit = hexNumber[length - i - 1];
        if (digit >= '0' && digit <= '9') {
            decimal += (digit - '0') * pow(16, i);
        } else if (digit >= 'A' && digit <= 'F') {
            decimal += (digit - 'A' + 10) * pow(16, i);
        } else {
            printf("Invalid hexadecimal input.\n");
            return;
        }
    }
    if (decimal == 0) {
        printf("Binary: 0\n");
        return;
    }
    char binary[64]; 
    int index = 0;
    while (decimal > 0) {
        binary[index++] = (decimal % 2) + '0';
        decimal /= 2;
    }
    binary[index] = '\0';
    for (int i = 0; i < index / 2; i++) {
        char temp = binary[i];
        binary[i] = binary[index - i - 1];
        binary[index - i - 1] = temp;
    }
    printf("Binary: %s\n", binary);
}
