class Solution {
 public:
  long long minOperations(vector<vector<int>>& queries) {
    long ans = 0;
    for (const vector<int>& query : queries) {
      const int l = query[0];
      const int r = query[1];
      ans += (getOperations(r) - getOperations(l - 1) + 1) / 2;
    }
    return ans;
  }

 private:
  // Returns the number of operations required for [1, n].
  long getOperations(int n) {
    long res = 0;
    int ops = 0;
    for (int powerOfFour = 1; powerOfFour <= n; powerOfFour *= 4) {
      const int l = powerOfFour;
      const int r = min(n, powerOfFour * 4 - 1);
      res += static_cast<long>(r - l + 1) * ++ops;
    }
    return res;
  }
};
