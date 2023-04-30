class Solution {
 public:
  vector<int> rearrangeArray(vector<int>& nums) {
    sort(begin(nums), end(nums));
    for (int i = 1; i < nums.size(); i += 2)
      swap(nums[i], nums[i - 1]);
    return nums;
  }
};
