#include <stdio.h>
#include <stdlib.h>

void findMaxMin(int arr[], int low, int high, int *max, int *min) {
    int mid, max1, max2, min1, min2;

    if (low == high) {
        *max = arr[low];
        *min = arr[low];
    }

    else if (high == low + 1) {
        if (arr[low] > arr[high]) {
            *max = arr[low];
            *min = arr[high];
        } else {
            *max = arr[high];
            *min = arr[low];
        }
    }

    else {
        mid = (low + high) / 2;
        findMaxMin(arr, low, mid, &max1, &min1);
        findMaxMin(arr, mid + 1, high, &max2, &min2);

        if (max1 > max2)
            *max = max1;
        else
            *max = max2;

        if (min1 < min2)
            *min = min1;
        else
            *min = min2;
    }
}

int main() {
    int n, i;
    int *arr;
    int max, min;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    findMaxMin(arr, 0, n - 1, &max, &min);

    printf("Maximum element: %d\n", max);
    printf("Minimum element: %d\n", min);

    free(arr);

    return 0;
}
