class Solution {
 public:
  int minimumSplits(vector<int>& nums) {
    int ans = 1;
    int gcd = nums[0];

    for (const int num : nums) {
      const int newGcd = __gcd(gcd, num);
      if (newGcd > 1) {
        gcd = newGcd;
      } else {
        gcd = num;
        ++ans;
      }
    }

    return ans;
  }
};
