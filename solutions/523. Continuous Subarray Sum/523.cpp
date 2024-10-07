class Solution {
 public:
  bool checkSubarraySum(vector<int>& nums, int k) {
    int prefix = 0;
    unordered_map<int, int> prefixToIndex{{0, -1}};

    for (int i = 0; i < nums.size(); ++i) {
      prefix += nums[i];
      if (k != 0)
        prefix %= k;
      if (const auto it = prefixToIndex.find(prefix);
          it != prefixToIndex.cend()) {
        if (i - it->second > 1)
          return true;
      } else {
        // Set a new key if it's absent because the previous index is better.
        prefixToIndex[prefix] = i;
      }
    }

    return false;
  }
};
