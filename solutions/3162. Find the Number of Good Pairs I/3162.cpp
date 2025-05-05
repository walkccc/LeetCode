class Solution {
 public:
  int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    int ans = 0;
    for (const int num1 : nums1)
      for (const int num2 : nums2)
        if (num1 % (num2 * k) == 0)
          ++ans;
    return ans;
  }
};
