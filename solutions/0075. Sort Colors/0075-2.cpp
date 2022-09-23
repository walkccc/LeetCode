class Solution {
 public:
  void sortColors(vector<int>& nums) {
    int l = 0;                // next 0 should be put in l
    int r = nums.size() - 1;  // next 2 should be put in r

    for (int i = 0; i <= r;)
      if (nums[i] == 0)
        swap(nums[i++], nums[l++]);
      else if (nums[i] == 1)
        ++i;
      else
        // we may swap a 0 to index i, but we're still not sure whether
        // this 0 is put in the correct index, so we can't move pointer i
        swap(nums[i], nums[r--]);
  }
};
