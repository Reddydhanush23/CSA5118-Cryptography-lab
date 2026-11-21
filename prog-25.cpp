#include <stdio.h>

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int n = 55;
    int plaintext = 15;
    int factor = gcd(n, plaintext);

    printf("RSA modulus n = %d\n", n);
    printf("Plaintext block = %d\n", plaintext);
    printf("GCD(n, plaintext) = %d\n", factor);

    if (factor > 1 && factor < n) {
        printf("Factor found: %d\n", factor);
        printf("Other factor: %d\n", n / factor);
        printf("RSA modulus is factored.\n");
    } else {
        printf("No non-trivial factor found.\n");
    }

    return 0;
}
