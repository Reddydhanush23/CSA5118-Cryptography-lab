#include <stdio.h>

int main() {
    int stateBits = 1600;
    int blockBits = 1024;
    int capacityBits = stateBits - blockBits;

    int lanes = capacityBits / 64;

    printf("SHA-3 state size = %d bits\n", stateBits);
    printf("Block (rate) size = %d bits\n", blockBits);
    printf("Capacity size = %d bits\n", capacityBits);
    printf("Zero capacity lanes = %d\n", lanes);

    printf("Without permutation, capacity lanes remain zero.\n");
    printf("Therefore, all capacity lanes never become nonzero.\n");

    return 0;
}
