
#include <stdio.h>

int main() {
    char text[100];
    int a, b, i, p;

    printf("Enter uppercase text: ");
    scanf("%99s", text);

    printf("Enter a and b: ");
    scanf("%d%d", &a, &b);

    for(i = 0; text[i]; i++) {
        p = text[i] - 'A';
        text[i] = (a * p + b) % 26 + 'A';
    }

    printf("Cipher text: %s\n", text);
    return 0;
}

