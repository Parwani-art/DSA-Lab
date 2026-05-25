#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace chrono;

long long comp_count = 0;
long long exch_count = 0;

// ================= BUBBLE SORT =================
void bubbleSort(vector<int>& x) {
    int n = x.size();
    bool switched = true;

    for (int pass = 0; pass < n - 1 && switched; pass++) {
        switched = false;

        for (int j = 0; j < n - pass - 1; j++) {
            comp_count++;

            if (x[j] > x[j + 1]) {
                swap(x[j], x[j + 1]);
                exch_count++;
                switched = true;
            }
        }
    }
}

// ================= SELECTION SORT =================
void selectionSort(vector<int>& x) {
    int n = x.size();

    for (int a = 0; a < n; a++) {
        int key = a;

        for (int b = a + 1; b < n; b++) {
            comp_count++;

            if (x[b] < x[key])
                key = b;
        }

        if (key != a) {
            swap(x[a], x[key]);
            exch_count++;
        }
    }
}

// ================= INSERTION SORT =================
void insertionSort(vector<int>& x) {
    int n = x.size();

    for (int k = 1; k < n; k++) {
        int y = x[k];
        int j;

        for (j = k - 1; j >= 0; j--) {
            comp_count++;

            if (y < x[j]) {
                x[j + 1] = x[j];
                exch_count++;
            }
            else {
                break;
            }
        }

        x[j + 1] = y;
    }
}

// ================= HEAP SORT =================
void heapify(vector<int>& x, int i, int sz) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < sz) {
        comp_count++;
        if (x[l] > x[largest])
            largest = l;
    }

    if (r < sz) {
        comp_count++;
        if (x[r] > x[largest])
            largest = r;
    }

    if (largest != i) {
        swap(x[i], x[largest]);
        exch_count++;

        heapify(x, largest, sz);
    }
}

void heapSort(vector<int>& x) {
    int n = x.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(x, i, n);

    for (int i = n - 1; i > 0; i--) {
        swap(x[0], x[i]);
        exch_count++;

        heapify(x, 0, i);
    }
}

// ================= GENERATE RANDOM ARRAY =================
vector<int> generateRandomArray(int n) {
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100000;
    }

    return arr;
}

// ================= TEST FUNCTION =================
void testSort(string name, void (*sortFunc)(vector<int>&), vector<int> arr) {

    comp_count = 0;
    exch_count = 0;

    auto start = high_resolution_clock::now();

    sortFunc(arr);

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(stop - start);

    cout << "\n========== " << name << " ==========\n";
    cout << "Comparisons : " << comp_count << endl;
    cout << "Exchanges   : " << exch_count << endl;
    cout << "Execution Time : " << duration.count() << " ms" << endl;
}

// ================= MAIN =================
int main() {

    srand(time(0));

    int sizes[] = { 10, 100, 1000, 5000 };

    for (int n : sizes) {

        cout << "\n\n====================================";
        cout << "\nArray Size N = " << n;
        cout << "\n====================================\n";

        vector<int> data = generateRandomArray(n);

        testSort("Bubble Sort", bubbleSort, data);

        testSort("Selection Sort", selectionSort, data);

        testSort("Insertion Sort", insertionSort, data);

        testSort("Heap Sort", heapSort, data);
    }

    return 0;
}