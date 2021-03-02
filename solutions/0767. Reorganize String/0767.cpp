class Solution {
 public:
  string reorganizeString(string S) {
    const int n = S.length();

    vector<int> count(128);
    int maxCount = 0;
    char maxChar;

    for (const char c : S)
      ++count[c];

    for (char c = 'a'; c <= 'z'; ++c)
      if (count[c] > maxCount) {
        maxCount = count[c];
        maxChar = c;
      }

    if (maxCount > (n + 1) / 2)
      return "";

    string ans(n, ' ');
    int i = 0;  // ans's index

    auto fillIn = [&](char c) {
      ans[i] = c;
      i += 2;
      if (i >= n)  // out of bound, reset the index to 1
        i = 1;
    };

    // fill in 0, 2, 4, ... indices with the maxCount char
    while (count[maxChar]-- > 0)
      fillIn(maxChar);

    // fill in remaining characters
    for (char c = 'a'; c <= 'z'; ++c)
      while (count[c]-- > 0)
        fillIn(c);

    return ans;
  }
};
