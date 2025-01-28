class Solution {
 public:
  bool xorGame(vector<int>& nums) {
    const int xors = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
    return xors == 0 || nums.size() % 2 == 0;
  }
};
