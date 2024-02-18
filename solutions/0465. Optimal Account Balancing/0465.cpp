class Solution {
 public:
  int minTransfers(vector<vector<int>>& transactions) {
    vector<int> balance(21);
    vector<int> debts;

    for (const vector<int>& t : transactions) {
      const int from = t[0];
      const int to = t[1];
      const int amount = t[2];
      balance[from] -= amount;
      balance[to] += amount;
    }

    for (const int b : balance)
      if (b > 0)
        debts.push_back(b);

    return dfs(debts, 0);
  }

 private:
  int dfs(vector<int>& debts, int s) {
    while (s < debts.size() && !debts[s])
      ++s;
    if (s == debts.size())
      return 0;

    int ans = INT_MAX;

    for (int i = s + 1; i < debts.size(); ++i)
      if (debts[i] * debts[s] < 0) {
        debts[i] += debts[s];  // `debts[s]` is settled.
        ans = min(ans, 1 + dfs(debts, s + 1));
        debts[i] -= debts[s];  // Backtrack.
      }

    return ans;
  }
};
