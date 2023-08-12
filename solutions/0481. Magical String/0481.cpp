class Solution {
 public:
  int magicalString(int n) {
    string s = " 122";

    for (int i = 3; i <= n; ++i)
      if (i & 1)
        s.append(s[i] - '0', '1');
      else
        s.append(s[i] - '0', '2');

    return count(s.begin(), s.begin() + n + 1, '1');
  }
};
