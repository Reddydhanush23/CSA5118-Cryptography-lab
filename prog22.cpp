#include <stdio.h>
int main() {
    int p[4] = {1, 2, 3, 4};
    int c[4], d[4];
    int key = 10, iv = 7, prev;
    int i;
    prev = iv;
    for (i = 0; i < 4; i++) {
        c[i] = (p[i] ^ prev) ^ key;
        prev = c[i];
    }
    printf("Ciphertext: ");
    for (i = 0; i < 4; i++)
        printf("%d ", c[i]);
    prev = iv;
    for (i = 0; i < 4; i++) {
        d[i] = (c[i] ^ key) ^ prev;
        prev = c[i];
    }
    printf("\nDecrypted: ");
    for (i = 0; i < 4; i++)
        printf("%d ", d[i]);
    printf("\n");
    return 0;
}
