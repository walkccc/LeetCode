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
      return k % 2 == 0 ? nums[0] : -1;
    // Take min(n, k - 1) elements and put the largest one back.
    const int mx = *max_element(nums.begin(), nums.begin() + min(n, k - 1));
    if (k >= n)
      return mx;
    return max(mx, nums[k]);
  }
};
