#include <stdio.h>

int mod26(int x) {
    return (x % 26 + 26) % 26;
}

int main() {
    int P[2][2] = {{1, 0}, {0, 1}};
    int C[2][2] = {{9, 4}, {5, 7}};
    int det, inv, i, j, K[2][2];

    det = mod26(P[0][0]*P[1][1] - P[0][1]*P[1][0]);

    for (inv = 1; inv < 26; inv++)
        if (mod26(det * inv) == 1)
            break;

    if (inv == 26) {
        printf("Plaintext matrix is not invertible.\n");
        return 0;
    }

    int I[2][2] = {
        {mod26(P[1][1]*inv), mod26(-P[0][1]*inv)},
        {mod26(-P[1][0]*inv), mod26(P[0][0]*inv)}
    };

    for (i = 0; i < 2; i++)
        for (j = 0; j < 2; j++)
            K[i][j] = mod26(C[i][0]*I[0][j] + C[i][1]*I[1][j]);

    printf("Recovered Hill key matrix:\n");

    for (i = 0; i < 2; i++)
        printf("%d %d\n", K[i][0], K[i][1]);

    return 0;
}
