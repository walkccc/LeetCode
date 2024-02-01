class Solution {
 public:
  vector<long long> minimumCosts(vector<int>& regular, vector<int>& express,
                                 int expressCost) {
    const int n = regular.size();
    vector<long long> ans(n);
    // the minimum cost to reach the current stop in a regular route
    long long dpReg = 0;
    // the minimum cost to reach the current stop in an express route
    long long dpExp = expressCost;

    for (int i = 0; i < n; ++i) {
      const long long prevReg = dpReg;
      const long long prevExp = dpExp;
      dpReg = min(prevReg + regular[i], prevExp + 0 + regular[i]);
      dpExp = min(prevReg + expressCost + express[i], prevExp + express[i]);
      ans[i] = min(dpReg, dpExp);
    }

    return ans;
  }
};
