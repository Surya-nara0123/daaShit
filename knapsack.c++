#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> weight;
vector<int> profit;
int targetW = 12;
vector<vector<int>> dp;

int func(int n, int c) {
    if (n == 0 || c == 0) {
        return 0;
    }

    // Check if value is already computed
    if (dp[n][c] != -1) {
        return dp[n][c];
    }

    if (weight[n - 1] > c) {
        dp[n][c] = func(n - 1, c);
    } else {
        int res1 = func(n - 1, c); // Exclude current item
        int res2 = profit[n - 1] + func(n - 1, c - weight[n - 1]); // Include current item
        dp[n][c] = max(res1, res2);
    }

    return dp[n][c];
}

int main() {
    weight = {1, 2, 4, 2, 5};
    profit = {5, 3, 5, 3, 2};
    
    int n = weight.size();
    dp.assign(n + 1, vector<int>(targetW + 1, -1));

    cout << func(n, targetW) << endl;
    return 0;
}
