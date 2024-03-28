class Solution {
 public:
  long long findScore(vector<int>& nums) {
    long long ans = 0;
    set<pair<int, int>> numAndIndices;
    vector<bool> seen(nums.size());

    for (int i = 0; i < nums.size(); ++i)
      numAndIndices.insert({nums[i], i});

    for (const auto& [num, i] : numAndIndices) {
      if (seen[i])
        continue;
      if (i > 0)
        seen[i - 1] = true;
      if (i + 1 < nums.size())
        seen[i + 1] = true;
      seen[i] = true;
      ans += num;
    }

    return ans;
  }
};
