class Solution {
 public:
  string getPermutation(int n, int k) {
    string ans;
    vector<int> nums(n);
    vector<int> factorial(n + 1, 1);  // factorial[i] := i!

    iota(begin(nums), end(nums), 1);

    for (int i = 2; i <= n; ++i)
      factorial[i] = factorial[i - 1] * i;

    --k;  // 0-indexed

    for (int i = n - 1; i >= 0; --i) {
      const int j = k / factorial[i];
      k %= factorial[i];
      ans += to_string(nums[j]);
      nums.erase(begin(nums) + j);
    }

    return ans;
  }
};
