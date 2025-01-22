class Solution {
 public:
  int closestFair(int n) {
    const int digitsCount = to_string(n).length();
    return digitsCount % 2 == 0 ? getEvenDigits(n) : getOddDigits(digitsCount);
  }

 private:
  long getOddDigits(int digitsCount) {
    const int zeros = (digitsCount + 1) / 2;
    const int ones = (digitsCount - 1) / 2;
    return stoi('1' + string(zeros, '0') + string(ones, '1'));
  }

  int getEvenDigits(int n) {
    const int digitsCount = to_string(n).length();
    const long maxNum = stol('1' + string(digitsCount, '0'));
    for (long num = n; num < maxNum; ++num)
      if (isValidNum(num))
        return num;
    return getOddDigits(digitsCount + 1);
  }

  bool isValidNum(long num) {
    int count = 0;
    for (const char c : to_string(num))
      count += (c - '0') % 2 == 0 ? 1 : -1;
    return count == 0;
  }
};
