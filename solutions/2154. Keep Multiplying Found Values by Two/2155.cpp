class Solution {
 public:
  int findFinalValue(vector<int>& nums, int original) {
    unordered_set<int> numsSet(nums.begin(), nums.end());
    while (numsSet.count(original))
      original *= 2;
    return original;
  }
};
