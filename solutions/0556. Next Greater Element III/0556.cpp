class Solution {
 public:
  int nextGreaterElement(int n) {
    string s = nextPermutation(to_string(n));
    long ans = stol(s);

    return ans > INT_MAX || ans <= n ? -1 : ans;
  }

 private:
  string nextPermutation(string s) {
    int i;
    for (i = s.length() - 2; i >= 0; --i)
      if (s[i] < s[i + 1]) break;

    if (i >= 0) {
      int j;
      for (j = s.length() - 1; j > i; --j)
        if (s[j] > s[i]) break;
      swap(s[i], s[j]);
    }

    reverse(s, i + 1, s.length() - 1);

    return s;
  }

  void reverse(string& s, int l, int r) {
    while (l < r) swap(s[l++], s[r--]);
  }
};