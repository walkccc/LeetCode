class Solution {
 public:
  int findGCD(vector<int>& nums) {
    return __gcd(ranges::min(nums), ranges::max(nums));
  }
};
