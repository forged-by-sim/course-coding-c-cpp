#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int num;
    int denom;
} Rational;

// Function to reduce fractions to lowest terms
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

void reduce(Rational* r) {
    int g = gcd(abs(r->num), abs(r->denom));
    r->num /= g;
    r->denom /= g;
    if (r->denom < 0) { // normalize
        r->num = -r->num;
        r->denom = -r->denom;
    }
}

// Add
Rational add(Rational a, Rational b) {
    Rational result;
    result.num = a.num * b.denom + b.num * a.denom;
    result.denom = a.denom * b.denom;
    reduce(&result);
    return result;
}

// Subtract
Rational subtract(Rational a, Rational b) {
    Rational result;
    result.num = a.num * b.denom - b.num * a.denom;
    result.denom = a.denom * b.denom;
    reduce(&result);
    return result;
}

// Multiply
Rational multiply(Rational a, Rational b) {
    Rational result;
    result.num = a.num * b.num;
    result.denom = a.denom * b.denom;
    reduce(&result);
    return result;
}

// Divide
Rational divide(Rational a, Rational b) {
    Rational result;
    result.num = a.num * b.denom;
    result.denom = a.denom * b.num;
    reduce(&result);
    return result;
}

// Print a rational
void printRational(Rational r) {
    printf("%d/%d", r.num, r.denom);
}

// Main
int main() {
    FILE* file = fopen("rational_data.txt", "r");
    if (!file) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    int n;
    fscanf(file, "%d", &n);

    Rational* data = (Rational*)malloc(n * sizeof(Rational));
    for (int i = 0; i < n; i++) {
        fscanf(file, "%d %d", &data[i].num, &data[i].denom);
        reduce(&data[i]);
    }
    fclose(file);

    Rational sum = {0, 1};
    for (int i = 0; i < n; i++) {
        sum = add(sum, data[i]);
    }

    Rational average = divide(sum, (Rational){n, 1});

    printf("Sum of rationals = ");
    printRational(sum);
    printf("\n");

    printf("Average of rationals = ");
    printRational(average);
    printf("\n");

    free(data);
    return 0;
}
