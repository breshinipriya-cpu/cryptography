
#include <stdio.h>
#include <math.h>

int main() {
    double totalKeys, uniqueKeys;
    double log2Total, log2Unique;

    // Playfair uses 25 letters in a 5x5 matrix
    totalKeys = 1.0;

    for (int i = 1; i <= 25; i++) {
        totalKeys *= i;
    }

    // Equivalent keys: swapping rows, columns,
    // and transposing the matrix
    uniqueKeys = totalKeys / (120.0 * 120.0 * 2.0);

    log2Total = log2(totalKeys);
    log2Unique = log2(uniqueKeys);

    printf("Total possible keys = 25!\n");
    printf("Approximate power of 2 = 2^%.2f\n", log2Total);

    printf("\nEffectively unique keys = 25! / (5! * 5! * 2)\n");
    printf("Approximate power of 2 = 2^%.2f\n", log2Unique);

    return 0;
}
