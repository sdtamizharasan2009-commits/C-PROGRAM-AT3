#include <stdio.h>

#define ROWS 3
#define COLS 4

void rowTotals(int rain[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        int total = 0;

        for (int j = 0; j < COLS; j++)
            total += rain[i][j];

        printf("District %d Total: %d\n", i + 1, total);
    }
}

void columnAverages(int rain[ROWS][COLS]) {
    for (int j = 0; j < COLS; j++) {
        int total = 0;

        for (int i = 0; i < ROWS; i++)
            total += rain[i][j];

        printf("Month %d Average: %.2f\n",
               j + 1, total / (float)ROWS);
    }
}

void maximumRainfall(int rain[ROWS][COLS]) {
    int max = rain[0][0];
    int district = 0, month = 0;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (rain[i][j] > max) {
                max = rain[i][j];
                district = i;
                month = j;
            }
        }
    }

    printf("Maximum Rainfall: %d\n", max);
    printf("District: %d Month: %d\n",
           district + 1, month + 1);
}

void deficientDistricts(int rain[ROWS][COLS]) {
    float total = 0;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++)
            total += rain[i][j];
    }

    float average = total / (ROWS * COLS);

    printf("State Average: %.2f\n", average);
    printf("Deficient Districts: ");

    for (int i = 0; i < ROWS; i++) {
        int districtTotal = 0;

        for (int j = 0; j < COLS; j++)
            districtTotal += rain[i][j];

        if (districtTotal / (float)COLS < average * 0.6)
            printf("%d ", i + 1);
    }

    printf("\n");
}

int main(void) {
    int rain[ROWS][COLS] = {
        {100, 120, 80, 90},
        {40, 30, 50, 35},
        {200, 180, 220, 190}
    };

    rowTotals(rain);
    columnAverages(rain);
    maximumRainfall(rain);
    deficientDistricts(rain);

    return 0;
}