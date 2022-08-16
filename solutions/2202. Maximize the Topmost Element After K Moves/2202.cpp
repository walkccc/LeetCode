class Solution {
 public:
  int maximumTop(vector<int>& nums, int k) {
    const int n = nums.size();
    // after taking k elements, if we're left something, then we return nums[k];
    // otherwise return -1
    if (k == 0 || k == 1)
      return n == k ? -1 : nums[k];
    // (remove then add) even times
    if (n == 1)
      return k & 1 ? -1 : nums[0];
    // take min(n, k - 1) elements and put back the largest one
    const int max = *max_element(begin(nums), begin(nums) + min(n, k - 1));
    if (k >= n)
      return max;
    return std::max(max, nums[k]);
  }
};
