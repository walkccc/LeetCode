class Solution {
 public:
  bool xorGame(vector<int>& nums) {
    const int xors = accumulate(begin(nums), end(nums), 0, bit_xor<int>());
    return xors == 0 || nums.size() % 2 == 0;
  }
};
