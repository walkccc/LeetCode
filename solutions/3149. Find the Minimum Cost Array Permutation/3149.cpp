class Solution {
 public:
  vector<int> findPermutation(vector<int>& nums) {
    const int n = nums.size();
    vector<vector<int>> mem(n, vector<int>(1 << n));
    // bestPick[last][mask] := the best pick, where `last` is the last chosen
    // number and `mask` is the bitmask of the chosen numbers
    vector<vector<int>> bestPick(n, vector<int>(1 << n));

    // Choose 0 as perm[0] since the score function is cyclic.
    getScore(nums, /*last=*/0, /*mask=*/1, bestPick, mem);
    return construct(bestPick);
  }

 private:
  // Returns the minimum score, where `last` is the last chosen number and
  // `mask` is the bitmask of the chosen numbers.
  int getScore(const vector<int>& nums, int last, unsigned mask,
               vector<vector<int>>& bestPick, vector<vector<int>>& mem) {
    if (popcount(mask) == nums.size())
      return abs(last - nums[0]);  // |perm[n - 1] - nums[perm[0]]|
    if (mem[last][mask] > 0)
      return mem[last][mask];

    int minScore = INT_MAX;
    for (int i = 1; i < nums.size(); ++i) {
      if (mask >> i & 1)
        continue;
      const int nextMinScore =
          abs(last - nums[i]) + getScore(nums, i, mask | 1 << i, bestPick, mem);
      if (nextMinScore < minScore) {
        minScore = nextMinScore;
        bestPick[last][mask] = i;
      }
    }

    return mem[last][mask] = minScore;
  }

  vector<int> construct(const vector<vector<int>>& bestPick) {
    vector<int> ans;
    int last = 0;
    int mask = 1;
    for (int i = 0; i < bestPick.size(); ++i) {
      ans.push_back(last);
      last = bestPick[last][mask];
      mask |= 1 << last;
    }
    return ans;
  }
};
