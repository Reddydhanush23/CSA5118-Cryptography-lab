
#include <stdio.h>
#include <string.h>

int main() {
    char text[100], key[100];
    int i, j = 0;

    printf("Enter plaintext: ");
    scanf("%99s", text);

    printf("Enter key: ");
    scanf("%99s", key);

    for(i = 0; text[i]; i++) {
        text[i] = (text[i] - 'A' +
                   key[j] - 'A') % 26 + 'A';
        j++;
        if(key[j] == '\0')
            j = 0;
    }

    printf("Cipher text: %s\n", text);
    return 0;
}

