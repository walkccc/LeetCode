class Bitset {
 public:
  Bitset(int size) : s(size, '0'), r(size, '1') {}

  void fix(int idx) {
    if (s[idx] == '0')
      ++cnt;
    s[idx] = '1';
    r[idx] = '0';
  }

  void unfix(int idx) {
    if (s[idx] == '1')
      --cnt;
    s[idx] = '0';
    r[idx] = '1';
  }

  void flip() {
    swap(s, r);
    cnt = s.length() - cnt;
  }

  bool all() {
    return cnt == s.length();
  }

  bool one() {
    return cnt;
  }

  int count() {
    return cnt;
  }

  string toString() {
    return s;
  }

 private:
  string s;  // the original
  string r;  // the reversed
  int cnt = 0;
};
