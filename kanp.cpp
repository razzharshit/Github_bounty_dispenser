#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to solve the 0/1 Knapsack problem using space-optimized DP
int knapsack01(int W, const vector<int>& weights, const vector<int>& values) {
    int n = weights.size();
    
    // dp[j] stores the maximum value achieved with a knapsack capacity of j
    vector<int> dp(W + 1, 0);

    // Build the table in a bottom-up manner
    for (int i = 0; i < n; ++i) {
        // Traverse backwards to prevent using the same item multiple times
        for (int j = W; j >= weights[i]; --j) {
            dp[j] = max(dp[j], values[i] + dp[j - weights[i]]);
        }
    }

    return dp[W];
}

