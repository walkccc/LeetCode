class Solution {
 public:
  int minCost(int n, vector<int>& cuts) {
    cuts.push_back(0);
    cuts.push_back(n);
    ranges::sort(cuts);
    vector<vector<int>> mem(cuts.size(), vector<int>(cuts.size(), INT_MAX));
    return minCost(cuts, 0, cuts.size() - 1, mem);
  }

 private:
  // Returns minCost(cuts[i..j]).
  int minCost(const vector<int>& cuts, int i, int j, vector<vector<int>>& mem) {
    if (j - i <= 1)
      return 0;
    if (mem[i][j] != INT_MAX)
      return mem[i][j];

    for (int k = i + 1; k < j; ++k)
      mem[i][j] = min(mem[i][j], cuts[j] - cuts[i] + minCost(cuts, i, k, mem) +
                                     minCost(cuts, k, j, mem));

    return mem[i][j];
  }
};
