
#include <stdio.h>
#include <ctype.h>

char m[5][6] = {
    "MFHIK", "UNOPQ", "ZVWXY", "ELARG", "DSTBC"
};

void encrypt(char a, char b) {
    int i, j, r1=0, c1=0, r2=0, c2=0;

    if(a == 'J') a = 'I';
    if(b == 'J') b = 'I';

    for(i = 0; i < 5; i++)
        for(j = 0; j < 5; j++) {
            if(m[i][j] == a) r1=i, c1=j;
            if(m[i][j] == b) r2=i, c2=j;
        }

    if(r1 == r2)
        printf("%c%c", m[r1][(c1+1)%5],
                       m[r2][(c2+1)%5]);
    else if(c1 == c2)
        printf("%c%c", m[(r1+1)%5][c1],
                       m[(r2+1)%5][c2]);
    else
        printf("%c%c", m[r1][c2], m[r2][c1]);
}

int main() {
    char text[200], s[200];
    int i, n = 0;

    printf("Enter message: ");
    fgets(text, sizeof(text), stdin);

    for(i = 0; text[i]; i++)
        if(isalpha((unsigned char)text[i])) {
            char ch = toupper((unsigned char)text[i]);
            s[n++] = (ch == 'J') ? 'I' : ch;
        }

    s[n] = '\0';

    printf("Cipher text: ");

    for(i = 0; i < n;) {
        char a = s[i], b;

        if(i + 1 == n || s[i] == s[i+1]) {
            b = 'X';
            i++;
        } else {
            b = s[i+1];
            i += 2;
        }

        encrypt(a, b);
        printf(" ");
    }

    printf("\n");
    return 0;
}

