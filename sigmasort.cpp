#include <iostream>
using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Use the last element as the pivot
    int i = low - 1;       // Index of the smaller element
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);  // Recursively sort the left subarray
        quickSort(arr, pi + 1, high); // Recursively sort the right subarray
    }
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Prompt user to enter the pivot index
    int pivotIndex;
    cout << "Enter the pivot index (0 to " << n - 1 << "): ";
    cin >> pivotIndex;

    // Validate pivot index
    if (pivotIndex < 0 || pivotIndex >= n) {
        cerr << "Invalid pivot index. It should be between 0 and " << n - 1 << "." << endl;
        return 1;
    }

    // Move the selected pivot to the end of the array
    swap(arr[pivotIndex], arr[n - 1]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    // Wait for user to press Enter to exit
    cout << "Press Enter to exit...";
    cin.ignore(); // To ignore the leftover newline character
    cin.get();    // Waits for Enter key press

    return 0;
}
