#include <stdio.h>
int main() {
    int p1 = 10, p2 = 12;
    int c1, c2, iv = 7;
    c1 = p1 ^ iv;
    c2 = p2 ^ c1;
    printf("Original C1 = %d\n", c1);
    printf("Original C2 = %d\n", c2);
    c1 = c1 ^ 1; 
    printf("Corrupted C1 = %d\n", c1);
    return 0;
}
