
#include <stdio.h>
#include <ctype.h>

int main() {
    char text[100];
    int a, b, i;

    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter value of a: ");
    scanf("%d", &a);

    printf("Enter value of b: ");
    scanf("%d", &b);

    if (a < 1 || a > 25 || b < 0 || b > 25) {
        printf("Invalid values!\n");
        return 1;
    }

    int valid = 0;
    for (i = 1; i <= 25; i++) {
        if ((a * i) % 26 == 1) {
            valid = 1;
            break;
        }
    }

    if (!valid) {
        printf("Invalid value of a! Choose a coprime to 26.\n");
        return 1;
    }

    printf("Encrypted message: ");

    for (i = 0; text[i] != '\0'; i++) {
        if (isupper((unsigned char)text[i])) {
            text[i] = ((a * (text[i] - 'A') + b) % 26) + 'A';
        }
        else if (islower((unsigned char)text[i])) {
            text[i] = ((a * (text[i] - 'a') + b) % 26) + 'a';
        }
    }

    printf("%s", text);

    return 0;
}
