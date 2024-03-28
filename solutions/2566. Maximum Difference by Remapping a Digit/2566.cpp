class Solution {
 public:
  int minMaxDifference(int num) {
    const string s = to_string(num);
    const char to9 = s[firstNotNineIndex(s)];
    const char to0 = s[0];
    return getMax(s, to9) - getMin(s, to0);
  }

 private:
  int firstNotNineIndex(const string& s) {
    for (int i = 0; i < s.length(); ++i)
      if (s[i] != '9')
        return i;
    return 0;
  }

  int getMax(string s, char to9) {
    for (char& c : s)
      if (c == to9)
        c = '9';
    return stoi(s);
  }

  int getMin(string s, char to0) {
    for (char& c : s)
      if (c == to0)
        c = '0';
    return stoi(s);
  }
};
