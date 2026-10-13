
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char text[100];
    int k, i;

    printf("Enter a message: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter shift value (1-25): ");
    scanf("%d", &k);

    if (k < 1 || k > 25) {
        printf("Invalid shift value!\n");
        return 1;
    }

    for (i = 0; text[i] != '\0'; i++) {
        if (isupper((unsigned char)text[i])) {
            text[i] = (text[i] - 'A' + k) % 26 + 'A';
        }
        else if (islower((unsigned char)text[i])) {
            text[i] = (text[i] - 'a' + k) % 26 + 'a';
        }
    }

    printf("Encrypted message: %s", text);

    return 0;
}
