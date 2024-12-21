class Solution {
 public:
  int minChanges(vector<int>& nums, int k) {
    const int n = nums.size();
    const int pairSize = n / 2;
    int ans = n;
    unordered_map<int, int> diffCount;  // {abs(nums[-i - 1] - nums[i]): freq}
    // oneChangeCount[i] := the number of pairs that need only one change to to
    // achieve a difference of `i`
    vector<int> oneChangeCount(k + 1);

    for (int i = 0; i < pairSize; ++i) {
      const int a = nums[i];
      const int b = nums[n - i - 1];
      ++diffCount[abs(a - b)];
      ++oneChangeCount[max({a, b, k - a, k - b})];
    }

    // prefixOneChangeCount[i] := the number of pairs that need only one change
    // to achieve a difference >= `i`
    // prefixOneChangeCount[i] = sum(oneChangeCount[i..k])
    vector<int> prefixOneChangeCount{oneChangeCount};

    for (int i = k - 1; i >= 0; --i)
      prefixOneChangeCount[i] += prefixOneChangeCount[i + 1];

    for (const auto& [diff, freq] : diffCount) {
      const int oneChange = prefixOneChangeCount[diff] - freq;
      const int twoChanges = (pairSize - prefixOneChangeCount[diff]) * 2;
      ans = min(ans, oneChange + twoChanges);
    }

    return ans;
  }
};
