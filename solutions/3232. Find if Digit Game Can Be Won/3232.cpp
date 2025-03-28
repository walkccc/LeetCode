class Solution {
 public:
  bool canAliceWin(vector<int>& nums) {
    return accumulate(nums.begin(), nums.end(), 0, [](int acc, int num) {
      return acc + (num < 10 ? num : -num);
    }) != 0;
  }
};
