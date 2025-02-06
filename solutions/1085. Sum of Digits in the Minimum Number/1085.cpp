class Solution {
 public:
  int sumOfDigits(vector<int>& nums) {
    int mn = ranges::min(nums);
    int sum = 0;

    while (mn > 0) {
      sum += mn % 10;
      mn /= 10;
    }

    return sum & 1 ^ 1;
  }
};
