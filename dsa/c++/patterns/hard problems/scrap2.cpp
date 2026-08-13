#include <bits/stdc++.h>
using namespace std;

int main() {
    // Measure time with high_resolution_clock
    auto start_high_res = chrono::high_resolution_clock::now();
    // Simulate a workload
    for (volatile int i = 0; i < 1e6; ++i);
    auto end_high_res = chrono::high_resolution_clock::now();
    chrono::duration<double> duration_high_res = end_high_res - start_high_res;

    // Measure time with steady_clock
    auto start_steady = chrono::steady_clock::now();
    // Simulate a workload
    for (volatile int i = 0; i < 1e6; ++i);
    auto end_steady = chrono::steady_clock::now();
    chrono::duration<double> duration_steady = end_steady - start_steady;

    cout << "Time taken with high_resolution_clock: " << fixed << setprecision(10)
         << duration_high_res.count() << " sec" << endl;
    cout << "Time taken with steady_clock: " << fixed << setprecision(10)
         << duration_steady.count() << " sec" << endl;

    return 0;
}
