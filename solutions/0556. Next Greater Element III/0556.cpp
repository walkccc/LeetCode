class Solution {
 public:
  int nextGreaterElement(int n) {
    const string& s = nextPermutation(to_string(n));
    const long ans = stol(s);
    return ans > INT_MAX || ans <= n ? -1 : ans;
  }

 private:
  // Similar to 31. Next Permutation
  string nextPermutation(string s) {
    const int n = s.length();

    int i;
    for (i = n - 2; i >= 0; --i)
      if (s[i] < s[i + 1])
        break;

    if (i >= 0) {
      for (int j = n - 1; j > i; --j)
        if (s[j] > s[i]) {
          swap(s[i], s[j]);
          break;
        }
    }

    reverse(s, i + 1, n - 1);
    return s;
  }

  void reverse(string& s, int l, int r) {
    while (l < r)
      swap(s[l++], s[r--]);
  }
};
