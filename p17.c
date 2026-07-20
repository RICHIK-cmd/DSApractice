// Maximum Subarray Sum (Kadane’s Algorithm)
#include <stdio.h>

int maxSubarraySum(int arr[], int n) {
    int current_sum = arr[0];
    int max_sum = arr[0];

    for(int i = 1; i < n; i++) {
        // Decide: extend or restart
        if(current_sum + arr[i] > arr[i]) {
            current_sum = current_sum + arr[i];  // extend
        } else {
            current_sum = arr[i];  // restart
        }

        // Update global max
        if(current_sum > max_sum) {
            max_sum = current_sum;
        }
    }

    return max_sum;
}

int main() {
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Maximum Subarray Sum = %d", maxSubarraySum(arr, n));
    return 0;
}