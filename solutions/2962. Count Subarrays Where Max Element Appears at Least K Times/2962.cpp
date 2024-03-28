class Solution {
 public:
  long long countSubarrays(vector<int>& nums, int k) {
    const int maxNum = ranges::max(nums);
    long long ans = 0;
    int count = 0;

    for (int l = 0, r = 0; r < nums.size(); ++r) {
      if (nums[r] == maxNum)
        ++count;
      // Keep the window to include k - 1 times of the maximum number.
      while (count == k)
        if (nums[l++] == maxNum)
          --count;
      // If l > 0, nums[l..r] has k - 1 times of the maximum number. For any
      // subarray nums[i..r], where i < l, it will have at least k times of the
      // maximum number, since nums[l - 1] equals the maximum number.
      ans += l;
    }

    return ans;
  }
};
