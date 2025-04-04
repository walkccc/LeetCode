class Solution {
 public:
  string maxValue(string n, int x) {
    bool isNegative = n[0] == '-';

    for (int i = 0; i < n.length(); ++i)
      if (!isNegative && n[i] - '0' < x || isNegative && n[i] - '0' > x)
        return n.substr(0, i) + (char)('0' + x) + n.substr(i);

    return n + (char)('0' + x);
  }
};
