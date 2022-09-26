class Solution {
 public:
  string customSortString(string S, string T) {
    string ans;
    vector<int> count(128);

    for (const char c : T)
      ++count[c];

    for (const char c : S)
      while (count[c]-- > 0)
        ans += c;

    for (char c = 'a'; c <= 'z'; ++c)
      while (count[c]-- > 0)
        ans += c;

    return ans;
  }
};
