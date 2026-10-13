#include <stdio.h>
#include <string.h>
#include <ctype.h>

char matrix[5][5];

void generateMatrix(char key[]) {
    int used[26] = {0};
    int i, j, k = 0;
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

void encryptPair(char a, char b) {
    int r1, c1, r2, c2, i, j;

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
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
        printf("%c%c", matrix[r1][(c1 + 1) % 5],
                       matrix[r2][(c2 + 1) % 5]);
    }
    else if (c1 == c2) {
        printf("%c%c", matrix[(r1 + 1) % 5][c1],
                       matrix[(r2 + 1) % 5][c2]);
    }
    else {
        printf("%c%c", matrix[r1][c2],
                       matrix[r2][c1]);
    }
}

int main() {
    char key[100], text[200], clean[200], a, b;
    int i, n = 0;

    printf("Enter keyword: ");
    fgets(key, sizeof(key), stdin);

    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);

    generateMatrix(key);

    printf("\nPlayfair Matrix:\n");
    for (i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++)
            printf("%c ", matrix[i][j]);
        printf("\n");
    }

    for (i = 0; text[i] != '\0'; i++) {
        a = toupper((unsigned char)text[i]);

        if (a >= 'A' && a <= 'Z') {
            if (a == 'J')
                a = 'I';
            clean[n++] = a;
        }
    }
    clean[n] = '\0';

    printf("\nEncrypted message: ");

    for (i = 0; i < n; i += 2) {
        a = clean[i];

        if (i + 1 >= n) {
            b = 'X';
        }
        else if (clean[i] == clean[i + 1]) {
            b = 'X';
            i--;
        }
        else {
            b = clean[i + 1];
        }

        encryptPair(a, b);
    }

    printf("\n");
    return 0;
}
