
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char p[100], c[100], target[100];
    int k[100], n = 0, i;

    printf("Enter plaintext: ");
    scanf("%99s", p);

    printf("Enter key numbers: ");
    for (i = 0; i < (int)strlen(p); i++)
        scanf("%d", &k[i]);

    n = strlen(p);

    for (i = 0; i < n; i++)
        c[i] = (p[i] - 'A' + k[i]) % 26 + 'A';

    c[n] = '\0';
    printf("Ciphertext: %s\n", c);

    printf("Enter target plaintext: ");
    scanf("%99s", target);

    printf("New key numbers: ");
    for (i = 0; i < n; i++)
        printf("%d ", (c[i] - target[i] + 26) % 26);

    printf("\n");
    return 0;
}

