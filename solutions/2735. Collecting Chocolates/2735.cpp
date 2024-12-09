class Solution {
 public:
  long long minCost(vector<int>& nums, long long x) {
    const int n = nums.size();
    long ans = LONG_MAX;
    // minCost[i] := the minimum cost to collect the i-th type
    vector<int> minCost(n, INT_MAX);

    for (int rotate = 0; rotate < n; ++rotate) {
      for (int i = 0; i < n; ++i)
        minCost[i] = min(minCost[i], nums[(i - rotate + n) % n]);
      ans =
          min(ans, accumulate(minCost.begin(), minCost.end(), 0L) + rotate * x);
    }

    return ans;
  }
};
