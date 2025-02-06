class Solution {
 public:
  int minOperations(vector<int>& nums) {
    int ans = 0;
    unordered_map<int, int> count;

    for (const int num : nums)
      ++count[num];

    for (const auto& [_, freq] : count) {
      // If freq == 3k, need k operations.
      // If freq == 3k + 1 = 3*(k - 1) + 2*2, need k + 1 operations.
      // If freq == 3k + 2, need k + 1 operations.
      if (freq == 1)
        return -1;
      ans += (freq + 2) / 3;
    }

    return ans;
  }
};
