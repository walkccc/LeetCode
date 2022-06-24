class Solution {
 public:
  int minTransfers(vector<vector<int>>& transactions) {
    vector<int> balance(21);
    vector<int> debt;

    for (const auto& t : transactions) {
      const int from = t[0];
      const int to = t[1];
      const int amount = t[2];
      balance[from] -= amount;
      balance[to] += amount;
    }

    for (const int b : balance)
      if (b)
        debt.push_back(b);

    return dfs(debt, 0);
  }

 private:
  int dfs(vector<int>& debt, int s) {
    while (s < debt.size() && !debt[s])
      ++s;
    if (s == debt.size())
      return 0;

    int ans = INT_MAX;

    for (int i = s + 1; i < debt.size(); ++i)
      if (debt[i] * debt[s] < 0) {
        debt[i] += debt[s];  // debt[s] is settled
        ans = min(ans, 1 + dfs(debt, s + 1));
        debt[i] -= debt[s];  // backtrack
      }

    return ans;
  }
};
