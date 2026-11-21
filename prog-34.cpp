#include <stdio.h>
#include <string.h>

int main() {
    char data[100], padded[200];
    int i, len, blockSize = 8, pad;

    printf("Enter binary plaintext: ");
    scanf("%99s", data);

    len = strlen(data);

    if (len == 0) {
        printf("Plaintext cannot be empty.\n");
        return 0;
    }

    strcpy(padded, data);

    pad = blockSize - (len % blockSize);
    if (pad == 0)
        pad = blockSize;

    padded[len] = '1';

    for (i = 1; i < pad; i++)
        padded[len + i] = '0';

    padded[len + pad] = '\0';

    printf("Original length: %d\n", len);
    printf("Padded plaintext: %s\n", padded);
    printf("Padded length: %d\n", (int)strlen(padded));

    return 0;
}
