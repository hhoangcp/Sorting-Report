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

double tmp[1000006];

void Merge_Sort(double a[], int Left, int Right) {
    if (Left >= Right) return;
    if (Left + 1 == Right) {
        if (a[Left] > a[Right]) swap(a[Left], a[Right]);
        return;
    }

    int Mid = (Left + Right) >> 1;
    Merge_Sort(a, Left, Mid);
    Merge_Sort(a, Mid+1, Right);

    int len = Right - Left + 1;
    merge(a + Left, a + Mid + 1, a + Mid + 1, a + Right + 1, tmp);
    copy(tmp, tmp + len, a + Left);
}

double a[1000006];
int n;

int main() {
    freopen("Sorting.inp", "r", stdin);
    freopen("Sorting.out", "w", stdout);

    ios_base::sync_with_stdio(NULL); cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; ++i) cin >> a[i];

    auto Start = high_resolution_clock::now();
    Merge_Sort(a, 0, n-1);
    auto End = high_resolution_clock::now();

    auto elapsed = duration_cast<milliseconds>(End - Start);
    cerr << "Time to sort: " << elapsed.count();

    for(int i = 0; i < n - 1; ++i) assert(a[i] <= a[i+1]);

    for(int i = 0; i < n; ++i) cout << fixed << setprecision(6) << a[i] << ' ';

    return 0;
}
