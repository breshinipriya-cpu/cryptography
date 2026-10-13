
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char matrix[5][5];

void generateMatrix(char key[]) {
    int used[26] = {0};
    int i, k = 0;
    char ch;

    used['J' - 'A'] = 1;

    for (i = 0; key[i] != '\0'; i++) {
        ch = toupper((unsigned char)key[i]);

        if (ch >= 'A' && ch <= 'Z') {
            if (ch == 'J')
                ch = 'I';

            if (!used[ch - 'A']) {
                matrix[k / 5][k % 5] = ch;
                used[ch - 'A'] = 1;
                k++;
            }
        }
    }

    for (ch = 'A'; ch <= 'Z'; ch++) {
        if (!used[ch - 'A']) {
            matrix[k / 5][k % 5] = ch;
            k++;
        }
    }
}

void decryptPair(char a, char b) {
    int r1 = 0, c1 = 0, r2 = 0, c2 = 0;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (matrix[i][j] == a) {
                r1 = i;
                c1 = j;
            }
            if (matrix[i][j] == b) {
                r2 = i;
                c2 = j;
            }
        }
    }

    if (r1 == r2) {
        putchar(matrix[r1][(c1 + 4) % 5]);
        putchar(matrix[r2][(c2 + 4) % 5]);
    } else if (c1 == c2) {
        putchar(matrix[(r1 + 4) % 5][c1]);
        putchar(matrix[(r2 + 4) % 5][c2]);
    } else {
        putchar(matrix[r1][c2]);
        putchar(matrix[r2][c1]);
    }
}

int main() {
    char key[100];
    char cipher[] =
        "KXJEYUREBEZWEHEWRYTUHEYFSKREHEGOYFIWTTTU"
        "OLKSYCAJPOBOTEIZONTXBYBNTGONE YCUZWRGDSON"
        "SXBOUYWRHEBAAHYUSEDQ";

    printf("Enter Playfair keyword: ");
    fgets(key, sizeof(key), stdin);

    generateMatrix(key);

    printf("\nDecrypted message:\n");

    for (int i = 0; cipher[i] != '\0'; i++) {
        if (isalpha((unsigned char)cipher[i])) {
            char a = toupper((unsigned char)cipher[i]);
            char b;
            int j = i + 1;

            while (cipher[j] != '\0' &&
                   !isalpha((unsigned char)cipher[j]))
                j++;

            if (cipher[j] == '\0')
                break;

            b = toupper((unsigned char)cipher[j]);
            decryptPair(a, b);
            i = j;
        }
    }

    printf("\n");
    return 0;
}
