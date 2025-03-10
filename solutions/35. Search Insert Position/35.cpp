class Solution {
 public:
  int searchInsert(vector<int>& nums, int target) {
    int l = 0;
    int r = nums.size();

    while (l < r) {
      const int m = (l + r) / 2;
      if (nums[m] == target)
        return m;
      if (nums[m] < target)
        l = m + 1;
      else
        r = m;
    }

    return l;
  }
};
