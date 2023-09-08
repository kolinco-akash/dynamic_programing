#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

double fractionalKnapsack(int W, vector<int>& weights, vector<int>& values) {
    int n = weights.size();
    vector<double> valuePerWeight(n);
    for (int i = 0; i < n; i++) {
        valuePerWeight[i] = (double)values[i] / weights[i];
    }
    sort(valuePerWeight.rbegin(), valuePerWeight.rend());

    double totalValue = 0.0;
    int remainingWeight = W;

    for (int i = 0; i < n; i++) {
        if (remainingWeight >= weights[i]) {
            totalValue += values[i];
            remainingWeight -= weights[i];
        } else {
            totalValue += (double)remainingWeight / weights[i] * values[i];
            break;
        }
    }
    return totalValue;
}

int main() {
    int n, W;
    cin >> n >> W;
    vector<int> weights(n);
    vector<int> values(n);

    for (int i = 0; i < n; i++) {
        cin >> weights[i] >> values[i];
    }
    double maxTotalValue = fractionalKnapsack(W, weights, values);
    cout << "Maximum total value: " << maxTotalValue << endl;

    return 0;
}
