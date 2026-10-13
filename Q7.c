#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char cipher[2000];
    int freq[26] = {0};
    int i, j, max;
    char temp;

    printf("Enter ciphertext:\n");
    fgets(cipher, sizeof(cipher), stdin);

    for (i = 0; cipher[i] != '\0'; i++) {
        if (isalpha((unsigned char)cipher[i])) {
            freq[toupper((unsigned char)cipher[i]) - 'A']++;
        }
    }

    printf("\nLetter frequencies:\n");

    for (i = 0; i < 26; i++) {
        if (freq[i] > 0)
            printf("%c : %d\n", 'A' + i, freq[i]);
    }

    printf("\nMost frequent ciphertext letters:\n");

    for (i = 0; i < 3; i++) {
        max = -1;
        j = -1;

        for (int k = 0; k < 26; k++) {
            if (freq[k] > max) {
                max = freq[k];
                j = k;
            }
        }

        if (j != -1 && max > 0) {
            printf("%c occurs %d times\n", 'A' + j, max);
            freq[j] = -1;
        }
    }

    printf("\nUse frequency analysis to determine the substitution key.\n");

    return 0;
}
