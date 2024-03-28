class Solution {
 public:
  int singleNonDuplicate(vector<int>& nums) {
    int l = 0;
    int r = nums.size() - 1;

    while (l < r) {
      int m = (l + r) / 2;
      if (m & 1)
        --m;
      if (nums[m] == nums[m + 1])
        l = m + 2;
      else
        r = m;
    }

    return nums[l];
  }
};
