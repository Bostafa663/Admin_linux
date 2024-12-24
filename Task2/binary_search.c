#include <stdio.h>

// Function to implement binary search
int binary_search(int arr[], int size, int target) {
    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if the target is at mid
        if (arr[mid] == target)
            return mid;

        // If target is greater, ignore the left half
        if (arr[mid] < target)
            left = mid + 1;
        else
            // If target is smaller, ignore the right half
            right = mid - 1;
    }

    return -1; // Element not found
}

int main() {
    // Declare the array and the element to search
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;

    printf("Enter the element to search: ");
    scanf("%d", &target);

    // Call the binary search function
    int result = binary_search(arr, size, target);

    // Print the result
    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");

    return 0;
}

