class Solution {
 public:
  int maxNumberOfAlloys(int n, int k, int budget,
                        vector<vector<int>>& composition, vector<int>& stock,
                        vector<int>& cost) {
    int l = 1;
    int r = 1'000'000'000;

    while (l < r) {
      const int m = (l + r) / 2;
      if (isPossible(n, budget, composition, stock, cost, m))
        l = m + 1;
      else
        r = m;
    }

    return l - 1;
  }

 private:
  // Returns true if it's possible to create `m` alloys by using any machine.
  bool isPossible(int n, int budget, const vector<vector<int>>& composition,
                  const vector<int>& stock, const vector<int>& costs, int m) {
    // Try all the possible machines.
    for (const vector<int>& machine : composition) {
      long requiredMoney = 0;
      for (int j = 0; j < n; ++j) {
        const long requiredUnits =
            max(0L, static_cast<long>(machine[j]) * m - stock[j]);
        requiredMoney += static_cast<long>(requiredUnits) * costs[j];
      }
      if (requiredMoney <= budget)
        return true;
    }
    return false;
  }
};
