#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char text[] = "meet me at the usual place at ten rather than eight oclock";
    char plain[100], cipher[100], decrypted[100];
    int i, n = 0;

    int K[2][2] = {{9, 4}, {5, 7}};
    int Inv[2][2] = {{5, 12}, {15, 25}};

    /* Remove spaces and convert to uppercase */
    for (i = 0; text[i] != '\0'; i++) {
        if (isalpha((unsigned char)text[i]))
            plain[n++] = toupper((unsigned char)text[i]);
    }

    /* Add X if the number of letters is odd */
    if (n % 2 != 0)
        plain[n++] = 'X';
    plain[n] = '\0';

    /* Encryption */
    for (i = 0; i < n; i += 2) {
        int a = plain[i] - 'A';
        int b = plain[i + 1] - 'A';

        cipher[i]     = (K[0][0] * a + K[0][1] * b) % 26 + 'A';
        cipher[i + 1] = (K[1][0] * a + K[1][1] * b) % 26 + 'A';
    }
    cipher[n] = '\0';

    /* Decryption */
    for (i = 0; i < n; i += 2) {
        int a = cipher[i] - 'A';
        int b = cipher[i + 1] - 'A';

        decrypted[i]     = (Inv[0][0] * a + Inv[0][1] * b) % 26 + 'A';
        decrypted[i + 1] = (Inv[1][0] * a + Inv[1][1] * b) % 26 + 'A';
    }
    decrypted[n] = '\0';

    printf("Plaintext : %s\n", plain);
    printf("Ciphertext: %s\n", cipher);
    printf("Decrypted : %s\n", decrypted);

    return 0;
}
