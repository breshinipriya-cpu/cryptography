
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char text[100], key[100];
    int i, j = 0, shift;

    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter key: ");
    fgets(key, sizeof(key), stdin);

    printf("Encrypted message: ");

    for (i = 0; text[i] != '\0'; i++) {
        if (isalpha((unsigned char)text[i])) {
            shift = toupper((unsigned char)key[j % (strlen(key) - 1)]) - 'A';

            if (isupper((unsigned char)text[i])) {
                text[i] = (text[i] - 'A' + shift) % 26 + 'A';
            } else {
                text[i] = (text[i] - 'a' + shift) % 26 + 'a';
            }

            j++;
        }
    }

    printf("%s", text);

    return 0;
}
