class Solution {
 public:
  int sumOfTheDigitsOfHarshadNumber(int x) {
    const int digitSum = getDigitSum(x);
    return x % digitSum == 0 ? digitSum : -1;
  }

 private:
  int getDigitSum(int x) {
    int digitSum = 0;
    while (x > 0) {
      digitSum += x % 10;
      x /= 10;
    }
    return digitSum;
  }
};
