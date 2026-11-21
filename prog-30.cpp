#include <stdio.h>

int main() {
    int X = 25;
    int T = 12;

    int secondBlock = X ^ T;
    int finalInput = secondBlock ^ T;

    printf("Message block X = %d\n", X);
    printf("One-block MAC T = %d\n", T);
    printf("Second block (X XOR T) = %d\n", secondBlock);
    printf("Final CBC input = %d\n", finalInput);

    if (finalInput == X)
        printf("CBC-MAC result is the same as MAC(X).\n");

    return 0;
}
