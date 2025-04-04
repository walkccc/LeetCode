class Solution {
 public:
  vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
    vector<int> ans;
    for (int i = 0; i < variables.size(); ++i) {
      const int a = variables[i][0];
      const int b = variables[i][1];
      const int c = variables[i][2];
      const int m = variables[i][3];
      if (modPow(modPow(a, b, 10), c, m) == target)
        ans.push_back(i);
    }
    return ans;
  }

 private:
  long modPow(long x, long n, int mod) {
    if (n == 0)
      return 1;
    if (n % 2 == 1)
      return x * modPow(x % mod, (n - 1), mod) % mod;
    return modPow(x * x % mod, (n / 2), mod) % mod;
  }
};
