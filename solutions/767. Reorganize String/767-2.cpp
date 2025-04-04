class Solution {
 public:
  string reorganizeString(string s) {
    const int n = s.length();
    vector<int> count(128);
    char maxChar = 'a' - 1;

    for (const char c : s)
      ++count[c];

    for (char c = 'a'; c <= 'z'; ++c)
      if (count[c] > count[maxChar])
        maxChar = c;

    if (count[maxChar] > (n + 1) / 2)
      return "";

    string ans(n, ' ');
    int i = 0;  // ans' index

    auto fillIn = [&](char c) {
      ans[i] = c;
      i += 2;
      if (i >= n)
        i = 1;
    };

    // Fill in 0, 2, 4, ... indices with `maxCount` letters.
    while (count[maxChar]-- > 0)
      fillIn(maxChar);

    // Fill in the remaining letters.
    for (char c = 'a'; c <= 'z'; ++c)
      while (count[c] > 0) {
        --count[c];
        fillIn(c);
      }

    return ans;
  }
};
