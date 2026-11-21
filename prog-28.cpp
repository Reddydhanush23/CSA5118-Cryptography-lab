#include <stdio.h>

long long power(int a, int b, int mod) {
    long long result = 1;
    while (b > 0) {
        result = (result * a) % mod;
        b--;
    }
    return result;
}

int main() {
    int q = 23, a = 5;
    int x = 6, y = 15;
    long long A, B, keyA, keyB;

    A = power(a, x, q);
    B = power(a, y, q);

    keyA = power(B, x, q);
    keyB = power(A, y, q);

    printf("Alice public value = %lld\n", A);
    printf("Bob public value = %lld\n", B);
    printf("Alice shared key = %lld\n", keyA);
    printf("Bob shared key = %lld\n", keyB);

    return 0;
}
