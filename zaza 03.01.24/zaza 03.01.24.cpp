#include <iostream>
#include <algorithm> 
using namespace std;

//2
int findMax(int arr[], int n) {
    if (n == 1) return arr[0];
    return std::max(arr[n - 1], findMax(arr, n - 1));
}

//2
int findMin(int arr[], int n) {
    if (n == 1) return arr[0];
    return std::min(arr[n - 1], findMin(arr, n - 1));
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    cout << "Опорный элемент: " << pivot << endl;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    int pivotIndex = i + 1;

    cout << "Массив после деления: ";
    for (int k = low; k <= high; k++) cout << arr[k] << " ";
    cout << "\nИндекс опорного элемента: " << pivotIndex << endl;

    cout << "Левая часть: ";
    for (int k = low; k < pivotIndex; k++) cout << arr[k] << " ";
    cout << "\nПравая часть: ";
    for (int k = pivotIndex + 1; k <= high; k++) cout << arr[k] << " ";
    cout << "\n\n";

    return pivotIndex;
}

// 3
void quickSortLumoto(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSortLumoto(arr, low, pivotIndex - 1);
        quickSortLumoto(arr, pivotIndex + 1, high);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arrays[][8] = {
        {34, 7, 23, 32, 5},         
        {1, 2, 3, 4, 5, 6},         
        {90, 80, 70, 60, 50, 40, 30}, 
        {5, 3, 8, 8, 1, 5, 3, 9}      
    };
    int sizes[] = { 5, 6, 7, 8 };

    for (int i = 0; i < 4; i++) {
        int* arr = arrays[i];
        int size = sizes[i];

        cout << "Початковий масив: ";
        printArray(arr, size);

        int maxElement = findMax(arr, size);
        int minElement = findMin(arr, size);
        cout << "Максимальний елемент: " << maxElement << endl;
        cout << "Мінімальний елемент: " << minElement << endl;
        quickSortLumoto(arr, 0, size - 1);

        cout << "Відсортований масив: ";
        printArray(arr, size);
        cout << "---------------------------\n";
    }

    return 0;
}
