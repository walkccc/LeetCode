class Solution {
 public:
  vector<int> solve(vector<int>& nums, vector<vector<int>>& queries) {
    constexpr int kMod = 1'000'000'007;
    const int n = nums.size();
    const int sqrtN = static_cast<int>(sqrt(n));
    vector<int> ans;
    // prefix[x][y] = sum(nums[x + ay]), where a >= 0 and x + ay < n
    vector<vector<int>> prefix(n, vector<int>(sqrtN));

    // Set prefix[i][j] to nums[i] to indicate the sequence starts with nums[i].
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < sqrtN; ++j)
        prefix[i][j] = nums[i];

    for (int x = n - 1; x >= 0; --x)
      for (int y = 1; y < sqrtN; ++y)
        if (x + y < n) {
          prefix[x][y] += prefix[x + y][y];
          prefix[x][y] %= kMod;
        }

    for (const vector<int>& query : queries) {
      const int x = query[0];
      const int y = query[1];
      if (y < sqrtN) {
        ans.push_back(prefix[x][y]);
      } else {
        int sum = 0;
        for (int i = x; i < n; i += y)
          sum = (sum + nums[i]) % kMod;
        ans.push_back(sum);
      }
    }

    return ans;
  }
};
