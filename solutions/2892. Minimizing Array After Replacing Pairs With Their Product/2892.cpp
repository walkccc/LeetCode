class Solution {
 public:
  int minArrayLength(vector<int>& nums, int k) {
    int count = 0;
    long prod = -1;

    for (const int num : nums) {
      if (num == 0)
        return 1;
      if (prod != -1 && prod * num <= k) {
        prod *= num;
      } else {
        prod = num;
        ++count;
      }
    }

    return count;
  }
};
