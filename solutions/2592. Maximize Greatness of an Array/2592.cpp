class Solution {
 public:
  int maximizeGreatness(vector<int>& nums) {
    int ans = 0;

    sort(nums.begin(), nums.end());

    for (const int num : nums)
      if (num > nums[ans])
        ++ans;

    return ans;
  }
};
