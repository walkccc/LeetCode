class Solution {
 public:
  int minOperations(vector<int>& nums, unsigned k) {
    const unsigned xors = accumulate(nums.begin(), nums.end(), 0, bit_xor<>());
    return popcount(k ^ xors);
  }
};
