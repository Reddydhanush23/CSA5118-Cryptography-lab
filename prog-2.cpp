#include <stdio.h>
int main() {
    char text[100];
    char key[] = "QWERTYUIOPASDFGHJKLZXCVBNM";
    int i;
    printf("Enter text: ");
    scanf("%s", text);

    for(i = 0; text[i] != '\0'; i++) {
        text[i] = key[text[i] - 'A'];
    }

    printf("Cipher text: %s", text);
    return 0;
}
