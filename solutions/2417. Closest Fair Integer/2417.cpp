class Solution {
 public:
  int closestFair(int n) {
    const int digitsCount = to_string(n).length();
    return (digitsCount & 1) ? getOddDigits(digitsCount) : getEvenDigits(n);
  }

 private:
  long getOddDigits(int digitsCount) {
    const int zerosCount = (digitsCount + 1) / 2;
    const int onesCount = (digitsCount - 1) / 2;
    return stoi('1' + string(zerosCount, '0') + string(onesCount, '1'));
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
    const string s = to_string(num);
    for (const char c : s)
      count += (c - '0' & 1) ? -1 : 1;
    return count == 0;
  }
};
