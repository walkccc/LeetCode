class Solution {
 public:
  bool checkSubarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> prefixToIndex{{0, -1}};
    int prefix = 0;

    for (int i = 0; i < nums.size(); ++i) {
      prefix += nums[i];
      if (k != 0)
        prefix %= k;
      if (prefixToIndex.count(prefix)) {
        if (i - prefixToIndex[prefix] > 1)
          return true;
      } else {
        // only add if absent, because the previous index is better
        prefixToIndex[prefix] = i;
      }
    }

    return false;
  }
};
