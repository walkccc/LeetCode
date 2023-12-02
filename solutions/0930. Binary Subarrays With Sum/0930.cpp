class Solution {
 public:
  int numSubarraysWithSum(vector<int>& nums, int goal) {
    int ans = 0;
    int prefix = 0;
    // {prefix: number of occurrence}
    unordered_map<int, int> count{{0, 1}};

    for (const int num : nums) {
      prefix += num;
      if (const auto it = count.find(prefix - goal); it != count.cend())
        ans += it->second;
      ++count[prefix];
    }

    return ans;
  }
};
