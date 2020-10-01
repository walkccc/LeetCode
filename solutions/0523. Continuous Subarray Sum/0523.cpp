class Solution {
 public:
  bool checkSubarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> prefixSumToIndex{{0, -1}};
    int prefixSum = 0;

    for (int i = 0; i < nums.size(); ++i) {
      prefixSum += nums[i];
      if (k != 0) prefixSum %= k;
      if (prefixSumToIndex.count(prefixSum)) {
        if (i - prefixSumToIndex[prefixSum] > 1)
          return true;
      } else {
        // only add if absent, because the previous index is better
        prefixSumToIndex[prefixSum] = i;
      }
    }

    return false;
  }
};