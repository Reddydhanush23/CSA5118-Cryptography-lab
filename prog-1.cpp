#include <stdio.h>
int main() {
    char str[100];
    int k, i;
    printf("Enter text: ");
    scanf("%s", str);
    printf("Enter key (1-25): ");
    scanf("%d", &k);
    for(i = 0; str[i] != '\0'; i++) {
        if(str[i] >= 'A' && str[i] <= 'Z')
            str[i] = (str[i] - 'A' + k) % 26 + 'A';
        else if(str[i] >= 'a' && str[i] <= 'z')
            str[i] = (str[i] - 'a' + k) % 26 + 'a';
    }
    printf("Cipher text: %s", str);
    return 0;
}
