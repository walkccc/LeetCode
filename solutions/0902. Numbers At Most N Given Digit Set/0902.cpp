class Solution {
 public:
  int atMostNGivenDigitSet(vector<string>& D, int N) {
    int ans = 0;
    string num = to_string(N);

    for (int i = 1; i < num.length(); ++i)
      ans += pow(D.size(), i);

    for (int i = 0; i < num.length(); ++i) {
      bool dHasSameNum = false;
      for (const string& digit : D) {
        if (digit[0] < num[i])
          ans += pow(D.size(), num.length() - i - 1);
        else if (digit[0] == num[i])
          dHasSameNum = true;
      }
      if (!dHasSameNum)
        return ans;
    }

    return ans + 1;
  }
};
