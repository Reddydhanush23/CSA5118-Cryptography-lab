
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char text[200], p[200], c[200];
    int i, j = 0, a, b, x, y;

    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);

    for (i = 0; text[i] != '\0'; i++) {
        if (isalpha((unsigned char)text[i]))
            p[j++] = toupper((unsigned char)text[i]);
    }

    if (j % 2 != 0)
        p[j++] = 'X';

    p[j] = '\0';

    for (i = 0; i < j; i += 2) {
        a = p[i] - 'A';
        b = p[i + 1] - 'A';

        x = (9 * a + 4 * b) % 26;
        y = (5 * a + 7 * b) % 26;

        c[i] = x + 'A';
        c[i + 1] = y + 'A';
    }

    c[j] = '\0';

    printf("Ciphertext: ");
    for (i = 0; i < j; i += 2)
        printf("%c%c ", c[i], c[i + 1]);

    printf("\n");
    return 0;
}

