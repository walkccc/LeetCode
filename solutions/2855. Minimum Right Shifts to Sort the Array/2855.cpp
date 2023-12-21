class Solution {
 public:
  int minimumRightShifts(vector<int>& nums) {
    int count = 0;
    int pivot = -1;

    for (int i = 0; i + 1 < nums.size(); i++)
      if (nums[i] > nums[i + 1]) {
        ++count;
        pivot = i;
      }

    if (count == 0)
      return 0;
    if (count > 1 || nums.back() > nums.front())
      return -1;
    return nums.size() - 1 - pivot;
  }
};
