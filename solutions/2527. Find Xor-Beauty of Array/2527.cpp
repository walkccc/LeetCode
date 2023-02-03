class Solution {
 public:
  int xorBeauty(vector<int>& nums) {
    return accumulate(begin(nums), end(nums), 0, bit_xor<>());
  }
};
