class Solution {
 public:
  int subsetXORSum(vector<int>& nums) {
    return accumulate(begin(nums), end(nums), 0, bit_or<>()) << nums.size() - 1;
  }
};
