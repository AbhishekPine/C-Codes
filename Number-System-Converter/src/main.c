#include <stdio.h>
#include "../include/converter.h"

int main() {
    int number;

    printf("Enter a decimal number: ");
    scanf("%d", &number);

    printf("\nBinary      : ");
    to_binary(number);
    printf("\nOctal       : ");
    to_octal(number);
    printf("\nHexadecimal : ");
    to_hex(number);
    printf("\n");

    return 0;
}
