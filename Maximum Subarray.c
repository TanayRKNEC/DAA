#include <stdio.h>

int maxSubArray(int arr[], int size) {
    int maxSum = arr[0];
    int currentSum = arr[0];

    for (int i = 1; i < size; i++) {
        currentSum = (currentSum + arr[i] > arr[i]) ? currentSum + arr[i] : arr[i];
        maxSum = (currentSum > maxSum) ? currentSum : maxSum;
    }

    return maxSum;
}

int main() {
    int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
    int size = sizeof(arr) / sizeof(arr[0]);

    int maxSum = maxSubArray(arr, size);
    printf("Maximum subarray sum: %d\n", maxSum);

    return 0;
}
