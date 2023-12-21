class Solution {
 public:
  int findMin(vector<int>& nums) {
    int l = 0;
    int r = nums.size() - 1;

    while (l < r) {
      const int m = (l + r) / 2;
      if (nums[m] == nums[r])
        --r;
      else if (nums[m] < nums[r])
        r = m;
      else
        l = m + 1;
    }

    return nums[l];
  }
};
