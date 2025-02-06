class Solution {
 public:
  int findFinalValue(vector<int>& nums, int original) {
    unordered_set<int> numsSet(nums.begin(), nums.end());
    while (numsSet.contains(original))
      original *= 2;
    return original;
  }
};
