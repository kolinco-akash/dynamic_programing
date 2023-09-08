#include <iostream>
#include <vector>
using namespace std;

int countWaysToMakeChange(int amount) {
    vector<int> coins = {1, 5, 10, 25, 50};
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;

    for (int coin : coins) {
        for (int i = coin; i <= amount; i++) {
            dp[i] += dp[i - coin];
        }
    }

    return dp[amount];
}

int main() {
    int amount;
    while (cin >> amount) {
        int ways = countWaysToMakeChange(amount);
        cout << ways << endl;
    }
    return 0;
}
