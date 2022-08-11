class Solution {
 public:
  int countEven(int num) {
    return (num - sumOfDigit(num) % 2) / 2;
  }

 private:
  int sumOfDigit(int num) {
    int sum = 0;
    while (num) {
      sum += num % 10;
      num /= 10;
    }
    return sum;
  }
};
