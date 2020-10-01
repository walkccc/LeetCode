class Solution {
 public:
  string reorganizeString(string S) {
    const int n = S.length();

    vector<int> count(128);

    for (const char c : S)
      ++count[c];

    const int maxCount = *max_element(begin(count), end(count));
    if (maxCount > (n + 1) / 2) return "";

    const char maxCountChar = getMaxCountChar(count, maxCount);

    string ans(n, ' ');
    int i = 0;  // point to ans

    auto fillIn = [&](char c) {
      ans[i] = c;
      i += 2;
      if (i >= n)  // out-of-bound, reset the index to 1
        i = 1;
    };

    // fill in 0, 2, 4, ... indices with the maxCount char
    while (count[maxCountChar]-- > 0)
      fillIn(maxCountChar);

    // fill in remaining characters
    for (char c = 'a'; c <= 'z'; ++c)
      while (count[c]-- > 0)
        fillIn(c);

    return ans;
  }

 private:
  char getMaxCountChar(const vector<int>& count, int maxCount) {
    for (char c = 'a'; c <= 'z'; ++c)
      if (count[c] == maxCount)
        return c;
    throw;
  }
};