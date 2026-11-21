#include <stdio.h>

int main() {
    int p[] = {1, 2, 4};
    int key[] = {5, 7, 3};
    int c[3], d[3];
    int i;

    printf("CTR Encryption:\n");

    for (i = 0; i < 3; i++) {
        c[i] = p[i] ^ key[i];
        printf("%08d ", c[i]);
    }

    printf("\nCTR Decryption:\n");

    for (i = 0; i < 3; i++) {
        d[i] = c[i] ^ key[i];
        printf("%08d ", d[i]);
    }

    printf("\n");
    return 0;
}
