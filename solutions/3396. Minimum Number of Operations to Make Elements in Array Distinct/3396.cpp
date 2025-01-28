class Solution {
 public:
  int minimumOperations(vector<int>& nums) {
    unordered_set<int> seen;
    for (int i = nums.size() - 1; i >= 0; --i)
      if (!seen.insert(nums[i]).second)
        return (i + 1 + 2) / 3;  // ceil((i + 1) / 3)
    return 0;
  }
};
