#include <stdio.h>
int main() {
    int shifts[16] = {
        1, 1, 2, 2, 2, 2, 2, 2,
        1, 2, 2, 2, 2, 2, 2, 1
    };
    int i;
    for (i = 0; i < 16; i++)
        printf("Round %2d: Shift %d bit(s)\n",
               i + 1, shifts[i]);
    return 0;
}
