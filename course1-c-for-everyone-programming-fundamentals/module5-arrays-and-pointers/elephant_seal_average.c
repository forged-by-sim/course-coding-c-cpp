#include <stdio.h>
#include <stdlib.h>

#define MAX_SEALS 1000  // Adjust if you expect more entries

int main(void) {
    FILE *fp;
    int weights[MAX_SEALS];
    int count = 0;
    int sum = 0;
    double average;

    // Open the file
    fp = fopen("elephant_seal_data.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    // Read data into the array
    while (fscanf(fp, "%d", &weights[count]) == 1) {
        sum += weights[count];
        count++;
        if (count >= MAX_SEALS) break;
    }

    fclose(fp);

    if (count == 0) {
        printf("No data found.\n");
        return 1;
    }

    // Calculate average
    average = (double)sum / count;

    // Print result
    printf("Number of elephant seals: %d\n", count);
    printf("Average weight: %.2f\n", average);

    return 0;
}
