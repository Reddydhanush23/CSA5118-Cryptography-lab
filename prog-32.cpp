#include <stdio.h>

int main() {
    int message = 25;
    int dsaK1 = 7, dsaK2 = 11;

    int dsaSig1 = (message * dsaK1) % 101;
    int dsaSig2 = (message * dsaK2) % 101;

    int rsaSignature1 = 77;
    int rsaSignature2 = 77;

    printf("Message = %d\n", message);

    printf("DSA signature 1 = %d\n", dsaSig1);
    printf("DSA signature 2 = %d\n", dsaSig2);

    printf("RSA signature 1 = %d\n", rsaSignature1);
    printf("RSA signature 2 = %d\n", rsaSignature2);

    return 0;
}
