class Solution {
 public:
  int maxSubArrayLen(vector<int>& nums, int k) {
    int ans = 0;
    int prefixSum = 0;
    unordered_map<int, int> prefixSumToIndex{{0, -1}};

    for (int i = 0; i < nums.size(); ++i) {
      prefixSum += nums[i];
      const int target = prefixSum - k;
      if (prefixSumToIndex.count(target))
        ans = max(ans, i - prefixSumToIndex[target]);
      if (!prefixSumToIndex.count(prefixSum))
        prefixSumToIndex[prefixSum] = i;
    }

    return ans;
  }
};