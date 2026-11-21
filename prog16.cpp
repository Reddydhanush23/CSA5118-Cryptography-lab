#include <stdio.h>
#include <string.h>
int main() {
    char text[500];
    int freq[26] = {0}, i;
    char english[] = "ETAOINSHRDLCUMWFGYPBVKJXQZ";
    printf("Enter ciphertext: ");
    fgets(text, sizeof(text), stdin);
    for (i = 0; text[i]; i++)
        if (text[i] >= 'A' && text[i] <= 'Z')
            freq[text[i] - 'A']++;
    printf("Letter frequencies:\n");
    for (i = 0; i < 26; i++)
        printf("%c = %d\n", 'A' + i, freq[i]);
    printf("\nUse frequency order: %s\n", english);
    printf("Frequency analysis gives clues, not guaranteed plaintext.\n");
    return 0;
}
