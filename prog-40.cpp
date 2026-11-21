#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char text[1000], result[1000];
    char english[] = "ETAOINSHRDLCUMWFGYPBVKJXQZ";
    int freq[26] = {0};
    int used[26] = {0};
    int i, j, max, letter, rank[26], count = 0;

    printf("Enter ciphertext: ");
    fgets(text, sizeof(text), stdin);

    for (i = 0; text[i]; i++)
        if (isalpha((unsigned char)text[i]))
            freq[toupper(text[i]) - 'A']++;

    for (i = 0; i < 26; i++) {
        max = -1;
        letter = -1;

        for (j = 0; j < 26; j++)
            if (!used[j] && freq[j] > max) {
                max = freq[j];
                letter = j;
            }

        if (letter == -1) break;

        used[letter] = 1;
        rank[letter] = count++;
    }

    for (i = 0; text[i]; i++) {
        if (isalpha((unsigned char)text[i])) {
            int x = toupper(text[i]) - 'A';
            char c = english[rank[x]];
            result[i] = islower((unsigned char)text[i])
                      ? tolower(c) : c;
        } else {
            result[i] = text[i];
        }
    }

    result[i] = '\0';

    printf("Possible plaintext: %s", result);
    printf("\nFrequency mapping:\n");

    for (i = 0; i < 26; i++)
        if (freq[i] > 0)
            printf("%c -> %c\n", 'A' + i, english[rank[i]]);

    return 0;
}
