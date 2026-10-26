
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char text[100], key[] = "MONARCHY";
    char mat[5][5], used[26] = {0};
    int i, j, k = 0, r1, c1, r2, c2;

    for(i = 0; key[i]; i++) {
        char ch = toupper(key[i]);
        if(ch == 'J') ch = 'I';
        if(!used[ch-'A']) {
            mat[k/5][k%5] = ch;
            used[ch-'A'] = 1;
            k++;
        }
    }

    for(i = 0; i < 26; i++) {
        if(i == 9) continue;
        if(!used[i]) {
            mat[k/5][k%5] = 'A' + i;
            k++;
        }
    }

    printf("Enter uppercase text (even length, no J): ");
    scanf("%99s", text);

    for(i = 0; text[i]; i += 2) {
        for(j = 0; j < 25; j++) {
            if(mat[j/5][j%5] == text[i]) {
                r1 = j/5; c1 = j%5;
            }
            if(mat[j/5][j%5] == text[i+1]) {
                r2 = j/5; c2 = j%5;
            }
        }

        if(r1 == r2) {
            text[i] = mat[r1][(c1+1)%5];
            text[i+1] = mat[r2][(c2+1)%5];
        } else if(c1 == c2) {
            text[i] = mat[(r1+1)%5][c1];
            text[i+1] = mat[(r2+1)%5][c2];
        } else {
            text[i] = mat[r1][c2];
            text[i+1] = mat[r2][c1];
        }
    }

    printf("Cipher text: %s\n", text);
    return 0;
}

