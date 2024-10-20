class Solution {
 public:
  int differenceOfSum(vector<int>& nums) {
    const int elementSum = accumulate(nums.begin(), nums.end(), 0);
    const int allDigitSum = getAllDigitSum(nums);
    return abs(elementSum - allDigitSum);
  }

 private:
  int getAllDigitSum(const vector<int>& nums) {
    int allDigitSum = 0;
    for (const int num : nums)
      allDigitSum += getDigitSum(num);
    return allDigitSum;
  }

  int getDigitSum(int num) {
    int digitSum = 0;
    while (num > 0) {
      digitSum += num % 10;
      num /= 10;
    }
    return digitSum;
  }
};
