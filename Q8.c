
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char text[100];
    char key[] = "CIPHERABDFGJKLMNOQSTUVWXYZ";
    int i, index;

    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);

    printf("Encrypted message: ");

    for (i = 0; text[i] != '\0'; i++) {
        if (isupper((unsigned char)text[i])) {
            index = text[i] - 'A';
            printf("%c", key[index]);
        }
        else if (islower((unsigned char)text[i])) {
            index = text[i] - 'a';
            printf("%c", tolower((unsigned char)key[index]));
        }
        else {
            printf("%c", text[i]);
        }
    }

    return 0;
}
