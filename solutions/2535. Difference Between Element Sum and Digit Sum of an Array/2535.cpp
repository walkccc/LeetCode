class Solution {
 public:
  int differenceOfSum(vector<int>& nums) {
    const int elementSum = accumulate(nums.begin(), nums.end(), 0);
    const int digitSum = getDigitSum(nums);
    return abs(elementSum - digitSum);
  }

 private:
  int getDigitSum(const vector<int>& nums) {
    int digitSum = 0;
    for (int num : nums) {
      int sum = 0;
      while (num > 0) {
        sum += num % 10;
        num /= 10;
      }
      digitSum += sum;
    }
    return digitSum;
  }
};
