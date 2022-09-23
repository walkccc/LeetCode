class Solution {
 public:
  bool isAdditiveNumber(string num) {
    const int n = num.length();

    // num[0..i] = firstNum
    for (int i = 0; i < n / 2; ++i) {
      if (i > 0 && num[0] == '0')
        return false;
      const long firstNum = stol(num.substr(0, i + 1));
      // num[i + 1..j] = secondNum
      // len(thirdNum) >= max(len(firstNum), len(secondNum))
      for (int j = i + 1; max(i, j - i) < n - j; ++j) {
        if (j > i + 1 && num[i + 1] == '0')
          break;
        const long secondNum = stol(num.substr(i + 1, j - i));
        if (dfs(num, firstNum, secondNum, j + 1))
          return true;
      }
    }

    return false;
  }

 private:
  bool dfs(const string& num, long firstNum, long secondNum, long s) {
    if (s == num.length())
      return true;

    const long thirdNum = firstNum + secondNum;
    const string& thirdNumStr = to_string(thirdNum);
    return num.find(thirdNumStr, s) == s &&
           dfs(num, secondNum, thirdNum, s + thirdNumStr.length());
  }
};
