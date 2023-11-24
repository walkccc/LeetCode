class Solution {
 public:
  int numberOfSpecialSubstrings(string s) {
    int ans = 0;
    vector<int> count(128);

    for (int l = 0, r = 0; r < s.length(); ++r) {
      ++count[s[r]];
      while (count[s[r]] == 2)
        --count[s[l++]];
      ans += r - l + 1;
    }

    return ans;
  }
};
