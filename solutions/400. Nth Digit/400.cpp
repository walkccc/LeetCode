class Solution {
 public:
  int findNthDigit(int n) {
    int digitSize = 1;
    int startNum = 1;
    long count = 9;

    while (digitSize * count < n) {
      n -= digitSize * count;
      ++digitSize;
      startNum *= 10;
      count *= 10;
    }

    const int targetNum = startNum + (n - 1) / digitSize;
    const int index = (n - 1) % digitSize;
    return to_string(targetNum)[index] - '0';
  }
};
