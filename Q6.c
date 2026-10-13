#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char text[1000];
    int a, b, i, inv, p1, p2;

    printf("Enter ciphertext: ");
    fgets(text, sizeof(text), stdin);

    // B = 1, U = 20
    // Assume common English letters E = 4 and T = 19
    // C = (a*p + b) mod 26

    printf("\nPossible decrypted messages:\n");

    for (a = 1; a < 26; a++) {
        inv = 0;

        for (i = 1; i < 26; i++) {
            if ((a * i) % 26 == 1) {
                inv = i;
                break;
            }
        }

        if (inv == 0)
            continue;

        // Map E -> B and T -> U
        // 4a + b = 1 (mod 26)
        // 19a + b = 20 (mod 26)
        if ((15 * a) % 26 != 19)
            continue;

        b = (1 - 4 * a) % 26;
        if (b < 0)
            b += 26;

        printf("\nKey: a = %d, b = %d\n", a, b);
        printf("Plaintext: ");

        for (i = 0; text[i] != '\0'; i++) {
            if (isalpha((unsigned char)text[i])) {
                int c = toupper((unsigned char)text[i]) - 'A';
                int p = (inv * (c - b + 26)) % 26;
                putchar(p + 'A');
            } else {
                putchar(text[i]);
            }
        }

        printf("\n");
    }

    return 0;
}
