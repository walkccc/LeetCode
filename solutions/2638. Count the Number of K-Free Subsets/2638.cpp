class Solution {
 public:
  // Similar to 2597. The Number of Beautiful Subsets
  long long countTheNumOfKFreeSubsets(vector<int>& nums, int k) {
    unordered_map<int, set<int>> modToSubset;

    for (const int num : nums)
      modToSubset[num % k].insert(num);

    int prevNum = -k;
    long long skip = 0;
    long long pick = 0;

    for (const auto& [_, subset] : modToSubset)
      for (const int num : subset) {
        const long long cacheSkip = skip;
        skip += pick;
        pick = 1 + cacheSkip + (num - prevNum == k ? 0 : pick);
        prevNum = num;
      }

    return 1 + skip + pick;
  }
};
