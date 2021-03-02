class Solution {
 public:
  int monotoneIncreasingDigits(int N) {
    string s = to_string(N);
    const int n = s.length();
    int k = n;  // s[k:] -> '9'

    for (int i = n - 1; i > 0; --i)
      if (s[i] < s[i - 1]) {
        --s[i - 1];
        k = i;
      }

    for (int i = k; i < n; ++i)
      s[i] = '9';

    return stoi(s);
  }
};
