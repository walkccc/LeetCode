class Solution {
 public:
  int getLucky(string s, int k) {
    int ans = convert(s);
    for (int i = 1; i < k; ++i)
      ans = getDigitSum(ans);
    return ans;
  }

 private:
  int convert(string s) {
    int sum = 0;
    for (const char c : s) {
      const int val = c - 'a' + 1;
      // Do one transform to prevent integer overflow.
      sum += val < 10 ? val : (val % 10 + val / 10);
    }
    return sum;
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
