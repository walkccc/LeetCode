class Solution {
 public:
  string removeOccurrences(string s, string part) {
    const int n = s.length();
    const int k = part.length();

    string t(n, ' ');
    int j = 0;  // t's index

    for (int i = 0; i < n; ++i) {
      t[j++] = s[i];
      if (j >= k && t.substr(j - k, k) == part)
        j -= k;
    }

    return t.substr(0, j);
  }
};
