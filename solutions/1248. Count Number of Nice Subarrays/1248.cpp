class Solution {
 public:
  int numberOfSubarrays(vector<int>& nums, int k) {
    return numberOfSubarraysAtMost(nums, k) -
           numberOfSubarraysAtMost(nums, k - 1);
  }

 private:
  int numberOfSubarraysAtMost(vector<int>& nums, int k) {
    int ans = 0;

    for (int l = 0, r = 0; r <= nums.size();)
      if (k >= 0) {
        ans += r - l;
        if (r == nums.size())
          break;
        if (nums[r] % 2 == 1)
          --k;
        ++r;
      } else {
        if (nums[l] % 2 == 1)
          ++k;
        ++l;
      }

    return ans;
  }
};
