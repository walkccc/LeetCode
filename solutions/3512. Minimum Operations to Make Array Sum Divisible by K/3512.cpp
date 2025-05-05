class Solution {
 public:
  int minOperations(vector<int>& nums, int k) {
    return accumulate(nums.begin(), nums.end(), 0) % k;
  }
};
