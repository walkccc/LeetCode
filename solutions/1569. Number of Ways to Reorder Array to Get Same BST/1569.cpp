class Solution {
 public:
  int numOfWays(vector<int>& nums) {
    comb = generate(nums.size() + 1);
    return ways(nums) - 1;
  }

 private:
  static constexpr int kMod = 1'000'000'007;
  // comb[n][k] := C(n, k)
  vector<vector<int>> comb;

  int ways(const vector<int>& nums) {
    if (nums.size() <= 2)
      return 1;

    vector<int> left;
    vector<int> right;

    for (int i = 1; i < nums.size(); ++i)
      if (nums[i] < nums[0])
        left.push_back(nums[i]);
      else
        right.push_back(nums[i]);

    long ans = comb[nums.size() - 1][left.size()];
    ans = (ans * ways(left)) % kMod;
    ans = (ans * ways(right)) % kMod;
    return ans;
  }

  // 118. Pascal's Triangle
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> comb;

    for (int i = 0; i < numRows; ++i)
      comb.push_back(vector<int>(i + 1, 1));

    for (int i = 2; i < numRows; ++i)
      for (int j = 1; j < comb[i].size() - 1; ++j)
        comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % kMod;

    return comb;
  }
};
