class Solution {
 public:
  bool canAliceWin(vector<int>& nums) {
    return accumulate(nums.begin(), nums.end(), 0, [](int subtotal, int num) {
      return subtotal + (num < 10 ? num : -num);
    }) != 0;
  }
};
