#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>

using namespace std;
using namespace std::chrono;

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) minIdx = j;
        }
        swap(arr[i], arr[minIdx]);
    }
}

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[(low + high) / 2];
    int i = low, j = high;
    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++; j--;
        }
    }
    return i;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int idx = partition(arr, low, high);
        quickSort(arr, low, idx - 1);
        quickSort(arr, idx, high);
    }
}

void merge(vector<int>& arr, int l, int m, int r) {
    vector<int> L(arr.begin() + l, arr.begin() + m + 1);
    vector<int> R(arr.begin() + m + 1, arr.begin() + r + 1);
    int i = 0, j = 0, k = l;
    while (i < L.size() && j < R.size()) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < L.size()) arr[k++] = L[i++];
    while (j < R.size()) arr[k++] = R[j++];
}

void mergeSort(vector<int>& arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void countingSort(vector<int>& arr) {
    int maxVal = *max_element(arr.begin(), arr.end());
    vector<int> count(maxVal + 1, 0);
    for (int x : arr) count[x]++;
    int idx = 0;
    for (int i = 0; i <= maxVal; i++) {
        while (count[i]-- > 0) arr[idx++] = i;
    }
}

void radixSort(vector<int>& arr) {
    int maxVal = *max_element(arr.begin(), arr.end());
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        vector<int> output(arr.size());
        int count[10] = {0};
        for (int x : arr) count[(x / exp) % 10]++;
        for (int i = 1; i < 10; i++) count[i] += count[i - 1];
        for (int i = arr.size() - 1; i >= 0; i--) {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }
        arr = output;
    }
}

int main() {
    vector<int> sizes = {5, 10, 50, 100};
    for (int n : sizes) {
        vector<int> base(n);
        for (int i = 0; i < n; i++) base[i] = n - i; // Case B: Reverse Sorted

        double totalBubble = 0, totalSelect = 0, totalQuick = 0, totalMerge = 0, totalCount = 0, totalRadix = 0;
        for (int run = 0; run < 5; run++) {
            vector<int> a;

            a = base; auto s = high_resolution_clock::now(); bubbleSort(a);
            totalBubble += duration<double, micro>(high_resolution_clock::now() - s).count();

            a = base; s = high_resolution_clock::now(); selectionSort(a);
            totalSelect += duration<double, micro>(high_resolution_clock::now() - s).count();

            a = base; s = high_resolution_clock::now(); quickSort(a, 0, n - 1);
            totalQuick += duration<double, micro>(high_resolution_clock::now() - s).count();

            a = base; s = high_resolution_clock::now(); mergeSort(a, 0, n - 1);
            totalMerge += duration<double, micro>(high_resolution_clock::now() - s).count();

            a = base; s = high_resolution_clock::now(); countingSort(a);
            totalCount += duration<double, micro>(high_resolution_clock::now() - s).count();

            a = base; s = high_resolution_clock::now(); radixSort(a);
            totalRadix += duration<double, micro>(high_resolution_clock::now() - s).count();
        }
        cout << "Size N = " << n << " (Avg of 5 runs in microseconds):\n";
        cout << "Bubble: " << totalBubble/5 << " | Selection: " << totalSelect/5
             << " | Quick: " << totalQuick/5 << " | Merge: " << totalMerge/5
             << " | Counting: " << totalCount/5 << " | Radix: " << totalRadix/5 << "\n\n";
    }
    return 0;
}
