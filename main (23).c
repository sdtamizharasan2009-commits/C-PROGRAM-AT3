#include <stdio.h>

int main(void) {
    int a[] = {45, 12, 30, 8, 25, 18};
    int n = 6;
    int comparisons = 0, swaps = 0;
    int temp, flag;

    for (int i = 0; i < n - 1; i++) {
        flag = 0;

        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;

            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                swaps++;
                flag = 1;
            }
        }

        if (flag == 0)
            break;
    }

    printf("Bubble Sort: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\nComparisons: %d\n", comparisons);
    printf("Swaps: %d\n", swaps);

    int b[] = {45, 12, 30, 8, 25, 18};
    comparisons = 0;
    swaps = 0;

    for (int i = 0; i < n - 1; i++) {
        int min = i;

        for (int j = i + 1; j < n; j++) {
            comparisons++;

            if (b[j] < b[min])
                min = j;
        }

        if (min != i) {
            temp = b[i];
            b[i] = b[min];
            b[min] = temp;
            swaps++;
        }
    }

    printf("\nSelection Sort: ");
    for (int i = 0; i < n; i++)
        printf("%d ", b[i]);

    printf("\nComparisons: %d\n", comparisons);
    printf("Swaps: %d\n", swaps);

    int c[] = {45, 12, 30, 8, 25, 18};
    comparisons = 0;
    int shifts = 0;

    for (int i = 1; i < n; i++) {
        int key = c[i];
        int j = i - 1;

        while (j >= 0) {
            comparisons++;

            if (c[j] > key) {
                c[j + 1] = c[j];
                shifts++;
                j--;
            } else {
                break;
            }
        }

        c[j + 1] = key;
    }

    printf("\nInsertion Sort: ");
    for (int i = 0; i < n; i++)
        printf("%d ", c[i]);

    printf("\nComparisons: %d\n", comparisons);
    printf("Shifts: %d\n", shifts);

    return 0;
}