class Solution {
 public:
  int diagonalPrime(vector<vector<int>>& nums) {
    int ans = 0;
    for (int i = 0; i < nums.size(); ++i) {
      const int a = nums[i][i];
      const int b = nums[i][nums.size() - i - 1];
      if (isPrime(a))
        ans = max(ans, a);
      if (isPrime(b))
        ans = max(ans, b);
    }
    return ans;
  }

 private:
  bool isPrime(int n) {
    if (n <= 1)
      return false;
    for (int i = 2; i * i <= n; ++i)
      if (n % i == 0)
        return false;
    return true;
  }
};
