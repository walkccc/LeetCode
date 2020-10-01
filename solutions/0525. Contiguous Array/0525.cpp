class Solution {
 public:
  int findMaxLength(vector<int>& nums) {
    int ans = 0;
    int prefixSum = 0;
    unordered_map<int, int> prefixSumToIndex{{0, -1}};

    for (int i = 0; i < nums.size(); ++i) {
      prefixSum += nums[i] ? 1 : -1;
      if (prefixSumToIndex.count(prefixSum))
        ans = max(ans, i - prefixSumToIndex[prefixSum]);
      else
        prefixSumToIndex[prefixSum] = i;
    }

    return ans;
  }
};