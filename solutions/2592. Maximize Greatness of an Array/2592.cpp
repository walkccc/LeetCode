class Solution {
 public:
  int maximizeGreatness(vector<int>& nums) {
    int ans = 0;

    sort(begin(nums), end(nums));

    for (const int num : nums)
      if (num > nums[ans])
        ++ans;

    return ans;
  }
};
