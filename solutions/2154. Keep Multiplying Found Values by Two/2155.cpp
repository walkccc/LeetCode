class Solution {
 public:
  int findFinalValue(vector<int>& nums, int original) {
    unordered_set<int> numsSet(begin(nums), end(nums));
    while (numsSet.count(original))
      original *= 2;
    return original;
  }
};
