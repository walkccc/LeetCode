class Solution {
 public:
  int maxSubArrayLen(vector<int>& nums, int k) {
    int ans = 0;
    int prefix = 0;
    unordered_map<int, int> prefixToIndex{{0, -1}};

    for (int i = 0; i < nums.size(); ++i) {
      prefix += nums[i];
      const int target = prefix - k;
      if (prefixToIndex.count(target))
        ans = max(ans, i - prefixToIndex[target]);
      if (!prefixToIndex.count(prefix))
        prefixToIndex[prefix] = i;
    }

    return ans;
  }
};
