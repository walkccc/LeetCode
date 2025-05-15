class Solution {
 public:
  int numberCount(int a, int b) {
    int ans = 0;
    for (int num = a; num <= b; ++num)
      if (isUniqueDigits(num))
        ++ans;
    return ans;
  }

 private:
  bool isUniqueDigits(int num) {
    vector<bool> seen(10);
    while (num > 0) {
      const int digit = num % 10;
      if (seen[digit])
        return false;
      seen[digit] = true;
      num /= 10;
    }
    return true;
  }
};
