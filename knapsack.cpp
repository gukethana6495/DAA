#include <iostream>
using namespace std;

int knapsack(int W, int wt[], int val[], int n) {
    int dp[n+1][W+1];

    // Build table dp[][]
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            
            // Base case
            if (i == 0 || w == 0)
                dp[i][w] = 0;

            // If weight of item is less than capacity
            else if (wt[i-1] <= w)
                dp[i][w] = max(val[i-1] + dp[i-1][w - wt[i-1]],
                               dp[i-1][w]);

            // If weight is more than capacity
            else
                dp[i][w] = dp[i-1][w];
        }
    }

    return dp[n][W];
}

int main() {
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;
    int n = 3;

    cout << "Maximum Profit = " << knapsack(W, wt, val, n);

    return 0;
}