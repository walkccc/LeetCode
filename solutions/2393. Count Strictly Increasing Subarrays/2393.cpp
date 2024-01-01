class Solution {
 public:
  long long countSubarrays(vector<int>& nums) {
    long long ans = 0;

    for (int i = 0, j = -1; i < nums.size(); ++i) {
      if (i > 0 && nums[i] <= nums[i - 1])
        j = i - 1;
      ans += i - j;
    }

    return ans;
  }
};
