class Solution {
 public:
  int atMostNGivenDigitSet(vector<string>& digits, int n) {
    int ans = 0;
    const string num = to_string(n);

    for (int i = 1; i < num.length(); ++i)
      ans += pow(digits.size(), i);

    for (int i = 0; i < num.length(); ++i) {
      bool dHasSameNum = false;
      for (const string& digit : digits) {
        if (digit[0] < num[i])
          ans += pow(digits.size(), num.length() - i - 1);
        else if (digit[0] == num[i])
          dHasSameNum = true;
      }
      if (!dHasSameNum)
        return ans;
    }

    return ans + 1;
  }
};
