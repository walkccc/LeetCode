class Solution {
 public:
  int maximumProduct(vector<int>& nums) {
    int min1 = INT_MAX;  // the minimum
    int min2 = INT_MAX;  // the second minimum
    int max1 = INT_MIN;  // the maximum
    int max2 = INT_MIN;  // the second maximum
    int max3 = INT_MIN;  // the third maximum

    for (const int num : nums) {
      if (num <= min1) {
        min2 = min1;
        min1 = num;
      } else if (num <= min2) {
        min2 = num;
      }
      if (num >= max1) {
        max3 = max2;
        max2 = max1;
        max1 = num;
      } else if (num >= max2) {
        max3 = max2;
        max2 = num;
      } else if (num >= max3) {
        max3 = num;
      }
    }

    return max(max1 * min1 * min2, max1 * max2 * max3);
  }
};
