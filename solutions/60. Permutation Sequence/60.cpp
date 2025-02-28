class Solution {
 public:
  string getPermutation(int n, int k) {
    string ans;
    vector<int> nums(n);
    vector<int> fact(n + 1, 1);  // fact[i] := i!

    iota(nums.begin(), nums.end(), 1);

    for (int i = 2; i <= n; ++i)
      fact[i] = fact[i - 1] * i;

    --k;  // 0-indexed

    for (int i = n - 1; i >= 0; --i) {
      const int j = k / fact[i];
      k %= fact[i];
      ans += to_string(nums[j]);
      nums.erase(nums.begin() + j);
    }

    return ans;
  }
};
