class Solution {
 public:
  int minElement(vector<int>& nums) {
    int ans = INT_MAX;
    for (const int num : nums)
      ans = min(ans, getDigitSum(num));
    return ans;
  }

 private:
  int getDigitSum(int num) {
    int digitSum = 0;
    while (num > 0) {
      digitSum += num % 10;
      num /= 10;
    }
    return digitSum;
  }
};
