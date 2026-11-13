#include <stdio.h>
#include <string.h>

#define MAX 10

int main(void) {
    char names[MAX][30] = {
        "Kumar",
        "Arun",
        "David",
        "Bala",
        "Charlie",
        "Arun",
        "Ravi",
        "Manoj",
        "John",
        "Ajay"
    };

    char temp[30];
    char search[30] = "Arun";
    int n = 10;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(names[i], names[j]) > 0) {
                strcpy(temp, names[i]);
                strcpy(names[i], names[j]);
                strcpy(names[j], temp);
            }
        }
    }

    printf("Sorted Names\n");

    for (int i = 0; i < n; i++)
        printf("%s\n", names[i]);

    printf("\nDuplicate Names\n");

    for (int i = 0; i < n - 1; i++) {
        if (strcmp(names[i], names[i + 1]) == 0)
            printf("%s\n", names[i]);
    }

    int low = 0, high = n - 1, found = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int result = strcmp(names[mid], search);

        if (result == 0) {
            found = mid;
            break;
        } else if (result < 0) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (found != -1)
        printf("\n%s found at index %d\n", search, found);
    else
        printf("\nName not found\n");

    return 0;
}