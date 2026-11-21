#include <stdio.h>
int main() {
    int p[4] = {10, 12, 5, 8};
    int c[4], iv = 7, i;
    printf("CBC demonstration:\n");
    for (i = 0; i < 4; i++) {
        c[i] = p[i] ^ iv;
        iv = c[i];
        printf("Block %d: %d\n", i + 1, c[i]);
    }
    return 0;
}
