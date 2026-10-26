
#include <stdio.h>

int main() {
    int a, b, c, d, i;
    int p1[] = {7, 4, 11, 15};
    int q1[] = {7, 8, 0, 19};

    printf("Possible matching keys:\n");

    for (a = 0; a < 26; a++)
    for (b = 0; b < 26; b++)
    for (c = 0; c < 26; c++)
    for (d = 0; d < 26; d++) {
        int ok = 1;

        for (i = 0; i < 4; i += 2) {
            int x = (a * p1[i] + b * p1[i+1]) % 26;
            int y = (c * p1[i] + d * p1[i+1]) % 26;

            if (x != q1[i] || y != q1[i+1]) {
                ok = 0;
                break;
            }
        }

        if (ok)
            printf("%d %d / %d %d\n", a, b, c, d);
    }

    return 0;
}

