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

int main() {
    freopen("Sorting.inp", "r", stdin);
    freopen("Sorting.out", "w", stdout);

    ios_base::sync_with_stdio(NULL); cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; ++i) cin >> a[i];

    auto Start = high_resolution_clock::now();
    sort(a, a+n);
    auto End = high_resolution_clock::now();

    auto elapsed = duration_cast<milliseconds>(End - Start);
    cerr << "Time to sort: " << elapsed.count();

    for(int i = 0; i < n - 1; ++i) assert(a[i] <= a[i+1]);

    for(int i = 0; i < n; ++i) cout << fixed << setprecision(6) << a[i] << ' ';

    return 0;
}
