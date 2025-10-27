#include <iostream>
#include <vector>

const int N = 40;

// Inline function to compute sum of elements
inline void sum(int* p, int n, const std::vector<int>& d) {
    *p = 0;
    for (int i = 0; i < n; ++i)
        *p += d[i];
}

int main() {
    int accum = 0;
    std::vector<int> data(N);

    // Initialize vector with values 0 to N-1
    for (int i = 0; i < N; ++i)
        data[i] = i;

    // Compute the sum
    sum(&accum, N, data);

    // Print the result
    std::cout << "sum is " << accum << std::endl;

    return 0;
}
