#include <iostream>
#include <cstdlib>
using namespace std;

void printArray(float array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

// ─── 1. INSERTION SORT ───────────────────────────────────────
void insertionSort(float array[], int size) {
    for (int step = 1; step < size; step++) {
        float key = array[step];
        int j = step - 1;

        while (j >= 0 && key < array[j]) {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = key;
    }
}

// ─── 2. BUBBLE SORT ──────────────────────────────────────────
void bubbleSort(float array[], int size) {
    for (int step = 0; step < size - 1; step++) {
        for (int j = 0; j < size - step - 1; j++) {
            if (array[j] > array[j + 1]) {
                float temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

// ─── 3. SELECTION SORT ───────────────────────────────────────
void selectionSort(float array[], int size) {
    for (int step = 0; step < size - 1; step++) {
        int minIdx = step;

        for (int j = step + 1; j < size; j++) {
            if (array[j] < array[minIdx]) {
                minIdx = j;
            }
        }

        float temp = array[minIdx];
        array[minIdx] = array[step];
        array[step] = temp;
    }
}

// ─── 4. MERGE SORT ───────────────────────────────────────────
void merge(float array[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    float leftArr[n1], rightArr[n2];

    for (int i = 0; i < n1; i++)
        leftArr[i] = array[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = array[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            array[k] = leftArr[i];
            i++;
        } else {
            array[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1) { array[k] = leftArr[i]; i++; k++; }
    while (j < n2) { array[k] = rightArr[j]; j++; k++; }
}

void mergeSort(float array[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);
        merge(array, left, mid, right);
    }
}

// ─── 5. QUICK SORT ───────────────────────────────────────────
int partition(float array[], int low, int high) {
    float pivot = array[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (array[j] <= pivot) {
            i++;
            float temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }

    float temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;

    return i + 1;
}

void quickSort(float array[], int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high);
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

// ─────────────────────────────────────────────────────────────

int main() {
    float data[10000];

    for (int i = 0; i < 10000; i++) {
        data[i] = (rand() % 100000) / 100.0f;
    }

    int size = sizeof(data) / sizeof(data[0]);

    cout << "Choose a sorting algorithm:" << endl;
    cout << "  1. Insertion Sort" << endl;
    cout << "  2. Bubble Sort" << endl;
    cout << "  3. Selection Sort" << endl;
    cout << "  4. Merge Sort" << endl;
    cout << "  5. Quick Sort" << endl;
    cout << "Enter (1-5): ";

    int choice;
    cin >> choice;

    switch (choice) {
        case 1:
            insertionSort(data, size);
            cout << "Sorted with Insertion Sort:" << endl;
            break;
        case 2:
            bubbleSort(data, size);
            cout << "Sorted with Bubble Sort:" << endl;
            break;
        case 3:
            selectionSort(data, size);
            cout << "Sorted with Selection Sort:" << endl;
            break;
        case 4:
            mergeSort(data, 0, size - 1);
            cout << "Sorted with Merge Sort:" << endl;
            break;
        case 5:
            quickSort(data, 0, size - 1);
            cout << "Sorted with Quick Sort:" << endl;
            break;
        default:
            cout << "Invalid choice." << endl;
            return 1;
    }

    printArray(data, size);
    return 0;
}