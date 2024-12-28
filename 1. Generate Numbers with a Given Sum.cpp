#include <iostream>
#include <vector>
using namespace std;

void findCombinations(int n, int sum, vector<int> &current, vector<vector<int>> &result) {
    if (sum == 0 && current.size() == n) {
        result.push_back(current);
        return;
    }
    if (current.size() >= n || sum <= 0) return;

    for (int i = 1; i <= sum; i++) {
        current.push_back(i);
        findCombinations(n, sum - i, current, result);
        current.pop_back();
    }
}

vector<vector<int>> generateNumbersWithSum(int n, int sum) {
    vector<vector<int>> result;
    vector<int> current;
    findCombinations(n, sum, current, result);
    return result;
}

int main() {
    int n = 3, sum = 7;
    vector<vector<int>> combinations = generateNumbersWithSum(n, sum);
    for (const auto &combination : combinations) {
        for (int num : combination) cout << num << " ";
        cout << endl;
    }
    return 0;
}
