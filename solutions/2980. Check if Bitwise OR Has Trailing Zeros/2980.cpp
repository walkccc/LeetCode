class Solution {
 public:
  bool hasTrailingZeros(vector<int>& nums) {
    int countEven = 0;

    for (const int num : nums)
      if (num % 2 == 0)
        ++countEven;

    return countEven >= 2;
  }
};
