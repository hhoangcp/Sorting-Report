/// hhoangcpascal

#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <iomanip>
#include <chrono>
#include <cassert>

using namespace std;
using namespace chrono;

double a[1000006];
int n;

void Heapify(int idx, int End) {
    while (idx < End) {
        int p = idx;
        int l = (idx << 1) + 1, r = (idx << 1) + 2;

        if (l < End && a[p] < a[l]) p = l; 
        if (r < End && a[p] < a[r]) p = r;

        if (p == idx) break;

        swap(a[p], a[idx]);
        idx = p;
    }
}

void Heap_Sort() {
    for(int idx = (n >> 1) - 1; idx >= 0; --idx) Heapify(idx, n);
    for(int idx = n - 1; idx > 0; --idx) {
        swap(a[0], a[idx]);
        Heapify(0, idx);
    }
}

int main() {
    freopen("Sorting.inp", "r", stdin);
    freopen("Sorting.out", "w", stdout);

    ios_base::sync_with_stdio(NULL); cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; ++i) cin >> a[i];

    auto Start = high_resolution_clock::now();
    Heap_Sort();
    auto End = high_resolution_clock::now();

    auto elapsed = duration_cast<milliseconds>(End - Start);
    cerr << "Time to sort: " << elapsed.count();

    for(int i = 0; i < n - 1; ++i) assert(a[i] <= a[i+1]);

    for(int i = 0; i < n; ++i) cout << fixed << setprecision(6) << a[i] << ' ';

    return 0;
}
