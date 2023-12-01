class Solution {
 public:
  int maximumTop(vector<int>& nums, int k) {
    const int n = nums.size();
    // After taking k elements, if there's something left, then return nums[k].
    // Otherwise, return -1.
    if (k == 0 || k == 1)
      return n == k ? -1 : nums[k];
    // Remove then add even number of times.
    if (n == 1)
      return k & 1 ? -1 : nums[0];
    // Take min(n, k - 1) elements and put the largest one back.
    const int max = *max_element(nums.begin(), nums.begin() + min(n, k - 1));
    if (k >= n)
      return max;
    return std::max(max, nums[k]);
  }
};
