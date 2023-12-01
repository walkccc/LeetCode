class Solution {
 public:
  vector<int> sortArrayByParityII(vector<int>& nums) {
    const int n = nums.size();

    for (int i = 0, j = 1; i < n; i += 2, j += 2) {
      while (i < n && nums[i] % 2 == 0)
        i += 2;
      while (j < n && nums[j] % 2 == 1)
        j += 2;
      if (i < n)
        swap(nums[i], nums[j]);
    }

    return nums;
  }
};
