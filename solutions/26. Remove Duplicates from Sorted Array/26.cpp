class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    int i = 0;

    for (const int num : nums)
      if (i < 1 || num > nums[i - 1])
        nums[i++] = num;

    return i;
  }
};
