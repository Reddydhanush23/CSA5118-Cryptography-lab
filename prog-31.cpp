#include <stdio.h>

void shiftLeft(unsigned char *in, unsigned char *out, int n) {
    int i;
    unsigned char carry = 0;

    for (i = n - 1; i >= 0; i--) {
        unsigned char next = in[i] >> 7;
        out[i] = (in[i] << 1) | carry;
        carry = next;
    }
}

int main() {
    unsigned char input64[8] = {0x80,0,0,0,0,0,0,0};
    unsigned char input128[16] = {0x80};

    unsigned char out64[8], out128[16];
    int i;

    shiftLeft(input64, out64, 8);
    if (input64[0] & 0x80)
        out64[7] ^= 0x1B;

    shiftLeft(input128, out128, 16);
    if (input128[0] & 0x80)
        out128[15] ^= 0x87;

    printf("64-bit CMAC constant: 0x1B\n");
    printf("128-bit CMAC constant: 0x87\n");

    printf("64-bit first subkey: ");
    for (i = 0; i < 8; i++) printf("%02X", out64[i]);

    printf("\n128-bit first subkey: ");
    for (i = 0; i < 16; i++) printf("%02X", out128[i]);

    printf("\n");
    return 0;
}
