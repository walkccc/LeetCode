class Solution {
 public:
  int findMaxLength(vector<int>& nums) {
    int ans = 0;
    int prefix = 0;
    unordered_map<int, int> prefixToIndex{{0, -1}};

    for (int i = 0; i < nums.size(); ++i) {
      prefix += nums[i] ? 1 : -1;
      if (const auto it = prefixToIndex.find(prefix);
          it != prefixToIndex.cend())
        ans = max(ans, i - it->second);
      else
        prefixToIndex[prefix] = i;
    }

    return ans;
  }
};
