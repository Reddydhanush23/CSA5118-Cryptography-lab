#include <stdio.h>
#include <string.h>
#include <ctype.h>

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    char text[100];
    int a, b, i;

    printf("Enter plaintext: ");
    scanf("%99s", text);

    printf("Enter a and b: ");
    scanf("%d%d", &a, &b);

    a = (a % 26 + 26) % 26;
    b = (b % 26 + 26) % 26;

    if (gcd(a, 26) != 1) {
        printf("Invalid key: encryption is not one-to-one.\n");
        return 0;
    }

    for (i = 0; text[i]; i++)
        text[i] = (a * (toupper(text[i]) - 'A') + b) % 26 + 'A';

    printf("Ciphertext: %s\n", text);
    return 0;
}
