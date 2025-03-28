class Solution {
 public:
  bool findSubarrays(vector<int>& nums) {
    unordered_set<int> seen;

    for (int i = 1; i < nums.size(); ++i)
      if (!seen.insert(nums[i - 1] + nums[i]).second)
        return true;

    return false;
  }
};
