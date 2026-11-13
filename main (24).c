#include <stdio.h>

int merge(const int a[], int na, const int b[], int nb, int out[]) {
    int i = 0, j = 0, k = 0;

    while (i < na && j < nb) {
        if (a[i] >= b[j])
            out[k++] = a[i++];
        else
            out[k++] = b[j++];
    }

    while (i < na)
        out[k++] = a[i++];

    while (j < nb)
        out[k++] = b[j++];

    return k;
}

int main(void) {
    int campusA[] = {98, 91, 85, 72};
    int campusB[] = {95, 91, 80};
    int merged[7];

    int n = merge(campusA, 4, campusB, 3, merged);

    for (int i = 0; i < n; i++)
        printf("%d ", merged[i]);

    printf("\n");

    return 0;
}