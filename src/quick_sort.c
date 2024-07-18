#include <donto_sorts.h>

void swap(int* a, int* b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int arr[], int low, int high)
{
    // choose the pivot
    int pivot = arr[high];

    // Index of smaller element and Indicate
    // the right position of pivot found so far
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than the pivot
        if (arr[j] < pivot) {
            // Increment index of smaller element
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// The Quicksort function Implement

void run_quick_sort(int arr[], int low, int high)
{
    // when low is less than high
    if (low < high) {
        // pi is the partition return index of pivot

        int pivot_index = partition(arr, low, high);

        // Recursion Call
        // smaller element than pivot goes left and
        // higher element goes right
        run_quick_sort(arr, low, pivot_index - 1);
        run_quick_sort(arr, pivot_index + 1, high);
    }
}

void quick_sort(int *tab, int size)
{
	run_quick_sort(tab, 0, size - 1);
}
