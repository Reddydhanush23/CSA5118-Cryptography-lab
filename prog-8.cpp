#include <stdio.h>
int main() {
    char text[100];
    char key[] = "CIPHERABDFGJKLMNOQSTUVWXYZ";
    int i;
    printf("Enter uppercase text: ");
    scanf("%99s", text);
    for(i = 0; text[i]; i++)
        text[i] = key[text[i] - 'A'];
    printf("Cipher text: %s\n", text);
    return 0;
}

