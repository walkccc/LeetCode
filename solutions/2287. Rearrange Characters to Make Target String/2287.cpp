class Solution {
 public:
  int rearrangeCharacters(string s, string target) {
    int ans = s.length();
    vector<int> countS(128);
    vector<int> countT(128);

    for (const char c : s)
      ++countS[c];

    for (const char c : target)
      ++countT[c];

    for (const char c : target)
      ans = min(ans, countS[c] / countT[c]);

    return ans;
  }
};
