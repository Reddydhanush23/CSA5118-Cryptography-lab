#include <stdio.h>

int main() {
    int p = 5, q = 11;
    int n = p * q;
    int phi = (p - 1) * (q - 1);

    int e1 = 3, d1 = 27;
    int e2 = 7, d2 = 23;

    printf("RSA modulus n = %d\n", n);
    printf("Phi(n) = %d\n", phi);

    printf("Old public key = (%d, %d)\n", e1, n);
    printf("Old private key = %d\n", d1);

    printf("New public key = (%d, %d)\n", e2, n);
    printf("New private key = %d\n", d2);

    printf("Warning: Modulus remains unchanged.\n");
    printf("An attacker who knows p and q can calculate new private keys.\n");

    return 0;
}
