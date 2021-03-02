class Solution {
 public:
  int findMaxLength(vector<int>& nums) {
    int ans = 0;
    int prefix = 0;
    unordered_map<int, int> prefixToIndex{{0, -1}};

    for (int i = 0; i < nums.size(); ++i) {
      prefix += nums[i] ? 1 : -1;
      if (prefixToIndex.count(prefix))
        ans = max(ans, i - prefixToIndex[prefix]);
      else
        prefixToIndex[prefix] = i;
    }

    return ans;
  }
};
