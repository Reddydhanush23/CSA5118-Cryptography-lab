#include <stdio.h>

int main() {
    int p = 4;
    int e = 3;
    int n = 55;
    int c = 1;
    int i;

    for (i = 0; i < e; i++)
        c = (c * p) % n;

    printf("Plaintext character value = %d\n", p);
    printf("Public exponent = %d\n", e);
    printf("Modulus = %d\n", n);
    printf("Encrypted value = %d\n", c);

    printf("Individual-character RSA is deterministic.\n");
    printf("An attacker can encrypt all 26 letters and build a lookup table.\n");

    return 0;
}
