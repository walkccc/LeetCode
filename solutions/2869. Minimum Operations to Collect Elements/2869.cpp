class Solution {
 public:
  int minOperations(vector<int>& nums, int k) {
    unordered_set<int> seen;

    for (int i = nums.size() - 1; i >= 0; --i) {
      if (nums[i] > k)
        continue;
      seen.insert(nums[i]);
      if (seen.size() == k)
        return nums.size() - i;
    }

    throw;
  }
};
