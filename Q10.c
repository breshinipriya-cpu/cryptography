
#include <stdio.h>
#include <ctype.h>
#include <string.h>

char matrix[5][5] = {
    {'M','F','H','I','K'},
    {'U','N','O','P','Q'},
    {'Z','V','W','X','Y'},
    {'E','L','A','R','G'},
    {'D','S','T','B','C'}
};

void encryptPair(char a, char b) {
    int r1, c1, r2, c2;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (matrix[i][j] == a) {
                r1 = i; c1 = j;
            }
            if (matrix[i][j] == b) {
                r2 = i; c2 = j;
            }
        }
    }

    if (r1 == r2) {
        putchar(matrix[r1][(c1 + 1) % 5]);
        putchar(matrix[r2][(c2 + 1) % 5]);
    } else if (c1 == c2) {
        putchar(matrix[(r1 + 1) % 5][c1]);
        putchar(matrix[(r2 + 1) % 5][c2]);
    } else {
        putchar(matrix[r1][c2]);
        putchar(matrix[r2][c1]);
    }
}

int main() {
    char message[] = "MUST SEE YOU OVER CADOGAN WEST COMING AT ONCE";
    char clean[200];
    int i, n = 0;

    for (i = 0; message[i] != '\0'; i++) {
        char ch = toupper((unsigned char)message[i]);
        if (ch >= 'A' && ch <= 'Z') {
            if (ch == 'J') ch = 'I';
            clean[n++] = ch;
        }
    }
    clean[n] = '\0';

    printf("Encrypted message: ");

    for (i = 0; i < n; i += 2) {
        char a = clean[i];
        char b;

        if (i + 1 >= n)
            b = 'X';
        else if (clean[i] == clean[i + 1]) {
            b = 'X';
            i--;
        } else
            b = clean[i + 1];

        encryptPair(a, b);
    }

    printf("\n");
    return 0;
}
