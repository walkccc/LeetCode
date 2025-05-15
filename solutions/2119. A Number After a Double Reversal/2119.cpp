class Solution {
 public:
  bool isSameAfterReversals(int num) {
    const int reversed1 = getReversed(num);
    const int reversed2 = getReversed(reversed1);
    return reversed2 == num;
  }

 private:
  int getReversed(int num) {
    int reversed = 0;
    while (num > 0) {
      reversed = reversed * 10 + num % 10;
      num /= 10;
    }
    return reversed;
  }
};
