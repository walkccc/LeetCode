class Solution {
 public:
  string reverseStr(string s, int k) {
    for (size_t i = 0; i < s.length(); i += 2 * k) {
      int l = i;
      int r = min(i + k - 1, s.length() - 1);
      while (l < r)
        swap(s[l++], s[r--]);
    }

    return s;
  }
};
