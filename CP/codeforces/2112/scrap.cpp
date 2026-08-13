#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

const int MAX_M = 500005;
long long dp[MAX_M];
int spf[MAX_M];

void sieve() {
    std::iota(spf, spf + MAX_M, 0);
    for (int i = 2; i * i < MAX_M; ++i) {
        if (spf[i] == i) {
            for (int j = i * i; j < MAX_M; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
}

void get_divisors_recursive(int k, int current_divisor, const std::vector<std::pair<int, int>>& factors, std::vector<int>& divisors) {
    if (k == factors.size()) {
        divisors.push_back(current_divisor);
        return;
    }

    int p = factors[k].first;
    int a = factors[k].second;
    int term = 1;
    for (int i = 0; i <= a; ++i) {
        get_divisors_recursive(k + 1, current_divisor * term, factors, divisors);
        term *= p;
    }
}

std::vector<int> get_divisors(int n) {
    if (n == 1) return {1};
    std::vector<std::pair<int, int>> factors;
    int temp = n;
    while (temp > 1) {
        int p = spf[temp];
        int count = 0;
        while (temp % p == 0) {
            temp /= p;
            count++;
        }
        factors.push_back({p, count});
    }
    std::vector<int> divisors;
    get_divisors_recursive(0, 1, factors, divisors);
    return divisors;
}

void precompute() {
    sieve();
    std::fill(dp, dp + MAX_M, -1);
    dp[1] = 1;

    for (int m = 2; m < MAX_M; ++m) {
        std::vector<int> divisors = get_divisors(m);
        long long min_vertices = -1;

        for (int d : divisors) {
            if (d < 3) continue;

            int m_by_d = m / d;
            int d_minus_2 = d - 2;

            if (dp[m_by_d] != -1 && dp[d_minus_2] != -1) {
                long long current_vertices = dp[m_by_d] + dp[d_minus_2];
                if (min_vertices == -1 || current_vertices < min_vertices) {
                    min_vertices = current_vertices;
                }
            }
        }
        dp[m] = min_vertices;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    precompute();
    int t;
    std::cin >> t;
    while (t--) {
        int m;
        std::cin >> m;
        std::cout << dp[m] << "\n";
    }
    return 0;
}
