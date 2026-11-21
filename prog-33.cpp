#include <stdio.h>
#include <string.h>
#include <openssl/des.h>

int main() {
    DES_cblock key = { '1','2','3','4','5','6','7','8' };
    DES_cblock input = { 'H','E','L','L','O','1','2','3' };
    DES_cblock encrypted, decrypted;
    DES_key_schedule schedule;

    DES_set_key_unchecked(&key, &schedule);

    DES_ecb_encrypt(&input, &encrypted, &schedule, DES_ENCRYPT);
    DES_ecb_encrypt(&encrypted, &decrypted, &schedule, DES_DECRYPT);

    printf("Original text: ");
    fwrite(input, 1, 8, stdout);

    printf("\nEncrypted data: ");
    for (int i = 0; i < 8; i++)
        printf("%02X ", encrypted[i]);

    printf("\nDecrypted text: ");
    fwrite(decrypted, 1, 8, stdout);

    printf("\n");
    return 0;
}
