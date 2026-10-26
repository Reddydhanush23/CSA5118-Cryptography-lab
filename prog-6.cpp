
#include <stdio.h>

int main() {
    char text[100];
    int i, p;

    printf("Enter ciphertext: ");
    scanf("%99s", text);

    for(i = 0; text[i]; i++) {
        p = (9 * (text[i] - 'A' - 15 + 26)) % 26;
        text[i] = p + 'A';
    }

    printf("Plaintext: %s\n", text);
    return 0;
}

