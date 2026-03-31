#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

// ─── 1. INSERTION SORT ───────────────────────────────────────
void insertionSort(int array[], int size) {
    for (int step = 1; step < size; step++) {
        int key = array[step];
        int j = step - 1;

        while (j >= 0 && key < array[j]) {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = key;
    }
}

// ─── 2. BUBBLE SORT ──────────────────────────────────────────
void bubbleSort(int array[], int size) {
    for (int step = 0; step < size - 1; step++) {
        for (int j = 0; j < size - step - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

// ─── 3. SELECTION SORT ───────────────────────────────────────
void selectionSort(int array[], int size) {
    for (int step = 0; step < size - 1; step++) {
        int minIdx = step;

        for (int j = step + 1; j < size; j++) {
            if (array[j] < array[minIdx]) {
                minIdx = j;
            }
        }

        int temp = array[minIdx];
        array[minIdx] = array[step];
        array[step] = temp;
    }
}

// ─── 4. MERGE SORT ───────────────────────────────────────────
void merge(int array[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* leftArr  = new int[n1];
    int* rightArr = new int[n2];

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

    delete[] leftArr;
    delete[] rightArr;
}

void mergeSort(int array[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);
        merge(array, left, mid, right);
    }
}

// ─── 5. QUICK SORT ───────────────────────────────────────────
int partition(int array[], int low, int high) {
    int pivot = array[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (array[j] <= pivot) {
            i++;
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }

    int temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;

    return i + 1;
}

void quickSort(int array[], int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high);
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

// ─────────────────────────────────────────────────────────────

int main() {
    const int MAX = 100000;

    int n;
    cout << "How many elements to sort (max " << MAX << "): ";
    cin >> n;

    if (n < 1 || n > MAX) {
        cout << "Invalid size. Enter a number between 1 and " << MAX << "." << endl;
        return 1;
    }

    int* data = new int[n];

    for (int i = 0; i < n; i++) {
        data[i] = rand() % 100000;
    }

    cout << "\nChoose a sorting algorithm:" << endl;
    cout << "  1. Insertion Sort" << endl;
    cout << "  2. Bubble Sort" << endl;
    cout << "  3. Selection Sort" << endl;
    cout << "  4. Merge Sort" << endl;
    cout << "  5. Quick Sort" << endl;
    cout << "Enter (1-5): ";

    int choice;
    cin >> choice;

    clock_t start, end;
    double time_taken;

    switch (choice) {
        case 1:
            start = clock();
            insertionSort(data, n);
            end = clock();
            cout << "Sorted with Insertion Sort:" << endl;
            break;
        case 2:
            start = clock();
            bubbleSort(data, n);
            end = clock();
            cout << "Sorted with Bubble Sort:" << endl;
            break;
        case 3:
            start = clock();
            selectionSort(data, n);
            end = clock();
            cout << "Sorted with Selection Sort:" << endl;
            break;
        case 4:
            start = clock();
            mergeSort(data, 0, n - 1);
            end = clock();
            cout << "Sorted with Merge Sort:" << endl;
            break;
        case 5:
            start = clock();
            quickSort(data, 0, n - 1);
            end = clock();
            cout << "Sorted with Quick Sort:" << endl;
            break;
        default:
            cout << "Invalid choice." << endl;
            delete[] data;
            return 1;
    }

    time_taken = (double)(end - start) / CLOCKS_PER_SEC * 1000;
    cout << "Time taken: " << time_taken << " ms" << endl;

    delete[] data;

    cout << "Press Enter to exit..." << endl;
    cin.ignore();
    cin.get();
    return 0;
}