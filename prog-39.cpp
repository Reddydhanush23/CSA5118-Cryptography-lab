#include <stdio.h>
#include <ctype.h>
#include <string.h>

double english[26] = {
    8.167,1.492,2.782,4.253,12.702,2.228,
    2.015,6.094,6.966,0.153,0.772,4.025,
    2.406,6.749,7.507,1.929,0.095,5.987,
    6.327,9.056,2.758,0.978,2.360,0.150,
    1.974,0.074
};

int main() {
    char text[1000], output[26][1000];
    double score[26];
    int shift, i, j, n = 0;

    printf("Enter ciphertext: ");
    fgets(text, sizeof(text), stdin);

    for (shift = 0; shift < 26; shift++) {
        int freq[26] = {0};
        int total = 0;
        score[shift] = 0;

        for (i = 0; text[i]; i++) {
            if (isalpha((unsigned char)text[i])) {
                int c = (toupper(text[i]) - 'A' - shift + 26) % 26;
                output[shift][i] = c + 'A';
                freq[c]++;
                total++;
            } else {
                output[shift][i] = text[i];
            }
        }

        output[shift][i] = '\0';

        for (j = 0; j < 26; j++) {
            double observed = total ? 100.0 * freq[j] / total : 0;
            double diff = observed - english[j];
            score[shift] += diff * diff / (english[j] + 0.01);
        }
    }

    printf("\nTop 10 possible plaintexts:\n");

    for (n = 0; n < 10; n++) {
        int best = -1;

        for (shift = 0; shift < 26; shift++)
            if (score[shift] >= 0 &&
                (best == -1 || score[shift] < score[best]))
                best = shift;

        if (best == -1) break;

        printf("%d. Shift %d: %s", n + 1, best, output[best]);
        score[best] = -1;
    }

    return 0;
}
