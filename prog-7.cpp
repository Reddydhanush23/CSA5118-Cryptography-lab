#include <stdio.h>
int main() {
    char text[2000];
    printf("Enter ciphertext:\n");
    fgets(text, sizeof(text), stdin);
    printf("Ciphertext received:\n%s", text);
    return 0;
}

