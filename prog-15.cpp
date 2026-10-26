
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char cipher[500], plain[500];
    int key, i, j, top = 10;
    double score[26];
    char results[26][500];
    int order[26];

    printf("Enter ciphertext (no spaces): ");
    scanf("%499s", cipher);

    for (key = 0; key < 26; key++) {
        score[key] = 0;

        for (i = 0; cipher[i] != '\0'; i++) {
            char ch = toupper((unsigned char)cipher[i]);

            if (ch >= 'A' && ch <= 'Z') {
                plain[i] = (ch - 'A' - key + 26) % 26 + 'A';

                if (plain[i] == 'E') score[key] += 12.7;
                if (plain[i] == 'T') score[key] += 9.1;
                if (plain[i] == 'A') score[key] += 8.2;
                if (plain[i] == 'O') score[key] += 7.5;
                if (plain[i] == 'I') score[key] += 7.0;
                if (plain[i] == 'N') score[key] += 6.7;
                if (plain[i] == 'S') score[key] += 6.3;
                if (plain[i] == 'H') score[key] += 6.1;
                if (plain[i] == 'R') score[key] += 6.0;
            }
        }

        plain[i] = '\0';
        strcpy(results[key], plain);
        order[key] = key;
    }

    for (i = 0; i < 26; i++)
        for (j = i + 1; j < 26; j++)
            if (score[order[j]] > score[order[i]]) {
                int temp = order[i];
                order[i] = order[j];
                order[j] = temp;
            }

    printf("\nTop %d possible plaintexts:\n", top);

    for (i = 0; i < top; i++)
        printf("Key %2d: %s\n",
               order[i], results[order[i]]);

    return 0;
}

