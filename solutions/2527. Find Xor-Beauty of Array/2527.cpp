class Solution {
 public:
  int xorBeauty(vector<int>& nums) {
    return accumulate(nums.begin(), nums.end(), 0, bit_xor<>());
  }
};
