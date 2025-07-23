class Solution {
 public:
  int countEven(int num) {
    return (num - getDigitSum(num) % 2) / 2;
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
