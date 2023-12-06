class Solution {
 public:
  int minOperations(vector<int>& nums, vector<int>& numsDivide) {
    const int gcd = getGCD(numsDivide);

    ranges::sort(nums);

    for (int i = 0; i < nums.size(); ++i)
      if (gcd % nums[i] == 0)
        return i;

    return -1;
  }

 private:
  int getGCD(const vector<int>& nums) {
    int gcd = nums[0];
    for (const int num : nums)
      gcd = __gcd(gcd, num);
    return gcd;
  }
};
