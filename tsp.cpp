#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

// mask: bitmask of visited cities
// pos: current city
int tsp(int mask, int pos, const vector<vector<int>>& dist, vector<vector<int>>& dp) {
    int n = dist.size();
    
    // Base case: all cities visited, return cost back to starting city (0)
    if (mask == (1 << n) - 1) {
        return dist[pos][0];
    }

    // Return already computed state
    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    int ans = INF;

    // Try visiting every unvisited city
    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0) {
            int newCost = dist[pos][city] + tsp(mask | (1 << city), city, dist, dp);
            ans = min(ans, newCost);
        }
    }

    return dp[mask][pos] = ans;
}

int main() {
    // Adjacency matrix representing distances between 4 cities
    vector<vector<int>> dist = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    int n = dist.size();
    // DP table initialized with -1: size [2^n][n]
    vector<vector<int>> dp(1 << n, vector<int>(n, -1));

    // Start at city 0, with only city 0 visited (mask = 1)
    cout << "Minimum TSP Cost: " << tsp(1, 0, dist, dp) << endl;

    return 0;
}
