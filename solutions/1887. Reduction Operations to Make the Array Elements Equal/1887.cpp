class Solution {
 public:
  int reductionOperations(vector<int>& nums) {
    int ans = 0;

    sort(nums.begin(), nums.end());

    for (int i = nums.size() - 1; i > 0; --i)
      if (nums[i] != nums[i - 1])
        ans += nums.size() - i;

    return ans;
  }
};
