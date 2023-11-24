class Solution {
 public:
  int maxProduct(vector<int>& nums) {
    int max1 = 0;
    int max2 = 0;

    for (const int num : nums)
      if (num > max1)
        max2 = std::exchange(max1, num);
      else if (num > max2)
        max2 = num;

    return (max1 - 1) * (max2 - 1);
  }
};
