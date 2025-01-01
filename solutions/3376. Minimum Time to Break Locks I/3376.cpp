class Solution {
 public:
  int findMinimumTime(vector<int>& strength, int K) {
    return find(strength, /*x=*/1, 0, K);
  }

 private:
  int find(const vector<int>& strength, int x, int mask, int k) {
    if (mask == (1 << strength.size()) - 1)
      return 0;
    int res = INT_MAX;
    for (int i = 0; i < strength.size(); ++i)
      if ((mask >> i & 1) == 0) {
        const int time = (strength[i] - 1) / x + 1;  // ceil(strength[i] / x)
        res = min(res, time + find(strength, x + k, mask | 1 << i, k));
      }
    return res;
  }
};
