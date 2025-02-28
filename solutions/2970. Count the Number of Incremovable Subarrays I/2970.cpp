class Solution {
 public:
  int incremovableSubarrayCount(vector<int>& nums) {
    const int n = nums.size();
    const int startIndex = getStartIndexOfSuffix(nums);
    // If the complete array is strictly increasing, the total number of ways we
    // can remove elements equals the total number of possible subarrays.
    if (startIndex == 0)
      return n * (n + 1) / 2;

    // The valid removals starting from nums[0] include nums[0..startIndex - 1],
    // nums[0..startIndex], ..., nums[0..n).
    int ans = n - startIndex + 1;

    // Enumerate each prefix subarray that is strictly increasing.
    for (int i = 0; i < startIndex; ++i) {
      if (i > 0 && nums[i] <= nums[i - 1])
        break;
      // Since nums[0..i] is strictly increasing, find the first index j in
      // nums[startIndex..n) such that nums[j] > nums[i]. The valid removals
      // will then be nums[i + 1..j - 1], nums[i + 1..j], ..., nums[i + 1..n).
      ans += nums.end() -
             upper_bound(nums.begin() + startIndex, nums.end(), nums[i]) + 1;
    }

    return ans;
  }

 private:
  // Returns the start index i of the suffix subarray such that nums[i..n) is
  // strictly increasing.
  int getStartIndexOfSuffix(const vector<int>& nums) {
    for (int i = nums.size() - 2; i >= 0; --i)
      if (nums[i] >= nums[i + 1])
        return i + 1;
    return 0;
  }
};
