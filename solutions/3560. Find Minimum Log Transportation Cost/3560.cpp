class Solution {
 public:
  long long minCuttingCost(long n, long m, int k) {
    return max(0L, max(n, m) - k) * k;
  }
};
