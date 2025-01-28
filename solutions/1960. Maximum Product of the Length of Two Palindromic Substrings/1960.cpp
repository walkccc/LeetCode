class Solution {
 public:
  long long maxProduct(string s) {
    const int n = s.length();
    long ans = 1;
    // maxLeft[i] := the maximum odd length of palindromes in s[0..i]
    vector<int> maxLeft = manacher(s, n);
    // maxRight[i] := the maximum odd length of palindromes in s[i..n - 1]
    vector<int> maxRight = manacher(string{s.rbegin(), s.rend()}, n);

    ranges::reverse(maxRight);

    for (int i = 1; i < n; ++i)
      ans = max(ans, static_cast<long>(maxLeft[i - 1]) * maxRight[i]);

    return ans;
  }

 private:
  vector<int> manacher(const string& s, int n) {
    vector<int> maxExtends(n);
    vector<int> leftToRight(n, 1);
    int center = 0;

    for (int i = 0; i < n; ++i) {
      const int r = center + maxExtends[center] - 1;
      const int mirrorIndex = center - (i - center);
      int extend = i > r ? 1 : min(maxExtends[mirrorIndex], r - i + 1);
      while (i - extend >= 0 && i + extend < n &&
             s[i - extend] == s[i + extend]) {
        leftToRight[i + extend] = 2 * extend + 1;
        ++extend;
      }
      maxExtends[i] = extend;
      if (i + maxExtends[i] >= r)
        center = i;
    }

    for (int i = 1; i < n; ++i)
      leftToRight[i] = max(leftToRight[i], leftToRight[i - 1]);

    return leftToRight;
  }
};
