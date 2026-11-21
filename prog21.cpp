#include <stdio.h>
#include <string.h>
int main() {
    char data[100];
    int i, len, block = 8;
    printf("Enter binary message: ");
    scanf("%99s", data);
    len = strlen(data);
    data[len++] = '1';
    while (len % block != 0)
        data[len++] = '0';
    data[len] = '\0';
    printf("Padded message: %s\n", data);
    return 0;
}
