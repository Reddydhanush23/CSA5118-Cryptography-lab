#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char text[200], cipher[200], decrypted[200];
    int key[200], n, i;

    printf("Enter plaintext: ");
    scanf("%199s", text);

    n = strlen(text);

    printf("Enter %d key values (0-25): ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &key[i]);

    for (i = 0; i < n; i++) {
        if (!isalpha((unsigned char)text[i]) ||
            key[i] < 0 || key[i] > 25) {
            printf("Invalid input.\n");
            return 0;
        }

        cipher[i] = (toupper(text[i]) - 'A' + key[i]) % 26 + 'A';
        decrypted[i] = (cipher[i] - 'A' - key[i] + 26) % 26 + 'A';
    }

    cipher[n] = '\0';
    decrypted[n] = '\0';

    printf("Ciphertext: %s\n", cipher);
    printf("Decrypted text: %s\n", decrypted);

    return 0;
}
